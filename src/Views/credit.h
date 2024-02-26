#ifndef CREDIT_H
#define CREDIT_H

#include <QWidget>

#include "../Controllers/credit_controller.h"

namespace Ui {
class Credit;
}

class Credit : public QWidget {
  Q_OBJECT

 public:
  explicit Credit(QWidget *parent = nullptr);
  ~Credit();

 private slots:
  void on_pushButton_calculate_clicked();

 private:
  Ui::Credit *ui;
  s21::CreditController controller;
};

#endif  // CREDIT_H
