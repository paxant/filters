#include "filter_table.h"
#include "ui_filter_table.h"
//#include <QtGui>
#include <QFileDialog>
filter_table::filter_table(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::filter_table)
{
    ui->setupUi(this);
    setWindowTitle("Результат расчета");

}
//Здесь сделать передачу структуры в функцию и вывести рассчитанные значения в таблицу.
filter_table::~filter_table()
{
    delete ui;
}

void filter_table::on_pushButton_clicked()
{
    close();
}

void filter_table::slot()
{
    close();
}


void filter_table::slot_trunsport(Calculation_of_the_filter_on_distributed_elements &filter)
{
    filter_ = filter;
    ui->tableWidget->setRowCount(2);

    QString dB = "";
    if(filter.setting_parameters_for_calculation.Attenuation_level_at_the_transmission_boundary_Bool_dB == true)
        dB = "дБ";
    else
        dB = "";
    QString Type_of_approximation;
    if(filter.setting_parameters_for_calculation.Type_of_approximation == 1)
    {
        Type_of_approximation = "фильтр Чебышева";
    }
    else
    {
        Type_of_approximation = "фильтр Баттерворта";
    }
    if(filter.setting_parameters_for_calculation.Type_of_filter == 5 || filter.setting_parameters_for_calculation.Type_of_filter == 6)
        ui->tableWidget->setColumnCount(filter_.Prototipe->Number_of_elements_in_the_prototype_filter+2);
    else
        ui->tableWidget->setColumnCount(filter_.Prototipe->Number_of_elements_in_the_prototype_filter);
    switch (filter.setting_parameters_for_calculation.Type_of_filter) {
    case 1:
    {
        ui->tableWidget->setVerticalHeaderLabels(QStringList() << "C" << "L");
        for(int j = 0; j < filter_.Prototipe->Number_of_elements_in_the_prototype_filter ; j++)
        {
            for(int i = 0; i < 2; i++)
            {
                QTableWidgetItem *tbl = new QTableWidgetItem(QString::number(filter_.Prototipe->Elements_of_filter[j+1][i]));
                //double uj = filter_.Prototipe->Elements_of_filter[j+1][i];
                ui->tableWidget->setItem(i, j, tbl);
                tbl->setBackground(Qt::gray);
            }
        }
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        QImage image;
        image.load("C:\\Users\\pov\\Desktop\\Culc_FIlt\\icon\\LC_VLF_P.png");
        QPixmap pixmap = QPixmap::fromImage(image);
        pixmap = pixmap.scaled(QSize(1000, 1000), Qt::KeepAspectRatio);
        ui->Image->setPixmap(pixmap);
        image.load("C:\\Users\\pov\\Desktop\\Culc_FIlt\\icon\\VLF_AFR.png");
        pixmap = QPixmap::fromImage(image);
        pixmap = pixmap.scaled(QSize(400, 400), Qt::KeepAspectRatio);
        ui->ACHH->setPixmap(pixmap);
        ui->INFO->setText("Общая информация. \n\tПорядок фильтра: " + QString::number(filter.Prototipe->Number_of_elements_in_the_prototype_filter) + "\n\t "
                                                                                                                                                      "Частота среза: " + QString::number(filter.setting_parameters_for_calculation.Filter_pass_frequency*filter.setting_parameters_for_calculation.Frequency_multiplier) + " Гц;" + "\n\t"
                                                                                                                                                                                         "Частота Заграждения: " + QString::number(filter.setting_parameters_for_calculation.Filter_cut_off_frequency*filter.setting_parameters_for_calculation.Frequency_multiplier) + " Гц;" + "\n\t"
                                                                                                                                                                                            "Затухание в полосе пропускания: " + QString::number(filter.setting_parameters_for_calculation.Attenuation_level_at_the_transmission_boundary) + " " + dB + "\n\t"
                                                                                                                                                   "Затухание в полосе заграждения: " + QString::number(filter.setting_parameters_for_calculation.Attenuation_level_in_the_area_of_attenuation) + " " + dB + "\n\t"
                                                                                                                                                 "Сопротивление тракта: " + QString::number(filter.setting_parameters_for_calculation.Path_resistance) + " Ом" + "\n\t"
                                                                                                                 "Тип аппроксимации: " + Type_of_approximation + "."
                                                    "\n*Расчет фильтра верен только для идеальных элементов фильтра. В реальном исполнении фильтры получат немного более худшие характеристики, из-за чего придется их донастраивать. "
                                                    "\n Для Выполнении ТЗ по затуханию в полосе заграждения при задании требований к расчету, необходимо поставить запас по порядку фильтра, отличный от нуля "
                                                    "\n В случае не выполнения ТЗ по частоте среза или полосе пропускания, выполните перерасчет фильтра с чуть другими параметрами");
    }
        break;
    case 2:
    {
        ui->tableWidget->setVerticalHeaderLabels(QStringList() << "C" << "L");
        for(int j = 0; j < filter_.Prototipe->Number_of_elements_in_the_prototype_filter ; j++)
        {
            for(int i = 0; i < 2; i++)
            {
                QTableWidgetItem *tbl = new QTableWidgetItem(QString::number(filter_.Prototipe->Elements_of_filter[j+1][i]));
                //double uj = filter_.Prototipe->Elements_of_filter[j+1][i];
                ui->tableWidget->setItem(i, j, tbl);
                tbl->setBackground(Qt::gray);
            }
        }
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        QImage image;
        image.load("C:\\Users\\pov\\Desktop\\Culc_FIlt\\icon\\LC_VHF_P.png");
        QPixmap pixmap = QPixmap::fromImage(image);
        pixmap = pixmap.scaled(QSize(1000, 1000), Qt::KeepAspectRatio);
        ui->Image->setPixmap(pixmap);
        image.load("C:\\Users\\pov\\Desktop\\Culc_FIlt\\icon\\VHF_AFR.png");
        pixmap = QPixmap::fromImage(image);
        pixmap = pixmap.scaled(QSize(400, 400), Qt::KeepAspectRatio);
        ui->ACHH->setPixmap(pixmap);

        ui->INFO->setText("Общая информация. \n\tПорядок фильтра: " + QString::number(filter.Prototipe->Number_of_elements_in_the_prototype_filter) + "\n\t "
                                                                                                                                                      "Частота заграждения: " + QString::number(filter.setting_parameters_for_calculation.Filter_pass_frequency*filter.setting_parameters_for_calculation.Frequency_multiplier) + " Гц;" + "\n\t"
                                                                                                                                                                                         "Частота среза: " + QString::number(filter.setting_parameters_for_calculation.Filter_cut_off_frequency*filter.setting_parameters_for_calculation.Frequency_multiplier) + " Гц;" + "\n\t"
                                                                                                                                                                                            "Затухание в полосе пропускания: " + QString::number(filter.setting_parameters_for_calculation.Attenuation_level_at_the_transmission_boundary) + " " + dB + "\n\t"
                                                                                                                                                   "Затухание в полосе заграждения: " + QString::number(filter.setting_parameters_for_calculation.Attenuation_level_in_the_area_of_attenuation) + " " + dB + "\n\t"
                                                                                                                                                 "Сопротивление тракта: " + QString::number(filter.setting_parameters_for_calculation.Path_resistance) + " Ом" + "\n\t"
                                                                                                                 "Тип аппроксимации: " + Type_of_approximation + "."
                                                    "\n*Расчет фильтра верен только для идеальных элементов фильтра. В реальном исполнении фильтры получат немного более худшие характеристики, из-за чего придется их донастраивать. "
                                                    "\n Для Выполнении ТЗ по затуханию в полосе заграждения при задании требований к расчету, необходимо поставить запас по порядку фильтра, отличный от нуля "
                                                    "\n В случае не выполнения ТЗ по частоте среза или полосе пропускания, выполните перерасчет фильтра с чуть другими параметрами");
    }
        break;
    case 4:
    {
         ui->tableWidget->setVerticalHeaderLabels(QStringList() << "C" << "L");
        for(int j = 0; j < filter_.Prototipe->Number_of_elements_in_the_prototype_filter ; j++)
        {
            for(int i = 0; i < 2; i++)
            {
                QTableWidgetItem *tbl = new QTableWidgetItem(QString::number(filter_.Prototipe->Elements_of_filter[j+1][i]));
                //double uj = filter_.Prototipe->Elements_of_filter[j+1][i];
                ui->tableWidget->setItem(i, j, tbl);
                tbl->setBackground(Qt::gray);
            }
        }
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        QImage image;
        image.load("C:\\Users\\pov\\Desktop\\Culc_FIlt\\icon\\LC_BPF_P.png");
        QPixmap pixmap = QPixmap::fromImage(image);
        pixmap = pixmap.scaled(QSize(1000, 1000), Qt::KeepAspectRatio);
        ui->Image->setPixmap(pixmap);
        image.load("C:\\Users\\pov\\Desktop\\Culc_FIlt\\icon\\BPF_AFR.png");
        pixmap = QPixmap::fromImage(image);
        pixmap = pixmap.scaled(QSize(400, 400), Qt::KeepAspectRatio);
        ui->ACHH->setPixmap(pixmap);

        ui->INFO->setText("Общая информация. \n\tПорядок фильтра: " + QString::number(filter.Prototipe->Number_of_elements_in_the_prototype_filter) + "\n\t "
                                                                                                                                                      "Полоса пропускания: " + QString::number(filter.setting_parameters_for_calculation.Filter_pass_frequency*filter.setting_parameters_for_calculation.Frequency_multiplier) + " Гц;" + "\n\t"
                                                                                                                                                                                         "Полоса заграждения: " + QString::number(filter.setting_parameters_for_calculation.Filter_cut_off_frequency*filter.setting_parameters_for_calculation.Frequency_multiplier) + " Гц;" + "\n\t"
                                                                                                                                                                                            "Затухание в полосе пропускания: " + QString::number(filter.setting_parameters_for_calculation.Attenuation_level_at_the_transmission_boundary) + " " + dB + "\n\t"
                                                                                                                                                   "Затухание в полосе заграждения: " + QString::number(filter.setting_parameters_for_calculation.Attenuation_level_in_the_area_of_attenuation) + " " + dB + "\n\t"
                                                                                                                                                 "Сопротивление тракта: " + QString::number(filter.setting_parameters_for_calculation.Path_resistance) + " Ом" + "\n\t"
                                                                                                                 "Тип аппроксимации: " + Type_of_approximation + "."
                                                    "\n*Расчет фильтра верен только для идеальных элементов фильтра. В реальном исполнении фильтры получат немного более худшие характеристики, из-за чего придется их донастраивать. "
                                                    "\n Для Выполнении ТЗ по затуханию в полосе заграждения при задании требований к расчету, необходимо поставить запас по порядку фильтра, отличный от нуля "
                                                    "\n В случае не выполнения ТЗ по частоте среза или полосе пропускания, выполните перерасчет фильтра с чуть другими параметрами");
    }
        break;
    case 3:
    {
        ui->tableWidget->setVerticalHeaderLabels(QStringList() << "C" << "L");
        for(int j = 0; j < filter_.Prototipe->Number_of_elements_in_the_prototype_filter ; j++)
        {
            for(int i = 0; i < 2; i++)
            {
                QTableWidgetItem *tbl = new QTableWidgetItem(QString::number(filter_.Prototipe->Elements_of_filter[j+1][i]));
                //double uj = filter_.Prototipe->Elements_of_filter[j+1][i];
                ui->tableWidget->setItem(i, j, tbl);
                tbl->setBackground(Qt::gray);
            }
        }
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        QImage image;
        image.load("C:\\Users\\pov\\Desktop\\Culc_FIlt\\icon\\LC_REJ_P.png");
        QPixmap pixmap = QPixmap::fromImage(image);
        pixmap = pixmap.scaled(QSize(1000, 1000), Qt::KeepAspectRatio);
        ui->Image->setPixmap(pixmap);
        image.load("C:\\Users\\pov\\Desktop\\Culc_FIlt\\icon\\REjF_AFR.png");
        pixmap = QPixmap::fromImage(image);
        pixmap = pixmap.scaled(QSize(400, 400), Qt::KeepAspectRatio);
        ui->ACHH->setPixmap(pixmap);
        ui->INFO->setText("Общая информация. \n\tПорядок фильтра: " + QString::number(filter.Prototipe->Number_of_elements_in_the_prototype_filter) + "\n\t "
                                                                                                                                                      "Верхняя полоса загрождения: " + QString::number(filter.setting_parameters_for_calculation.Filter_pass_frequency*filter.setting_parameters_for_calculation.Frequency_multiplier) + " Гц;" + "\n\t"
                                                                                                                                                                                         "Нижняя полоса заграждения: " + QString::number(filter.setting_parameters_for_calculation.Filter_cut_off_frequency*filter.setting_parameters_for_calculation.Frequency_multiplier) + " Гц;" + "\n\t"
                                                                                                                                                                                            "Затухание в полосе пропускания: " + QString::number(filter.setting_parameters_for_calculation.Attenuation_level_at_the_transmission_boundary) + " " + dB + "\n\t"
                                                                                                                                                   "Затухание в полосе заграждения: " + QString::number(filter.setting_parameters_for_calculation.Attenuation_level_in_the_area_of_attenuation) + " " + dB + "\n\t"
                                                                                                                                                 "Сопротивление тракта: " + QString::number(filter.setting_parameters_for_calculation.Path_resistance) + " Ом" + "\n\t"
                                                                                                                 "Тип аппроксимации: " + Type_of_approximation + "."
                                                    "\n*Расчет фильтра верен только для идеальных элементов фильтра. В реальном исполнении фильтры получат немного более худшие характеристики, из-за чего придется их донастраивать. "
                                                    "\n Для Выполнении ТЗ по затуханию в полосе заграждения при задании требований к расчету, необходимо поставить запас по порядку фильтра, отличный от нуля "
                                                    "\n В случае не выполнения ТЗ по частоте среза или полосе пропускания, выполните перерасчет фильтра с чуть другими параметрами");

    }
        break;
    case 5:
    {
        ui->tableWidget->setVerticalHeaderLabels(QStringList() << "w" << "l");
        for(int j = 0; j < filter_.Prototipe->Number_of_elements_in_the_prototype_filter+2 ; j++)
        {
            for(int i = 0; i < 2; i++)
            {
                QTableWidgetItem *tbl;
                switch (i) {
                case 0:
                    tbl = new QTableWidgetItem(QString::number(filter_.MPL_itog.W[j]));
                    break;

                default:
                    tbl = new QTableWidgetItem(QString::number(filter_.MPL_itog.l[j]));
                    break;
                }
                //double uj = filter_.Prototipe->Elements_of_filter[j+1][i];
                ui->tableWidget->setItem(i, j, tbl);
                tbl->setBackground(Qt::gray);
            }
        }
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        QImage image;
        image.load("C:\\Users\\pov\\Desktop\\Culc_FIlt\\icon\\LC_VLF_P_MPL.png");
        QPixmap pixmap = QPixmap::fromImage(image);
        pixmap = pixmap.scaled(QSize(1000, 1000), Qt::KeepAspectRatio);
        ui->Image->setPixmap(pixmap);
        image.load("C:\\Users\\pov\\Desktop\\Culc_FIlt\\icon\\VLF_AFR.png");
        pixmap = QPixmap::fromImage(image);
        pixmap = pixmap.scaled(QSize(400, 400), Qt::KeepAspectRatio);
        ui->ACHH->setPixmap(pixmap);
        ui->INFO->setText("Общая информация. \n\tПорядок фильтра: " + QString::number(filter.Prototipe->Number_of_elements_in_the_prototype_filter) + "\n\t "
                                                                                                                                                      "Верхняя полоса загрождения: " + QString::number(filter.setting_parameters_for_calculation.Filter_pass_frequency*filter.setting_parameters_for_calculation.Frequency_multiplier) + " Гц;" + "\n\t"
                                                                                                                                                                                         "Нижняя полоса заграждения: " + QString::number(filter.setting_parameters_for_calculation.Filter_cut_off_frequency*filter.setting_parameters_for_calculation.Frequency_multiplier) + " Гц;" + "\n\t"
                                                                                                                                                                                            "Затухание в полосе пропускания: " + QString::number(filter.setting_parameters_for_calculation.Attenuation_level_at_the_transmission_boundary) + " " + dB + "\n\t"
                                                                                                                                                   "Затухание в полосе заграждения: " + QString::number(filter.setting_parameters_for_calculation.Attenuation_level_in_the_area_of_attenuation) + " " + dB + "\n\t"
                                                                                                                                                 "Сопротивление тракта: " + QString::number(filter.setting_parameters_for_calculation.Path_resistance) + " Ом" + "\n\t"
                                                                                                                 "Тип аппроксимации: " + Type_of_approximation + "."
                                                    "\n*Расчет фильтра верен только для идеальных элементов фильтра. В реальном исполнении фильтры получат немного более худшие характеристики, из-за чего придется их донастраивать. "
                                                    "\n Для Выполнении ТЗ по затуханию в полосе заграждения при задании требований к расчету, необходимо поставить запас по порядку фильтра, отличный от нуля "
                                                    "\n В случае не выполнения ТЗ по частоте среза или полосе пропускания, выполните перерасчет фильтра с чуть другими параметрами");


    }
        break;
    case 6:
    {
        ui->tableWidget->setVerticalHeaderLabels(QStringList() << "w" << "s");
        for(int j = 0; j < filter_.Prototipe->Number_of_elements_in_the_prototype_filter+2 ; j++)
        {
            for(int i = 0; i < 2; i++)
            {
                QTableWidgetItem *tbl;
                switch (i) {
                case 0:
                    tbl = new QTableWidgetItem(QString::number(filter_.MPL_itog.W[j+1]));
                    break;

                default:
                    tbl = new QTableWidgetItem(QString::number(filter_.MPL_itog.S[j+1]));
                    break;
                }
                //double uj = filter_.Prototipe->Elements_of_filter[j+1][i];
                ui->tableWidget->setItem(i, j, tbl);
                tbl->setBackground(Qt::gray);
            }
        }
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        QImage image;
        image.load("C:\\Users\\pov\\Desktop\\Culc_FIlt\\icon\\BPF_SVL.png");
        QPixmap pixmap = QPixmap::fromImage(image);
        pixmap = pixmap.scaled(QSize(500, 500), Qt::KeepAspectRatio);
        ui->Image->setPixmap(pixmap);
        image.load("C:\\Users\\pov\\Desktop\\Culc_FIlt\\icon\\BPF_AFR.png");
        pixmap = QPixmap::fromImage(image);
        pixmap = pixmap.scaled(QSize(400, 400), Qt::KeepAspectRatio);
        ui->ACHH->setPixmap(pixmap);
        ui->INFO->setText("Общая информация. \n\tПорядок фильтра: " + QString::number(filter.Prototipe->Number_of_elements_in_the_prototype_filter) + "\n\t "
                                                                                                                                                      "Частота среза: " + QString::number(filter.setting_parameters_for_calculation.Filter_pass_frequency*filter.setting_parameters_for_calculation.Frequency_multiplier) + " Гц;" + "\n\t"
                                                                                                                                                                                         "Частота Заграждения: " + QString::number(filter.setting_parameters_for_calculation.Filter_cut_off_frequency*filter.setting_parameters_for_calculation.Frequency_multiplier) + " Гц;" + "\n\t"
                                                                                                                                                                                            "Затухание в полосе пропускания: " + QString::number(filter.setting_parameters_for_calculation.Attenuation_level_at_the_transmission_boundary) + " " + dB + "\n\t"
                                                                                                                                                   "Затухание в полосе заграждения: " + QString::number(filter.setting_parameters_for_calculation.Attenuation_level_in_the_area_of_attenuation) + " " + dB + "\n\t"
                                                                                                                                                 "Сопротивление тракта: " + QString::number(filter.setting_parameters_for_calculation.Path_resistance) + " Ом" + "\n\t"
                                                                                                                 "Тип аппроксимации: " + Type_of_approximation + "."
                                                    "\n*Расчет фильтра верен только для идеальных элементов фильтра. В реальном исполнении фильтры получат немного более худшие характеристики, из-за чего придется их донастраивать. "
                                                    "\nДля Выполнении ТЗ по затуханию в полосе заграждения при задании требований к расчету, необходимо поставить запас по порядку фильтра, отличный от нуля "
                                                    "\nВ случае не выполнения ТЗ по частоте среза или полосе пропускания, выполните перерасчет фильтра с чуть другими параметрами");

    }
        break;
    case 7:

        break;
    case 8:

        break;
    default:
        break;
    }

}

void filter_table::on_pushButton_2_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    QString::fromUtf8("Сохранить файл"),
                                                    QDir::currentPath(),
                                                    "Текстовый файл (*.txt);;All files (*.*)");
    // Здесь получили адресс расположения и названия файла
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    QTextStream out(&file);//поток для записи текста
    for(int j = 0; j < 2; j++)
    {

        for(int i = 1; i <= filter_.Prototipe->Number_of_elements_in_the_prototype_filter; i++)
        {
            if(j == 0)
                out << "C" << i << "\t \t";
            if(j == 1)
                out << "L" << i << "\t \t";
            out << filter_.Prototipe->Elements_of_filter[i][j] << '\t';
            if(filter_.Prototipe->Elements_of_filter[i][j] == 0)
            {
                out << "\t";
            }
        }
        out << "\n";
    }

}

