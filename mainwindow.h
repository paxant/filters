#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <analogue_filters.h>
#include <filter_table.h>
#include <mpl.h>
#include <mpl_calculation.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Calculation_of_the_filter_on_distributed_elements New_Filter;
    MPL_Calculation MPL_calc;

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void go_to_mainwindow(Ui::MainWindow * ui);
    void mainwindow_hide(Ui::MainWindow * ui);
    Ui::MainWindow *ui;
    void Reading_frequency_and_attenuation_level(Ui::MainWindow * ui, Calculation_of_the_filter_on_distributed_elements &New_Filter);

private slots:
    void on_VLF_clicked();

    void on_VHF_clicked();

    void on_REG_clicked();

    void on_BPF_clicked();

    void on_action_2_triggered();

    void on_Hz_clicked();

    void on_kHz_clicked();

    void on_MHz_clicked();

    void on_GHz_clicked();

    void on_pushButton_clicked();

    void on_action_triggered();

    void on_action_3_triggered();

    void on_SVCH_VLF_clicked();

    void on_BPF_SV_clicked();

    void on_BPF_4_L_clicked();

    void on_BPF_2_L_clicked();

private:
    filter_table *form;
    MPL *form_mpl;

signals:
    void signal();
    void signal_trunsport(Calculation_of_the_filter_on_distributed_elements &filter);

protected:
    void closeEvent(QCloseEvent *e);
};
#endif // MAINWINDOW_H
