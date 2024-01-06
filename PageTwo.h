#pragma once
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QDateEdit>
#include <QRadioButton>
#include <QComboBox>
#include <QPalette>
#include "Credit.h"
#include <QButtonGroup>
class PageTwo : public QWidget
{

public:
	PageTwo(QWidget* parent = nullptr);

	~PageTwo();

	void moveToCredit(Credit* partner);

	//void movFun(PageWelcome* pa);
private:

	QVBoxLayout* main_layout;

	QHBoxLayout* title_layout;
	QHBoxLayout* additional_layout;
	QHBoxLayout* religion_layout;
	QHBoxLayout* category_layout;
	QHBoxLayout* income_layout;
	QHBoxLayout* education_layout;
	QHBoxLayout* occupation_layout;
	QHBoxLayout* phone_layout;
	QHBoxLayout* pan_layout;
	QHBoxLayout* citizen_layout;
	QHBoxLayout* account_layout;
	QHBoxLayout* next_layout;


	//QLineEdit* category_box;
	//QLineEdit* income_box;
	//QLineEdit* education_box;
	//QLineEdit* occupation_box;
	QLineEdit* phone_box;
	QLineEdit* pan_box;

	QComboBox* religion_combo;
	QComboBox* income_combo;
	QComboBox* category_combo;
	QComboBox* education_combo;
	QComboBox* occupation_combo;




	QRadioButton* radio_yes_citizen;
	QRadioButton* radio_no_citizen;

	QRadioButton* radio_yes_account;
	QRadioButton* radio_no_account;




	QButtonGroup* citizenGroup;

	QButtonGroup* accountGroup;

	//QRadioButton* radio_married;
	//QRadioButton* radio_single;
	//QRadioButton* radio_other;

	//QLabel* testTabel;
	QLabel* additional_label;
	QLabel* welcometitle;
	QLabel* bank_icon;
	QLabel* religion_label;
	QLabel* form_counter;
	QLabel* category_label;
	QLabel* income_label;
	QLabel* education_label;
	QLabel* occupation_label;
	QLabel* phone_label;
	QLabel* pan_label;
	QLabel* citizen_label;
	QLabel* account_label;
	//QLabel* city_label;
	//QLabel* state_label;


	QPushButton* back_btn;
	QPushButton* next_btn;
	QPushButton* closebtn;


	//PageWelcome* pageWelcome;

	//// Click Functions ( Buttons )
	//void onPressedNextPage1();
	//void onPressedSign();
	//void onPressedLogin();
	//void onPressedClear();
	//void closeFun();

	//// Unfocus Function ( Fields )
	//void unFocusFunCard();
	//void unFocusFunPin();
	void onChangePhone();
	//void onChangePin();


	//void openPageWelcome();
};