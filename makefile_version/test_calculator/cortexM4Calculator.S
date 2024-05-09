/*
 * For a list of the instructions to use for the M4, please refer to
 * https://developer.arm.com/documentation/ddi0439/b/CHDDIGAC
*/

.syntax unified

.global additionAssembly
.type additionAssembly,%function
.align 2
additionAssembly:
    push {r4-r11, r14}

    ADD r0, r0, r1

    pop {r4-r11, pc}

.global substractionAssembly
.type substractionAssembly,%function
.align 2
substractionAssembly:
    push {r4-r11, r14}

    SUB r0, r0, r1

    pop {r4-r11, pc}


.global multiplicationAssembly
.type multiplicationAssembly,%function
.align 2
multiplicationAssembly:
    push {r4-r11, r14}

    MUL r0, r0, r1

    pop {r4-r11, pc}