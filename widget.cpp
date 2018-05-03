#pragma
#include "widget.h"
#include "ui_widget.h"
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QString>
#include <ecalc.h>
#define PI "3.141592653589793"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    expression = ""; // 输入表达式初始为空
    expression_dec = ""; // 十进制的表达式，用于计算
    last = ""; // 上次计算结果，本程序仅用做判断是否计算结束
    result = ""; // 计算结果
    mode = "normal"; // 初始化计算器模式为普通模式

    setWindowTitle(tr("计算器"));
    lexp=new QLineEdit(""); //表达式显示框
    lexp->setFont(QFont("Timers" , 12 ,  QFont::Bold));
    lexp->setReadOnly(1);
    lexp->setAlignment(Qt::AlignRight); //靠右对齐
    ledt=new QLineEdit("0"); //计算结果输出框
    ledt->setFont(QFont("Timers" , 28 ,  QFont::Bold));
    ledt->setReadOnly(1);
    ledt->setAlignment(Qt::AlignRight);
    hex=new QPushButton(tr("HEX")); //16进制按钮
    dec=new QPushButton(tr("DEC ")); //10进制按钮
    bin=new QPushButton(tr("BIN")); //2进制按钮
    lhex=new QLineEdit("0");
    lhex->setReadOnly(1);
    ldec=new QLineEdit("0");
    ldec->setReadOnly(1);
    lbin=new QLineEdit("0");
    lbin->setReadOnly(1);
//创建所需的按钮
    maxcd=new QPushButton(tr("最大公约数"));
    squ=new QPushButton(tr("X²"));
    cube=new QPushButton(tr("^"));
    sin=new QPushButton(tr("sin"));
    cos=new QPushButton(tr("cos"));
    tan=new QPushButton(tr("tan"));
    mincm=new QPushButton(tr("最小公倍数"));
    sqr=new QPushButton(tr("√"));
    tenx=new QPushButton(tr("10^"));
    log=new QPushButton(tr("lg"));
    ln=new QPushButton(tr("ln"));
    mod=new QPushButton(tr("Mod"));
    pi=new QPushButton(tr("π"));
    rec=new QPushButton(tr("1/x"));
    ce=new QPushButton(tr("CE"));
    cle=new QPushButton(tr("C"));
    back=new QPushButton(tr("←"));
    div=new QPushButton(tr("÷"));
    btn_a=new QPushButton(tr("A"));
    btn_b=new QPushButton(tr("B"));
    btn_7=new QPushButton(tr("7"));
    btn_8=new QPushButton(tr("8"));
    btn_9=new QPushButton(tr("9"));
    mul=new QPushButton(tr("×"));
    btn_c=new QPushButton(tr("C"));
    btn_d=new QPushButton(tr("D"));
    btn_4=new QPushButton(tr("4"));
    btn_5=new QPushButton(tr("5"));
    btn_6=new QPushButton(tr("6"));
    sub=new QPushButton(tr("-"));
    btn_e=new QPushButton(tr("E"));
    btn_f=new QPushButton(tr("F"));
    btn_1=new QPushButton(tr("1"));
    btn_2=new QPushButton(tr("2"));
    btn_3=new QPushButton(tr("3"));
    add=new QPushButton(tr("+"));
    leftbr=new QPushButton(tr("("));
    rightbr=new QPushButton(tr(")"));
    mark=new QPushButton(tr("±"));
    btn_0=new QPushButton(tr("0"));
    point=new QPushButton(tr("."));
    equal=new QPushButton(tr("="));
    //水平布局
    QHBoxLayout *Hl00=new QHBoxLayout;
    QHBoxLayout *Hl0=new QHBoxLayout;
    QHBoxLayout *Hl1=new QHBoxLayout;
    QHBoxLayout *Hl2=new QHBoxLayout;
    QHBoxLayout *Hl3=new QHBoxLayout;
    QHBoxLayout *Hl4=new QHBoxLayout;
    QHBoxLayout *Hl5=new QHBoxLayout;
    QHBoxLayout *Hl6=new QHBoxLayout;
    QHBoxLayout *Hl7=new QHBoxLayout;
    QHBoxLayout *Hl8=new QHBoxLayout;
    QHBoxLayout *Hl9=new QHBoxLayout;
    QHBoxLayout *Hl10=new QHBoxLayout;
    Hl00->addWidget(lexp);
    Hl0->addWidget(ledt);
    Hl1->addWidget(hex);
    Hl1->addWidget(lhex);
    Hl2->addWidget(dec);
    Hl2->addWidget(ldec);
    Hl3->addWidget(bin);
    Hl3->addWidget(lbin);
    Hl4->addWidget(maxcd);
    Hl4->addWidget(squ);
    Hl4->addWidget(cube);
    Hl4->addWidget(sin);
    Hl4->addWidget(cos);
    Hl4->addWidget(tan);
    Hl5->addWidget(mincm);
    Hl5->addWidget(sqr);
    Hl5->addWidget(tenx);
    Hl5->addWidget(log);
    Hl5->addWidget(ln);
    Hl5->addWidget(mod);
    Hl6->addWidget(pi);
    Hl6->addWidget(rec);
    Hl6->addWidget(ce);
    Hl6->addWidget(cle);
    Hl6->addWidget(back);
    Hl6->addWidget(div);
    Hl7->addWidget(btn_a);
    Hl7->addWidget(btn_b);
    Hl7->addWidget(btn_7);
    Hl7->addWidget(btn_8);
    Hl7->addWidget(btn_9);
    Hl7->addWidget(mul);
    Hl8->addWidget(btn_c);
    Hl8->addWidget(btn_d);
    Hl8->addWidget(btn_4);
    Hl8->addWidget(btn_5);
    Hl8->addWidget(btn_6);
    Hl8->addWidget(sub);
    Hl9->addWidget(btn_e);
    Hl9->addWidget(btn_f);
    Hl9->addWidget(btn_1);
    Hl9->addWidget(btn_2);
    Hl9->addWidget(btn_3);
    Hl9->addWidget(add);
    Hl10->addWidget(leftbr);
    Hl10->addWidget(rightbr);
    Hl10->addWidget(mark);
    Hl10->addWidget(btn_0);
    Hl10->addWidget(point);
    Hl10->addWidget(equal);
