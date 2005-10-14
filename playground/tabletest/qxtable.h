#include <qtable.h>
#include <qtextedit.h>

class QxTable: public QTable
{
	Q_OBJECT
public:
	QxTable(QWidget* parent = 0, const char* name = 0);
	QWidget* createEditor(int row, int col, bool initFromCell) const;
	void setCellContentFromEditor(int row, int col);
private:
	mutable QTextEdit* _editor;
};
