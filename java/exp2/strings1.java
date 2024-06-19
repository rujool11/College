import java.util.*;
import java.lang.*;
class strings1{
    public static void main(String args[]){
        Scanner s = new Scanner(System.in);
        System.out.println("enter the two strings");
        String a = s.nextLine();
        String b = s.nextLine();
        System.out.println("the lengths are " + a.length() + " and " + b.length());
        System.out.println(a.concat(b));
        System.out.println(a.toUpperCase()); 
    }
}