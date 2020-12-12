#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "person.h"
#include <QString>
#include <QTextStream>
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//сохранить информацию при заполнении полей
void MainWindow::on_push_Save_clicked()
{
    QString lineEdit_Surname=ui->lineEdit_Surname->text();
    QString lineEdit_Name=ui->lineEdit_Name->text();
    QString lineEdit_MiddleName=ui->lineEdit_MiddleName->text();
    QString sex;
    if (ui->radioButton_SexM->isChecked())
    {
        sex="M";
    } else if (ui->radioButton_SexW->isChecked())
    {
        sex="Ж";
    }
    QDate dateEdit_BirthDay = ui->dateEdit_BirthDay->date();
    QString lineEdit_MaritalStatus=ui->lineEdit_MaritalStatus->text();
    QString lineEdit_Others=ui->lineEdit_Others->text();
    Person person(lineEdit_Surname, lineEdit_Name, lineEdit_MiddleName, sex, dateEdit_BirthDay, lineEdit_MaritalStatus, lineEdit_Others);
    listPerson.append(person);
    //сохранение в файл
    QFile filePerson("Person.csv");
    //при сохранении в файл данные не перезаписываются
    if (filePerson.open(QIODevice::ReadWrite)) {
        QTextStream outFile(&filePerson);
        outFile << lineEdit_Surname + ";";
        outFile << lineEdit_Name + ";";
        outFile << lineEdit_MiddleName + ";";
        outFile << sex  + ";";
        outFile << dateEdit_BirthDay.toString() + ";";
        outFile << lineEdit_MaritalStatus + ";";
        outFile << lineEdit_Others << Qt::endl;
        ui->statusbar->showMessage("Данные успешно сохранены");;
    }
    else {
           ui->statusbar->showMessage("Ошибка сохранения");
    }
    filePerson.close();
    //добавление в listWidget_Person
    QString temp = "";
    foreach (auto person, listPerson)
    {
        temp += person.name + " " + person.sex + " " + person.birthDay.toString(Qt::SystemLocaleShortDate) + "\n";
    }
    //при сохранении в listWidget старые данные не удаляются если будет несколько раз нажата кнопка сохранить
    ui->listWidget_Person->clear();
    ui->listWidget_Person->addItem(temp);
}

void MainWindow::on_push_Download_clicked()
{
    //загрузить из файла
    QFile filePerson("Person.csv");
    if (!filePerson.open(QIODevice::ReadOnly)) {
        ui->statusbar->showMessage("Ошибка загзузки из файла");
    }
    QTextStream in(&filePerson);
    //не разобрался как сделать загрузку из файла

    filePerson.close();
}

void MainWindow::on_push_Add_clicked()
{
    ui->lineEdit_Surname->clear();
    ui->lineEdit_Name->clear();
    ui->lineEdit_MiddleName->clear();
    //не получается снять отметку с radiobutton при добавлении нового пользователя
    if (ui->radioButton_SexM->isChecked())
    {
        ui->radioButton_SexM->clearMask();
    } else if (ui->radioButton_SexW->isChecked())
    {
        ui->radioButton_SexW->clearMask();
    }
    ui->dateEdit_BirthDay->setDate(QDate(1900, 1, 1));
    ui->lineEdit_MaritalStatus->clear();
    ui->lineEdit_Others->clear();
    ui->statusbar->showMessage("Добавьте нового гражданина");
}

void MainWindow::on_push_Delete_clicked()
{
    listPerson.clear();
    ui->listWidget_Person->clear();
    ui->statusbar->showMessage("Данные очищены");
}
