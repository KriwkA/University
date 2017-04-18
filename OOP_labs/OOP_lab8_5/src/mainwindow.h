#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QWidget>
#include <QTableWidget>
#include <QLineEdit>
#include <QPushButton>

#include "contactedit.h"

class MyWindow : public QDialog
{
    Q_OBJECT

public:
    MyWindow(QWidget *parent = 0);
    ~MyWindow();
private:
    QTableWidget* mainTable_;
    QLineEdit* contact_;
    QLineEdit* phone_;
    QPushButton* exit_;
    QPushButton* add_;
    QPushButton* edit_;
    QPushButton* del_;
    ContactEdit* editWidget_;
    quint64 contacts_;
private slots:
    void addTextChanged();
    void addContact();
    void editBegin();
    void editEnd();
    void changeContact();
    void selectedContact();
    void deleteContact();
};

#endif // MAINWINDOW_H
