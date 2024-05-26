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
	QWidget*		widNameIconLeague; // ������ ������ ���������� � ��� ��������
	QFrame*			mainFrame;		// ������� Frame ��� �������������� �����
	QVBoxLayout*	layVertMain; // Parent layout
	QTableView*		ESTW_TableView; // �������� �������
private:
	QWidget* widgetIconLeague(); // C������ � ����������� ������ ��� ����������� ������� � �������� ���������� ����.

	void setViewModeESTW();
	void setLabelStyleNameLeague(QLabel* labelNameLeague = nullptr); // �������� ����� ��� �������� �������
	void setLabelStyleIconLeague(QLabel* labelIconLeague = nullptr); // �������� ����� ��� ����������� ������ ����������

	void fillForm(); //�������� � ���������� ����������� ����� ��������� ������� �������.
	void fillFrame(); // �������� � �������������� ����� mainFrame 
	void initListViewModel(void); // �������� � ��������� ��������� ������� ESTW_TableView
};