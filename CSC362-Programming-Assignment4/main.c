//
//  main.c
//  CSC362-Programming-Assignment4
//
//  Created by Andrew Smiley on 3/22/16.
//  Copyright © 2016 Andrew Smiley. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int input, sumOfFactors, closeness,currentFactor;
    sumOfFactors = 0;closeness=0;input=2;currentFactor=0;
    while(input > 1){
        printf("Enter a number: ");
        scanf("%d", &input);
        __asm{
            mov currentFactor, 0        //we always want to start this out by setting  to 0, because they will have retained their value from the last time
            mov sumOfFactors, 0
            mov closeness, 0
        loop:           inc currentFactor
            mov eax, currentFactor
            cmp eax, input
            je calcperc
            mov eax, input
            mov edx, 0
            div currentFactor
            cmp edx, 0
            jne loop
            mov eax, currentFactor
            add eax, sumOfFactors
            mov sumOfFactors, eax
            jmp loop
        calcperc:   mov eax, sumOfFactors
            sub eax, input
            cmp eax, 0
            jle negate
            jmp muldiv
        negate: neg eax
            jmp muldiv
        muldiv:     mov edx, 0
            mov ecx, 100
            mul ecx
            mov edx, 0
            div input
            mov closeness, eax
        }
        
        printf("\nOf the input %d, the closeness was %d, we hit factor %d sum of factors %d\r", input, closeness, currentFactor,sumOfFactors);
        
    }
    /*
     mov eax, currentFactor
     sub eax, input
     cmp currentFactor, 0    //ok so first compare the current factor to the input
     je calcperc
     mov eax, input              //prepare for division
     mov edx, 0
     div currentFactor
     cmp edx, 0                  //check to see if the remainder is 0, if it is, it's a factor
     jne loop                    //if it's not a factor, jump to the start of the loop
     mov eax, sumOfFactors
     add eax, currentFactor      //if it is a factor, then we want to add it to our sum of factors
     mov sumOfFactors, eax
     jmp loop                    // now we just want to go back to the start of the loop
     calcperc:       mov eax, currentFactor    //prepare to write down the recipe! no seriously, prepare to do sum_of_factors-number
     mov edx, 0
     mov ecx, 100
     mul eax
     sub eax, input              //prepare for the division bit
     mov edx, 0
     div input
     mov closeness, eax
     */
    
    return 0;
}
