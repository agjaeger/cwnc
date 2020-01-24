
#ifndef PARSER_ASM_H
#define PARSER_ASM_H

extern int g_asm_indent;

void asm_printHeader ();
void asm_printLabel (char* p_labelName);
void asm_printOp (char* p_operation, char* p_arg1, char* p_arg2);
void asm_printReturn ();

#endif /* end of include guard: PARSER_ASM_H */
