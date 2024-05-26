/**
 * @file establewidget.h
 * @brief ����� ESTableWidget ������������� ������ ��� ����������� � ���������� ����������� � ���������� ����.
 *
 * ���� ����� ��������� ���������� ��������� �������, ������� � �������� ����, � ����� ������������� ����������� ��� �������������� ����� � �����������.
 *
 * @author Vladislav Trifonov https://github.com/milkivei7
 * @date 26.05.2024
 */


#include "ESTableWidget.h"
#include <QStandardItem>
#include <QStandardItemModel>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QFrame>
#include <QHeaderView>

ESTableWidget::ESTableWidget(QWidget* parent) : QWidget(parent)
{
	ESTW_TableView		= nullptr;
	mainFrame			= nullptr;
	widNameIconLeague	= nullptr;
	layVertMain			= nullptr;
	
	setViewModeESTW();
	fillForm();
}

ESTableWidget::~ESTableWidget()
{

}

/**
 * ������� widgetIconLeague() ������� � ����������� ������ ��� ����������� ������� � �������� ���������� ����.
 */
QWidget* ESTableWidget::widgetIconLeague()
{
	QWidget* widIconLeague = new QWidget(this);

	widIconLeague->setMaximumHeight(50);
	widIconLeague->setStyleSheet(
		"QWidget{"
		"margin: 0px;"
		"background: transparent;"
		"border-image: transparent;"
		"padding: 0px;"
		"} "
	);

	
	QLabel* labelIconLeague = new QLabel(widIconLeague);
	labelIconLeague->setMinimumSize(45, 45);
	setLabelStyleIconLeague(labelIconLeague);


	QLabel* labelNameLeague = new QLabel("Table", widIconLeague);
	labelNameLeague->setMinimumSize(45, 45);
	setLabelStyleNameLeague(labelNameLeague);

	QHBoxLayout* LayWidIconLeag = new QHBoxLayout(widIconLeague);
	LayWidIconLeag->setAlignment(Qt::AlignLeft);
	
	LayWidIconLeag->addWidget(labelNameLeague);
	LayWidIconLeag->addWidget(labelIconLeague);

	widIconLeague->setLayout(LayWidIconLeag);


	return widIconLeague;
}



/*
 * ������� setViewModeESTW() ������������� ������������� ��������� ��� ������� ESTableWidget
 *
 * 1. ������������� ������������ ������ ������� �� 232 �������.
 * 2. �������� ������ ���� �� "hand" ��� ��������� �� ������, �������� �� ���������������.
 * 3. ��������� ����� QSS ��� ��������� �������� ���� �������:
 *     - ������� ���������� ������� (margin � padding).
 *     - ��� ��������� ���� ������ ��� ������� �� ��������������.
 * 4. ������������� ������ �������� ������� ����� �������, ��� ����������� ������ ����� ������ �����������,
 *    � ������ ����� ����������� ������ � ����������.
 */
void ESTableWidget::setViewModeESTW()
{
	setMaximumHeight(232);
	setCursor(Qt::PointingHandCursor);
	setStyleSheet(
		"QWidget{"
		"margin:0px;"
		"padding:0px;"
		"} "
		"QWidget::hover{"
		"background-color: rgba(105,105,105, 0.30);"
		"} "
	);
	setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
}



/**
 * ������� setLabelStyleNameLeague(QLabel* labelNameLeague) ��������� ����� QSS � ����������� QLabel,
 * ���������������� ��� ����������� �������� ���������� ����.
 */
void ESTableWidget::setLabelStyleNameLeague(QLabel* labelNameLeague)
{

	labelNameLeague->setStyleSheet(
		"QLabel{"
		"border-image: transparent;"
		"background: transparent;"
		"max-width: 100px;"
		"height: 40px;"
		"font-size: 20pt;"
		"font-weight: bold;"
		"border: none;"
		"border-radius:0px;"
		"} "
	);
}





/**
 * ������� setLabelStyleIconLeague(QLabel* labelIconLeague) ��������� ����� QSS � ����������� QLabel,
 * ���������������� ��� ����������� ������ ����������.
 */
void ESTableWidget::setLabelStyleIconLeague(QLabel* labelIconLeague)
{
	QIcon   rmIcon(":/resource/img/realMadridIcon.png");
	QPixmap pxmLeague(
		 rmIcon.pixmap(
			35, 35, 
			QIcon::Mode::Normal,
			QIcon::State::On
		)
	);

	labelIconLeague->setPixmap(pxmLeague);
	labelIconLeague->setAlignment(Qt::AlignVCenter);

	labelIconLeague->setStyleSheet(
		"QLabel{"
		"padding: 1px;"
		"border-image: transparent;"
		"background: transparent;"
		"max-width: 50px;"
		"height: 45px;"
		"font-size: 20pt;"
		"font-weight: bold;"
		"border: none;"
		"border-radius:10px;"
		"} "
	);
}


