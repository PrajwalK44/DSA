import java.util.Scanner;

public class KnuthMorris {

    private static int[] computeLPS(String p) {
        int m = p.length();
        int[] lps = new int[m];
        int len = 0, i = 1;
        while (i < m) {
            if (p.charAt(i) == p.charAt(len)) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }

    public static void knuthMorrisPratt(String p, String t) {
        int m = p.length(), n = t.length();
        int[] lps = computeLPS(p);

        int i = 0, j = 0;
        while (i < n) {
            if (p.charAt(j) == t.charAt(i)) {
                i++;
                j++;
            }
            if (j == m) {
                System.out.println("Pattern found at position: " + (i - j)); //imp
                j = lps[j - 1];
            } else if (i < n && p.charAt(j) != t.charAt(i)) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter two strings");
        String str1, str2;
        System.out.println("Enter text");
        str1=sc.nextLine();
        System.out.println("Enter pattern");
        str2=sc.nextLine();
        knuthMorrisPratt(str2, str1);
    }
}
