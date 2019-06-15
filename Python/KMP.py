import sys

class KMP:
    def __init__(self, txt, pat):
        self.t_ = txt # text to search
        self.p_ = pat # pattern to search
        self.n_ = len(self.t_)
        self.m_ = len(self.p_)
        self.pi_ = [0] * self.m_ # pi_ is the lps table

    '''
    For a pattern acacabacacabacacac the prefix table will be
    0 0 1 2 3 0 1 2 3 4 5 6 7 8 9 10 11 4
    '''
    def precomputePrefixTable(self):
        self.pi_[0] = 0
        q = 1
        k = 0
        while q < self.m_:
            while (k > 0) and (self.p_[k] != self.p_[q]):
                k = self.pi_[k - 1]
            if (self.p_[k] == self.p_[q]):
                k += 1
            self.pi_[q] = k
            q += 1
        '''
        sys.stdout.write('Longest-Prefix-Suffix table\n')
        for i in range(len(self.pi_)):
            sys.stdout.write(str(self.pi_[i]) + ' ')
        sys.stdout.write('\n')
        '''

    def search(self, searchAll = False):
        pos = []
        if self.n_ < self.m_:
            return pos

        self.precomputePrefixTable()
        q = 0 # index in the pattern
        for i in range(self.n_):
            while (q > 0 ) and (self.p_[q] != self.t_[i]):
                q = self.pi_[q - 1]
            if (self.p_[q] == self.t_[i]):
                q += 1
            if q == self.m_:
                # One match found
                pos += [i - self.m_ + 1]
                if searchAll == False:
                    return pos
                q = self.pi_[q - 1] # continue search for next match
        return pos

def main():
    # old_stdin = sys.stdin
    # sys.stdin = open('.\\Python\kmp.txt')
    T = int(input())
    for tc in range(T):
        text = input()
        pattern = input()
        kmp = KMP(text, pattern)
        pos = kmp.search(True)
        sys.stdout.write('#' + str(tc) + '\n')
        sys.stdout.write('Text:\n  ' + text + '\nPattern:\n  ' \
                         + pattern + '\nResult:\n  ')
        if len(pos) > 0:
            sys.stdout.write(str(len(pos)) + \
                ' occurence(s) of pattern found at: ')
            for i in range(len(pos)):
                sys.stdout.write(str(pos[i]) + ' ')
            sys.stdout.write('\n')
        else:
            sys.stdout.write('Pattern not found.\n')

if __name__ == '__main__': main()

'''
SAMPLE INPUT
2
THIS IS A TEST TEXT
TEST
AABAACAADAABAABA
AABA

SAMPLE OUTPUT
#0
Text:
  THIS IS A TEST TEXT
Pattern:
  TEST
Result:
  1 occurence(s) of pattern found at: 10 
#1
Text:
  AABAACAADAABAABA
Pattern:
  AABA

'''
