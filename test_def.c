#include "unit_test.h"
//1
Status test_init_default_returns_nonNULL(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  hString = my_string_init_default();
  if(hString == NULL)
    {
      my_string_destroy(&hString);
      strncpy(buffer, "test_init_default_returns_nonNULL\n" "my_string_init_default returns NULL", length);
      status = FAILURE;
    }
  else
    {
      my_string_destroy(&hString);
      strncpy(buffer, "test_init_default_returns_nonNULL\n", length);
      status = SUCCESS;
    }
  return status;
}

//2
Status test_get_size_on_init_default_returns_0(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  hString = my_string_init_default();
  if(my_string_get_size(hString) != 0)
    {
      status = FAILURE;
      printf("Expected a size of 0 but got %d\n", my_string_get_size(hString));
      strncpy(buffer, "test_get_size_on_init_default_returns_0\n" "Did not receive 0 from get_size after init_default\n", length);
    }
  else
    {
      status = SUCCESS;
      strncpy(buffer, "test_get_size_on_init_default_returns_0\n", length);
    }
  my_string_destroy(&hString);
  return status;
}

//3
Status test_adaly_init_default_capacity_is_7(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  hString = my_string_init_default();
  if (my_string_get_capacity(hString) != 7)
    {
      status = FAILURE;
      printf("Expected a size of 7 but got %d\n", my_string_get_capacity(hString));
	strncpy(buffer, "test_adaly_init_default_capacity_is_7\n" "Did not receive 7 from get_size after init_default\n", length); 
    }
  else
    {
      status = SUCCESS;
      strncpy(buffer, "test_adaly_init_default_capacity_is_7\n", length);
    }
  my_string_destroy(&hString);
  return status;
}

//4
Status test_adaly_init_c_string_returns_nonNULL(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  hString = my_string_init_c_string("hello");
  if (hString == NULL)
    {
      my_string_destroy(&hString);
      strncpy(buffer, "test_adaly_init_c_string_returns_nonNULL\n" "my_string_init_c_string returns NULL", length);
      status = FAILURE;
    }
  else
    {
      my_string_destroy(&hString);
      strncpy(buffer, "test_adaly_init_c_string_returns_nonNULL\n", length);
      status = SUCCESS;
    }
  return status;
}

//5
Status test_adaly_init_c_string_returns_correct_size(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  hString = my_string_init_c_string("hello");
  if (my_string_get_size(hString) != 5)
    {
      status = FAILURE;
      printf("Expected a size of 5 but got %d\n", my_string_get_size(hString));
      strncpy(buffer, "test_adaly_init_c_string_returns_correct_size\n" "Did not receive 5 from get_size after init_c_string 'hello'\n", length);
    }
  else
    {
      status = SUCCESS;
      strncpy(buffer, "test_adaly_init_c_string_returns_correct_size\n", length);
    }
  my_string_destroy(&hString);
  return status;
}

//6
Status test_adaly_init_c_string_returns_correct_capacity(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  hString = my_string_init_c_string("hello");
  if (my_string_get_capacity(hString) != 6)
    {
      status = FAILURE;
      printf("Expected a size of 6 but got %d\n", my_string_get_capacity(hString));
      strncpy(buffer, "test_adaly_init_c_string_returns_correct_capacity\n" "Did not receive 6 from get_capacity after init_c_string of 'hello'\n", length);
    }
  else
    {
      status = SUCCESS;
      strncpy(buffer, "test_adaly_init_c_string_returns_correct_capacity\n", length);
    }
  my_string_destroy(&hString);
  return status;
}

//7
Status test_adaly_compare_strings_left_is_smaller(char* buffer, int length)
{
  MY_STRING hLeft = NULL;
  MY_STRING hRight = NULL;
  Status status;
  hLeft = my_string_init_c_string("apple");
  hRight = my_string_init_c_string("orange");
  if (my_string_compare(hLeft, hRight) >= 0)
    {
      status = FAILURE;
      printf("Expected a negative number but got %d\n", my_string_compare(hLeft, hRight));
      strncpy(buffer, "test_adaly_compare_strings_left_is_smaller\n" "Did not receive a negetive number from compare_strings of 'apple' and 'orange'\n", length);
    }
  else
    {
      status = SUCCESS;
      strncpy(buffer, "test_adaly_compare_strings_left_is_smaller\n", length);
    }
  my_string_destroy(&hLeft);
  my_string_destroy(&hRight);
  return status;
}

