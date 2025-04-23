import java.util.Scanner;

public class ErrorDetectionCorrection {
    public static void performXOR(int[] temp, int[] genBits, int dataLength, int genLength){
        for (int i = 0; i < dataLength; i++) {
            if(temp[i]==1){
                for (int j = 0; j < genLength; j++) {
                    temp[i+j]^=genBits[j];
                }
            }
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of bits in data");
        int dataLength=sc.nextInt();
        int[] dataBits = new int[30];
        System.out.println("Enter data");
        for (int i = 0; i < dataLength; i++) {
            dataBits[i]=sc.nextInt();
        }
        System.out.println("Enter number of bits in generator");
        int genLength=sc.nextInt();
        System.out.println("Enter generator");
        int[] genBits = new int[30];
        for (int i = 0; i < genLength; i++) {
            genBits[i]=sc.nextInt();
        }

        //append zeros
        int[] temp = new int[30];
        for (int i = 0; i < dataLength; i++) {
            temp[i]=dataBits[i];
        }
        for (int i = dataLength; i < dataLength+genLength-1; i++) {
            temp[i]=0;
        }

        performXOR(temp, genBits, dataLength, genLength);
        System.out.println("CRC bits- ");
        for (int i = dataLength; i < dataLength+genLength-1; i++) {
            dataBits[i]=temp[i];
            System.out.println(temp[i]);
        }

        System.out.println("Transmitted data ");
        for (int i = 0; i < dataLength+genLength-1; i++) {
            System.out.print(dataBits[i]+" ");
        }
        System.out.println();
        System.out.println("Enter received data");
        int[] receivedData = new int[30];
        for (int i = 0; i < dataLength+genLength-1; i++) {
            receivedData[i]=sc.nextInt();
        }


        performXOR(receivedData, genBits, dataLength, genLength);
        boolean isErrorfree=true;
        for (int i = dataLength; i < dataLength+genLength-1; i++) {
            if(receivedData[i]!=0){
                isErrorfree=false;
            }
        }
        if(isErrorfree){
            System.out.println("No error");
        } else System.out.println("Error detected");

    }
}
