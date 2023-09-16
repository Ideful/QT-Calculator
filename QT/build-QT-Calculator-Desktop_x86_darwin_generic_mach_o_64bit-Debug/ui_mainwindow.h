/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *zero;
    QPushButton *one;
    QPushButton *two;
    QPushButton *nine;
    QPushButton *eight;
    QPushButton *seven;
    QPushButton *six;
    QPushButton *five;
    QPushButton *four;
    QPushButton *three;
    QPushButton *minus;
    QPushButton *plus;
    QPushButton *multiply;
    QPushButton *divide;
    QPushButton *log10;
    QPushButton *logn;
    QPushButton *sin;
    QPushButton *atan;
    QPushButton *cos;
    QPushButton *cl_br;
    QPushButton *asin;
    QPushButton *tan;
    QPushButton *op_br;
    QPushButton *sqrt;
    QPushButton *acos;
    QLineEdit *CalcString;
    QPushButton *dot;
    QPushButton *calculate;
    QPushButton *pow;
    QPushButton *clear_all;
    QPushButton *clear_sign;
    QLabel *label;
    QLineEdit *x_val;
    QPushButton *mod;
    QPushButton *xbut;
    QLabel *xmin;
    QLabel *xmax;
    QLabel *ymin;
    QLabel *ymax;
    QLineEdit *xminval;
    QLineEdit *xmaxval;
    QLineEdit *yminval;
    QLineEdit *ymaxval;
    QPushButton *makegraph;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(438, 514);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        zero = new QPushButton(centralwidget);
        zero->setObjectName(QString::fromUtf8("zero"));
        zero->setGeometry(QRect(110, 210, 31, 31));
        zero->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 214, 229); \n"
"border: 1px solid black;\n"
"border-radius: 8px;"));
        one = new QPushButton(centralwidget);
        one->setObjectName(QString::fromUtf8("one"));
        one->setGeometry(QRect(70, 90, 31, 31));
        one->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 214, 229); \n"
"border: 1px solid black;\n"
"border-radius: 8px;"));
        two = new QPushButton(centralwidget);
        two->setObjectName(QString::fromUtf8("two"));
        two->setGeometry(QRect(110, 90, 31, 31));
        two->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 214, 229); \n"
"border: 1px solid black;\n"
"border-radius: 8px;"));
        nine = new QPushButton(centralwidget);
        nine->setObjectName(QString::fromUtf8("nine"));
        nine->setGeometry(QRect(150, 170, 31, 31));
        nine->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 214, 229); \n"
"border: 1px solid black;\n"
"border-radius: 8px;"));
        eight = new QPushButton(centralwidget);
        eight->setObjectName(QString::fromUtf8("eight"));
        eight->setGeometry(QRect(110, 170, 31, 31));
        eight->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 214, 229); \n"
"border: 1px solid black;\n"
"border-radius: 8px;"));
        seven = new QPushButton(centralwidget);
        seven->setObjectName(QString::fromUtf8("seven"));
        seven->setGeometry(QRect(70, 170, 31, 31));
        seven->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 214, 229); \n"
"border: 1px solid black;\n"
"border-radius: 8px;"));
        six = new QPushButton(centralwidget);
        six->setObjectName(QString::fromUtf8("six"));
        six->setGeometry(QRect(150, 130, 31, 31));
        six->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 214, 229); \n"
"border: 1px solid black;\n"
"border-radius: 8px;"));
        five = new QPushButton(centralwidget);
        five->setObjectName(QString::fromUtf8("five"));
        five->setGeometry(QRect(110, 130, 31, 31));
        five->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 214, 229); \n"
"border: 1px solid black;\n"
"border-radius: 8px;"));
        four = new QPushButton(centralwidget);
        four->setObjectName(QString::fromUtf8("four"));
        four->setGeometry(QRect(70, 130, 31, 31));
        four->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 214, 229); \n"
"border: 1px solid black;\n"
"border-radius: 8px;"));
        three = new QPushButton(centralwidget);
        three->setObjectName(QString::fromUtf8("three"));
        three->setGeometry(QRect(150, 90, 31, 31));
        three->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 214, 229); \n"
