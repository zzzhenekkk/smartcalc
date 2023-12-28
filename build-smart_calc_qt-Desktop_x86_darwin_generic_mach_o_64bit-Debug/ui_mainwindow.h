/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *result_show;
    QPushButton *pushButton_ac;
    QPushButton *pushButton_pow;
    QPushButton *pushButton_mod;
    QPushButton *pushButton_mult;
    QPushButton *pushButton_div;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_minus;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_plus;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_eq;
    QPushButton *pushButton_0;
    QPushButton *pushButton_dot;
    QPushButton *pushButton_sin;
    QPushButton *pushButton_cos;
    QPushButton *pushButton_acos;
    QPushButton *pushButton_asin;
    QPushButton *pushButton_ln;
    QPushButton *pushButton_log;
    QPushButton *pushButton_atan;
    QPushButton *pushButton_tan;
    QPushButton *pushButton_ob;
    QPushButton *pushButton_cb;
    QPushButton *pushButton_x;
    QPushButton *pushButton_sqrt;
    QLabel *x_g;
    QPushButton *pushButton_graph;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(632, 474);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        result_show = new QLabel(centralwidget);
        result_show->setObjectName(QString::fromUtf8("result_show"));
        result_show->setGeometry(QRect(50, 30, 281, 61));
        QFont font;
        font.setPointSize(20);
        result_show->setFont(font);
        result_show->setStyleSheet(QString::fromUtf8("QLabel {\n"
"  qproperty-alignment: 'AlignVCenter | AlignRight';\n"
"}\n"
"\n"
"background-color : rgb(82, 76, 75);"));
        result_show->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pushButton_ac = new QPushButton(centralwidget);
        pushButton_ac->setObjectName(QString::fromUtf8("pushButton_ac"));
        pushButton_ac->setGeometry(QRect(100, 90, 61, 61));
        pushButton_ac->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(93, 86, 87);\n"
"  border: 1px solid rgb(82, 76, 76);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_pow = new QPushButton(centralwidget);
        pushButton_pow->setObjectName(QString::fromUtf8("pushButton_pow"));
        pushButton_pow->setGeometry(QRect(160, 90, 61, 61));
        pushButton_pow->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(93, 86, 87);\n"
"  border: 1px solid rgb(82, 76, 76);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_mod = new QPushButton(centralwidget);
        pushButton_mod->setObjectName(QString::fromUtf8("pushButton_mod"));
        pushButton_mod->setGeometry(QRect(220, 90, 61, 61));
        pushButton_mod->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(93, 86, 87);\n"
"  border: 1px solid rgb(82, 76, 76);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_mult = new QPushButton(centralwidget);
        pushButton_mult->setObjectName(QString::fromUtf8("pushButton_mult"));
        pushButton_mult->setGeometry(QRect(280, 90, 61, 61));
        pushButton_mult->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(241, 163, 60);\n"
"  border: 1px solid rgb(82, 76, 76);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_div = new QPushButton(centralwidget);
        pushButton_div->setObjectName(QString::fromUtf8("pushButton_div"));
        pushButton_div->setGeometry(QRect(280, 150, 61, 61));
        pushButton_div->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(241, 163, 60);\n"
"  border: 1px solid rgb(82, 76, 76);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(100, 150, 61, 61));
        pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(123, 120, 120);\n"
"  border: 1px solid rgb(82, 76, 76);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(160, 150, 61, 61));
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(123, 120, 120);\n"
"  border: 1px solid rgb(82, 76, 76);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(220, 150, 61, 61));
        pushButton_9->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(123, 120, 120);\n"
"  border: 1px solid rgb(82, 76, 76);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_1 = new QPushButton(centralwidget);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        pushButton_1->setGeometry(QRect(100, 270, 61, 61));
        pushButton_1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(123, 120, 120);\n"
"  border: 1px solid rgb(82, 76, 76);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(160, 270, 61, 61));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(123, 120, 120);\n"
"  border: 1px solid rgb(82, 76, 76);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_minus = new QPushButton(centralwidget);
        pushButton_minus->setObjectName(QString::fromUtf8("pushButton_minus"));
        pushButton_minus->setGeometry(QRect(280, 270, 61, 61));
        pushButton_minus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(241, 163, 60);\n"
