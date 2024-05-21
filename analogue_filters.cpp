#include "analogue_filters.h"



void Calculation_of_the_filter_on_distributed_elements::Calculation_of_the_flow_of_the_Chebyshev_prototype()
{
    double Az, Apr;
    if(setting_parameters_for_calculation.Attenuation_level_in_the_area_of_attenuation_Bool_dB)
    {
        Az = pow(10, setting_parameters_for_calculation.Attenuation_level_in_the_area_of_attenuation/10);
    }
    else Az = setting_parameters_for_calculation.Attenuation_level_in_the_area_of_attenuation;
    if(setting_parameters_for_calculation.Attenuation_level_at_the_transmission_boundary_Bool_dB)
    {
        Apr = pow(10, setting_parameters_for_calculation.Attenuation_level_at_the_transmission_boundary/10);
    }
    else Apr = setting_parameters_for_calculation.Attenuation_level_at_the_transmission_boundary;


    switch (setting_parameters_for_calculation.Type_of_filter) {
    case 3:
        auxiliary_variables.Number_of_elements_in_the_prototype_filter = acosh(sqrt((Az-1)/(Apr-1)))/acosh(setting_parameters_for_calculation.Filter_pass_frequency / setting_parameters_for_calculation.Filter_cut_off_frequency)+1;
        break;
    case 4:
        auxiliary_variables.Number_of_elements_in_the_prototype_filter = acosh(sqrt((Az-1)/(Apr-1)))/acosh(setting_parameters_for_calculation.Filter_cut_off_frequency/setting_parameters_for_calculation.Filter_pass_frequency)+1;
        break;
    default:
         auxiliary_variables.Number_of_elements_in_the_prototype_filter = acosh(sqrt((Az-1)/(Apr-1)))/acosh(setting_parameters_for_calculation.Filter_cut_off_frequency/auxiliary_variables.Half_the_bandwidth)+1;
        break;
    }
}

void Calculation_of_the_filter_on_distributed_elements::Calculation_of_the_flow_of_the_Butterwater_prototype()
{
    double Az;
    if(setting_parameters_for_calculation.Attenuation_level_in_the_area_of_attenuation_Bool_dB)
    {
        Az = pow(10, setting_parameters_for_calculation.Attenuation_level_in_the_area_of_attenuation/10);
    }
    else Az = setting_parameters_for_calculation.Attenuation_level_in_the_area_of_attenuation;

    switch (setting_parameters_for_calculation.Type_of_filter) {
    case 3:
        auxiliary_variables.Number_of_elements_in_the_prototype_filter = log(Az - 1)/(2*log(setting_parameters_for_calculation.Filter_pass_frequency / setting_parameters_for_calculation.Filter_cut_off_frequency))+1;
        break;
    case 4:
        auxiliary_variables.Number_of_elements_in_the_prototype_filter = log(Az - 1)/(2*log(setting_parameters_for_calculation.Filter_cut_off_frequency/setting_parameters_for_calculation.Filter_pass_frequency))+1;
        break;
    default:
        auxiliary_variables.Number_of_elements_in_the_prototype_filter = log(Az - 1)/(2*log(setting_parameters_for_calculation.Filter_cut_off_frequency/auxiliary_variables.Half_the_bandwidth))+1;
        break;
    }
}


double* Calculation_of_the_filter_on_distributed_elements::The_Butterwater_g()
{
    for(int k = 1; k <= auxiliary_variables.Number_of_elements_in_the_prototype_filter; k++)
    {
        auxiliary_variables.Coefficients_g[k] = 2*sin(((2*k-1)*M_PI)/(2*auxiliary_variables.Number_of_elements_in_the_prototype_filter));
    }
    return 0;
}

double* Calculation_of_the_filter_on_distributed_elements::Chebyshev_Filter_g()
{
    double Am = 0;
    if(!setting_parameters_for_calculation.Attenuation_level_at_the_transmission_boundary_Bool_dB)
    {
        Am = 10*log10(setting_parameters_for_calculation.Attenuation_level_at_the_transmission_boundary);
    }
    else Am = setting_parameters_for_calculation.Attenuation_level_at_the_transmission_boundary;

    double B = log(1/tan(Am/17.37));
    double y = sinh(B/(2*auxiliary_variables.Number_of_elements_in_the_prototype_filter));
    auxiliary_variables.Coefficients_g[1] = 1;
    double a_buff = 0;
    double b_buff = 0;
    for(int i = 1; i <= auxiliary_variables.Number_of_elements_in_the_prototype_filter; i++)
    {
        double a = sin((2*i-1)*M_PI/(2*auxiliary_variables.Number_of_elements_in_the_prototype_filter));

        if(i == 1)
        {
            auxiliary_variables.Coefficients_g[i] = 2*a/y;
        }
        if(i != 1 )
        {
            auxiliary_variables.Coefficients_g[i] = (4*a_buff*a)/(b_buff*auxiliary_variables.Coefficients_g[i-1] );
        }
        b_buff = y*y+sin(i*M_PI/auxiliary_variables.Number_of_elements_in_the_prototype_filter)*sin(i*M_PI/auxiliary_variables.Number_of_elements_in_the_prototype_filter);
        a_buff = a;
    }
}

