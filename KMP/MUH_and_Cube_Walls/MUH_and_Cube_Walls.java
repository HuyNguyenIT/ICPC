import java.io.*;
import java.lang.*;
import java.util.*;

public class Solution_AC {
    public static void KMPPreprocess(int[] p, int[] prefix) {
        int m = p.length;
        prefix[0] = 0;
        int i = 1, j = 0;
        while (i < m) {
            if (p[i] == p[j]) {
                j++;
                prefix[i] = j;
                i++;
            }
            else {
                if (j != 0) {
                    j = prefix[j - 1];
                }
                else {
                    prefix[i] = 0;
                    i++;
                }
            }
        }
    }

    public static int calc(int[] B, int[] A) {
        if (B.length == 0) {
            return A.length + 1;
        }

        int[] prefix;
        prefix = new int[B.length];
        KMPPreprocess(B, prefix);

        int cnt = 0;

        int n = A.length;
        int m = B.length;
        int i = 0, j = 0;
        while (i < n) {
            if (B[j] == A[i]) {
                i++;
                j++;
            }
            if (j == m) {
                cnt++;
                j = prefix[j - 1];
            }
            else if (i < n && B[j] != A[i]) {
                if (j != 0) {
                    j = prefix[j - 1];
                } else {
                    i++;
                }
            }
        }
        return cnt;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n, w, x, y;
        int[] A, B;

        n = sc.nextInt();
        w = sc.nextInt();

        A = new int [n - 1];
        x = sc.nextInt();
        for (int i = 0; i < n - 1; i++) {
            y = sc.nextInt();
            A[i] = y - x;
            x = y;
        }

        B = new int [w - 1];
        x = sc.nextInt();
        for (int i = 0; i < w - 1; i++) {
            y = sc.nextInt();
            B[i] = y - x;
            x = y;
        }

        System.out.print(calc(B, A));
    }
}