#include "mbed.h"

// main() runs in its own thread in the OS
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

