#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
//using namespace std;
class Solution
{
	public:
	bool repeatNtimes(char* list)
	{
		int len_list = sizeof(list)/sizeof(list[0]);
		//std::cout<<"length of list = "<<len_list<<std::endl;
		//std::cout<<" arr = "<< list<<std::endl;
		//std::cout<<" size and size[0]= "<<sizeof(list)<<" & "<<sizeof(list[0])<<std::endl;
		//std::cout<<" zeroth element= "<<list[0]<<std::endl;
		for(int k=0; k< len_list; k++)
		{
			//std::cout<<"ith element = "<<list[k]<<std::endl;
		}
		for(int i=0; i<len_list; i++)
		{
			for(int j=i+1; j<len_list; j++)
			{
				if((list[i] == list[j]) && list[i]!=0)
					return 1;
			}
		}
			 
		return 0;
			  
	}
/*	
	char* create_new_array(char* in_list, int size_of_in_list)
	{
		int size_of_out_list = 2*size_of_in_list;
		char out_list[size_of_out_list];

		for(int i=0 ; i<size_of_in_list ; i++)
		{
			out_list[i] = &in_list[i];
		}

		return out_list;
	}

*/
};  

int main()
{
	Solution sol;
	bool ans;
	char a[] = {'a','b','s','e','w','a','a'};
	//char a[5] = {'a','b','s','e','w'};
	ans = sol.repeatNtimes(a);
	std::cout<<"ans = "<<ans<<std::endl;
	return 0;
}
