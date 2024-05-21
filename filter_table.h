#ifndef FILTER_TABLE_H
#define FILTER_TABLE_H

#include <QWidget>
#include <analogue_filters.h>\

namespace Ui {
class filter_table;
}

class filter_table : public QWidget
{
    Q_OBJECT

public:
    explicit filter_table(QWidget *parent = nullptr);
    ~filter_table();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::filter_table *ui;
    Calculation_of_the_filter_on_distributed_elements filter_;

public slots:
    void slot();
    void slot_trunsport(Calculation_of_the_filter_on_distributed_elements  &filter);
};

#endif // FILTER_TABLE_H
