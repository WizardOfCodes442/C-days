#include <stdio.h>

int f1(int n);
int f2(void);

int main(void)
{
    int t;
    printf("Enter a number: ");
    scanf("%d", &t);

    /* print proper message */
    t ? f1(t) + f2() : printf("zero entered. \n");

    return 0;
}

int f1(int n) 
{
    printf("%d ", n);
    return 0;
}

int f2(void) 
{
    printf("entered. \n");
    return 0;
}

void menu(void) {
    char ch;

    printf("1. check spelling\n");
    printf("2. correct spelling errors\n");
    printf("3. display spelling errors\n");
    printf("Strike any other key to skip\n ");
    printf("   Enter Your choice: ");

    ch = getchar(); /* read the selection from the keyboard*/

    switch (ch) {
        case '1':
        
    }
}