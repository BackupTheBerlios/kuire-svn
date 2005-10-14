#include <qapplication.h>
#include "qxtable.h"

int main(int argc, char** argv)
{
	QApplication* qApp = new QApplication(argc, argv);
	QxTable* tab = new QxTable;
	tab->show();
	qApp->setMainWidget(tab);
	int ret = qApp->exec();
	delete tab;
	delete qApp;
	return ret;
}
