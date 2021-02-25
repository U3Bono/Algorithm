#ifndef _serialize_h
#define _serialize_h

#include <stdio.h>
#include <string.h>
#include "stringop.h"

int write_table(void *node_list, int length, char *file_name);
int add_table(void *node_list, int length, char *file_name);
int read_table(void *node_list, int start, int length, char *file_name);

#endif