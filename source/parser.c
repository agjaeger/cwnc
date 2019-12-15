
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#include "parser.h"

Token*
newToken (
    TokenType p_type,
    Token* p_current,
    char* p_string
) {
    Token* tok = calloc(1, sizeof(Token));

    tok->type = p_type;
    tok->string = p_string;
    p_current->next = tok;

    return tok;
}

Token*
tokenize (
    char* p_inputString
) {
    Token head;
    head.type = TK_EOF;
    head.next = NULL;

    Token* current = &head;

    return head.next;
}
