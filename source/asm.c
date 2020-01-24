
#include "asm.h"

#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

int g_asm_indent = 0;

void
asm_printHeader () {
    char* asmheader =
        ".intel_syntax noprefix\n"
        ".global main\n";

    printf("%s", asmheader);
}

void
asm_printLabel (
    char* p_labelName
) {
    printf("%s:\n", p_labelName);
    g_asm_indent = 4;
}

void
asm_printOp (
    char* p_operation,
    char* p_arg1,
    char* p_arg2
) {
    printSpaces(g_asm_indent);
    printf("%s %s, %s\n",
        p_operation,
        p_arg1,
        p_arg2
    );
}

void
asm_printReturn () {
    printSpaces(g_asm_indent);
    printf("ret\n");
}
