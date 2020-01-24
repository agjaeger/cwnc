
#include <stdbool.h>
#include <stdio.h>

#include "parser.h"
#include "utils.h"
#include "asm.h"

Token* g_tokenList;

void
printToken (
  Token p_tok
) {
    switch (p_tok.type) {
        case TK_RESERVED:
            printf("Reserved Token");
            printf(": %c\n", *p_tok.string);
            break;
        case TK_NUM:
            printf("Number Token");
            printf(": %d\n", p_tok.value);
            break;
        case TK_START:
            printf("Start Token\n");
            break;
        case TK_EOF:
            printf("EOF Token\n");
            break;
    }
}

bool
isOperation (
    Token* o_tok,
    char p_op
) {
    if (o_tok->type != TK_RESERVED || o_tok->string[0] != p_op)
        return false;

    return true;
}

int
expect_number (
    Token* o_tok
) {
    if (o_tok->type != TK_NUM) {
        error("Expected Number! Got %c", o_tok->string[0]);
    }

    int value = o_tok->value;
    o_tok = o_tok->next;

    return value;
}

int main () {
    g_tokenList = tokenize(" 13 + 34 - 5 + 3");

    Token* listHead = &g_tokenList[0];

    asm_printHeader();
    asm_printLabel("main");

    asm_printOp(
        "mov",
        rax,
        intToString(expect_number(listHead))
    );

    while (!at_EOF(listHead)) {
        if (isOperation(listHead, '+')) {
            listHead = listHead->next;

            asm_printOp(
                "add",
                rax,
                intToString(expect_number(listHead))
            );

            continue;
        }

        if (isOperation(listHead, '-')) {
            listHead = listHead->next;

            asm_printOp(
                "sub",
                rax,
                intToString(expect_number(listHead))
            );
        }

        listHead = listHead->next;
    }

    asm_printReturn();

    return 0;
}
