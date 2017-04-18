#include "mainwindow.h"
#include "workerdialog.h"
#include <QMessageBox>
#include <QApplication>
#include <QMenuBar>
#include <QFileDialog>
#include <QList>
#include <QQueue>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{    
    this->resize(1280, 720);
    mainMenu = new QMenu(QString("&Menu"), this);
    QList < QAction* > menuList;
    open = new QAction(QString("Open"), this);
    save = new QAction(QString("Save"),this);
    saveFactoryesTable = new QAction(QString("Save factoryes table .txt"),this);
    exit = new QAction(QString("Exit"),this);
    menuList.append(open);
    menuList.append(save);
    menuList.append(saveFactoryesTable);
    menuList.append(exit);
    mainMenu->addActions(menuList);
    menuBar()->addMenu(mainMenu);

    QHBoxLayout* topLay = new QHBoxLayout(this);
    workersView = new QRadioButton("Workers", this);
    workersView->setChecked(true);
    factoryesView = new QRadioButton("Factoryes", this);
    topLay->addWidget(workersView);
    topLay->addWidget(factoryesView);
    topLay->addStretch();

    QVBoxLayout* leftLay = new QVBoxLayout(this);
    add = new QPushButton("&Add", this);
    edit = new QPushButton("&Edit", this);
    search = new QPushButton("Search", this);
    del = new QPushButton("Delete", this);
    edit->setEnabled(false);
    del->setEnabled(false);
    leftLay->addWidget(add);
    leftLay->addWidget(edit);
    leftLay->addWidget(search);
    leftLay->addWidget(del);
    leftLay->addStretch();

    QHBoxLayout* botLay = new QHBoxLayout(this);
    workersTable = new QTableWidget(0, 12, this);
    workersTable->horizontalHeader()->setStretchLastSection(true);
    workersTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    QStringList workersTableHeader;
    workersTableHeader << "Id" << "Name" << "Sername"<<
                          "Fathername" << "Birthday" <<
                          "Gender" << "Profession" <<
                          "Experience" << "Rang" <<
                          "Factory" << "Sector" << "Payment";
    workersTable->setHorizontalHeaderLabels(workersTableHeader);

    factoryesTable = new QTableWidget(0, 7, this);
    factoryesTable->horizontalHeader()->setStretchLastSection(true);
    factoryesTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    QStringList factoryesTableHeader;
    factoryesTableHeader << "ID" << "Male" << "Female" << "All" << "Male(%)" << "Female(%)" << "All(%)";
    factoryesTable->setHorizontalHeaderLabels(factoryesTableHeader);

    botLay->addLayout(leftLay);
    botLay->addWidget(workersTable);
    botLay->addWidget(factoryesTable);
    factoryesTable->setVisible(false);

    QVBoxLayout* mainLay = new QVBoxLayout(this);
    mainLay->addLayout(topLay);
    mainLay->addLayout(botLay);

    centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLay);

    this->setCentralWidget(centralWidget);

    //Data init
    data::initialize(workers);
    sortDirection = 0;

    QObject::connect(exit, SIGNAL(triggered(bool)),
                     this, SLOT(close()));
    QObject::connect(workersView,SIGNAL(clicked(bool)),
                     this, SLOT(tableChanged()));
    QObject::connect(factoryesView,SIGNAL(clicked(bool)),
                     this, SLOT(tableChanged()));
    QObject::connect(add, SIGNAL(clicked(bool)),
                     this, SLOT(addClicked()));
    QObject::connect(edit, SIGNAL(clicked(bool)),
                     this, SLOT(editClicked()));
    QObject::connect(del, SIGNAL(clicked(bool)),
                     this, SLOT(removeSelectedWorkers()));
    QObject::connect(save, SIGNAL(triggered(bool)),
                     this, SLOT(saveClicked()));
    QObject::connect(open, SIGNAL(triggered(bool)),
                     this, SLOT(openClicked()));
    QObject::connect(workersTable->horizontalHeader(),SIGNAL(sectionClicked(int)),
                     this, SLOT(setWorkersTableSortPriority(int)));
    QObject::connect(factoryesTable->horizontalHeader(),SIGNAL(sectionClicked(int)),
                     this, SLOT(setFactoryesTableSortPriority(int)));
    QObject::connect(workersTable, SIGNAL(itemSelectionChanged()),
                     this, SLOT(itemSelectionChanged()));
    QObject::connect(search, SIGNAL(clicked(bool)),
                     this, SLOT(searchClicked()));
    QObject::connect(saveFactoryesTable, SIGNAL(triggered(bool)),
                     this, SLOT(saveFTableClicked()));
}

