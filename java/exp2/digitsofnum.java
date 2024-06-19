import java.util.*;
class digitsofnum{
    public static void main(String args[]){
        Scanner s = new Scanner(System.in);
        System.out.println("enter the number");
        String num_s = s.nextLine();
        int sum = 0;
        for (int i=0;i<num_s.length;i++){
            sum+=integer.parseInt(num_s.charAt(i));
        }     
        System.out.println("the sum of digits is " + sum);
    }
}