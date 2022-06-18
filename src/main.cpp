#include "../headers/functions.h"

int main()
{
	chdir(getenv("HOMEPATH"));
	bool quit = false;
	while (!quit)
	{
		std::string s = get_string(current_dir().append("> "));
		std::string operation = get_operation(s);
		handle(operation, s);
	}
}