"  border: 1px solid rgb(82, 76, 76);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(100, 210, 61, 61));
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(123, 120, 120);\n"
"  border: 1px solid rgb(82, 76, 76);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(220, 270, 61, 61));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(123, 120, 120);\n"
"  border: 1px solid rgb(82, 76, 76);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_plus = new QPushButton(centralwidget);
        pushButton_plus->setObjectName(QString::fromUtf8("pushButton_plus"));
        pushButton_plus->setGeometry(QRect(280, 210, 61, 61));
        pushButton_plus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(241, 163, 60);\n"
"  border: 1px solid rgb(82, 76, 76);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(160, 210, 61, 61));
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(123, 120, 120);\n"
"  border: 1px solid rgb(82, 76, 76);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(220, 210, 61, 61));
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(123, 120, 120);\n"
"  border: 1px solid rgb(82, 76, 76);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_eq = new QPushButton(centralwidget);
        pushButton_eq->setObjectName(QString::fromUtf8("pushButton_eq"));
        pushButton_eq->setGeometry(QRect(280, 330, 61, 61));
        pushButton_eq->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(241, 163, 60);\n"
"  border: 1px solid rgb(82, 76, 76);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_0 = new QPushButton(centralwidget);
        pushButton_0->setObjectName(QString::fromUtf8("pushButton_0"));
        pushButton_0->setGeometry(QRect(100, 330, 121, 61));
        pushButton_0->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(123, 120, 120);\n"
"  border: 1px solid rgb(82, 76, 76);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_dot = new QPushButton(centralwidget);
        pushButton_dot->setObjectName(QString::fromUtf8("pushButton_dot"));
        pushButton_dot->setGeometry(QRect(220, 330, 61, 61));
        pushButton_dot->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(123, 120, 120);\n"
"  border: 1px solid rgb(82, 76, 76);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_sin = new QPushButton(centralwidget);
        pushButton_sin->setObjectName(QString::fromUtf8("pushButton_sin"));
        pushButton_sin->setGeometry(QRect(40, 120, 61, 31));
        pushButton_sin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(93, 86, 87);\n"
"  border: 1px solid rgb(82, 76, 76);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_cos = new QPushButton(centralwidget);
        pushButton_cos->setObjectName(QString::fromUtf8("pushButton_cos"));
        pushButton_cos->setGeometry(QRect(40, 150, 61, 31));
        pushButton_cos->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(93, 86, 87);\n"
"  border: 1px solid rgb(82, 76, 76);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_acos = new QPushButton(centralwidget);
        pushButton_acos->setObjectName(QString::fromUtf8("pushButton_acos"));
        pushButton_acos->setGeometry(QRect(40, 210, 61, 31));
        pushButton_acos->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(93, 86, 87);\n"
"  border: 1px solid rgb(82, 76, 76);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_asin = new QPushButton(centralwidget);
        pushButton_asin->setObjectName(QString::fromUtf8("pushButton_asin"));
        pushButton_asin->setGeometry(QRect(40, 180, 61, 31));
        pushButton_asin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(93, 86, 87);\n"
"  border: 1px solid rgb(82, 76, 76);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_ln = new QPushButton(centralwidget);
        pushButton_ln->setObjectName(QString::fromUtf8("pushButton_ln"));
        pushButton_ln->setGeometry(QRect(40, 300, 61, 31));
        pushButton_ln->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(93, 86, 87);\n"
"  border: 1px solid rgb(82, 76, 76);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_log = new QPushButton(centralwidget);
        pushButton_log->setObjectName(QString::fromUtf8("pushButton_log"));
        pushButton_log->setGeometry(QRect(40, 330, 61, 31));
        pushButton_log->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(93, 86, 87);\n"
"  border: 1px solid rgb(82, 76, 76);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_atan = new QPushButton(centralwidget);
        pushButton_atan->setObjectName(QString::fromUtf8("pushButton_atan"));
        pushButton_atan->setGeometry(QRect(40, 270, 61, 31));
        pushButton_atan->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(93, 86, 87);\n"
