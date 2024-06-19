import java.util.*;
class LL{
    public static void main(String args[]){
    LinkedList<String>list = new LinkedList<String>();
    list.add("Python");
    list.add("C++/C");
    list.add("Java");
    list.add("Ruby");
    list.add("JavaScript");
    list.add("Rust");
    System.out.println(list);
    System.out.println(list.size());
    for (int i=0;i<list.size();i++){
        if (list.get(i).charAt(0) == 'C'){
        list.remove(i);
        }
    }
    list.set(2,"C#");
    System.out.println(list);

    }
}