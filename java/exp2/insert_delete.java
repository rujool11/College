import java.util.*;
class insert_delete{
    public static void main(String args[]){
        Scanner s = new Scanner(System.in);
        int []arr = new int[10];
        System.out.println("enter the elements of array");
        for (int i=0;i<9;i++){
            arr[i] = s.nextInt();
        }
        System.out.println("enter the location and element to insert");
        int location = s.nextInt() - 1;
        int element = s.nextInt();
        for (int i=arr.length-2;i>=location;i--){
            arr[i+1] = arr[i];
        }
        arr[location] = element;
        Pprint(arr);
        System.out.println("enter the location to delete");
        int del_loc = s.nextInt() - 1;
        for (int i=del_loc;i<arr.length-1;i++){
            arr[i] = arr[i+1];
        }
        arr[9]=0;
        Pprint(arr);
    }
    public static void Pprint(int []arr){
        System.out.print("{ ");
        for (int i=0;i<arr.length;i++){
            System.out.print(arr[i] + ", ");
        }
        System.out.println("}");
    }
}