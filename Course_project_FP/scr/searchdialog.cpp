#include "searchdialog.h"
#include "ui_searchdialog.h"

SearchDialog::SearchDialog(const worker::WorkersData* data, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchDialog)
{
    ui->setupUi(this);
    data_ = data;
    QObject::connect(ui->id, SIGNAL(textChanged(QString)),
                     this, SLOT(argChanged()));
    QObject::connect(ui->search, SIGNAL(clicked(bool)),
                     this, SLOT(search()));
    QObject::connect(ui->cancle, SIGNAL(clicked(bool)),
                     this, SLOT(close()));
}

SearchDialog::~SearchDialog()
{
    delete ui;
}

void SearchDialog::search()
{
    int searchID = ui->id->text().toInt();
    emit searchClicked(worker::search(*data_, searchID));
}

void SearchDialog::argChanged()
{
    if(ui->id->text().length())
        ui->search->setEnabled(true);
    else
        ui->search->setEnabled(false);
}