void Calculation_of_the_filter_on_distributed_elements::Calculation_of_the_VLF_filter()
{
    for(int i = 1; i <= auxiliary_variables.Number_of_elements_in_the_prototype_filter; i++)
    {
        if(i%2 == 0)
        {
            auxiliary_variables.Elements_of_filter[i][1] = auxiliary_variables.Coefficients_g[i]*setting_parameters_for_calculation.Path_resistance/(auxiliary_variables.Half_the_bandwidth*setting_parameters_for_calculation.Frequency_multiplier*2*M_PI);
        }
        else
        {
            auxiliary_variables.Elements_of_filter[i][0] = auxiliary_variables.Coefficients_g[i]/(auxiliary_variables.Half_the_bandwidth*setting_parameters_for_calculation.Frequency_multiplier*setting_parameters_for_calculation.Path_resistance*2*M_PI);
        }
    }
}

void Calculation_of_the_filter_on_distributed_elements::Calculation_of_the_VHF_filter()
{
    for(int i = 1; i <= auxiliary_variables.Number_of_elements_in_the_prototype_filter; i++)
    {
        if(i%2 == 0)
        {
            auxiliary_variables.Elements_of_filter[i][0] = 1/(auxiliary_variables.Half_the_bandwidth*setting_parameters_for_calculation.Frequency_multiplier*setting_parameters_for_calculation.Path_resistance*2*M_PI*auxiliary_variables.Coefficients_g[i]);
        }
        else
        {
            auxiliary_variables.Elements_of_filter[i][1] = setting_parameters_for_calculation.Path_resistance/(auxiliary_variables.Half_the_bandwidth*setting_parameters_for_calculation.Frequency_multiplier*2*M_PI*auxiliary_variables.Coefficients_g[i]);
        }
    }
}

void Calculation_of_the_filter_on_distributed_elements::Calculation_of_the_band_pass_filter()
{
    for(int i = 1; i <= auxiliary_variables.Number_of_elements_in_the_prototype_filter; i++)
    {
        if(i%2 == 0)
        {
            auxiliary_variables.Elements_of_filter[i][1] = auxiliary_variables.Coefficients_g[i]*setting_parameters_for_calculation.Path_resistance/(setting_parameters_for_calculation.Filter_pass_frequency*2*M_PI*setting_parameters_for_calculation.Frequency_multiplier);
            auxiliary_variables.Elements_of_filter[i][0] = 1/(pow(auxiliary_variables.Central_Freq_For_PPF_PZF_or_NO*2*M_PI, 2)*pow(setting_parameters_for_calculation.Frequency_multiplier,2)*auxiliary_variables.Elements_of_filter[i][1]);
        }
        else
        {
            auxiliary_variables.Elements_of_filter[i][0] = auxiliary_variables.Coefficients_g[i]/(setting_parameters_for_calculation.Filter_pass_frequency*2*M_PI*setting_parameters_for_calculation.Frequency_multiplier*setting_parameters_for_calculation.Path_resistance);
            auxiliary_variables.Elements_of_filter[i][1] = 1/(pow(auxiliary_variables.Central_Freq_For_PPF_PZF_or_NO*2*M_PI, 2)*pow(setting_parameters_for_calculation.Frequency_multiplier,2)*auxiliary_variables.Elements_of_filter[i][0]);
        }
    }
}

void Calculation_of_the_filter_on_distributed_elements::Calculation_of_the_VLF_SVCH_filter()
{
    Calculation_of_the_VLF_filter();
}

void Calculation_of_the_filter_on_distributed_elements::Calculation_of_band_rejection_filter()
{
    for(int i = 1; i <= auxiliary_variables.Number_of_elements_in_the_prototype_filter; i++)
    {
        if(i%2 == 0)
        {
            auxiliary_variables.Elements_of_filter[i][0] = 1/(setting_parameters_for_calculation.Filter_pass_frequency*2*M_PI*setting_parameters_for_calculation.Path_resistance*auxiliary_variables.Coefficients_g[i]*setting_parameters_for_calculation.Frequency_multiplier);
            auxiliary_variables.Elements_of_filter[i][1] = 1/(pow(auxiliary_variables.Central_Freq_For_PPF_PZF_or_NO*2*M_PI, 2)*auxiliary_variables.Elements_of_filter[i][0]*pow(setting_parameters_for_calculation.Frequency_multiplier,2));
        }
        else
        {
            auxiliary_variables.Elements_of_filter[i][1] = setting_parameters_for_calculation.Path_resistance/(auxiliary_variables.Coefficients_g[i]*setting_parameters_for_calculation.Filter_pass_frequency*setting_parameters_for_calculation.Frequency_multiplier*2*M_PI);
            auxiliary_variables.Elements_of_filter[i][0] = 1/(pow(auxiliary_variables.Central_Freq_For_PPF_PZF_or_NO*2*M_PI,2)*pow(setting_parameters_for_calculation.Frequency_multiplier, 2)*auxiliary_variables.Elements_of_filter[i][1] );
        }
    }
}