//垂直对齐
    QVBoxLayout *V1=new QVBoxLayout;
    V1->addLayout(Hl00);
    V1->addLayout(Hl0);
    V1->addLayout(Hl1);
    V1->addLayout(Hl2);
    V1->addLayout(Hl3);
    V1->addLayout(Hl4);
    V1->addLayout(Hl5);
    V1->addLayout(Hl6);
    V1->addLayout(Hl7);
    V1->addLayout(Hl8);
    V1->addLayout(Hl9);
    V1->addLayout(Hl10);

//建立信号与槽的连接
    connect(hex,&QPushButton::clicked,this,[=]{change_mode("hex");}); //点击转换进制按钮，改变计算器模式
    connect(dec,&QPushButton::clicked,this,[=]{change_mode("dec");});
    connect(bin,&QPushButton::clicked,this,[=]{change_mode("bin");});

    connect(btn_0,&QPushButton::clicked,this,[=]{input("0");});
    connect(btn_1,&QPushButton::clicked,this,[=]{input("1");});
    connect(btn_2,&QPushButton::clicked,this,[=]{input("2");});
    connect(btn_3,&QPushButton::clicked,this,[=]{input("3");});
    connect(btn_4,&QPushButton::clicked,this,[=]{input("4");});
    connect(btn_5,&QPushButton::clicked,this,[=]{input("5");});
    connect(btn_6,&QPushButton::clicked,this,[=]{input("6");});
    connect(btn_7,&QPushButton::clicked,this,[=]{input("7");});
    connect(btn_8,&QPushButton::clicked,this,[=]{input("8");});
    connect(btn_9,&QPushButton::clicked,this,[=]{input("9");});
    connect(btn_a,&QPushButton::clicked,this,[=]{input("a");});
    connect(btn_b,&QPushButton::clicked,this,[=]{input("b");});
    connect(btn_c,&QPushButton::clicked,this,[=]{input("c");});
    connect(btn_d,&QPushButton::clicked,this,[=]{input("d");});
    connect(btn_e,&QPushButton::clicked,this,[=]{input("e");});
    connect(btn_f,&QPushButton::clicked,this,[=]{input("f");});
    connect(point,&QPushButton::clicked,this,[=]{input(".");});
    connect(pi,&QPushButton::clicked,this,[=]{input(PI);});

    connect(div,&QPushButton::clicked,this,[=]{operate("/");});
    connect(mul,&QPushButton::clicked,this,[=]{operate("*");});
    connect(add,&QPushButton::clicked,this,[=]{operate("+");});
    connect(sub,&QPushButton::clicked,this,[=]{operate("-");});
    connect(maxcd,&QPushButton::clicked,this,[=]{operate("#");});
    connect(mincm,&QPushButton::clicked,this,[=]{operate("$");});
    connect(cube,&QPushButton::clicked,this,[=]{operate("^");});
    connect(mod,&QPushButton::clicked,this,[=]{operate("%");});
    connect(squ,&QPushButton::clicked,this,[=]{operate("^2");});

    connect(sin,&QPushButton::clicked,this,[=]{func("sin");});
    connect(cos,&QPushButton::clicked,this,[=]{func("cos");});
    connect(tan,&QPushButton::clicked,this,[=]{func("tan");});
    connect(tenx,&QPushButton::clicked,this,[=]{func("10^");});
    connect(sqr,&QPushButton::clicked,this,[=]{func("sqrt");});
    connect(log,&QPushButton::clicked,this,[=]{func("lg");});
    connect(ln,&QPushButton::clicked,this,[=]{func("ln");});
    connect(rec,&QPushButton::clicked,this,[=]{func("(1/");});

    connect(ce,SIGNAL(clicked()),this,SLOT(ce_clicked())); //取消输入的数字
    connect(cle,SIGNAL(clicked()),this,SLOT(cle_clicked())); //清除按钮
    connect(back,SIGNAL(clicked()),this,SLOT(back_clicked())); //取消输入数字的末位
    connect(equal,SIGNAL(clicked()),this,SLOT(equal_clicked()));
    connect(leftbr,SIGNAL(clicked()),this,SLOT(leftbr_clicked()));
    connect(rightbr,SIGNAL(clicked()),this,SLOT(rightbr_clicked()));
    connect(mark,SIGNAL(clicked()),this,SLOT(mark_clicked()));

    setLayout(V1);

    change_mode("normal");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::change_mode(QString to_mode)
{

    if (to_mode == mode) // 点两次切换开关，计算器回到普通模式
    {
        result = convert(mode, "normal", result);
        mode = "normal";
    } else {
        // 切换模式的时候清空不必要的数据
        expression = "";
        expression_dec = "";
        last = "";
        result = convert(mode, to_mode, result);
        mode = to_mode;
    }
    update();
    //若点击进制转换按钮，则该进制按钮字体变为蓝色，且该进制的输入框内字体变为蓝色。其他情况字体均为黑色
    hex->setStyleSheet(mode == "hex" ? "color: rgb(0,0,255)" : "color:black");
    lhex->setStyleSheet(mode == "hex" ? "color: rgb(0,0,255)" : "color:black");
    dec->setStyleSheet(mode == "dec" ? "color: rgb(0,0,255)" : "color:black");
    ldec->setStyleSheet(mode == "dec" ? "color: rgb(0,0,255)" : "color:black");
    bin->setStyleSheet(mode == "bin" ? "color: rgb(0,0,255)" : "color:black");
    lbin->setStyleSheet(mode == "bin" ? "color: rgb(0,0,255)" : "color:black");
    //设置按钮是否可点击
    btn_0->setEnabled(true);
    btn_1->setEnabled(true);
    btn_2->setEnabled(mode == "hex" || mode == "dec" || mode == "normal");
    btn_3->setEnabled(mode == "hex" || mode == "dec" || mode == "normal");
    btn_4->setEnabled(mode == "hex" || mode == "dec" || mode == "normal");
    btn_5->setEnabled(mode == "hex" || mode == "dec" || mode == "normal");
    btn_6->setEnabled(mode == "hex" || mode == "dec" || mode == "normal");
    btn_7->setEnabled(mode == "hex" || mode == "dec" || mode == "normal");
    btn_8->setEnabled(mode == "hex" || mode == "dec" || mode == "normal");
    btn_9->setEnabled(mode == "hex" || mode == "dec" || mode == "normal");
    btn_a->setEnabled(mode == "hex");
    btn_b->setEnabled(mode == "hex");
    btn_c->setEnabled(mode == "hex");
    btn_d->setEnabled(mode == "hex");
    btn_e->setEnabled(mode == "hex");
    btn_f->setEnabled(mode == "hex");
    point->setEnabled(mode == "normal"); //只有在普通模式小数点才可用，程序员模式小数点不可用
    pi->setEnabled(mode == "normal");
}

