#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Data.h"
#include "searchdialog.h"
#include <QMainWindow>
#include <QAction>
#include <QMenu>
#include <QTableWidget>
#include <QRadioButton>
#include <QPushButton>
#include <QLineEdit>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void keyPressEvent(QKeyEvent *);
private slots:
    void tableChanged();
    void addClicked();
    void editClicked();
    void addWorker(const worker::Worker&, int);
    void changeSelectedWorker(const worker::Worker&, int);
    void removeSelectedWorkers();
    void saveClicked();
    void saveFTableClicked();
    void openClicked();
    void setWorkersTableSortPriority(int);
    void setFactoryesTableSortPriority(int);
    void itemSelectionChanged();
    void enableTrue();
    void searchClicked();
    void showSearchResult(int);
private:

    void printWorkersTable();
    void printTreeTable(factory::FNode*, int&);
    void printFactoryesTable();

    //Data
    data::Data workers;
    int sortDirection;

    //menu bar
    QMenu* mainMenu;
    QAction* exit;
    QAction* open;
    QAction* save;
    QAction* saveFactoryesTable;

    QWidget* centralWidget;
    SearchDialog* searchDialog;

    //tables
    QTableWidget* workersTable;
    QTableWidget* factoryesTable;
    QRadioButton* workersView;
    QRadioButton* factoryesView;

    //edit buttons
    QPushButton* add;
    QPushButton* edit;
    QPushButton* search;
    QPushButton* del;
};

#endif // MAINWINDOW_H
