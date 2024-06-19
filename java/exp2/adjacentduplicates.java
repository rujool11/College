import java.util.*;
import java.lang.*;
class adjacentduplicates{
    public static void main(String args[]){
        Scanner s = new Scanner(System.in);
        System.out.println("enter the string");
        String word = s.nextLine();
        StringBuilder sb = new StringBuilder(word);
        for (int i=0;i<word.length()-1;i++){
            if (word.charAt(i)==word.charAt(i+1)){
                sb.replace(i,i+1,"0");
            }
        }
        String final_word = sb.toString();
        final_word = final_word.replaceAll("0","");
        System.out.println("the final string is :" + final_word);
    }
}