import java.io.BufferedReader;  
import java.io.FileReader;  
import java.io.FileWriter;
import java.io.BufferedWriter;
import java.lang.*;
   
public class Main   
{  
    public static void main(String[] args) throws Exception {  
        BufferedReader reader = new BufferedReader(new FileReader("data.txt"));
        BufferedWriter writer = new BufferedWriter(new FileWriter("data.txt"));

        String word="";
        String line= reader.readLine();
        while (line!=null){
            word = word.concat(line);
            word = word.concat("\n");
            line = reader.readLine();
        }    
        reader.close();
        System.out.println(word);
        writer.close(); 
              
    }  
}  