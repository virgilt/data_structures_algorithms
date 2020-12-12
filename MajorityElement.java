import java.util.*;
import java.io.*;

public class MajorityElement {

    private static int getCount(int[] a, int i, int j, int c) {
        int result = 0;
        for (int k = i; k <= j; k++) {
            if (a[k] == c) {
                result++;
            }
        }
        return result;
    }

    private static int getMajority(int[] a, int i, int j) {
        if (i == j) {
            return a[i];
        }

        int mid = (i + j) / 2;
        int left = getMajority(a, i, mid);
        int right = getMajority(a, mid + 1, j);

        if (left == right) {
            return left;
        }

        int countLeft = getCount(a, i, mid, left);
        int countRight = getCount(a, mid + 1, j, right);

        if (countLeft == countRight) {
            return -1;
        }

        return countLeft > countRight ? left : right;
    }

    private static int getMajorityElement(int[] a, int i, int j) {

        int result = getMajority(a, i, j);
        int count = getCount(a, i, j, result);

        if (count > a.length / 2) {
            return 0;
        } else {
            return -1;
        }
    }

    public static void main(String[] args) {
        FastScanner scanner = new FastScanner(System.in);
        int n = scanner.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        if (getMajorityElement(a, 0, a.length - 1) != -1) {
            System.out.println(1);
        } else {
            System.out.println(0);
        }
    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(InputStream stream) {
            try {
                br = new BufferedReader(new InputStreamReader(stream));
            } catch (Exception e) {
                e.printStackTrace();
            }
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
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
    }
}
