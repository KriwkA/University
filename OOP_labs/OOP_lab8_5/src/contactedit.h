#ifndef CONTACTEDIT_H
#define CONTACTEDIT_H
#include <QString>
#include <QWidget>
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>

class ContactEdit : public QDialog
{
    Q_OBJECT
public:
    ContactEdit(const QString& _name, const QString& phone, const int& _row, QWidget *parent = 0);
    QString getName() const;
    QString getPhone() const;
    inline int getRow() const;
    ~ContactEdit();
private:
    int row_;
    QLineEdit* name_;
    QLineEdit* phone_;
    QPushButton* ok_;
    QPushButton* cancle_;
private slots:
    void addTextChanged();
    void ok();
signals:
    void okClicked();
};

#endif // CONTACTEDIT_H

