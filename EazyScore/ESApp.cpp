#include "ESApp.h"
#include <QFile>
#include "ESTableWidget.h"


ESApp::ESApp(QWidget* parent) : QMainWindow(parent)
{

	resize(500, 500);
	/*QWidget* wid = new QWidget(this);
	lay = new QVBoxLayout(wid);
	btnMain = new QPushButton("Press me", wid);*/

	QFile styleFile(":/resource/style.qss");
	if (!styleFile.open(QIODevice::ReadOnly)) {
		qWarning() << "STYLE SHEET DONT OPEN!";
		return;

	}
		

	QTextStream textStream(&styleFile);
	QString styleSheet = textStream.readAll();

	QWidget* wid = new QWidget(this);
	QGridLayout* lay = new QGridLayout(wid);


	ESTableWidget* esTable = new ESTableWidget(this);
	esTable->setStyleSheet(styleSheet);

	QWidget* wid2 = new QWidget(wid);
	wid2->setMinimumSize(200, 200);
	//wid2->resize(200, 200);

	lay->addWidget(wid2, 0, 0);
	lay->addWidget(esTable, 1, 1);
	//btnMain->setStyleSheet(styleSheet);
	//QIcon icon(":/resource/img/stadium.png");
	//btnMain->setStyleSheet("border-image:url(:/resource/img/stadium.png);");
	//btnMain->setIcon(icon);

	/*lay->addWidget(btnMain);
	wid->setLayout(lay);*/
	this->setCentralWidget(wid);
}

ESApp::~ESApp()
{

}

void ESApp::somethingVoid(int i, QString b)
{
	qDebug() << i + 2;
}
