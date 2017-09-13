#include "qtwindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    QSpinBox *spin = new QSpinBox;
//    QSlider *slider = new QSlider(Qt::Horizontal);
//    QHBoxLayout *lay = new QHBoxLayout;
//    QWidget *window = new QWidget;

//    spin->setMaximum(100);
//    slider->setMaximum(100);

//    lay->addWidget(spin);
//    lay->addWidget(slider)

//    window->setLayout(lay);
//    window->show();

//    QObject::connect(spin,SIGNAL(valueChanged(int)),slider,SLOT(setValue(int)));
//    QObject::connect(slider,SIGNAL(valueChanged(int)),spin,SLOT(setValue(int)));

    QTWindow *main = new QTWindow(0);
    main->show();

    str *n = new str;

    QObject::connect(main,SIGNAL(simple(QString)),n,SLOT(Simple(QString)));
    QObject::connect(main,SIGNAL(Inverse(QString)),n,SLOT(Inversia(QString)));
    QObject::connect(main,SIGNAL(toUper(QString)),n,SLOT(touper(QString)));
    QObject::connect(main,SIGNAL(all(QString)),n,SLOT(ALL(QString)));

    return a.exec();
}
