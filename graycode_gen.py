import sys

class GrayCode:
    def __init__(self, n):
        self._n = n; self._code = [0] * n

    
    def displayCode(self):
        for i in range(self._n):
            sys.stdout.write(str(self._code[i]))
            if (self._n - i - 1) % 4 == 0:
                sys.stdout.write(' ')
        sys.stdout.write('\n')
    
    def _generate(self, pos, setBit):
        if pos > 0:
            for x in self._generate(pos - 1, True):
                yield x

            if setBit: self._code[self._n - pos] = 1
            else:      self._code[self._n - pos] = 0
            
            yield self._code
            
            for x in self._generate(pos - 1, False):
                yield x

    def generateAll(self):
        yield self._code
        for x in self._generate(self._n, True):
            yield x

def main():
    gc = GrayCode(int(sys.argv[1]))
    for c in gc.generateAll():
        gc.displayCode()

if __name__ == '__main__': main()
