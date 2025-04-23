import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class ErrorDetectionCorrection {
    // === CRC SECTION ===
    private static final String ZERO_STRING = "0";
    // Performs XOR between two binary strings
    private static String xor(String a, String b) { // a=1011 and b=1101 => 0110
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < a.length(); i++) {
            result.append(a.charAt(i) == b.charAt(i) ? '0' : '1');
        }
        return result.toString();
    }

    // Simulates modulo-2 division for CRC
    private static String divideBinary(String dividend, String divisor) {
        int divisorLength = divisor.length(); // 4 -> divisor and 101101000 -> 9 -> dividend 
        String current = dividend.substring(0, divisorLength); // (0, 4) // 1011
        int pointer = divisorLength;

        while (pointer < dividend.length()) { // 4 / 5 / 6 / 7 / 8-> 9
            if (current.charAt(0) == '1') {
                current = xor(current, divisor).substring(1) + dividend.charAt(pointer); 
            } else {
                current = current.substring(1) + dividend.charAt(pointer);
            }
            pointer++;
        }

        // Final XOR operation
        if (current.charAt(0) == '1') { //current=a=0010 b=1101
            current = xor(current, divisor);
        } else {
            current = xor(current, ZERO_STRING.repeat(divisorLength)); // 0010 xor 0000 -> 010
        }
        return current.substring(1);
    }

    // Append CRC bits to data
    public static String createCRC(String data, String divisor) { 
        String extendedData = data + ZERO_STRING.repeat(divisor.length() - 1);
        String crcBits = divideBinary(extendedData, divisor); //crcbits = 010
        return data + crcBits; //101101010
    }

    // Check received CRC data
    public static boolean verifyCRC(String receivedData, String divisor) {
        return divideBinary(receivedData, divisor).matches("^0+$"); 
    }

    // === HAMMING CODE SECTION ===
    public static int[] generateHamming(int[] dataBits, String parityType) {
        int m = dataBits.length;
        int r = 0;

        // Calculate how many parity bits are needed
        while (Math.pow(2, r) < m + r + 1) {
            r++;
        }

        int[] hammingCode = new int[m + r];
        ArrayList<Integer> dataPositions = new ArrayList<>();

        // Identify positions for data bits (non-powers of 2)
        for (int i = 1; i <= hammingCode.length; i++) {
            if (!isPowerOfTwo(i)) {
                dataPositions.add(i);
            }
        }

        Collections.reverse(dataPositions);  // Fill from the end
        int index = 0;
        for (int pos : dataPositions) {
            hammingCode[pos - 1] = dataBits[index++];
        }

        // Calculate parity bits
        for (int i = 0; i < r; i++) {
            int parityIndex = (int) Math.pow(2, i) - 1;
            hammingCode[parityIndex] = calculateParity(hammingCode, i, parityType);
        }
        return hammingCode;
    }

    private static boolean isPowerOfTwo(int n) {
        return (n & (n - 1)) == 0;
    }

    private static int calculateParity(int[] hammingCode, int power, String parityType) {
        int parity = 0;
        int parityBit = (int) Math.pow(2, power);

        for (int i = 0; i < hammingCode.length; i++) {
            int position = i + 1;
            if (position == parityBit) continue;

            if ((position & parityBit) != 0) {
                parity ^= hammingCode[i];
            }
        }

        // For odd parity
        if (parityType.equalsIgnoreCase("odd")) {
            parity ^= 1;
        }

        return parity;
    }

    public static int detectAndFixError(int[] received, String parityType) {
        int r = 0;
        while (Math.pow(2, r) <= received.length) {
            r++;
        }

        int errorPosition = 0;

        for (int i = 0; i < r; i++) {
            int parityBit = (int) Math.pow(2, i);
            int parity = 0;

            for (int j = 0; j < received.length; j++) {
                int position = j + 1;
                if ((position & parityBit) != 0) {
                    parity ^= received[j];
                }
            }

            if (parityType.equalsIgnoreCase("odd")) {
                parity ^= 1;
            }

            if (parity != 0) {
                errorPosition += parityBit;
            }
        }

        return errorPosition;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Choose method:\n1. CRC\n2. Hamming Code");
        System.out.print("Enter choice: ");
        int choice = sc.nextInt();

        if (choice == 1) {
            
                System.out.print("Enter binary data: ");
                String data = sc.next();
                System.out.print("Enter binary divisor: ");
                String divisor = sc.next();
                String encoded = createCRC(data, divisor); //101101010
                System.out.println("CRC Encoded Data: " + encoded);

                System.out.print("Enter received data: ");
                String received = sc.next();
                if (verifyCRC(received, divisor)) {
                    System.out.println("No error detected.");
                } else {
                    System.out.println("Error detected in received data.");
                }
            

        } else if (choice == 2) {
            System.out.print("Enter number of data bits: ");
            int m = sc.nextInt();
            int[] dataBits = new int[m];

            System.out.println("Enter data bits:");
            for (int i = 0; i < m; i++) {
                dataBits[i] = sc.nextInt();
            }

            System.out.print("Parity type (even/odd): ");
            String parityType = sc.next();

            int[] hammingCode = generateHamming(dataBits, parityType);
            System.out.print("Generated Hamming Code: ");
            for (int bit : hammingCode) {
                System.out.print(bit + " ");
            }

            System.out.println("\nEnter received Hamming code:");
            int[] receivedCode = new int[hammingCode.length];
            for (int i = 0; i < receivedCode.length; i++) {
                receivedCode[i] = sc.nextInt();
            }

            int errorPos = detectAndFixError(receivedCode, parityType);
            if (errorPos == 0) {
                System.out.println("No error detected.");
            } else {
                System.out.println("Error detected at position: " + errorPos);
                receivedCode[errorPos - 1] ^= 1;
                System.out.print("Corrected Hamming Code: ");
                for (int bit : receivedCode) {
                    System.out.print(bit + " ");
                }
            }

        } else {
            System.out.println("Invalid choice.");
        }

        sc.close();
    }
}
