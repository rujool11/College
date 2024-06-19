import java.lang.*;
class jagged{
    public static void main(String args[]){
        String [][]arr = new String[4][]; 
        arr[0] = new String[]{"Raja","78","85"};
        arr[1] = new String[]{"Dev","81","89","90","76"};
        arr[2] = new String[]{"Arush","54","67","78"};
        arr[3] = new String[]{"John","56","87","54","45","78"};
        
        for (int i=0;i<4;i++){
            for (int j=0;j<arr[i].length;j++){
                System.out.print(arr[i][j]+ " ");
            }
            System.out.println();
        }
    }
}