//8
Status test_adaly_compare_strings_left_is_bigger(char* buffer, int length)
{
  MY_STRING hLeft = NULL;
  MY_STRING hRight = NULL;
  Status status;
  hLeft = my_string_init_c_string("orange");
  hRight = my_string_init_c_string("apple");
  if (my_string_compare(hLeft, hRight) <= 0)
    {
      status = FAILURE;
      printf("Expected a positive number but got %d\n", my_string_compare(hLeft, hRight));
      strncpy(buffer, "test_adaly_compare_strings_left_is_bigger\n" "Did not reveive a positive number from compare_strings of 'orange' and 'apple'\n", length);
    }
  else
    {
      status = SUCCESS;
      strncpy(buffer, "test_adaly_compare_strings_left_is_bigger\n", length);
    }
  my_string_destroy(&hLeft);
  my_string_destroy(&hRight);
  return status;    
}

//9
Status test_adaly_compare_strings_are_equal(char* buffer, int length)
{
  MY_STRING hLeft = NULL;
  MY_STRING hRight = NULL;
  Status status;
  hLeft = my_string_init_c_string("apple");
  hRight = my_string_init_c_string("apple");
  if (my_string_compare(hLeft, hRight) != 0)
    {
      status = FAILURE;
      printf("Expected 0 but got %d\n", my_string_compare(hLeft, hRight));
      strncpy(buffer, "test_adaly_compare_strings_are_equal\n" "Did not receive 0 from compare_strings of 'apple' and 'apple'\n", length);
    }
  else
    {
      status = SUCCESS;
      strncpy(buffer, "test_adaly_compare_strings_are_equal\n", length);
    }
  my_string_destroy(&hLeft);
  my_string_destroy(&hRight);
  return status;
}

//10
Status test_adaly_push_back_size_correct(char* buffer, int length)
{
  MY_STRING hMy_string = NULL;
  Status status;
  hMy_string = my_string_init_c_string("test");
  my_string_push_back(hMy_string, 'x');
  if (my_string_push_back(hMy_string, 'x') == SUCCESS && my_string_get_size(hMy_string) == 6)
    {
      status = SUCCESS;
      strncpy(buffer, "test_adaly_push_back_size_correct\n", length);
    }
  else
    {
      status = FAILURE;
      printf("Expected 6 but got %d\n", my_string_get_size(hMy_string));
      strncpy(buffer, "test_adaly_push_back_size_correct\n" "Did not receive size of 6 after push_back of 'test'\n", length);
    }
  my_string_destroy(&hMy_string);
  return status;
}

//11
Status test_adaly_push_back_capacity_correct(char* buffer, int length)
{
  MY_STRING hMy_string = NULL;
  Status status;
  hMy_string = my_string_init_c_string("test");
  my_string_push_back(hMy_string, 'x');
  if (my_string_push_back(hMy_string, 'x') == SUCCESS && my_string_get_capacity(hMy_string) == 10)
    {
      status = SUCCESS;
      strncpy(buffer, "test_adaly_push_back_capacity_correct\n", length);
    }
  else
    {
      status = FAILURE;
      printf("Expected 10 but got %d\n", my_string_get_capacity(hMy_string));
      strncpy(buffer, "test_adaly_push_back_size_correct\n" "Did not receive capacity of 10 after push_back of 'test'\n", length);
    }
  my_string_destroy(&hMy_string);
  return status;
}

//12
Status test_adaly_pop_back_size_correct(char* buffer, int length)
{
  MY_STRING hMy_string = NULL;
  Status status;
  hMy_string = my_string_init_c_string("test");
  if (my_string_pop_back(hMy_string) == SUCCESS && my_string_get_size(hMy_string) == 3)
    {
      status = SUCCESS;
      strncpy(buffer, "test_adaly_pop_back_size_correct\n", length);
    }
  else
    {
      status = FAILURE;
      printf("Expected 3 but got %d\n", my_string_get_size(hMy_string));
      strncpy(buffer, "test_adaly_pop_back_size_correct\n" "Did not receive size of 3 after pop_back of 'test'\n", length);
    }
  my_string_destroy(&hMy_string);
  return status;
}

//13
Status test_adaly_pop_back_capacity_correct(char* buffer, int length)
{
  MY_STRING hMy_string = NULL;
  Status status;
  hMy_string = my_string_init_c_string("test");
  if (my_string_pop_back(hMy_string) == SUCCESS && my_string_get_capacity(hMy_string) == 5)
    {
      status = SUCCESS;
      strncpy(buffer, "test_adaly_pop_back_capacity_correct\n", length);
    }
  else
    {
      status = FAILURE;
      printf("Expected 5 but got %d\n", my_string_get_size(hMy_string));
      strncpy(buffer, "test_adaly_pop_back_capacity_correct\n" "Did not receive unchanged capacity of 5 after pop_back of 'test'\n", length);
    }
  my_string_destroy(&hMy_string);
  return status;
}

