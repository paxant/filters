#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QDebug>
#include<math.h>
#include <QCloseEvent>

void MainWindow::go_to_mainwindow(Ui::MainWindow * ui){
    ui->A_L_dB->hide();     ui->A_L_pr->hide();     ui->A_L_z->hide();     ui->Centaral_freq->hide();     ui->F_pr->hide();    ui->F_reg->hide();     ui->GHz->hide();
    ui->Hz->hide();    ui->kHz->hide();    ui->MHz->hide();    ui->Zv->hide();    ui->comboBox->hide();    ui->label_2->hide();    ui->label_3->hide();    ui->label_4->hide();
    ui->label_5->hide();     ui->label_6->hide();    ui->label_7->hide();    ui->label_10->hide();    ui->label_11->hide();    ui->label_13->hide();    ui->label_16->hide();
    ui->label_17->hide();    ui->label_18->hide();    ui->label_19->hide(); ui->pushButton->hide(); ui->label_14->hide();   ui->comboBox_2->hide(); ui->textEdit->hide();
    ui->textEdit_2->hide(); ui->textEdit_3->hide(); ui->label_12->hide(); ui->label_8->hide(); ui->label_9->hide(); ui->label_15->hide(); ui->label_20->hide();  ui->label_21->hide();
    ui->Stockpile->hide(); ui->label_22->hide(); ui->label_23->hide();

    ui->label->show();
    ui->VLF->show();
    ui->VHF->show();
    ui->BPF->show();
    ui->REG->show();
    ui->BPF_2_L->show();
    ui->BPF_4_L->show();
    ui->BPF_SV->show();
    ui->SVCH_VLF->show();
}

void MainWindow::mainwindow_hide(Ui::MainWindow * ui){
    ui->label->hide();
    ui->VLF->hide();
    ui->VHF->hide();
    ui->BPF->hide();
    ui->REG->hide();
    ui->BPF_2_L->hide();
    ui->BPF_4_L->hide();
    ui->BPF_SV->hide();
    ui->SVCH_VLF->hide();
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Расчет фильтров");

    ui->VLF->setIcon(QIcon("C:\\Users\\pov\\Desktop\\Culc_FIlt\\icon\\VLF_icon.png"));
    ui->VLF->setIconSize(QSize(200, 200));

    ui->VHF->setIcon(QIcon("C:\\Users\\pov\\Desktop\\Culc_FIlt\\icon\\VHF_icon.png"));
    ui->VHF->setIconSize(QSize(200, 200));

    ui->BPF->setIcon(QIcon("C:\\Users\\pov\\Desktop\\Culc_FIlt\\icon\\BPF_icon.png"));
    ui->BPF->setIconSize(QSize(200, 200));

    ui->REG->setIcon(QIcon("C:\\Users\\pov\\Desktop\\Culc_FIlt\\icon\\REG_icon.png"));
    ui->REG->setIconSize(QSize(200, 200));

    ui->SVCH_VLF->setIcon(QIcon("C:\\Users\\pov\\Desktop\\Culc_FIlt\\icon\\VLF_MPL_icon.png"));
    ui->SVCH_VLF->setIconSize(QSize(200, 200));

    ui->BPF_SV->setIcon(QIcon("C:\\Users\\pov\\Desktop\\Culc_FIlt\\icon\\BPF_SVL_icon.png"));
    ui->BPF_SV->setIconSize(QSize(200, 200));

    ui->BPF_4_L->setIcon(QIcon("C:\\Users\\pov\\Desktop\\Culc_FIlt\\icon\\BPF_4L_icon.png"));
    ui->BPF_4_L->setIconSize(QSize(200, 200));

    ui->BPF_2_L->setIcon(QIcon("C:\\Users\\pov\\Desktop\\Culc_FIlt\\icon\\BPF_2L_icon.png"));
    ui->BPF_2_L->setIconSize(QSize(200, 200));

    go_to_mainwindow(ui);

}


MainWindow::~MainWindow()
{
    delete ui;
}

