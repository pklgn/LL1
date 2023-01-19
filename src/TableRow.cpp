#include "TableRow.h"

TableRow::TableRow(const std::unordered_set<unsigned char>& directionalSymbol, bool shift, bool error, std::optional<TableRowPtr> pointer, bool ssnrais, bool end)
	: m_directionalSymbol(directionalSymbol)
	, m_shift(shift)
	, m_error(error)
	, m_pointer(pointer)
	, m_shouldSaveNextRowAddressInStack(ssnrais)
	, m_end(end)
{
}

bool TableRow::DirectionalSymbolMatched(unsigned char symb) const
{
	return m_directionalSymbol.empty() || m_directionalSymbol.find(symb) != m_directionalSymbol.end();
}

bool TableRow::ShouldShift() const
{
	return m_shift;
}

bool TableRow::IsError() const
{
	return m_error;
}

std::optional<TableRowPtr> TableRow::GetPointer() const
{
	return m_pointer;
}

bool TableRow::ShouldSaveNextRowAddressInStack() const
{
	return m_shouldSaveNextRowAddressInStack;
}

bool TableRow::IsEnd() const
{
	return m_end;
}
