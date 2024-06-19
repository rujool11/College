import java.lang.*;
import java.util.*;
class vowcon{
    public static void main(String args[]){
        Scanner s = new Scanner(System.in);
        System.out.println("enter the word");
        String word = s.nextLine();
        int vowel_num = 0;
        for (int i=0;i<word.length();i++){
            if (word.charAt(i)=='a'||word.charAt(i)=='e'||word.charAt(i)=='i'||word.charAt(i)=='o'||word.charAt(i)=='u'){
                vowel_num += 1 ;
            }
        }
        System.out.println("the number of vowels are " + vowel_num);
        System.out.println("the number of consonants are " + (word.length()-vowel_num));
    }
}