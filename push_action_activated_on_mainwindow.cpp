#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::on_VLF_clicked()
{
    mainwindow_hide(ui);
    New_Filter.setting_parameters_for_calculation.Type_of_filter = 1;
    ui->A_L_dB->show();     ui->A_L_pr->show();     ui->A_L_z->show();  ui->F_pr->show();   ui->F_reg->show();  ui->GHz->show();
    ui->Centaral_freq->hide();
    ui->Hz->show();    ui->kHz->show();    ui->MHz->show();    ui->Zv->show();    ui->comboBox->show();    ui->label_2->show();    ui->label_3->show();    ui->label_4->show();
    ui->label_5->show();     ui->label_6->show();    ui->label_7->show();    ui->label_10->show();    ui->label_11->hide();    ui->label_13->hide();    ui->label_16->show();
    ui->label_17->show();    ui->label_18->hide();    ui->label_19->hide(); ui->pushButton->show(); ui->label_15->hide(); ui->label_20->hide(); ui->label_21->show();
    ui->Stockpile->show(); ui->label_22->hide(); ui->label_23->hide();
}


void MainWindow::on_VHF_clicked()
{
    mainwindow_hide(ui);
    New_Filter.setting_parameters_for_calculation.Type_of_filter = 2;
    ui->A_L_dB->show();     ui->A_L_pr->show();     ui->A_L_z->show();  ui->F_pr->show();   ui->F_reg->show();  ui->GHz->show();
    ui->Centaral_freq->hide();
    ui->Hz->show();    ui->kHz->show();    ui->MHz->show();    ui->Zv->show();    ui->comboBox->show();    ui->label_2->show();    ui->label_3->show();    ui->label_4->hide();
    ui->label_5->show();     ui->label_6->show();    ui->label_7->show();    ui->label_10->show();    ui->label_11->hide();    ui->label_13->hide();    ui->label_16->hide();
    ui->label_17->show();    ui->label_18->hide();    ui->label_19->hide(); ui->pushButton->show(); ui->label_15->show(); ui->label_20->show();ui->label_21->show();
    ui->Stockpile->show(); ui->label_22->hide(); ui->label_23->hide();

}


void MainWindow::on_REG_clicked()
{
    mainwindow_hide(ui);
    New_Filter.setting_parameters_for_calculation.Type_of_filter = 3;
    ui->A_L_dB->show();     ui->A_L_pr->show();     ui->A_L_z->show();  ui->F_pr->show();   ui->F_reg->show();  ui->GHz->show();
    ui->Centaral_freq->show();
    ui->Hz->show();    ui->kHz->show();    ui->MHz->show();    ui->Zv->show();    ui->comboBox->show();    ui->label_2->show();    ui->label_3->show();    ui->label_4->hide();
    ui->label_5->show();     ui->label_6->show();    ui->label_7->show();    ui->label_10->show();    ui->label_11->hide();    ui->label_13->hide();    ui->label_16->hide();
    ui->label_17->show();    ui->label_18->show();    ui->label_19->show(); ui->pushButton->show(); ui->label_15->hide(); ui->label_20->hide();ui->label_21->show();
    ui->Stockpile->show(); ui->label_22->show(); ui->label_23->show();
}


void MainWindow::on_BPF_clicked()
{
    mainwindow_hide(ui);
    New_Filter.setting_parameters_for_calculation.Type_of_filter = 4;
    ui->A_L_dB->show();     ui->A_L_pr->show();     ui->A_L_z->show();  ui->F_pr->show();   ui->F_reg->show();  ui->GHz->show();
    ui->Centaral_freq->show();
    ui->Hz->show();    ui->kHz->show();    ui->MHz->show();    ui->Zv->show();    ui->comboBox->show();    ui->label_2->show();    ui->label_3->show();    ui->label_4->hide();
    ui->label_5->show();     ui->label_6->show();    ui->label_7->show();    ui->label_10->show();    ui->label_11->show();    ui->label_13->show();    ui->label_16->hide();
    ui->label_17->show();    ui->label_18->show();    ui->label_19->show(); ui->pushButton->show(); ui->label_15->hide(); ui->label_20->hide();ui->label_21->show();
    ui->Stockpile->show(); ui->label_22->hide(); ui->label_23->hide();
}

void MainWindow::on_action_2_triggered()
{
    qApp->quit();
}

