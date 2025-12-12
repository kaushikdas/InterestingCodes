// #define MAHARNAB_SLN

#ifdef MAHARNAB_SLN
#include <stdio.h>
int group_numbers(int result_so_far, int idx, int string_idx, char string[]);
int replace_minus(int result_so_far, int idx, int string_idx, char string[]);
char get_digit(int digit);

int num[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
int main()
{
  int c;
  do
  {
    printf("Choose Option:\n");
    printf("1) GROUP 2) REPLACEMINUS 3) Quit\n");
    printf("Enter Option: ");
    scanf("%d", &c);
    char string[1000] = {'0'};
    switch (c)
    {
    case 1:
      group_numbers(0, 0, 0, string);
      if (group_numbers(0, 0, 0, string) != 1)
      {
        printf("No variation exists that sums to 100\n");
      }
      break;

    case 2:
      replace_minus(0, 0, 0, string);
      if (replace_minus(0, 0, 0, string) != 1)
      {
        printf("No variation exists that sums to 100\n");
      }
      break;

    case 3:
      printf("Quitting ...\n");
      break;

    default:
      printf("Wrong input, try again\n");
      printf("1) GROUP 2) REPLACEMINUS 3) Quit\n");
      printf("Enter Option: ");
      scanf("%d", &c);
    }
  } while (c != 3);
  return 0;
}

char get_digit(int digit)
{
  if ((digit >= 1) && (digit <= 9))
  {
    return '1' + digit - 1;
  }
}

int group_numbers(int result_so_far, int idx, int string_idx, char string[])
{
  int result_so_far_received = result_so_far;
  int string_idx_received1 = string_idx, string_idx_received2 = string_idx, string_idx_received3 = string_idx;
  int found1, found2, found3, found4;
  if (idx <= 9)
  {
    if (idx == 9)
    {
      string[string_idx] = '\0';
      if (result_so_far == 100)
      {
        printf("%s = 100\n", string);
        return 1;
      }
      else
        return 0;
    }

    if (idx == 0)
    {
      result_so_far = result_so_far_received + num[idx];
      string[string_idx++] = get_digit(num[idx]);
      found3 = group_numbers(result_so_far, idx + 1, string_idx, string);

      result_so_far = result_so_far_received + 10 * num[idx] + num[idx + 1];
      string[string_idx_received3++] = get_digit(num[idx]);
      string[string_idx_received3++] = get_digit(num[idx + 1]);
      found4 = group_numbers(result_so_far, idx + 2, string_idx_received3, string);
    }

    if (idx != 0)
    {
      {
        result_so_far = result_so_far_received + num[idx];
        string[string_idx_received1++] = ' ';
        string[string_idx_received1++] = '+';
        string[string_idx_received1++] = ' ';
        string[string_idx_received1++] = get_digit(num[idx]);
        found1 = group_numbers(result_so_far, idx + 1, string_idx_received1, string);
      }
      {
        if (idx < 8)
        {
          result_so_far = result_so_far_received + 10 * num[idx] + num[idx + 1];
          string[string_idx_received2++] = ' ';
          string[string_idx_received2++] = '+';
          string[string_idx_received2++] = ' ';
          string[string_idx_received2++] = get_digit(num[idx]);
          string[string_idx_received2++] = get_digit(num[idx + 1]);
          found2 = group_numbers(result_so_far, idx + 2, string_idx_received2, string);
        }
      }
    }
    if ((found1 == 1) || (found2 == 1))
    {
      /* printf("%s\n", string); */
      return 1;
    }
  }
}

int replace_minus(int result_so_far, int idx, int string_idx, char string[])
{
  int result_so_far_received = result_so_far;
  int string_idx_received = string_idx, string_idx_received1 = string_idx, string_idx_received2 = string_idx, string_idx_received3 = string_idx, string_idx_received4 = string_idx;
  int found1, found2, found3, found4, found5, found6;
  if (idx <= 9)
  {
    if (idx == 9)
    {
      string[string_idx] = '\0';
      if (result_so_far == 100)
      {
        printf("%s = 100\n", string);
        return 1;
      }
      else
        return 0;
    }

    {
      if (idx == 0)
      {
        result_so_far = result_so_far_received + num[idx];
        string[string_idx_received3++] = get_digit(num[idx]);
        found5 = replace_minus(result_so_far, idx + 1, string_idx_received3, string);

        result_so_far = result_so_far_received + 10 * num[idx] + num[idx + 1];
        string[string_idx_received4++] = get_digit(num[idx]);
        string[string_idx_received4++] = get_digit(num[idx + 1]);
        found6 = replace_minus(result_so_far, idx + 2, string_idx_received4, string);
      }

      if (idx != 0)
      {
        {
          {
            result_so_far = result_so_far_received + num[idx];
            string[string_idx++] = ' ';
            string[string_idx++] = '+';
            string[string_idx++] = ' ';
            string[string_idx++] = get_digit(num[idx]);
            found1 = replace_minus(result_so_far, idx + 1, string_idx, string);
          }

          {
            result_so_far = result_so_far_received - num[idx];
            string[string_idx_received++] = ' ';
            string[string_idx_received++] = '-';
            string[string_idx_received++] = ' ';
            string[string_idx_received++] = get_digit(num[idx]);
            found3 = replace_minus(result_so_far, idx + 1, string_idx_received, string);
          }
        }
        {
          if (idx < 8)
          {
            {
              result_so_far = result_so_far_received + 10 * num[idx] + num[idx + 1];
              string[string_idx_received1++] = ' ';
              string[string_idx_received1++] = '+';
              string[string_idx_received1++] = ' ';
              string[string_idx_received1++] = get_digit(num[idx]);
              string[string_idx_received1++] = get_digit(num[idx + 1]);
              found2 = replace_minus(result_so_far, idx + 2, string_idx_received1, string);
            }

            {
              result_so_far = result_so_far_received - 10 * num[idx] - num[idx + 1];
              string[string_idx_received2++] = ' ';
              string[string_idx_received2++] = '-';
              string[string_idx_received2++] = ' ';
              string[string_idx_received2++] = get_digit(num[idx]);
              string[string_idx_received2++] = get_digit(num[idx + 1]);
              found4 = replace_minus(result_so_far, idx + 2, string_idx_received2, string);
            }
          }
        }
      }
      if ((found1 == 1) || (found2 == 1) || (found3 == 1) || (found4 == 1))
      {
        /* printf("%s\n", string); */
        return 1;
      }
    }
  }
}

#else
#include <stdio.h>

#define MAX_LEN 100

/* Define global array that is accessible to all functions */
int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

/* Declare function prototypes */

void display_menu();

char get_digit_char(int digit); /* 1 -> '1', 2 -> '2' etc. */

void find_group_variations();
void find_replace_minus_variations();

int group_digits(int result_so_far, int idx, char result_str[], int write_idx);
int replace_minus(int result_so_far, int idx, char result_str[], int write_idx);

// Main Function: Displays menu and calls corresponding options
int main()
{
  int option;
  do
  {
    display_menu();
    scanf("%d", &option);

    switch (option)
    {
    case 1:
      find_group_variations();
      break;
    case 2:
      find_replace_minus_variations();
      break;
    case 3:
      printf("Quitting\n");
      break;
    default:
      printf("Invalid option! Please choose again.\n");
      break;
    }
  } while (option != 3);

  return 0;
}

// Function to display the menu
void display_menu()
{
  printf("\nChoose Option:\n");
  printf("1) GROUP ");
  printf("2) REPLACEMINUS ");
  printf("3) Quit\n");
  printf("Enter Option: ");
}

char get_digit_char(int digit) /* 1 -> '1', 2 -> '2' etc. */
{
  if ((digit >= 1) && (digit <= 9))
  {
    return '1' + (digit - 1); /* digit - 1 will be 0, 1 etc. when
                                 digit = 1, 2 etc. So it will return
                                 '1', '2' etc. */
  }
}

/* Function to recursively group digits and find expressions summing to 100
   result_str: result string created so far
   write_idx: the index at which we can write next expression in the result_str
   result_so_far: expression result so far
   idx: which number to process now

   On recursive exit it will return 1 if the result sums to 100, else 0.
 */
int group_digits(int result_so_far, int idx, char result_str[], int write_idx)
{
  int found1 = 0, found2 = 0;
  int result_so_far_received = result_so_far;
  int write_idx_received = write_idx;

  if (idx == 9) /* recursion exit condition */
  {
    result_str[write_idx] = '\0'; /* Null terminate result string.
                                          We overwrite the + or - char
                                          in the result_str with NULL
                                          '\0' char */
    if (result_so_far == 100)
    {
      printf("%s = 100\n", result_str);
      return 1; /* found a valid variation */
    }
    else
    {
      /*printf("%s = %d\n", result_str, result_so_far);*/
      return 0; /* Not a valid variation */
    }
  }

  /* Now make recursive calls */

  /* Option 1: Keep current number as a single digit */

  if (write_idx != 0) /* No need to write leading + for the 1st digit */
  {
    result_str[write_idx++] = ' ';
    /* The ++ in the above line makes it equivalent to:
         result_str[write_idx] = ' ';
         write_idx += 1
         */
    result_str[write_idx++] = '+';
    result_str[write_idx++] = ' ';
  }
  result_str[write_idx++] = get_digit_char(numbers[idx]);
  result_so_far = result_so_far + numbers[idx];

  /* 1st recursive call for option 1 */
  found1 = group_digits(result_so_far, idx + 1, result_str, write_idx);

  /* Option 2: Group current (idx) and next digit (idx+1) if possible */

  if (idx < 8)
  {
    /* reset write_idx to received value because that is modified during
       above recursive call */
    write_idx = write_idx_received;
    if (write_idx != 0)
    {
      result_str[write_idx++] = ' ';
      result_str[write_idx++] = '+';
      result_str[write_idx++] = ' ';
    }
    result_str[write_idx++] = get_digit_char(numbers[idx]);
    result_str[write_idx++] = get_digit_char(numbers[idx + 1]);

    /* reset result_so_far to received value because that is modified
       during above recursive call */
    result_so_far = result_so_far_received;
    result_so_far = result_so_far + numbers[idx] * 10 + numbers[idx + 1];
    /* 2nd recursive call for option 2 */
    found2 = group_digits(result_so_far, idx + 2, result_str, write_idx);
  }

  if ((found1 == 1) || (found2 == 1))
    return 1;
  else
    return 0;
}

/* Function to recursively replace '+' with '-' and find expressions summing to 100

   result_str: result string created so far
   write_idx: the index at which we can write next expression in the result_str
   result_so_far: expression result so far
   idx: which number to process now

   On recursive exit it will return 1 if the result sums to 100, else 0.
*/
int replace_minus(int result_so_far, int idx, char result_str[], int write_idx)
{
  int found1 = 0, found2 = 0, found3 = 0;
  int result_so_far_received = result_so_far;
  int write_idx_received = write_idx;

  if (idx == 9) /* recursion exit condition */
  {
    result_str[write_idx] = '\0'; /* Null terminate result string.
                                          We overwrite the + or - char
                                          in the result_str with NULL
                                          '\0' char */
    if (result_so_far == 100)
    {
      printf("%s = 100\n", result_str);
      return 1; /* found a valid variation */
    }
    else
    {
      /*printf("%s = %d\n", result_str, result_so_far);
      getchar();*/
      return 0; /* Not a valid variation */
    }
  }

  /* Now make recursive calls */

  /* Option 1: Keep current number as a single digit with '+' */
  if (write_idx != 0) /* No need to write leading + for the 1st digit */
  {
    result_str[write_idx++] = ' ';
    /* The ++ in the above line makes it equivalent to:
         result_str[write_idx] = ' ';
         write_idx += 1
         */
    result_str[write_idx++] = '+';
    result_str[write_idx++] = ' ';
  }
  result_str[write_idx++] = get_digit_char(numbers[idx]);

  result_so_far = result_so_far + numbers[idx];
  /* 1st recursive call for option 1 */
  found1 = replace_minus(result_so_far, idx + 1, result_str, write_idx);

  /* Option 2: Replace '+' with '-' for the current digit */
  /* reset write_idx to received value because that is modified during
     above recursive call */
  write_idx = write_idx_received;
  if (write_idx != 0) /* No leading space for the 1st -ve digit*/
    result_str[write_idx++] = ' ';
  result_str[write_idx++] = '-';
  result_str[write_idx++] = ' ';
  result_str[write_idx++] = get_digit_char(numbers[idx]);

  /* reset result_so_far to received value because that is modified
     during above recursive call */
  result_so_far = result_so_far_received;
  result_so_far = result_so_far - numbers[idx];
  /* 2nd recursive call for option 2 */
  found2 = replace_minus(result_so_far, idx + 1, result_str, write_idx);

  /* Option 3: Group current and next digit if possible */

  if (idx < 8)
  {
    /* reset write_idx to received value because that is modified during
       above recursive call */
    write_idx = write_idx_received;
    if (write_idx != 0) /* No need to write leading + for the 1st digit */
    {
      result_str[write_idx++] = ' ';
      result_str[write_idx++] = '+';
      result_str[write_idx++] = ' ';
    }
    result_str[write_idx++] = get_digit_char(numbers[idx]);
    result_str[write_idx++] = get_digit_char(numbers[idx + 1]);

    /* reset result_so_far to received value because that is modified
       during above recursive call */
    result_so_far = result_so_far_received;

    result_so_far = result_so_far + numbers[idx] * 10 + numbers[idx + 1];
    /* 3rd recursive call for option 3 */
    found3 = replace_minus(result_so_far, idx + 2, result_str, write_idx);
  }

  if ((found1 == 1) || (found2 == 1) || (found3 == 1))
    return 1;
  else
    return 0;
}

/* Function to handle the GROUP option */
void find_group_variations()
{
  int found = 0;
  char result_str[1000] = {0}; /* 100 char string with all NULLs */

  printf("Trying GROUP variations...\n");
  found = group_digits(0, 0, result_str, 0);

  if (found == 0)
  {
    printf("No variation exists that sums to 100.\n");
  }
}

/* Function to handle the REPLACEMINUS option */
void find_replace_minus_variations()
{
  int found = 0;
  char result_str[1000] = {0}; /* 100 char string with all NULLs */

  printf("Valid variations are...\n");
  found = replace_minus(0, 0, result_str, 0);

  if (found == 0)
  {
    printf("No variation exists that sums to 100.\n");
  }
}

/*
SAMPLE OUTPUT

$ ./a.exe

Choose Option:
1) GROUP 2) REPLACEMINUS 3) Quit
Enter Option: 1
Trying GROUP variations...
No variation exists that sums to 100.

Choose Option:
1) GROUP 2) REPLACEMINUS 3) Quit
Enter Option: 2
Valid variations are...
1 + 2 + 3 - 4 + 5 + 6 + 78 + 9 = 100
1 + 2 + 34 - 5 + 67 - 8 + 9 = 100
1 + 23 - 4 + 5 + 6 + 78 - 9 = 100
1 + 23 - 4 + 56 + 7 + 8 + 9 = 100
- 1 + 2 - 3 + 4 + 5 + 6 + 78 + 9 = 100
12 + 3 + 4 + 5 - 6 - 7 + 89 = 100
12 + 3 - 4 + 5 + 67 + 8 + 9 = 100
12 - 3 - 4 + 5 - 6 + 7 + 89 = 100

Choose Option:
1) GROUP 2) REPLACEMINUS 3) Quit
Enter Option: 3
Quitting

*/
#endif /* MAHARNAB_SLN */