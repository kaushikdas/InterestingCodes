import sys

class MathGame:
    MAX_N = 105
    MAX_VAL = 1000005

    def __init__(self):
        self.a_ = []; self.N_ = 0; self.pfs_ = []; self.maxVal_ = 0
        self.gcdpfs_ = []; self.gcd_ = 0; self.ops_ = 0

    def readTcInput(self):
        self.N_ = int(input())
        self.a_ = [int(i) for i in input().split(' ')]
        self.maxVal_ = max(self.a_)
        self.pfs_ = [0] * self.maxVal_

    def processPfs(self):
        # Find the sum of all prime factor powers
        maxFactor = 0
        for i in range(self.N_):
            n = self.a_[i]
            factor = 2
            while factor*factor < n:
                while (n % factor) == 0:
                    self.pfs_[factor] += 1
                    if factor > maxFactor:
                        maxFactor = factor
                    n //= factor
                factor += 1
            if n > 1:
                self.pfs_[n] += 1
                if n > maxFactor:
                    maxFactor = n
        
        self.gcd_ = 1
        for f in range(maxFactor + 1):
            if self.pfs_[f] > 0:
                self.pfs_[f] //= self.N_
                if self.pfs_[f] > 0:
                    self.gcdpfs_ += [f]
                    for i in range(self.pfs_[f]):
                        self.gcd_ *= f

    def countOps(self):
        self.ops_ = 0
        for i in range(self.N_):
            n = self.a_[i]
            for f in self.gcdpfs_:
                c = 0
                while (n % f) == 0:            
                    c += 1
                    n //= f
                if (c < self.pfs_[f]):
                    self.ops_ += (self.pfs_[f] - c)
    
    def solve(self):
        self.processPfs()
        self.countOps()

    def execute(self):
        self.readTcInput()

def main():
    # old_stdin = sys.stdin
    # sys.stdin = open('.\\Python\mathgame.txt')
    T = int(input())
    for tc in range(T):
        m = MathGame()
        m.execute()
        sys.stdout.write('#' + str(tc + 1) + ' ' + \
                         str(m.gcd_) + ' ' + str(m.ops_) + '\n')

if __name__ == '__main__': main()
