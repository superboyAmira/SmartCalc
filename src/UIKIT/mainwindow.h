#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../s21_calc.h"

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
    void ViewNums();

    void ViewOperators();

    void ViewFuncs();

    void ViewBracket();

private:
    Ui::MainWindow *ui;

    void FormatFont();

    void Calculation();

};
#endif // MAINWINDOW_H
