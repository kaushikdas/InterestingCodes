#-----------------------------------------------------------------------
# rose.py
#-----------------------------------------------------------------------

import sys

sys.path.append('introcslib')
import stddraw

import math

# Accept integer command-line argument n. Draw an n petal rose (if n
# is odd) and a 2n petal rose (if n is even).

n = int(sys.argv[1])
stddraw.setXscale(-1, +1)
stddraw.setYscale(-1, +1)
stddraw.setPenColor(stddraw.RED)

x0 = 0.0
y0 = 0.0

t = 0.0
i = 0
while t <= 360.0:
    theta = math.radians(t)
    r = math.sin(n * theta)
    x1 = r * math.cos(theta)
    y1 = r * math.sin(theta)
    stddraw.line(x0, y0, x1, y1)
    # import stdio
    # stdio.writef("[%d] r = %.2f, t = %.2f, x0 = %.2f, y0 = %.2f, x1 = %.2f, y1 = %.2f\n", i, r, t, x0, y0, x1, y1)
    i += 1
    # if (i > 1000): break
    x0 = x1
    y0 = y1
    t += 100.0
    
stddraw.show()

#-----------------------------------------------------------------------

# python rose.py 4        

# python rose.py 7

# python rose.py 8