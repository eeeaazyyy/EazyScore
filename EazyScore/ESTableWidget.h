#pragma once
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QListView>
#include <QTableView>

class ESTableWidget : public QWidget
{
	Q_OBJECT
public:

	ESTableWidget(QWidget* parent = nullptr);
	~ESTableWidget();

private:
	QVBoxLayout* layWidget; // parent layout
	QTableView* listViewTable;
private:
	void initListViewModel(void);
};