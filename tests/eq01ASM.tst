// eq Test file 01
// compares with the results from generated from the VM test file.
// Run using CPUEmulator

load eq01.asm,
output-file eq01.out,
compare-to eq01.cmp,
output-list RAM[0]%D1.6.1 RAM[1]%D1.6.1 RAM[2]%D1.6.1 RAM[3]%D1.6.1 RAM[4]%D1.6.1
            RAM[256]%D1.6.1 RAM[257]%D1.6.1 RAM[258]%D1.6.1
            RAM[300]%D1.6.1 RAM[301]%D1.6.1
            RAM[400]%D1.6.1 RAM[401]%D1.6.1 
            RAM[3000]%D1.6.1 RAM[3001]%D1.6.1
            RAM[3010]%D1.6.1 RAM[3011]%D1.6.1;

set RAM[0] 259,     // stack pointer
set RAM[1] 300,     // base address of the local segment
set RAM[2] 400,     // base address of the argument segment
set RAM[3] 3000,    // base address of the this segment
set RAM[4] 3010,    // base address of the that segment
set RAM[256] 0,
set RAM[257] 10,
set RAM[258] 50,

repeat 100 {        // Change this number to cover the number of instructions in the asm test file
  ticktock;
}

output;