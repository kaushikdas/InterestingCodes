#include <stdio.h>

#define MAX 999

int main()
{
  int P, /* No. of +ve points */
      N; /* No. of -ve points */

  int px[MAX] = {0}, py[MAX] = {0}, nx[MAX] = {0}, ny[MAX] = {0};
  int max_px = -1, max_py = -1, min_px = MAX + 1, min_py = MAX + 1;
  int max_nx = -1, max_ny = -1, min_nx = MAX + 1, min_ny = MAX + 1;
  int max_x = -1, max_y = -1, min_x = MAX + 1, min_y = MAX + 1;

  int tx, ty; /* temp. variables */

  printf("++ Enter Number of Positive-Labelled Points: ");
  scanf("%d", &P);
  printf("++ Enter Positive-Labelled Points:\n");
  for (int i = 0; i < P; i++)
  {
    printf("    -- Enter Point-%d (space-separated X,Y-values): ", i + 1);
    scanf("%d %d", &tx, &ty);
    px[i] = tx;
    py[i] = ty;

    max_px = (max_px < tx) ? tx : max_px; /* Identify max_px */
    max_py = (max_py < ty) ? ty : max_py; /* Identify max_py */

    min_px = (min_px > tx) ? tx : min_px; /* Identify min_px */
    min_py = (min_py > ty) ? ty : min_py; /* Identify min_py */

    max_x = (max_x < tx) ? tx : max_x;
    max_y = (max_y < ty) ? ty : max_y;

    min_x = (min_x > tx) ? tx : min_x;
    min_y = (min_y > ty) ? ty : min_y;
  }

  printf("\n++ Enter Number of Negative-Labelled Points: ");
  scanf("%d", &N);
  printf("++ Enter Negative-Labelled Points:\n");
  for (int i = 0; i < N; i++)
  {
    printf("    -- Enter Point-%d (space-separated X,Y-values): ", i + 1);
    scanf("%d %d", &tx, &ty);
    nx[i] = tx;
    ny[i] = ty;

    max_nx = (max_nx < tx) ? tx : max_nx; /* Identify max_nx */
    max_ny = (max_ny < ty) ? ty : max_ny; /* Identify max_ny */

    min_nx = (min_nx > tx) ? tx : min_nx; /* Identify min_nx */
    min_ny = (min_ny > ty) ? ty : min_ny; /* Identify min_ny */

    max_x = (max_x < tx) ? tx : max_x;
    max_y = (max_y < ty) ? ty : max_y;

    min_x = (min_x > tx) ? tx : min_x;
    min_y = (min_y > ty) ? ty : min_y;
  }

  printf("\n** Spatial Canvas with Positive and Negative Points **\n");

  /* EACH POINT IS ASSUMED TO OCCUPY A WIDTH OF 3 UNITS */

  for (ty = max_y; ty >= min_y; ty--)
  {
    /* Print y axis label */
    int is_inside = 0; /* Is inside containment zone
                          For each row we will start outside the
                          containment zone */
    printf("%3d|  ", ty);

    for (tx = min_x; tx <= max_x; tx++)
    {
      /* Now we are at tx, ty point in the space */

      int is_real_ppt = 0, /* If tx, ty a real +ve point */
          is_real_npt = 0 /* If tx, ty a real -ve point */;

      for (int i = 0; i < max_py; i++)
      {
        if ((ty == py[i]) && (tx == px[i]))
        {
          is_real_ppt = 1;
          break;
        }
      }

      for (int i = 0; i < max_ny; i++)
      {
        if ((ty == ny[i]) && (tx == nx[i]))
        {
          is_real_npt = 1;
          break;
        }
      }

      /* is_real_ppt and is_real_npt both should not be 1 */

      if (is_real_ppt) /* real positive pt. */
        printf("(+)");
      else if (is_real_npt) /* real positive pt. */
        printf("(-)");
      else if ((tx < min_px) || (tx > max_px) ||
               (ty < min_py) || (ty > max_py))
      {
        /* outside containment zone */
        printf("   ");
      }
      else /* Inside or on the boundary of the containment zone */
      {
        if (tx == min_px) /* left birder of c. zone  */
        {
          if ((ty == max_py) || (ty == min_py)) /* top or bottom
                                                   corner of c. zone */
          {
            printf(" +-");
          }
          else /* left border */
          {
            printf(" | ");
          }
        }
        else if (tx == max_px) /* right border of c. zone */
        {
          if ((ty == max_py) || (ty == min_py)) /* top or bottom
                                                   corner of c. zone */
          {
            printf("-+ ");
          }
          else /* right border */
          {
            printf(" | ");
          }
        }
        else if ((ty == max_py) || (ty == min_py)) /* c. zone top or
                                                      bottom border */
        {
          printf("---"); /* NOT a real point */
        }
        else /* Inside c.zone */
        {
          printf("   "); /* NOT a real point */
        }
      }
    }
    printf("\n");
  }

  /* print x-axis */
  printf("     ");
  for (int i = min_x; i <= max_x; i++)
  {
    printf("-+-", i);
  }
  printf("\n");
  /* print x-axis labels */
  printf("     ");
  for (int i = min_x; i <= max_x; i++)
  {
    printf("%3d", i);
  }
  printf("\n");

  return 0;
}

/*
SAMPLE OUTPUT

$ ./bounding_box.o
++ Enter Number of Positive-Labelled Points: 5
++ Enter Positive-Labelled Points:
    -- Enter Point-1 (space-separated X,Y-values): 6 10
    -- Enter Point-2 (space-separated X,Y-values): 8 6
    -- Enter Point-3 (space-separated X,Y-values): 15 8
    -- Enter Point-4 (space-separated X,Y-values): 12 13
    -- Enter Point-5 (space-separated X,Y-values): 11 9

++ Enter Number of Negative-Labelled Points: 7
++ Enter Negative-Labelled Points:
    -- Enter Point-1 (space-separated X,Y-values): 2 8
    -- Enter Point-2 (space-separated X,Y-values): 9 2
    -- Enter Point-3 (space-separated X,Y-values): 18 3
    -- Enter Point-4 (space-separated X,Y-values): 20 11
    -- Enter Point-5 (space-separated X,Y-values): 18 18
    -- Enter Point-6 (space-separated X,Y-values): 11 17
    -- Enter Point-7 (space-separated X,Y-values): 5 19

** Spatial Canvas with Positive and Negative Points **
 19|           (-)
 18|                                                  (-)
 17|                             (-)
 16|
 15|
 14|
 13|               +----------------(+)-------+
 12|               |                          |
 11|               |                          |             (-)
 10|              (+)                         |
  9|               |             (+)          |
  8|  (-)          |                         (+)
  7|               |                          |
  6|               +----(+)-------------------+
  5|
  4|
  3|                                                  (-)
  2|                       (-)
     -+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+-
       2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20
*/