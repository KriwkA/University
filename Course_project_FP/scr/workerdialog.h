#ifndef WORKERDIALOG_H
#define WORKERDIALOG_H

#include "Worker.h"
#include <QDialog>

namespace Ui {
class WorkerDialog;
}

class WorkerDialog : public QDialog
{
    Q_OBJECT

public:
    WorkerDialog(QWidget *parent = 0);
    WorkerDialog(const worker::Worker& account, QWidget* parent = 0);
    ~WorkerDialog();
private slots:
    void argChanged();
    void ok();
signals:
    void okClicked(worker::Worker, int);
private:
    int prevId;
    Ui::WorkerDialog *ui;
};

#endif // WORKERDIALOG_H
