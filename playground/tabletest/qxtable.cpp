#include "qxtable.h"

QxTable::QxTable(QWidget* parent, const char* name)
	: QTable(5, 5, parent, name)
{
}

QWidget* QxTable::createEditor(int row, int col, bool initFromCell) const
{
	_editor = new QTextEdit(const_cast<QxTable*>(this));
	_editor->setText(initFromCell ? text(row, col) : "");
	return _editor;
}

void QxTable::setCellContentFromEditor(int row, int col)
{
	setText(row, col, _editor->text());
}
