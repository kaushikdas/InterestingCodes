# 1 C++

## 1.1 Common

### 1.1.1 Numeric limits

#### C way

[C Numeric limits](https://en.cppreference.com/w/cpp/types/climits)

```cpp
#include <climits>

auto max = INT_MAX;
auto min = INT_MIN;
```

#### C++ way

[Numeric Limits](https://en.cppreference.com/w/cpp/types/numeric_limits)

```cpp
#include <limits>

auto constexpr ulmax = std::numeric_limits<unsigned long>::max();
auto constexpr imin = std::numeric_limits<int>::min();

```

## 1.2 String

# 2 Java

# 3 Python

## 3.1 Common

|           Operation | Description                                |
| ------------------: | ------------------------------------------ |
|     **For Objects** |                                            |
|           `help(a)` | Documentation for object `a`               |
|           `type(a)` | Gives type of variable `a`                 |
|             `id(a)` | Identity (memory address) of `a`           |
|           `hash(a)` | Hash value of object `a`                   |
| **Type conversion** |                                            |
|            `int(a)` | Coverts `a` to `int` type                  |
|          `float(a)` | Coverts `a` to `float` type                |
|          `float(a)` | Coverts `a` to `float` type                |
|            `abs(x)` | Absolute value of x                        |
|    `min(x, y, ...)` | Minimum of x, y, ... (ints/floats/strings) |
|    `max(x, y, ...)` | Maximum of x, y, ... (ints/floats/string)  |
|      `round(fv, 2)` | rounds float var `fv` to `2` places        |

### 3.1.1 Math related&mdash;`math`module

| Operation | Description                |
| --------: | -------------------------- |
| `type(a)` | Gives type of variable `a` |


## 3.2 String

## 3.3 Collections
<details>
  <summary>list</summary>

  - Ordered 
  - Indexed
  - Modifiable
  - Allows duplicate values
  - Allows values of different types
  
</details>

<details>
  <summary>tuple</summary>

  - Very much like lists&mdash;but non-modifiable
    - To modify: 
      1. Convert tuple to a list: `tempList = list(aTuple)`
      2. Modify the list: `tempList[i] = v`
      3. Rectreate a tuple from this list: `aTuple = tuple(tempList)`
  - Created using `()`
  - Can have duplicates
</details>

<details>
  <summary>set</summary>

  - Created with `{}` 
  - Unordered
  - Element cannot be modified&mdash;but can be added/deleted
  - Can **not** have duplicates
  - Elements MUST be hashable
</details>

<details>
  <summary>dictionary</summary>

  - Key-value pairs&mdash;`{'name' : 'kaushik'}` 
  - Elements MUST be hashable
</details>

### 3.3.1 `list`

|                    Operation | Description                                                                                            |
| ---------------------------: | :----------------------------------------------------------------------------------------------------- |
|               **_Creation_** |                                                                                                        |
|                     `a = []` | Creates empty list `a`                                                                                 |
|                 `a = list()` | -do-                                                                                                   |
|                `a = [0]*100` | Crates a list of 100 0's                                                                               |
|                      `a = b` | `a` refers to list `b` (`a` & `b` refers to same list)                                                 |
|               `a = b.copy()` | `a` is copy of list `b`&mdash;changing `b` (`a`) does not affect `a` (`b`)                             |
|           `a = list('ABCD')` | Same as `a = ['A', 'B', 'C', 'D']`                                                                     |
|                 **_Length_** |                                                                                                        |
|                     `len(a)` | Length of `a` &mdash; _O_(1)                                                                           |
|               **_Read/Get_** |                                                                                                        |
|                       `a[i]` | `i`<sup>th</sup> element of `a`&mdash;_O_(1)                                                           |
|                    `a.pop()` | _Deletes_ `a[len(a)-1]` from the list and returns that value&mdash;_O_(1)                              |
|                   `a.pop(i)` | _Deletes_ `a[i]` from the list and returns that value&mdash;_O_(1)                                     |
|                     `a[i:j]` | Returns a list `[a[i], a[i+1], ... , a[j-1]]`&mdash;_O_(_n_)                                           |
|             **_Modify/Set_** | -                                                                                                      |
|                  `a [i] = v` | Sets value `v` to `a[i]`                                                                               |
| `a += [v]`<br/>`a.append(v)` | Append `v` to `a`&mdash;_O_(1)                                                                         |
|                 `a[i:j] = b` | `a[i] = b[0]`, `a[i+1] = b[1]`, ...                                                                    |
|                   `del a[i]` | Deletes `a[i]` from list `a`&mdash;_O_(_n_)                                                            |
|             `a.insert(i, v)` | Inserts values `v` before `a[i]`&mdash;_O_(_n_)                                                        |
|                `a.remove(v)` | Removes first occurrence of `v` from `a`                                                               |
|            `[`a`].extend(b)` | Appends **elements** from `b` to `a`                                                                   |
|                  `a.clear()` | Clears list                                                                                            |
|       **_Other Operations_** | -                                                                                                      |
|                      `a + b` | Concatenation of list `a` and list `b`                                                                 |
|                     `v in a` | `True` if `a` contains `v`, `False` otherwise&mdash;_O_(_n_)                                           |
|                 `for v in a` | Iterates over `a``&mdash;_O_(_n_)                                                                      |
|                 `a.index(v)` | Returns index of _first_ occurence of `v` in `a`&mdash;_O_(_n_) <br/> Raises `ValueError` if not found |
|                `a.reverse()` | Revesres `a`&mdash;_O_(_n_)                                                                            |
|                   `a.sort()` | Sorts `a`&mdash;_O_(_n_ log _n_)                                                                       |
|      ` a.sort(reverse=True)` | Sorts list `a` in **descending** order                                                                 |
|                 `a.count(v)` | Counts # of occurrences of `v` in list `a`                                                             |
|                 `a.revese()` | Reverse list `a`                                                                                       |

### 3.3.2 `tuple`

|      Operation | Description                                         |
| -------------: | :-------------------------------------------------- |
| `tuple(aList)` | Creates tuple from list `aList`                     |
|       `len(a)` | Length of tuple `a`                                 |
|         `a[i]` | `i`<sup>th</sup> elemnt of  tuple `a`               |
|   `for v in a` | Iterates over tuple `a`                             |
|       `v in a` | `True` if tuple `a` contains `v`, `False` otherwise |
|   `a.index(v)` | Same as list                                        |
|   `a.count(v)` | Same as list                                        |

### 3.3.3 `set`

|           Operation | Description                                                                                  |
| ------------------: | :------------------------------------------------------------------------------------------- |
|    `set()`<br/>`{}` | Creates empty set&mdash;_O_(1)                                                               |
|            `len(s)` | Length of set `s`&mdash;_O_(1)                                                               |
|          `s.add(e)` | Adds item `e` to set `s`&mdash;_O_(1) (if not present already)                               |
|       `s.remove(e)` | Removes item `e` from set `s`&mdash;_O_(1) <br/>Raises `KeyError` if the `e` is not a member |
|            `e in s` | `True` if `s` contains `e`, `False` otherwise&mdash;_O_(1)                                   |
|        `for e in s` | Iterate over set `s`&mdash;_O_(_n_)                                                          |
| `s.intersection(t)` | Intersection of `s` and `t``&mdash;_O_(_n_)                                                  |
|        `s.union(t)` | Union of `s` and `t``&mdash;_O_(_n_)                                                         |

> Elements MUST be hashable

### 3.3.4 `dictionary`

|                      Operation | Description                                                                                                          |
| -----------------------------: | :------------------------------------------------------------------------------------------------------------------- |
|              `dict()`<br/>`{}` | Creates empty dictionary`&mdash;_O_(1)                                                                               |
|                      `len(st)` | Length of `st`&mdash;_O_(1)                                                                                          |
| `st = st.fromkeys(list('AB'))` | `st = {'A': None, 'B': None`&mdash;Form keys in the dict based on the input, it has to be stored in another variable |
d
| `st[k]` | The values associated with key `k`&mdash;_O_(1)<br/>Raises `KeyError` if no such key |
|                                                                                   `st.get(k)` | Gets value of key `k`&mdash;`None` if not found                                                     |
|                                                                                `st.get(k, x)` | `st[k]` if `k` is in `st`; otherwise `x` (default `None`)                                           |
|                                                                                   `st[k] = v` | Associate key `k` with value `v`&mdash;_O_(1)                                                       |
|                                                                                     `k in st` | `True` if `st` contains `k`, `False` otherwise&mdash;_O_(1)                                         |
|                                                                 `del st[k]` <br/> `st.pop(k`) | Delete key `k` and its associated value from `st`&mdash;_O_(1)<br/>Raises `KeyError` if no such key |
|                                                                                 `for k in st` | Iterate over _keys_ in `st`&mdash;_O_(_n_)                                                          |
|                                                                                   `st.keys()` | Keys in `st` (dict_keys(['one', 'two']))                                                            |
|                                                                                 `st.values()` | Values in (`dict_values([1, 2])`)`st`                                                               |
|                                                                                  `st.items()` | Key values paits in `st` (`dict_items([('o', 1), ('t', 2)])`)                                       |
|                                                                                `st.update(d)` | Update `st` using dict `d`, if the key from `d` is present it gets updated, if not it gets created  |

> Elements MUST be hashable

## 3.4 Miscelleneous

### 3.4.1 `os` module

```python
import os

# os.name: OS Name
print(os.name)  # nt - Windows

# os.getcwd(): Current working directory
print(os.getcwd())

# os.listdir(): Contents of a directory
print(os.listdir("."))

# os.mkdir: Make dir: os.mkdir()
os.mkdir("C:\\Users\\Kaushik\\Test\\python\\new_dir")

# os.rename(): Rename dir 
os.rename("old_dir_path_with_dir_name", "new_dir_path_with_dir_name")

# Create and edit file
dir_fd = os.open('somedir', os.O_RDONLY)
def opener(path, flags):
    return os.open(path, flags, dir_fd=dir_fd)

with open('spamspam.txt', 'w', opener=opener) as f:
    print('This will be written to somedir/spamspam.txt', file=f)

os.close(dir_fd)  # don't leak a file descriptor
```