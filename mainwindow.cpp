#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QListWidget>

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

void MainWindow::on_button_Clear_clicked()
{
    ui->input_Name->clear();
    ui->comboBox_Sex->setCurrentIndex(-1);
    ui->date_BirthDay->setDate(QDate(1900, 1, 1));

    ui->statusbar->showMessage("Очищено!");
}

void MainWindow::on_button_Save_clicked()
{
    auto name = ui->input_Name->text();
    auto sex = ui->comboBox_Sex->currentText();
    QDate birthDay = ui->date_BirthDay->date();

    Person person(name, sex, birthDay);

    listPerson.append(person);

    ui->input_Name->clear();

    ui->statusbar->showMessage("Данные успешно сохранены");
}

void MainWindow::on_button_ShowAllPersons_clicked()
{
    QString temp = "";
    foreach (auto person, listPerson)
    {
        temp += person.GetName() + "\n" + person.GetSex() + "\n" + person.GetBirthDay().toString(Qt::SystemLocaleShortDate) + "\n";
    }

    ui->label_AllPersons->setText(temp);
}
void MainWindow::on_Add_clicked()
{
    QString temp = "";
    foreach (auto person, listPerson)
    {
        temp += person.GetName() + "\n";
    }

    ui->listWidget->addItem(temp);
    ui->input_Name->clear();
    ui->comboBox_Sex->clear();
    ui->date_BirthDay->clear();
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->input_Name->setText(ui->listWidget->currentItem()->text());
    auto name = ui->input_Name->text();
    auto sex = ui->comboBox_Sex->currentText();
    QDate birthDay = ui->date_BirthDay->date();

    //Person person(name, sex, birthDay);

    //listPerson.append(person);

    ui->statusbar->showMessage("Данные успешно сохранены");
}

void MainWindow::on_AddItem_clicked()
{
    QString temp = "";
    foreach (auto person, listPerson)
    {
        temp += person.GetName() + "\n";
    }

    ui->listWidget->addItem(temp);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->label_AllPersons->clear();
    ui->listWidget->currentItem()->text().clear();
}
