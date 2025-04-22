import java.util.Scanner;

public class RabinKarp{
    int PRIME_NO=101;

    public double calculateHash(String str){
        double hash=0;
        for(int i=0; i<str.length(); i++){
            hash+=str.charAt(i)*Math.pow(PRIME_NO, i);
        }
        return hash;
    }
    
    public double updateHash(double prevHash, char oldChar, char newChar, int patternLength){
        double newHash = (prevHash - oldChar)/PRIME_NO;
        newHash+=newChar*Math.pow(PRIME_NO, patternLength-1);
        return newHash;
    }

    public void search(String text, String pattern){
        int patternLength = pattern.length();
        double patternHash = calculateHash(pattern);
        double textHash = calculateHash(text.substring(0, patternLength));

        for (int i = 0; i < text.length()-patternLength; i++) {
            if(textHash == patternHash){
                if(text.substring(i, i+patternLength).equals(pattern)){
                    System.out.println("Pattern found at index "+i);
                }
            }

            if(i<text.length()-patternLength){
                textHash = updateHash(textHash, text.charAt(i), text.charAt(i+patternLength), patternLength);
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
        RabinKarp kp = new RabinKarp();
        kp.search(str1, str2);
    }

}