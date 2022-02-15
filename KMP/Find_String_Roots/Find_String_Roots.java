import java.io.*;
import java.util.Scanner; 
import java.util.*;

class Solution_AC {
    static final int MAX_N = 100005;
    public static void main (String[] args) {
        MyScanner sc = new MyScanner();
        int kmp[] = new int [MAX_N];
        while(true){
            String s = sc.nextLine();
            if(s.equals("*"))
                return;
            int res = Solve(s,kmp);
            System.out.println(res);
        }
    }

    static int Solve(String s, int []kmp){
        Build(s,kmp);
        int m = s.length();
        if( (m % (m - kmp[m -1])) != 0){
            return 1;
        }else{
            return (m/(m - kmp[m - 1]));
        }
    }

    static void Build(String s, int[] kmp){
        int m = s.length();
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
    public static class MyScanner {
        BufferedReader br;
        StringTokenizer st;

        public MyScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }
        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
        int nextInt() {
            return Integer.parseInt(next());
        }
        long nextLong() {
            return Long.parseLong(next());
        }
        double nextDouble() {
            return Double.parseDouble(next());
        }
        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }  
            return str;
        }
    } 
}