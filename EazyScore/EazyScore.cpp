// EazyScore.cpp: определяет точку входа для приложения.
//

#include <QApplication>
#include <iostream>
#include "ESApp.h"


using namespace std;

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	ESApp EApp;
	EApp.show();
	return app.exec();
}
