#include "person.h"

Person::Person() {}

Person::Person(QString surname, QString name, QString middleName, QString sex, QDate birthDay, QString maritalStatus, QString others)
{
    this->surname = surname;
    this->name = name;
    this->middleName = middleName;
    this->sex = sex;
    this->birthDay = birthDay;
    this->maritalStatus = maritalStatus;
    this->others = others;
}
