#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <file.h>
#include <vector>
#include <array>

const unsigned int VOLUME_SIZE_IN_CLUSTERS = 64 * 1024;
const unsigned int SECTOR_SIZE = 512;
const unsigned int CLUSTER_SIZE = 8 * SECTOR_SIZE;

struct Cluster
{
    char data[CLUSTER_SIZE];
};

class FileSystem
{
public:
    FileSystem();
    void Format();

public:
    void NewFile(QString name, QString ext);
    void CopyFile(File* oldFile, QString newName, QString newExt);
    void RemoveFile(File* file);
    void MoveFile(QString newName);
    void NewFolder(QString name);
    void loadFolder();
    void editFile(File* f);
    void editFolder(File* f);
    //
    //Cluster* getFreeCluster();

    std::vector<QString> GetFiles();

private:
    int GetNextFreeIndex();
    void InitFs();
    void LoadFs();
    void SaveFs();

public:

    int fileTable[VOLUME_SIZE_IN_CLUSTERS]; //2 bytes each
    // TODO - must be VOLUME_SIZE_IN_CLUSTERS!
    std::array<Cluster*, VOLUME_SIZE_IN_CLUSTERS> dataTable; // 8*512 bytes each

    std::vector<File*> fileArray;
    int index;
};

#endif // FILESYSTEM_H
