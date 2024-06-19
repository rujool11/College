import java.util.*;
class seven{
    public static void main(String args[]){
        Scanner s1 = new Scanner(System.in);
        int perDay,days;
        System.out.println("enter per day salary");
        perDay = s1.nextInt();
        System.out.println("enter number of days present");
        days = s1.nextInt();
        int total = perDay*days;
        System.out.println("the total salary is " + total);
         
    }
}