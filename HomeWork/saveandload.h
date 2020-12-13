#ifndef SAVEANDLOAD_H
#define SAVEANDLOAD_H

#include <fstream>
#include <QTextStream>
#include <QFile>

class SaveAndLoad
{
public:
    SaveAndLoad();
    void Save(QString item);
    void Load();
    void Remove();
};

#endif // SAVEANDLOAD_H
