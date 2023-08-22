#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../../header.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->zero,SIGNAL(clicked()),this,SLOT(entersign()));
    connect(ui->one,SIGNAL(clicked()),this,SLOT(entersign()));
    connect(ui->two,SIGNAL(clicked()),this,SLOT(entersign()));
    connect(ui->three,SIGNAL(clicked()),this,SLOT(entersign()));
    connect(ui->four,SIGNAL(clicked()),this,SLOT(entersign()));
    connect(ui->five,SIGNAL(clicked()),this,SLOT(entersign()));
    connect(ui->six,SIGNAL(clicked()),this,SLOT(entersign()));
    connect(ui->seven,SIGNAL(clicked()),this,SLOT(entersign()));
    connect(ui->eight,SIGNAL(clicked()),this,SLOT(entersign()));
    connect(ui->nine,SIGNAL(clicked()),this,SLOT(entersign()));
    connect(ui->asin,SIGNAL(clicked()),this,SLOT(entersign()));
    connect(ui->acos,SIGNAL(clicked()),this,SLOT(entersign()));
    connect(ui->atan,SIGNAL(clicked()),this,SLOT(entersign()));
    connect(ui->sin,SIGNAL(clicked()),this,SLOT(entersign()));
    connect(ui->cos,SIGNAL(clicked()),this,SLOT(entersign()));
    connect(ui->tan,SIGNAL(clicked()),this,SLOT(entersign()));
    connect(ui->plus,SIGNAL(clicked()),this,SLOT(entersign()));
    connect(ui->minus,SIGNAL(clicked()),this,SLOT(entersign()));
    connect(ui->multiply,SIGNAL(clicked()),this,SLOT(entersign()));
    connect(ui->divide,SIGNAL(clicked()),this,SLOT(entersign()));
    connect(ui->sqrt,SIGNAL(clicked()),this,SLOT(entersign()));
    connect(ui->pow,SIGNAL(clicked()),this,SLOT(entersign()));
    connect(ui->mod,SIGNAL(clicked()),this,SLOT(entersign()));
    connect(ui->log10,SIGNAL(clicked()),this,SLOT(entersign()));
    connect(ui->logn,SIGNAL(clicked()),this,SLOT(entersign()));
    connect(ui->op_br,SIGNAL(clicked()),this,SLOT(entersign()));
    connect(ui->cl_br,SIGNAL(clicked()),this,SLOT(entersign()));
//    connect(ui->x,SIGNAL(clicked()),this,SLOT(entersign()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_calculate_clicked()
{
//    QByteArray expression = ui->CalcString->text().toUtf8();
    std::string str = ui->CalcString->text().toUtf8().data();
    if (Errorchecker(str) == false) QMessageBox::warning(this,"error","wrong input");
    else {
        if (ui->x_val->text() == "") {
            QString res = QString::number(Calculator(str));
            ui->CalcString->setText(res);
        } else {
            std::string xval = ui->CalcString->text().toUtf8().data();
            if (XIsDouble(xval) == false) QMessageBox::warning(this,"error","wrong X input");
            else {
                QString res = QString::number(Calculator(str));
                ui->CalcString->setText(res);
            }
        }
    }
}

void MainWindow::entersign(){
    QPushButton * button_clicked = (QPushButton *)sender();
    QString syms = ui->CalcString->text() + button_clicked->text();
    if (sender() == ui->tan || sender() == ui->sin || sender() == ui->cos || sender() == ui->atan || sender() == ui->asin || sender() == ui->acos || sender() == ui->logn  || sender() == ui->log10  || sender() == ui->sqrt) syms = syms + "(";
    ui->CalcString->setText(syms);

}
