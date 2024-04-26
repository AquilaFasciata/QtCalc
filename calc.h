#ifndef CALC_H
#define CALC_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class calc;
}
QT_END_NAMESPACE

class calc : public QMainWindow
{
    Q_OBJECT

public:
    calc(QWidget *parent = nullptr);
    ~calc();

private slots:

    void on_box2_valueChanged(double arg1);

    void on_box1_valueChanged(double arg1);

private:
    Ui::calc *ui;
};
#endif // CALC_H
