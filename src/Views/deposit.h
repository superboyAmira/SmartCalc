#ifndef DEPOSIT_H
#define DEPOSIT_H

#include <QWidget>
#include "../Controllers/deposit_controller.h"

namespace Ui {
class Deposit;
}

class Deposit : public QWidget
{
    Q_OBJECT

public:
    explicit Deposit(QWidget *parent = nullptr);
    ~Deposit();

private:
    Ui::Deposit *ui;
};

#endif // DEPOSIT_H
