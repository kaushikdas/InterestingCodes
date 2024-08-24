#include <stdio.h>
#include <math.h>

/* Leibnitz
   pi = sum_i=1toINF { 4(-1)^(i + 1) / (2i - 1) } */

#define PI (22.0 / 7)

int main()
{
    int i = 1, d = 0;
    float epsilon = 1.0, pi = 1.0, old_pi = 0.0, diff = 0.0;
    float sum = 0.0, power_of_1s = -1.0;
    char format_string[100];

    printf("How many decimal places (between 1 - 8)? ");
    scanf("%d", &d);

    for (int j = 0; j <= d; j++)
    {
        epsilon /= 10.0;
    }
    /* printf("epsilon = %.10f\n", epsilon); */

    diff = pi - old_pi;

    while (diff > epsilon)
    {
        old_pi = pi;

        /* pi = sum_i=1toINF { 4(-1)^(i + 1) / (2i - 1) } */
        power_of_1s *= -1.0;
        sum += power_of_1s / (2 * i - 1);
        pi = sum * 4.0;

        i += 1;

        if (pi > old_pi)
        {
            diff = pi - old_pi;
        }
        else
        {
            diff = old_pi - pi;
        }

        /* diff = (pi > old_pi)? (pi - old_pi) : (old_pi - pi); */
    }

    printf("Iterations: %d\n", i);

    sprintf(format_string, "Value of pi = %%.%df\n", d);
    printf(format_string, pi);
    printf("Error w.r.t. 22/7 = %.9f\n", PI - pi);

    return 0;
}