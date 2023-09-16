#include "graphique.h"
#include "ui_graphique.h"

graphique::graphique(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::graphique)
{
    ui->setupUi(this);
    setFixedSize(800,400);
}

graphique::~graphique()
{
    delete ui;
}

void graphique::make_graph(std::string& str, std::vector<double>& edgesval) {
    ui->graphwidget->xAxis->setRange(edgesval[0],edgesval[1]);
    ui->graphwidget->yAxis->setRange(edgesval[2],edgesval[3]);
    if (ui->graphwidget->graph()) {
        for(int i = 0; i < graphcounter; i++) {
            ui->graphwidget->graph(i)->data()->clear();
        }
        ui->graphwidget->replot();
    }
    std::vector<double> x;
    std::vector<double> y;
    double i = edgesval[0];
    while (i <= edgesval[1]) {
        if(!x.empty()) x.clear();
        if(!y.empty()) y.clear();
        controller_.MakeGraph(x,y,edgesval,str,i);
        ui->graphwidget->addGraph();
        graphcounter++;
        ui->graphwidget->graph()->addData(
            QVector<double>(x.begin(), x.end()),
            QVector<double>(y.begin(), y.end())
        );
        ui->graphwidget->replot();
    }
}
