#include "TaskTable.h"

TaskTable::TaskTable()
{
	AddRow(1, TableRow({ '-', '(', 'a', 'b', '8', '3' }, false, true, 2, false, false));
	AddRow(2, TableRow({ '-', '(', 'a', 'b', '8', '3' }, false, false, 5, true, false));
	AddRow(3, TableRow({}, false, false, 8, true, false));
	AddRow(4, TableRow({}, false, false, {}, false, true));
	AddRow(5, TableRow({ '-', '(', 'a', 'b', '8', '3' }, false, true, 6, false, false));
	AddRow(6, TableRow({ '-', '(', 'a', 'b', '8', '3' }, false, false, 17, true, false));
	AddRow(7, TableRow({}, false, false, 12, false, false));
	AddRow(8, TableRow({ '+' }, true, false, 10, false, false));
	AddRow(9, TableRow({ '\n', ')'}, false, true, {}, false, false));
	AddRow(10, TableRow({ '-', '(', 'a', 'b', '8', '3' }, false, false, 5, true, false));
	AddRow(11, TableRow({}, false, false, 8, false, false));
	AddRow(12, TableRow({ '*' }, true, false, 15, false, false));
	AddRow(13, TableRow({ '+' }, true, false, 10, false, false));
	AddRow(14, TableRow({ '\n', ')'}, false, true, {}, false, false));
	AddRow(15, TableRow({ '-', '(', 'a', 'b', '8', '3' }, false, true, 17, true, false));
	AddRow(16, TableRow({}, false, false, 12, false, false));
	AddRow(17, TableRow({ '-' }, true, false, 17, false, false));
	AddRow(18, TableRow({ '(' }, true, false, 23, false, false));
	AddRow(19, TableRow({ 'a' }, true, false, {}, false, false));
	AddRow(20, TableRow({ 'b' }, true, false, {}, false, false));
	AddRow(21, TableRow({ '8' }, true, false, {}, false, false));
	AddRow(22, TableRow({ '3' }, true, true, {}, false, false));
	AddRow(23, TableRow({ '-', '(', 'a', 'b', '8', '3' }, false, true, 1, true, false));
	AddRow(24, TableRow({ ')' }, true, true, {}, false, false));
}
