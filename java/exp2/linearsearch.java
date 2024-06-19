import java.util.*;
class linearsearch{
    public static void main(String args[]){
        Scanner s = new Scanner(System.in);
        int num,length;
        System.out.println("enter the length of array");
        length = s.nextInt();
        int[] arr = new int[length];
        System.out.println("enter the elements of the array");
        for (int i=0;i<length;i++){
            arr[i] =  s.nextInt();
        }
        System.out.println("enter the element to search");
        num = s.nextInt();
        int counter=0;
        for (int i=0;i<length;i++){
            if (arr[i]==num){
                System.out.println("the element is at index " + i);
                counter = 1;
            }
        }
        if (counter!=1){
            System.out.println("element not found in array");
        } 
    }
}