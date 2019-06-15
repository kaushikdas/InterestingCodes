/**
 * Generate Gray Codes of n bits (max 10) using the mirroring
 * technique - mirror n - 1 bit codes, prefix 0 to original code(s) and 
 * prefix 1 to mirrored codes:
 * 1 bit    2 bits    3 bits
 * =====    ======    ======
 *   0        0 0      0 00
 *   1        0 1      0 01    0 prefixed to each code
 *            ----     0 11    (shown in space separated column)
 *            1 1      0 10
 *            1 0     ------ <--- mirror
 *                     1 10      
 *                     1 11    1 prefixed to each code
 *                     1 01    (shown in space separated column)
 *                     1 00
 **/

#include <iostream>
#include <fstream>

using namespace std;

const int MAX = 1024;

class GrayCode
{
    int _n;
    unsigned int _codes[MAX];
    ofstream myout;

    // Generates Gray Codes till n bits
    void _generate(int n)
    {
        if (0 == n) return;

        // Generate Gray Codes till n - 1 bits
        _generate(n - 1);

        ///////////////////////////////////////////////////////////////
        //                    |
        //           2^(n-1)-1|         
        //       0 1        \ |
        //      +-+-+-------+-+-+-+-------+-+
        //      |o|o|       |o|m|m|       |m|   
        //      +-+-+-------+-+-+-+-------+-+
        //                    | \           \
        //                    | 2^(n-1)    2^n - 1
        //                    |
        // Original codes: o[0] ... o[2^(n-1)-1], 
        // Mirrored codes: m[2^(n-1)] ... m[2^n - 1]
        //
        // In the below loop i (mirror side index) iterates from 2^(n-1)
        // up to 2^n-1 while j (original side index) iterates from
        // 2^(n-1)-1 down to 0.
        // For the mirrored codes prefix 1 by just OR-ing 2^(n-1), i.e.,
        // 1 followed by n-1 0's which is same as the start value of i.
        ///////////////////////////////////////////////////////////////
        int start = 1 << (n - 1), end = 1 << n;
        for (int i = start, j = start - 1; i < end; ++i, --j)
            _codes[i] = _codes[j] | start;
    };

    void _output(int code)
    {
        for (int i = _n - 1; i >= 0; --i) {
            myout << ((code & (1 << i)) >> i);
            // add a blank space after every 4 bits
            if (i % 4 == 0)
                myout << " ";
        }
        myout << endl;
    };

    void _outputAll(void)
    {
        for (int i = 0; i < (1 << _n); ++i)
            _output(_codes[i]);
    };
public:
    GrayCode(int n) : _n(n)
    {
        _codes[0] = 0;
        myout.open("graycodeoutput.txt");
    };

    ~GrayCode() { myout.close(); };

    void generate(void)
    {
        _generate(_n);
        _outputAll();
    };
};

int main(void)
{
    int n;
    cout << "No. of bits (1 - 10)? "; cin >> n;
    if (n < 0 || n > 10)
        cerr << "[ERROR] Invalid no. of bits!" << endl;
    GrayCode gc(n);
    gc.generate();
    cout << "Done.\n";
    return 0;
}
///:~

/* 
SAMPLE OUTPUT
No. of bits? 5
Done.

RESULT WRITTEN TO FILE graycodeoutput.txt
0 0000 
0 0001 
0 0011 
0 0010 
0 0110 
0 0111 
0 0101 
0 0100 
0 1100 
0 1101 
0 1111 
0 1110 
0 1010 
0 1011 
0 1001 
0 1000 
1 1000 
1 1001 
1 1011 
1 1010 
1 1110 
1 1111 
1 1101 
1 1100 
1 0100 
1 0101 
1 0111 
1 0110 
1 0010 
1 0011 
1 0001 
1 0000 

*/
