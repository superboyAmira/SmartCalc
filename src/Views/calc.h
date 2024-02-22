#ifndef CALC_H
#define CALC_H

#include <QMainWindow>
#include "credit.h"
#include "deposit.h"

#include "../Controllers/calc_controller.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Calc;
}
QT_END_NAMESPACE

class Calc : public QMainWindow
{
    Q_OBJECT

public:
    Calc(QWidget *parent = nullptr);
    ~Calc();

private slots:
    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_0_clicked();

    void on_pushButton_dot_clicked();

    void on_pushButton_plus_clicked();

    void on_pushButton_minus_clicked();

    void on_pushButton_mul_clicked();

    void on_pushButton_del_clicked();

    void on_pushButton_mod_clicked();

    void on_pushButton_clear_clicked();

    void on_pushButton_equal_sign_clicked();

    void on_pushButton_un_minus_clicked();

    void on_pushButton_scale_clicked();

    void on_pushButton_bracket_close_clicked();

    void on_pushButton_bracket_open_clicked();

    void on_pushButton_cos_clicked();

    void on_pushButton_sin_clicked();

    void on_pushButton_tan_clicked();

    void on_pushButton_acos_clicked();

    void on_pushButton_asin_clicked();

    void on_pushButton_atan_clicked();

    void on_pushButton_sqrt_clicked();

    void on_pushButton_ln_clicked();

    void on_pushButton_log_clicked();

    void on_pushButton_x_clicked();

    void on_pushButton_draw_graph_clicked();

    void on_pushButton_credit_clicked();

    void on_pushButton_Deposit_clicked();

private:
    Ui::Calc *ui;

    Credit ui_credit;
    Deposit ui_deposit;
    s21::CalcController controller;

};
#endif // CALC_H