//根据用户点击的进制转换按钮切换更新计算器的模式
void Widget::update()
{

    if (result.length() == 0) {
        result = "0";
    }

    ledt->setText(result);
    lexp->setText(expression);

    //程序员模式
    if (mode != "normal") {
        lhex->setText(convert(mode, "hex", result));
        ldec->setText(convert(mode, "dec", result));
        lbin->setText(convert(mode, "bin", result));
    } else {
        //普通模式
        lhex->setText("不可用");
        ldec->setText("不可用");
        lbin->setText("不可用");
    }
}
//根据上次计算结果判断新一次输入所对应的操作
void Widget::input(QString ch) {
    if (last.length() > 0) {
        last = "";
        expression = "";
        expression_dec = "";
        result = ch;
    } else {
        if (result.length() > 0 && result != "0") {
            result += ch;
        } else {
            result = ch;
        }
    }

    update();
}

void Widget::operate(QString ch) {
    if (last.length() > 0) {
        expression = "";
        expression_dec = "";
        last = "";
    }

    if (expression.length() > 0 && result == "0") {
        result = "";
    }

    expression += result + ch;
    expression_dec += convert(mode, "normal", result) + ch;
    result = "";
    update();
}

void Widget::func(QString ch) {
    if (result.length() > 0) {
        if (last.length() > 1) {
            expression = "";
            expression_dec = "";
        }
        expression += ch + "(" + result + ")";
        expression_dec += ch + "(" + convert(mode, "normal", result) + ")";
        if (ch == "(1/") {
            expression += ")";
            expression_dec += ")";
        }
        result = "";
    }
    update();
}
//正负号点击信号
void Widget::mark_clicked()
{
    if (result.startsWith("-")) {
        result = result.right(result.length() - 1);
    } else if(result.length() > 0 && result != "0") {
        result = "-" + result;
    }
    update();
}

