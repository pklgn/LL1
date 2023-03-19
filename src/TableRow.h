#pragma once

#include <unordered_set>
#include <memory>
#include <optional>

using TableRowPtr = size_t;

class TableRow
{
public:
	TableRow(const std::unordered_set<unsigned char>& m_directionalSymbol, bool shift, bool error, std::optional<TableRowPtr> pointer, bool ssnrais, bool end);

	bool DirectionalSymbolMatched(unsigned char symb) const;
	bool ShouldShift() const;
	bool IsError() const;
	std::optional<TableRowPtr> GetPointer() const;
	bool ShouldSaveNextRowAddressInStack() const;
	bool IsEnd() const;

private:
	std::unordered_set<unsigned char> m_directionalSymbol;
	bool m_shift;
	bool m_error;
	std::optional<TableRowPtr> m_pointer;
	bool m_shouldSaveNextRowAddressInStack;
	bool m_end;
};
