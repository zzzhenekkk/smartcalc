#include "creditform.h"
#include "ui_creditform.h"

CreditForm::CreditForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CreditForm)
{
    ui->setupUi(this);
    ui->radioButton_annuitet->setChecked(1);
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
    ui->doubleSpinBox_credit_sum->clear();
    ui->doubleSpinBox_percent->clear();
    ui->spinBox_period->clear();
}


void CreditForm::on_radioButton_annuitet_clicked()
{
    ui->radioButton_diff->setEnabled(true);
    ui->radioButton_annuitet->setEnabled(false);
}


void CreditForm::on_radioButton_diff_clicked()
{
    ui->radioButton_diff->setEnabled(false);
    ui->radioButton_annuitet->setEnabled(true);
}


void CreditForm::on_pushButton_calculate_clicked()
{

}

