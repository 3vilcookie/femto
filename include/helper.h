#ifndef HELPER_H
#define HELPER_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdarg.h>

#define MIN(x,y) (x<y ? x : y)
#define MAX(x,y) (x>y ? x : y)
#define CLAMP(x,l,h) (MAX(MIN(x,h),l))

/* Fun-Fact: This directive is a really bad an imprecise log10 */
#define DIGITS(x) ( x <   10 ? 1 :   \
                  ( x <  100 ? 2 :   \
                  ( x < 1000 ? 3 : 4 )))

#define lprintf(l,...) (lprintf_(l, __FILE__, __LINE__, __VA_ARGS__));

typedef enum{
    /* Program must exit */
    LOG_ERROR = 0,

    /* Program can still run in defined state */
    LOG_WARNING,

    /* Wow, I didn't know that. Sounds interesting */
    LOG_INFO,

    /* Developers daily bread */
    LOG_DEBUG
} LOG_LEVEL;
void lopen(char* filename, LOG_LEVEL level);
void lprintf_(LOG_LEVEL l, char* location, int line, char *format,...);
void lclose();
#endif // HELPER_H