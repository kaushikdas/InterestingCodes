# 1. C++

# 2. Java

# 3. Python

## 3.1. Common

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

### 3.1.1. Math related&mdash;`math`module

| Operation | Description                |
| --------: | -------------------------- |
| `type(a)` | Gives type of variable `a` |


## 3.2 Collections
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

## 3.3. String

## 3.4 `list`

|                    Operation | Description                                                                                            |
| ---------------------------: | :----------------------------------------------------------------------------------------------------- |
|               **_Creation_** |                                                                                                        |
|                     `a = []` | Creates empty list `a`                                                                                 |
|                 `a = list()` | -do-                                                                                                   |
|                `a = [0]*100` | Crates a list of 100 0's                                                                               |
|                      `a = b` | `a` refers to list `b` (`a` & `b` refers to same list)                                                 |
|               `a = b.copy()` | `a` is copy of list `b`&mdash;changing `b` (`a`) does not affect `a` (`b`)                             |
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
|       **_Other Operations_** | -                                                                                                      |
|                      `a + b` | Concatenation of list `a` and list `b`                                                                 |
|                     `v in a` | `True` if `a` contains `v`, `False` otherwise&mdash;_O_(_n_)                                           |
|                 `for v in a` | Iterates over `a``&mdash;_O_(_n_)                                                                      |
|                 `a.index(v)` | Returns index of _first_ occurence of `v` in `a`&mdash;_O_(_n_) <br/> Raises `ValueError` if not found |
|                `a.reverse()` | Revesres `a`&mdash;_O_(_n_)                                                                            |
|                   `a.sort()` | Sorts `a`&mdash;_O_(_n_ log _n_)                                                                       |

## 3.5 `tuple`

|      Operation | Description                                         |
| -------------: | :-------------------------------------------------- |
| `tuple(aList)` | Creates tuple from list `aList`                     |
|       `len(a)` | Length of tuple `a`                                 |
|         `a[i]` | `i`<sup>th</sup> elemnt of  tuple `a`               |
|   `for v in a` | Iterates over tuple `a`                             |
|       `v in a` | `True` if tuple `a` contains `v`, `False` otherwise |

## 3.6 `set`

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

## 3.7 `dictionary`

|         Operation | Description                                                                                         |
| ----------------: | :-------------------------------------------------------------------------------------------------- |
| `dict()`<br/>`{}` | Creates empty dictionary`&mdash;_O_(1)                                                              |
|         `len(st)` | Length of `st`&mdash;_O_(1)                                                                         |
|           `st[k]` | The values associated with key `k`&mdash;_O_(1)<br/>Raises `KeyError` if no such key                |
|    `st.get(k, x)` | `st[k]` if `k` is in `st`; otherwise `x` (default `None`)                                           |
|       `st[k] = v` | Associate key `k` with value `v``&mdash;_O_(1)                                                      |
|         `k in st` | `True` if `st` contains `k`, `False` otherwise&mdash;_O_(1)                                         |
|       `del st[k]` | Delete key `k` and its associated value from `st`&mdash;_O_(1)<br/>Raises `KeyError` if no such key |
|     `for k in st` | Iterate over _keys_ in `st`&mdash;_O_(_n_)                                                          |

> Elements MUST be hashable