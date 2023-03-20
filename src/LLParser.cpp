#include "LLParser.h"
#include "common.h"

LLParser::LLParser(std::istream& input, const Table& table)
	: m_input(input)
	, m_table(table)
{
}

bool LLParser::Parse()
{
	TableRowPtr currentRowPtr = 1;
	// FIXED: убрать ссылку, каким-то образом меняется значение строки, из-за этого цикл бесконечный для -(8)
	TableRow currentRow = m_table.GetRow(currentRowPtr);
	char currCh = ' ';
	while (!currentRow.IsEnd() || !m_stack.empty())
	{
		if constexpr (LL1_DEBUG)
		{
			m_table.PrintRow(currentRowPtr);
		}
		currCh = m_input.peek();
		if (!currentRow.DirectionalSymbolMatched(currCh))
		{
			if (currentRow.IsError())
				return false;
			else
				currentRow = m_table.GetRow(++currentRowPtr);
		}
		else
		{
			if (currentRow.ShouldShift())
			{
				++m_tapePosition;
				if constexpr (LL1_DEBUG)
				{
					std::cout << char(m_input.get()) << std::endl;
				}
			}

			if (currentRow.ShouldSaveNextRowAddressInStack())
			{
				m_stack.push(currentRowPtr + 1);
				if constexpr (LL1_DEBUG)
				{
					std::cout << "Push " << currentRowPtr + 1 << '\n';
				}
			}

			auto rowPtr = currentRow.GetPointer();
			if (rowPtr)
			{
				currentRow = m_table.GetRow(currentRowPtr = *rowPtr);
			}
			else if (!m_stack.empty())
			{
				currentRowPtr = m_stack.top();
				currentRow = m_table.GetRow(currentRowPtr);
				m_stack.pop();
				if constexpr (LL1_DEBUG)
				{
					std::cout << "Pop  " << currentRowPtr << '\n';
				}
			}
			else
			{
				return false;
			}
		}
	}

	return currCh == '\n';
}

size_t LLParser::GetTapePosition() const
{
	return m_tapePosition;
}
