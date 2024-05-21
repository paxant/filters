#include "mpl.h"
#include "ui_mpl.h"
#include <mpl_calculation.h>

int MPL_Type = 0;

MPL::MPL(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MPL)
{
    ui->setupUi(this);
    setWindowTitle("Расчет МПЛ передачи");
    ui->MPL_SIMM->hide();
    ui->MPL_NO_SIMM->hide();
    ui->SV_MPL_SIMM->hide();
    ui->SV_MPL_NO_SIMM->hide();
    ui->label->hide();
    ui->textEdit_4->hide();
    ui->label_6->hide();
    ui->textEdit_5->hide();
    ui->label_9->hide();
    ui->label_8->hide();
    ui->textEdit_6->hide();
    ui->textEdit_7->hide();
    ui->label_10->hide();
    ui->label_11->hide();
    ui->textEdit_8->hide();
    ui->textEdit_9->hide();
}

MPL::~MPL()
{
    delete ui;
}

void MPL::slot()
{
    close();
}

void MPL::on_radioButton_clicked()
{
    MPL_Type = 1;
    ui->MPL_NO_SIMM->show();
    ui->MPL_SIMM->hide();
    ui->SV_MPL_SIMM->hide();
    ui->SV_MPL_NO_SIMM->hide();
    QImage image;
    if (image.load("C:\\Users\\pov\\Desktop\\Culc_FIlt\\icon\\MPL_NO_SIMM_.png")) {
        image = image.scaledToWidth(ui->MPL_NO_SIMM->width(), Qt::SmoothTransformation);
        ui->MPL_NO_SIMM->setPixmap(QPixmap::fromImage(image));
    }
    ui->label->show();
    ui->textEdit_4->show();
    ui->label_6->hide();
    ui->textEdit_5->hide();
    ui->textEdit_6->hide();
    ui->textEdit_7->hide();
    ui->label_9->hide();
    ui->label_8->hide();
    ui->textEdit_6->hide();
    ui->textEdit_7->hide();
    ui->label_10->hide();
    ui->label_11->hide();
    ui->textEdit_8->hide();
    ui->textEdit_9->hide();
}

void MPL::on_radioButton_2_clicked()
{
    MPL_Type = 2;
    ui->MPL_SIMM->show();
    ui->MPL_NO_SIMM->hide();
    ui->SV_MPL_SIMM->hide();
    ui->SV_MPL_NO_SIMM->hide();
    QImage image;
    if (image.load("C:\\Users\\pov\\Desktop\\Culc_FIlt\\icon\\MPL_SIMM.png")) {
        image = image.scaledToWidth(ui->MPL_SIMM->width(), Qt::SmoothTransformation);
        ui->MPL_SIMM->setPixmap(QPixmap::fromImage(image));
    }
    ui->label->hide();
    ui->textEdit_4->hide();
    ui->label_6->show();
    ui->textEdit_5->show();
    ui->textEdit_6->hide();
    ui->textEdit_7->hide();
    ui->label_9->hide();
    ui->label_8->hide();
    ui->textEdit_6->hide();
    ui->textEdit_7->hide();
    ui->label_10->hide();
    ui->label_11->hide();
    ui->textEdit_8->hide();
    ui->textEdit_9->hide();
}

void MPL::on_radioButton_4_clicked()
{
    MPL_Type = 3;
    ui->MPL_SIMM->hide();
    ui->MPL_NO_SIMM->hide();
    ui->SV_MPL_SIMM->hide();
    ui->SV_MPL_NO_SIMM->show();
    QImage image;
    if (image.load("C:\\Users\\pov\\Desktop\\Culc_FIlt\\icon\\S_MPL_NO_SIMM.png")) {
        image = image.scaledToWidth(ui->SV_MPL_NO_SIMM->width(), Qt::SmoothTransformation);
        ui->SV_MPL_NO_SIMM->setPixmap(QPixmap::fromImage(image));
    }
    ui->label->hide();
    ui->textEdit_4->hide();
    ui->label_6->hide();
    ui->textEdit_5->hide();
    ui->label_9->hide();
    ui->label_8->hide();
    ui->textEdit_6->hide();
    ui->textEdit_7->hide();
    ui->label_10->show();
    ui->label_11->show();
    ui->textEdit_8->show();
    ui->textEdit_9->show();
}

void MPL::on_radioButton_3_clicked()
{
    MPL_Type = 4;
    ui->MPL_SIMM->hide();
    ui->MPL_NO_SIMM->hide();
    ui->SV_MPL_SIMM->show();
    ui->SV_MPL_NO_SIMM->hide();
    QImage image;
    if (image.load("C:\\Users\\pov\\Desktop\\Culc_FIlt\\icon\\S_MPL_SIMM.png")) {
        image = image.scaledToWidth(ui->SV_MPL_SIMM->width(), Qt::SmoothTransformation);
        ui->SV_MPL_SIMM->setPixmap(QPixmap::fromImage(image));
    }
    ui->label->hide();
    ui->textEdit_4->hide();
    ui->label_6->hide();
    ui->textEdit_5->hide();
    ui->label_9->show();
    ui->label_8->show();
    ui->textEdit_6->show();
    ui->textEdit_7->show();
    ui->label_10->hide();
    ui->label_11->hide();
    ui->textEdit_8->hide();
    ui->textEdit_9->hide();
}

void MPL::on_pushButton_clicked()
{
    MPL_Calcul.Settings.Er = ui->textEdit->toPlainText().toDouble();
    MPL_Calcul.Settings.t = ui->textEdit_3->toPlainText().toDouble();
    switch (MPL_Type) {
    case 1:
        MPL_Calcul.Settings.Zv = ui->textEdit_4->toPlainText().toDouble();
        MPL_Calcul.Settings.h = ui->textEdit_2->toPlainText().toDouble();
        MPL_Calcul.Calculation_of_asymmetrical_microstrip_transmission_line();
        ui->label_5->setText("w = " + QString::number(MPL_Calcul.Results.w) + "\n"
                             + "Eeff = " + QString::number(MPL_Calcul.Results.Eeff));
        break;
    case 2:
        MPL_Calcul.Settings.Zv = ui->textEdit_5->toPlainText().toDouble();
        MPL_Calcul.Settings.b = ui->textEdit_2->toPlainText().toDouble();
        MPL_Calcul.Calculation_of_symmetrical_microstrip_transmission_line();
        ui->label_5->setText("w = " + QString::number(MPL_Calcul.Results.w) + "\n");
        break;
    case 3:
        MPL_Calcul.Settings.h = ui->textEdit_2->toPlainText().toDouble();
        MPL_Calcul.Settings.Zve = ui->textEdit_8->toPlainText().toDouble();
        MPL_Calcul.Settings.Zvo = ui->textEdit_9->toPlainText().toDouble();
        MPL_Calcul.Calculation_of_coupled_asymmetric_microstrip_transmission_line();
        break;
    case 4:
        MPL_Calcul.Settings.b = ui->textEdit_2->toPlainText().toDouble();
        MPL_Calcul.Settings.Zve = ui->textEdit_6->toPlainText().toDouble();
        MPL_Calcul.Settings.Zvo = ui->textEdit_7->toPlainText().toDouble();
        MPL_Calcul.Calculation_of_coupled_symmetrical_microstrip_transmission_line();
        ui->label_5->setText("w = " + QString::number(MPL_Calcul.Results.w) + "\n"
                             + "s = " + QString::number(MPL_Calcul.Results.s));
        break;
    default:
        break;
    }
}
