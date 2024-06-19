import java.util.*;
class pascaltriangle{
    public static void main(String args[]){
        Scanner s = new Scanner(System.in);
        System.out.println("enter height of the pascal pyramid");
        int l = s.nextInt();
        for (int i=0;i<l;i++){
            for (int j=i;j<=l;j++){
                System.out.print(" ");
            }
            for (int j=1;j<i;j++){
                System.out.print("*");
            }
            for (int j=1;j<=i;j++){
                System.out.print("*");
            }
            System.out.println();
        }
    }
}