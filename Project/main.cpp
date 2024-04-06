#include <iostream>
#include <string>

std::string Reverse(const std::string& str)
{
	if (str.length() == 0)
	{
		return "";
	}
	else
	{
		return Reverse(str.substr(1)) + str[0];
	}
}

int main()
{
	std::cout << Reverse("Hello") << std::endl;

	return 0;
}