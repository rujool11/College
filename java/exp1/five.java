import java.util.*;
import java.lang.Math;
class five{
    public static void main(String args[]){
        Scanner s1 = new Scanner(System.in);
        System.out.println("enter the amount");
        double amount = s1.nextDouble();
        System.out.println("enter the rate");
        double rate = s1.nextDouble();
        System.out.println("enter the time");
        double time = s1.nextDouble();
        double simple = amount*(1+rate*time/100);
        double compound = amount*Math.pow((1+rate/100),time);
        System.out.println("the amount to be paid after simple interest is " + simple); 
        System.out.println("the amount to be paid after compound interest is " + compound); 
    }
}