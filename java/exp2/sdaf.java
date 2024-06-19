import java.util.*;
class sdaf{
    public static void main(String args[]){
        Scanner s = new Scanner(System.in);
        int size = s.nextInt();
        int []arr1 = new int[size];
        System.out.println(arr1.length);
        for (int i=0;i<size;i++){
            arr1[i]= s.nextInt();
        }
        for (int i=0;i<size;i++){
            System.out.println(arr1[i]);
        }
    }
}