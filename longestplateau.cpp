/**
 * LONGEST PLATEAU. Given an array of integers, compose a program that
 * finds the length and location of the longest contiguous sequence of
 * equal values where the values of the elements just before and just 
 * after this sequence are smaller.
 */

#include <iostream>
#include <chrono>
#include <random>
#include <cstdlib>

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
        delete [] m_a;
    };

    void Init(int sz)
    {
        m_sz = sz;
        delete [] m_a;
        m_a = new int[sz];
        
        // Populate the array a with some random numbers
        //   Use current time as seed for random generator
        unsigned seed = 
            std::chrono::system_clock::now().time_since_epoch().count();
        std::default_random_engine re{seed};
        std::uniform_int_distribution<int> dist{1,5};
        for (int i = 0; i < m_sz; ++i)
        {
            m_a[i] = dist(re);
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

int main(int argc, char *argv[])
{

    std::cout << "LONGEST PLATEAU PROBLEM";
    
    int trials = atoi(argv[1]);
    for (int i = 0; i < trials; ++i)
    {
        std::cout << "\nTrail " << (i + 1) << "\nData len? ";
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
}
///:~

/* 
>longestplateau.o 7
LONGEST PLATEAU PROBLEM
Trail 1
Data len? 37
Input array of size 37:
2 5 5 5 1 5 3 5 5 1 5 1 5 2 1 1 3 5 3 3 4 3 3 5 2 4 3 4 3 5 1 3 5 4 5 4 1
Longest Plateau (start index - length): 1 - 3

Trail 2
Data len? 61
Input array of size 61:
4 3 5 3 4 1 5 1 3 3 4 1 3 2 2 3 5 5 5 2 5 5 2 4 5 5 4 5 3 3 3 4 4 4 1 5 4 5 4 5 1 2 2 5 5 3 5 2 5 1 4 2 3 1 4 5 4 2 4 4 4
Longest Plateau (start index - length): 31 - 3

Trail 3
Data len? 10
Input array of size 10:
5 4 1 5 5 3 2 1 2 3
Longest Plateau (start index - length): 3 - 2

Trail 4
Data len? 1
Input array of size 1:
3
Input data has no plataeu!

Trail 5
Data len? 2
Input array of size 2:
1 3
Input data has no plataeu!

Trail 6
Data len? 3
Input array of size 3:
2 1 5
Input data has no plataeu!

Trail 7
Data len? 29
Input array of size 29:
1 3 1 3 3 3 5 2 2 3 1 2 4 5 3 1 4 1 4 5 3 5 5 3 3 3 4 4 5
Longest Plateau (start index - length): 21 - 2

*/
