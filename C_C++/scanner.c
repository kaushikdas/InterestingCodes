#include <stdio.h>

#define UNK 0
#define VOWEL_LC 1
#define VOWEL_UC 2
#define CONSONANT_LC 3
#define CONSONANT_UC 4
#define DIGIT 5
#define BINARY_OP 6
#define PUNCT 7
#define BRACKET 8

#include <stdio.h>

int main(void)
{
    char c;
    int category = UNK;

    printf("Input? ");

    do
    {
        category = UNK;
        c = getchar();

        if ((c >= 'a') && (c <= 'z'))
        {
            if ((c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u'))
            {
                category = VOWEL_LC;
            }
            else
            {
                category = CONSONANT_LC;
            }
        }
        else if ((c >= 'A') && (c <= 'Z'))
        {
            if ((c == 'A') || (c == 'E') || (c == 'I') || (c == 'O') || (c == 'U'))
            {
                category = VOWEL_UC;
            }
            else
            {
                category = CONSONANT_UC;
            }
        }
        else if ((c >= '0') && (c <= '9'))
        {
            category = DIGIT;
        }
        else if ((c == '+') || (c == '-') || (c == '*') || (c == '/') || (c == '%'))
        {
            category = BINARY_OP;
        }
        else if ((c == ',') || (c == ':') || (c == ';') || (c == '\'') || (c == '"'))
        {
            category = PUNCT;
        }
        else if ((c == '(') || (c == ')') || (c == '{') || (c == '}') || (c == '[') || (c == ']'))
        {
            category = BRACKET;
        }
        else
        {
            category = UNK;
        }

        switch (category)
        {
        case VOWEL_LC:
            printf("Vowel %c\n", c - 32);
            break;
        case VOWEL_UC:
            printf("Vowel %c\n", c);
            break;
        case CONSONANT_LC:
            printf("Consonant %c\n", c - 32);
            break;
        case CONSONANT_UC:
            printf("Vowel %c\n", c);
            break;
        case DIGIT:
            printf("Digit %c\n", c);
            break;
        case BINARY_OP:
            printf("BinaryOperator %c\n", c);
            break;
        case PUNCT:
            printf("Punctuator %c\n", c);
            break;
        case BRACKET:
            printf("Bracket %c\n", c);
            break;
        default:
            break;
        }
    } while (c != '\n');

    return 0;
}