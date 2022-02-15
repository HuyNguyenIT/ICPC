import java.io.*;
import java.util.Scanner; 
import java.util.*;

public class Solution_AC {
    static final int MAX_N = 100005;
    public static void main (String[] args) {
        MyScanner sc = new MyScanner();
        int prefix[] = new int [MAX_N];
        int T = sc.nextInt();
        for(int t = 1; t <= T; t++) {
            String test = sc.nextLine().replaceAll("\\s+","");
            String patt = sc.nextLine().replaceAll("\\s+","");
            //System.out.println(test);
            //System.out.println(test.length());
            System.out.printf("Case %d: %d\n",t,Solve(test,patt,prefix));            
        }
    }

    static int Solve(String t,String s, int []prefix){ // t : test string
        // s : pattern string
        Build(s,prefix);
        int m = s.length();
        int n = t.length();
        int i = 0, j = 0;
        int res = 0;
        while(i < n){
            if(s.charAt(j) == t.charAt(i)){
                i++; j++;
            }
            if(j == m){
                res++;
                j = prefix[j-1];
            }
            else if(i < n && s.charAt(j) != t.charAt(i)){
                if(j != 0){
                    j = prefix[j-1];
                }
                else{
                    i ++;
                }
            }
        }
        return res;
    }

    static void Build(String s, int[] prefix){
        int m = s.length();
        prefix[0] = 0;
        int i = 1, j = 0;
        while(i < m){
            if(s.charAt(i) == s.charAt(j)){
                j++;
                prefix[i] = j;
                i++;
            }
            else{
                if(j != 0){
                    j = prefix[j-1];
                }
                else{
                    prefix[i] = 0;
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