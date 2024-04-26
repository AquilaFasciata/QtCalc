#include "calc.h"
#include "./ui_calc.h"

calc::calc(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::calc)
{
    ui->setupUi(this);
}

calc::~calc()
{
    delete ui;
}


void calc::on_box2_valueChanged(double arg1)
{
    double first = ui->box1->value();
    double second = ui->box2->value();
    double result = first + second;
    QString resultString = QString::number(result);
    ui->output->setText(resultString);
}

void calc::on_box1_valueChanged(double arg1)
{
    double first = ui->box1->value();
    double second = ui->box2->value();
    double result = first + second;
    QString resultString = QString::number(result);
    ui->output->setText(resultString);
}
