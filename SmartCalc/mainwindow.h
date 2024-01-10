#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <creditform.h>

#ifdef __cplusplus

extern "C" {
#endif

#include "C:\Users\Андрей\Desktop\школа 21\base\smartcalc\s21_smartcalc.h"

#ifdef __cplusplus
}
#endif

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void convert_buttons();

    // void convert_pi();

    // void convert_exp();

    void on_pushButton_equal_clicked();

    void on_pushButton_del_clicked();

    void on_pushButton_plot_clicked();

    void on_Set_X_clicked();

    void on_Clear_X_clicked();

    void on_pushButton_clear_plot_clicked();

    void on_pushButton_credit_calc_clicked();

private:
    Ui::MainWindow *ui;
    CreditForm *credit;
};
#endif // MAINWINDOW_H
