import java.io.*;
import java.util.Scanner; 
import java.util.*;
import java.lang.*;

public class Solution_AC {
    static final int MAX_N = 1000006;
    static int kmp[] = new int [MAX_N];
    static String s;
    static int m;
    public static void main (String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        //StringBuilder sb = new StringBuilder();
        s = sc.next();
        m = s.length();
        KMPPreprocess();
        int x = kmp[m-1];
        if (x == 0)
            System.out.println("Just a legend");
        else if (findElement(1, m - 1, x))
            System.out.println(s.substring(0, x));
        else if (kmp[x - 1] == 0)
            System.out.println("Just a legend");
        else if (kmp[x - 1] != 0)
            System.out.println(s.substring(0, kmp[x-1]));
        else
            System.out.println("Just a legend");
    }
    
    static boolean findElement(int start, int end, int elem){
        for(int i = start; i < end; ++i)
            if(kmp[i] == elem)
                return true;
        return false;
    }

    static void printString(String s, int end){
        System.out.println(s.substring(0, end));
    }
    static void KMPPreprocess(){
        kmp[0] = 0;
        int i = 1, j = 0;
        while(i < m){
            if(s.charAt(i) == s.charAt(j)){
                j++;
                kmp[i] = j;
                i++;
            }
            else{
                if(j != 0){
                    j = kmp[j-1];
                }
                else{
                    kmp[i] = 0;
                    i++;
                }
            }
        }
    }
    public static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream));
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }
    }
}