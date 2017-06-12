#include <stdio.h>
#include "unit_test.h"
int main(int argc, char* argv[])
{
  Status (*tests[])(char*, int) =
    {
      test_init_default_returns_nonNULL,
      test_get_size_on_init_default_returns_0,
      test_adaly_init_default_capacity_is_7,
      test_adaly_init_c_string_returns_nonNULL,
      test_adaly_init_c_string_returns_correct_size,
      test_adaly_init_c_string_returns_correct_capacity,
      test_adaly_compare_strings_left_is_smaller,
      test_adaly_compare_strings_left_is_bigger,
      test_adaly_compare_strings_are_equal,
      test_adaly_push_back_size_correct,
      test_adaly_push_back_capacity_correct,
      test_adaly_pop_back_size_correct,
      test_adaly_pop_back_capacity_correct,
      test_adaly_if_string_empty_pop_returns_NULL,
      test_adaly_string_at_correct,
      test_adaly_string_at_neg_index_returns_NULL,
      test_adaly_string_at_above_bounds_index_returns_NULL,
      test_adaly_c_str_adds_NULL_terminator,
      test_adaly_c_str_does_not_change_size,
      test_adaly_c_str_does_not_change_capacity,
      test_adaly_concat_does_not_fail,
      test_adaly_concat_size_correct,
      test_adaly_concat_capacity_correct,
      test_adaly_string_empty_returns_true_if_NULL,
      test_adaly_string_is_actually_destroyed
    };
  int number_of_functions = sizeof(tests) / sizeof(tests[0]);
  int i;
  char buffer[500];
  int success_count = 0;
  int failure_count = 0;
  for(i=0; i<number_of_functions; i++)
    {
      if(tests[i](buffer, 500) == FAILURE)
	{
	  printf("FAILED: Test %d failed miserably\n", i+1);
	  printf("\t%s\n", buffer);
	  failure_count++;
	}
      else
	{
	  //printf("PASS: Test %d passed\n", i);
	  //printf("\t%s\n", buffer);
	  success_count++;
	}
    }
  printf("Total number of tests: %d\n", number_of_functions);
  printf("%d/%d Pass, %d/%d Failure\n", success_count, number_of_functions, failure_count, number_of_functions);
  return 0;
}

