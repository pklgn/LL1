#include "LLParser.h"

LLParser::LLParser(std::istream& input, const Table& table)
	: m_input(input)
	, m_table(table)
{
}

bool LLParser::Parse()
{
	TableRowPtr currentRowPtr = 1;
	TableRow& currentRow = m_table.GetRow(currentRowPtr);

	while (!currentRow.IsEnd())
	{
		if (!currentRow.DirectionalSymbolMatched(m_input.peek()))
		{
			if (currentRow.IsError())
				return false;
			else
				currentRow = m_table.GetRow(++currentRowPtr);
		}
		else
		{
			if (currentRow.ShouldShift())
				m_input.get();

			if (currentRow.ShouldSaveNextRowAddressInStack())
				m_stack.push(currentRowPtr + 1);

			auto rowPtr = currentRow.GetPointer();
			if (rowPtr)
			{
				currentRow = m_table.GetRow(*rowPtr);
			}
			else if (!m_stack.empty())
			{
				currentRow = m_table.GetRow(m_stack.top());
				m_stack.pop();
			}
			else
			{
				return false;
			}
		}
	}
	return true;
}
