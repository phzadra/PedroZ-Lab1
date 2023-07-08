#include "mbed.h"

// main() runs in its own thread in the OS

//1.
/*++ MbedOS Error Info ++
Error Status: 0x80010133 Code: 307 Module: 1
Error Message: Mutex: 0x200015FC, Not allowed in ISR context
Location: 0x800934D
Error Value: 0x200015FC
Current Thread: main Id: 0x20001DB4 Entry: 0x800691F StackSize: 0x1000 StackMem: 0x20000580 SP: 0x2009FF54 
For more info, visit: https://mbed.com/s/error?error=0x80010133&tgt=B_L4S5I_IOT01A
-- MbedOS Error Info --

Meaning: Rtos Mutex Error
This error is triggered when a Mutex object error occurs in Kernel/RTOS layer.
*/


InterruptIn bttn(PC_13);


void bttn_interrupt(){
    printf("Button pressed\r\n");
}

int main()
{
    bttn.fall(&bttn_interrupt);
    while (true) {
    }
}

