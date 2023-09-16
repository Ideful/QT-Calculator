/********************************************************************************
** Form generated from reading UI file 'graphique.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHIQUE_H
#define UI_GRAPHIQUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_graphique
{
public:
    QWidget *centralwidget;
    QCustomPlot *graphwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *graphique)
    {
        if (graphique->objectName().isEmpty())
            graphique->setObjectName(QString::fromUtf8("graphique"));
        graphique->resize(569, 355);
        centralwidget = new QWidget(graphique);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphwidget = new QCustomPlot(centralwidget);
        graphwidget->setObjectName(QString::fromUtf8("graphwidget"));
        graphwidget->setGeometry(QRect(10, 10, 531, 271));
        graphique->setCentralWidget(centralwidget);
        menubar = new QMenuBar(graphique);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 569, 24));
        graphique->setMenuBar(menubar);
        statusbar = new QStatusBar(graphique);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        graphique->setStatusBar(statusbar);

        retranslateUi(graphique);

        QMetaObject::connectSlotsByName(graphique);
    } // setupUi

    void retranslateUi(QMainWindow *graphique)
    {
        graphique->setWindowTitle(QCoreApplication::translate("graphique", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class graphique: public Ui_graphique {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHIQUE_H
