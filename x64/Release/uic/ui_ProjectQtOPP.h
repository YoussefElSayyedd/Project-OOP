/********************************************************************************
** Form generated from reading UI file 'ProjectQtOPP.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROJECTQTOPP_H
#define UI_PROJECTQTOPP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProjectQtOPPClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ProjectQtOPPClass)
    {
        if (ProjectQtOPPClass->objectName().isEmpty())
            ProjectQtOPPClass->setObjectName("ProjectQtOPPClass");
        ProjectQtOPPClass->resize(600, 400);
        menuBar = new QMenuBar(ProjectQtOPPClass);
        menuBar->setObjectName("menuBar");
        ProjectQtOPPClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ProjectQtOPPClass);
        mainToolBar->setObjectName("mainToolBar");
        ProjectQtOPPClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(ProjectQtOPPClass);
        centralWidget->setObjectName("centralWidget");
        ProjectQtOPPClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ProjectQtOPPClass);
        statusBar->setObjectName("statusBar");
        ProjectQtOPPClass->setStatusBar(statusBar);

        retranslateUi(ProjectQtOPPClass);

        QMetaObject::connectSlotsByName(ProjectQtOPPClass);
    } // setupUi

    void retranslateUi(QMainWindow *ProjectQtOPPClass)
    {
        ProjectQtOPPClass->setWindowTitle(QCoreApplication::translate("ProjectQtOPPClass", "ProjectQtOPP", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProjectQtOPPClass: public Ui_ProjectQtOPPClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJECTQTOPP_H
