#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 100

// Function Prototypes
void displayMenu();
void groupDigits(char *expression, int idx, char *curr_expr, int curr_idx, int *found);
void replaceMinus(char *expression, int idx, char *curr_expr, int curr_idx, int *found);
int evaluateExpression(const char *expr);
void findGroupVariations();
void findReplaceMinusVariations();

// Main Function: Displays menu and calls corresponding options
int main()
{
  int option;
  do
  {
    displayMenu();
    scanf("%d", &option);

    switch (option)
    {
    case 1:
      findGroupVariations();
      break;
    case 2:
      findReplaceMinusVariations();
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
void displayMenu()
{
  printf("\nChoose Option:\n");
  printf("1) GROUP\n");
  printf("2) REPLACEMINUS\n");
  printf("3) Quit\n");
  printf("Enter Option: ");
}

// Function to recursively group digits and find expressions summing to 100
void groupDigits(char *expression, int idx, char *curr_expr, int curr_idx, int *found)
{
  if (idx == 9)
  {
    curr_expr[curr_idx] = '\0';
    if (evaluateExpression(curr_expr) == 100)
    {
      printf("%s = 100\n", curr_expr);
      *found = 1;
    }
    return;
  }

  // Option 1: Keep current number as a single digit
  curr_expr[curr_idx] = expression[idx];
  curr_expr[curr_idx + 1] = '+';
  groupDigits(expression, idx + 1, curr_expr, curr_idx + 2, found);

  // Option 2: Group current and next digit if possible
  if (idx < 8)
  {
    curr_expr[curr_idx] = expression[idx];
    curr_expr[curr_idx + 1] = expression[idx + 1];
    curr_expr[curr_idx + 2] = '+';
    groupDigits(expression, idx + 2, curr_expr, curr_idx + 3, found);
  }
}

// Function to recursively replace '+' with '-' and find expressions summing to 100
void replaceMinus(char *expression, int idx, char *curr_expr, int curr_idx, int *found)
{
  if (idx == 9)
  {
    curr_expr[curr_idx] = '\0';
    if (evaluateExpression(curr_expr) == 100)
    {
      printf("%s = 100\n", curr_expr);
      *found = 1;
    }
    return;
  }

  // Option 1: Keep current number as a single digit with '+'
  curr_expr[curr_idx] = expression[idx];
  curr_expr[curr_idx + 1] = '+';
  replaceMinus(expression, idx + 1, curr_expr, curr_idx + 2, found);

  // Option 2: Replace '+' with '-' for the current digit
  curr_expr[curr_idx] = expression[idx];
  curr_expr[curr_idx + 1] = '-';
  replaceMinus(expression, idx + 1, curr_expr, curr_idx + 2, found);

  // Option 3: Group current and next digit if possible
  if (idx < 8)
  {
    curr_expr[curr_idx] = expression[idx];
    curr_expr[curr_idx + 1] = expression[idx + 1];
    curr_expr[curr_idx + 2] = '+';
    replaceMinus(expression, idx + 2, curr_expr, curr_idx + 3, found);
  }
}

// Function to evaluate the arithmetic expression
int evaluateExpression(const char *expr)
{
  char buffer[MAX_LEN];
  strcpy(buffer, expr);

  // Remove '+' before negative numbers
  for (int i = 1; i < strlen(buffer); i++)
  {
    if (buffer[i] == '-' && buffer[i - 1] == '+')
    {
      for (int j = i - 1; j < strlen(buffer); j++)
      {
        buffer[j] = buffer[j + 1];
      }
    }
  }

  // Evaluate the resulting expression
  int total = 0, num = 0, sign = 1;
  for (int i = 0; i < strlen(buffer); i++)
  {
    if (buffer[i] == '+')
    {
      total += sign * num;
      sign = 1;
      num = 0;
    }
    else if (buffer[i] == '-')
    {
      total += sign * num;
      sign = -1;
      num = 0;
    }
    else
    {
      num = num * 10 + (buffer[i] - '0');
    }
  }
  total += sign * num;

  return total;
}

// Function to handle the GROUP option
void findGroupVariations()
{
  char expression[] = "123456789";
  char curr_expr[MAX_LEN];
  int found = 0;

  printf("Trying GROUP variations...\n");
  groupDigits(expression, 0, curr_expr, 0, &found);

  if (!found)
  {
    printf("No variation exists that sums to 100.\n");
  }
}

// Function to handle the REPLACEMINUS option
void findReplaceMinusVariations()
{
  char expression[] = "123456789";
  char curr_expr[MAX_LEN];
  int found = 0;

  printf("Trying REPLACEMINUS variations...\n");
  replaceMinus(expression, 0, curr_expr, 0, &found);

  if (!found)
  {
    printf("No variation exists that sums to 100.\n");
  }
}