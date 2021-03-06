#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "my_string.h"

struct my_string
{
  int size;
  int capacity;
  char* data;
};
typedef struct my_string My_string;

MY_STRING my_string_init_default(void)
{
  My_string* pMy_string;
  pMy_string = (My_string*)malloc(sizeof(My_string));
  if (pMy_string != NULL)
    {
      pMy_string->size = 0;
      pMy_string->capacity = 7;
      pMy_string->data = (char*)malloc(sizeof(char) * pMy_string->capacity);
      if (pMy_string == NULL)
	{
	  free(pMy_string);
	  pMy_string = NULL;
	}
    }
  return pMy_string;
}

MY_STRING my_string_init_c_string(const char* c_string)
{
  My_string* pMy_string;
  int i;
  pMy_string = (My_string*)malloc(sizeof(My_string));
  if (pMy_string != NULL)
    {
      pMy_string->size = strlen(c_string);
      pMy_string->capacity = strlen(c_string) + 1;
      pMy_string->data = (char*)malloc(sizeof(char) * pMy_string->capacity);
      for (i = 0; i < pMy_string->capacity; i++)
	{
	  pMy_string->data[i] = c_string[i];
	}
      if (pMy_string->data == NULL)
	{
	  free(pMy_string->data);
	  pMy_string = NULL;
	}
    }
  return pMy_string;
}

int my_string_get_capacity(MY_STRING hMy_string)
{
  My_string* pMy_string = (My_string*)hMy_string;
  return pMy_string->capacity;
}

int my_string_get_size(MY_STRING hMy_string)
{
  My_string* pMy_string = (My_string*)hMy_string;
  return pMy_string->size;
}

int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string)
{
  My_string* pLeft_string = (My_string*)hLeft_string;
  My_string* pRight_string = (My_string*)hRight_string;
  int i;
  for (i = 0; i <= pLeft_string->capacity && i <= pRight_string->capacity; i++)
    {
      if ((pLeft_string->data[i]) < (pRight_string->data[i]))
	{
	  return -1;
	}
      else if ((pLeft_string->data[i]) > (pRight_string->data[i]))
	{
	  return 1;
	}
      else if ((pLeft_string->data[i]) == '\0' && (pRight_string->data[i]) == '\0')
	{
	  return 0;
	}
    }
  printf("Function my_string_compare did not work properly.\n");
  return -42424242;
}

Status my_string_extraction(MY_STRING hMy_string, FILE* fp)
{
  My_string* pMy_string = (My_string*)hMy_string;
  char* temp;
  char ch;
  int i, index = 0, check;
  check = fscanf(fp, "%c", &ch);
  if (check == 1 && check != EOF)
    {
      while (ch != ' ' && ch != '\n' && ch != EOF) //ignores whitespace, newline characters, and stops at eof
	{
	  pMy_string->data[index] = ch;
	  pMy_string->size = index + 1;
	  index++;
	  if (pMy_string->capacity <= pMy_string->size) //push back to increase capacity
	    {
	      temp = (char*)malloc(sizeof(char) * 2 * pMy_string->capacity);
	      if (temp == NULL)
		{
		  return FAILURE;
		}
	      for (i = 0; i < pMy_string->size; i++)
		{
		  temp[i] = pMy_string->data[i];
		}
	      free(pMy_string->data);
	      pMy_string->data = temp;
	      pMy_string->capacity *= 2;
	    }
	  ch = fgetc(fp);
	}
      ungetc(ch, fp);
      return SUCCESS;
    }
  return FAILURE;
}

Status my_string_insertion(MY_STRING hMy_string, FILE* fp)
{
  My_string* pMy_string = (My_string*)hMy_string;
  int i;
  for (i = 0; i < pMy_string->size; i++)
    {
      fprintf(fp, "%c", pMy_string->data[i]);
    }
  return SUCCESS;
}

Status my_string_push_back(MY_STRING hMy_string, char item)
{
  My_string* pMy_string = (My_string*)hMy_string;
  char* temp;
  int i;
  if (pMy_string->size >= pMy_string->capacity)
    {
      temp = (char*)malloc(sizeof(char) * 2 * pMy_string->capacity);
      if (temp == NULL)
	{
	  return FAILURE;
	}
      for (i = 0; i < pMy_string->size; i++)
	{
	  temp[i] = pMy_string->data[i];
	}
      free(pMy_string->data);
      pMy_string->data = temp;
      pMy_string->capacity *= 2;
    }
  //if there is space
  pMy_string->data[pMy_string->size] = item;
  pMy_string->size++;
  return SUCCESS;
}

Status my_string_pop_back(MY_STRING hMy_string)
{
  My_string* pMy_string = (My_string*)hMy_string;
  if (pMy_string->size <= 0)
    {
      return FAILURE;
    }
  pMy_string->size--;
  return SUCCESS;
}

char* my_string_at(MY_STRING hMy_string, int index)
{
  My_string* pMy_string = (My_string*)hMy_string;
  if (index < 0 || index >= pMy_string->size)
    {
      return NULL;
    }
  return &pMy_string->data[index];
}

char* my_string_c_str(MY_STRING hMy_string)
{
  My_string* pMy_string = (My_string*)hMy_string;
  char* temp;
  int i;
  if ((pMy_string->size) >= pMy_string->capacity)//need space for the null terminator
    {
      temp = (char*)malloc(sizeof(char) * 2 * pMy_string->capacity);
      if (temp == NULL)
	{
	  free(temp);
	  return NULL;
	}
      for (i = 0; i < pMy_string->size; i++)
	{
	  temp[i] = pMy_string->data[i];
	}
      free(pMy_string->data);
      pMy_string->data = temp;
      pMy_string->capacity += 1;
    }
  pMy_string->data[pMy_string->size] = '\0';
  return &pMy_string->data[0];
}

Status my_string_concat(MY_STRING hResult, MY_STRING hAppend)
{
  My_string* pResult = (My_string*)hResult;
  My_string* pAppend = (My_string*)hAppend;
  int i;
  for (i = 0; i < pAppend->size; i++)
    {
      my_string_push_back(pResult, pAppend->data[i]);
    }
  free(pAppend->data); 
  free(pAppend);
  return SUCCESS;
}


Boolean my_string_empty(MY_STRING hMy_string)
{
  My_string* pMy_string = (My_string*)hMy_string;
  if (pMy_string == NULL || pMy_string->size == 0)
    {
      return TRUE;
    }
  return FALSE;
}

void my_string_assignment(Item* pLeft, Item Right)
{
  My_string* p_Left = *pLeft;
  My_string* p_Right = Right;
  int i;
  if (p_Left == NULL) //if it's null
    {
      p_Left =(My_string*)malloc(sizeof(My_string));//allocate space for it
      if (p_Left == NULL)//check malloc
	{
	  printf("string_assignment malloc failed.\n");
	}
    }
  p_Left->capacity = p_Right->capacity;
  p_Left->size = p_Right->size;//set capacity and size
  free(p_Left->data);//free old data to make room for new
  p_Left->data = malloc(sizeof(char) * p_Left->capacity);//allocate space for the data
  for (i = 0; i < p_Right->size; i++)
    {
      p_Left->data[i] = p_Right->data[i];//assign the data
    }
  *pLeft = p_Left;//adjust pointer
}

void my_string_destroy(Item* pItem)
{
  My_string* pMy_string = (My_string*)*pItem;
  free(pMy_string->data);
  free(pMy_string);
  *pItem = NULL;
}


/*Format for init, destroy, capacity, size, push back, pop back, my string at, and empty functions taken from Dr. Rykalova's code on vectors for UML Computing II.*/
