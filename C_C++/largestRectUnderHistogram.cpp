// C++ program to find maximum rectangular area in 
// linear time 
#include <iostream> 
#include <stack> 
using namespace std; 

// The main function to find the maximum rectangular 
// area under given histogram with n bars 
int getMaxArea(int hist[], int n) 
{ 
	// Create an empty stack. The stack holds inde es 
	// of hist[] array. The bars stored in stack are 
	// always in increasing order of their heights. 
	stack<int> s; 

	int max_area = 0; // Initalize max_area 
	int tp; // To store top of stack 
	int area_with_top; // To store area with top bar 
					// as the smallest bar 

	// Run through all bars of given histogram 
	int i = 0; 
	while (i < n) 
	{ 
		// If this bar is higher than the bar on top 
		// stack, push it to stack 
		if (s.empty() || hist[s.top()] <= hist[i]) 
			s.push(i++); 

		// If this bar is lower than top of stack, 
		// then calculate area of rectangle with stack 
		// top as the smallest (or minimum height) bar. 
		// 'i' is 'right index' for the top and element 
		// before top in stack is 'left index' 
		else
		{
/*
 * Ex. hist[0] = 2, hist[2] = hist[3] = 6, hist[5] = 8
 * 
 *                     1
 *                +--+--+
 *                | 8| 8|         |   |
 *          +--+--|  |  |         |   |
 *       +--| 6| 6|  |  |         | 5 | <--- s.top 
 *       | 5|  |  |  |  |--+      | 4 |
 *       |  |  |  |  |  |.4|      | 3 |
 *    +--|  |  |  |  |  |..|      | 2 |   
 *    | 2|  |  |  |  |  |..|      | 1 |
 *    |  |  |  |  |  |  |..|      | 0 |
 * --------------------------     +---+
 *      0  1  2  3  4  5  6
 * 
 *
 *                  2  1
 *                +--+   
 *                | 8|xx          |   |
 *          +--+--|  |xx          |   |
 *       +--| 6| 6|  |xx          |   | 
 *       | 5|  |  |  |xx+--+      | 4 | <--- s.top
 *       |  |  |  |  |xx|.4|      | 3 |
 *    +--|  |  |  |  |xx|..|      | 2 |   
 *    | 2|  |  |  |  |xx|..|      | 1 |
 *    |  |  |  |  |  |xx|..|      | 0 |
 * --------------------------     +---+
 *      0  1  2  3  4  5  6
 * 
 *                  2  1
 *                       
 *               3 xx xx          |   |
 *          +--+--+xx xx          |   |
 *       +--| 6| 6|xx xx          |   | 
 *       | 5|  |  |xx xx+--+      |   |
 *       |  |  |  |xx xx|.4|      | 3 | <--- s.top
 *    +--|  |  |  |xx xx|..|      | 2 |   
 *    | 2|  |  |  |xx xx|..|      | 1 |
 *    |  |  |  |  |xx xx|..|      | 0 |
 * --------------------------     +---+
 *      0  1  2  3  4  5  6
 * 
 *                  2  1
 *                       
 *               3                |   |
 *          +--+                  |   |
 *       +--| 6|xx xx xx          |   | 
 *       | 5|  |xx xx xx+--+      |   |
 *       |  |  |xx xx xx|.4|      |   |
 *    +--|  |  |xx xx xx|..|      | 2 | <--- s.top   
 *    | 2|  |  |xx xx xx|..|      | 1 |
 *    |  |  |  |xx xx xx|..|      | 0 |
 * --------------------------     +---+
 *      0  1  2  3  4  5  6
 * 
 *                  2  1
 *                       
 *            4  3                |   |
 *                                |   |
 *       +--|xx xx xx xx          |   | 
 *       | 5|xx xx xx xx+--+      |   |
 *       |  |xx xx xx xx|.4|      |   |
 *    +--|  |xx xx xx xx|..|      |   |   
 *    | 2|  |xx xx xx xx|..|      | 1 | <--- s.top
 *    |  |  |xx xx xx xx|..|      | 0 |
 * --------------------------     +---+
 *      0  1  2  3  4  5  6
 * 
 *  Till i = 5, all indices will just get pushed to the stack since it satisfies
 *  (s.empty() || hist[s.top()] <= hist[i]). But with i = 6, this condition
 *  fails and we calculate note top (tp), pop it out and calcutkate the area
 *  with hist[tp] stack as smallest bar:
 *      area_with_top = hist[tp] * (i - s.top() - 1) = 8 * (6 - 4 - 1) = 8
 *  We continue to loop, keep poping out stack top and calculate the area
 *  hist[tp] as smallest bar (as shown above with xx xx shaded area)
 *  till (s.empty() || hist[s.top()] <= hist[i]) satisfies. 
 */
			tp = s.top(); // store the top index
			s.pop(); // pop the top 

			// Calculate the area with hist[tp]  
			// as smallest bar 
			area_with_top = hist[tp] * (s.empty() ? i : 
								i - s.top() - 1); 

			// update ma  area, if needed 
			if (max_area < area_with_top) 
				max_area = area_with_top; 
		}
	} 

	// Now pop the remaining bars from stack and calculate 
	// area with every popped bar as the smallest bar 
	while (s.empty() == false) 
	{ 
		tp = s.top(); 
		s.pop(); 
		area_with_top = hist[tp] * (s.empty() ? i : 
								i - s.top() - 1); 

		if (max_area < area_with_top) 
			max_area = area_with_top; 
	} 

	return max_area; 
} 

// Driver program to test above function 
int main() 
{ 
	int hist[] = {2, 1, 4, 5, 1, 3, 3}; 
	int n = sizeof(hist)/sizeof(hist[0]); 
	cout << "Maximum area is " << getMaxArea(hist, n); 
	return 0; 
}