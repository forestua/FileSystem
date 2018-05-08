#ifndef FILE_H
#define FILE_H

#include <QString>
#include <QDate>
#include <QTime>
#include <sstream>

class File
{
public:
    File(QString name, QString ext, unsigned int indexCluster);
    //1 option
    File(char* byteArray);
    //2 option
    std::ifstream& operator >>(std::ifstream& is);

    std::string GetByteArray();
    const char* GetFormattedBytes(QString val, const unsigned int size);
    unsigned int GetSize() { return size; }

public:
    QString name;
    QString extension;
    QDate lastAccessDate;
    QTime lastAccessTime;
    char attr;
    unsigned int indexCluster;
    unsigned int size;
private:
    std::ostringstream ss;
};

#endif // FILE_H
