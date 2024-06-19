import java.util.*;
class sumofdigits{
    public static void main(String args[]){
        Scanner s = new Scanner(System.in);
        System.out.println("enter the number"); 
        String num = s.nextLine();
        int sum = 0;
        for (int i=0;i<num.length();i++){
            sum += Character.getNumericValue(num.charAt(i));
        }
        System.out.println("the sum of digits is " + sum);
    }
}