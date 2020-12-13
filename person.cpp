#include "person.h"

Person::Person()
{

}

Person::Person(QString name, QString sex, QDate date)
{

    this->name=name;
    this->sex=sex;
    this->date=date;
}

void Person::SetName(QString name)
{
    this->name=name;
}
QString Person::GetName()
{
    return name;
}

void Person::SetSex(QString sex)
{
    this->sex=sex;
}
QString Person::GetSex()
{
    return sex;
}

void Person::SetDate(QDate date)
{
    this->date=date;
}
QDate Person::GetDate()
{
    return date;
}
