#include <stdio.h>

int main()
{
    int i = 1, d = 2;
    float epsilon = 1.0, e = 1.0, old_e = 0.0, diff = e - old_e;
    float sum = 1.0, term = 1.0;
    char format_string[100];

    printf("How many decimal places (between 2 - 7)? ");
    scanf("%d", &d);
    for (; (d < 2) || (d > 8);)
    {
        printf("Invalid decimal places! Retry!\n");
        printf("How many decimal places (between 2 - 7)? ");
        scanf("%d", &d);
    }

    for (int j = 0; j <= d; j++)
    {
        epsilon /= 10.0;
    }
    /* printf("epsilon = %.10f\n", epsilon); */

    for (i = 1; diff > epsilon; i++)
    {
        old_e = e;

        /* 1/e = sum_0toINF { (-1)^i / i! } */
        term *= (-1.0 / i);

        sum += term;
        e = (sum != 0) ? 1.0 / sum : sum;

        diff = (e > old_e) ? (e - old_e) : (old_e - e);
    }

    printf("Iterations: %d\n", i);

    sprintf(format_string, "Value of e = %%.%df\n", d);
    printf(format_string, e);

    return 0;
}