#include <climits>
#include <iostream>
#include <iomanip>
#include <limits>

int lc_longest_substr_wo_repeated_chars_main();

#define COUT(x) (std::cout << "\nstd::numeric_limits<" << #x << ">" \
                           << std::setw(12) \
                           << std::numeric_limits<x>::max() << std::endl)

int main()
{
	std::cout << std::setw(14) << INT_MAX << std::endl;
	COUT(unsigned long);
	// return lc_longest_substr_wo_repeated_chars_main();
	auto constexpr imin = std::numeric_limits<int>::min();
	std::cout << imin << std::endl;
}