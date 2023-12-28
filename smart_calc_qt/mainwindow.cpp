#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox> // библиотека для диалогового окна

#include "../s21_smartcalc.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_cb, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_dot, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_mult, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_ob, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_pow, SIGNAL(clicked()), this, SLOT(digits_numbers()));

}

MainWindow::~MainWindow()
{
    delete ui;
}


// добавляем в строку из кнопки, без логики
void MainWindow::digits_numbers()
{
    QPushButton * button = (QPushButton *)sender();

    if (ui->result_show->text() == "0" && button->text() != ".") {
        ui->result_show->setText("");
        if (button->text() == ".")
            ui->result_show->setText("0");
    }

    ui->result_show->setText(ui->result_show->text() + button->text());
}


// для ac
void MainWindow::on_pushButton_ac_clicked()
{

    ui->result_show->setText("0");
}

// для подсчета
void MainWindow::on_pushButton_eq_clicked()
{
    QString input = ui->result_show->text();
    double result;
    int error = smart_calc( (char*)input.toStdString().c_str(), &result);

    if (std::isnan(result) || error <= 0) {
      ui->result_show->setText("ERROR");
    } else {
      ui->result_show->setText(QString::number(result, 'g', 7));
    }
}




















//void MainWindow::on_pushButton_dot_clicked()
//{
////    if (!(ui->result_show->text().contains('.')))
//    ui->result_show->setText(ui->result_show->text() + ".");
//}

//connect(ui->pushButton_dot, SIGNAL(clicked()), this, SLOT(digits_numbers()));
//connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(digits_numbers()));
//connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(digits_numbers()));
//connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(digits_numbers()));
//connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(digits_numbers()));
//connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(digits_numbers()));


//ui->result_show->text() + button->text()
//void MainWindow::on_pushButton_clicked()
//{   // для labek по нажатию кнопки меняется текст
////    ui->label->setText("Кнопка нажата!");
////    // открывается диалоговое окно типа about
////    QMessageBox::about(this, "Заголовок", "Здесь текст, который нужно отобразить");
////    // открывается диалоговое окно типа ОШИБКА
////    QMessageBox::critical(this, "Заголовок", "ОШИБКАААА");
////    // открывается диалоговое окно типа информация там другая картинка
////    QMessageBox::information(this, "Заголовок", "Информация");
////    // открывается диалоговое окно типа предупреждение там другая картинка
////    QMessageBox::warning(this, "Заголовок", "Информация");
//    // открывается диалоговое окно типа вопрос там другая картинка
////    QMessageBox::StandardButton reply = QMessageBox::question(this, "Заголовок", "Информация", QMessageBox::Yes | QMessageBox::No);
////    if (reply == QMessageBox::Yes) {
////        QApplication::quit();
////    } else {
////        qDebug() << "Кнопка нет, была нажата";
////    }


//}








