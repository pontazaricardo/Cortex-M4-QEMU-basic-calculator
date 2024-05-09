#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include "core/hal.h"

int main(void){

    hal_setup(CLOCK_BENCHMARK);

    hal_send_str("-------------");
    hal_send_str("Hello World.\n");

    // Example on how to print strings with parameters.

    int a, b;
    a=25;
    b=10;
    unsigned char str[100];

    sprintf(str,"String with two parameters: %d, %d.", a, b);
    hal_send_str(str);

    hal_send_str("-------------");

    return 0;
}
