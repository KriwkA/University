#ifndef SEARCHDIALOG_H
#define SEARCHDIALOG_H

#include <QDialog>
#include "WorkersData.h"

namespace Ui {
class SearchDialog;
}

class SearchDialog : public QDialog
{
    Q_OBJECT
public:
    SearchDialog(const worker::WorkersData* data, QWidget *parent = 0);
    ~SearchDialog();
private slots:
    void search();
    void argChanged();
signals:
    void searchClicked(int);
private:
    const worker::WorkersData* data_;
    Ui::SearchDialog *ui;
};

#endif // SEARCHDIALOG_H
