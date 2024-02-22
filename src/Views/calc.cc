#include "calc.h"
#include "ui_calc.h"

Calc::Calc(QWidget *parent) : QMainWindow(parent), ui(new Ui::Calc)
{
    ui->setupUi(this);
    ui->label_equation->setText("acos(x)+asin(x)+atan(0.1)");
    ui->doubleSpinBox_x_min->setValue(-10);
    ui->doubleSpinBox_x_max->setValue(10);
    ui->doubleSpinBox_y_min->setValue(-10);
    ui->doubleSpinBox_y_max->setValue(10);
}

Calc::~Calc()
{
    delete ui;
}

void Calc::on_pushButton_draw_graph_clicked()
{
    controller.updateGraph(ui->widget_graph, ui->label_equation, ui->doubleSpinBox_x_max->value(), ui->doubleSpinBox_x_min->value(), ui->doubleSpinBox_y_max->value(), ui->doubleSpinBox_y_min->value());
}

void Calc::on_pushButton_equal_sign_clicked()
{
    controller.upadteViewModel(ui->label_equation, ui->label_equation->text(), ui->doubleSpinBox_x->value(), ui->checkBox_x);
}

void Calc::on_pushButton_1_clicked()
{
    controller.UpdateViewInstantly(ui->label_equation, "1");
}

void Calc::on_pushButton_2_clicked()
{
    controller.UpdateViewInstantly(ui->label_equation, "2");
}

void Calc::on_pushButton_3_clicked()
{
    controller.UpdateViewInstantly(ui->label_equation, "3");
}

void Calc::on_pushButton_4_clicked()
{
    controller.UpdateViewInstantly(ui->label_equation, "4");
}

void Calc::on_pushButton_5_clicked()
{
    controller.UpdateViewInstantly(ui->label_equation, "5");
}

void Calc::on_pushButton_6_clicked()
{
    controller.UpdateViewInstantly(ui->label_equation, "6");
}

void Calc::on_pushButton_7_clicked()
{
    controller.UpdateViewInstantly(ui->label_equation, "7");
}

void Calc::on_pushButton_8_clicked()
{
    controller.UpdateViewInstantly(ui->label_equation, "8");
}

void Calc::on_pushButton_9_clicked()
{
    controller.UpdateViewInstantly(ui->label_equation, "9");
}

void Calc::on_pushButton_0_clicked()
{
    controller.UpdateViewInstantly(ui->label_equation, "0");
}

void Calc::on_pushButton_dot_clicked()
{
    controller.UpdateViewInstantly(ui->label_equation, ".");
}

void Calc::on_pushButton_plus_clicked()
{
    controller.UpdateViewInstantly(ui->label_equation, "+");
}

void Calc::on_pushButton_minus_clicked()
{
    controller.UpdateViewInstantly(ui->label_equation, "-");
}

void Calc::on_pushButton_mul_clicked()
{
    controller.UpdateViewInstantly(ui->label_equation, "*");
}

void Calc::on_pushButton_del_clicked()
{
    controller.UpdateViewInstantly(ui->label_equation, "/");
}

void Calc::on_pushButton_mod_clicked()
{
    controller.UpdateViewInstantly(ui->label_equation, "%");
}
void Calc::on_pushButton_clear_clicked()
{
    controller.DefaultView(ui->label_equation);
}

void Calc::on_pushButton_un_minus_clicked()
{
    controller.UpdateViewInstantly(ui->label_equation, "~");
}

void Calc::on_pushButton_scale_clicked()
{
    controller.UpdateViewInstantly(ui->label_equation, "^");
}

void Calc::on_pushButton_bracket_close_clicked()
{
    controller.UpdateViewInstantly(ui->label_equation, ")");
}

void Calc::on_pushButton_bracket_open_clicked()
{
    controller.UpdateViewInstantly(ui->label_equation, "(");
}

void Calc::on_pushButton_cos_clicked()
{
    controller.UpdateViewInstantly(ui->label_equation, "cos(");
}

void Calc::on_pushButton_sin_clicked()
{
    controller.UpdateViewInstantly(ui->label_equation, "sin(");
}

void Calc::on_pushButton_tan_clicked()
{
    controller.UpdateViewInstantly(ui->label_equation, "tan(");
}

void Calc::on_pushButton_acos_clicked()
{
    controller.UpdateViewInstantly(ui->label_equation, "acos(");
}

void Calc::on_pushButton_asin_clicked()
{
    controller.UpdateViewInstantly(ui->label_equation, "asin(");
}

void Calc::on_pushButton_atan_clicked()
{
    controller.UpdateViewInstantly(ui->label_equation, "atan(");
}

void Calc::on_pushButton_sqrt_clicked()
{
    controller.UpdateViewInstantly(ui->label_equation, "sqrt(");
}

void Calc::on_pushButton_ln_clicked()
{
    controller.UpdateViewInstantly(ui->label_equation, "ln(");
}

void Calc::on_pushButton_log_clicked()
{
    controller.UpdateViewInstantly(ui->label_equation, "log(");
}

void Calc::on_pushButton_x_clicked()
{
    controller.UpdateViewInstantly(ui->label_equation, "x");
}

void Calc::on_pushButton_credit_clicked()
{
    ui_credit.show();
}

void Calc::on_pushButton_Deposit_clicked()
{
    ui_deposit.show();
}

