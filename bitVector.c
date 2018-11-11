/**
 * bitVector data structure to implement linear time sorting of 
 * NON-NEGATIVE integers
 * 
 * Inspired by Problem 3 of COLUMN 1 in the book Programming
 * Pearls, 2nd edition by John Bentley. Although the original
 * problem does not allow duplicate integers, below implementation
 * allows maximum 3 DUPLICATES for any integer.
 */

#include <stdio.h>

#define BITS_PER_WORD (32) /* sizeof(int) is assumed to be 32 */
#define BITS_PER_INT_lg (1) /* 2^BITS_PER_INT_lg bits per int.
                               Since any int i can repeat at most 
                               3 times, we can use 2 bits to store
                               number of times i appears. */
#define BITS_PER_INT (1 << BITS_PER_INT_lg) /* 2 bits per int */
#define INTS_PER_WORD (BITS_PER_WORD >> BITS_PER_INT_lg) /* 16 */
#define SHIFT (4) /* Since we will store 16 ints in one int array
                     element, for any int i its most signficant
                     32 - 4 = 28 bits will decide in which array
                     element i will be stored. Therefore, to get
                     the array index we need to shift i by 4. */
#define MASK (~(1 << SHIFT)) /* = 0xF, this will lift 4 least 
                                significant bits. */
#define BIT_MASK (~(~0 << BITS_PER_INT)) /* = 0x11 */
#define MAX_N (1000000) /* Can sort maximum 1 M NON-NEGATIVE integers */
#define MAX_SZ (MAX_N/INTS_PER_WORD + 1)

#define GET_BITS() \
    {\
        /* offset within an array element */\
        offset = ((i & MASK) << BITS_PER_INT_lg);\
        /* bits in the array element represeting counts of i */\
        n = (a[i >> SHIFT] & (BIT_MASK << offset)) >> offset; \
    }

int a[MAX_SZ]; /* array storing given integers in compact form */

void add(int i)
{
    int n = 0, offset = 0;
    GET_BITS();             
    if (n >= ((1 << BITS_PER_INT) - 1)) {
        /* Any integer can repeat at most 3 times */
        printf("add-fail: %d has already appeared %d times\n", 
                i, n);
        return; 
    }

    a[i >> SHIFT] += 1 << offset;
}

void clear(int i)
{
    int n = 0, offset = 0;
    GET_BITS();
    if (n == 0) {
        printf("clear-fail: %d has never appeared\n", i); 
        return; /* Any integer can repeat at most 3 times */
    }

    a[i >> SHIFT] -= 1 << ((i & MASK) << BITS_PER_INT_lg);
}

int test(int i)
{
    int n = 0, offset = 0;
    GET_BITS();
    return (n == 0) ? 0 : 1;
}

void init()
{
    int i = 0;
    for (i = 0; i < MAX_SZ; ++i) a[i] = 0;
}

int main()
{
    int N = 0, i = 0, v = 0, j = 0, t = 0, T = 0;

    /* freopen("bitvectorinput.txt", "r", stdin); */

    scanf("%d", &T);
    for (t = 0; t < T; ++t)
    {
        init();
        scanf("%d", &N);
        for (i = 0; i < N; ++i)
        {
            scanf("%d", &v);
            add(v);
        }
        printf("#%d ", t + 1);
        j = 0;
        for (i = 0; (i < MAX_N && j < N); ++i)
        {
            while (test(i))
            {
                printf("%d ", i);
                j++;
                clear(i);
            }
        }
        printf("\n");
    }
}

/*

SAMPLE INPUT

2
10
50 20 100 4 50 10 30 30 20 50
16
200 85 19 24 23 19 19 99 76 76 33 512 100 43 100 85

SAMPLE OUTPUT

> .\bitvector.exe
#1 4 10 20 20 30 30 50 50 50 100
#2 19 19 19 23 24 33 43 76 76 85 85 99 100 100 200 512

*/
