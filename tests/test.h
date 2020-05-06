#if !defined(__test_h__)
#define __test_h__
#include <stdio.h>
#include "../list.h"


void assert(char *msg, Status actual, Status expected);
void test_add_to_end(void);
void test_add_to_start(void);
void test_insert_at(void);
void test_remove_from_start(void);
#endif // __test_h__

