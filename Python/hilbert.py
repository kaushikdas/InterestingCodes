import sys

sys.path.append('.\InterestingCodes\Python\introcslib')
import stddraw

import math

from turtle import Turtle

# Hilbert curve
def hilbert(n, turtle):
    if (n == 0): return

    turtle.turnLeft(-90)

    treblih(n-1, turtle)

    turtle.goForward(1.0)
    turtle.turnLeft(90)
    
    hilbert(n-1, turtle)
    
    turtle.goForward(1.0)
    
    hilbert(n-1, turtle)
    
    turtle.turnLeft(90)
    turtle.goForward(1.0)
    
    treblih(n-1, turtle)
    
    turtle.turnLeft(-90)
    
    stddraw.show(300)

# evruc trebliH
def treblih(n, turtle):
    if (n == 0): return
    turtle.turnLeft(90)
    hilbert(n-1, turtle)
    turtle.goForward(1.0)
    turtle.turnLeft(-90)
    treblih(n-1, turtle)
    turtle.goForward(1.0)
    treblih(n-1, turtle)
    turtle.turnLeft(-90)
    turtle.goForward(1.0)
    hilbert(n-1, turtle)
    turtle.turnLeft(90)
    stddraw.show(300)

def Hilbert(n):
    max = math.pow(2, n)
    turtle = Turtle(max - 0.5, max - 0.5, 270.0)
    
    stddraw.setXscale(0, max)
    stddraw.setYscale(0, max)
    hilbert(n, turtle)
    stddraw.show()

def main():
    n = int(sys.argv[1])
    Hilbert(n)

if __name__ == '__main__':
    main()