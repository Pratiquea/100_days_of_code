#include <iostream>
#include <string>

bool permutation(std::string &str1, std::string &str2)
{
	if(str1.length() != str2.length())
	{
		std::cout<<"1st reject"<<std::endl;
		return false;
	}

	int char_map[256] = {0};
	for(int i=0; i<str1.length(); i++)
	{
		char_map[int(str1[i])]+=1;
	}
	
	
	for(int i=0; i<str2.length(); i++)
	{
		char_map[int(str2[i])]-=1;
		if (char_map[int(str2[i])]<0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	std::string a = "abcde";
	std::string b = "daebc";

	bool ans;
	ans = permutation(a,b);
	std::cout<<"is permutation "<<ans<<std::endl;
}
