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
	QWidget*		widNameIconLeague; // виджет иконки чемпионата и его название
	QFrame*			mainFrame;		// Главный Frame для редактирования стиля
	QVBoxLayout*	layVertMain; // Parent layout
	QTableView*		ESTW_TableView; // Трнирная таблица
private:
	QWidget* widgetIconLeague(); // Cоздает и настраивает виджет для отображения эмблемы и названия футбольной лиги.

	void setViewModeESTW();
	void setLabelStyleNameLeague(QLabel* labelNameLeague = nullptr); // Создание стиля для название турнира
	void setLabelStyleIconLeague(QLabel* labelIconLeague = nullptr); // Создание стиля для отображения иконки чемпионата

	void fillForm(); //Создание и заполнение графической формы турнирной таблицы виджета.
	void fillFrame(); // Создание и редактирование стиля mainFrame 
	void initListViewModel(void); // Создание и настройка турнирной таблицы ESTW_TableView
};