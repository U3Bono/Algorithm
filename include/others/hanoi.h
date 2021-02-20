#ifndef _hanoi_h
#define _hanoi_h

#define move HanoiMove

#include <stdio.h>

void hanoiMain(void);
void hanoi(int i, char a, char b, char c);
void move(char x, char b);

#endif