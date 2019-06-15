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
            self._generate(pos - 1, True)

            if setBit: self._code[self._n - pos] = 1
            else:      self._code[self._n - pos] = 0
            self.displayCode()
            
            self._generate(pos - 1, False)

    def generateAll(self):
        self.displayCode()
        self._generate(self._n, True)

def main():
    gc = GrayCode(int(sys.argv[1]))
    gc.generateAll()

if __name__ == '__main__': main()
