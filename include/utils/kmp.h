#ifndef _kmp_h
#define _kmp_h

#include <stdlib.h>
#include "../container/seqqueue.h"

int kmp_index(char *major, char *pattern);
void get_next_arr(char *pattern, SeqQueue *next_queue);

#endif