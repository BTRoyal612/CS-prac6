// push VM Test file 03
// does not compare, but generates a .cmp file for the given .vm file
// Run using VMEmulator

load push03.vm,
output-file push03.cmp,
output-list RAM[0]%D1.6.1 RAM[1]%D1.6.1 RAM[2]%D1.6.1 RAM[3]%D1.6.1 RAM[4]%D1.6.1
            RAM[256]%D1.6.1 RAM[257]%D1.6.1 RAM[258]%D1.6.1 RAM[259]%D1.6.1
            RAM[300]%D1.6.1 RAM[301]%D1.6.1
            RAM[400]%D1.6.1 RAM[401]%D1.6.1 
            RAM[3000]%D1.6.1 RAM[3001]%D1.6.1
            RAM[3010]%D1.6.1 RAM[3011]%D1.6.1;

set sp 256,        // stack pointer
set local 300,     // base address of the local segment
set argument 400,  // base address of the argument segment
set this 3000,     // base address of the this segment
set that 3010,     // base address of the that segment
set RAM[300] 10,
set RAM[301] -10,
set RAM[400] 100,
set RAM[401] -100,
set RAM[3000] 1000,
set RAM[3001] -1000,
set RAM[3010] 10000,
set RAM[3011] -10000,

repeat 4 {        // Change this number to cover the number of instructions in the VM test file
  vmstep;
}

output;
