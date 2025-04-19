import java.util.Scanner;

public class LCS {
    public static void lcsAlgo(String s1, String s2){
        int m=s1.length();
        int n = s2.length();

        int[][] LCS_table = new int[m+1][n+1];

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if(i==0 || j==0){
                    LCS_table[i][j]=0;
                } else if(s1.charAt(i-1)==s2.charAt(j-1)){
                    LCS_table[i][j]=LCS_table[i-1][j-1]+1;
                } else {
                    LCS_table[i][j]=Math.max(LCS_table[i-1][j], LCS_table[i][j-1]);
                }

            }
        }

        int lengthLCS = LCS_table[m][n];
        char[] lcs = new char[lengthLCS+1];
        int temp = lengthLCS;
        System.out.println("Length of longest common subsequence is "+lengthLCS);
        lcs[lengthLCS]='\0';

        int i=m, j=n;
        while (i>0 && j>0) {
            if(s1.charAt(i-1)==s2.charAt(j-1)){
                lcs[lengthLCS-1] = s1.charAt(i-1);
                i--;
                j--;
                lengthLCS--;
            } else if(LCS_table[i-1][j]>LCS_table[i][j-1]){
                i--;
            } else j--;
        }

        System.out.println("Longset common subsequenec is:-");
        for(char c: lcs){
            System.out.print(c);
        }
     
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s1;
        String s2;
        System.out.println("Enter two strings");
        System.out.println("String 1:-");
        s1=sc.nextLine();
        System.out.println("String 2:-");
        s2=sc.nextLine();
        lcsAlgo(s1, s2);
        sc.close();
    }
}