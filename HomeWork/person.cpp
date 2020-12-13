#include "person.h"

Person::Person()
{

}

Person::Person(QString name, QString sex, QDate birthDay)
{
    this->name = name;
    this->sex = sex;
    this->birthDay = birthDay;
}
//-------------------------------------
void Person::SetName(QString name)
{
    this->name = name;
}

QString Person::GetName()
{
    return name;
}
//-------------------------------------

void Person::SetSex(QString sex)
{
    this->sex = sex;
}

QString Person::GetSex()
{
    return sex;
}
//-------------------------------------

void Person::SetBirthDay(QDate birthDay)
{
    this->birthDay = birthDay;
}

QDate Person::GetBirthDay()
{
    return birthDay;
}
//-------------------------------------
