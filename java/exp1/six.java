import java.util.*;
import java.util.Date;    
class six{
	
    private static void main(String args[]){
        Scanner s1 = new Scanner(System.in);
        System.out.println("enter birth year");
        int birthYear = s1.nextInt();
        Date d = new Date();
        int currYear = d.getYear() + 1900; 
        int diff = currYear - birthYear;
        System.out.println("your age is " + diff + "years");
    }
}
