#if !defined(__test_h__)
#define __test_h__
#include <stdio.h>
#include "../list.h"


void assert(char *msg, Status actual, Status expected);
void test_add_to_end(void);
void test_add_to_start(void);
void test_insert_at(void);
void test_remove_from_start(void);
void test_remove_from_end(void);
void test_remove_at(void);
void test_add_unique(void);
void test_clear_list(void);
void test_remove_first_occurrence(void);
void test_remove_all_occurrences(void);
#endif // __test_h__

