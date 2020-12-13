#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QListWidgetItem>

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


void MainWindow::on_Button_Press_clicked()
{
auto name = ui->lineEdit_Name->text();
auto sex = ui->comboBox_Sex->currentText();
QDate date = ui->dateEdit_Date->date();

Person person(name, sex, date);
listPerson.append(person);
    ui->statusbar->showMessage("Данные успешно сохранены!");


}

void MainWindow::on_Button_Clear_clicked()
{
ui->lineEdit_Name->clear();
ui->comboBox_Sex->setCurrentIndex(-1);
ui->dateEdit_Date->setDate(QDate(1900,1,1));
    ui->statusbar->showMessage("Очищено!");
}

void MainWindow::on_Button_Show_clicked()
{
    ui->listWidget->clear();
    QString name = "";
    QString sex = "";
    QString date = "";



    foreach (auto person , listPerson) {
        name = person.GetName();
        sex = person.GetSex();
        date = person.GetDate().toString(Qt::SystemLocaleShortDate);

        QListWidgetItem *item = new QListWidgetItem (name + " " + sex + " " + date);
       ui->listWidget->addItem(item);
    }


}

void MainWindow::on_listWidget_itemSelectionChanged()
{
    ui->statusbar->showMessage(ui->listWidget->currentItem()->text());
    int index = ui->listWidget->currentRow();
    Person pers;
    pers = listPerson[index];
    ui->lineEdit_Name->setText(pers.GetName());
   if(pers.GetSex()=="Мужской"){
       ui->comboBox_Sex->setCurrentIndex(0);
   } else {
   ui->comboBox_Sex->setCurrentIndex(1);
   }

    ui->dateEdit_Date->setDate(pers.GetDate());

}

void MainWindow::on_Button_Correct_clicked()
{

    auto name = ui->lineEdit_Name->text();
    auto sex = ui->comboBox_Sex->currentText();
    QDate date = ui->dateEdit_Date->date();
    int index = ui->listWidget->currentRow();

listPerson[index].SetName(name);
listPerson[index].SetSex(sex);
listPerson[index].SetDate(date);
}

void MainWindow::on_Button_Delete_clicked()
{
        int index = ui->listWidget->currentRow();
        listPerson.erase(listPerson.begin() + index);
}
