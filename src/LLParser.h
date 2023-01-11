#pragma once

#include <iostream>
#include <stack>

#include "Table.h"

class LLParser
{
public:
	LLParser(std::istream& input, const Table& table);

	bool Parse();

private:
	Table m_table;
	std::istream& m_input;
	std::stack<TableRowPtr> m_stack;
};
