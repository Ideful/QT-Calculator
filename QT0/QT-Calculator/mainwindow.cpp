#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#define step 80000

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
    connect(ui->xbut,SIGNAL(clicked()),this,SLOT(entersign()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_calculate_clicked()
{
    std::string str = ui->CalcString->text().toUtf8().data();
    controller_.InitString(str);
    if (controller_.model_.CheckForErrors() == false) QMessageBox::warning(this,"error","wrong input");
    else {
        if (controller_.model_.StringContainsX() == false) {
            QString res = QString::number(controller_.GetRes());
            ui->CalcString->setText(res);
        } else {
            std::string xval = ui->x_val->text().toUtf8().data();
            if (ui->x_val->text() == "" || controller_.model_.XValueValidator(xval) == false) QMessageBox::warning(this,"error","wrong X input");
            else {
                controller_.model_.SetXValue(ui->x_val->text().toDouble());
                QString res = QString::number(controller_.GetRes());
                ui->CalcString->setText(res);
            }
        }
    }
}


void MainWindow::on_makegraph_clicked()
{
    std::string str = ui->CalcString->text().toUtf8().data();
    controller_.InitString(str);
    if (ui->CalcString->text() == "" || controller_.model_.CheckForErrors() == false) QMessageBox::warning(this,"error","wrong input");
    else {
        QVector<double>x,y;
        std::string xminstr = ui->xminval->text().toUtf8().data();
        std::string xmaxstr = ui->xmaxval->text().toUtf8().data();
        std::string yminstr = ui->yminval->text().toUtf8().data();
        std::string ymaxstr = ui->ymaxval->text().toUtf8().data();
        double xminval = 0;
        double xmaxval = 5;
        double yminval = 0;
        double ymaxval = 5;
        if (xminstr != "") {
            if (controller_.model_.IsDouble(xminstr)) xminval = ui->xminval->text().toDouble();
            else QMessageBox::warning(this,"error","wrong XMin input");
        }
        if (xmaxstr != "") {
            if (controller_.model_.IsDouble(xmaxstr)) xmaxval = ui->xmaxval->text().toDouble();
            else QMessageBox::warning(this,"error","wrong XMax input");
        }
        if (yminstr != "") {
            if (controller_.model_.IsDouble(yminstr)) yminval = ui->yminval->text().toDouble();
            else QMessageBox::warning(this,"error","wrong YMin input");
        }
        if (ymaxstr != "") {
            if (controller_.model_.IsDouble(ymaxstr)) ymaxval = ui->ymaxval->text().toDouble();
            else QMessageBox::warning(this,"error","wrong XMin input");
        }
        ui->graphwidget->xAxis->setRange(xminval,xmaxval);
        ui->graphwidget->yAxis->setRange(yminval,ymaxval);
        if(ui->graphwidget->graph()) {
            ui->graphwidget->graph()->data()->clear();
            ui->graphwidget->replot();
        }

        for(double i = xminval, yval = 0, prevyval = 0;i <= xmaxval;i+=(xmaxval-xminval)/step) {
            std::string calcstr = ui->CalcString->text().toUtf8().data();
            controller_.InitString(calcstr);
            controller_.model_.SetXValue(i);
            yval = controller_.GetRes();
            if (yval - prevyval < -1000) {
                ui->graphwidget->addGraph();
                ui->graphwidget->graph()->addData(x,y);
                x.clear();
                y.clear();
            } else {
                x.push_back(i);
                y.push_back(yval);
            }
            prevyval = yval;
        }
        ui->graphwidget->addGraph();
        ui->graphwidget->graph()->addData(x,y);
        ui->graphwidget->replot();
        x.clear();
        y.clear();
    }

}

void MainWindow::entersign(){
    QPushButton * button_clicked = (QPushButton *)sender();
    QString syms = ui->CalcString->text() + button_clicked->text();
    if (sender() == ui->tan || sender() == ui->sin || sender() == ui->cos || sender() == ui->atan || sender() == ui->asin || sender() == ui->acos || sender() == ui->logn  || sender() == ui->log10  || sender() == ui->sqrt) syms = syms + "(";
    ui->CalcString->setText(syms);

}

void MainWindow::on_clear_all_clicked()
{
    ui->CalcString->setText("");
}


void MainWindow::on_clear_sign_clicked()
{
    QString shorty = ui->CalcString->text();
    shorty.chop(1);
    ui->CalcString->setText(shorty);
}

void MainWindow::keyPressEvent(QKeyEvent* event) {
    if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return) on_calculate_clicked();
    if (event->key() == Qt::Key_Escape) on_makegraph_clicked();
    else QMainWindow::keyPressEvent(event);
}







