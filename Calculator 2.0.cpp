// Calculator 2.0.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>

int main()
{
    int stack[1000];
    // sp = индекс €чейки, куда будет push-итьс€ очередное число
    int sp = 0;      // (sp-1) = индекс €чейки, €вл€ющейс€ вершиной стека
    while (!feof(stdin)) {
        int c = getchar();
        int x;
        switch (c) {
        case  ' ':
        case '\n':
            break;
        case '=':
            printf("Result = %d\n", stack[sp - 1]);  sp--;
            break;
        case '+':
            stack[sp - 2] = stack[sp - 2] + stack[sp - 1];  sp--;
            break;
        case '-':
            stack[sp - 2] = stack[sp - 2] - stack[sp - 1];  sp--;
            break;
        case '*':
            stack[sp - 2] = stack[sp - 1] * stack[sp - 2];  sp--;
            break;
        case '/':
            stack[sp - 2] = stack[sp - 2] / stack[sp - 1];   sp--;
            break;
        default:
            ungetc(c, stdin); // вернуть символ обратно в поток
            if (scanf("%d", &x) != 1) {
                fprintf(stderr, "Can't read integer\n");
                return -1;
            }
            else {
                stack[sp] = x;                       sp++;
            }
        }
    }
    printf("Result = %d\n", stack[sp - 1]);
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
