#pragma once
#include <iostream>
#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QMainWindow>
#include <QPixmap>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QIntValidator>
#include <QMessageBox>
#include <QKeyEvent>
#include <QLinearGradient>
#include <cmath>
#include <ctime>
#include "PageOne.h"

// MySQL Connection
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>


using namespace std;
class PageWelcome : public QWidget
{


public:
	PageWelcome(QWidget* parent = 0);

	~PageWelcome();

	void moveToPageOneFun(PageOne* partner);

private:
	QVBoxLayout* main_layout;

	QHBoxLayout* title_layout;
	QHBoxLayout* card_layout;
	QHBoxLayout* pin_layout;

	QVBoxLayout* login_layout;
	QVBoxLayout* clear_layout;
	QHBoxLayout* clearLogin_layout;
	QHBoxLayout* sign_layout;
	QHBoxLayout* next_layout;

	QVBoxLayout* left_layout;
	QVBoxLayout* right_layout;


	QLineEdit* card_box;
	QLineEdit* pin_box;


	QLabel* card_label;
	QLabel* pin_label;
	QLabel* welcometitle;
	QLabel* bank_icon;


	QPushButton* login_btn;
	QPushButton* sign_btn;
	QPushButton* clear_btn;
	QPushButton* next_btn;
	QPushButton* close_btn;

	QPushButton* registerButton;

	// Click Functions ( Buttons )
	void onPressedNextPageW();
	void onPressedSign();
	void onPressedLogin();
	void onPressedClear();
	void closeFun();
	

	// Unfocus Function ( Fields )
	void unFocusFunCard();
	void unFocusFunPin();
	void onChangeCard();
	void onChangePin();
	void insertDataIntoDatabase(const QString& cardNumber, const QString& pin);
	void insertDataPwelcome();
};