/**
 * ������� fillForm() ��������� �������� ������ ESTableWidget ������� � �����������, ������������ ��� �����������
 * ���������� � ���������� ���� � �� ��������� �������.
 */
void ESTableWidget::fillForm()
{
	initListViewModel();
	widNameIconLeague = widgetIconLeague();
	fillFrame();
	layVertMain = new QVBoxLayout(this);
	layVertMain->addWidget(mainFrame);
	this->setLayout(layVertMain);
}

void ESTableWidget::fillFrame()
{
	if (mainFrame != nullptr)
		return;

	mainFrame = new QFrame(this);


	QGridLayout* mainLayout = new QGridLayout(mainFrame);
	mainLayout->setSpacing(0);
	mainLayout->addWidget(widNameIconLeague, 0, 0);
	mainLayout->addWidget(ESTW_TableView, 1, 0);

	mainFrame->setLayout(mainLayout);
	mainFrame->setStyleSheet(
		"QFrame{"
		"background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0.04 rgba(139,55,169,0),"
		"stop : 0.4 rgba(139,55,169,30), stop : 1 rgba(50,73,158,90));"
		"} "

		"QFrame::hover{"
		"background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0.04 rgba(139,55,169,0),"
		"stop : 0.4 rgba(139,55,169,10), stop : 1 rgba(50,73,158,60));"
		"} "
	);
	/*QVBoxLayout* vbox = new QVBoxLayout(this);
	vbox->addWidget(mainFrame);*/
}


/**
 * ������� initListViewModel(void) �������������� � ����������� ������ ������������� ��� QTableView, ������������ � ESTableWidget,
 * ��������������� ��� ����������� ������ � ���������� �������� � �� ����������.
 */
void ESTableWidget::initListViewModel(void)
{
	if (ESTW_TableView != nullptr)
		return;
	ESTW_TableView = new QTableView(this);
	ESTW_TableView->setMinimumHeight(250);
	ESTW_TableView->setAttribute(Qt::WA_TransparentForMouseEvents);
	ESTW_TableView->setIconSize(QSize(28, 28));
	ESTW_TableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	ESTW_TableView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
	ESTW_TableView->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Expanding);
	ESTW_TableView->setStyleSheet(
		"QHeaderView {"
		"background-color: transparent;"
		"background: transparent;"
		"border-image: transparent;"
		"border: none;"
		"margin: 0px;"
		"font-size: 12pt;"
		"} "

		"QHeaderView::section {"
		"background-color: transparent;"
		"background: transparent;"
		"border-image: transparent;"
		"border: none;"
		"} "

		"QTableView::item:focus{"
		"background-color:  rgba(105,105,105, 0.30); "
		"} "

		"QTableView::item {"
		"border-radius: 16px;"
		"margin-bottom: 4px;"
		"min-width: 10px;"
		"background-color: rgba(105,105,105, 0.30);"
		"} "

		"QTableView {"
		"outline: none;"
		"selection-background-color: none;"
		"background: transparent;"
		"gridline-color: rgba(255,0,0,0.0);"
		"border-image: transparent;"
		"font-size: 12pt;"
		"}"

		"QTableView::branch:selected{"
		"background - color: yellow;"
		"} "
	);
	
	

	QStandardItemModel* modelList = new QStandardItemModel(ESTW_TableView);
	modelList->setHorizontalHeaderLabels({ "TEAM", "W", "D", "L"});


	QIcon rmIcon(":/resource/img/realMadridIcon.png");
	rmIcon.addFile(":/resource/img/realMadridIcon.png", QSize(), QIcon::Selected);
	QStandardItem* item1 = new QStandardItem(rmIcon, "Real Madrid");
	item1->setFlags(item1->flags() & ~Qt::ItemIsEditable);
	QStandardItem* item2 = new QStandardItem(rmIcon, "Barcelona");
	item2->setFlags(item2->flags() & ~Qt::ItemIsEditable); // ������� ����������� ��������������
	QStandardItem* item3 = new QStandardItem(rmIcon, "Girona");
	item3->setFlags(item3->flags() & ~Qt::ItemIsEditable); // ������� ����������� ��������������
	QStandardItem* item4 = new QStandardItem("Girona");
	item4->setFlags(item4->flags() & ~Qt::ItemIsEditable); // ������� ����������� ��������������

	modelList->appendRow(item1);
	modelList->appendRow(item2);
	modelList->appendRow(item3);
	modelList->setItem(0, 1, item4);
	//modelList->insertColumn(1, {item4});

	
	//listViewTable->setColumnWidth(1, 200);

	ESTW_TableView->setModel(modelList);
	ESTW_TableView->verticalHeader()->setVisible(false);
	
	ESTW_TableView->verticalHeader()->setMinimumSectionSize(40);
	//listViewTable->setRowHeight(0, 100); // ������������� ������ ������ ������ ������ 40 ��������
	ESTW_TableView->resizeColumnsToContents();
	
}
