#include "pch.h"

#include "LLParser.h"
#include "TaskTable.h"

int main()
{
	TaskTable table;

	std::string str;
	std::getline(std::cin, str);
	str += '\n';
	std::istringstream iss(str);
	
	LLParser parser(iss, table);

	if (parser.Parse())
	{
		std::cout << "SUCCESS\n";

		return 0;
	}
	else
	{
		std::cout << "ERROR at " << parser.GetTapePosition() + 1 << " position\n";

		return 1;
	}
}
