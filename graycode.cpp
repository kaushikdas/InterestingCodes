#include <iostream>
#include <fstream>

using namespace std;

class GrayCode
{
    int _n;
    unsigned int _code;
    ofstream myout;

    void _printCode(void)
    {
        for (int i = _n - 1; i >= 0; --i) {
            myout << ((_code & (1 << i)) >> i);
            if (0 == i % 4) myout << " ";
        }
        myout << endl;
    };
    
    void _generate(int pos, bool setBit)
    {
        if (0 == pos) return;

        _generate(pos - 1, true);
        unsigned int mask = 1 << (pos - 1);
        _code = setBit ? (_code | mask) : (_code & ~mask);
        _printCode();
        _generate(pos - 1, false);
    };

public:
    GrayCode(int n) : _n(n),  _code(0) 
    { 
        myout.open("graycodeoutput.txt");
    };

    ~GrayCode() { myout.close(); };

    void generateAll(void)
    {
        _printCode();
        _generate(_n, true);
    };
};

int main()
{
    int n = 1;
    cout << "No. of bits? "; cin >> n;
    if (n > 0 && n < 32) {
        GrayCode gc(n);
        gc.generateAll();
        cout << "Done.\n";
    }
    else {
        cerr << "[ERROR] Invalid no. of bits entered!\n";
    }
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
