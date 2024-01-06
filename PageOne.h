#pragma once
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QDateEdit>
#include <QRadioButton>
#include <QComboBox>
#include <QButtonGroup>
#include <QMessageBox>
#include "PageTwo.h"
//#include "PageWelcome.h"
class PageOne : public QWidget
{

public:
	 PageOne(QWidget* parent = nullptr);

	~PageOne();

	void moveToPageTwoFun(PageTwo* partner);

	//void backToPageWelcomeFun(PageWelcome* partner);
private:

	QVBoxLayout* main_layout;

	QHBoxLayout* title_layout;
	QHBoxLayout* personal_layout;
	QHBoxLayout* father_layout;
	QHBoxLayout* name_layout;
	QHBoxLayout* date_layout;
	QHBoxLayout* gander_layout;
	QHBoxLayout* email_layout;
	QHBoxLayout* status_layout;
	QHBoxLayout* address_layout;
	QHBoxLayout* city_layout;
	//QHBoxLayout* pinCode_layout;
	QHBoxLayout* state_layout;
	QHBoxLayout* next_layout;


	QLineEdit* name_box;
	QLineEdit* father_box;
	QLineEdit* email_box;
	//QLineEdit* pinCode_box;

	QComboBox* address_combo;
	QComboBox* city_combo;
	QComboBox* state_combo;


	QDateEdit* dateOfBirth;


	QRadioButton* radio_male;
	QRadioButton* radio_female;

	QRadioButton* radio_married;
	QRadioButton* radio_single;
	QRadioButton* radio_other;


	QButtonGroup* ganderGroup;
	
	QButtonGroup* maritalStatusGroup;

	QLabel* testTabel;
	QLabel* personal_label;
	QLabel* welcometitle;
	QLabel* bank_icon;
	QLabel* form_counter;
	QLabel* name_label;
	QLabel* father_label;
	QLabel* date_label;
	QLabel* gander_label;
	QLabel* email_label;
	QLabel* status_label;
	QLabel* address_label;
	QLabel* city_label;
	QLabel* state_label;


	QPushButton* back_btn;
	QPushButton* next_btn;
	QPushButton* closebtn;



	// Click Functions ( Buttons )
	void onPressedNextPageOne();
	void cityChange(int index);


	bool isSubmit = false;
};