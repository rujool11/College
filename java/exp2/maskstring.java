import java.util.*;
import java.lang.*;
class maskstring{
    public static void main(String args[]){
        Scanner s = new Scanner(System.in);
        System.out.println("enter main string and mask string");
        String main_string = s.nextLine();
        String mask_string = s.nextLine();
        for (int i=0;i<main_string.length();i++){
            for (int j=0;j<mask_string.length();j++){
                if (main_string.charAt(i)==mask_string.charAt(j)){
                    String temp = Character.toString(mask_string.charAt(j));
                    main_string = main_string.replace(temp,"");
                }
            }
        }
        System.out.println(main_string);
    }
}