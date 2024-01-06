// Here Default Header File
#include <QtWidgets/QApplication>
#include <iostream>
#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QListWidget>


// Here User_Defined Header File
#include "ProjectQtOPP.h"
#include "PageWelcome.h"
#include "PageOne.h"
#include "PageTwo.h"
#include "Credit.h"
#include "Atm.h"

// Here MySQL
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>

const string server = "tcp://127.0.0.1:3306";
const string username = "root";
const string password = "";

int main(int argc, char* argv[])
{
    // Here Connection MySQL
    sql::Driver* driver;
    sql::Connection* con;
    sql::Statement* stmt;
    sql::PreparedStatement* pstmt;
    sql::ResultSet* res;

    try
    {
        driver = get_driver_instance();
        con = driver->connect(server, username, password);

        stmt = con->createStatement();
        stmt->execute("CREATE DATABASE IF NOT EXISTS qt_project;");

        if (con->isValid())
        {
            // Connection successful, perform database operations
            // For example, execute a simple query
            stmt->execute("USE qt_project;");
            stmt->execute("CREATE TABLE tableTest;");
            // Here My Queries


            delete stmt;
        }
        else
        {
            // Handle invalid connection case
            throw runtime_error("Invalid connection!");
        }
        delete con; // Close the connection when done
    }
    catch (sql::SQLException& e)
    {
        // Handle SQL exception (MySQL errors)
        qDebug() << "SQL Exception: " << e.what();  // qDebug() = cout 
    }
    catch (runtime_error& e)
    {
        // Handle general runtime errors
        cout << "Runtime Error: " << e.what();
    }
    // End SQL

    QApplication a(argc, argv);
    ProjectQtOPP w;

    PageWelcome pwelcome;
    PageOne pone;
    PageTwo ptwo;

    Credit credit;

    Atm atm;

    pwelcome.moveToPageOneFun(&pone);
    pone.moveToPageTwoFun(&ptwo);
    ptwo.moveToCredit(&credit);
    credit.moveToAtmFun(&atm);
    pwelcome.show();

    return a.exec();
}
