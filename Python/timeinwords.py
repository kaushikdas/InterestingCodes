# https://www.hackerrank.com/challenges/the-time-in-words/problem


def numToWord(n):
    numDict = {1: 'one',
               2: 'two',
               3: 'three',
               4: 'four',
               5: 'five',
               6: 'six',
               7: 'seven',
               8: 'eight',
               9: 'nine',
               10: 'ten',
               11: 'eleven',
               12: 'twelve',
               13: 'thirteen',
               14: 'fourteen',
               15: 'quarter',
               16: 'sixteen',
               17: 'seventeen',
               18: 'eighteen',
               19: 'nineteen',
               20: 'twenty',
               30: 'half',
               40: 'forty',
               50: 'fifty'}
    if n < 1 or n >= 60:
        return ''
    elif n >= 1 and n <= 20:
        return numDict[n]
    else:
        unit = n % 10
        unitStr = '' if unit == 0 else ' ' + numDict[unit]
        return numDict[n-unit] + unitStr


def minStr(m):
    if m == 1:
        return ' minute'
    elif m == 15 or m == 30:
        return ''
    else:
        return ' minutes'


def timeInWords(h, m):
    '''Converts time specified by hour h and minute m to words
    Example:
        timeInWords(5, 0)  gives "five o' clock"
        timeInWords(5, 1)  gives "one minute past five",
        timeInWords(5, 10) gives "ten minutes past five"
        timeInWords(5, 15) gives "quarter past five"
        timeInWords(5, 30) gives "half past five"

    Args:
        h (integer)): hour
        m (integer): minute

    Returns:
        [type]: [description]
    '''
    if m == 0:
        return (numToWord(h) + " o' clock")
    elif m <= 30:
        return (numToWord(m) + minStr(m) + ' past ' + numToWord(h))
    else:
        h += 1
        h = 1 if h > 12 else h
        #minStr = ' minutes' if (60-m) != 15 else ''
        return (numToWord(60-m) + minStr(60-m) + ' to ' + numToWord(h))


if __name__ == '__main__':
    tc = [(5, 0, "five o' clock"),
          (5, 1, 'one minute past five'),
          (5, 10, 'ten minutes past five'),
          (5, 15, 'quarter past five'),
          (5, 30, 'half past five'),
          (5, 40, 'twenty minutes to six'),
          (5, 45, 'quarter to six'),
          (5, 47, 'thirteen minutes to six'),
          (5, 28, 'twenty eight minutes past five')
          ]

    for t in tc:
        timeStr = timeInWords(t[0], t[1])
        assert(timeStr == t[2])
        # print("{0:02d}:{1:02d} -> {2}".format(t[0], t[1], timeStr))
        print("{h:02d}:{m:02d} -> {s}"
              .format(h=t[0], m=t[1], s=timeStr))

    print(timeInWords.__doc__)
