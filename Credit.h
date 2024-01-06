#pragma once
#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QPalette>
#include <QPushButton>

#include "Atm.h"

class Credit : public QWidget
{
public:

	Credit(QWidget* parent = nullptr);


	void moveToAtmFun(Atm* partner);

private:

	QLabel* displayCard;
	QLabel* nameBank;
	QLabel* namePerson;


	QLabel* yourCredit;


	QPushButton* next;
	
};