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

