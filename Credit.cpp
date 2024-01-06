#include "Credit.h"


Credit::Credit(QWidget* parent) : QWidget(parent)
{

	setFixedSize(630, 490);
	setWindowTitle("Credit Card");
	setStyleSheet("\
		background-image: url(:/icons/resources/creditOneAlt.jpg);\
		background-repeat: no-repeat;\
		background-color: rgba(210, 210, 210, 200);\
		");
	setWindowFlags(Qt::FramelessWindowHint);

	
	displayCard = new QLabel(this);
	displayCard->setText("2586  1596  3578  3698");
	displayCard->setStyleSheet("\
		font: 36px bold;\
		background: transparent;\
		color: #FFF;\
		padding: 0 40px 0 40px;\
		border-radius: 5px;\
	");
	displayCard->move(80, 220);


	nameBank = new QLabel(this);
	nameBank->setText("ExtraTop");
	nameBank->setStyleSheet("\
		font: 50px bold;\
		background: transparent;\
		color: #008170;\
		padding: 0 30px 0 30px;\
		border-radius: 6px;\
	");
	nameBank->move(40, 50);

	namePerson = new QLabel(this);
	namePerson->setText("Youssef ElSayed");
	namePerson->setStyleSheet("\
		font: 24px bold;\
		background: transparent;\
		color: #BED754;\
	");
	namePerson->move(60, 340);
	

	yourCredit = new QLabel(this);
	yourCredit->setText("Your Credit Card");
	yourCredit->setStyleSheet("\
		font: 30px bold;\
		background: transparent;\
		color: black;\
	");
	yourCredit->move(40, height() - 45);


	next = new QPushButton("Next", this);
	next->move(width() - 140, height() - 45);
	next->setStyleSheet("\
    QPushButton {\
		padding: 5px 10px;\
		width: 100px;\
		font: bold 16px;\
		border-radius: 6px;\
		background: qlineargradient(\
				x1: 0,\
				y1: 0.5,\
				x2: 1,\
				y2: 0.5\
				stop: 0 #16222A,\
				stop: 0.51 #3A6073,\
				stop: 1 #16222A);\
				color: rgba(255, 255, 255, 70);\
				}\
	QPushButton:hover {\
		background: qlineargradient(\
				x1: 0,\
				y1: 0,\
				x2: 1,\
				y2: 1\
				stop: 0 #000000,\
				stop: 0.51 #53346D,\
				stop: 1 #000000);\
				color: #FFF;\
				}");
};

void Credit::moveToAtmFun(Atm* partner)
{
	connect(next, SIGNAL(clicked()), this, SLOT(hide()));
	connect(next, SIGNAL(clicked()), partner, SLOT(show()));
}



