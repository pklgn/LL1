#include "Table.h"

void Table::AddRow(TableRowPtr ptr, const TableRow& row)
{
	m_rows.insert({ ptr, row });
}

TableRow& Table::GetRow(TableRowPtr rowPtr)
{
	if (m_rows.find(rowPtr) != m_rows.end())
		return m_rows.at(rowPtr);
	else
		throw std::exception();
}
