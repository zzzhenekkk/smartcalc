#ifndef CREDITFORM_H
#define CREDITFORM_H

#include <QWidget>

namespace Ui {
class CreditForm;
}

class CreditForm : public QWidget
{
    Q_OBJECT

public:
    explicit CreditForm(QWidget *parent = nullptr);
    ~CreditForm();

private slots:

    void on_pushButton_call_main_window_clicked();


    void on_pushButton_clear_clicked();

    void on_radioButton_annuitet_clicked();

    void on_radioButton_diff_clicked();

    void on_pushButton_calculate_clicked();

signals:
    void firstWindow();

private:
    Ui::CreditForm *ui;
};

#endif // CREDITFORM_H
