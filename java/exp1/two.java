import java.util.*;
class two{
    public static void main(String args[]){
        Scanner s1=new Scanner(System.in);
        System.out.println("enter the number");
        int num = s1.nextInt();
        if (num%2==0){
            System.out.println("the number is even");
        }
        else {
            System.out.println("the number is odd");
        }


    }
}