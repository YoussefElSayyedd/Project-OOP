#include "PageTwo.h"

PageTwo::PageTwo(QWidget* parent) : QWidget(parent)
{
	setWindowTitle("Additional Details");
	setStyleSheet("\
		background: qlineargradient(\
			x1: 0,\
			y1: 0,\
			x2: 1,\
			y2: 1,\
			stop: 0.02 #15154E,\
			stop: 0.45 #2C406A,\
			stop: 0.78 #4F4F7F,\
			stop: 0.87 #186675\
			);\
	");
	setFixedSize(800, 730);
	setWindowFlags(Qt::FramelessWindowHint);
	closebtn = new QPushButton(this);
	closebtn->setText("x");
	closebtn->setFont(QFont("Arial", 18));
	closebtn->setStyleSheet("\
		QPushButton {\
			background: transparent;\
			border-bottom-left-radius: 4px;\
			color: rgb(255, 255, 255);\
		}\
		QPushButton:hover {\
		background: red;\
		}\
		");
	closebtn->setFixedSize(35, 35);
	closebtn->move(width() - 35, 0);


	// Connection Close Button
	connect(closebtn, &QPushButton::clicked, this, &PageTwo::close);


	// Main Layout
	main_layout = new QVBoxLayout();
	setLayout(main_layout);
	main_layout->setAlignment(Qt::AlignTop);


	// Title Layout ( Application Form NO )
	title_layout = new QHBoxLayout();
	title_layout->setAlignment(Qt::AlignCenter);
	bank_icon = new QLabel();
	QPixmap bIcon(":/icons/resources/bank.png");
	QPixmap baIcon = bIcon.scaled(QSize(140, 170), Qt::KeepAspectRatio);
	bank_icon->setPixmap(baIcon);
	bank_icon->setMinimumWidth(140);
	bank_icon->setMinimumHeight(170);
	bank_icon->setStyleSheet("\
		margin-right: 10px;\
		background-color: transparent;\
		");
	welcometitle = new QLabel("Application form No: ");
	welcometitle->setStyleSheet("\
		font: bold 38px;\
		background-color: transparent;\
		text-transform: uppercase;\
		");
	form_counter = new QLabel("0");
	form_counter->setStyleSheet("\
		font: bold 32px;\
		background: transparent;\
		color: white;\
		");
	title_layout->addWidget(bank_icon);
	title_layout->addWidget(welcometitle);
	title_layout->addWidget(form_counter);

	// Additional Details Layout
	additional_layout = new QHBoxLayout();
	additional_layout->setAlignment(Qt::AlignCenter);
	additional_label = new QLabel("Page 2 : Additional Details");
	additional_label->setStyleSheet("\
		font: 26px;\
		background: transparent;\
		color: white;\
		");
	additional_layout->addWidget(additional_label);

	// Religion Layout ( Religion )
	religion_layout = new QHBoxLayout();
	religion_label = new QLabel("Religion: ");
	religion_label->setStyleSheet("\
		margin-left: 100px;\
		font: bold 22px;\
		border-radius: 4px;\
		color: #FFF;\
		");
	religion_label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
	religion_combo = new QComboBox();
	religion_combo->addItem("Muslim");
	religion_combo->addItem("Christian");
	// Set Style Sheet ( Religion )
	//religion_combo->setPlaceholderText("Enter Your Religion");
	religion_combo->setStyleSheet("\
	         QComboBox { \
				border: 1px solid #DDD;\
                font: 18px;\
				background: white;\
				border-radius: 4px;\
				padding: 0 8px;\
				}\
			 QComboBox:focus {\
				border-color: #4CAF50;\
				}\
			 QComboBox::item { background-color: red; } \
			 QComboBox::item:hover { background-color: lightgreen; }\
			 ");
	//religion_combo->setForegroundRole();
	religion_combo->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
	religion_layout->addWidget(religion_label);
	religion_layout->addWidget(religion_combo);

	// Category Layout ( Category )
	category_layout = new QHBoxLayout();
	category_label = new QLabel("Category: ");
	category_label->setStyleSheet("\
		margin-left: 100px;\
		font: bold 22px;\
		border-radius: 4px;\
		color: #FFF;\
		");
	category_label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
	category_combo = new QComboBox();
	category_combo->addItem("General");
	category_combo->addItem("OBC");
	category_combo->addItem("SC");
	category_combo->addItem("ST");
	category_combo->addItem("Other");
	//category_box->setMaxLength(14);
	// Set Style Sheet ( Category Field )
	//category_box->setPlaceholderText("Enter your Category");
	category_combo->setStyleSheet("\
	         QComboBox { \
				border: 1px solid #DDD;\
                font: 18px;\
				background: white;\
				border-radius: 4px;\
				padding: 0 8px;\
				}\
			 QComboBox:focus {\
				border-color: #4CAF50;\
				}\
			 ");
	category_combo->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
	category_layout->addWidget(category_label);
	category_layout->addWidget(category_combo);


	// Income Layout
	income_layout = new QHBoxLayout();
	income_label = new QLabel("Income: ");
	income_label->setStyleSheet("\
		margin-left: 100px;\
		font: bold 22px;\
		border-radius: 4px;\
		color: #FFF;\
		");
	income_label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
	income_combo = new QComboBox();
	income_combo->addItem("Null");
	income_combo->addItem("Less than 3,500");
	income_combo->addItem("3,500 : 4,500");
	income_combo->addItem("4,500 : 5,500");
	income_combo->addItem("5,500 : 6,500");
	income_combo->addItem("Bigger than 6,500");
	// Set Style Sheet ( Father's Name Field )
	//income_combo->setPlaceholderText("");
	income_combo->setStyleSheet("\
	         QComboBox { \
				border: 1px solid #DDD;\
                font: 18px;\
				background: white;\
				border-radius: 4px;\
				padding: 0 8px;\
				}\
			 QComboBox:focus {\
				border-color: #4CAF50;\
				}\
			 ");
	income_combo->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
	income_layout->addWidget(income_label);
	income_layout->addWidget(income_combo);


	// Education Layout
	education_layout = new QHBoxLayout();
	education_label = new QLabel("Education: ");
	education_label->setStyleSheet("\
		margin-left: 100px;\
		font: bold 22px;\
		border-radius: 4px;\
		color: #FFF;\
		");
	education_label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
	education_combo = new QComboBox();
	education_combo->addItem("Non-Graduate");
	education_combo->addItem("Graduate");
	education_combo->addItem("Post-Graduate");
	education_combo->addItem("Master");
	education_combo->addItem("Ph.D");
	education_combo->addItem("Other");
	// Set Style Sheet ( Education Field )
	//education_box->setPlaceholderText("Enter Your Education");
	education_combo->setStyleSheet("\
	         QComboBox { \
				border: 1px solid #DDD;\
                font: 18px;\
				background: white;\
				border-radius: 4px;\
				padding: 0 8px;\
				}\
			 QComboBox:focus {\
				border-color: #4CAF50;\
				}\
			 ");
	education_combo->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
	education_layout->addWidget(education_label);
	education_layout->addWidget(education_combo);

	// Occupation Layout
	occupation_layout = new QHBoxLayout();
	occupation_label = new QLabel("Occupation: ");
	occupation_label->setStyleSheet("\
		margin-left: 100px;\
		font: bold 22px;\
		border-radius: 4px;\
		color: #FFF;\
		");
	occupation_label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
	occupation_combo = new QComboBox();
	occupation_combo->addItem("Student");
	occupation_combo->addItem("Self-Employed");
	occupation_combo->addItem("Business");
	occupation_combo->addItem("Retired");
	occupation_combo->addItem("Other");
	// Set Style Sheet ( Education Field )
	//occupation_->setPlaceholderText("Enter Your Education");
	occupation_combo->setStyleSheet("\
	         QComboBox { \
				border: 1px solid #DDD;\
                font: 18px;\
				background: white;\
				border-radius: 4px;\
				padding: 0 8px;\
				}\
			 QComboBox:focus {\
				border-color: #4CAF50;\
				}\
			 ");
	occupation_combo->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
	occupation_layout->addWidget(occupation_label);
	occupation_layout->addWidget(occupation_combo);



	// Phone Layout ( Phone Number )
	phone_layout = new QHBoxLayout();
	phone_label = new QLabel("Phone Number: ");
	phone_label->setStyleSheet("\
		margin-left: 100px;\
		font: bold 22px;\
		border-radius: 4px;\
		color: #FFF;\
		");
	phone_label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
	phone_box = new QLineEdit();
	phone_box->setMaxLength(14);
	// Set Style Sheet ( Phone Number Field )
	phone_box->setPlaceholderText("Enter Phone Number");
	phone_box->setStyleSheet("\
	         QLineEdit { \
				margin-right: 100px;\
				border: 1px solid #DDD;\
                font: 18px;\
				background: white;\
				border-radius: 4px;\
				padding: 0 8px;\
				}\
			 QLineEdit:focus {\
				border-color: #4CAF50;\
				}\
			 ");
	phone_box->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
	phone_layout->addWidget(phone_label);
	phone_layout->addWidget(phone_box);



	// Phone Layout ( Phone Number )
	pan_layout = new QHBoxLayout();
	pan_label = new QLabel("PAN Number: ");
	pan_label->setStyleSheet("\
		margin-left: 100px;\
		font: bold 22px;\
		border-radius: 4px;\
		color: #FFF;\
		");
	pan_label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
	pan_box = new QLineEdit();
	pan_box->setMaxLength(14);
	// Set Style Sheet ( Phone Number Field )
	pan_box->setPlaceholderText("Enter Phone Number");
	pan_box->setStyleSheet("\
	         QLineEdit { \
				margin-right: 100px;\
				border: 1px solid #DDD;\
                font: 18px;\
				background: white;\
				border-radius: 4px;\
				padding: 0 8px;\
				}\
			 QLineEdit:focus {\
				border-color: #4CAF50;\
				}\
			 ");
	pan_box->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
	pan_layout->addWidget(pan_label);
	pan_layout->addWidget(pan_box);


	// Connection
	connect(phone_box, &QLineEdit::textChanged, this, &PageTwo::onChangePhone);

	// Senior Citizen Layout
	citizen_layout = new QHBoxLayout();
	citizen_label = new QLabel("Senior Citizen: ");
	citizen_label->setStyleSheet("\
		margin-left: 100px;\
		font: bold 22px;\
		border-radius: 4px;\
		color: #FFF;\
		");
	citizen_label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
	radio_yes_citizen = new QRadioButton("Yes");
	radio_no_citizen = new QRadioButton("No");
	// Set Style Sheet ( Gander Radio Button )
	radio_yes_citizen->setStyleSheet("\
				margin-right: 100px;\
				margin-left: 40px;\
                font: bold 18px;\
				background: transparent;\
				color: black;\
			 ");
	radio_no_citizen->setStyleSheet("\
				margin-right: 130px;\
				margin-left: 20px;\
                font: bold 18px;\
				background: transparent;\
				color: black;\
			 ");

	citizenGroup = new QButtonGroup();
	citizenGroup->addButton(radio_yes_citizen);
	citizenGroup->addButton(radio_no_citizen);
	citizen_layout->addWidget(citizen_label);
	citizen_layout->addWidget(radio_yes_citizen);
	citizen_layout->addWidget(radio_no_citizen);

	
	// Existing Account Layout
	account_layout = new QHBoxLayout();
	account_label = new QLabel("Existing Account: ");
	account_label->setStyleSheet("\
		margin-left: 100px;\
		font: bold 22px;\
		border-radius: 4px;\
		color: #FFF;\
		");
	account_label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
	radio_yes_account = new QRadioButton("Yes");
	radio_no_account = new QRadioButton("No");
	// Set Style Sheet ( Gander Radio Button )
	radio_yes_account->setStyleSheet("\
				margin-right: 100px;\
				margin-left: 40px;\
                font: bold 18px;\
				background: transparent;\
				color: black;\
			 ");
	radio_no_account->setStyleSheet("\
				margin-right: 130px;\
				margin-left: 20px;\
                font: bold 18px;\
				background: transparent;\
				color: black;\
			 ");
	accountGroup = new QButtonGroup();
	accountGroup->addButton(radio_yes_account);
	accountGroup->addButton(radio_no_account);

	account_layout->addWidget(account_label);
	account_layout->addWidget(radio_yes_account);
	account_layout->addWidget(radio_no_account);


	// Back Button
	back_btn = new QPushButton("Back"); // Back Button
	//back_btn->setDisabled(true);
	// Set Style Sheet ( Back Button )
	back_btn->setStyleSheet("\
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
				");
	// Next Layout
	next_layout = new QHBoxLayout();
	next_layout->addStretch();
	next_btn = new QPushButton("Next"); // Next Button
	//next_btn->setDisabled(true);
	// Set Style Sheet ( Next Button )
	next_btn->setStyleSheet("\
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
				}");
	next_layout->addWidget(back_btn);
	next_layout->addWidget(next_btn);



	main_layout->addLayout(title_layout); // Insert Title Layout
	main_layout->addSpacing(0);
	main_layout->addLayout(additional_layout); // Insert Additional Layout
	main_layout->addSpacing(20);
	main_layout->addLayout(religion_layout); // Insert Religion Layout
	main_layout->addSpacing(10);
	main_layout->addLayout(category_layout); // Insert Category Layout
	main_layout->addSpacing(10);
	main_layout->addLayout(income_layout); // Insert Income Layout
	main_layout->addSpacing(10);
	main_layout->addLayout(education_layout); // Insert Education Layout
	main_layout->addSpacing(10);
	main_layout->addLayout(occupation_layout); // Insert Occupation Layout
	main_layout->addSpacing(10);
	//main_layout->addLayout(pan_layout); // Insert Pan Number Layout
	//main_layout->addSpacing(10);
	main_layout->addLayout(phone_layout); // Insert Phone Number Layout
	main_layout->addSpacing(20);
	main_layout->addLayout(citizen_layout); // Insert Citizen Layout
	main_layout->addSpacing(10);
	main_layout->addLayout(account_layout); // Insert Account Layout
	main_layout->addSpacing(50);
	main_layout->addLayout(next_layout); // Insert Next & Back Layout


}
PageTwo::~PageTwo()
{

}

void PageTwo::onChangePhone()
{
	QString textChangePhone = phone_box->text();
	QString textResPhone = "";
	for (int i = 0; i < textChangePhone.length(); i++)
	{
		if (!textChangePhone.at(i).isDigit())
		{
			for (int j = 0; j < textChangePhone.length() - 1; j++)
			{
				textResPhone += textChangePhone.at(j);
			}
			phone_box->setText(textResPhone);
		}
	}
	if (textChangePhone.length() != 0 /*Another Condition Here*/)
	{
		next_btn->setDisabled(false);
		next_btn->setStyleSheet("\
			QPushButton {\
				padding: 5px 10px;\
				width: 100px;\
				font: bold 16px;\
				border-radius: 6px;\
				background: qlineargradient(\
				x1: 0,\
				y1: 0,\
				x2: 1,\
				y2: 1\
				stop: 0 #000000,\
				stop: 0.51 #53346D,\
				stop: 1 #000000);\
				color: #FFF;\
			}\
		");
	}
	else
	{
		next_btn->setDisabled(true);
		next_btn->setStyleSheet("\
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
		");
	}
}









/*
void PageWelcome::onChangeCard()
{
	QString textChange = card_box->text();
	QString textRes = "";
	for (int i = 0; i < textChange.length(); i++)
	{
		if (!textChange.at(i).isDigit())
		{
			for (int j = 0; j < textChange.length() - 1; j++)
			{
				textRes += textChange.at(j);
			}
			card_box->setText(textRes);
		}
	}
	// Event Submit
	if (textChange.length() == 16 && pin_box->text().length() == 4)
	{
		sign_btn->setDisabled(false);
		sign_btn->setStyleSheet("\
			QPushButton {\
				padding: 5px 10px;\
				width: 100px;\
				font: bold 16px;\
				border-radius: 6px;\
				background: qlineargradient(\
				x1: 0,\
				y1: 0,\
				x2: 1,\
				y2: 1\
				stop: 0 #000000,\
				stop: 0.51 #53346D,\
				stop: 1 #000000);\
				color: #FFF;\
			}\
		");
	}
	else
	{
		sign_btn->setDisabled(true);
		sign_btn->setStyleSheet("\
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
		");
	}
	// Feature I Don't Use It For Now
	/*
	if (textChange.length() == 14)
	{
		pin_box->setFocus();
	}
	
}





*/







void PageTwo::moveToCredit(Credit* partner)
{
	connect(next_btn, SIGNAL(clicked()), this, SLOT(hide()));
	connect(next_btn, SIGNAL(clicked()), partner, SLOT(show()));
}



