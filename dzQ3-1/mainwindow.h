#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
    namespace Ui { class MainWindow; }
QT_END_NAMESPACE

    class MainWindow : public QMainWindow
{
    Q_OBJECT

      public:
          MainWindow(QWidget *parent = nullptr);
         ~MainWindow();

      private slots:
          void on_saveButton_clicked();
          void on_openButton_clicked();
          void on_helpButton_clicked();

      private:
          Ui::MainWindow *ui;
          QString Path;
};
#endif // MAINWINDOW_H
