
#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void
printSpaces (
    int p_count
) {
    printf("%*c", p_count, ' ');
}

char*
intToString (
    int p_value
) {
    int length = snprintf(NULL, 0, "%d", p_value);

    char* strbuffer = malloc((length+1) * sizeof(char));
    snprintf(strbuffer, length+1, "%d", p_value);

    return strbuffer;
}

void
error (char* p_fmt, ...) {
    va_list ap;
    va_start(ap, p_fmt);

    vfprintf(stderr, p_fmt, ap);
    fprintf(stderr, "\n");

    exit(1);
}
