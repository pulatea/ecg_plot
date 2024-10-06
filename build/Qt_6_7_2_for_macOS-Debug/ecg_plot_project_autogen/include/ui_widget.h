/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "/Users/teapula/Documents/AIM/C++/examples/ecg_plot/qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QCustomPlot *qcpwidget;
    QPushButton *load_ecg_button;
    QLabel *label;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(400, 300);
        qcpwidget = new QCustomPlot(Widget);
        qcpwidget->setObjectName("qcpwidget");
        qcpwidget->setGeometry(QRect(10, 10, 371, 231));
        qcpwidget->setMinimumSize(QSize(281, 0));
        load_ecg_button = new QPushButton(Widget);
        load_ecg_button->setObjectName("load_ecg_button");
        load_ecg_button->setGeometry(QRect(10, 250, 100, 41));
        load_ecg_button->setStyleSheet(QString::fromUtf8("background-color:blue;\n"
"color:white;"));
        label = new QLabel(Widget);
        label->setObjectName("label");
        label->setGeometry(QRect(120, 250, 151, 31));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Form", nullptr));
        load_ecg_button->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        label->setText(QCoreApplication::translate("Widget", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
