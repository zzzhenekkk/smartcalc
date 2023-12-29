#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#ifdef __cplusplus

extern "C" {
#endif

#include "../s21_smartcalc.h"

#ifdef __cplusplus
}
#endif



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
      void digits_numbers();
//    void on_pushButton_clicked();

//      void operations();
      void on_pushButton_ac_clicked();

      void on_pushButton_eq_clicked();

      void on_pushButton_set_x_clicked();

      void on_pushButton_clear_x_clicked();

      void on_pushButton_calc_x_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
