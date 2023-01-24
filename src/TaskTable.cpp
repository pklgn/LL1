#include "TaskTable.h"

TaskTable::TaskTable()
{
	AddRow(1, TableRow({ '-', '(', 'a', 'b', '8', '3' }, false, true, 2, false, false));
	AddRow(2, TableRow({ '-', '(', 'a', 'b', '8', '3' }, false, false, 5, true, false));
	AddRow(3, TableRow({}, false, false, 8, true, false));
	AddRow(4, TableRow({}, false, false, {}, false, true));
	AddRow(5, TableRow({ '-', '(', 'a', 'b', '8', '3' }, false, true, 6, false, false));
	AddRow(6, TableRow({ '-', '(', 'a', 'b', '8', '3' }, false, false, 20, true, false));
	AddRow(7, TableRow({}, false, false, 14, false, false));
	AddRow(8, TableRow({ '+' }, true, false, 12, false, false));
	AddRow(9, TableRow({ '*' }, true, false, 18, false, false));
	AddRow(10, TableRow({ ')' }, true, false, {}, false, false));
	AddRow(11, TableRow({ '\n' }, true, true, 4, false, false));
	AddRow(12, TableRow({ '-', '(', 'a', 'b', '8', '3' }, false, false, 5, true, false));
	AddRow(13, TableRow({}, false, false, 8, false, false));
	AddRow(14, TableRow({ '*' }, true, false, 18, false, false));
	AddRow(15, TableRow({ '+' }, true, false, 12, false, false));
	AddRow(16, TableRow({ ')' }, true, false, {}, false, false));
	AddRow(17, TableRow({ '\n' }, true, true, 4, false, false));
	AddRow(18, TableRow({ '-', '(', 'a', 'b', '8', '3' }, false, true, 20, true, false));
	AddRow(19, TableRow({}, false, false, 14, false, false));
	AddRow(20, TableRow({ '-' }, true, false, 20, false, false));
	AddRow(21, TableRow({ '(' }, true, false, 26, false, false));
	AddRow(22, TableRow({ 'a' }, true, false, {}, false, false));
	AddRow(23, TableRow({ 'b' }, true, false, {}, false, false));
	AddRow(24, TableRow({ '8' }, true, false, {}, false, false));
	AddRow(25, TableRow({ '3' }, true, true, {}, false, false));
	AddRow(26, TableRow({ '-', '(', 'a', 'b', '8', '3' }, false, false, 1, true, false));
	AddRow(27, TableRow({ ')' }, true, true, {}, false, false));
}
