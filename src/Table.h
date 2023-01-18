#pragma once

#include <unordered_map>

#include "TableRow.h"

class Table
{
public:
	void AddRow(TableRowPtr ptr, const TableRow& row);

	TableRow& GetRow(TableRowPtr rowPtr);

	void PrintRow(TableRowPtr);

private:
	std::unordered_map<TableRowPtr, TableRow> m_rows;
};