void Widget::ce_clicked()
{
    if (last.length() > 0) {
        cle_clicked(); // 上次有结果的话按ce清除所有
    } else {
        result = "";
        update();
    }
}

void Widget::cle_clicked()
{
    last = "";
    result = "";
    expression = "";
    expression_dec = "";
    update();
}

void Widget::back_clicked()
{
    result = result.left(result.length()-1);
    if (result == "-") {
        result = "";
    }

    update();
}

void Widget::equal_clicked()
{
    if (last.length() == 0) {
        if (result != "0") {
            expression += result;
            expression_dec += convert(mode, "normal", result);
        }
        result = convert("normal", mode, QString::number(ECalc::xcalc(expression_dec)));
        last = result;
    }
    update();
}

void Widget::leftbr_clicked()
{
    if (result == "0") {
        result = "";
    }

    expression += "(" + result;
    expression_dec += "(" + convert(mode, "normal", result);
    result = "";
    update();
}

void Widget::rightbr_clicked()
{
    expression += result + ")";
    expression_dec += convert(mode, "normal", result) + ")";
    result = "";
    update();
}

int Widget::get_base(QString m)
{
    if (m == "bin") {
        return 2;
    }

    if (m == "hex") {
        return 16;
    }

    return 10;
}
//进制转换
QString Widget::convert(QString from, QString to, QString num)
{
    if (from == to || num == "") {
        return num;
    }

    return QString::number(num.toInt(nullptr, get_base(from)), get_base(to));
}
