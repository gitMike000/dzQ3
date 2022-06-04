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


void MainWindow::on_saveButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                                     tr("Save text"), Path, (tr("Text Files (*.txt)")));
    QFile f(fileName + ".txt");
    f.open(QIODevice::WriteOnly);
    QTextStream in (&f);
    in << ui->textEdit->toPlainText();
    f.flush();
    f.close();
}


void MainWindow::on_openButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                     tr("Open text"), Path, (tr("Text Files (*.txt)")));
    Path = QFileInfo(fileName).path();
    QFile f(fileName);
    f.open(QIODevice::ReadOnly);
    QTextStream in(&f);
    ui->textEdit->setText(in.readAll());
    f.close();
}


void MainWindow::on_helpButton_clicked()
{
    QFile h(":/help/text");
    h.open(QIODevice::ReadOnly);
    QTextStream in(&h);
    ui->textEdit->setText(in.readAll());
    h.close();
}