//14
Status test_adaly_if_string_empty_pop_returns_NULL(char* buffer, int length)
{
  MY_STRING hMy_string = NULL;
  Status status;
  hMy_string = my_string_init_default();
  if (my_string_pop_back(hMy_string) != NULL)
    {
      status = FAILURE;
      printf("Expected NULL but did not get it\n");
      strncpy(buffer, "test_adaly_if_string_empty_pop_returns_NULL" "Did not recieve NULL from pop_back of empty string\n", length);
    }
  else
    {
      status = SUCCESS;
      strncpy(buffer, "test_adaly_if_string_empty_pop_returns_NULL\n", length);
    }
  my_string_destroy(&hMy_string);
  return status;
}

//15
Status test_adaly_string_at_correct(char* buffer, int length)
{
  MY_STRING hMy_string = NULL;
  Status status;
  hMy_string = my_string_init_c_string("test");
  if(*(my_string_at(hMy_string, 0)) != 't')
    {
      status = FAILURE;
      printf("Expected 't' but got %c\n", *(my_string_at(hMy_string, 0)));
      strncpy(buffer, "test_adaly_string_at_correct\n" "Did not receive 't' for string_at index of 0 of 'test'\n", length);
    }
  else
    {
      status = SUCCESS;
      strncpy(buffer, "test_adaly_string_at_correct\n", length);
    }
  my_string_destroy(&hMy_string);
  return status;
}

//16
Status test_adaly_string_at_neg_index_returns_NULL(char* buffer, int length)
{
  MY_STRING hMy_string = NULL;
  Status status;
  hMy_string = my_string_init_c_string("test");
  if(my_string_at(hMy_string, -5) != NULL)
    {
      status = FAILURE;
      printf("Expected NULL but got %c\n", *(my_string_at(hMy_string, -5)));
      strncpy(buffer, "test_adaly_string_at_neg_index_returns_NULL\n" "Did not receive NULL for string_at index of -5 of 'test'\n", length);
    }
  else
    {
      status = SUCCESS;
      strncpy(buffer, "test_adaly_string_at_neg_index_returns_NULL\n", length);
    }
  my_string_destroy(&hMy_string);
  return status;
}

//17
Status test_adaly_string_at_above_bounds_index_returns_NULL(char* buffer, int length)
{
  MY_STRING hMy_string = NULL;
  Status status;
  hMy_string = my_string_init_c_string("test");
  if (my_string_at(hMy_string, 8) != NULL)
    {
      status = FAILURE;
      printf("Expected NULL but got %c\n", *(my_string_at(hMy_string, 8)));
      strncpy(buffer, "test_adaly_string_at_above_bounds_index_returns_NULL\n" "Did not receive NULL for string at index of 8 of 'test'\n", length);
    }
  else
    {
      status = SUCCESS;
      strncpy(buffer, "test_adaly_string_at_above_bounds_index_returns_NULL\n", length);
    }
  my_string_destroy(&hMy_string);
  return status;
}

//18
Status test_adaly_c_str_adds_NULL_terminator(char* buffer, int length)
{
  MY_STRING hMy_string = NULL;
  Status status;
  hMy_string = my_string_init_c_string("test");
  my_string_c_str(hMy_string);
  if (my_string_at(hMy_string, 4) != NULL)
    {
      status = FAILURE;
      printf("Expected NULL but got %c\n", *(my_string_at(hMy_string, 4)));
      strncpy(buffer, "test_adaly_c_str_adds_NULL_terminator\n" "Did not receive NULL for string at index of 4 for 'test'\n", length);
    }
  else
    {
      status = SUCCESS;
      strncpy(buffer, "test_adaly_c_str_adds_NULL_terminator\n", length);
    }
  my_string_destroy(&hMy_string);
  return status;
}

//19
Status test_adaly_c_str_does_not_change_size(char* buffer, int length)
{
  MY_STRING hMy_string = NULL;
  Status status;
  hMy_string = my_string_init_c_string("test");
  my_string_c_str(hMy_string);
  if (my_string_get_size(hMy_string) != 4)
    {
      status = FAILURE;
      printf("Expected 4 but got %d\n", my_string_get_size(hMy_string));
      strncpy(buffer, "test_adaly_c_str_does_not_change_size\n" "Did not receive 4 for size of 'test' after c_str\n", length);
    }
  else
    {
      status = SUCCESS;
      strncpy(buffer, "test_adaly_c_str_does_not_change_size\n", length);
    }
  my_string_destroy(&hMy_string);
  return status;
}

