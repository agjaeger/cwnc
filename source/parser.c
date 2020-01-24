
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#include "parser.h"

Token*
new_token (
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
    char* p_string
) {
    // describe the first token
    Token head;
    head.type = TK_START;
    head.next = NULL;

    Token* cur = &head;

    while (*p_string) {
        if (isspace(*p_string)) {
            p_string++;
            continue;
        }

        if (*p_string == '+' || *p_string == '-') {
            cur = new_token(TK_RESERVED, cur, &p_string[0]);
            p_string++;
            continue;
        }

        if (isdigit(*p_string)) {
            cur = new_token(TK_NUM, cur, p_string);

            /*  strtol will greedily get the largest number of
                chars to form a valid base 10 number until the
                next whitespace character
            */
            cur->value = strtol(p_string, &p_string, 10);
            continue;
        }
    }

    // describe the last token
    new_token(TK_EOF, cur, p_string);

    return head.next;
}

bool
at_EOF (
    Token* p_tok
) {
    return p_tok->type == TK_EOF;
}
