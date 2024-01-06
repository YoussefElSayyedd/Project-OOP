#include "PageOne.h"
//#include "PageTwo.h"
PageOne::PageOne(QWidget* parent) : QWidget(parent)
{
	setWindowTitle("Personal Details");
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
	connect(closebtn, &QPushButton::clicked, this, &PageOne::close);


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

	// Personal Details Layout
	personal_layout = new QHBoxLayout();
	personal_layout->setAlignment(Qt::AlignCenter);
	personal_label = new QLabel("Page 1 : Personal Details");
	personal_label->setStyleSheet("\
		font: 26px;\
		background: transparent;\
		color: white;\
		");
	personal_layout->addWidget(personal_label);

	// Name Layout ( Name )
	name_layout = new QHBoxLayout();
	name_label = new QLabel("Name: ");
	name_label->setStyleSheet("\
		margin-left: 100px;\
		font: bold 22px;\
		border-radius: 4px;\
		color: #FFF;\
		");
	name_label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
	name_box = new QLineEdit();
	name_box->setMaxLength(14);
	// Set Style Sheet ( Name Field )
	name_box->setPlaceholderText("Enter Your First Name");
	name_box->setStyleSheet("\
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
	name_box->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
	name_layout->addWidget(name_label);
	name_layout->addWidget(name_box);

	// Father Layout ( Father's Name )
	father_layout = new QHBoxLayout();
	father_label = new QLabel("Father's Name: ");
	father_label->setStyleSheet("\
		margin-left: 100px;\
		font: bold 22px;\
		border-radius: 4px;\
		color: #FFF;\
		");
	father_label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
	father_box = new QLineEdit();
	father_box->setMaxLength(14);
	// Set Style Sheet ( Father's Name Field )
	father_box->setPlaceholderText("Enter Your Last Name");
	father_box->setStyleSheet("\
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
	father_box->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
	father_layout->addWidget(father_label);
	father_layout->addWidget(father_box);

	// Date Layout ( Date of Birth )
	date_layout = new QHBoxLayout();
	date_label = new QLabel("Date of Birth: ");
	date_label->setStyleSheet("\
		margin-left: 100px;\
		font: bold 22px;\
		border-radius: 4px;\
		color: #FFF;\
		");
	date_label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
	dateOfBirth = new QDateEdit();
	dateOfBirth->setMinimumDate(QDate(1900, 1, 1));
	dateOfBirth->setMaximumDate(QDate::currentDate());
	dateOfBirth->setDate(QDate(2004, 1, 14));
	dateOfBirth->setDisplayFormat("dd/MM/yyyy");
	//dateOfBirth->setCalendarPopup(true);
	dateOfBirth->setLocale(QLocale::English);
	// Set Style Sheet ( Date Field )
	dateOfBirth->setStyleSheet("\
	         QDateEdit { \
				margin-right: 100px;\
				border: 1px solid #DDD;\
                font: 18px;\
				background: white;\
				border-radius: 4px;\
				}\
			 ");
	dateOfBirth->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
	date_layout->addWidget(date_label);
	date_layout->addWidget(dateOfBirth);

	// Gander Layout
	gander_layout = new QHBoxLayout();
	gander_label = new QLabel("Gander: ");
	gander_label->setStyleSheet("\
		margin-left: 100px;\
		font: bold 22px;\
		border-radius: 4px;\
		color: #FFF;\
		");
	gander_label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
	radio_male = new QRadioButton("Male");
	radio_female = new QRadioButton("Female");
	// Set Style Sheet ( Gander Radio Button )
	radio_female->setStyleSheet("\
				margin-right: 100px;\
                font: bold 18px;\
				background: transparent;\
				color: black;\
			 ");
	radio_male->setStyleSheet("\
				margin-right: 140px;\
				margin-left: 0px;\
                font: bold 18px;\
				background: transparent;\
				color: black;\
			 ");
	ganderGroup = new QButtonGroup();
	ganderGroup->addButton(radio_female);
	ganderGroup->addButton(radio_male);
	gander_layout->addWidget(gander_label);
	gander_layout->addWidget(radio_male);
	gander_layout->addWidget(radio_female);


	// Email Layout
	email_layout = new QHBoxLayout();
	email_label = new QLabel("Email Address: ");
	email_label->setStyleSheet("\
		margin-left: 100px;\
		font: bold 22px;\
		border-radius: 4px;\
		color: #FFF;\
		");
	email_label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
	email_box = new QLineEdit();
	// Set Style Sheet ( Father's Name Field )
	email_box->setPlaceholderText("Enter Your Email");
	email_box->setStyleSheet("\
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
	email_box->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
	email_layout->addWidget(email_label);
	email_layout->addWidget(email_box);

	// Status Layout
	status_layout = new QHBoxLayout();
	status_label = new QLabel("Marital Status: ");
	status_label->setStyleSheet("\
		margin-left: 100px;\
		font: bold 22px;\
		border-radius: 4px;\
		color: #FFF;\
		");
	status_label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
	radio_married = new QRadioButton("Married");
	radio_single = new QRadioButton("Single");
	radio_other = new QRadioButton("Other");
	// Set Style Sheet ( Gander Radio Button )
	radio_other->setStyleSheet("\
				margin-right: 100px;\
                font: bold 18px;\
				background: transparent;\
				color: black;\
			 ");
	radio_single->setStyleSheet("\
				margin-right: 20px;\
                font: bold 18px;\
				background: transparent;\
				color: black;\
			 ");
	radio_married->setStyleSheet("\
				margin-right: 30px;\
				margin-left: 0px;\
                font: bold 18px;\
				background: transparent;\
				color: black;\
			 ");
	maritalStatusGroup = new QButtonGroup();
	maritalStatusGroup->addButton(radio_married);
	maritalStatusGroup->addButton(radio_single);
	maritalStatusGroup->addButton(radio_other);
	status_layout->addWidget(status_label);
	status_layout->addWidget(radio_married);
	status_layout->addWidget(radio_single);
	status_layout->addWidget(radio_other);

	// Address Layout ( Address )
	address_layout = new QHBoxLayout();
	address_label = new QLabel("Address: ");
	address_label->setStyleSheet("\
		margin-left: 100px;\
		font: bold 22px;\
		border-radius: 4px;\
		color: #FFF;\
		");
	address_label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
	address_combo = new QComboBox();
	address_combo->setFixedWidth(500);
	address_combo->move(width() - 400, height() - 300);
	QStringList countries;
	countries << "Afghanistan" << "Albania" << "Algeria" << "Andorra" << "Angola"
		<< "Antigua and Barbuda" << "Argentina" << "Armenia" << "Australia" << "Austria"
		<< "Azerbaijan" << "Bahamas" << "Bahrain" << "Bangladesh" << "Barbados"
		<< "Belarus" << "Belgium" << "Belize" << "Benin" << "Bhutan"
		// Add more countries as needed
		<< "Bolivia" << "Bosnia and Herzegovina" << "Botswana" << "Brazil" << "Brunei"
		<< "Bulgaria" << "Burkina Faso" << "Burundi" << "Cabo Verde" << "Cambodia"
		<< "Cameroon" << "Canada" << "Central African Republic" << "Chad" << "Chile"
		<< "China" << "Colombia" << "Comoros" << "Congo" << "Costa Rica"
		// Add more countries as needed
		<< "Croatia" << "Cuba" << "Cyprus" << "Czech Republic" << "Denmark"
		<< "Djibouti" << "Dominica" << "Dominican Republic" << "Ecuador" << "Egypt"
		<< "El Salvador" << "Equatorial Guinea" << "Eritrea" << "Estonia" << "Eswatini"
		// Add more countries as needed
		<< "Ethiopia" << "Fiji" << "Finland" << "France" << "Gabon"
		<< "Gambia" << "Georgia" << "Germany" << "Ghana" << "Greece"
		<< "Grenada" << "Guatemala" << "Guinea" << "Guinea-Bissau" << "Guyana"
		// Add more countries as needed
		<< "Haiti" << "Honduras" << "Hungary" << "Iceland" << "India"
		<< "Indonesia" << "Iran" << "Iraq" << "Ireland" << "Israel"
		<< "Italy" << "Jamaica" << "Japan" << "Jordan" << "Kazakhstan"
		// Add more countries as needed
		<< "Kenya" << "Kiribati" << "Korea, North" << "Korea, South" << "Kosovo"
		<< "Kuwait" << "Kyrgyzstan" << "Laos" << "Latvia" << "Lebanon"
		<< "Lesotho" << "Liberia" << "Libya" << "Liechtenstein" << "Lithuania"
		// Add more countries as needed
		<< "Luxembourg" << "Madagascar" << "Malawi" << "Malaysia" << "Maldives"
		<< "Mali" << "Malta" << "Marshall Islands" << "Mauritania" << "Mauritius"
		<< "Mexico" << "Micronesia" << "Moldova" << "Monaco" << "Mongolia"
		// Add more countries as needed
		<< "Montenegro" << "Morocco" << "Mozambique" << "Myanmar" << "Namibia"
		<< "Nauru" << "Nepal" << "Netherlands" << "New Zealand" << "Nicaragua"
		<< "Niger" << "Nigeria" << "North Macedonia" << "Norway" << "Oman"
		// Add more countries as needed
		<< "Pakistan" << "Palau" << "Panama" << "Papua New Guinea" << "Paraguay"
		<< "Peru" << "Philippines" << "Poland" << "Portugal" << "Qatar"
		<< "Romania" << "Russia" << "Rwanda" << "Saint Kitts and Nevis" << "Saint Lucia"
		// Add more countries as needed
		<< "Saint Vincent and the Grenadines" << "Samoa" << "San Marino" << "Sao Tome and Principe"
		<< "Saudi Arabia" << "Senegal" << "Serbia" << "Seychelles" << "Sierra Leone"
		<< "Singapore" << "Slovakia" << "Slovenia" << "Solomon Islands" << "Somalia"
		// Add more countries as needed
		<< "South Africa" << "South Sudan" << "Spain" << "Sri Lanka" << "Sudan"
		<< "Suriname" << "Sweden" << "Switzerland" << "Syria" << "Taiwan"
		<< "Tajikistan" << "Tanzania" << "Thailand" << "Timor-Leste" << "Togo"
		// Add more countries as needed
		<< "Tonga" << "Trinidad and Tobago" << "Tunisia" << "Turkey" << "Turkmenistan"
		<< "Tuvalu" << "Uganda" << "Ukraine" << "United Arab Emirates" << "United Kingdom"
		<< "United States" << "Uruguay" << "Uzbekistan" << "Vanuatu" << "Vatican City"
		// Add more countries as needed
		<< "Venezuela" << "Vietnam" << "Yemen" << "Zambia" << "Zimbabwe";
	countries.sort();
	for (const QString& country : countries) {
		address_combo->addItem(country);
	}
	address_combo->setPlaceholderText("Enter Your Country");
	// Set Style Sheet ( Address Field )
	address_combo->setStyleSheet("\
	         QComboBox { \
				border: 1px solid #DDD;\
                font: 18px;\
				background: white;\
				border-radius: 4px;\
				padding: 0 8px;\
				}\
			 ");
	address_combo->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
	address_layout->addWidget(address_label);
	address_layout->addWidget(address_combo);



	// State Layout ( Address )
	state_layout = new QHBoxLayout();
	state_label = new QLabel("State: ");
	state_label->setStyleSheet("\
		margin-left: 100px;\
		font: bold 22px;\
		border-radius: 4px;\
		color: #FFF;\
		");
	state_label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
	state_combo = new QComboBox();
	state_combo->setFixedWidth(500);
	state_combo->move(width() - 400, height() - 300);
	// List Of Governorates In Egypt
	QStringList governorates;
	governorates << "Sharqia" << "Cairo" << "Alexandria" << "Red Sea" << "Beheira"
		<< "Beni Suef" << "Dakahlia" << "Damietta" << "Fayyum" << "Gharbia"
		<< "Giza" << "Ismailia" << "Kafr El Sheikh" << "Luxor" << "Matrouh"
		<< "Minya" << "Monufia" << "New Valley" << "North Sinai" << "South Sinai"
		<< "Qalyubia" << "Qena" << "Asyut" << "Aswan" << "Sohag" << "Suez"
		<< "Port Said";
	for (const QString& governorate : governorates) {
		state_combo->addItem(governorate);
	}
	// Set Style Sheet ( Address Field )
	state_combo->setPlaceholderText("Enter Your City");
	state_combo->setStyleSheet("\
	         QComboBox { \
				border: 1px solid #DDD;\
                font: 18px;\
				background: white;\
				border-radius: 4px;\
				padding: 0 8px;\
				}\
			 ");
	state_combo->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
	state_layout->addWidget(state_label);
	state_layout->addWidget(state_combo);





	// City Layout ( City )
	city_layout = new QHBoxLayout();
	city_label = new QLabel("City: ");
	city_label->setStyleSheet("\
		margin-left: 100px;\
		font: bold 22px;\
		border-radius: 4px;\
		color: #FFF;\
		");
	city_label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
	city_combo = new QComboBox();
	city_combo->setFixedWidth(500);
	city_combo->move(width() - 400, height() - 300);
	QStringList cities;
	cities << "Faqous" << "Zagazig" << "Bilbeis"
		<< "El Qassasin" << "El Qanayat" << "El Husseiniya"
		<< "Hihya" << "Abu Kebir" << "10th of Ramadan City"
		<< "Abu Hammad" << "Minya al-Qamh" << "Diyarb Negm"
		<< "Diyarb Negm" << "Awlad Saqr" << "El Ibrahimiya";
	city_combo->addItems(cities);
	// Set Style Sheet ( City Field );
	city_combo->setPlaceholderText("Enter Your City");
	city_combo->setStyleSheet("\
	         QComboBox { \
				border: 1px solid #DDD;\
                font: 18px;\
				background: white;\
				border-radius: 4px;\
				padding: 0 8px;\
				}\
			 ");
	city_combo->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
	city_layout->addWidget(city_label);
	city_layout->addWidget(city_combo);

	connect(state_combo, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &PageOne::cityChange);


	// back Button
	back_btn = new QPushButton("Back"); // Back Button
	//back_btn->setDisabled(true);
	// Set Style Sheet ( Next Button )
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
			}\
				");
	next_layout->addWidget(back_btn);
	next_layout->addWidget(next_btn);

	// Connection
	//connect(next_btn, &QPushButton::clicked, this, &PageOne::onPressedNextPageOne);

	//onPressedNextPageOne();

	main_layout->addLayout(title_layout); // Insert Title Layout
	main_layout->addSpacing(0);
	main_layout->addLayout(personal_layout); // Insert Personal Layout
	main_layout->addSpacing(20);
	main_layout->addLayout(name_layout); // Insert Name Layout
	main_layout->addSpacing(10);
	main_layout->addLayout(father_layout); // Insert Father's Name Layout
	main_layout->addSpacing(10);
	main_layout->addLayout(date_layout); // Insert Date of Birth Layout
	main_layout->addSpacing(10);
	main_layout->addLayout(gander_layout); // Insert Gander Layout
	main_layout->addSpacing(10);
	main_layout->addLayout(email_layout); // Insert Email Layout
	main_layout->addSpacing(10);
	main_layout->addLayout(status_layout); // Insert Status Layout
	main_layout->addSpacing(10);
	main_layout->addLayout(address_layout); // Insert Address Layout
	main_layout->addSpacing(10);
	main_layout->addLayout(state_layout); // Insert State Layout
	main_layout->addSpacing(10);
	main_layout->addLayout(city_layout); // Insert City Layout
	main_layout->addSpacing(30);
	main_layout->addLayout(next_layout); // Insert Next & Back Layout


}
PageOne::~PageOne()
{

}
// Function Implementation

// Next Button Function
void PageOne::onPressedNextPageOne()
{
	
}
void PageOne::cityChange(int index) {
 // Check if the selected country is "Egypt"
        if (index == 0) { // 1 corresponds to "Egypt"
            // List of states in Egypt
			QStringList sharqiaDistricts;
			sharqiaDistricts << "Faqous" << "Zagazig" << "Bilbeis"
				<< "El Qassasin" << "El Qanayat" << "El Husseiniya"
				<< "Hihya" << "Abu Kebir" << "10th of Ramadan City"
				<< "Abu Hammad" << "Minya al-Qamh" << "Diyarb Negm"
				<< "Diyarb Negm" << "Awlad Saqr" << "El Ibrahimiya";

			// Clear existing items and add the Egyptian states
			city_combo->clear();
			city_combo->addItems(sharqiaDistricts);
			//city_combo->addItem("test");
        } 
		if (index == 1) { // 1 corresponds to "Egypt"
            // List of states in Egypt
			QStringList cairoDistricts;
			cairoDistricts << "Maadi" << "Zamalek" << "Nasr City"
				<< "Heliopolis" << "Dokki" << "Mohandessin"
				<< "Giza" << "Sayeda Zeinab";

			// Clear existing items and add the Egyptian states
			city_combo->clear();
			city_combo->addItems(cairoDistricts);
			//city_combo->addItem("test");
        } 
		if (index == 2) { // 1 corresponds to "Egypt"
            // List of states in Egypt
			QStringList alexandriaDistricts;
			alexandriaDistricts << "Al-Montaza" << "Bahary" 
				<< "Sidi Gaber" << "Al-Ibrahimia" 
				<< "El-Mandara" << "Alexandria Downtown" 
				<< "El-Gomrok";

			// Clear existing items and add the Egyptian states
			city_combo->clear();
			city_combo->addItems(alexandriaDistricts);
			//city_combo->addItem("test");
        }
		if (index == 3) { // 1 corresponds to "Egypt"
            // List of states in Egypt
			QStringList redSeaDistricts;
			redSeaDistricts << "Hurghada" << "El Gouna"
				<< "Marsa Alam" << "Safaga" << "Quseir"
				<< "Ras Gharib";


			// Clear existing items and add the Egyptian states
			city_combo->clear();
			city_combo->addItems(redSeaDistricts);
			//city_combo->addItem("test");
        } 
    }
void PageOne::moveToPageTwoFun(PageTwo* partner)
{
		connect(next_btn, SIGNAL(clicked()), this, SLOT(hide()));
		connect(next_btn, SIGNAL(clicked()), partner, SLOT(show()));
}

/*
void PageOne::backToPageWelcomeFun(PageWelcome* partner)
{
	connect(back_btn, SIGNAL(clicked()), this, SLOT(hide()));
	connect(back_btn, SIGNAL(clicked()), partner, SLOT(show()));
}
*/
/*
void PageOne::moveToPageWelcomeFun(PageWelcome* partner)
{
	connect(back_btn, SIGNAL(clicked()), this, SLOT(hide()));
	connect(back_btn, SIGNAL(clicked()), partner, SLOT(show()));
}
*/






















/*

// Check The Name And Father's Name Field Is Not Empty
	if (!name_box->text().isEmpty()) // Check Name Field
	{
		qDebug() << "Name Field Is Not Empty.";
		if (!father_box->text().isEmpty()) // Check Father's Name
		{
			qDebug() << "Father's Name Field Is Not Empty.";
			///// Gander /////
			if (ganderGroup->checkedButton()) // Check Gander Radio Is Checked
			{
				if (radio_female->isChecked()) // Check Female is Checked
				{
					qDebug() << "The Female Radio Checked.";
				}
				if (radio_male->isChecked()) // Check Male is Checked
				{
					qDebug() << "The Male Radio Checked.";
				}
				/// Email Address ///
				if (!email_box->text().isEmpty())
				{
					qDebug() << "The Email Address Is Not Empty.";
					///// Status /////
					if (maritalStatusGroup->checkedButton()) // Check Status Radio Is Checked
					{
						if (radio_married->isChecked()) // Check Married is Checked
						{
							qDebug() << "The Married Radio Checked.";
						}
						if (radio_single->isChecked()) // Check Single is Checked
						{
							qDebug() << "The Single Radio Checked.";
						}
						if (radio_other->isChecked()) // Check Other is Checked
						{
							qDebug() << "The Other Radio Checked.";
						}
						/////// Here Submit Date ///////
						next_btn->setDisabled(false);
						isSubmit = true;

					} /// End Status Radio /
					else
					{
						QMessageBox::warning(this, "Invalid Status Field", "Please Chosse Your Status");
					}
				} /// End Email /
				else
				{
					QMessageBox::warning(this, "Invalid Email Field", "Please Enter Your Email");
				}
			} /// End Gander Radio /
			else
			{
				QMessageBox::warning(this, "Invalid Gander Field", "Please Chosse Your Gander");
			}
		} /// End Father's Name /
		else
		{
			QMessageBox::warning(this, "Invalid Father's Name Field", "Please Enter The Father's Name");
		}
	} /// End Name Field /
	else
	{
		QMessageBox::warning(this, "Invalid Name Field", "Please Enter The Name");
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

*/