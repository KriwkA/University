#include "workerdialog.h"
#include "ui_workerdialog.h"

WorkerDialog::WorkerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WorkerDialog)
{
    ui->setupUi(this);

    ui->name->clear();
    ui->sername->clear();
    ui->fathername->clear();
    ui->factoryId->clear();
    ui->id->clear();
    ui->payment->clear();
    ui->profession->clear();

    ui->payment->setValidator(new QRegExpValidator(QRegExp("^([1-9][0-9]*|0)(\\.)[0-9]*|0"),this));
    prevId = -1;
    QObject::connect(ui->cancle, SIGNAL(clicked(bool)),
                     this, SLOT(close()));
    QObject::connect(ui->ok, SIGNAL(clicked(bool)),
                     this, SLOT(ok()));
    QObject::connect(ui->name, SIGNAL(textChanged(QString)),
                     this, SLOT(argChanged()));
    QObject::connect(ui->sername, SIGNAL(textChanged(QString)),
                     this, SLOT(argChanged()));
    QObject::connect(ui->fathername, SIGNAL(textChanged(QString)),
                     this, SLOT(argChanged()));
    QObject::connect(ui->id, SIGNAL(textChanged(QString)),
                     this, SLOT(argChanged()));
    QObject::connect(ui->birthday, SIGNAL(textChanged(QString)),
                     this, SLOT(argChanged()));
    QObject::connect(ui->profession, SIGNAL(textChanged(QString)),
                     this, SLOT(argChanged()));
    QObject::connect(ui->factoryId, SIGNAL(textChanged(QString)),
                     this, SLOT(argChanged()));
    QObject::connect(ui->sectorId, SIGNAL(textChanged(QString)),
                     this, SLOT(argChanged()));
    QObject::connect(ui->payment, SIGNAL(textChanged(QString)),
                     this, SLOT(argChanged()));
    QObject::connect(ui->male, SIGNAL(clicked(bool)),
                     this, SLOT(argChanged()));
    QObject::connect(ui->female, SIGNAL(clicked(bool)),
                     this, SLOT(argChanged()));
    QObject::connect(ui->rang, SIGNAL(valueChanged(int)),
                     this, SLOT(argChanged()));
    QObject::connect(ui->experience, SIGNAL(valueChanged(int)),
                     this, SLOT(argChanged()));
}

WorkerDialog::WorkerDialog(const worker::Worker& account, QWidget* parent)
    : WorkerDialog(parent)
{
    prevId = account.id;
    ui->ok->setText("Ok");
    ui->name->setText(QString(account.fio.name));
    ui->sername->setText(QString(account.fio.sername));
    ui->fathername->setText(QString(account.fio.fathername));
    ui->profession->setText(QString(account.profession));
    ui->birthday->setText(QString(dateToString(account.birthday).c_str()));
    ui->id->setText(tr("%1").arg(account.id));
    ui->experience->setValue(account.experience);
    ui->factoryId->setText(tr("%1").arg(account.factory));
    ui->sectorId->setText(tr("%1").arg(account.sector));
    if(account.gender == worker::MALE)
    {
        ui->male->setChecked(true);
        ui->female->setChecked(false);
    }
    else
    {
        ui->male->setChecked(false);
        ui->female->setChecked(true);
    }
    ui->payment->setText(tr("%1").arg(account.payment, 0 , 'f', 2));
    ui->rang->setValue(account.rang);
    ui->ok->setEnabled(false);
}

WorkerDialog::~WorkerDialog()
{
    delete ui;
}

void WorkerDialog::argChanged()
{
    if(ui->name->text().isEmpty() ||
       ui->sername->text().isEmpty() ||
       ui->fathername->text().isEmpty() ||
       ui->id->text().isEmpty() ||
       ui->factoryId->text().isEmpty() ||
       ui->payment->text().isEmpty() ||
       ui->profession->text().isEmpty() ||
       (ui->birthday->text().length() != 10))
    {
        ui->ok->setEnabled(false);
    }
    else
    {
        ui->ok->setEnabled(true);
    }
}

void WorkerDialog::ok()
{
    ui->ok->setEnabled(false);
    worker::Worker newWorker;
    memset(newWorker.fio.name, 0, sizeof(newWorker.fio.name));
    memset(newWorker.fio.sername, 0, sizeof(newWorker.fio.sername));
    memset(newWorker.fio.fathername, 0, sizeof(newWorker.fio.name));
    memset(newWorker.profession, 0, sizeof(newWorker.profession));
    std::string buffer;

    buffer = ui->name->text().toStdString();
    for(int i = 0; i < ui->name->text().length(); ++i)
        newWorker.fio.name[i] = buffer[i];

    buffer = ui->sername->text().toStdString();
    for(int i = 0; i < ui->sername->text().length(); ++i)
        newWorker.fio.sername[i] = buffer[i];

    buffer = ui->fathername->text().toStdString();
    for(int i = 0; i < ui->fathername->text().length(); ++i)
        newWorker.fio.fathername[i] = buffer[i];

    buffer = ui->profession->text().toStdString();
    for(int i = 0; i < ui->profession->text().length(); ++i)
        newWorker.profession[i] = buffer[i];

    newWorker.birthday.day = QString(ui->birthday->text().toStdString().substr(0,2).c_str()).toInt();
    newWorker.birthday.month = QString(ui->birthday->text().toStdString().substr(3,2).c_str()).toInt();
    newWorker.birthday.year = QString(ui->birthday->text().toStdString().substr(6,4).c_str()).toInt();
    newWorker.experience = ui->experience->value();
    newWorker.rang = ui->rang->value();
    newWorker.factory = ui->factoryId->text().toInt();
    newWorker.sector = ui->sectorId->text().toInt();
    newWorker.gender = ui->male->isChecked() ? worker::MALE : worker::FEMALE;
    newWorker.id = ui->id->text().toInt();
    newWorker.payment = ui->payment->text().toDouble();
    emit okClicked(newWorker, prevId);
}
