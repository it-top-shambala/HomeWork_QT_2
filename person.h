#ifndef PERSON_H
#define PERSON_H
#include <QString>
#include <QDate>

class Person
{
private:
   QString name;
   QString sex;
   QDate date;

public:
    Person();
    Person(QString name, QString sex, QDate date);

void SetName(QString name);
QString GetName();

void SetSex(QString sex);
QString GetSex();

void SetDate(QDate date);
QDate GetDate();



};

#endif // PERSON_H
