#include "mpl_calculation.h"
#include <math.h>

#define The_speed_of_light 299792458

void MPL_Calculation::Calculation_of_coupled_asymmetric_microstrip_transmission_line()
{
    /*
    double K = (Settings.Zve - Settings.Zvo)/(Settings.Zve + Settings.Zvo);
    double B = 376.6 / sqrt(Settings.Er);
    double D = 1/3/sqrt(Settings.Er);
    double F = 1.35 / log(4* Settings.h /Settings.t);
    double STE = 0.01;
    for (int var = 1 ; var <= 1000; var ++ )
    {
        Results.w += STE;
        double M = 0;
        double A = Results.w / Settings.h;
        double G = pow(A+1, 2);
        double AA = D * (A - 1/G);
        double BB = D / G;
        double CC = A + AA + 0.5 * D * A - BB + 1.5 * F;
        double DD = 0.5 * D * A + 0.5 * F;
        double X = ((B / Settings.Zve) - CC) / DD;
        double Y = 1/X;
        double XX = 4 * (Y-1);
        double S = Results.w / XX;
        if(S > 0)
        {
            double Z1 = 2 * AA;
            M += 1;
            double Z2 = 4 *D / (S*Results.w + 1);
            double Z3 = 1.35 / log(4 * S / M_PI * Settings.t);
            double TE = B / (A + Z1 + F + Z2 + Z3);
            if( M == 1)
                STE = STE/10;
            double CH = (TE - Settings.Zvo)/ Settings.Zvo;
            if(abs(CH) <= 0.01)
            {

            }

        }
    }
*/
}

void MPL_Calculation::Calculation_of_coupled_symmetrical_microstrip_transmission_line()
{
    //double K = (Settings.Zve - Settings.Zvo)/(Settings.Zve + Settings.Zvo);
    double Xe = sqrt(Settings.Er) * Settings.Zve/ (30*M_PI);
    double Xo = sqrt(Settings.Er) * Settings.Zvo/ (30* M_PI);
    double ke, ko;
    if(Xe <= 1 && Xe >= 0)
    {
        ke = pow((exp(M_PI/Xe)-2)/(exp(M_PI/Xe)+2), 2);
    }
    else {
        ke = sqrt(1 - pow((exp(M_PI*Xe)-2)/(exp(M_PI*Xe)+2), 4));
    }
    if(Xo <= 1 && Xo >= 0)
    {
        ko = pow((exp(M_PI/Xo)-2)/(exp(M_PI/Xo)+2), 2); // Здесь мб деление
    }
    else {
        ko = sqrt(1 - pow((exp(M_PI*Xo)-2)/(exp(M_PI*Xo)+2), 4));
    }
    Results.w = 2/M_PI * atanh(sqrt(ke*ko)) * Settings.b;
    Results.s = Settings.b * 2/M_PI * atanh((1-ko)/(1-ke)*sqrt(ke/ko));
}

void MPL_Calculation::Calculation_of_symmetrical_microstrip_transmission_line()
{
    double w = 0;
    while(true)
    {
        w = w+ 0.000001;
        double x = Settings.t/Settings.b;
        double p = 2/(1+2/3*x/(1-x));
        double dW_B_t = x/(M_PI*(1-x))*(1-0.5*log(pow(x/(2-x) ,2)+pow((0.0796*x/(w/Settings.b+1.1*x)) , p)));
        double m = w/(Settings.b-Settings.t)+dW_B_t;
        double Z_v = (30/sqrt(Settings.Er))*log(1+(4/(m*M_PI))*(8/(m*M_PI)+sqrt(pow(8/(m*M_PI),2)+6.27)));
        if(Z_v < Settings.Zv)
            break;
    }
    Results.w = w;
}

void MPL_Calculation::Calculation_of_asymmetrical_microstrip_transmission_line()
{
    // Ширина полоска без учета толщины полоска  
    double w_h = 0;
    double E_ef_sh = 0.2775 +0.722 * Settings.Er;
    if(Settings.Zv < 128/sqrt(E_ef_sh))
    {
        w_h = 64 * ( 1 - sqrt( 1.0455 - ( 0.0512 * ( 60 * M_PI / ( Settings.Zv * sqrt( E_ef_sh ) ) ) ) ) );
    }
    else
    {
        w_h = 2 * ( exp((Settings.Zv*sqrt(E_ef_sh) / 60)) - sqrt( exp(Settings.Zv * sqrt( E_ef_sh )/30) - 8 ) );
    }
    double wt_h = 0;
    if(w_h < 0.16)
    {
        wt_h = w_h + Settings.t/(M_PI*Settings.h)*(1+log(4*M_PI*w_h*Settings.h/(Settings.t)));
    }
    else
    {
        wt_h = w_h + Settings.t/(M_PI*Settings.h)*(1+log(2*Settings.h/Settings.t));
    }
    Results.Eeff = (Settings.Er + 1) / 2 + ((Settings.Er - 1) / 2) / (sqrt( 1+ 10 * 1 / wt_h));
    Results.w = wt_h * Settings.h;
    if(wt_h < 2)
    {
        Results.Zv = 60/sqrt(Results.Eeff)*(log(8/wt_h)+wt_h*wt_h*1/32);
    }
    else{
        Results.Zv = 120*M_PI/sqrt(Results.Eeff)*pow((wt_h+2/M_PI*log(17.08*(wt_h/2+0.92))), -1);
    }
}
