import java.util.*;
class bikers{
    public static void main(String args[]){
        float a,b,c,d,e;
        Scanner s = new Scanner(System.in);
        System.out.println("enter the speed of the bikers");
        a = s.nextFloat();
        b = s.nextFloat();
        c = s.nextFloat();
        d = s.nextFloat();
        e = s.nextFloat();
        float avg = (a+b+c+d+e)/5;
        System.out.println("the average speed is " + avg + "and speeds above average are :");
        if (avg<a){
            System.out.println(a);
        }
        if (avg<b){
            System.out.println(b);
        }
        if (avg<c){
            System.out.println(c);
        }
        if (avg<d){
            System.out.println(d);
        }
        if (avg<e){
            System.out.println(e);
        }
        
    }
}