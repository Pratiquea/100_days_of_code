#include <iostream>
#include <string>

std::string ReplaceWhitespace(std::string &gen_str, int len)
{
	std::string new_str;
	std::cout<<" init string = "<<new_str<<std::endl;
	for(int i=0; i<len; i++)
	{
		if(gen_str[i]==' ')
		{
			new_str+="%20";
		}
		else
		{
			 new_str+=gen_str[i];
		}

	}

	return new_str;
}

int main()
{
	std::string str = "my name is iwabe";
	std::string ans;
	int str_len = str.length();
	str = str+"         ";
	std::cout<<"input string = "<<str<<std::endl;
	ans = ReplaceWhitespace(str,str_len);
	std::cout<<"output string = "<<ans<<std::endl;
}
