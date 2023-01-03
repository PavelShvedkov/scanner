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
/*
    std::vector<float> norm = gaussian(50000);

    std::ofstream out("/home/pavel/repositories/JupyterNB-main/MS/normal.txt", std::ios::app);

    std::default_random_engine generator;
    std::normal_distribution<float> uniform(0, 1);

    if (out.is_open())
    {
        for(int i =0; i<50000; i++)
        {
            //out << norm[i] << std::endl;
            out << uniform(generator) << std::endl;
        }
    }

    out.close();

    return 0;*/
}
