#ifndef QTWINDOW_H
#define QTWINDOW_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>
#include <QMessageBox>


class QTWindow:public QDialog
{
    Q_OBJECT
public:
    QTWindow(QWidget *perent);
private:
    QLabel *lbl;
    QLineEdit *line;
    QCheckBox *cb1;
    QCheckBox *cb2;
    QPushButton *ok;
    QPushButton *close;
private slots:
    void OkCkiced();
    void TextChange(QString str);
signals:
    void Inverse(QString str);
    void simple(QString str);
    void toUper(QString str);
    void all(QString str);

};

class str:public QObject
{
    Q_OBJECT

public slots:
    void Simple(QString str)
    {
        QMessageBox mes;
        mes.setText(str);
        mes.exec();
    }
    void Inversia(QString str)
    {
            QString result;
            for(int i =str.size(), j=0 ;i>=0;i--,j++)
                result[j]=str[i];

            QMessageBox mes;
            mes.setText(result);
            mes.exec();
    }
    void touper(QString str)
    {   str =str.toUpper();
        QMessageBox mes;
        mes.setText(str);
        mes.exec();
    }
    void ALL(QString str)
    {
        QString result;
        for(int i =str.size(), j=0 ;i>=0;i--,j++)
            result[j]=str[i];
        result = result.toUpper();
        QMessageBox mes;
        mes.setText(result);
        mes.exec();
    }
};



#endif // QTWINDOW_H
