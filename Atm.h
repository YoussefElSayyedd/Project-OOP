#pragma once
#include <QWidget>
#include <QLabel>
#include <QPushButton>
class Atm : public QWidget
{
public:

	Atm(QWidget* parent = nullptr);

private:

	QPushButton* deposit;
	QPushButton* fastCash;
	QPushButton* pinChange;
	QPushButton* cashWithdrawl;
	QPushButton* miniStatment;
	QPushButton* balanceEnquiry;
	QPushButton* exit;


	QLabel* selectOptions;

};