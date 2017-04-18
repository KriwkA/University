#include "mainwindow.h"
#include "contactedit.h"

#include <QDebug>
#include <QString>
#include <QList>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSlider>
#include <QLineEdit>
#include <QSpacerItem>
#include <QHeaderView>
#include <QLabel>
#include <QLineEdit>

MyWindow::MyWindow(QWidget *parent)
    : QDialog(parent)
{
    contacts_ = 0;
    editWidget_ = nullptr;

    this->setMinimumHeight(350);
    this->setMinimumWidth(500);

    QLabel* header = new QLabel("Contact / phone");

    contact_ = new QLineEdit;
    contact_->setMaximumWidth(150);
    phone_ = new QLineEdit;
    phone_->setMaximumWidth(150);
    phone_->setInputMask("+0-000-000-00-00");
    add_ = new QPushButton("&Добавить");
    add_->setEnabled(false);
    edit_ = new QPushButton("Изменить");
    edit_->setEnabled(false);
    exit_ = new QPushButton("&Выход");
    del_ = new QPushButton("Удалить");
    del_->setEnabled(false);

    //QLabel* lbl = new QLabel(tr("%1").arg(phone_->text().length()));

    mainTable_ = new QTableWidget(contacts_,2);
    mainTable_->horizontalHeader()->setStretchLastSection(true);
    mainTable_->setHorizontalHeaderItem(0,new QTableWidgetItem("Контакт"));
    mainTable_->setHorizontalHeaderItem(1,new QTableWidgetItem("Телефон"));
    mainTable_->setSortingEnabled(true);
    mainTable_->setSelectionBehavior(QAbstractItemView::SelectRows);
    QVBoxLayout* leftLay = new QVBoxLayout;
    leftLay->addWidget(header);
    leftLay->addWidget(contact_);
    leftLay->addWidget(phone_);
    leftLay->addWidget(add_);
    leftLay->addWidget(edit_);
    leftLay->addWidget(del_);
    leftLay->addStretch();
    //leftLay->addWidget(lbl);
    leftLay->addWidget(exit_);

    QHBoxLayout* mainLay = new QHBoxLayout;
    mainLay->addLayout(leftLay);
    mainLay->addWidget(mainTable_);

    QObject::connect(exit_,SIGNAL(clicked()),this,SLOT(close()));
    QObject::connect(add_, SIGNAL(clicked()),this,SLOT(addContact()));
    QObject::connect(del_,SIGNAL(clicked(bool)),this,SLOT(deleteContact()));
    QObject::connect(contact_,SIGNAL(textChanged(QString)),this, SLOT(addTextChanged()));
    QObject::connect(phone_,SIGNAL(textChanged(QString)),this, SLOT(addTextChanged()));
    QObject::connect(mainTable_,SIGNAL(itemSelectionChanged()),this, SLOT(selectedContact()));
    QObject::connect(edit_,SIGNAL(clicked(bool)),this, SLOT(editBegin()));
    this->setLayout(mainLay);
}

void MyWindow::addTextChanged()
{
    if(contact_->text().length() && (phone_->text().length() == 16))
        add_->setEnabled(true);
    else
        add_->setEnabled(false);
}

void MyWindow::addContact()
{
    QTableWidgetItem* contact = new QTableWidgetItem(contact_->text());
    QTableWidgetItem* phone = new QTableWidgetItem(phone_->text());
    contact->setFlags(contact->flags() ^ Qt::ItemIsEditable);
    phone->setFlags(phone->flags() ^ Qt::ItemIsEditable);

    mainTable_->setRowCount(contacts_ + 1);
    mainTable_->setSortingEnabled(false);
    mainTable_->setItem(contacts_,0,contact);
    mainTable_->setItem(contacts_,1,phone);
    mainTable_->setSortingEnabled(true);
    contact_->clear();
    phone_->clear();
    contacts_++;
}

void MyWindow::editBegin()
{
    this->setEnabled(false);
    mainTable_->setSortingEnabled(false);

    int row = mainTable_->currentRow();
    editWidget_ = new ContactEdit(mainTable_->item(row,0)->text(),
                                  mainTable_->item(row,1)->text(), row);
    QObject::connect(editWidget_,SIGNAL(rejected()), this, SLOT(editEnd()));
    QObject::connect(editWidget_,SIGNAL(okClicked()), this, SLOT(changeContact()));
    editWidget_ -> show();
    editWidget_ -> exec();
}

void MyWindow::changeContact()
{
    QTableWidgetItem* contact = new QTableWidgetItem(editWidget_->getName());
    QTableWidgetItem* phone = new QTableWidgetItem(editWidget_->getPhone());
    contact->setFlags(contact->flags() ^ Qt::ItemIsEditable);
    phone->setFlags(phone->flags() ^ Qt::ItemIsEditable);

    int row = mainTable_->currentRow();

    mainTable_->setItem(row, 0, contact);
    mainTable_->setItem(row, 1, phone);
    editWidget_ ->close();
}

void MyWindow::editEnd()
{
    mainTable_->setSortingEnabled(true);
    delete editWidget_;
    this->setEnabled(true);
}

MyWindow::~MyWindow()
{
    delete mainTable_;
    delete contact_;
    delete phone_;
    delete exit_;
    delete add_;
    delete edit_;
    delete editWidget_;
    delete del_;
}

void MyWindow::selectedContact()
{
    if(!mainTable_ ->selectedItems().count())
    {
        edit_->setEnabled(false);
        del_->setEnabled(false);
        return;
    }
    del_->setEnabled(true);
    if (mainTable_->selectedItems().count() < 3)
        edit_->setEnabled(true);
    else
        edit_->setEnabled(false);
}

void MyWindow::deleteContact()
{
    while(mainTable_->selectedRanges().count())
    {
        mainTable_->removeRow(mainTable_->selectedRanges().at(0).bottomRow());
        contacts_--;
    }
    del_->setEnabled(false);
    edit_->setEnabled(false);
}
