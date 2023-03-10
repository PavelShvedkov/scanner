/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "qwt_plot.h"
#include "qwt_text_label.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QwtPlot *qwtPlot;
    QwtPlot *qwtPlotBright;
    QFormLayout *formLayout_3;
    QwtTextLabel *blStrLabel;
    QLineEdit *blStrBox;
    QwtTextLabel *whStrLabel;
    QLineEdit *whStrBox;
    QwtTextLabel *zMaxLabel;
    QLineEdit *zMaxBox;
    QwtTextLabel *stepLabel;
    QLineEdit *stepBox;
    QwtTextLabel *countsLabel;
    QLineEdit *countsBox;
    QwtTextLabel *maxBrLabel;
    QLineEdit *maxBrBox;
    QwtTextLabel *minBrLabel;
    QLineEdit *minBrBox;
    QPushButton *plotButton;
    QPushButton *startButton;
    QPushButton *stopButton;
    QPushButton *defaultButton;
    QPushButton *noiseSetButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(832, 445);
        MainWindow->setMinimumSize(QSize(768, 0));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setEnabled(true);
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout_2->setContentsMargins(-1, -1, -1, 9);
        qwtPlot = new QwtPlot(centralwidget);
        qwtPlot->setObjectName("qwtPlot");
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(qwtPlot->sizePolicy().hasHeightForWidth());
        qwtPlot->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(qwtPlot);

        qwtPlotBright = new QwtPlot(centralwidget);
        qwtPlotBright->setObjectName("qwtPlotBright");
        qwtPlotBright->setProperty("autoReplot", QVariant(false));

        horizontalLayout_2->addWidget(qwtPlotBright);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName("formLayout_3");
        formLayout_3->setSizeConstraint(QLayout::SetNoConstraint);
        formLayout_3->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout_3->setRowWrapPolicy(QFormLayout::DontWrapRows);
        formLayout_3->setLabelAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        formLayout_3->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        formLayout_3->setHorizontalSpacing(15);
        formLayout_3->setVerticalSpacing(6);
        formLayout_3->setContentsMargins(0, -1, -1, -1);
        blStrLabel = new QwtTextLabel(centralwidget);
        blStrLabel->setObjectName("blStrLabel");
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(blStrLabel->sizePolicy().hasHeightForWidth());
        blStrLabel->setSizePolicy(sizePolicy1);
        blStrLabel->setLineWidth(1);
        blStrLabel->setProperty("indent", QVariant(10));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, blStrLabel);

        blStrBox = new QLineEdit(centralwidget);
        blStrBox->setObjectName("blStrBox");
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(blStrBox->sizePolicy().hasHeightForWidth());
        blStrBox->setSizePolicy(sizePolicy2);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, blStrBox);

        whStrLabel = new QwtTextLabel(centralwidget);
        whStrLabel->setObjectName("whStrLabel");
        sizePolicy1.setHeightForWidth(whStrLabel->sizePolicy().hasHeightForWidth());
        whStrLabel->setSizePolicy(sizePolicy1);

        formLayout_3->setWidget(1, QFormLayout::LabelRole, whStrLabel);

        whStrBox = new QLineEdit(centralwidget);
        whStrBox->setObjectName("whStrBox");
        sizePolicy2.setHeightForWidth(whStrBox->sizePolicy().hasHeightForWidth());
        whStrBox->setSizePolicy(sizePolicy2);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, whStrBox);

        zMaxLabel = new QwtTextLabel(centralwidget);
        zMaxLabel->setObjectName("zMaxLabel");
        sizePolicy1.setHeightForWidth(zMaxLabel->sizePolicy().hasHeightForWidth());
        zMaxLabel->setSizePolicy(sizePolicy1);

        formLayout_3->setWidget(2, QFormLayout::LabelRole, zMaxLabel);

        zMaxBox = new QLineEdit(centralwidget);
        zMaxBox->setObjectName("zMaxBox");
        sizePolicy2.setHeightForWidth(zMaxBox->sizePolicy().hasHeightForWidth());
        zMaxBox->setSizePolicy(sizePolicy2);

        formLayout_3->setWidget(2, QFormLayout::FieldRole, zMaxBox);

        stepLabel = new QwtTextLabel(centralwidget);
        stepLabel->setObjectName("stepLabel");
        sizePolicy1.setHeightForWidth(stepLabel->sizePolicy().hasHeightForWidth());
        stepLabel->setSizePolicy(sizePolicy1);

        formLayout_3->setWidget(3, QFormLayout::LabelRole, stepLabel);

        stepBox = new QLineEdit(centralwidget);
        stepBox->setObjectName("stepBox");
        sizePolicy2.setHeightForWidth(stepBox->sizePolicy().hasHeightForWidth());
        stepBox->setSizePolicy(sizePolicy2);

        formLayout_3->setWidget(3, QFormLayout::FieldRole, stepBox);

        countsLabel = new QwtTextLabel(centralwidget);
        countsLabel->setObjectName("countsLabel");
        sizePolicy1.setHeightForWidth(countsLabel->sizePolicy().hasHeightForWidth());
        countsLabel->setSizePolicy(sizePolicy1);

        formLayout_3->setWidget(4, QFormLayout::LabelRole, countsLabel);

        countsBox = new QLineEdit(centralwidget);
        countsBox->setObjectName("countsBox");
        sizePolicy2.setHeightForWidth(countsBox->sizePolicy().hasHeightForWidth());
        countsBox->setSizePolicy(sizePolicy2);

        formLayout_3->setWidget(4, QFormLayout::FieldRole, countsBox);

        maxBrLabel = new QwtTextLabel(centralwidget);
        maxBrLabel->setObjectName("maxBrLabel");
        sizePolicy1.setHeightForWidth(maxBrLabel->sizePolicy().hasHeightForWidth());
        maxBrLabel->setSizePolicy(sizePolicy1);

        formLayout_3->setWidget(5, QFormLayout::LabelRole, maxBrLabel);

        maxBrBox = new QLineEdit(centralwidget);
        maxBrBox->setObjectName("maxBrBox");
        sizePolicy2.setHeightForWidth(maxBrBox->sizePolicy().hasHeightForWidth());
        maxBrBox->setSizePolicy(sizePolicy2);

        formLayout_3->setWidget(5, QFormLayout::FieldRole, maxBrBox);

        minBrLabel = new QwtTextLabel(centralwidget);
        minBrLabel->setObjectName("minBrLabel");
        sizePolicy1.setHeightForWidth(minBrLabel->sizePolicy().hasHeightForWidth());
        minBrLabel->setSizePolicy(sizePolicy1);

        formLayout_3->setWidget(6, QFormLayout::LabelRole, minBrLabel);

        minBrBox = new QLineEdit(centralwidget);
        minBrBox->setObjectName("minBrBox");
        sizePolicy2.setHeightForWidth(minBrBox->sizePolicy().hasHeightForWidth());
        minBrBox->setSizePolicy(sizePolicy2);

        formLayout_3->setWidget(6, QFormLayout::FieldRole, minBrBox);

        plotButton = new QPushButton(centralwidget);
        plotButton->setObjectName("plotButton");
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(plotButton->sizePolicy().hasHeightForWidth());
        plotButton->setSizePolicy(sizePolicy3);

        formLayout_3->setWidget(7, QFormLayout::SpanningRole, plotButton);

        startButton = new QPushButton(centralwidget);
        startButton->setObjectName("startButton");
        startButton->setEnabled(true);
        sizePolicy3.setHeightForWidth(startButton->sizePolicy().hasHeightForWidth());
        startButton->setSizePolicy(sizePolicy3);
        startButton->setCheckable(true);
        startButton->setChecked(false);
        startButton->setFlat(false);

        formLayout_3->setWidget(8, QFormLayout::SpanningRole, startButton);

        stopButton = new QPushButton(centralwidget);
        stopButton->setObjectName("stopButton");
        sizePolicy3.setHeightForWidth(stopButton->sizePolicy().hasHeightForWidth());
        stopButton->setSizePolicy(sizePolicy3);

        formLayout_3->setWidget(9, QFormLayout::SpanningRole, stopButton);

        defaultButton = new QPushButton(centralwidget);
        defaultButton->setObjectName("defaultButton");

        formLayout_3->setWidget(10, QFormLayout::SpanningRole, defaultButton);

        noiseSetButton = new QPushButton(centralwidget);
        noiseSetButton->setObjectName("noiseSetButton");

        formLayout_3->setWidget(11, QFormLayout::SpanningRole, noiseSetButton);


        horizontalLayout_2->addLayout(formLayout_3);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 832, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        blStrLabel->setProperty("plainText", QVariant(QCoreApplication::translate("MainWindow", "Black strip width", nullptr)));
        whStrLabel->setProperty("plainText", QVariant(QCoreApplication::translate("MainWindow", "White strip width", nullptr)));
        zMaxLabel->setProperty("plainText", QVariant(QCoreApplication::translate("MainWindow", "z max", nullptr)));
        stepLabel->setProperty("plainText", QVariant(QCoreApplication::translate("MainWindow", "Step", nullptr)));
        countsLabel->setProperty("plainText", QVariant(QCoreApplication::translate("MainWindow", "Counts", nullptr)));
        maxBrLabel->setProperty("plainText", QVariant(QCoreApplication::translate("MainWindow", "Max brightness", nullptr)));
        minBrLabel->setProperty("plainText", QVariant(QCoreApplication::translate("MainWindow", "Min brightness", nullptr)));
        plotButton->setText(QCoreApplication::translate("MainWindow", "Plot", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        stopButton->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        defaultButton->setText(QCoreApplication::translate("MainWindow", "Default", nullptr));
        noiseSetButton->setText(QCoreApplication::translate("MainWindow", "Noise setting", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
