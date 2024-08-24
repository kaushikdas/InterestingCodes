import sys

EPSILON = 1e-15

c = float(sys.argv[1])
k = int(sys.argv[2])

t = c

while abs(t - c/(t**(k-1)) > (EPSILON * t)):
    # Replace t with new estimate
    t = (c/(t**(k-1)) + (k-1)*t)/k
    
print(f'{k}th root of {c} = {t}')

#-----------------------------------------------------------------------

# python kth_root.py 8 3
# 3th root of 8.0 = 2.0

# python kth_root.py 625 3
# 3th root of 625.0 = 8.549879733383484

# python kth_root.py 125 3
# 3th root of 125.0 = 5.0

# python kth_root.py 16 4 
# 4th root of 16.0 = 2.0

# python kth_root.py 704969 3
# 3th root of 704969.0 = 89.0

# python kth_root.py 1419757 5
# 5th root of 1419757.0 = 16.999760532519236