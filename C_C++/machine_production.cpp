#include <set>
#include <map>
#include <iostream>

using namespace std;

int n;
set<pair<int, int>> st;
map<int, int> mp;

void init(int N, int mId[], int mTime[])
{
    n = N;
    mp.clear();
    st.clear();
    
    for (int i = 0; i < N; i++) {
        st.insert({mTime[i], mId[i]});
        mp[mId[i]] = mTime[i];
    }
}

int add(int mId, int mTime)
{
	if (mp.count(mId) != 0) {
	    // existing machine
	    st.erase({mp[mId], mId});
	}
	st.insert({mTime, mId});
	mp[mId] = mTime;
	
	return (int)st.size();
}

int remove(int k)
{
	while (k--) {
		auto pi = *st.rbegin();
		st.erase(pi);
		mp.erase(pi.second);
	}
	
	return st.rbegin()->second;
}
