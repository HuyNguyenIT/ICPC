import java.io.*;
import java.util.Scanner; 
import java.util.*;
import java.lang.*;

public class Solution_AC {
    static final int MAX_N = 1000006;
    static int prefix[] = new int [MAX_N];
    static String p,t;
    static int m,n;
    public static void main (String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        //StringBuilder sb = new StringBuilder();
        t = sc.nextLine();
        p = sc.nextLine();
        int k;
        k = sc.nextInt();
        int l = 0; 
        int r = (int) p.length() - 1;
        String ans = "IMPOSSIBLE"; 
        while (l <= r) {
            int mid = (l + r) / 2; 
            String tmp = p.substring(0,mid+1);

            KMPPreprocess(tmp);

            int cnt = KMPSearch(t, tmp); 

             if (cnt >= k) {
                 ans = tmp; 
                 l = mid + 1;
             }
             else {
                 r = mid - 1; 
             }
         }

        System.out.println(ans);
    }

    static void KMPPreprocess(String s){
        m = s.length();
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
    static int KMPSearch(String t, String p) {
        n = t.length();
        m = p.length();
        int cnt = 0; 
        int i = 0, j = 0;
        while (i < n) {
            if (p.charAt(j)== t.charAt(i)) {
                j++;
                i++;
            }
            if (j == m) {
                cnt++; 
                j = prefix[j - 1];
            }
            else {
                if (i < n && p.charAt(j) != t.charAt(i)) {
                    if (j != 0) {
                        j = prefix[j - 1];
                    }
                    else {
                        i = i + 1;
                    }
                }
            }
        }

        return cnt;  
    } 
}