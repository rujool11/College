import java.lang.*;
public class stringswap{
    public static void main(String args[]){
        String A = "apple";
        String B = "banana";
        System.out.println("before swapping A and B " + A + " " + B);
        A = A + B;
        B = A.substring(0,A.length()-B.length());
        A = A.substring(B.length());
        System.out.println("after swapping A and B " + A + " " + B);
    }
}