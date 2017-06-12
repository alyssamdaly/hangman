#include <stdlib.h>
#include "my_string.h"

int main(int argc, char* argv[])
{
  int i;
  MY_STRING hMy_string[100];//Create array of MY_STRING handles w/ 100 elements
  for (i = 0; i < 100; i++)//Initialize each element to NULL
    {
      hMy_string[i] = NULL;
    }
  hMy_string[0] = my_string_init_c_string("COPY ME!");//Use init_c_string to initialize the first element of the arra to "COPY ME!"
  for (i = 1; i < 100; i++)//Write a for loop that uses assignment function to copy the first string into all other elements
    {
      my_string_assignment(&hMy_string[i], hMy_string[0]);
    }
  for (i = 0; i < 100; i++)//Destroy every element with a for loop calling destroy
    {
      printf("%d ", i + 1);
      my_string_insertion(hMy_string[i], stdout);
      printf("\n");
      my_string_destroy(&hMy_string[i]);
    }
  //Print each string to screen using string insertion before deleting
  return 0;
}
