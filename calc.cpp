#include "calc.h"
#include "./ui_calc.h"
#include <cmath>

int numPlaces(int num) {
    int places = 0;
    do {
        num /= 10;
        places++;
    }   while (num > 10);
    return places;
}

calc::calc(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::calc)
{
    runningTotal = 0;
    inputBuffer  = 0;
    nextIsDec    = false;
    std::vector<double> prevInputsBuffer;
    prevInputsBuffer.reserve(2);
    std::map<char, std::vector<int>> operationIndicies;
    ui->setupUi(this);
}

int calc::appendInputBuff(int num) {
    static int decOps = 1;
    double decBuffer = 0.0;


    if (

    // This should only be a case when using an operator or clearing input
    if (inputBuffer == 0 && decOps > 1) {
        nextIsDec = false;
        decOps = 1;
    }


    if (nextIsDec) {
        decBuffer = num;
        decBuffer /= pow(10, decOps);
        inputBuffer += decBuffer;
        decOps++;
    }
    else {
        inputBuffer *= 10;
        inputBuffer += num;
    }

    ui->lcdNumber->display(inputBuffer);
    return inputBuffer;
}

int calc::appendOperator(char op) {
    static int index = 0;
    operationIndicies[op].push_back(index);
    index++;

    inputBuffer = 0.0;
    ui->lcdNumber->display(inputBuffer);
    return index;
}

calc::~calc()
{
    delete ui;
}

void calc::on_oneButton_clicked()
{
    calc::appendInputBuff(1);
}


void calc::on_twobutton_clicked()
{
    calc::appendInputBuff(2);
}


void calc::on_threeButton_clicked()
{
    calc::appendInputBuff(3);
}


void calc::on_fourButton_clicked()
{
    calc::appendInputBuff(4);
}


void calc::on_fiveButton_clicked()
{
    calc::appendInputBuff(5);
}


void calc::on_sixButton_clicked()
{
    calc::appendInputBuff(6);
}


void calc::on_sevenButton_clicked()
{
    calc::appendInputBuff(7);
}


void calc::on_eightButton_clicked()
{
    calc::appendInputBuff(8);
}


void calc::on_nineButton_clicked()
{
    calc::appendInputBuff(9);
}


void calc::on_zeroButton_clicked()
{
    calc::appendInputBuff(0);
}


void calc::on_decButton_clicked()
{
    nextIsDec = true;
}


void calc::on_eqButton_clicked()
{

}


void calc::on_plusButton_clicked()
{
    calc::appendOperator('+');
}


void calc::on_minusButton_clicked()
{
    calc::appendOperator('-');
}


void calc::on_multButton_clicked()
{
    calc::appendOperator('*');
}


void calc::on_divButton_clicked()
{
    calc::appendOperator('/');
}


void calc::on_lcdNumber_overflow()
{
    ui->lcdNumber->setDigitCount(ui->lcdNumber->digitCount() + 1);
}


void calc::on_actionClear_triggered()
{
    inputBuffer = 0.0;
    nextIsDec = false;
    ui->lcdNumber->display(inputBuffer);
}

