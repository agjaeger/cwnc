
#include <stdbool.h>
#include <stdio.h>

#include "parser.h"

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

int main () {
    g_tokenList = tokenize(" 12 + 34 - 5 ");

    Token* listHead = &g_tokenList[0];
    while (!at_EOF(listHead)) {
        printToken(*listHead);
        listHead = listHead->next;
    }

    return 0;
}
