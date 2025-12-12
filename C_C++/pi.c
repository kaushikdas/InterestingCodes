#include <stdio.h>
#include <math.h>

/* pi^2/6 = sum_i=1toINF {1/i^2} */

#define PI (22.0 / 7)

int main()
{
    int i = 1, d = 0;
    float epsilon = 1.0, sum = 0.0, pi = 1.0, old_pi = 0.0;
    char format_string[100];

    printf("How many decimal places (between 1 - 8)? ");
    scanf("%d", &d);

    for (int j = 0; j <= d; j++)
    {
        epsilon /= 10.0;
    }
    /* printf("epsilon = %.10f\n", epsilon); */

    while ((pi - old_pi) > epsilon)
    {
        old_pi = pi;

        sum += 6.0 / (i * i);
        pi = sqrt((double)sum);

        i += 1;
    }
    printf("Iterations: %d\n", i);

    sprintf(format_string, "Value of pi = %%.%df\n", d);
    printf(format_string, pi);
    printf("Error w.r.t. 22/7 = %.9f\n", PI - pi);

    return 0;
}