void MainWindow::on_Hz_clicked()
{
    ui->label_5->setText("Гц");
    ui->label_18->setText("Гц");
    ui->label_17->setText("Гц");
    New_Filter.setting_parameters_for_calculation.Frequency_multiplier = pow(10, 0);
}


void MainWindow::on_kHz_clicked()
{
    ui->label_5->setText("кГц");
    ui->label_18->setText("кГц");
    ui->label_17->setText("кГц");
    New_Filter.setting_parameters_for_calculation.Frequency_multiplier = pow(10, 3);
}


void MainWindow::on_MHz_clicked()
{
    ui->label_5->setText("МГц");
    ui->label_18->setText("МГц");
    ui->label_17->setText("МГц");
    New_Filter.setting_parameters_for_calculation.Frequency_multiplier = pow(10, 6);
}


void MainWindow::on_GHz_clicked()
{
    ui->label_5->setText("ГГц");
    ui->label_18->setText("ГГц");
    ui->label_17->setText("ГГц");
    New_Filter.setting_parameters_for_calculation.Frequency_multiplier = pow(10, 9);
}


void MainWindow::on_pushButton_clicked()
{
    Reading_frequency_and_attenuation_level(ui, New_Filter);
    New_Filter.The_elements_in_the_prototype_filter();
    form = new filter_table;
    form->show();
    connect(this, &MainWindow::signal, form, &filter_table::slot);
    connect(this, &MainWindow::signal_trunsport, form, &filter_table::slot_trunsport);
    emit signal_trunsport(New_Filter);
}

void MainWindow::Reading_frequency_and_attenuation_level(Ui::MainWindow * ui, Calculation_of_the_filter_on_distributed_elements &New_Filter){

    New_Filter.setting_parameters_for_calculation.Attenuation_level_in_the_area_of_attenuation = ui->A_L_z->toPlainText().toDouble();
    New_Filter.setting_parameters_for_calculation.Attenuation_level_at_the_transmission_boundary = ui->A_L_pr->toPlainText().toDouble();
    New_Filter.setting_parameters_for_calculation.Filter_pass_frequency = ui->F_pr->toPlainText().toDouble();
    New_Filter.setting_parameters_for_calculation.Filter_cut_off_frequency = ui->F_reg->toPlainText().toDouble();
    New_Filter.setting_parameters_for_calculation.Path_resistance = ui->Zv->toPlainText().toDouble();
    New_Filter.setting_parameters_for_calculation.Central_Freq = ui->Centaral_freq->toPlainText().toDouble();
    New_Filter.setting_parameters_for_calculation.Stockpile = ui->Stockpile->toPlainText().toInt();
    if (ui->A_L_dB->isChecked())
    {
        New_Filter.setting_parameters_for_calculation.Attenuation_level_in_the_area_of_attenuation_Bool_dB = true;
    }
    if (ui->A_L_dB->isChecked())
    {
        New_Filter.setting_parameters_for_calculation.Attenuation_level_at_the_transmission_boundary_Bool_dB = true;
    }
    ;
    if(ui->comboBox->currentText().toStdString() == "Чебышев")
    {
        New_Filter.setting_parameters_for_calculation.Type_of_approximation = 1;
    }
    else {
        New_Filter.setting_parameters_for_calculation.Type_of_approximation = 2;
    }
    if(ui->comboBox_2->currentText().toStdString() == "Симметричная МПЛ")
    {
        MPL_calc.type_of_MPL = 1;
        MPL_calc.Settings.b = ui->textEdit_2->toPlainText().toDouble();
    }
    else {
        MPL_calc.type_of_MPL = 2;
        MPL_calc.Settings.h = ui->textEdit_2->toPlainText().toDouble();
    }

    MPL_calc.Settings.Er = ui->textEdit->toPlainText().toDouble();
    MPL_calc.Settings.t = ui->textEdit_3->toPlainText().toDouble();

    New_Filter.MPL_calcul = MPL_calc;
}

void MainWindow::on_action_triggered()
{
    go_to_mainwindow(ui);
}

void MainWindow::closeEvent(QCloseEvent *e)
{
    emit signal();
}

void MainWindow::on_action_3_triggered()
{
    form_mpl = new MPL;
    form_mpl->show();
    connect(this, &MainWindow::signal, form_mpl, &MPL::slot);
}


