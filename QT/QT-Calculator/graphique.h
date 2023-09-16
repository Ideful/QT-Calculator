#ifndef GRAPHIQUE_H
#define GRAPHIQUE_H

#include <QMainWindow>
#include "../../Controller.h"


namespace Ui {
class graphique;
}

class graphique : public QMainWindow
{
    Q_OBJECT

public:
    explicit graphique(QWidget *parent = nullptr);
    ~graphique();
    void make_graph(std::string& str, std::vector<double>& edgesval);
    Controller controller_;
private:
    Ui::graphique *ui;
    int graphcounter = 0;
};

#endif // GRAPHIQUE_H