MainWindow::~MainWindow()
{
    delete mainMenu;
    delete exit;
    delete save;
    delete saveFactoryesTable;
    delete workersTable;
    delete factoryesTable;
    delete workersView;
    delete factoryesView;
    delete add;
    delete edit;
    delete del;
    data::clearData(workers);
}

void MainWindow::keyPressEvent(QKeyEvent* event)
{
    switch(event->key())
    {
    case Qt::Key_Delete:
    {
        if(del->isEnabled())
            this->removeSelectedWorkers();
    } break;

    case Qt::Key_F:
    {
        if (QApplication::keyboardModifiers() && Qt::ControlModifier)
            this->searchClicked();
    } break;

    case Qt::Key_S:
    {
        if (QApplication::keyboardModifiers() && Qt::ControlModifier)
            this->saveClicked();
    } break;

    }
}

void MainWindow::tableChanged()
{
    if(workersView->isChecked())
    {
        workersTable->setVisible(true);
        add->setVisible(true);
        edit->setVisible(true);
        del->setVisible(true);
        search->setVisible(true);
        factoryesTable->setVisible(false);
    }
    else
    {
        workersTable->setVisible(false);
        workersTable->clearSelection();
        add->setVisible(false);
        search->setVisible(false);
        edit->setVisible(false);
        del->setVisible(false);
        factoryesTable->setVisible(true);
    }
}

void MainWindow::addClicked()
{
    WorkerDialog* addDialog = new WorkerDialog(this);
    this->setEnabled(false);
    addDialog->setEnabled(true);
    QObject::connect(addDialog,SIGNAL(okClicked(worker::Worker, int)),
                     this, SLOT(addWorker(worker::Worker, int)));
    QObject::connect(addDialog, SIGNAL(rejected()),
                     this, SLOT(enableTrue()));
    addDialog->show();
    addDialog->exec();
}

void MainWindow::editClicked()
{
    this->setEnabled(false);
    int workerPos = this->workersTable->selectedRanges().at(0).bottomRow();
    WorkerDialog* editDialog = new WorkerDialog(workers.workersData.workers[workerPos], this);
    editDialog->setEnabled(true);
    QObject::connect(editDialog, SIGNAL(okClicked(worker::Worker, int)),
                     this, SLOT(changeSelectedWorker(worker::Worker, int)));
    QObject::connect(editDialog, SIGNAL(okClicked(worker::Worker, int)),
                     editDialog, SLOT(close()));
    QObject::connect(editDialog, SIGNAL(rejected()),
                     this, SLOT(enableTrue()));
    editDialog->show();
    editDialog->exec();
}

void MainWindow::addWorker(const worker::Worker& newWorker, int)
{
    if (worker::search(workers.workersData, newWorker.id) == -1)
    {
        data::addWorker(workers, newWorker);
        printWorkersTable();
        printFactoryesTable();
    }
    else
    {
        QMessageBox* result = new QMessageBox(this);
        result->setWindowTitle("Adding error");
        result->setText("This ID are reserved");
        result->show();
        result->exec();
    }
}

void MainWindow::changeSelectedWorker(const worker::Worker& newWorker, int prevId)
{
    if(worker::search(workers.workersData, newWorker.id) == -1 || prevId == newWorker.id)
    {
        data::delWorker(workers, this->workersTable->selectedRanges().at(0).bottomRow());
        data::addWorker(workers, newWorker);
        printWorkersTable();
        printFactoryesTable();
    }
    else
    {
        QMessageBox* result = new QMessageBox(this);
        result->setWindowTitle("Change error");
        result->setText("This ID are reserved");
        result->show();
        result->exec();
    }
}

