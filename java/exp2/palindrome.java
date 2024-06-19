import java.util.*;
import java.lang.*;
class palindrome{
    public static void main(String args[]){
        Scanner s = new Scanner(System.in);
        System.out.println("enter the string");
        String word = s.nextLine();
        String rev_word ="";
        for (int i=word.length()-1;i>=0;i--){
            rev_word += word.charAt(i);
        }
        if (word.equals(rev_word)){
            System.out.println("it is a palindrome");
        }
        else {
            System.out.println("not a palindrome");
        }
    }
}