void MainWindow::on_SVCH_VLF_clicked()
{
    mainwindow_hide(ui);
    New_Filter.setting_parameters_for_calculation.Type_of_filter = 5;
    ui->A_L_dB->show();     ui->A_L_pr->show();     ui->A_L_z->show();  ui->F_pr->show();   ui->F_reg->show();  ui->GHz->show();
    ui->Centaral_freq->hide();
    ui->Hz->show();    ui->kHz->show();    ui->MHz->show();    ui->Zv->show();    ui->comboBox->show();    ui->label_2->show();    ui->label_3->show();    ui->label_4->show();
    ui->label_5->show();     ui->label_6->show();    ui->label_7->show();    ui->label_10->show();    ui->label_11->hide();    ui->label_13->hide();    ui->label_16->show();
    ui->label_17->show();    ui->label_18->hide();    ui->label_19->hide(); ui->pushButton->show(); ui->label_22->hide(); ui->label_23->hide();



    ui->label_14->show();   ui->comboBox_2->show(); ui->textEdit->show();
    ui->textEdit_2->show(); ui->textEdit_3->show(); ui->label_12->show(); ui->label_8->show(); ui->label_9->show();
}


void MainWindow::on_BPF_SV_clicked()
{
    mainwindow_hide(ui);
    New_Filter.setting_parameters_for_calculation.Type_of_filter = 6;
    ui->A_L_dB->show();     ui->A_L_pr->show();     ui->A_L_z->show();  ui->F_pr->show();   ui->F_reg->show();  ui->GHz->show();
    ui->Centaral_freq->show();
    ui->Hz->show();    ui->kHz->show();    ui->MHz->show();    ui->Zv->show();    ui->comboBox->show();    ui->label_2->show();    ui->label_3->show();    ui->label_4->hide();
    ui->label_5->show();     ui->label_6->show();    ui->label_7->show();    ui->label_10->show();    ui->label_11->show();    ui->label_13->show();    ui->label_16->hide();
    ui->label_17->show();    ui->label_18->show();    ui->label_19->show(); ui->pushButton->show(); ui->label_22->hide(); ui->label_23->hide();

    ui->label_14->show();   ui->comboBox_2->show(); ui->textEdit->show();
    ui->textEdit_2->show(); ui->textEdit_3->show(); ui->label_12->show(); ui->label_8->show(); ui->label_9->show();
}


void MainWindow::on_BPF_4_L_clicked()
{
    mainwindow_hide(ui);
    New_Filter.setting_parameters_for_calculation.Type_of_filter = 7;
    ui->A_L_dB->show();     ui->A_L_pr->show();     ui->A_L_z->show();  ui->F_pr->show();   ui->F_reg->show();  ui->GHz->show();
    ui->Centaral_freq->show();
    ui->Hz->show();    ui->kHz->show();    ui->MHz->show();    ui->Zv->show();    ui->comboBox->show();    ui->label_2->show();    ui->label_3->show();    ui->label_4->hide();
    ui->label_5->show();     ui->label_6->show();    ui->label_7->show();    ui->label_10->show();    ui->label_11->show();    ui->label_13->show();    ui->label_16->hide();
    ui->label_17->show();    ui->label_18->show();    ui->label_19->show(); ui->pushButton->show(); ui->label_22->hide(); ui->label_23->hide();
    ui->label_14->show();   ui->comboBox_2->show(); ui->textEdit->show();
    ui->textEdit_2->show(); ui->textEdit_3->show(); ui->label_12->show(); ui->label_8->show(); ui->label_9->show();


}


void MainWindow::on_BPF_2_L_clicked()
{
    mainwindow_hide(ui);
    New_Filter.setting_parameters_for_calculation.Type_of_filter = 8;
    ui->A_L_dB->show();     ui->A_L_pr->show();     ui->A_L_z->show();  ui->F_pr->show();   ui->F_reg->show();  ui->GHz->show();
    ui->Centaral_freq->show();
    ui->Hz->show();    ui->kHz->show();    ui->MHz->show();    ui->Zv->show();    ui->comboBox->show();    ui->label_2->show();    ui->label_3->show();    ui->label_4->hide();
    ui->label_5->show();     ui->label_6->show();    ui->label_7->show();    ui->label_10->show();    ui->label_11->show();    ui->label_13->show();    ui->label_16->hide();
    ui->label_17->show();    ui->label_18->show();    ui->label_19->show(); ui->pushButton->show(); ui->label_22->hide(); ui->label_23->hide();
    ui->label_14->show();   ui->comboBox_2->show(); ui->textEdit->show();
    ui->textEdit_2->show(); ui->textEdit_3->show(); ui->label_12->show(); ui->label_8->show(); ui->label_9->show();

}
