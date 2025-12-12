import sys

sys.path.append('.\InterestingCodes\Python\introcslib')
import stddraw

import math

from turtle import Turtle

# dragon curve
def dragon(n, turtle):
    if (n == 0):
        turtle.goForward(1.0) 
        return
    dragon(n - 1, turtle)
    turtle.turnLeft(90)
    # turtle.goForward(1.0)
    nogard(n - 1, turtle)
    # stddraw.show(1000)

# evruc nogard
def nogard(n, turtle):
    if (n == 0):
        turtle.goForward(1.0) 
        return
    dragon(n - 1, turtle)
    turtle.turnLeft(-90)
    # turtle.goForward(1.0)
    nogard(n - 1, turtle)
    # stddraw.show(1000)

def Dragon(n):
    '''***********************************************************************
    *  The following constants are used to figure out where to start         
    *  drawing the dragon curve.  left[i] = maximum number of steps taken
    *  to the left in dragon(i).  right[i], up[i], down[i] are similar.
    ***********************************************************************'''
    left  = [ 0, 0, 0, 2, 4, 5, 5,  5,  5,  5, 10, 42, 74, 81,  85,  85 ]
    right = [ 1, 1, 1, 1, 1, 1, 2, 10, 18, 21, 21, 21, 21, 21,  57, 170 ]
    up    = [ 0, 1, 2, 2, 2, 2, 2,  2,  5, 21, 37, 42, 42, 42,  42,  42 ]
    down  = [ 0, 0, 0, 0, 1, 5, 9, 10, 10, 10, 10, 10, 23, 85, 149, 165 ]

    size = max(left[n] + right[n], up[n] + down[n])
    x = (right[n] - left[n]) / 2.0
    y = (up[n]    - down[n]) / 2.0
    stddraw.setXscale(x - size/2, x + size/2)
    stddraw.setYscale(y - size/2, y + size/2)

    turtle = Turtle(0.5, 0.5, 0.0)

    dragon(n, turtle)
    stddraw.show()

def main():
    n = int(sys.argv[1])
    Dragon(n)

if __name__ == '__main__':
    main()