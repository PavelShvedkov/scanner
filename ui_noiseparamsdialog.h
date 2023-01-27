/********************************************************************************
** Form generated from reading UI file 'noiseparamsdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOISEPARAMSDIALOG_H
#define UI_NOISEPARAMSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NoiseParamsDialog
{
public:
    QWidget *verticalWidget;
    QGridLayout *gridLayout;
    QPushButton *declineButton;
    QLineEdit *devBox;
    QLabel *meanLabel;
    QPushButton *confirmButton;
    QLineEdit *meanBox;
    QLabel *devLabel;

    void setupUi(QDialog *NoiseParamsDialog)
    {
        if (NoiseParamsDialog->objectName().isEmpty())
            NoiseParamsDialog->setObjectName("NoiseParamsDialog");
        NoiseParamsDialog->resize(222, 160);
        NoiseParamsDialog->setMinimumSize(QSize(222, 160));
        NoiseParamsDialog->setMaximumSize(QSize(222, 160));
        NoiseParamsDialog->setSizeGripEnabled(false);
        NoiseParamsDialog->setModal(true);
        verticalWidget = new QWidget(NoiseParamsDialog);
        verticalWidget->setObjectName("verticalWidget");
        verticalWidget->setGeometry(QRect(10, 10, 201, 141));
        verticalWidget->setMinimumSize(QSize(201, 141));
        gridLayout = new QGridLayout(verticalWidget);
        gridLayout->setObjectName("gridLayout");
        declineButton = new QPushButton(verticalWidget);
        declineButton->setObjectName("declineButton");

        gridLayout->addWidget(declineButton, 5, 0, 1, 3);

        devBox = new QLineEdit(verticalWidget);
        devBox->setObjectName("devBox");

        gridLayout->addWidget(devBox, 0, 1, 1, 1);

        meanLabel = new QLabel(verticalWidget);
        meanLabel->setObjectName("meanLabel");

        gridLayout->addWidget(meanLabel, 2, 0, 1, 1);

        confirmButton = new QPushButton(verticalWidget);
        confirmButton->setObjectName("confirmButton");

        gridLayout->addWidget(confirmButton, 4, 0, 1, 3);

        meanBox = new QLineEdit(verticalWidget);
        meanBox->setObjectName("meanBox");

        gridLayout->addWidget(meanBox, 2, 1, 1, 1);

        devLabel = new QLabel(verticalWidget);
        devLabel->setObjectName("devLabel");

        gridLayout->addWidget(devLabel, 0, 0, 1, 1);


        retranslateUi(NoiseParamsDialog);

        QMetaObject::connectSlotsByName(NoiseParamsDialog);
    } // setupUi

    void retranslateUi(QDialog *NoiseParamsDialog)
    {
        NoiseParamsDialog->setWindowTitle(QCoreApplication::translate("NoiseParamsDialog", "Dialog", nullptr));
        declineButton->setText(QCoreApplication::translate("NoiseParamsDialog", "Decline", nullptr));
        meanLabel->setText(QCoreApplication::translate("NoiseParamsDialog", "Mean", nullptr));
        confirmButton->setText(QCoreApplication::translate("NoiseParamsDialog", "Accept", nullptr));
        devLabel->setText(QCoreApplication::translate("NoiseParamsDialog", "Standart deviation", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NoiseParamsDialog: public Ui_NoiseParamsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOISEPARAMSDIALOG_H
