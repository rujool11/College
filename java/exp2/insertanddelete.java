import java.util.*;
class insertanddelete{
    Scanner s = new Scanner(System.in);
    public static void main(String args[]){
        int []arr = new int[10];
        System.out.println("enter the array");
        for (int i=0;i<9;i++){
            arr[i] = s.nextInt();
        }
        System.out.println("enter 0 for deletion, 1 for insertion");
        int choice = s.nextInt();
        if (choice == 0){
            Deletion(arr);
        }
        // else if (choice == 1){
        //     Insertion(arr);
        // }
        else {
            System.out.println("enter valid choice");
        }
    }
    public static void Deletion(int []z){
        System.out.prinln("enter the location");
        int location = s.nextInt();
        for (int i=location;i<=8;i++){
        z[i-1] = z[i];
    }
    for (int j=0;j<=7;j++){
        System.out.print(z[j]);
    }
    System.out.println();
    }
}