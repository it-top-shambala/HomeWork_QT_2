#ifndef PERSON_H
#define PERSON_H

#include <QString>
#include <QDate>

class Person
{
public:
    QString surname;
    QString name;
    QString middleName;
    QString sex;
    QDate birthDay;
    QString maritalStatus;
    QString others;

    Person();
    Person(QString surname, QString name,QString middleName, QString sex, QDate birthDay, QString maritalStatus, QString others);
};

#endif // PERSON_H
