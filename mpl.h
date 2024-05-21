#ifndef MPL_H
#define MPL_H

#include <QWidget>
#include <mpl_calculation.h>

namespace Ui {
class MPL;
}

class MPL : public QWidget
{
    Q_OBJECT

public:
    explicit MPL(QWidget *parent = nullptr);
    ~MPL();

private slots:
    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_4_clicked();

    void on_radioButton_3_clicked();

    void on_pushButton_clicked();

private:
    Ui::MPL *ui;
    MPL_Calculation MPL_Calcul;

public slots:
    void slot();
};

#endif // MPL_H
