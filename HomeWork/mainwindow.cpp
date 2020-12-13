#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//добавить
void MainWindow::on_Button_add_clicked()
{
    ui->listWidget->addItem(GetItems());
    ClearFields();
}

//удаляем
void MainWindow::on_Button_delet_clicked()
{
    QListWidgetItem *Item = ui->listWidget->currentItem();
    delete Item;
}

//изменить
void MainWindow::on_Button_change_clicked()
{
     ui->listWidget->currentItem()->setText(GetItems());
     ClearFields();
}

//сохранение в файл
void MainWindow::on_pushButton_3_clicked()
{
    SaveAndLoad save;

    save.Remove();
    for (int i = 0; i < ui->listWidget->count(); i++ )
    {
        save.Save(ui->listWidget->item(i)->text());
    }
}

//загрузка из файла
void MainWindow::on_pushButton_2_clicked()
{

}


//------------------ вспомогательные методы -----------------------//

QString MainWindow::GetItems()//получить данные из полей
{
    QString temp = ui->lineEdit_name->text() + " | " +
                   ui->dateEdit->date().toString(Qt::SystemLocaleShortDate) + " | " +
                   ui->comboBox_sex->currentText();
    return temp;
}

void MainWindow::ClearFields()//очистить все поля
{
    ui->lineEdit_name->clear();
    ui->dateEdit->setDate(QDate(1900,1,1));
    ui->comboBox_sex->setCurrentIndex(-1);
}

//-----------------------------------------------------------------//



