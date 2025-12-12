#include <iostream>
#include <string>
#include <vector>

using namespace std;

int print_type_main() {
	// your code goes here
	const string hw = "hello world";
	vector<vector<int>> ivec;
	vector<string> svec;
	vector<string> svec1(10, "null");	

	for (auto& c : hw)
	{
		cout << typeid(c).name() << endl;
	}
	return 0;
}
