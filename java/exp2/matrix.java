import java.util.*;
class matrix{
    public static void main(String args[]){
        Scanner s = new Scanner(System.in);
        int [][]mat = new int[3][3];
        System.out.println("enter the array");
        for (int i=0;i<3;i++){
            for (int j=0;j<3;j++){
                mat[i][j] = s.nextInt();
            }
        }
        System.out.println("enter the element to delete");
        int element = s.nextInt();
        Delete(mat,element);
        Pprint(mat);
        int largest = Largest(mat);
        System.out.println("the largest element is " + largest);
        System.out.println("enter the row to sort");
        int row = s.nextInt();
        Sort(mat,row);
        
    }
    public static void Delete(int [][]mat,int el){
        for (int i=0;i<3;i++){
            for (int j=0;j<3;j++){
                if (mat[i][j] == el){
                    mat[i][j] = 0;
                }
            }
        }
        
    }
    public static void Pprint(int [][]mat){
        for (int i=0;i<3;i++){
            System.out.println(mat[i][0]+" "+mat[i][1]+" "+mat[i][2]);
        }
    }
    public static int Largest(int [][]mat){
        int largest = mat[0][0];
        for (int i=0;i<3;i++){
            for (int j=0;j<3;j++){
                if (mat[i][j]>largest){
                    largest = mat[i][j];
                }
            }
        }
        return largest;
    }
    public static void Sort(int [][]mat,int i){
        for (int j=0;j<2;j++){
            for (int k=0;k<2;k++){
                (if mat[i][j]>mat[i][j+1]){
                    int temp = mat[i][j+1];
                    mat[i][j+1] = mat[i][j];
                    mat [i][j] = temp;
                }
            }
        }
        for (int k=0;k<3;k++){
            System.out.print(arr[i][k] + " ");
        }
        System.out.println();
    }
}