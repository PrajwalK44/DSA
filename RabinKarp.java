import java.util.Scanner;

public class RKPractice {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String text, pattern;
        int textLength, patternLength;
        int textHash=0; 
        int patternHash=0;
        System.out.println("Enter the text");
        text=sc.nextLine();
        
        System.out.println("Enter the pattern");
        pattern = sc.nextLine();
        textLength = text.length();
        patternLength = pattern.length();
        
        for(int i=0; i<patternLength; i++){
            textHash+=text.charAt(i);
            patternHash+=pattern.charAt(i);
        }
        
        textHash %= 11;
        patternHash %= 11;
        //imp condition => textLength-patternLength
        for(int i=0; i<=textLength-patternLength; i++){
            if(textHash==patternHash){
                if(text.substring(i, i+patternLength).equals(pattern)){
                    System.out.println("Pattern found at "+(i+1));
                }
                else{
                    System.out.println("Spurious hit");
                }
            } else{
                textHash = (textHash-text.charAt(i)+text.charAt(i+patternLength))%11;
                if(textHash<0){
                    textHash+=11;
                }
            }
        }
    }
}