void MainWindow::printWorkersTable()
{
    int rowCount = workers.workersData.size;
    workersTable->setRowCount(rowCount);
    worker::Worker nextWorker;
    QTableWidgetItem temp[12];
    for(int i = 0; i < 12; ++i)
        temp[i].setFlags(temp[i].flags() ^ Qt::ItemIsEditable);
    for(int i = 0; i < rowCount; ++i)
    {
        nextWorker = workers.workersData.workers[i];
        temp[0].setText(tr("%1").arg(nextWorker.id));
        temp[1].setText(QString(nextWorker.fio.name));
        temp[2].setText(QString(nextWorker.fio.sername));
        temp[3].setText(QString(nextWorker.fio.fathername));
        temp[4].setText(QString(dateToString(nextWorker.birthday).c_str()));
        temp[5].setText(QString(((nextWorker.gender == worker::MALE) ? ("Male") : ("Female"))));
        temp[6].setText(QString(nextWorker.profession));
        temp[7].setText(tr("%1").arg(nextWorker.experience));
        temp[8].setText(tr("%1").arg(nextWorker.rang));
        temp[9].setText(tr("%1").arg(nextWorker.factory));
        temp[10].setText(tr("%1").arg(nextWorker.sector));
        temp[11].setText(tr("%1").arg(nextWorker.payment, 0, 'f', 2));
        for(int j = 0; j < 12; ++j)
            workersTable->setItem(i, j, new QTableWidgetItem(temp[j]));
    }
}

void MainWindow::printTreeTable(factory::FNode* root, int& pos)
{
    if(root == nullptr)
        return;
    printTreeTable(root->left, pos);

    QTableWidgetItem temp[7];
    for(int i = 0; i < 7; ++i)
        temp[i].setFlags(temp[i].flags() ^ Qt::ItemIsEditable);
    temp[0].setText(tr("%1").arg(root->key->number));
    temp[1].setText(tr("%1").arg(root->key->count.male));
    temp[2].setText(tr("%1").arg(root->key->count.female));
    temp[3].setText(tr("%1").arg(root->key->count.all));
    temp[4].setText(tr("%1").arg(root->key->persentCount.male));
    temp[5].setText(tr("%1").arg(root->key->persentCount.female));
    temp[6].setText(tr("%1").arg(root->key->persentCount.all));
    for(int i = 0; i < 7; ++i)
        factoryesTable->setItem(pos, i, new QTableWidgetItem(temp[i]));
    pos++;
    printTreeTable(root->right, pos);
}

void MainWindow::printFactoryesTable()
{
    this->factoryesTable->setRowCount(workers.factoryesData.size);
    int pos = 0;
    if(workers.factoryesData.size)
        this->printTreeTable(workers.factoryesData.root, pos);
}

void MainWindow::removeSelectedWorkers()
{
    auto selectedWorkers = this->workersTable->selectedRanges();
    for(int i = selectedWorkers.size() - 1; i > -1; --i)
    {
        for(int j = selectedWorkers.at(i).bottomRow(); j >= selectedWorkers.at(i).topRow(); --j)
            data::delWorker(workers, j);
    }
    printWorkersTable();
    printFactoryesTable();
}

void MainWindow::saveClicked()
{
    if (workers.all == 0)
    {
        QMessageBox* result = new QMessageBox(this);
        result->setWindowTitle("Save error");
        result->setText("Data is empty");
        result->show();
        result->exec();
        return;
    }
    this->setEnabled(false);
    QString path = QFileDialog::getSaveFileName(this,QString("Select path"),
                        QDir::homePath(), QString("Data file (*.dat)"));
    this->setEnabled(true);
    if(!path.length())
        return;
    data::saveBinDataFile(workers, path.toStdString());
}

void MainWindow::saveFTableClicked()
{
    if (workers.all == 0)
    {
        QMessageBox* result = new QMessageBox(this);
        result->setWindowTitle("Save error");
        result->setText("Data is empty");
        result->show();
        result->exec();
        return;
    }
    this->setEnabled(false);
    QString path = QFileDialog::getSaveFileName(this,QString("Select path"),
                        QDir::homePath(), QString("Text file (*.txt)"));
    this->setEnabled(true);
    if(!path.length())
        return;
    data::printFactoryTableTextFile(workers, path.toStdString());
}

