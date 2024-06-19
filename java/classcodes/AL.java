import java.lang.*;
import java.util.*;
class AL{
    public static void main(String args[]){
        ArrayList<String>list = new ArrayList<String>(); // string is the type of element in list
        //the object here is list 
        list.add("Python");
        list.add("C++/C");
        list.add("Java");
        list.add("Ruby");
        list.add("JavaScript");
        list.add("Rust");
        System.out.println(list);
        System.out.println(list.size());
        //to remove item with first char as c
        for (int i=0;i<list.size();i++){
            if (list.get(i).charAt(0) == 'C'){ //use get and set 
                list.remove(i);
            }
        }
        list.set(2,"C#");
        System.out.println(list);
    }
}
// same for linked list and stack