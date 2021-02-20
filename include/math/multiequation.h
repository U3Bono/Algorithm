#ifndef _multiequantion_h
#define _multiequantion_h

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../tools/mathfunc.h"

#define EPS 1e-8 //解的精度

void multiEquationMain(void);
double dichotomy(double (*fp)(double x), int a, int b);                      //二分法
double newtonIM(double x, double (*fp1)(double x), double (*fp2)(double x)); //牛顿迭代法
double sectionChord(double (*fp)(double x), int a, int b);                   //旋截法

#endif