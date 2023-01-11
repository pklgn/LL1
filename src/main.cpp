#include "pch.h"

#include "LLParser.h"

int main()
{
	Table table;
	table.AddRow(1, TableRow({ '-', '(', 'a', 'b', '8', '3' }, false, true, 2, false, false));
	table.AddRow(2, TableRow({ '-', '(', 'a', 'b', '8', '3' }, false, false, 5, true, false));
	table.AddRow(3, TableRow({}, false, false, 8, true, false));
	table.AddRow(4, TableRow({}, false, false, {}, false, true));
	table.AddRow(5, TableRow({ '-', '(', 'a', 'b', '8', '3' }, false, true, 6, false, false));
	table.AddRow(6, TableRow({ '-', '(', 'a', 'b', '8', '3' }, false, false, 16, true, false));
	table.AddRow(7, TableRow({}, false, false, 12, false, false));
	table.AddRow(8, TableRow({ '+' }, true, false, 9, false, false));
	table.AddRow(9, TableRow({}, false, false, {}, false, false));
	table.AddRow(10, TableRow({ '-', '(', 'a', 'b', '8', '3' }, false, false, 5, true, false));
	table.AddRow(11, TableRow({}, false, false, 8, false, false));
	table.AddRow(12, TableRow({ '*' }, true, false, 14, false, false));
	table.AddRow(13, TableRow({}, false, false, {}, false, false));
	table.AddRow(14, TableRow({ '-', '(', 'a', 'b', '8', '3' }, false, false, 16, true, false));
	table.AddRow(15, TableRow({}, false, false, 12, false, false));
	table.AddRow(16, TableRow({ '-' }, true, false, 16, false, false));
	table.AddRow(17, TableRow({ '(' }, true, false, 22, false, false));
	table.AddRow(18, TableRow({ 'a' }, true, false, {}, false, false));
	table.AddRow(19, TableRow({ 'b' }, true, false, {}, false, false));
	table.AddRow(20, TableRow({ '8' }, true, false, {}, false, false));
	table.AddRow(21, TableRow({ '3' }, true, true, {}, false, false));
	table.AddRow(22, TableRow({ '-', '(', 'a', 'b', '8', '3' }, false, false, 1, true, false));
	table.AddRow(23, TableRow({ ')' }, true, false, {}, false, false));

	LLParser parser(std::cin, table);

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
