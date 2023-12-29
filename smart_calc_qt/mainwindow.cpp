#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox> // библиотека для диалогового окна

#include "../s21_smartcalc.h"

/**
 * @brief Конструктор класса MainWindow.
 *
 * Конструктор инициализирует интерфейс пользователя и устанавливает необходимые соединения между сигналами и слотами.
 *
 * @param parent Указатель на родительский виджет.
 */
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

/**
 * @brief Деструктор класса MainWindow.
 *
 * Деструктор освобождает ресурсы, выделенные для интерфейса пользователя.
 */
MainWindow::~MainWindow()
{
    delete ui;
}


/**
 * @brief Добавляет число или символ к текущему результату.
 *
 * Эта функция вызывается, когда пользователь нажимает кнопку с числовым значением или оператором. Она добавляет текст кнопки к текущему результату.
 */
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


/**
 * @brief Очищает поле результата.
 *
 * Эта функция вызывается, когда пользователь нажимает кнопку "AC". Она обнуляет поле результата.
 */
void MainWindow::on_pushButton_ac_clicked()
{

    ui->result_show->setText("0");
}

/**
 * @brief Выполняет расчет.
 *
 * Эта функция вызывается, когда пользователь нажимает кнопку "=". Она преобразует введенную пользователем строку в число и выводит результат расчета.
 */
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

/**
 * @brief Устанавливает значение x.
 *
 * Эта функция вызывается, когда пользователь нажимает кнопку "Set x". Она устанавливает значение x равным текущему результату.
 */
void MainWindow::on_pushButton_set_x_clicked()
{
    ui->x_g->setText(ui->result_show->text());
}

/**
 * @brief Очищает значение x.
 *
 * Эта функция вызывается, когда пользователь нажимает кнопку "Clear x". Она обнуляет значение x.
 */
void MainWindow::on_pushButton_clear_x_clicked()
{
    ui->x_g->setText("0");
}


/**
 * @brief Выполняет расчет с использованием значения x.
 *
 * Эта функция вызывается, когда пользователь нажимает кнопку "Calc x". Она преобразует введенную пользователем строку```
*/
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

/**
*@brief Генерирует и отображает график.
*Эта функция вызывается, когда пользователь нажимает кнопку "Graph". Она генерирует данные для графика, устанавливает параметры графика и отображает его. 
*/
void MainWindow::on_pushButton_graph_clicked()
{
    //Сгенерируем данные
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









