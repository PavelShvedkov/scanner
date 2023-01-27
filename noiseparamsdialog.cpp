#include "noiseparamsdialog.h"
#include "ui_noiseparamsdialog.h"

NoiseParamsDialog::NoiseParamsDialog(QWidget* parent) :
	QDialog(parent),
	ui(new Ui::NoiseParamsDialog)
{
	ui->setupUi(this);
}

NoiseParamsDialog::~NoiseParamsDialog()
{
	delete ui;
}

void NoiseParamsDialog::setBoxesSlot(float mean, float stdDev)
{
	ui->meanBox->setText(QString::number(mean));
	ui->devBox->setText(QString::number(stdDev));
}

void NoiseParamsDialog::on_confirmButton_clicked()
{ 
	emit sendParamsSignal((ui->meanBox->text()).toFloat(), (ui->devBox->text()).toFloat());
}


void NoiseParamsDialog::on_declineButton_clicked()
{
	emit sendParamsSignal(0, 0.1);
}

