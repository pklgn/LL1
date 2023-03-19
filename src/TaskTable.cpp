#include "TaskTable.h"

TaskTable::TaskTable()
{
	AddRow(1, TableRow({ '-', '(', 'a', 'b', '8', '3' }, false, true, 2, false, false));
	AddRow(2, TableRow({ '-', '(', 'a', 'b', '8', '3' }, false, false, 5, true, false));
	AddRow(3, TableRow({}, false, false, 8, true, false));
	AddRow(4, TableRow({}, false, false, {}, false, true));
	AddRow(5, TableRow({ '-', '(', 'a', 'b', '8', '3' }, false, true, 6, false, false));
	AddRow(6, TableRow({ '-', '(', 'a', 'b', '8', '3' }, false, false, 16, true, false));
	AddRow(7, TableRow({}, false, false, 12, false, false));
	AddRow(8, TableRow({ '+' }, true, false, 10, false, false));
	AddRow(9, TableRow({}, false, false, {}, false, false));
	AddRow(10, TableRow({ '-', '(', 'a', 'b', '8', '3' }, false, false, 5, true, false));
	AddRow(11, TableRow({}, false, false, 8, false, false));
	AddRow(12, TableRow({ '*' }, true, false, 14, false, false));
	AddRow(13, TableRow({}, false, false, {}, false, false));
	AddRow(14, TableRow({ '-', '(', 'a', 'b', '8', '3' }, false, true, 16, true, false));
	AddRow(15, TableRow({}, false, false, 12, false, false));
	AddRow(16, TableRow({ '-' }, true, false, 16, false, false));
	AddRow(17, TableRow({ '(' }, true, false, 22, false, false));
	AddRow(18, TableRow({ 'a' }, true, false, {}, false, false));
	AddRow(19, TableRow({ 'b' }, true, false, {}, false, false));
	AddRow(20, TableRow({ '8' }, true, false, {}, false, false));
	AddRow(21, TableRow({ '3' }, true, true, {}, false, false));
	AddRow(22, TableRow({ '-', '(', 'a', 'b', '8', '3' }, false, false, 1, true, false));
	AddRow(23, TableRow({ ')' }, true, true, {}, false, false));
}
