// The machine code generated by your program should go here
// push pointer0
@0
D=A
@3
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

// push temp0
@0
D=A
@5
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1

(END)
@END
0;JMP