#include <stdio.h>
/*
if a function use an argument it must declare variables that will accept values of those 
arguments. These variables are called formal parameters of the function , 
They bahave like any other local variables inside the function
**/
// example function 

// return 1 if c is part of string s: 0 otherwise

int is_in(char *s, char c) {
    while(*s){
        if (**s == c) return 1;
        else s++;
    }
    return 0;
}

// GLOBAL VARIABLES 
// you create global variable by declaring them outside of any function 

int count; // count is a global variable

void func1(void);
void func2(void);

int main (void) {
    count = 100;
    func1();

    return 0;
}

void func1(void){
    int temp;

    temp = count;
    func2();
    printf("count is %d", count); /* will print 100*/

}

void func2(void){
    int count;
    for(count = 0; count <= 10; count++) putchar('.');
}