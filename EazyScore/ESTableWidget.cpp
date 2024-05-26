#include "ESTableWidget.h"
#include <QStandardItem>
#include <QStandardItemModel>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QFrame>
#include <QHeaderView>

ESTableWidget::ESTableWidget(QWidget* parent) : QWidget(parent), listViewTable(nullptr)
{
	//setMinimumSize(350, 230);
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
	initListViewModel();

	QWidget* widIconLeague = new QWidget(this);
	widIconLeague->setMaximumHeight(50);
	
	QHBoxLayout* LayWidIconLeag = new QHBoxLayout(widIconLeague);
	LayWidIconLeag->setAlignment(Qt::AlignLeft);

	QIcon rmIcon(":/resource/img/realMadridIcon.png");
	QPixmap pxmLeague(rmIcon.pixmap(35, 35, QIcon::Mode::Normal, QIcon::State::On));

	QLabel* labelTable = new QLabel(widIconLeague);
	labelTable->setMinimumSize(45, 45);
	QLabel* labelNameTable = new QLabel("TABLE", widIconLeague);
	labelNameTable->setMinimumSize(45, 45);


	labelTable->setPixmap(pxmLeague);
	labelTable->setAlignment(Qt::AlignVCenter);

	widIconLeague->setStyleSheet(
		"QWidget{"
		"margin: 0px;"
		"background: transparent;"
		"border-image: transparent;"
		"padding: 0px;"
		"} "
	);

	labelTable->setStyleSheet(
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
	labelNameTable->setAlignment(Qt::AlignVCenter);
	labelNameTable->setStyleSheet(
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


	LayWidIconLeag->addWidget(labelNameTable);
	LayWidIconLeag->addWidget(labelTable);

	widIconLeague->setLayout(LayWidIconLeag);
	//labelTable->setPixmap(pxmLeague);
	//labelTable->setMask(pxmLeague.mask());
	

	QFrame* frame = new QFrame(this);
	
	QGridLayout* mainLayout = new QGridLayout(frame);
	mainLayout->setSpacing(0);
	mainLayout->addWidget(widIconLeague, 0, 0);
	mainLayout->addWidget(listViewTable, 1, 0);
	
	frame->setLayout(mainLayout);
	frame->setStyleSheet(
		"QFrame{"
		"background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0.04 rgba(139,55,169,0), stop : 0.4 rgba(139,55,169,30), stop : 1 rgba(50,73,158,90));"
		"} "
		"QFrame::hover{background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0.04 rgba(139,55,169,0), stop : 0.4 rgba(139,55,169,10), stop : 1 rgba(50,73,158,60));}");
	//frame->setStyleSheet("border-image: url(:/resource/img/stadium.png) 0 0 0 0 stretch stretch;");50,73,158
	
	QVBoxLayout* vbox = new QVBoxLayout(this);
	vbox->addWidget(frame);

	this->setLayout(vbox);

}

ESTableWidget::~ESTableWidget()
{

}

void ESTableWidget::initListViewModel(void)
{
	if (listViewTable != nullptr)
		return;
	listViewTable = new QTableView(this);
	listViewTable->setMinimumHeight(250);
	listViewTable->setAttribute(Qt::WA_TransparentForMouseEvents);
	listViewTable->setIconSize(QSize(28, 28));
	listViewTable->setSelectionBehavior(QAbstractItemView::SelectRows);
	listViewTable->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
	listViewTable->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Expanding);
	listViewTable->setStyleSheet(
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
	
	

	QStandardItemModel* modelList = new QStandardItemModel(listViewTable);
	modelList->setHorizontalHeaderLabels({ "TEAM", "W", "D", "L"});


	QIcon rmIcon(":/resource/img/realMadridIcon.png");
	rmIcon.addFile(":/resource/img/realMadridIcon.png", QSize(), QIcon::Selected);
	QStandardItem* item1 = new QStandardItem(rmIcon, "Real Madrid");
	item1->setFlags(item1->flags() & ~Qt::ItemIsEditable);
	QStandardItem* item2 = new QStandardItem(rmIcon, "Barcelona");
	item2->setFlags(item2->flags() & ~Qt::ItemIsEditable); // Убираем возможность редактирования
	QStandardItem* item3 = new QStandardItem(rmIcon, "Girona");
	item3->setFlags(item3->flags() & ~Qt::ItemIsEditable); // Убираем возможность редактирования
	QStandardItem* item4 = new QStandardItem("Girona");
	item4->setFlags(item4->flags() & ~Qt::ItemIsEditable); // Убираем возможность редактирования

	modelList->appendRow(item1);
	modelList->appendRow(item2);
	modelList->appendRow(item3);
	modelList->setItem(0, 1, item4);
	//modelList->insertColumn(1, {item4});

	
	//listViewTable->setColumnWidth(1, 200);

	listViewTable->setModel(modelList);
	listViewTable->verticalHeader()->setVisible(false);
	
	listViewTable->verticalHeader()->setMinimumSectionSize(40);
	//listViewTable->setRowHeight(0, 100); // Устанавливает высоту первой строки равной 40 пикселей
	listViewTable->resizeColumnsToContents();
	
}
