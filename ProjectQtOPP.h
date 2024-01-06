#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ProjectQtOPP.h"

class ProjectQtOPP : public QMainWindow
{
    Q_OBJECT

public:
    ProjectQtOPP(QWidget *parent = nullptr);
    ~ProjectQtOPP();

private:
    Ui::ProjectQtOPPClass ui;
};
