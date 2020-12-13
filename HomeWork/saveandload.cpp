#include "saveandload.h"

SaveAndLoad::SaveAndLoad()
{

}

void SaveAndLoad::Remove()
{
    QFile("SaveData.txt").remove();
}

void SaveAndLoad::Save(QString item )
{
    QFile outputStream("SaveData.txt");

    if(outputStream.open(QIODevice::Append))
    {
        QTextStream stream( &outputStream );
        stream << item <<"\n";
    }

    outputStream.close();
}

void SaveAndLoad::Load()
{

}
