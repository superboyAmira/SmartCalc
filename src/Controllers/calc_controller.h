#ifndef CALC_CONTROLLER_H
#define CALC_CONTROLLER_H

#include <QLabel>
#include <QString>
#include <QCheckBox>
#include <QMessageBox>
#include "qcustomplot.h"

// #include <QDebug>

#include "../Models/calc_model.h"

namespace s21 {

class CalcController {
public:
    CalcController() noexcept {};
    ~CalcController() noexcept = default;

    void UpdateViewInstantly(QLabel* label, const QString& text) const noexcept {
        label->setText(label->text() + text);
    };

    void DefaultView(QLabel* label) const noexcept {
        label->setText("");
    }

    void upadteViewModel(QLabel* label, const QString equation, const double x, QCheckBox* x_mode) {
        model.SetEquation(equation.toStdString());
        if (x_mode->isChecked()) {
            model.EnableX();
            model.UpdateModel(x);
        } else if (equation.contains('x')) {
            QMessageBox::critical(x_mode, "Error", "INVALID INPUT!<NOT CHECKED X>");
            return;
        } else {
            model.UpdateModel();
        }
        if (!model.GetStatus()) {
            QMessageBox::critical(x_mode, "Error", "INVALID INPUT!<BAD EQUATION>");
            return;
        }
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(10) << model.GetResult();
        std::string _tmp = oss.str();
        if (_tmp.front() == '-') {
            _tmp.front() = '~';
        }
        label->setText(QString::fromStdString(_tmp));
    };

    void updateGraph(QCustomPlot* graphic, QLabel* label, const double x_max, const double x_min, const double y_max, const double y_min) {
        graphic->clearPlottables();
        if (label->text().length() == 0 || (x_max == 0 && x_min == 0
                                                       && y_min == 0 && y_max == 0)) {
            QMessageBox::critical(label, "Error", "INVALID INPUT!<GRAPH>");
        } else {
            model.EnableX();
            step = 0.01;
            xBegin = x_min;
            xEnd = x_max + step;

            graphic->xAxis->setRange(xBegin,xEnd);
            graphic->yAxis->setRange(y_min, y_max);

            for (X = xBegin; X < xEnd; X += step) {
                if (fabs(X) < 1e-7) {
                    X = 0.0;
                }
                model.SetStatus(true);
                model.SetEquation(label->text().toStdString());
                model.UpdateModel(X);
                if (model.GetStatus()) {
                    x.push_back(X);
                    y.push_back(model.GetResult());
                }
            }

            graphic->addGraph();
            graphic->graph(0)->addData(x,y);
            graphic->replot();
            x.clear();
            y.clear();
        }
    };

private:
    CalcModel model;
    QVector<double> x, y;
    double xBegin, xEnd, step, X;
};


}

#endif  // CALC_CONTROLLER_H