"border: 1px solid black;\n"
"border-radius: 8px;"));
        minus = new QPushButton(centralwidget);
        minus->setObjectName(QString::fromUtf8("minus"));
        minus->setGeometry(QRect(250, 90, 31, 31));
        minus->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 214, 229); \n"
"border: 1px solid black;\n"
"border-radius: 8px;"));
        plus = new QPushButton(centralwidget);
        plus->setObjectName(QString::fromUtf8("plus"));
        plus->setGeometry(QRect(210, 90, 31, 31));
        plus->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 214, 229); \n"
"border: 1px solid black;\n"
"border-radius: 8px;"));
        multiply = new QPushButton(centralwidget);
        multiply->setObjectName(QString::fromUtf8("multiply"));
        multiply->setGeometry(QRect(290, 90, 31, 31));
        multiply->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 214, 229); \n"
"border: 1px solid black;\n"
"border-radius: 8px;"));
        divide = new QPushButton(centralwidget);
        divide->setObjectName(QString::fromUtf8("divide"));
        divide->setGeometry(QRect(330, 90, 31, 31));
        divide->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 214, 229); \n"
"border: 1px solid black;\n"
"border-radius: 8px;"));
        log10 = new QPushButton(centralwidget);
        log10->setObjectName(QString::fromUtf8("log10"));
        log10->setGeometry(QRect(290, 130, 31, 31));
        log10->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 214, 229); \n"
"border: 1px solid black;\n"
"border-radius: 8px;"));
        logn = new QPushButton(centralwidget);
        logn->setObjectName(QString::fromUtf8("logn"));
        logn->setGeometry(QRect(330, 130, 31, 31));
        logn->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 214, 229); \n"
"border: 1px solid black;\n"
"border-radius: 8px;"));
        sin = new QPushButton(centralwidget);
        sin->setObjectName(QString::fromUtf8("sin"));
        sin->setGeometry(QRect(210, 170, 42, 31));
        sin->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 214, 229); \n"
"border: 1px solid black;\n"
"border-radius: 8px;"));
        atan = new QPushButton(centralwidget);
        atan->setObjectName(QString::fromUtf8("atan"));
        atan->setGeometry(QRect(320, 210, 42, 31));
        atan->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 214, 229); \n"
"border: 1px solid black;\n"
"border-radius: 8px;"));
        cos = new QPushButton(centralwidget);
        cos->setObjectName(QString::fromUtf8("cos"));
        cos->setGeometry(QRect(265, 170, 42, 31));
        cos->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 214, 229); \n"
"border: 1px solid black;\n"
"border-radius: 8px;"));
        cl_br = new QPushButton(centralwidget);
        cl_br->setObjectName(QString::fromUtf8("cl_br"));
        cl_br->setGeometry(QRect(110, 250, 31, 31));
        cl_br->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 214, 229); \n"
"border: 1px solid black;\n"
"border-radius: 8px;"));
        asin = new QPushButton(centralwidget);
        asin->setObjectName(QString::fromUtf8("asin"));
        asin->setGeometry(QRect(210, 210, 42, 31));
        asin->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 214, 229); \n"
"border: 1px solid black;\n"
"border-radius: 8px;"));
        tan = new QPushButton(centralwidget);
        tan->setObjectName(QString::fromUtf8("tan"));
        tan->setGeometry(QRect(320, 170, 42, 31));
        tan->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 214, 229); \n"
"border: 1px solid black;\n"
"border-radius: 8px;"));
        op_br = new QPushButton(centralwidget);
        op_br->setObjectName(QString::fromUtf8("op_br"));
        op_br->setGeometry(QRect(70, 250, 31, 31));
        op_br->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 214, 229); \n"
"border: 1px solid black;\n"
"border-radius: 8px;"));
        sqrt = new QPushButton(centralwidget);
        sqrt->setObjectName(QString::fromUtf8("sqrt"));
        sqrt->setGeometry(QRect(250, 130, 31, 31));
        sqrt->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 214, 229); \n"
"border: 1px solid black;\n"
"border-radius: 8px;"));
        acos = new QPushButton(centralwidget);
        acos->setObjectName(QString::fromUtf8("acos"));
        acos->setGeometry(QRect(265, 210, 42, 31));
        acos->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 214, 229); \n"
