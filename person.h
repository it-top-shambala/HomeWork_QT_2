#ifndef PERSON_H
#define PERSON_H

#include <QString>
#include <QDate>

class Person
{
private:
    QString name;
    QString sex;
    QDate birthDay;

public:
    Person();
    Person(QString name, QString sex, QDate birthDay);

    void SetName(QString name);
    QString GetName();

    void SetSex(QString sex);
    QString GetSex();

    void SetBirthDay(QDate birthDay);
    QDate GetBirthDay();
};

#endif // PERSON_H
