#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#define step 80000

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
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
    std::string xval = ui->x_val->text().toUtf8().data();
    std::pair<std::string,double> qwe = Graphique.controller_.GetRes(str,xval);
    if (qwe.first != "")  QMessageBox::warning(this,"error", QString::fromStdString(qwe.first));
    else {
        QString res = QString::number(qwe.second);
        ui->CalcString->setText(res);
    }
}


void MainWindow::on_makegraph_clicked()
{
     std::string str = ui->CalcString->text().toUtf8().data();
     if (!Graphique.controller_.CheckIfInputStringIsOk(str)) QMessageBox::warning(this,"error","wrong input");
     else {
         std::vector<std::string> edges;
         edges.push_back(ui->xminval->text().toUtf8().data());
         edges.push_back(ui->xmaxval->text().toUtf8().data());
         edges.push_back(ui->yminval->text().toUtf8().data());
         edges.push_back(ui->ymaxval->text().toUtf8().data());

         std::vector<double> edgesval;
         edgesval.push_back(0);
         edgesval.push_back(5);
         edgesval.push_back(0);
         edgesval.push_back(5);

        std::vector<std::string> validator = Graphique.controller_.ValidateGraphEdges(edgesval,edges);
        if (validator.size()) {
            for(size_t i = 0; i < validator.size(); i++) {
                QMessageBox::warning(this,"error",QString::fromStdString(validator[i]));
            }
        }
        if (validator.size() == 0) {
            Graphique.make_graph(str,edgesval);
            Graphique.show();
        }
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







