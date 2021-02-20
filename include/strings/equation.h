#ifndef _equation_h
#define _equation_h

#include "../container/seqqueue.h"
#include "../container/linkstack.h"
#include "string.h"

void equationMain();
double calculate(char* s);
void postfixEquation(char *s, SeqQueue* seqQueue);
int signGrade(char c);

#endif