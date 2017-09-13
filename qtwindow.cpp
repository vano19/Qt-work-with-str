#include "qtwindow.h"

QTWindow::QTWindow(QWidget *parent=0): QDialog(parent)
{
    lbl= new QLabel("&Enter");
    line= new QLineEdit;
    lbl->setBuddy(line);

    cb1= new QCheckBox("&Toupper");
    cb2 = new QCheckBox("&Inventer");

    ok = new QPushButton("&Ok");
    ok->setDefault(true);
    ok->setEnabled(false);
    close = new QPushButton("&Close");

    QHBoxLayout *loyout = new QHBoxLayout;
    loyout->addWidget(lbl);
    loyout->addWidget(line);

    QVBoxLayout *Vloy = new QVBoxLayout;
    Vloy->addLayout(loyout);
    Vloy->addWidget(cb1);
    Vloy->addWidget(cb2);

    QVBoxLayout *loyt = new QVBoxLayout;
    loyt->addWidget(ok);
    loyt->addWidget(close);

    QHBoxLayout* alllout = new QHBoxLayout;
    alllout->addLayout(Vloy);
    alllout->addLayout(loyt);

    connect(line,SIGNAL(textChanged(QString)),this,SLOT(TextChange(QString)));
    connect(close,SIGNAL(clicked()),this,SLOT(close()));
    connect(ok,SIGNAL(clicked()),this,SLOT(OkCkiced()));


    setLayout(alllout);
    setWindowTitle("Demo");


}

void QTWindow::TextChange(QString str)
{
    ok->setEnabled(!str.isEmpty());
}

void QTWindow::OkCkiced()
{
    if(cb1->isChecked() && cb2->isChecked())
        emit all(line->text());
    else{
    if(!cb1->isChecked() && !cb2->isChecked())
        emit simple(line->text());
    else if(cb1->isChecked())
        emit toUper(line->text());

    else if(cb2->isChecked())
        emit Inverse(line->text());
    }
}



