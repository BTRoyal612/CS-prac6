#include <string>

#include "VMTranslator.h"

using namespace std;

/** Generate Hack Assembly code for a VM push operation assessed in Practical Assignment 6 */
string VMTranslator::vm_push(string segment, int offset){
    return "";
}

/** Generate Hack Assembly code for a VM pop operation assessed in Practical Assignment 6 */
string VMTranslator::vm_pop(string segment, int offset){    
    return "";
}

/** Generate Hack Assembly code for a VM add operation assessed in Practical Assignment 6 */
string VMTranslator::vm_add(){
    string trans = "";
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
    trans += "@SP\n"; // get (not pop) value into M
    trans += "A=M-1\n"; 
    trans += "M=-M\n"; // and negate it 
    return trans;
}

/** Generate Hack Assembly code for a VM eq operation assessed in Practical Assignment 6 */
string VMTranslator::vm_eq(){
    return "";
}

/** Generate Hack Assembly code for a VM gt operation assessed in Practical Assignment 6 */
string VMTranslator::vm_gt(){
    return "";
}

/** Generate Hack Assembly code for a VM lt operation assessed in Practical Assignment 6 */
string VMTranslator::vm_lt(){
    return "";
}

/** Generate Hack Assembly code for a VM and operation assessed in Practical Assignment 6 */
string VMTranslator::vm_and(){
    string trans = "";
    trans += "@SP\n"; // pop first value into D
    trans += "AM=M-1\n";
    trans += "D=M\n";
    trans += "@SP\n"; // get second value into M
    trans += "A=M-1\n";
    trans += "M=D&M\n"; // put result back on stack
    return "";
}

/** Generate Hack Assembly code for a VM or operation assessed in Practical Assignment 6 */
string VMTranslator::vm_or(){
    string trans = "";
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