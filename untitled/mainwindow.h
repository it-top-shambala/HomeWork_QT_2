#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include "person.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QVector<Person> listPerson;

private slots:
    void on_push_Save_clicked();

    void on_push_Download_clicked();

    void on_push_Add_clicked();

    void on_push_Delete_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
