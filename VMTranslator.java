import java.io.*;
import java.util.*;

public class VMTranslator {

    /** Generate Hack Assembly code for a VM push operation assessed in Practical Assignment 6 */
    public static String vm_push(String segment, int offset){
        return "";
    }

    /** Generate Hack Assembly code for a VM pop operation assessed in Practical Assignment 6 */
    public static String vm_pop(String segment, int offset){    
        return "";
    }

    /** Generate Hack Assembly code for a VM add operation assessed in Practical Assignment 6 */
    public static String vm_add(){
        return "";
    }

    /** Generate Hack Assembly code for a VM sub operation assessed in Practical Assignment 6 */
    public static String vm_sub(){
        return "";
    }

    /** Generate Hack Assembly code for a VM neg operation assessed in Practical Assignment 6 */
    public static String vm_neg(){
        return "";
    }

    /** Generate Hack Assembly code for a VM eq operation assessed in Practical Assignment 6 */
    public static String vm_eq(){
        return "";
    }

    /** Generate Hack Assembly code for a VM gt operation assessed in Practical Assignment 6 */
    public static String vm_gt(){
        return "";
    }

    /** Generate Hack Assembly code for a VM lt operation assessed in Practical Assignment 6 */
    public static String vm_lt(){
        return "";
    }

    /** Generate Hack Assembly code for a VM and operation assessed in Practical Assignment 6 */
    public static String vm_and(){
        return "";
    }

    /** Generate Hack Assembly code for a VM or operation assessed in Practical Assignment 6 */
    public static String vm_or(){
        return "";
    }

    /** Generate Hack Assembly code for a VM not operation assessed in Practical Assignment 6 */
    public static String vm_not(){
        return "";
    }

    /** Generate Hack Assembly code for a VM label operation assessed in Practical Assignment 7 */
    public static String vm_label(String label){
        return "";
    }

    /** Generate Hack Assembly code for a VM goto operation assessed in Practical Assignment 7 */
    public static String vm_goto(String label){
        return "";
    }

    /** Generate Hack Assembly code for a VM if-goto operation assessed in Practical Assignment 7 */
    public static String vm_if(String label){
        return "";
    }

    /** Generate Hack Assembly code for a VM function operation assessed in Practical Assignment 7 */
    public static String vm_function(String function_name, int n_vars){
        return "";
    }

    /** Generate Hack Assembly code for a VM call operation assessed in Practical Assignment 7 */
    public static String vm_call(String function_name, int n_args){
        return "";
    }

    /** Generate Hack Assembly code for a VM return operation assessed in Practical Assignment 7 */
    public static String vm_return(){
        return "";
    }

    /** A quick-and-dirty parser when run standalone. */ 
    public static void main(String[] args){
        if(args.length > 0){
            try {
                Scanner sc = new Scanner(new File(args[0]));
                while (sc.hasNextLine()) {
                    String[] tokens = sc.nextLine().trim().toLowerCase().split("\\s+");
                    if(tokens.length==1){
                        if(tokens[0].equals("add")){
                            System.out.println(vm_add());
                        } else if(tokens[0].equals("sub")){
                            System.out.println(vm_sub());
                        } else if(tokens[0].equals("neg")){
                            System.out.println(vm_neg());
                        } else if(tokens[0].equals("eq")){
                            System.out.println(vm_eq());
                        } else if(tokens[0].equals("gt")){
                            System.out.println(vm_gt());
                        } else if(tokens[0].equals("lt")){
                            System.out.println(vm_lt());
                        } else if(tokens[0].equals("and")){
                            System.out.println(vm_and());
                        } else if(tokens[0].equals("or")){
                            System.out.println(vm_or());
                        } else if(tokens[0].equals("not")){
                            System.out.println(vm_not());
                        } else if(tokens[0].equals("return")){
                            System.out.println(vm_return());
                        }
                    } else if(tokens.length==2){
                        if(tokens[0].equals("label")){
                            System.out.println(vm_label(tokens[1]));
                        } else if(tokens[0].equals("goto")){
                            System.out.println(vm_goto(tokens[1]));
                        } else if(tokens[0].equals("if")){
                            System.out.println(vm_if(tokens[1]));
                        }
                    } else if(tokens.length==3){
                        int t2;
                        try {
                            t2 = Integer.parseInt(tokens[2]);
                        } catch (Exception e) {
                            System.err.println("Unable to parse int.");
                            break;
                        }
                        if(tokens[0].equals("push")){
                            System.out.println(vm_push(tokens[1],t2));
                        } else if(tokens[0].equals("pop")){
                            System.out.println(vm_pop(tokens[1],t2));
                        } else if(tokens[0].equals("function")){
                            System.out.println(vm_function(tokens[1],t2));
                        } else if(tokens[0].equals("call")){
                            System.out.println(vm_call(tokens[1],t2));
                        }
                    }
                }
                sc.close();
            } catch (FileNotFoundException e) {
                System.err.println("File not found.");
            }
        }
    }
        
}