"  border: 1px solid rgb(82, 76, 76);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_tan = new QPushButton(centralwidget);
        pushButton_tan->setObjectName(QString::fromUtf8("pushButton_tan"));
        pushButton_tan->setGeometry(QRect(40, 240, 61, 31));
        pushButton_tan->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(93, 86, 87);\n"
"  border: 1px solid rgb(82, 76, 76);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_ob = new QPushButton(centralwidget);
        pushButton_ob->setObjectName(QString::fromUtf8("pushButton_ob"));
        pushButton_ob->setGeometry(QRect(40, 90, 31, 31));
        pushButton_ob->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(93, 86, 87);\n"
"  border: 1px solid rgb(82, 76, 76);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_cb = new QPushButton(centralwidget);
        pushButton_cb->setObjectName(QString::fromUtf8("pushButton_cb"));
        pushButton_cb->setGeometry(QRect(70, 90, 31, 31));
        pushButton_cb->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(93, 86, 87);\n"
"  border: 1px solid rgb(82, 76, 76);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_x = new QPushButton(centralwidget);
        pushButton_x->setObjectName(QString::fromUtf8("pushButton_x"));
        pushButton_x->setGeometry(QRect(40, 390, 61, 31));
        pushButton_x->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(93, 86, 87);\n"
"  border: 1px solid rgb(82, 76, 76);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_sqrt = new QPushButton(centralwidget);
        pushButton_sqrt->setObjectName(QString::fromUtf8("pushButton_sqrt"));
        pushButton_sqrt->setGeometry(QRect(40, 360, 61, 31));
        pushButton_sqrt->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(93, 86, 87);\n"
"  border: 1px solid rgb(82, 76, 76);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        x_g = new QLabel(centralwidget);
        x_g->setObjectName(QString::fromUtf8("x_g"));
        x_g->setGeometry(QRect(100, 390, 121, 31));
        x_g->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(236, 236, 236);\n"
"  border: 1px solid rgb(82, 76, 76);\n"
"}"));
        pushButton_graph = new QPushButton(centralwidget);
        pushButton_graph->setObjectName(QString::fromUtf8("pushButton_graph"));
        pushButton_graph->setGeometry(QRect(220, 390, 61, 31));
        pushButton_graph->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(93, 86, 87);\n"
"  border: 1px solid rgb(82, 76, 76);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        result_show->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_ac->setText(QCoreApplication::translate("MainWindow", "AC", nullptr));
        pushButton_pow->setText(QCoreApplication::translate("MainWindow", "^", nullptr));
        pushButton_mod->setText(QCoreApplication::translate("MainWindow", "mod", nullptr));
        pushButton_mult->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        pushButton_div->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        pushButton_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        pushButton_minus->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        pushButton_plus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        pushButton_eq->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        pushButton_0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_dot->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        pushButton_sin->setText(QCoreApplication::translate("MainWindow", "sin", nullptr));
        pushButton_cos->setText(QCoreApplication::translate("MainWindow", "cos", nullptr));
        pushButton_acos->setText(QCoreApplication::translate("MainWindow", "acos", nullptr));
        pushButton_asin->setText(QCoreApplication::translate("MainWindow", "asin", nullptr));
        pushButton_ln->setText(QCoreApplication::translate("MainWindow", "ln", nullptr));
        pushButton_log->setText(QCoreApplication::translate("MainWindow", "log", nullptr));
        pushButton_atan->setText(QCoreApplication::translate("MainWindow", "atan", nullptr));
        pushButton_tan->setText(QCoreApplication::translate("MainWindow", "tan", nullptr));
        pushButton_ob->setText(QCoreApplication::translate("MainWindow", "(", nullptr));
        pushButton_cb->setText(QCoreApplication::translate("MainWindow", ")", nullptr));
        pushButton_x->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        pushButton_sqrt->setText(QCoreApplication::translate("MainWindow", "sqrt", nullptr));
        x_g->setText(QCoreApplication::translate("MainWindow", "   0", nullptr));
        pushButton_graph->setText(QCoreApplication::translate("MainWindow", "graph", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