//20
Status test_adaly_c_str_does_not_change_capacity(char* buffer, int length)
{
  MY_STRING hMy_string = NULL;
  Status status;
  hMy_string = my_string_init_c_string("test");
  my_string_c_str(hMy_string);
  if (my_string_get_capacity(hMy_string) != 5)
    {
      status = FAILURE;
      printf("Expected 5 but got %d\n", my_string_get_capacity(hMy_string));
      strncpy(buffer, "test_adaly_c_str_does_not_change_capacity\n" "Did not recieve 5 for capacity of 'test' after c_str\n", length);
    }
  else
    {
      status = SUCCESS;
      strncpy(buffer, "test_adaly_c_str_does_not_change_capacity\n", length);
    }
  my_string_destroy(&hMy_string);
  return status;
}

//21
Status test_adaly_concat_does_not_fail(char* buffer, int length)
{
  MY_STRING hResult = NULL;
  MY_STRING hAppend = NULL;
  Status status;
  Status stat;
  hResult = my_string_init_c_string("book");
  hAppend = my_string_init_c_string("case");
  stat = my_string_concat(hResult, hAppend);
  if (stat != SUCCESS)
    {
      status = FAILURE;
      printf("Expected SUCCESS but got FAILURE\n");
      strncpy(buffer, "test_adaly_concat_does_not_fail\n" "Did not receive SUCCESS from concat function\n", length);
    }
  else
    {
      status = SUCCESS;
      strncpy(buffer, "test_adaly_concat_does_not_fail\n", length);
    }
  my_string_destroy(&hResult);
  return status;
}

//22
Status test_adaly_concat_size_correct(char* buffer, int length)
{
  MY_STRING hResult = NULL;
  MY_STRING hAppend = NULL;
  Status status;
  hResult = my_string_init_c_string("book");
  hAppend = my_string_init_c_string("case");
  my_string_concat(hResult, hAppend);
  if (my_string_get_size(hResult) != 8)
    {
      status = FAILURE;
      printf("Expected 8 but got %d\n", my_string_get_size(hResult));
      strncpy(buffer, "test_adaly_concat_size_correct\n" "Did not receive size of 8 after concat of 'book' and 'case'\n", length);
    }
  else
    {
      status = SUCCESS;
      strncpy(buffer, "test_adaly_concat_size_correct\n", length);
    }
  my_string_destroy(&hResult);
  return status;
}

//23
Status test_adaly_concat_capacity_correct(char* buffer, int length)
{
  MY_STRING hResult = NULL;
  MY_STRING hAppend = NULL;
  Status status;
  hResult = my_string_init_c_string("book");
  hAppend = my_string_init_c_string("case");
  my_string_concat(hResult, hAppend);
  if (my_string_get_capacity(hResult) != 10)
    {
      status = FAILURE;
      printf("Expected 10 but got %d\n", my_string_get_capacity(hResult));
      strncpy(buffer, "test_adaly_concat_capacity_correct\n" "Did not receive capacity of 10 after concat of 'book' and 'case'\n", length);
    }
  else
    {
      status = SUCCESS;
      strncpy(buffer, "test_adaly_concat_size_correct\n", length);
    }
  my_string_destroy(&hResult);
  return status;
  }

//24
Status test_adaly_string_empty_returns_true_if_NULL(char* buffer, int length)
{
  MY_STRING hMy_string = NULL;
  Status status;
  if (my_string_empty(hMy_string) != TRUE)
    {
      status = FAILURE;
      printf("Expected TRUE but got FALSE\n");
      strncpy(buffer, "test_adaly_string_empty_returns_true_if_NULL\n" "Did not receive TRUE from string_empty of NULL string\n", length);
      my_string_destroy(&hMy_string);
    }
  else
    {
      status = SUCCESS;
      strncpy(buffer, "test_adaly_string_empty_returns_true_if_NULL\n", length);
    }
  return status;
}

//25
Status test_adaly_string_is_actually_destroyed(char* buffer, int length)
{
  MY_STRING hMy_string = NULL;
  Status status;
  hMy_string = my_string_init_c_string("test");
  my_string_destroy(&hMy_string);
  if (hMy_string != NULL)
    {
      status = FAILURE;
      printf("Expected hMy_string to equal NULL but it does not\n");
      strncpy(buffer, "test_adaly_string_is_actually_destroyed\n" "Did not receive NULL after string_destroy\n", length);
      my_string_destroy(&hMy_string);
    }
  else
    {
      status = SUCCESS;
      strncpy(buffer, "test_adaly_string_is_actually_destroyed\n", length);
    }
  return status;
}
