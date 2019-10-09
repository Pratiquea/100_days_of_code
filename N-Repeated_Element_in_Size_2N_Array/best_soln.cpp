#include <iostream>
#include <stdlib.h>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution 
{
	public:
	int repeatedNTimes(vector<int>& A) 
	{
		unordered_set<int> m;
		// unordered set will have unique elements
		// if non unique element is inserted it will not
		// perform the insertion operation and return the
		// non unique value
		for (auto i:A) // works like python eg 'for each in list:'
		{

			if(m.count(i))
			{
				return i;	
			}
			m.insert(i);
		}
		return 0;
	}
};

int main()
{
	Solution sol;
	vector<int> A{1,2,8,3,8};
	int ans;
	ans = sol.repeatedNTimes(A);
	cout<< endl << "repeated element = " << ans << endl;
	return 0;	
}