void Calculation_of_the_filter_on_distributed_elements::Calc_FILT()
{
    switch (setting_parameters_for_calculation.Type_of_filter) {
    case 1:
        Calculation_of_the_VLF_filter();
        break;
    case 2:
        Calculation_of_the_VHF_filter();
        break;
    case 3:
        Calculation_of_the_band_pass_filter();
        break;
    case 4:
        Calculation_of_band_rejection_filter();
        break;
    case 5:
        Calculation_of_the_VLF_filter();
        switch (MPL_calcul.type_of_MPL) {
        case 1:
            for (int var = 0; var < auxiliary_variables.Number_of_elements_in_the_prototype_filter; ++var) {
                if(var == 0)
                {
                    MPL_itog.Zv[0] = setting_parameters_for_calculation.Path_resistance;
                    MPL_calcul.Settings.Zv = MPL_itog.Zv[0];
                    MPL_calcul.Calculation_of_symmetrical_microstrip_transmission_line();
                    MPL_itog.W[0] = MPL_calcul.Results.w;
                    MPL_itog.l[0] = C_ / (setting_parameters_for_calculation.Filter_pass_frequency*pow(10, 6)*2*sqrt(MPL_calcul.Settings.Er));
                    MPL_itog.l[auxiliary_variables.Number_of_elements_in_the_prototype_filter+1] = MPL_itog.l[0];
                }
                if(var >= 1  && var <= auxiliary_variables.Number_of_elements_in_the_prototype_filter && var % 2 != 0)
                {
                    MPL_itog.Zv[var] = MPL_calcul.Settings.Zc;
                    MPL_calcul.Settings.Zv = MPL_calcul.Settings.Zc;
                    MPL_calcul.Calculation_of_symmetrical_microstrip_transmission_line();
                    MPL_itog.W[var] = MPL_calcul.Results.w;
                    MPL_itog.l[var] = MPL_itog.Zv[var]/3333/sqrt(MPL_calcul.Settings.Er)*pow(10, 6) * auxiliary_variables.Elements_of_filter[var][0];
                }
                if(var >= 1  && var <= auxiliary_variables.Number_of_elements_in_the_prototype_filter && var % 2 == 0)
                {
                    MPL_itog.Zv[var] = MPL_calcul.Settings.Zl;
                    MPL_calcul.Settings.Zv = MPL_calcul.Settings.Zl;
                    MPL_calcul.Calculation_of_symmetrical_microstrip_transmission_line();
                    MPL_itog.W[var] = MPL_calcul.Results.w;
                    MPL_itog.l[var] = auxiliary_variables.Elements_of_filter[var][1]/3.333/MPL_itog.Zv[var]/sqrt(MPL_calcul.Settings.Er) * pow(10, 12) ;
                }
            }
            break;
        default:
            for (int var = 0; var <= auxiliary_variables.Number_of_elements_in_the_prototype_filter; ++var) {
                if(var == 0)
                {
                    MPL_itog.Zv[0] = setting_parameters_for_calculation.Path_resistance;
                    MPL_calcul.Settings.Zv = MPL_itog.Zv[0];
                    MPL_calcul.Calculation_of_asymmetrical_microstrip_transmission_line() ;
                    MPL_itog.W[0] = MPL_calcul.Results.w;
                    MPL_itog.l[0] = C_ / (setting_parameters_for_calculation.Filter_pass_frequency*2*pow(10, 6)*sqrt(MPL_calcul.Results.Eeff));
                    MPL_itog.l[auxiliary_variables.Number_of_elements_in_the_prototype_filter+1] = MPL_itog.l[0];
                    MPL_itog.W[auxiliary_variables.Number_of_elements_in_the_prototype_filter+1] = MPL_itog.W[0];
                }
                if(var >= 1  && var <= auxiliary_variables.Number_of_elements_in_the_prototype_filter && var % 2 != 0)
                {
                    MPL_calcul.Settings.Zv = MPL_calcul.Settings.Zc;
                    MPL_calcul.Calculation_of_asymmetrical_microstrip_transmission_line();
                    MPL_itog.W[var] = MPL_calcul.Results.w;
                    MPL_itog.Zv[var] = MPL_calcul.Results.Zv;
                    MPL_itog.l[var] = MPL_itog.Zv[var]/(3333*sqrt(MPL_calcul.Results.Eeff))*pow(10, 15) * auxiliary_variables.Elements_of_filter[var][0];
                }
                if(var >= 1  && var <= auxiliary_variables.Number_of_elements_in_the_prototype_filter && var % 2 == 0)
                {
                    MPL_calcul.Settings.Zv = MPL_calcul.Settings.Zl;
                    MPL_calcul.Calculation_of_asymmetrical_microstrip_transmission_line();
                    MPL_itog.W[var] = MPL_calcul.Results.w;
                    MPL_itog.Zv[var] = MPL_calcul.Results.Zv;
                    MPL_itog.l[var] = auxiliary_variables.Elements_of_filter[var][1]/3.333/MPL_itog.Zv[var]/sqrt(MPL_calcul.Results.Eeff) * pow(10, 12);
                }
            }
            break;
        }
        break;
    case 6:
        double B = (setting_parameters_for_calculation.Filter_pass_frequency)/setting_parameters_for_calculation.Central_Freq;
        double Z;
        MPL_calcul.Settings.Zv = setting_parameters_for_calculation.Path_resistance;
        MPL_calcul.Calculation_of_symmetrical_microstrip_transmission_line();
        MPL_itog.W[1] = MPL_calcul.Results.w;
        MPL_itog.W[auxiliary_variables.Number_of_elements_in_the_prototype_filter+2] =  MPL_itog.W[1];
        for (int var = 1; var <= auxiliary_variables.Number_of_elements_in_the_prototype_filter; ++var) {
            if(var == 1)
            {
                Z = sqrt(M_PI*B/2/auxiliary_variables.Coefficients_g[var]);
            }
            else
            {
                Z = M_PI*B/(2*sqrt(auxiliary_variables.Coefficients_g[var]*auxiliary_variables.Coefficients_g[var-1]));
            }
            if(var == auxiliary_variables.Number_of_elements_in_the_prototype_filter)
            {
                Z = sqrt(M_PI*B/2/auxiliary_variables.Coefficients_g[var]);
            }
            MPL_calcul.Settings.Zve = setting_parameters_for_calculation.Path_resistance*(1+Z+Z*Z);
            MPL_calcul.Settings.Zvo = setting_parameters_for_calculation.Path_resistance*(1-Z+Z*Z);
            MPL_calcul.Calculation_of_coupled_symmetrical_microstrip_transmission_line();
            MPL_itog.S[var+1] = MPL_calcul.Results.s;
            MPL_itog.W[var+1] = MPL_calcul.Results.w;
        }
        break;
    }
}


