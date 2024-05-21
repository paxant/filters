#ifndef ANALOGUE_FILTERS_H
#define ANALOGUE_FILTERS_H
#include<math.h>
#include <iostream>
#include <mpl_calculation.h>

using namespace std;

class Calculation_of_the_filter_on_distributed_elements
{
private:
    struct _PaRaMeTeRs_
    {
        uint8_t Type_of_approximation = 0;
        // 1 - Фильтр Чебышева
        // 2 - ФИльтр Баттерворта
        uint8_t Type_of_filter = 0;
        // 1 - ФНЧ
        // 2 - ФВЧ
        // 3 - ПЗФ
        // 4 - ППФ
        bool Attenuation_level_at_the_transmission_boundary_Bool_dB = false;        // Затухание в Дб
        bool Attenuation_level_in_the_area_of_attenuation_Bool_dB = false;          // Пропускание в дБ
        double Filter_cut_off_frequency = 0;                                        // Частота среза
        double Filter_pass_frequency = 0;                                           // Частота заграждения
        double Attenuation_level_at_the_transmission_boundary = 0;                  // Затухание в полосе пропускания
        double Attenuation_level_in_the_area_of_attenuation = 0;                    // Затухание в области затухания
        double Path_resistance = 0;                                                 // Сопротивление тракта
        double Frequency_multiplier = 1;                                            // Множитель частоты можно не задавать, а задать сразу частоту с кучей нулей
        double Central_Freq = 0;                                                    // Центральная частота на рассчитанном фильтре
        int Stockpile = 0;                                                     // Запас по порядку фильтра
    };
    struct FREQ_prototipe
    {
        double Central_Freq_For_PPF_PZF_or_NO = 0;
        double Half_the_bandwidth = 0;
        int Number_of_elements_in_the_prototype_filter = 0;
        double Coefficients_g[2000];
        double Elements_of_filter[2000][2];
        // [][0] - Емкости
        // [][1] - Индуктивности
    };
    FREQ_prototipe auxiliary_variables;

    struct MPL
    {
        double W[2000];
        double Zv[2000];
        double l[2000];
        double S[2000];
    };

public:
    double C_ = 299792548;
    MPL MPL_itog;
    MPL_Calculation MPL_calcul;
    struct _PaRaMeTeRs_ setting_parameters_for_calculation;
    FREQ_prototipe *Prototipe = &auxiliary_variables;
    void Calculation_of_the_flow_of_the_Chebyshev_prototype();                       // Расчет количества элементов в фильтре
    void Calculation_of_the_flow_of_the_Butterwater_prototype();
    double* The_Butterwater_g();                                               // Расчет фильтра прототипа Баттерворта
    double* Chebyshev_Filter_g();                                                     // Расчет Чебышевского нормированного фильтра
    double The_elements_in_the_prototype_filter();                                  // Расчет abkmnhf
    void Calculation_of_the_VLF_filter();                                   // Расчет ФНЧ
    void Calculation_of_the_VHF_filter();                                           // Расчет ФВЧ
    void Calculation_of_the_band_pass_filter();                              //Расчет ППФ
    void Calculation_of_band_rejection_filter();                            // Расчет ПЗФ
    void Calc_FILT();
    void Calculation_of_the_VLF_SVCH_filter();                                  // Расчет ФНЧ на МПЛ
};

#endif // ANALOGUE_FILTERS_H

