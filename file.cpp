#include "file.h"
#include <sstream>

File::File(QString name, QString ext, unsigned int indexCluster)
{
    this->name = name;
    this->extension = ext;
    this->lastAccessDate = QDate::currentDate();
    this->lastAccessTime = QTime::currentTime();
    this->indexCluster = indexCluster;
    this->size = 10*1024;
}

File::File(char* byteArray)
{
    //this->name = new QString();
}

char* File::GetFormattedBytes(QString val, const unsigned int size)
{
    char out[4] = {0};
    if (val.length() > size){
        val.toStdString().copy(out, size, 0);
    }
    else{
        val.toStdString().copy(out, val.length());
    }
    return out;
}

char* File::GetByteArray()
{
    std::stringstream ss;
    //ss << name.toStdString().c_str();
    ss << GetFormattedBytes(name, 4);
    ss << extension.toStdString().c_str();
    ss << indexCluster;
    ss << size;

    return (char*)ss.str().c_str();
}

std::ifstream& File::operator >>(std::ifstream& is)
{
    is >> name;
    is >> extension;
    is >> lastAccessDate;
    is >> lastAccessTime;
    is >> attr;
    is >> indexCluster;
    is >> size;
}

