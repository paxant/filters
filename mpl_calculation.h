#ifndef MPL_CALCULATION_H
#define MPL_CALCULATION_H

class MPL_Calculation
{
private:
    struct Calculation_settings
    {
        double Er = 0;
        double Zv = 0;
        double Zve = 0;
        double Zvo = 0;
        double t = 0;
        double h = 0;
        double b = 0;
        double Zc = 17;
        double Zl = 100;
        double L_C_L = 1/8;
        int type_of_MPL = 0;
    };

    struct Calculation_results
    {
        double Eeff = 0;
        double Wavelength = 0;
        double w = 0;
        double s = 0;
        double Zv = 0;
    };

public:
    int type_of_MPL = 0;
    Calculation_settings Settings;
    Calculation_results Results;
    void Calculation_of_coupled_asymmetric_microstrip_transmission_line();
    void Calculation_of_coupled_symmetrical_microstrip_transmission_line();
    void Calculation_of_symmetrical_microstrip_transmission_line();
    void Calculation_of_asymmetrical_microstrip_transmission_line();
};

#endif // MPL_CALCULATION_H
