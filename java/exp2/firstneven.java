import java.util.*;
class firstneven{
    public static void main(String args[]){
        Scanner s = new Scanner(System.in);
        System.out.println("enter the value of n ");
        int n = s.nextInt();
        int sum = 0;
        for (int i=0;i<=2*(n-1);i+=2){
            if (i%3 == 0){
                sum+=i;
            }
        }
        System.out.println("the required value is " + sum);
    }
}