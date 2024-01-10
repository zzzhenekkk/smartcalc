#include "creditform.h"
#include "ui_creditform.h"

// #include "C:\Users\Андрей\Desktop\школа 21\base\smartcalc\s21_smartcalc.h"
#include "s21_smartcalc.h"

CreditForm::CreditForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CreditForm)
{
    ui->setupUi(this);
    ui->radioButton_annuitet->setChecked(1);
    ui->radioButton_annuitet->setEnabled(false);
    ui->spinBox_month_number->setEnabled(false);
}

CreditForm::~CreditForm()
{
    delete ui;
}

void CreditForm::on_pushButton_call_main_window_clicked()
{
    this->close();
    emit firstWindow();
}



void CreditForm::on_pushButton_clear_clicked()
{
    // очистка рассчитанных значений
    ui->label_total->setText("0");
    ui->label_extra_pay->setText("0");
    ui->label_pay_per_month->setText("0");

    // очистка введенных значений
    ui->doubleSpinBox_credit_sum->setValue(0.00);
    ui->doubleSpinBox_percent->setValue(0.0);
    ui->spinBox_period->setValue(1);
}


void CreditForm::on_radioButton_annuitet_clicked()
{
    ui->radioButton_diff->setEnabled(true);
    ui->radioButton_annuitet->setEnabled(false);
    ui->spinBox_month_number->setEnabled(false);
    ui->spinBox_month_number->setValue(1);
}


void CreditForm::on_radioButton_diff_clicked()
{
    ui->radioButton_diff->setEnabled(false);
    ui->radioButton_annuitet->setEnabled(true);
    ui->spinBox_month_number->setEnabled(true);
}


void CreditForm::on_pushButton_calculate_clicked()
{
    double sum_credit = ui->doubleSpinBox_credit_sum->value();
    double percent = ui->doubleSpinBox_percent->value();
    int period = ui->spinBox_period->value();
    int month_number = ui->spinBox_month_number->value();
    double payment = 0., extra = 0., total = 0.;
    int type = 0;
    double buf = 0.;
    if (ui->radioButton_annuitet->isChecked())
        type = ANNUITET;
    else
        type = DIFF;
    if (type == DIFF && month_number > period) {
        ui->label_pay_per_month->setText("ERROR");
        calulate_credit(type, sum_credit, percent, period, 1, &payment, &extra, &total);
    }
    else {
        calulate_credit(type, sum_credit, percent, period, month_number, &payment, &extra, &total);
        buf = round(payment);
        ui->label_pay_per_month->setText(QString::number(buf)+"."+QString::number(100*(payment-buf)));
    }
    ui->label_extra_pay->setText(QString::number(extra, 'f'));
    ui->label_total->setText(QString::number(total, 'f'));

}

