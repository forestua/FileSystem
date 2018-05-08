#include "file.h"

File::File(QString name, QString ext, unsigned int indexCluster)
{
    this->name = name;
    this->extension = ext;
    this->lastAccessDate = QDate::currentDate();
    this->lastAccessTime = QTime::currentTime();
    this->indexCluster = indexCluster;
    this->size = 0;
}

File::File(char* byteArray)
{
    //this->name = new QString();
}

const char* File::GetFormattedBytes(QString val, const unsigned int size)
{
    if (val.length() > size){
        return val.toStdString().substr(0, size).c_str();
    }
    else{
        return val.toStdString().substr(0, val.length()).c_str();
    }
}

std::string File::GetByteArray()
{
    ss << name.toStdString().c_str();
    //ss << GetFormattedBytes(name, 4);
    ss << extension.toStdString().c_str();
    ss << indexCluster;
    ss << size;

    return ss.str();
}

/*std::ifstream& File::operator >>(std::ifstream& is)
{
    is >> name;
    is >> extension;
    is >> lastAccessDate;
    is >> lastAccessTime;
    is >> attr;
    is >> indexCluster;
    is >> size;
}*/
