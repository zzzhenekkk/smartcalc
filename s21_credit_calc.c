#include "s21_smartcalc.h"

// общая функция для расчета кредита (выдает 3 значения)
void calulate_cradit(int type, double sum_credit, double percent, int period, int number, double *payment, double *extra, double *total) {
    if (type == ANNUITET) {
        *payment = annuitet(sum_credit, percent, period);
        *total = (*payment) * period;
        *extra = *total - sum_credit;
    }
    else if (type == DIFF) {
        *total = diff_total(sum_credit, percent, period);
        *extra = *total - sum_credit;
        *payment = diff_payment(sum_credit, percent, period, number);
    }
}

// считает ежемесячную выплату по аннуитету
double annuitet(double sum_credit, double percent, int period) {
    double coeff = (100 + percent) / 100;
    double x = sum_credit;
    if (percent > 0)
        x = percent*(sum_credit * pow(coeff, period) / (pow(coeff, period) - 1));
    return x;
}

// считате общую сумму выплат дифференцированного кредита
double diff_total(double sum_credit, double percent, int period) {
    double coeff = percent / 100;
    double x = sum_credit;
    x += coeff * sum_credit * (period + 1) / 2;
    return x;
}

// считате выплату в определенный месяц для дифференцированного кредита
double diff_payment(double sum_credit, double percent, int period, int number) {
    double coeff = percent / 100;
    return coeff * sum_credit * (period - (number - 1)) / period + sum_credit / period;
}