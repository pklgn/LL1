#include "pch.h"

#include "LLParser.h"
#include "TaskTable.h"

int main()
{
	TaskTable table;

	std::string str;
	std::getline(std::cin, str);
	std::istringstream iss(str);

	LLParser parser(iss, table);

	if (parser.Parse())
	{
		std::cout << "SUCCESS" << std::endl;

		return 0;
	}
	else
	{
		std::cout << "ERROR" << std::endl;

		return 1;
	}
}
