#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
typedef enum {
    TK_RESERVED,
    TK_NUM,
    TK_EOF
} TokenType;

typedef struct Token Token;
struct Token {
    Token* next;

    TokenType type;
    int value;
    char* string;
};

Token* g_tokenList;

bool atEOF () {
    return g_tokenList->type == TK_EOF;
}


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
    head.next = NULL;

    Token* cur = &head;

    while (*p_inputString) {
        if (isspace(*p_inputString)) {
            p_inputString++;
            continue;
        }

        if (*p_inputString == '+' || *p_inputString == '-') {
            cur = newToken(TK_RESERVED, cur, p_inputString++);
            continue;
        }

        if (isdigit(*p_inputString)) {
            cur = newToken(TK_NUM, cur, p_inputString);
            cur->value = strtol(p_inputString, &p_inputString, 10);
            continue;
        }
    }

    newToken(TK_EOF, cur, p_inputString);

    return head.next;
}

int main () {
    g_tokenList = tokenize(" 12 + 34 - 5 ");

    while (!atEOF()) {
        if (g_tokenList->type == TK_NUM) {
            printf("NUM TOKEN\n");
        } else if (g_tokenList->type == TK_RESERVED) {
            printf("TK_RESERVED\n");
        }


        g_tokenList = g_tokenList->next;
    }

    return 0;
}
