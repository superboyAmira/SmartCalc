#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QVector>

#ifdef __cplusplus
extern "C"
{
    #include "../Model/s21_calc.h"
}
#endif

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void FormatFont();

private slots:
    void ViewNums();

    void ViewOperators();

    void ViewFuncs();

    void ViewBracket();

    void DrawGraph();

    void ResultCredit();

    void ResultDeposit();

private:
    Ui::MainWindow *ui;

    double xBegin, xEnd, step, X;
    QVector<double> x, y;

};

// help functions

char * QStringToChar(QString src);

#endif // MAINWINDOW_H
