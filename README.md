# Some Interesting Codes

# DS and Algo Problems

## HackerRank

### 1. Minimum Swaps 2 (`Medium`)

You are given an unordered array consisting of consecutive integers
from [1, 2, 3, ..., n] without any duplicates. You are allowed to
swap any two elements. Find the minimum number of swaps required to
sort the array in ascending order. 

- **Sol:** Just put an element in its right position: `x` at `arr[x-1]`

### 2. Sherlock and Anagrams (Medium)

Two strings are anagrams of each other if the letters of one string can
be rearranged to form the other string. Given a string, find the number
of pairs of substrings of the string that are anagrams of each other.

Example

`s = mom`

The list of all anagrammatic pairs `[m, m], [mo, om]` are at positions
`[[0, 0], [2, 2]], [[0, 1], [1, 2]]` respectively.

- **Sol:** Simple brute force

  ```python
  for sz in range(1..s.len()):
      for i in range(0, s.len() - len + 1):
          for j in range(i+1, s.len() - len + 1):
              checkIfAnagram(s[i:i+sz], sz[j:j+sz])
  ```
  
### 3. New Year Chaos (Medium)

n peersons [1...n] are in a queue in order. One person can bride atmost
2 persons in front. Return the total number of bribes if no one has
bribed more than 2 people, otherwise just print `Too chaotic`

- **Sol:** Keep track expected (next) 3 numbers starting with `1, 2, 3`.
If 2 is found instead of 1, change expected list to 1, 3 and 4 with
bribe count as 1.

### 4. Array Manipulation (Hard)

Starting with a 1-indexed array of zeros and a list of operations, for
each operation add a value to each the array element between two given
indices, inclusive. Once all operations have been performed, return th
maximum value in the array.

Example

n = 10

Queries:

```
    a b k
    1 5 3
    4 8 7
    6 9 1
```

Add the values of `k` between the indices `a` and `b` inclusive:

```
index->	 1 2 3  4  5 6 7 8 9 10
	      [0,0,0, 0, 0,0,0,0,0, 0]
      	[3,3,3, 3, 3,0,0,0,0, 0]
      	[3,3,3,10,10,7,7,7,0, 0]
	      [3,3,3,10,10,8,8,8,1, 0]
```
The largest value is `10` after all operations are performed.

- **Sol:** 

```
(a, b, k) -> values between arr[a..b] are incaremented by k
Instead of actually incrementing all elements arr[a..b]
just incremenet arr[a] by k and decrement arr[b+1] by k:

           +k                   -k
   +-----+----+---------------+----+------+
   | ... |    |   ....        |    | ...  |
   +-----+----+---------------+----+------+
            a                    b
This indicates that all elements before index a and after
index b are less than [a..b] by k. So that when we calculate
the value at an index using CUMULATIVE sum till that index
we get the correct value.
```

### 5. Organizing Containers of Balls (`Medium`)

David has several containers, each with a number of balls in 
it. He has just enough containers to sort each type of ball he 
has into its own container. David wants to sort the balls 
using his sort method.

David wants to perform some number of swap operations such that:

- Each container contains only balls of the same type.
- No two balls of the same type are located in different containers.

- **Sol:**
  - Count the freq of each colour
  - Count the cpacity of each color
  - Now for each box capacity check if the a color freq equal
    to that

