import java.util.Scanner;
class JavaException{
    float weight, height;
    JavaException(float weight,float height){
        this.weight = weight;
        this.height = height;
    }
    
    public void checkBMI(){
        if (this.weight/(this.height*this.height)>=25){
            System.out.println("You are Overweight");
        }else{
            System.out.println("you had normal weight");
        }
    }
}

public class Main{
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.println("enter height and weight");
        float ht = s.nextFloat();
        float wt = s.nextFloat();
        try{
            JavaException obj = new JavaException(wt,ht);
            obj.checkBMI();}
        finally{
            System.out.println("rest of the code");
        }
    }
}