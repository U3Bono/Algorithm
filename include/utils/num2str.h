#ifndef _num2str_h
#define _num2str_h

#include <math.h>
#include "../container/linkstack.h"

#define MAX_BIT 16 //总位数，double最长表示位数15位

void numConvert(double a, char *s, int length);
char num2char(unsigned int n);

#endif