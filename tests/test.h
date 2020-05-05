#if !defined(__test_h__)
#define __test_h__
#include <stdio.h>
#include "../list.h"


void assert(char *msg, Status actual, Status expected);
void test_add_to_end(List *sample_list);


#endif // __test_h__

