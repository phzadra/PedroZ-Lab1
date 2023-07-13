//1..
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

//2. The flag0 initialized = 0.
//2. When interrupt calls the function, flag0 will be set to 1.
//2. Inside while (true) loop, if flag0 is 1, then print statement, and set flag0 back to 0.
//2. Nothing was being printed, so I decided to print the state of the flag0 inside the same if statement, but still nothing was reporting back.
//2. I decided to move the interrupt function call inside the while (true) loop, and it works now, but in this case the interrupt is only acting as a common function because its inside the loop.
//2. To try and debug I initiallized 2 LEDs. One that would constatly blink inside the while loop, and the second one that would change its state when the interruption was called.
//2. This resulted in the code to running properly. So now I had the LEDs reporting how the code was behaving and the proper requested printf statement "Button pressed" anytime I pressed it.
//2. Once I remove the LEDs to leave the code running properly wihtout the debug techniques, it actually stopped working.
//2. I then inserted a wait_us(100) then the code run properly.
//2. I even left wait_ns(0) and the code still run.
//2. I believe the wait_ns(0) statement allows other threads and interrupts to be executed, ensuring proper multitasking and interrupt handling properly.
//2. If I remove the wait_ns(0) statement, the code may continuously loop without giving other threads or interrupts the opportunity to execute.

//3. I left the wait_ns(0) in place, now the code is running as intended.

//4. Final code as follows:

#include "mbed.h"
InterruptIn bttn(PC_13);
int flag0 = 0;

void bttn_interrupt(){
    flag0 = 1;
}

int main()
{ 
    bttn.fall(&bttn_interrupt);
    while (true) {
        if (flag0 == 1){
            printf("Button pressed\r\n");
            flag0 = 0;       
        }
    wait_ns(0);
    }
}