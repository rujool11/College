import java.util.*;
class arrayavg{
    public static void main(String args[]){
        Scanner s = new Scanner(System.in);
        int[] arr = new int[4];
        System.out.println("enter the elements of array");
        for (int i=0;i<4;i++){
            arr[i] = s.nextInt();
        }
        float sum = 0;
        for (int i=0;i<4;i++){
            sum+=arr[i];
        }
        float avg = sum/4;
        System.out.println("the average is " + avg);

    }
}