/**
 * LONGEST PLATEAU. Given an array of integers, compose a program that
 * finds the length and location of the longest contiguous sequence of
 * equal values where the values of the elements just before and just 
 * after this sequence are smaller.
 */

#include <cstdlib>
#include <iostream>
#include <ctime>

class LongestPlateau
{
  private:
    int *m_a;    // Array of input data
    int m_sz;    // Size of input data
    int m_start; // Start index of longest plateau
                 //   If at least one plateau present
                 //   0 < m_start < (m_sz - 1)
    int m_len;   // Length of the longest plateau

    void __FindLongestPlateau();

  public:
    ~LongestPlateau()
    {
        if (m_a)
            delete[] m_a;
    };

    void Init(int sz)
    {
        m_sz = sz;
        if (m_a)
            delete m_a;
        m_a = new int[sz];

        // Populate the array a with some random numbers
        //   Use current time as seed for random generator
        std::srand(std::time(0));
        for (int i = 0; i < m_sz; ++i)
        {
            m_a[i] = std::rand() % 5;
        }

        m_start = 0;
        m_len = 0;
    }

    void PrintResult()
    {
        std::cout << "Input array of size " << m_sz << ":" << std::endl;
        for (int i = 0; i < m_sz; ++i)
        {
            std::cout << m_a[i] << " ";
        }
        __FindLongestPlateau();
        if (m_len > 0)
        {
            std::cout << "\nLongest Plateau (start index - length): "
                      << m_start << " - " << m_len << std::endl;
        }
        else
        {
            std::cout << "\nInput data has no plataeu!\n";
        }
    }
};

/**
 * In case of multiple plateaus of longest length, index of the
 * rightmost plateau is considered
 */
void LongestPlateau::__FindLongestPlateau()
{
    if (m_sz > 0)
    {
        m_start = 0;
        m_len = 0;
        int currentPlateauStart = 0, currentPlateauLen = 0;
        // **** A plateau cannot start at 0 ****
        for (int i = 1; i < m_sz; ++i)
        {
            if ((m_a[i] == m_a[i - 1]) && (currentPlateauLen > 0))
            {
                // Continue current plateau...
                //   (2nd cond ensures that we are inside a plateau)
                currentPlateauLen += 1;
            }
            else if (m_a[i] > m_a[i - 1])
            {
                // Start of a plateau...
                currentPlateauStart = i;
                currentPlateauLen = 1;
            }
            else if ((m_a[i] < m_a[i - 1]) && (currentPlateauLen > 0))
            {
                // ...end of current plateau
                if (currentPlateauLen >= m_len)
                {
                    // Equality ensures that we always consider
                    //   the right plateau
                    m_len = currentPlateauLen;
                    m_start = currentPlateauStart;
                }
                // Reset search
                currentPlateauStart = 0, currentPlateauLen = 0;
            }
        }
    }
}

int main()
{

    std::cout << "LONGEST PLATEAU PROBLEM\n";
    std::cout << "Data len? ";
    int len = 0;
    std::cin >> len;
    if (len > 0)
    {
        LongestPlateau lp;
        lp.Init(len);
        lp.PrintResult();
    }
    else
    {
        std::cerr << "Invalid input length!\n";
    }
}
///:~

/* 
SAMPLE OUTPUT
LONGEST PLATEAU PROBLEM
Data len? 47
Input array of size 47:
2 3 3 0 3 4 4 4 4 1 0 2 1 4 1 3 3 0 4 1 2 0 3 3 1 0 3 4 1 0 4 2 1 1 2 0 4 1 2 0 3 4 0 1 4 4 3
Longest Plateau (start index - length): 5 - 4
*/
