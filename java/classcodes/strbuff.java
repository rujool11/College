import java.lang.*;
class strbuff{
    public static void main(String args[]){
        String a = "Java";
        StringBuffer sb = new StringBuffer(a);
        StringBuilder sbu = new StringBuilder(a); //can do all these functions as well
        System.out.println(sb.append("Programming"));
        System.out.println(sb.insert(1,"book"));
        System.out.println(sb.reverse());
        System.out.println(sb.capacity()); //default capacity is 16 bytes, depends on particular string 
        System.out.println(sb.replace(1,4,"1234")); 
        System.out.println(sb.delete(1,5));
    }
}
