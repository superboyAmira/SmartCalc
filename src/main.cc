#include "../Views/calc.h"
// #include <locale.h>

#include <QApplication>

int main(int argc, char *argv[])
{
    // setlocale(LC_ALL,"en_us");
    QApplication a(argc, argv);
    Calc w;
    w.show();
    return a.exec();
}
