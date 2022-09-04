//
// Created by mustafa58 on 16.08.2022.
//
/* _Assert function */
#include "assert.h"
#include <stdio.h>
#include <stdlib.h>
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

inline static unsigned int _strlen(const char* str) {
    unsigned int i = 0;
    while (str[i]) ++i;
    return i;
}
inline static const char* fileFromPath(const char *mesg) {
    unsigned int i = _strlen(mesg);
    while (mesg[i] != '/') --i;
    return mesg + i+1;
}

void _Assert(const char *mesg, const char *func, char *test)
{	/* print assertion message and abort */
    fprintf(stderr, "%s: %s: %s", fileFromPath(mesg), func, test);
    fputs(" -- assertion failed\n", stderr);
    abort();
}

void _Assert_Equals(const char *mesg, const char *func, int expr, int res)
{	/* print assertion message and abort */
    fprintf(stderr, "%s: %s", fileFromPath(mesg), func);
    fputs(" -- assertion failed\n", stderr);
    fprintf(stderr, "Expected: %d \n", res);
    fprintf(stderr, "Actual\t: %d \n", expr);
    //abort();
}

inline static unsigned int len_digit(int num) {
    int d=1, l = num;
    while(l >= 10 || l <= -10) {
        l /= 10;
        d++;
    }
    return d;
}

void _Report(int pass, int fail) {
    printf("%d Test(s) completed:" GRN " %d PASS\n" RESET, pass+fail, pass);
    for (int i = 0; i < len_digit(pass + fail); ++i)
        putc(' ', stdout);
    printf("                  :" RED " %d FAIL" RESET ".\n", fail);
}