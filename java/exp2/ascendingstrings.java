import java.util.*;
import java.lang.*;
class ascendingstrings{
    public static void main(String args[]){
        Scanner s = new Scanner(System.in);
        System.out.println("enter the number of elements");
        int size = s.nextInt() + 1;
        String []arr = new String[size];
        System.out.println("enter the elemnts in array");
        for (int i=0;i<size;i++){
            arr[i] = s.nextLine();
        }
        for (int i=0;i<size-1;i++){
            for (int j=0;j<size-1;j++){
                if (arr[j].compareTo(arr[j+1])>0){
                    String temp = arr[j+1];
                    arr[j+1] = arr[j];
                    arr[j] = temp;
                }
            }
        }
        System.out.println("the array in alphabetical order is : ");
        for (int i=0;i<size;i++){
            System.out.println(arr[i]);
        }
    }
}
// ASK SIR WHY WE NEED TO ADD AN EXTRA +1 IN SIZE