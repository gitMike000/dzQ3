#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QTextStream>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    Path = "./";
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_openButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                     ("Open HTML file"), Path, ("Text Files (*.htm, *.html)"));
    Path = QFileInfo(fileName).path();
    QFile f(fileName);
    f.open(QIODevice::ReadOnly);
    QTextStream in(&f);
    QString stParse;
    stParse = in.readAll();
    QRegExp RegExp("(data-testid=\"weather-temp\">)(0|[+-]?[0-9]{1,2}°)(</span>)(.*)(<div class=\"rate__currency svelte-19b6xeo\">)([0-9]{1,2}\.[0-9]{1,2})(</div>)");
    RegExp.setMinimal(true);

    RegExp.indexIn(stParse, 0);
//    RegExp.cap(1);
    ui->wethLabel->setText(RegExp.cap(2));
//    RegExp.cap(3);
//    RegExp.cap(4);
//    RegExp.cap(5);
    ui->usbLabel->setText(RegExp.cap(6));
//    RegExp.cap(7);

    f.close();
}