"border: 1px solid black;\n"
"border-radius: 8px;"));
        CalcString = new QLineEdit(centralwidget);
        CalcString->setObjectName(QString::fromUtf8("CalcString"));
        CalcString->setGeometry(QRect(70, 20, 291, 31));
        CalcString->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
"border-radius: 8px;"));
        dot = new QPushButton(centralwidget);
        dot->setObjectName(QString::fromUtf8("dot"));
        dot->setGeometry(QRect(70, 210, 31, 31));
        dot->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 214, 229); \n"
"border: 1px solid black;\n"
"border-radius: 8px;"));
        dot->setIconSize(QSize(16, 8));
        calculate = new QPushButton(centralwidget);
        calculate->setObjectName(QString::fromUtf8("calculate"));
        calculate->setGeometry(QRect(150, 210, 31, 31));
        calculate->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 119, 182); \n"
"border: 1px solid black;\n"
"border-radius: 8px;"));
        calculate->setIconSize(QSize(16, 8));
        pow = new QPushButton(centralwidget);
        pow->setObjectName(QString::fromUtf8("pow"));
        pow->setGeometry(QRect(210, 130, 31, 31));
        pow->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 214, 229); \n"
"border: 1px solid black;\n"
"border-radius: 8px;"));
        clear_all = new QPushButton(centralwidget);
        clear_all->setObjectName(QString::fromUtf8("clear_all"));
        clear_all->setGeometry(QRect(150, 250, 31, 31));
        clear_all->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 214, 229); \n"
"border: 1px solid black;\n"
"border-radius: 8px;"));
        clear_sign = new QPushButton(centralwidget);
        clear_sign->setObjectName(QString::fromUtf8("clear_sign"));
        clear_sign->setGeometry(QRect(210, 250, 31, 31));
        clear_sign->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 214, 229); \n"
"border: 1px solid black;\n"
"border-radius: 8px;"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(195, 290, 41, 31));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 119, 182); \n"
"border: 1px solid black;\n"
"border-radius: 8px;"));
        label->setAlignment(Qt::AlignCenter);
        x_val = new QLineEdit(centralwidget);
        x_val->setObjectName(QString::fromUtf8("x_val"));
        x_val->setGeometry(QRect(195, 330, 41, 31));
        x_val->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 119, 182); \n"
"border: 1px solid black;\n"
"border-radius: 8px;"));
        mod = new QPushButton(centralwidget);
        mod->setObjectName(QString::fromUtf8("mod"));
        mod->setGeometry(QRect(330, 250, 31, 31));
        mod->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 214, 229); \n"
"border: 1px solid black;\n"
"border-radius: 8px;"));
        xbut = new QPushButton(centralwidget);
        xbut->setObjectName(QString::fromUtf8("xbut"));
        xbut->setGeometry(QRect(270, 250, 31, 31));
        xbut->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 214, 229); \n"