void MainWindow::openClicked()
{
    QString path = QFileDialog::getOpenFileName(0, QString("Select path"),
                        QDir::homePath(), QString("Data files (*.dat);;All files(*.*)"));
    if(!path.length())
        return;
    data::clearData(workers);
    data::initialize(workers);
    data::loadBinDataFile(workers, path.toStdString());
    this->printFactoryesTable();
    this->printWorkersTable();
}

void MainWindow::setFactoryesTableSortPriority(int priority)
{
    factory::SortPriority prevPriority = workers.factoryesData.sortPriority;
    switch(priority)
    {
    case 0: workers.factoryesData.sortPriority = factory::NUMBER; break;
    case 1: workers.factoryesData.sortPriority = factory::MALE; break;
    case 2: workers.factoryesData.sortPriority = factory::FEMALE; break;
    case 3: workers.factoryesData.sortPriority = factory::ALL; break;
    case 4: workers.factoryesData.sortPriority = factory::P_MALE; break;
    case 5: workers.factoryesData.sortPriority = factory::P_FEMALE; break;
    case 6: workers.factoryesData.sortPriority = factory::P_ALL; break;
    }
    if(workers.factoryesData.sortPriority != prevPriority || sortDirection == 1)
    {
        sortDirection = 0;
        factory::sort(workers.factoryesData, 0);
    }
    else
    {
        sortDirection = 1;
        factory::sort(workers.factoryesData, 1);
    }
    this->printFactoryesTable();
}

void MainWindow::setWorkersTableSortPriority(int priority)
{
    worker::SortPriority prevPriority = workers.workersData.sortPriority;
    switch(priority)
    {
    case 0: workers.workersData.sortPriority = worker::ID; break;
    case 1: workers.workersData.sortPriority = worker::NAME; break;
    case 2: workers.workersData.sortPriority = worker::SERNAME; break;
    case 3: workers.workersData.sortPriority = worker::FATHERNAME; break;
    case 4: workers.workersData.sortPriority = worker::BIRTHDAY; break;
    case 5: workers.workersData.sortPriority = worker::GENDER; break;
    case 6: workers.workersData.sortPriority = worker::PROFFESSION; break;
    case 7: workers.workersData.sortPriority = worker::EXPERIENCE; break;
    case 8: workers.workersData.sortPriority = worker::RANG; break;
    case 9: workers.workersData.sortPriority = worker::FACTORY; break;
    case 10: workers.workersData.sortPriority = worker::SECTOR; break;
    case 11: workers.workersData.sortPriority = worker::PAYMENT; break;
    }

    if(workers.workersData.sortPriority != prevPriority || sortDirection == 1)
    {
        sortDirection = 0;
        worker::sort(workers.workersData);
    }
    else
    {
        sortDirection = 1;
        worker::sort(workers.workersData, 1);
    }
    this->printWorkersTable();
}

void MainWindow::itemSelectionChanged()
{
    int selectedItems = workersTable->selectedItems().count();
    if(!selectedItems)
    {
        del->setEnabled(false);
        edit->setEnabled(false);
        return;
    }
    del->setEnabled(true);
    if(selectedItems > 15)
        edit->setEnabled(false);
    else
        edit->setEnabled(true);
}

void MainWindow::enableTrue()
{
    this->setEnabled(true);
}

void MainWindow::searchClicked()
{
    this->setEnabled(false);
    searchDialog = new SearchDialog(&workers.workersData, this);
    QObject::connect(searchDialog, SIGNAL(rejected()),
                     this, SLOT(enableTrue()));
    QObject::connect(searchDialog, SIGNAL(searchClicked(int)),
                     this, SLOT(showSearchResult(int)));
    QObject::connect(searchDialog, SIGNAL(searchClicked(int)),
                     searchDialog, SLOT(close()));
    searchDialog->show();
    searchDialog->exec();
}

void MainWindow::showSearchResult(int pos)
{
    searchDialog->close();
    delete searchDialog;
    if (pos == -1)
    {
        QMessageBox* result = new QMessageBox(this);
        result->setWindowTitle("Search result");
        result->setText("Null result");
        result->show();
        result->exec();
        this->setEnabled(true);
        return;
    }
    this->workersTable->clearSelection();
    this->workersTable->selectRow(pos);
    this->editClicked();
}
