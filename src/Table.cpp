#include <ios>
#include <iostream>
#include "Table.h"

void Table::AddRow(TableRowPtr ptr, const TableRow& row)
{
	m_rows.insert({ ptr, row });
}

TableRow& Table::GetRow(TableRowPtr rowPtr)
{
	// at выбросит нужное исключение, можно без if'а
	return m_rows.at(rowPtr);
}

void Table::PrintRow(TableRowPtr rowPtr)
{
	if (rowPtr == 1)
	{
		std::cout << "\t" << "Row  "
				  << "\t" << "Shift"
				  << "\t" << "Error"
				  << "\t" << "Stack"
				  << "\t" << "End  " << '\n';
	}
	auto row = m_rows.at(rowPtr);
	std::cout << "\t" << rowPtr
			  << std::boolalpha
			  << "\t" << row.ShouldShift()
			  << "\t" << row.IsError()
			  << "\t" << row.ShouldSaveNextRowAddressInStack()
			  << "\t" << row.IsEnd() << '\n'
			  << std::noboolalpha;
}
