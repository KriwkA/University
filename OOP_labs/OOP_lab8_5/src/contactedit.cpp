#include "contactedit.h"
#include <QVBoxLayout>
#include <QHBoxLayout>

ContactEdit::ContactEdit(const QString& _name, const QString& _phone, const int& _row, QWidget* parent)
    : QDialog(parent)
{
    row_ = _row;
    name_ = new QLineEdit(_name);
    phone_ = new QLineEdit(_phone);
    phone_->setInputMask("+0-000-000-00-00");

    ok_ = new QPushButton("Ок");
    ok_->setEnabled(false);
    cancle_ = new QPushButton("Отмена");

    QHBoxLayout* botLay = new QHBoxLayout;
    botLay->addWidget(ok_);
    botLay->addWidget(cancle_);
    QVBoxLayout* mainLay = new QVBoxLayout;
    mainLay->addWidget(name_);
    mainLay->addWidget(phone_);
    mainLay->addLayout(botLay);
    this->setLayout(mainLay);

    QObject::connect(ok_, SIGNAL(clicked(bool)), this, SLOT(ok()));
    QObject::connect(name_, SIGNAL(textChanged(QString)), this, SLOT(addTextChanged()));
    QObject::connect(phone_, SIGNAL(textChanged(QString)), this, SLOT(addTextChanged()));
    QObject::connect(cancle_, SIGNAL(clicked()), this, SLOT(close()));
}

QString ContactEdit::getName() const
{
    return name_->text();
}

QString ContactEdit::getPhone() const
{
    return phone_->text();
}

int ContactEdit::getRow() const
{
    return row_;
}

ContactEdit::~ContactEdit()
{
    delete name_;
    delete phone_;
    delete ok_;
    delete cancle_;
}

void ContactEdit::addTextChanged()
{
    if(name_->text().length() && phone_->text().length() == 16)
        ok_->setEnabled(true);
    else
        ok_->setEnabled(false);
}

void ContactEdit::ok()
{
    emit okClicked();
}
