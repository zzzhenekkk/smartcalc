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

    connect(ui->pushButton_x, SIGNAL(clicked()), this, SLOT(digits_numbers()));

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
    double result = 0.;
    int error = SUCCESS;

    error = smart_calc( (char*)input.toStdString().c_str(), &result);

    if (std::isnan(result) || error <= 0) {
      ui->result_show->setText("ERROR");
    } else {
      ui->result_show->setText(QString::number(result, 'g', 7));
    }
}


void MainWindow::on_pushButton_set_x_clicked()
{
    ui->x_g->setText(ui->result_show->text());
}


void MainWindow::on_pushButton_clear_x_clicked()
{
    ui->x_g->setText("0");
}



void MainWindow::on_pushButton_calc_x_clicked()
{
    QString input = ui->result_show->text();
    double result = 0.;
    int status = SUCCESS;
    result = 0.;
    node_t * output_list = NULL;
    status = convert_polish_notation (&output_list, (char*)input.toStdString().c_str());
    if (status == SUCCESS)
      status = calculate (output_list, &result, ui->x_g->text().toDouble(), GRAPH_ON);

        //
    remove_node(output_list);

    if (std::isnan(result) || status <= 0) {
      ui->result_show->setText("ERROR");
    } else {
      ui->result_show->setText(QString::number(result, 'g', 7));
    }
}


void MainWindow::on_pushButton_graph_clicked()
{
    //Рисуем график y=x*x
    //Сгенерируем данные
    //Для этого создадим два массива точек:
    //один для сохранения x координат точек,
    //а второй для y соответственно
//    double a = -1; //Начало интервала, где рисуем график по оси Ox
//    double b =  1; //Конец интервала, где рисуем график по оси Ox
    // получаем максимальные и минимальные значения осей
    double x_min = ui->doubleSpinBox_x_min->value();
    double x_max = ui->doubleSpinBox_x_max->value();
    double y_min = ui->doubleSpinBox_y_min->value();
    double y_max = ui->doubleSpinBox_y_max->value();
    double h = ui->doubleSpinBox_h->value(); //Шаг, с которым будем пробегать по оси Ox
    int N = (x_max - x_min) / h + 1; //Вычисляем количество точек, которые будем отрисовывать
    QVector<double> x(N), y(N); //Массивы координат точек

    //Вычисляем наши данные
    int i=0;
    double res_p = 0.0;
    QString input = ui->result_show->text();
    int status = SUCCESS;
    node_t * output_list = NULL;
    status = convert_polish_notation (&output_list, (char*)input.toStdString().c_str());
    node_t * header_output_list = output_list;

    //Пробегаем по всем точкам
    if (status > 0) {
        for (double X = x_min; X <= x_max; X += h) {
//            if (X == 0.0) {
//                continue;
//            }
          x[i] = X;

          output_list = header_output_list;
          if (status == SUCCESS)
            status = calculate(output_list, &res_p, x[i], GRAPH_ON);

          y[i] = res_p;
          if (status <= 0) {
            ui->result_show->setText("ERROR");
            break;
          }


          i++;
        }
    } else {
        ui->result_show->setText("ERROR");
    }
    remove_node(output_list);

    ui->widget->clearGraphs();//Если нужно, но очищаем все графики


    //Добавляем один график в widget
    ui->widget->addGraph();

    //Говорим, что отрисовать нужно график по нашим двум массивам x и y
    ui->widget->graph(0)->setData(x, y);

    //Подписываем оси Ox и Oy
    ui->widget->xAxis->setLabel("x");
    ui->widget->yAxis->setLabel("y");

    //Установим область, которая будет показываться на графике
    ui->widget->xAxis->setRange(x_min, x_max);//Для оси Ox

    //Для показа границ по оси Oy сложнее, так как надо по правильному
    //вычислить минимальное и максимальное значение в векторах
    double minY = y[0], maxY = y[0];
    for (int i = 1; i < N; i++) {
      if (y[i] < minY) minY = y[i];
      if (y[i] > maxY) maxY = y[i];
    }
    if (y_min == -10.0 && y_max == 10.0 )
        ui->widget->yAxis->setRange(minY, maxY);//если пользователь ничего не установил

    else
        ui->widget->yAxis->setRange(y_min, y_max);

    // задаем возможность зумировать график
    ui->widget->setInteraction(QCP::iRangeZoom, true);

    // задаем цвет точки и толщину линии
    ui->widget->graph(0)->setPen(QColor(61, 82, 62, 255));
    QPen graphPen = ui->widget->graph(0)->pen();
    graphPen.setWidth(2);
    ui->widget->graph(0)->setPen(graphPen);

    //И перерисуем график на нашем widget
    ui->widget->replot();
}



//    // шаг
//    double h = 0.1;
//    QVector<double> x, y;  // Массивы координат точек

//    // собираем все точки
//    for (double X = x_min; X <= x_max; X += h) {
//      x.push_back(X);
//      y.push_back(
//          calculate_points(result_text.toLower().toStdString().c_str(), X));
//    }














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











