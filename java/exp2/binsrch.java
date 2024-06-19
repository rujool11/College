import java.util.*;
class binsrch{
    public static void main(String args[]){
        Scanner s = new Scanner(System.in);
        System.out.println("enter the key");
        int key = s.nextInt();
        int []arr = {10,2,4,6,8};
        Arrays.sort(arr);
        int a = BinSearch(arr,key,0,4) + 1;
        if (a==0){
            System.out.println("not found in the array");
        }
        else {
            System.out.println("found in the array at "+ a + "in the sorted array");
        }
    }
    public static int BinSearch(int []z,int key,int low, int high){
        int mid = (low+high)/2;
        while (low<=high){
            if (z[mid] == key){
                return mid;
            }
            else if (z[mid] < key){
                return BinSearch(z,key,mid+1,high);
            }
            else if (z[mid] > key){
                return BinSearch(z,key,low,mid-1);
            }
        }
        return -1;
    }
}