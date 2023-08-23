#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QKeyEvent>
//#include "../../header.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_calculate_clicked();
    void entersign();
    void on_clear_all_clicked();
    void on_clear_sign_clicked();
    void keyPressEvent(QKeyEvent* event) override;
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
