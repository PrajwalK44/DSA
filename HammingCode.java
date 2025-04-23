import java.util.Scanner;

public class HammingCode {
    // Function to calculate the number of parity bits
    public static int calculateParityBits(int m) {
        int r = 0;
        while ((1 << r) < (m + r + 1)) {
            r++;
        }
        return r;
    }
    // Function to insert parity bits and generate Hamming code
    public static void generateHammingCode(int[] data, int m, int[] code, int r, int totalBits) {
        int j = 0;
        // Insert data and parity bit placeholders
        for (int i = 1; i <= totalBits; i++) {
            if ((i & (i - 1)) == 0) {
                code[i - 1] = 0; // Parity bit placeholder
            } else {
                code[i - 1] = data[j++];
            }
        }
        // Calculate parity bits
        for (int i = 0; i < r; i++) {
            int pos = 1 << i;
            int parity = 0;
            for (int k = 1; k <= totalBits; k++) {
                if ((k & pos) != 0) {
                    parity ^= code[k - 1];
                }
            }
            code[pos - 1] = parity;
        }
        System.out.print("Encoded Hamming Code: ");
        for (int i = 0; i < totalBits; i++) {
            System.out.print(code[i] + " ");
        }
        System.out.println();
    }
    // Function to detect and correct error
    public static void detectError(int[] code, int totalBits) {
        int r = 0;
        while ((1 << r) < totalBits + 1) r++;
        int errorPos = 0;
        for (int i = 0; i < r; i++) {
            int pos = 1 << i;
            int parity = 0;
            for (int j = 1; j <= totalBits; j++) {
                if ((j & pos) != 0) {
                    parity ^= code[j - 1];
                }
            }
            if (parity != 0) errorPos += pos;
        }
        if (errorPos == 0) {
            System.out.println("No error detected in received code.");
        } else {
            System.out.println("Error detected at position: " + errorPos);
            code[errorPos - 1] ^= 1;
            System.out.print("Corrected Hamming Code: ");
            for (int i = 0; i < totalBits; i++) {
                System.out.print(code[i] + " ");
            }
            System.out.println();
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of data bits: ");
        int m = sc.nextInt();
        int[] data = new int[m];
        System.out.print("Enter data bits (from left to right): ");
        for (int i = 0; i < m; i++) {
            data[i] = sc.nextInt();
        }
        int r = calculateParityBits(m);
        int totalBits = m + r;
        int[] code = new int[totalBits];
        generateHammingCode(data, m, code, r, totalBits);
        System.out.print("Enter received Hamming code (with possible error): ");
        for (int i = 0; i < totalBits; i++) {
            code[i] = sc.nextInt();
        }
        detectError(code, totalBits);
    }
}
