#ifndef NOISEPARAMSDIALOG_H
#define NOISEPARAMSDIALOG_H

#include <QDialog>

namespace Ui {
class NoiseParamsDialog;
}

class NoiseParamsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NoiseParamsDialog(QWidget *parent = nullptr);
    ~NoiseParamsDialog();

public slots:
    void setBoxesSlot(float, float);
    
signals:
    void sendParamsSignal(float, float);  

private:
    Ui::NoiseParamsDialog* ui;

private slots:
    void on_confirmButton_clicked();
    void on_declineButton_clicked();
};

#endif // NOISEPARAMSDIALOG_H
