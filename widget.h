#ifndef WIDGET_H
#define WIDGET_H
#pragma execution_character_set("utf-8")


#include <QWidget>
class QPushButton;
class QLineEdit;
class QLabel;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();


private:
    Ui::Widget *ui;
    QString expression; //输入的表达式
    QString expression_dec; //输入表达式的10进制
    QString last; //中间计算结果
    QString result; //最终计算结果
    QString mode; //计算器模式（普通模式或程序员模式）

    QLineEdit *ledt;
    QLineEdit *lexp;
    QPushButton *hex;
    QPushButton *dec;
    QPushButton *bin;
    QLineEdit *lhex;
    QLineEdit *ldec;
    QLineEdit *lbin;
    QPushButton *maxcd;
    QPushButton *squ;
    QPushButton *cube;
    QPushButton *sin;
    QPushButton *cos;
    QPushButton *tan;
    QPushButton *mincm;
    QPushButton *sqr;
    QPushButton *tenx;
    QPushButton *log;
    QPushButton *ln;
    QPushButton *mod;
    QPushButton *pi;
    QPushButton *rec;
    QPushButton *ce;
    QPushButton *cle;
    QPushButton *back;
    QPushButton *div;
    QPushButton *btn_a;
    QPushButton *btn_b;
    QPushButton *btn_7;
    QPushButton *btn_8;
    QPushButton *btn_9;
    QPushButton *mul;
    QPushButton *btn_c;
    QPushButton *btn_d;
    QPushButton *btn_4;
    QPushButton *btn_5;
    QPushButton *btn_6;
    QPushButton *sub;
    QPushButton *btn_e;
    QPushButton *btn_f;
    QPushButton *btn_1;
    QPushButton *btn_2;
    QPushButton *btn_3;
    QPushButton *add;
    QPushButton *leftbr;
    QPushButton *rightbr;
    QPushButton *mark;//正负号按钮
    QPushButton *btn_0;
    QPushButton *point;
    QPushButton *equal;

    void change_mode(QString to_mode); //改变计算器模式
    void input(QString ch);
    void operate(QString ch); //操作
    void func(QString ch); //函数
    void update();
    int get_base(QString mode);
    QString convert(QString from, QString to, QString num);

private slots:
    void ce_clicked();
    void cle_clicked();
    void back_clicked();
    void equal_clicked();

    void mark_clicked();//正负号槽
    void leftbr_clicked();
    void rightbr_clicked();
};

#endif // WIDGET_H
