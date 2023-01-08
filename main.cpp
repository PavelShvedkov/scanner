#include "mainwindow.h"

#include <QApplication>
#include "distributions.h"
#include <iostream>
#include <fstream>
#include <random>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
