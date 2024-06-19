import java.util.*;
class sum{
    public static void main(String args[]){
        Scanner s = new Scanner(System.in);
        System.out.println("enter the number");
        int n = s.nextInt();
        int sum = 0;
        for (int i=1;i<=n;i++){
            sum+=i;
        }
        System.out.println("the sum is " +  sum);
    }
}