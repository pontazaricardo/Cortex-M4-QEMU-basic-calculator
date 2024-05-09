#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "core/hal.h"

#include "cortexM4Calculator.h"
#include "referenceCalculator.h"

#define additionASMInjected_asm(a,b,c)          \
        __asm__ volatile ("ADD %2, %0, %1\n\t"  \
                    :"+r"(a),"+r"(b),"+r"(c)    \
                    );                          \

#define substractionASMInjected_asm(a,b,c)          \
        __asm__ volatile ("SUB %2, %0, %1\n\t"  \
                    :"+r"(a),"+r"(b),"+r"(c)    \
                    );                          \


#define multiplicationASMInjected_asm(a,b,c)          \
        __asm__ volatile ("MUL %2, %0, %1\n\t"  \
                    :"+r"(a),"+r"(b),"+r"(c)    \
                    );                          \



int test_additionAssembly(void){
    uint32_t a,b,resultAssemlby, resultReference, resultAssemblyInjected;

    a = 15;
    b = 2345;
    resultAssemblyInjected = 0;

    resultAssemlby = additionAssembly(a,b);
    resultReference =additionReference(a,b);

    additionASMInjected_asm(a, b, resultAssemblyInjected);

    if((resultReference == resultAssemlby) && (resultReference == resultAssemblyInjected)){
        return 0;
    }else{
        return -1;
    }
}

int test_substractionAssembly(void){
    uint32_t a,b,resultAssemlby, resultReference, resultAssemblyInjected;

    a = 15;
    b = 2345;
    resultAssemblyInjected = 0;

    resultAssemlby = substractionAssembly(a,b);
    resultReference =substractionReference(a,b);

    substractionASMInjected_asm(a, b, resultAssemblyInjected);

    if((resultReference == resultAssemlby) && (resultReference == resultAssemblyInjected)){
        return 0;
    }else{
        return -1;
    }
}

int test_multiplicationAssembly(void){
    uint32_t a,b,resultAssemlby, resultReference, resultAssemblyInjected;

    a = 15;
    b = 2345;
    resultAssemblyInjected = 0;

    resultAssemlby = multiplicationAssembly(a,b);
    resultReference =multiplicationReference(a,b);

    multiplicationASMInjected_asm(a, b, resultAssemblyInjected);

    if((resultReference == resultAssemlby) && (resultReference == resultAssemblyInjected)){
        return 0;
    }else{
        return -1;
    }
}


void test_cycleCounter(void){
    uint64_t t0, t1;
    unsigned char str[100];

    t0 = hal_get_time();

    //This function is only for test the cycle count

    int pivot=0;
    for(int i=0;i<5000;i++){
        pivot++;
    }

    t1 = hal_get_time();
    hal_send_str("-------------");

    sprintf(str,"Total number of cycles: %llu cycles", t1-t0);
    hal_send_str(str);

    hal_send_str("  - If running on QEMU, this value doesn't matter, as it changes because of the OS.");
    hal_send_str("  - If running in bare metal, this value should be constant.");
    hal_send_str("-------------");
}


int main(void){
    hal_setup(CLOCK_BENCHMARK);
    hal_send_str("====== START ======");

    if(test_additionAssembly()){
        hal_send_str("ERROR ADDITION ASSEMBLY");
    } else {
        hal_send_str("OK ADDITION ASSEMBLY");
    }
    hal_send_str("#");


    if(test_substractionAssembly()){
        hal_send_str("ERROR SUBSTRACTION ASSEMBLY");
    } else {
        hal_send_str("OK SUBSTRACTION ASSEMBLY");
    }
    hal_send_str("#");


    if(test_multiplicationAssembly()){
        hal_send_str("ERROR MULTIPLICATION ASSEMBLY");
    } else {
        hal_send_str("OK MULTIPLICATION ASSEMBLY");
    }
    hal_send_str("#");

    test_cycleCounter();

    return 0;
}

