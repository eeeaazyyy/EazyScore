#pragma once
#include <QMainWindow>
#include <QPushButton>
#include <QFrame>
#include <QVBoxLayout>
#include <QDebug>

class ESApp : public QMainWindow
{
public:
	ESApp(QWidget* parent = nullptr);
	~ESApp();

private:
	QPushButton* btnMain;
	QVBoxLayout* lay;
	void somethingVoid(int i, QString b);
};