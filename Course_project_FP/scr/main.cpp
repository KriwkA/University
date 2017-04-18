/* Севастопольский Государственный Университет
 * Кафедра информационных систем
 * Программа WorkersTable
 * СГУ 2015.13
 * Разработал
 * ст. гр. ИС22-22-о
 * Серегин Александр Владимирович
 * 2015г.
 * Вариант задания №13 Утверждено 08.08.2015
 * Среда разработки QtCreator
 * Дата последней коррекции 20.10.2015
 * Версия 1.0
*/
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Workers Table");
    w.show();

    return a.exec();
}
