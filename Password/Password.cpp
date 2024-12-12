#include <iostream>

struct Password
{
	char value[16];
	bool incorrect;
	Password() : value(""), incorrect(true)
	{
	}
};

int main()
{
	std::cout << "Enter your password to continue:" << std::endl;
	Password pwd;
	// Password: any 16 chars long password, example: "aaaaaaaaaaaaaaaa"
	// The reason - buffer overfllow.
	// Cin enters the 16 chars into the value[16] array, and than put a 0 (end of string) in the next byte - this is the byte of incorrect variable
	// So after entering 16 chars the cin put a 0 (false) in the incorrect value, and it runs as we entered the password
	std::cin >> pwd.value;

	if (!strcmp(pwd.value, "********"))
		pwd.incorrect = false;

	if(!pwd.incorrect)
		std::cout << "Congratulations\n";

	return 0;
}
