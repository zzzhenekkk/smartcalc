#include "mainwindow.h"
#include "ui_mainwindow.h"

// #include "C:\Users\Андрей\Desktop\школа 21\base\smartcalc\s21_smartcalc.h"
#include "s21_smartcalc.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    credit = new CreditForm();
    connect(credit, &CreditForm::firstWindow, this, &MainWindow::show);

    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(convert_buttons()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(convert_buttons()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(convert_buttons()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(convert_buttons()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(convert_buttons()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(convert_buttons()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(convert_buttons()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(convert_buttons()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(convert_buttons()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(convert_buttons()));
    connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(convert_buttons()));
    connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(convert_buttons()));
    connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(convert_buttons()));
    connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(convert_buttons()));
    connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(convert_buttons()));
    connect(ui->pushButton_lb, SIGNAL(clicked()), this, SLOT(convert_buttons()));
    connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(convert_buttons()));
    connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(convert_buttons()));
    connect(ui->pushButton_dot, SIGNAL(clicked()), this, SLOT(convert_buttons()));
    connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(convert_buttons()));
    connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(convert_buttons()));
    connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(convert_buttons()));
    connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(convert_buttons()));
    connect(ui->pushButton_mul, SIGNAL(clicked()), this, SLOT(convert_buttons()));
    connect(ui->pushButton_rb, SIGNAL(clicked()), this, SLOT(convert_buttons()));
    connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(convert_buttons()));
    connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(convert_buttons()));
    connect(ui->pushButton_pow, SIGNAL(clicked()), this, SLOT(convert_buttons()));

    connect(ui->pushButton_pi, SIGNAL(clicked()), this, SLOT(convert_buttons()));
    connect(ui->pushButton_exp, SIGNAL(clicked()), this, SLOT(convert_buttons()));

    connect(ui->pushButton_x, SIGNAL(clicked()), this, SLOT(convert_buttons()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::convert_buttons()
{
    QPushButton * button = (QPushButton *)sender();

    // добавление символа или функции в выражение
    if (ui->result->text() == "0" && strchr("^/*,", *button->text().toStdString().c_str()) == 0 && button->text() != "mod") {
           ui->result->clear();
    }
    ui->result->setText(ui->result->text() + ((button->text() == ",") ? "." : button->text()));
}


void MainWindow::on_pushButton_del_clicked()
{
    ui->result->setText("0");
}


void MainWindow::on_pushButton_equal_clicked()
{

    QString input = ui->result->text();
    double result = 0.;
    int error = SUCCESS;

    // если в выражении есть x
    if (input.contains('x')) {
        node_t * output_list = NULL;
        error = convert_polish_notation (&output_list, (char*)input.toStdString().c_str());
        if (error == SUCCESS) {
            QString x_val = ui->x_value->text();
            double x = x_val.toDouble();
            if (x == 0 && x_val != "0") {
                if (x_val.length() == 1) // попали в exp
                    x = EXP;
                else // остается только pi
                    x = PI;
            }
            error = calculate(output_list, &result, x, GRAPH_ON);
            if (error == SUCCESS)
                ui->result->setText(QString::number(result));
        }
        remove_node(output_list);
        if (error != SUCCESS)
            ui->result->setText("ERROR");
    }
    else { // обычное выражение
        error = smart_calc( (char*)input.toStdString().c_str(), &result);

        if (std::isnan(result) || error !=SUCCESS) {
            ui->result->setText("ERROR");
        } else {
            ui->result->setText(QString::number(result, 'g', 7));
        }
    }

}


void MainWindow::on_pushButton_plot_clicked()
{
    //Сгенерируем данные
    // получаем максимальные и минимальные значения осей
    double x_min = ui->doubleSpinBox_x_min->value();
    double x_max = ui->doubleSpinBox_x_max->value();
    double y_min = ui->doubleSpinBox_y_min->value();
    double y_max = ui->doubleSpinBox_y_max->value();
    double h = 0.01; //Шаг, с которым будем пробегать по оси Ox
    int N = (x_max - x_min) / h + 1; //Вычисляем количество точек, которые будем отрисовывать
    QVector<double> x(N), y(N); //Массивы координат точек

    //Вычисляем наши данные
    int i=0;
    double res_p = 0.0;
    QString input = ui->result->text();
    int status = SUCCESS;
    node_t * output_list = NULL;
    status = convert_polish_notation (&output_list, (char*)input.toStdString().c_str());
    node_t * header_output_list = output_list;

    //Пробегаем по всем точкам
    double X = x_min;
    if (status > 0) {
        for (; i < N; i++) {
            x[i] = X;

            output_list = header_output_list;
            if (status == SUCCESS)
                status = calculate(output_list, &res_p, x[i], GRAPH_ON);

            y[i] = res_p;
            if (status <= 0) {
                ui->result->setText("ERROR");
                break;
            }


            X += h;
        }
    } else {
        ui->result->setText("ERROR");
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
    if (y_min == -10.0 && y_max == 10.0 ) {
        ui->widget->yAxis->setRange(minY, maxY);//если пользователь ничего не установил
        ui->doubleSpinBox_y_min->setValue(minY);
        ui->doubleSpinBox_y_max->setValue(maxY);
    }

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

void MainWindow::on_pushButton_clear_plot_clicked()
{
    // ставим по умолчанию значения осей
    ui->doubleSpinBox_x_min->setValue(-10.0);
    ui->doubleSpinBox_x_max->setValue(10.0);
    ui->doubleSpinBox_y_min->setValue(-10.0);
    ui->doubleSpinBox_y_max->setValue(10.0);

    // удаляем график
    ui->widget->clearGraphs();
    ui->widget->replot();
}

void MainWindow::on_Set_X_clicked()
{
    // проверка на валидные значения
    if (strspn(ui->result->text().toStdString().c_str(), "1234567890.e𝝅") > 0) {
        ui->x_value->setText(ui->result->text());
        ui->result->setText("0");
    }
    else
        ui->result->setText("ERROR");
}


void MainWindow::on_Clear_X_clicked()
{
    ui->x_value->setText("0");
}



void MainWindow::on_pushButton_credit_calc_clicked()
{
    credit->resize(1000,600);
    credit->show();
    this->close();
}

