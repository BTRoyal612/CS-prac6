#include <string>

#include "VMTranslator.h"

using namespace std;

/** Generate Hack Assembly code for a VM push operation assessed in Practical Assignment 6 */
string VMTranslator::vm_push(string segment, int offset){
    string trans = "";
    trans += "// push " + segment + to_string(offset) + "\n";
    if (segment == "constant") {
        trans += "@" + to_string(offset) + "\n"; // load index into A
        trans += "D=A\n"; // move it to D
        trans += "@SP\n"; // load 0 into A (M[0] contains stack pointer)
        trans += "A=M\n"; // load stack pointer
        trans += "M=D\n"; // put D onto stack
        trans += "@SP\n"; // load stack pointer address into A
        trans += "M=M+1\n"; // increment stack pointer
    } else if (segment == "static") {
        trans += "@" + to_string(offset + 16) + "\n";
        trans += "D=M\n";
        trans += "@SP\n";
        trans += "A=M\n"; 
        trans += "M=D\n";
        trans += "@SP\n";
        trans += "M=M+1\n";
    } else {
        trans += "@" + to_string(offset) + "\n"; // get value into D
        trans += "D=A\n";
        
        if (segment == "this") {
            trans += "@THIS\n";
            trans += "A=M+D\n";
        } else if (segment == "that") {
            trans += "@THAT\n";
            trans += "A=M+D\n";
        } else if (segment == "argument") {
            trans += "@ARG\n";
            trans += "A=M+D\n";
        } else if (segment == "local") {
            trans += "@LCL\n";
            trans += "A=M+D\n";
        } else if (segment == "temp") {
            trans += "@5\n";
            trans += "A=A+D\n";
        } else if (segment == "pointer") {
            trans += "@3\n";
            trans += "A=A+D\n";
        }

        trans += "D=M\n";
        trans += "@SP\n"; // put it onto the stack
        trans += "A=M\n";
        trans += "M=D\n";
        trans += "@SP\n"; // increment the stack pointer
        trans += "M=M+1\n";
    }
    
    return trans;
}

/** Generate Hack Assembly code for a VM pop operation assessed in Practical Assignment 6 */
string VMTranslator::vm_pop(string segment, int offset){  
    string trans = "";
    trans += "// pop " + segment + to_string(offset) + "\n";
    if (segment == "static") {
        trans += "@SP\n"; // pop value into D
        trans += "AM=M-1\n";
        trans += "D=M\n";
        trans += "@" + to_string(16 + offset) + "\n";
        trans += "M=D\n";
    } else {
        trans += "@" + to_string(offset) + "\n"; // get address into R13
        trans += "D=A\n";

        if (segment == "this") {
            trans += "@THIS\n";
            trans += "D=M+D\n";
            trans += "@R13\n";
            trans += "M=D\n";
            trans += "@SP\n"; // pop value into D
            trans += "AM=M-1\n";
            trans += "D=M\n";
            trans += "@R13\n"; // address back in A (no touchy D)
            trans += "A=M\n";
            trans += "M=D\n";
        } else if (segment == "that") {
            trans += "@THAT\n";
            trans += "D=M+D\n"; 
            trans += "@R13\n";
            trans += "M=D\n";
            trans += "@SP\n"; // pop value into D
            trans += "AM=M-1\n";
            trans += "D=M\n";
            trans += "@R13\n"; // address back in A (no touchy D)
            trans += "A=M\n";
            trans += "M=D\n";
        } else if (segment == "argument") {
            trans += "@ARG\n";
            trans += "D=M+D\n"; 
            trans += "@R13\n";
            trans += "M=D\n";
            trans += "@SP\n"; // pop value into D
            trans += "AM=M-1\n";
            trans += "D=M\n";
            trans += "@R13\n"; // address back in A (no touchy D)
            trans += "A=M\n";
            trans += "M=D\n";
        } else if (segment == "local") {
            trans += "@LCL\n";
            trans += "D=M+D\n"; 
            trans += "@R13\n";
            trans += "M=D\n";
            trans += "@SP\n"; // pop value into D
            trans += "AM=M-1\n";
            trans += "D=M\n";
            trans += "@R13\n"; // address back in A (no touchy D)
            trans += "A=M\n";
            trans += "M=D\n";
        } else if (segment == "pointer") {
            trans += "@3\n";
            trans += "D=A+D\n"; 
            trans += "@R13\n";
            trans += "M=D\n";
            trans += "@SP\n"; // pop value into D
            trans += "AM=M-1\n";
            trans += "D=M\n";
            trans += "@R13\n"; // address back in A (no touchy D)
            trans += "A=M\n";
            trans += "M=D\n";
        } else if (segment == "temp") {
            trans += "@5\n";
            trans += "D=A+D\n"; 
            trans += "@R13\n";
            trans += "M=D\n";
            trans += "@SP\n"; // pop value into D
            trans += "AM=M-1\n";
            trans += "D=M\n";
            trans += "@R13\n"; // address back in A (no touchy D)
            trans += "A=M\n";
            trans += "M=D\n";
        }
    }

    return trans;
}

/** Generate Hack Assembly code for a VM add operation assessed in Practical Assignment 6 */
string VMTranslator::vm_add(){
    string trans = "";
    trans += "// add \n";
    trans += "@SP\n"; // pop first value into D
    trans += "AM=M-1\n";
    trans += "D=M\n";
    trans += "@SP\n"; // pop second value into M
    trans += "AM=M-1\n"; 
    trans += "M=D+M\n"; // push sum onto M
    trans += "@SP\n";
    trans += "M=M+1\n"; 
    return trans;
}

