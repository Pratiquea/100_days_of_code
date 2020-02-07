#include<string>
#include<iostream>


bool IsUnique(std::string &str)
{
	int str_len = str.length();
	if (str_len>256)
	{
		return false;
	}
	
	bool char_map[256] = {false};

	for(int i=0; i<str.length(); i++)
	{
	//	std::cout<<"char = "<<str[i]<<" int = "<<int(str[i])<<std::endl;
		
		if(char_map[str[i]])
		{
			return false;
		}

		char_map[str[i]] = true;
	}
	return true;
}



int main()
{
	std::string str = "abca";
	bool ans;
	ans = IsUnique(str);
	if(ans)
	{
	std::cout<<" String is unique"<<std::endl;
	}

	else
	{
		std::cout<<" String is NOT unique"<<std::endl;
	}
	return 0;
}
