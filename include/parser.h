
#ifndef PARSER_HEADER_FILE
#define PARSER_HEADER_FILE

typedef enum TokenType TokenType;
enum TokenType {
    TK_RESERVED,
    TK_NUM,
    TK_START,
    TK_EOF
};

typedef struct Token Token;
struct Token {
    Token* next;

    TokenType type;
    int value;
    char* string;
};

Token* new_token (TokenType p_type, Token* p_current, char* p_string);
Token* tokenize (char* string);
bool at_EOF (Token* tok);

#endif
