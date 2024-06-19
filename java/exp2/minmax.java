import java.util.*;
class minmax{
    public static void main(String args[]){
        Scanner s = new Scanner(System.in);
        int []arr = new int[10];
        System.out.println("enter the elements in the array");
        for (int i=0;i<10;i++){
            arr[i] = s.nextInt();
        }
        int min = arr[0],max = arr[0];
        for (int j=0;j<10;j++){
            if (arr[j]>max){
                max = arr[j];
            }
            if (arr[j]<min){
                min = arr[j];
            }
        }
        System.out.println("the max value is " + max);
        System.out.println("the min value is " + min);
    }
}