"border: 1px solid black;\n"
"border-radius: 8px;"));
        xmin = new QLabel(centralwidget);
        xmin->setObjectName(QString::fromUtf8("xmin"));
        xmin->setGeometry(QRect(70, 290, 41, 31));
        xmin->setStyleSheet(QString::fromUtf8("background-color: rgb(72, 202, 228); \n"
"border: 1px solid black;\n"
"border-radius: 8px;"));
        xmin->setAlignment(Qt::AlignCenter);
        xmax = new QLabel(centralwidget);
        xmax->setObjectName(QString::fromUtf8("xmax"));
        xmax->setGeometry(QRect(130, 290, 41, 31));
        xmax->setStyleSheet(QString::fromUtf8("background-color: rgb(72, 202, 228); \n"
"border: 1px solid black;\n"
"border-radius: 8px;"));
        xmax->setAlignment(Qt::AlignCenter);
        ymin = new QLabel(centralwidget);
        ymin->setObjectName(QString::fromUtf8("ymin"));
        ymin->setGeometry(QRect(255, 290, 41, 31));
        ymin->setStyleSheet(QString::fromUtf8("background-color: rgb(72, 202, 228); \n"
"border: 1px solid black;\n"
"border-radius: 8px;"));
        ymin->setAlignment(Qt::AlignCenter);
        ymax = new QLabel(centralwidget);
        ymax->setObjectName(QString::fromUtf8("ymax"));
        ymax->setGeometry(QRect(320, 290, 41, 31));
        ymax->setStyleSheet(QString::fromUtf8("background-color: rgb(72, 202, 228); \n"
"border: 1px solid black;\n"
"border-radius: 8px;"));
        ymax->setAlignment(Qt::AlignCenter);
        xminval = new QLineEdit(centralwidget);
        xminval->setObjectName(QString::fromUtf8("xminval"));
        xminval->setGeometry(QRect(70, 330, 41, 31));
        xminval->setStyleSheet(QString::fromUtf8("background-color: rgb(72, 202, 228); \n"
"border: 1px solid black;\n"
"border-radius: 8px;"));
        xmaxval = new QLineEdit(centralwidget);
        xmaxval->setObjectName(QString::fromUtf8("xmaxval"));
        xmaxval->setGeometry(QRect(130, 330, 41, 31));
        xmaxval->setStyleSheet(QString::fromUtf8("background-color: rgb(72, 202, 228); \n"
"border: 1px solid black;\n"
"border-radius: 8px;"));
        yminval = new QLineEdit(centralwidget);
        yminval->setObjectName(QString::fromUtf8("yminval"));
        yminval->setGeometry(QRect(255, 330, 41, 31));
        yminval->setStyleSheet(QString::fromUtf8("background-color: rgb(72, 202, 228); \n"
"border: 1px solid black;\n"
"border-radius: 8px;"));
        ymaxval = new QLineEdit(centralwidget);
        ymaxval->setObjectName(QString::fromUtf8("ymaxval"));
        ymaxval->setGeometry(QRect(320, 330, 41, 31));
        ymaxval->setStyleSheet(QString::fromUtf8("background-color: rgb(72, 202, 228); \n"
"border: 1px solid black;\n"
"border-radius: 8px;"));
        makegraph = new QPushButton(centralwidget);
        makegraph->setObjectName(QString::fromUtf8("makegraph"));
        makegraph->setGeometry(QRect(170, 380, 100, 32));
        makegraph->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 119, 182); \n"
"border: 1px solid black;\n"
"border-radius: 8px;"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 438, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        zero->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        one->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        two->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        nine->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        eight->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        seven->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        six->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        five->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        four->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        three->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        minus->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        plus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        multiply->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        divide->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        log10->setText(QCoreApplication::translate("MainWindow", "log", nullptr));
        logn->setText(QCoreApplication::translate("MainWindow", "ln", nullptr));
        sin->setText(QCoreApplication::translate("MainWindow", "sin", nullptr));
        atan->setText(QCoreApplication::translate("MainWindow", "atan", nullptr));
        cos->setText(QCoreApplication::translate("MainWindow", "cos", nullptr));
        cl_br->setText(QCoreApplication::translate("MainWindow", ")", nullptr));
        asin->setText(QCoreApplication::translate("MainWindow", "asin", nullptr));
        tan->setText(QCoreApplication::translate("MainWindow", "tan", nullptr));
        op_br->setText(QCoreApplication::translate("MainWindow", "(", nullptr));
        sqrt->setText(QCoreApplication::translate("MainWindow", "sqrt", nullptr));
        acos->setText(QCoreApplication::translate("MainWindow", "acos", nullptr));
        dot->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        calculate->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        pow->setText(QCoreApplication::translate("MainWindow", "^", nullptr));
        clear_all->setText(QCoreApplication::translate("MainWindow", "AC", nullptr));
        clear_sign->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "x\n"
" value", nullptr));
        mod->setText(QCoreApplication::translate("MainWindow", "mod", nullptr));
        xbut->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
        xmin->setText(QCoreApplication::translate("MainWindow", "xmin", nullptr));
        xmax->setText(QCoreApplication::translate("MainWindow", "xmax", nullptr));
        ymin->setText(QCoreApplication::translate("MainWindow", "ymin", nullptr));
        ymax->setText(QCoreApplication::translate("MainWindow", "ymax", nullptr));
        makegraph->setText(QCoreApplication::translate("MainWindow", "graph", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
