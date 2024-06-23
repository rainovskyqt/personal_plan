#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "database/database.h"
#include "login/user.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_userBaseId{0}
    ,m_currentPlanId{0}
{
    ui->setupUi(this);

    ui->sw_pages->setCurrentIndex(Pages::Login);

    // // Database::get()->init("10.0.100.157", 8020);
    Database::get()->init("10.0.2.18", 3306);

    connect(ui->page_login, &LoginForm::enterToSystem,
            this, [&](User *user){
                if(user->baseId()){
                    ui->w_header->setUser(user);
                    ui->sw_pages->setCurrentIndex(Pages::TotalTime);
                    ui->w_header->init();
                } else {
                    QMessageBox::critical(this, "Ошибка аутинтефикации", "Введены неверные логин и пароль");
                }
            });

    connect(ui->w_header, &Header::currentPlanChanged, this, [&](TeacherPlan *plan){
        ui->tab_totalTime->setPlaneData(plan);
    });
    connect(ui->tab_totalTime, &FormTotalTime::modelDataChanged, ui->w_header, &Header::modelDataChanged);
    connect(ui->tab_totalTime, &FormTotalTime::savePlan, ui->w_header, &Header::savePlan);
    connect(ui->tab_totalTime, &FormTotalTime::rateChanged, ui->w_header, &Header::setRate);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::enterToSystem()
{
    ui->w_header->setVisible(true);
    ui->sw_pages->setCurrentIndex(Pages::TotalTime);
}
