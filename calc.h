#ifndef CALC_H
#define CALC_H

#include <QMainWindow>
#include <vector>
#include <map>

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

    void on_oneButton_clicked();

    void on_twobutton_clicked();

    void on_threeButton_clicked();

    void on_fourButton_clicked();

    void on_fiveButton_clicked();

    void on_sixButton_clicked();

    void on_sevenButton_clicked();

    void on_eightButton_clicked();

    void on_nineButton_clicked();

    void on_zeroButton_clicked();

    void on_decButton_clicked();

    void on_eqButton_clicked();

    void on_plusButton_clicked();

    void on_minusButton_clicked();

    void on_multButton_clicked();

    void on_divButton_clicked();

    void on_lcdNumber_overflow();

    void on_actionClear_triggered();

private:
    double  runningTotal;
    double  inputBuffer;
    bool    nextIsDec;
    std::vector<double> prevInputsBuffer;
    std::map<char, std::vector<int>> operationIndicies;
    Ui::calc *ui;
    int appendInputBuff(int num);
    int appendOperator(char op);
};
#endif // CALC_H