double Calculation_of_the_filter_on_distributed_elements::The_elements_in_the_prototype_filter(){

    for(int i = 0; i < 2000; i++)
    {
        auxiliary_variables.Coefficients_g[i] = 0.;
        for(int j = 0; j != 2; j++)
        {
            auxiliary_variables.Elements_of_filter[i][j] = 0;
        }
    }

    if(setting_parameters_for_calculation.Type_of_filter == 3 || setting_parameters_for_calculation.Type_of_filter == 4)
    {
        auxiliary_variables.Central_Freq_For_PPF_PZF_or_NO = sqrt((setting_parameters_for_calculation.Central_Freq - setting_parameters_for_calculation.Filter_pass_frequency/2)*(setting_parameters_for_calculation.Central_Freq + setting_parameters_for_calculation.Filter_pass_frequency/2));
        auxiliary_variables.Half_the_bandwidth = auxiliary_variables.Central_Freq_For_PPF_PZF_or_NO + setting_parameters_for_calculation.Filter_cut_off_frequency/2;
    }
    else
    {
        auxiliary_variables.Half_the_bandwidth = setting_parameters_for_calculation.Filter_pass_frequency;
    }

    switch (setting_parameters_for_calculation.Type_of_approximation) {
    case 1:
        Calculation_of_the_flow_of_the_Chebyshev_prototype();
        auxiliary_variables.Number_of_elements_in_the_prototype_filter += setting_parameters_for_calculation.Stockpile;
        if (auxiliary_variables.Number_of_elements_in_the_prototype_filter % 2 == 0)
        {
            auxiliary_variables.Number_of_elements_in_the_prototype_filter++;
        }
        Chebyshev_Filter_g();
        Calc_FILT();
        break;
    case 2:
        Calculation_of_the_flow_of_the_Butterwater_prototype();
        auxiliary_variables.Number_of_elements_in_the_prototype_filter += setting_parameters_for_calculation.Stockpile;
        The_Butterwater_g();
        Calc_FILT();
        break;
    default:
        break;
    }
}