/** Generate Hack Assembly code for a VM sub operation assessed in Practical Assignment 6 */
string VMTranslator::vm_sub(){
    string trans = "";
    trans += "// sub \n";
    trans += "@SP\n"; // pop first value into D
    trans += "AM=M-1\n";
    trans += "D=M\n"; 
    trans += "@SP\n"; // pop second value into M
    trans += "AM=M-1\n"; 
    trans += "M=M-D\n"; // push difference onto M
    trans += "@SP\n";
    trans += "M=M+1\n"; 
    return trans;
}

/** Generate Hack Assembly code for a VM neg operation assessed in Practical Assignment 6 */
string VMTranslator::vm_neg(){
    string trans = "";
    trans += "// neg \n";
    trans += "@SP\n"; // get (not pop) value into M
    trans += "A=M-1\n"; 
    trans += "M=-M\n"; // and negate it 
    return trans;
}

/** Generate Hack Assembly code for a VM eq operation assessed in Practical Assignment 6 */
string VMTranslator::vm_eq(){
    string trans = "";
    static int count = 0;
    string label = to_string(count);
    count++;
    trans += "// eq " + label + "\n";
    trans += "@SP\n"; // pop first value into D
    trans += "AM=M-1\n";
    trans += "D=M\n";
    trans += "@SP\n"; // get second value into M
    trans += "A=M-1\n";
    trans += "D=M-D\n"; // D = older value - newer
    trans += "M=-1\n"; // tentatively put true on stack
    trans += "@eqTrue" + label + "\n"; // and jump to end if so
    trans += "D;JEQ\n";
    trans += "@SP\n"; // set to false otherwise
    trans += "A=M-1\n";
    trans += "M=0\n";
    trans += "(eqTrue" + label + ")\n";
    return trans;
}

/** Generate Hack Assembly code for a VM gt operation assessed in Practical Assignment 6 */
string VMTranslator::vm_gt(){
    string trans = "";
    static int count = 0;
    string label = to_string(count);
    count++;
    trans += "// gt " + label + "\n";
    trans += "@SP\n"; // pop first value into D
    trans += "AM=M-1\n";
    trans += "D=M\n";
    trans += "@SP\n"; // get second value into M
    trans += "A=M-1\n";
    trans += "D=M-D\n"; // D = older value - newer
    trans += "M=-1\n"; // tentatively put true on stack
    trans += "@gtTrue" + label + "\n"; // and jump to end if so
    trans += "D;JGT\n";
    trans += "@SP\n"; // set to false otherwise
    trans += "A=M-1\n";
    trans += "M=0\n";
    trans += "(gtTrue" + label + ")\n";
    return trans;
}

/** Generate Hack Assembly code for a VM lt operation assessed in Practical Assignment 6 */
string VMTranslator::vm_lt(){
    string trans = "";
    static int count = 0;
    string label = to_string(count);
    count++;
    trans += "// lt " + label + "\n";
    trans += "@SP\n"; // pop first value into D
    trans += "AM=M-1\n";
    trans += "D=M\n"; 
    trans += "@SP\n"; // get second value into M
    trans += "A=M-1\n";
    trans += "D=M-D\n"; // D = older value - newer
    trans += "M=-1\n"; // tentatively put true on stack
    trans += "@ltTrue" + label + "\n"; // and jump to end if so
    trans += "D;JLT\n";
    trans += "@SP\n"; // set to false otherwise
    trans += "A=M-1\n";
    trans += "M=0\n"; 
    trans += "(ltTrue" + label + ")\n";
    return trans;
}

/** Generate Hack Assembly code for a VM and operation assessed in Practical Assignment 6 */
string VMTranslator::vm_and(){
    string trans = "";
    trans += "// and\n";
    trans += "@SP\n"; // pop first value into D
    trans += "AM=M-1\n";
    trans += "D=M\n";
    trans += "@SP\n"; // get second value into M
    trans += "A=M-1\n";
    trans += "M=D&M\n"; // put result back on stack
    return trans;
}

/** Generate Hack Assembly code for a VM or operation assessed in Practical Assignment 6 */
string VMTranslator::vm_or(){
    string trans = "";
    trans += "// or\n";
    trans += "@SP\n"; // pop first value into D
    trans += "AM=M-1\n";
    trans += "D=M\n"; 
    trans += "@SP\n"; // get second value into M
    trans += "A=M-1\n";
    trans += "M=D|M\n"; // put result back on stack
    return trans;
}

/** Generate Hack Assembly code for a VM not operation assessed in Practical Assignment 6 */
string VMTranslator::vm_not(){
    string trans = "";
    trans += "// not\n";
    trans += "@SP\n"; // get (not pop) value into M
    trans += "A=M-1\n"; 
    trans += "M=!M\n"; // and negate it 
    return trans;
}

/** Generate Hack Assembly code for a VM label operation assessed in Practical Assignment 7 */
string VMTranslator::vm_label(string label){
    return "";
}

/** Generate Hack Assembly code for a VM goto operation assessed in Practical Assignment 7 */
string VMTranslator::vm_goto(string label){
    return "";
}

/** Generate Hack Assembly code for a VM if-goto operation assessed in Practical Assignment 7 */
string VMTranslator::vm_if(string label){
    return "";
}

/** Generate Hack Assembly code for a VM function operation assessed in Practical Assignment 7 */
string VMTranslator::vm_function(string function_name, int n_vars){
    return "";
}

/** Generate Hack Assembly code for a VM call operation assessed in Practical Assignment 7 */
string VMTranslator::vm_call(string function_name, int n_args){
    return "";
}

/** Generate Hack Assembly code for a VM return operation assessed in Practical Assignment 7 */
string VMTranslator::vm_return(){
    return "";
}