import java.util.*;
class three{
    public static void main(String args[]){
        Scanner s1=new Scanner(System.in);
        System.out.println("enter the marks");
        int marks=s1.nextInt();
        if (marks>=91 && marks<=100){
            System.out.println("O");
        }
        else if (marks<=90 && marks>=81){
            System.out.println("A");
        }
        else if (marks<=80 && marks>=71){
            System.out.println("B");
        }
        else if (marks>=61 && marks<=70){
            System.out.println("C");
        }
        else if (marks>=50 && marks<=60){
            System.out.println("D");
        }
        else{
            System.out.println("RA");
        }

    }
}