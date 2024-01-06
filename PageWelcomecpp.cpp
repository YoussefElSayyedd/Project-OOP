#include "PageWelcome.h"
//#include "PageOne.h"

const string server = "tcp://127.0.0.1:3306";
const string username = "root";
const string password = "";
const string database = "qt_project";



PageWelcome::PageWelcome(QWidget* parent) : QWidget(parent)
{
	
	// Page Welcome Style
	setWindowTitle("Welcome Page");
	setFixedSize(800, 500);
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
	setWindowFlags(Qt::FramelessWindowHint);
	close_btn = new QPushButton("×", this);
	close_btn->setFont(QFont("Arial", 18));
	close_btn->setStyleSheet("\
		QPushButton {\
			background: transparent;\
			border-bottom-left-radius: 4px;\
			color: rgb(255, 255, 255);\
		}\
		QPushButton:hover {\
		background: red;\
		}\
		");
	close_btn->setFixedSize(35, 35);
	close_btn->move(width() - 35, 0);
	
	// Connection Close Button
	connect(close_btn, &QPushButton::clicked, this, &PageWelcome::close);



	// Main Layout
	main_layout = new QVBoxLayout();
	setLayout(main_layout);
	main_layout->setAlignment(Qt::AlignTop);

	// Title Layout ( Welcome To ATM )
	title_layout = new QHBoxLayout();
	title_layout->setAlignment(Qt::AlignCenter);
	bank_icon = new QLabel();
	QPixmap bIcon(":/icons/resources/bank.png");
	QPixmap baIcon = bIcon.scaled(QSize(160, 190), Qt::KeepAspectRatio);
	bank_icon->setPixmap(baIcon);
	bank_icon->setMinimumWidth(160);
	bank_icon->setMinimumHeight(190);
	bank_icon->setStyleSheet("\
		margin-right: 100px;\
		background-color: transparent;\
		");
	welcometitle = new QLabel("Welcome To ATM");
	welcometitle->setStyleSheet("\
		font: bold 42px;\
		background-color: transparent;\
		");
	title_layout->addWidget(bank_icon);
	title_layout->addWidget(welcometitle);
	
	
	// Card Layout ( Card No )
	card_layout = new QHBoxLayout();
	card_label = new QLabel("Card No: ");
	card_label->setStyleSheet("\
		margin-left: 100px;\
		font: bold 22px;\
		border-radius: 4px;\
		color: #FFF;\
		");
	card_label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
	card_box = new QLineEdit();
	card_box->setMaxLength(16);
	// Set Style Sheet ( Card Field )
	card_box->setPlaceholderText("Enter Card Number ( 16 Digits )");
	card_box->setStyleSheet("\
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
	card_box->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
	card_layout->addWidget(card_label);
	card_layout->addWidget(card_box);

	// PIN Layout ( PIN )
	pin_layout = new QHBoxLayout();
	pin_label = new QLabel("PIN: ");
	pin_label->setStyleSheet("\
		font: bold 22px;\
		margin-left: 100px;\
		border-radius: 4px;\
		color: #FFF;\
		");
	pin_label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
	pin_box = new QLineEdit();
	pin_box->setEchoMode(QLineEdit::Password);
	// Set Validator
	QIntValidator* validator = new QIntValidator(this);
	pin_box->setValidator(validator);
	pin_box->setMaxLength(4);
	// Set Style Sheet ( PIN Field )
	pin_box->setPlaceholderText("Enter Your PIN Here ( 4 Digits )");
	pin_box->setStyleSheet("\
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
	pin_box->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
	pin_layout->addWidget(pin_label);
	pin_layout->addWidget(pin_box);

	// Login & Clear Button Layout
	clearLogin_layout = new QHBoxLayout();
	clearLogin_layout->setAlignment(Qt::AlignRight);
	login_layout = new QVBoxLayout(); // Login Layout
	clear_layout = new QVBoxLayout(); // Clear Layout
	login_btn = new QPushButton("Login"); // Login Button
	login_btn->setDisabled(true);
	// Set Style Sheet ( Log In Button )
	login_btn->setStyleSheet("\
    QPushButton {\
		padding: 5px 10px;\
		width: 120px;\
		font: bold 16px;\
		border-radius: 6px;\
		background-color: black;\
		background: qlineargradient(\
			x1: 0, \
			y1 : 0.5, \
			x2 : 1, \
			y2 : 0.5\
			stop : 0 #16222A, \
			stop: 0.51 #3A6073, \
			stop: 1 #16222A);\
		color: rgba(255, 255, 255, 70);\
		}\
		");
	clear_btn = new QPushButton("Clear"); // Clear Button
	// Set Style Sheet ( Clear Button )
	clear_btn->setStyleSheet("QPushButton:hover { background-color: red; }\
    QPushButton {margin-right: 100px;\
    padding: 5px 10px; width: 120px; font: bold 16px; border-radius: 6px;\
    background-color: black; color: white;}");
	login_layout->addWidget(login_btn);
	clear_layout->addWidget(clear_btn);
	clearLogin_layout->addLayout(login_layout);
	clearLogin_layout->addLayout(clear_layout);

	// Sign Button Layout
	sign_layout = new QHBoxLayout();
	sign_layout->setAlignment(Qt::AlignRight);
	sign_btn = new QPushButton("Sign In");
	// Set Style Sheet ( Sign Button )
	sign_btn->setStyleSheet("QPushButton:hover { background-color: green; }\
    QPushButton {margin-right: 100px;\
    padding: 5px 10px; width: 267px; font: bold 16px; border-radius: 6px;\
    background-color: black; color: white;}");
	sign_layout->addWidget(sign_btn);


	
	// Connection Buttons
	connect(clear_btn, &QPushButton::clicked, this, &PageWelcome::onPressedClear);
	connect(sign_btn, &QPushButton::clicked, this, &PageWelcome::onPressedSign);

	// Connection Fields
	connect(card_box, &QLineEdit::returnPressed, this, &PageWelcome::unFocusFunCard);
	connect(card_box, &QLineEdit::textChanged, this, &PageWelcome::onChangeCard);
	connect(pin_box, &QLineEdit::returnPressed, this, &PageWelcome::unFocusFunPin);
	connect(pin_box, &QLineEdit::textChanged, this, &PageWelcome::onChangePin);

	connect(sign_btn, &QPushButton::clicked, this, &PageOne::show);

	main_layout->addLayout(title_layout); // Insert Title Layout
	main_layout->addSpacing(10);
	main_layout->addLayout(card_layout); // Insert Card Layout
	main_layout->addSpacing(10);
	main_layout->addLayout(pin_layout); // Inserrt Pin Layout
	main_layout->addSpacing(30);
	main_layout->addLayout(clearLogin_layout); // Insert Login & Clear Layout
	main_layout->addSpacing(10);
	main_layout->addLayout(sign_layout); // Insert Sign Layout
	main_layout->addSpacing(50);
	
}
PageWelcome::~PageWelcome()
{

}
// Implementation Functions
// Function Card Focus
void PageWelcome::unFocusFunCard() // Field
{
	pin_box->setFocus();
}
// Function Pin Focus
void PageWelcome::unFocusFunPin() // Pin Field 
{
	login_btn->pressed();
}
// Function Clear Click
void PageWelcome::onPressedClear() // Clear Button
{
	card_box->clear();
	pin_box->clear();
}
// Function Sign Click
void PageWelcome::onPressedSign() // Sign In Button
{
	insertDataPwelcome();
}
// Implementation To Function Doesn't Exsits in FrameWork Qt
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
		login_btn->setDisabled(false);
		login_btn->setStyleSheet("\
			QPushButton {\
				padding: 5px 10px;\
				width: 120px;\
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
		login_btn->setDisabled(true);
		login_btn->setStyleSheet("\
			QPushButton {\
				padding: 5px 10px;\
				width: 120px;\
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
	*/
}
void PageWelcome::onChangePin()
{
	QString textPin = pin_box->text();
	// Event Submit
	if (card_box->text().length() == 16 && textPin.length() == 4)
	{
		login_btn->setDisabled(false);
		login_btn->setStyleSheet("\
			QPushButton {\
				padding: 5px 10px;\
				width: 120px;\
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
		login_btn->setDisabled(true);
		login_btn->setStyleSheet("\
			QPushButton {\
				padding: 5px 10px;\
				width: 120px;\
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
// Function To Move to PageOne 
void PageWelcome::moveToPageOneFun(PageOne* partner)
{
	connect(sign_btn, SIGNAL(clicked()), this, SLOT(hide()));
	connect(sign_btn, SIGNAL(clicked()), partner, SLOT(show()));
}
// Function DataBase
void PageWelcome::insertDataIntoDatabase(const QString& cardNumber, const QString& pin)
{
	sql::Driver* driver;
	sql::Connection* con;
	sql::PreparedStatement* pstmt;

	try
	{
		driver = get_driver_instance();
		con = driver->connect(server, username, password);
		con->setSchema(database);

		// Prepare the INSERT query
		pstmt = con->prepareStatement("INSERT INTO testtable (CardNum, PinNum) VALUES (?, ?)");

		// Set the parameters
		pstmt->setString(1, cardNumber.toStdString());
		pstmt->setString(2, pin.toStdString());

		// Execute the query
		pstmt->execute();

		// Clean up
		delete pstmt;
		delete con;
	}
	catch (sql::SQLException& e)
	{
		// Handle SQL exception (MySQL errors)
		qDebug() << "SQL Exception: " << e.what();
	}
}


void PageWelcome::insertDataPwelcome()
{
	sql::Driver* driver;
	sql::Connection* con;
	sql::PreparedStatement* pstmt;

	try
	{
		driver = get_driver_instance();
		con = driver->connect(server, username, password);
		con->setSchema(database);

		// Prepare the INSERT query
		pstmt = con->prepareStatement("INSERT INTO pwelcomedb (card_num, pin_num) VALUES (?, ?)");

		srand(static_cast<unsigned int>(time(nullptr)));

		int randomPinNum = rand() % 9000 + 1000;
		int randomCardNum1 = rand() % 90000000 + 10000000;
		int randomCardNum2 = rand() % 90000000 + 10000000;
		string randonCardStr = to_string(randomCardNum1) + to_string(randomCardNum2);
		// Set the parameters
		pstmt->setString(1, randonCardStr);
		pstmt->setInt(2, randomPinNum);

		// Execute the query
		pstmt->execute();

		// Clean up
		delete pstmt;
		delete con;
	}
	catch (sql::SQLException& e)
	{
		// Handle SQL exception (MySQL errors)
		qDebug() << "SQL Exception: " << e.what();
	}
}