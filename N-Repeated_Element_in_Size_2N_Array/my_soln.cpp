#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

class Solution 
{
	public:
	int repeatedNTimes(vector<int>& A) 
	{
		int a_size = A.size();
		int a,b;
		while(1)
		{		
			a = rand() % a_size;
			b = rand() % a_size;
			if(A.at(a) == A.at(b) && a!=b)
			{
				return A.at(a);
			}
		}
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
