#include "Atm.h"


Atm::Atm(QWidget* parent) : QWidget(parent)
{

	setFixedSize(570, 730);
	//setWindowTitle("Credit Card");
	setStyleSheet("\
		background-image: url(:/icons/resources/Atm.jpg);\
		background-repeat: no-repeat;\
		background-color: rgba(210, 210, 210, 200);\
		");
	setWindowFlags(Qt::FramelessWindowHint);

	selectOptions = new QLabel("Please Select Your Transaction", this);
	selectOptions->setStyleSheet("\
		font: 18px bold;\
		color: #fff;\
		background: transparent;\
		");
	selectOptions->move(165, 260);

	deposit = new QPushButton("Deposit", this);
	deposit->setStyleSheet("\
		font: 15px bold;\
		color: black;\
		background: white;\
		border-radius: 6px;\
		text-align: center;\
		width: 140px;\
		text-transform: uppercase;\
		");
	deposit->move(145, 330);

	fastCash = new QPushButton("Fast Cash", this);
	fastCash->setStyleSheet("\
		font: 15px bold;\
		color: black;\
		background: white;\
		border-radius: 6px;\
		text-align: center;\
		width: 140px;\
		text-transform: uppercase;\
		");
	fastCash->move(145, 370);
	
	pinChange = new QPushButton("Pin Change", this);
	pinChange->setStyleSheet("\
		font: 15px bold;\
		color: black;\
		background: white;\
		border-radius: 6px;\
		text-align: center;\
		width: 140px;\
		text-transform: uppercase;\
		");
	pinChange->move(145, 410);


	//QPushButton* cashWithdrawl;
	//QPushButton* miniStatment;
	//QPushButton* balanceEnquiry;
	//QPushButton* exit;
	///// Right Side
	cashWithdrawl = new QPushButton("Cash Withdrawl", this);
	cashWithdrawl->setStyleSheet("\
		font: 15px bold;\
		color: black;\
		background: white;\
		border-radius: 6px;\
		text-align: center;\
		width: 140px;\
		text-transform: uppercase;\
		");
	cashWithdrawl->move(290, 330);

	miniStatment = new QPushButton("Mini Statment", this);
	miniStatment->setStyleSheet("\
		font: 15px bold;\
		color: black;\
		background: white;\
		border-radius: 6px;\
		text-align: center;\
		width: 140px;\
		text-transform: uppercase;\
		");
	miniStatment->move(290, 370);

	balanceEnquiry = new QPushButton("Balance Enquiry", this);
	balanceEnquiry->setStyleSheet("\
		font: 15px bold;\
		color: black;\
		background: white;\
		border-radius: 6px;\
		text-align: center;\
		width: 140px;\
		text-transform: uppercase;\
		");
	balanceEnquiry->move(290, 410);

	exit = new QPushButton("Exit", this);
	exit->setStyleSheet("\
		font: 15px bold;\
		color: black;\
		background: white;\
		border-radius: 6px;\
		text-align: center;\
		width: 140px;\
		text-transform: uppercase;\
		");
	exit->move(290, 450);

	// Close ATM Page
	connect(exit, &QPushButton::pressed, this, &Atm::close);
	
};

