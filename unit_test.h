#ifndef UNIT_TEST_H
#define UNIT_TEST_H
#include "my_string.h"
#include <string.h>

Status test_init_default_returns_nonNULL(char* buffer, int length);
Status test_get_size_on_init_default_returns_0(char* buffer, int length);
Status test_adaly_init_default_capacity_is_7(char* buffer, int length);
Status test_adaly_init_c_string_returns_nonNULL(char* buffer, int length);
Status test_adaly_init_c_string_returns_correct_size(char* buffer, int length);
Status test_adaly_init_c_string_returns_correct_capacity(char* buffer, int length);
Status test_adaly_compare_strings_left_is_smaller(char* buffer, int length);
Status test_adaly_compare_strings_left_is_bigger(char* buffer, int length);
Status test_adaly_compare_strings_are_equal(char* buffer, int length);
Status test_adaly_push_back_size_correct(char* buffer, int length);
Status test_adaly_push_back_capacity_correct(char* buffer, int length);
Status test_adaly_pop_back_size_correct(char* buffer, int length);
Status test_adaly_pop_back_capacity_correct(char* buffer, int length);
Status test_adaly_if_string_empty_pop_returns_NULL(char* buffer, int length);
Status test_adaly_string_at_correct(char* buffer, int length);
Status test_adaly_string_at_neg_index_returns_NULL(char* buffer, int length);
Status test_adaly_string_at_above_bounds_index_returns_NULL(char* buffer, int length);
Status test_adaly_c_str_adds_NULL_terminator(char* buffer, int length);
Status test_adaly_c_str_does_not_change_size(char* buffer, int length);
Status test_adaly_c_str_does_not_change_capacity(char* buffer, int length);
Status test_adaly_concat_does_not_fail(char* buffer, int length);
Status test_adaly_concat_size_correct(char* buffer, int length);
Status test_adaly_concat_capacity_correct(char* buffer, int length);
Status test_adaly_string_empty_returns_true_if_NULL(char* buffer, int length);
Status test_adaly_string_is_actually_destroyed(char* buffer, int length);



#endif
