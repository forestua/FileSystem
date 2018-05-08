#include "filesystem.h"
#include <math.h>
#include <fstream>
#include <array>

const char* DATA_FILE = "d:\\data.fs";
const int SIZE = 200;

FileSystem::FileSystem()
{
    index = 0;

    Format();
    InitFs();
    NewFile("/", "");
    NewFile("111", "txt");
    NewFile("222", "fff");
    NewFile("3333", "data");

    SaveFs();

    //LoadFs();
}

void FileSystem::Format()
{
    for (unsigned int i = 0; i < VOLUME_SIZE_IN_CLUSTERS; i++)
    {
        fileTable[i] = 0;
    }
    fileArray.clear();
    index = 0;

    for (int i = 0; i < VOLUME_SIZE_IN_CLUSTERS; i++)
    {
        dataTable[i] = new Cluster();
    }

    InitFs();
}

void FileSystem::NewFile(QString name, QString ext)
{
    File* newFile = new File(name, ext, GetNextFreeIndex());
    fileArray.push_back(newFile);

    //select by file size
    //int cluster_count = (int) ceil(newFile->GetSize() / CLUSTER_SIZE) + 1;
    /*for (int i=0; i<cluster_count; i++)
    {
        fileTable[index] = ++index;
    }*/

    /*Cluster* cluster = getFreeCluster();
    if(cluster)
    {

    }*/

    //fileTable[index] = 0xFFFF;
}

void FileSystem::CopyFile(File* oldFile, QString newName, QString newExt)
{
    File* newFile = new File(newName, newExt, index);
    fileArray.push_back(newFile);

    int cluster_count = (int) ceil(oldFile->GetSize() / CLUSTER_SIZE) + 1;
    for (int i=0; i<cluster_count; i++)
    {
        int nextIndex = GetNextFreeIndex();
        fileTable[index] = nextIndex;
        index = nextIndex;
    }
    fileTable[index] = 0xFFFF;
}

void FileSystem::RemoveFile(File* file)
{
    int fileIndex = file->indexCluster;
    int nextIndex = fileIndex;
    while (fileTable[fileIndex] != 0xFFFF);
    {
        nextIndex = fileTable[fileIndex];
        fileTable[fileIndex] = 0x0;
        fileIndex = nextIndex;
    }
    fileTable[nextIndex] = 0x0;

    fileArray.erase(std::remove(fileArray.begin(), fileArray.end(), file), fileArray.end());
}

void FileSystem::MoveFile(QString newName)
{
    // TODO
}

std::vector<QString> FileSystem::GetFiles()
{
    std::vector<QString> resVector;
    std::vector<File*>::iterator it;
    for(it = fileArray.begin(); it != fileArray.end(); it++)
    {
        resVector.push_back((*it)->name + "." + (*it)->extension);
    }
    return resVector;
}

int FileSystem::GetNextFreeIndex()
{
    // TODO - check size.
    for (int i = 0; i < VOLUME_SIZE_IN_CLUSTERS; i++)
    {
        if (!fileTable[i])
        {
            //fileTable[index] = i;
            fileTable[i] = 0xFFFF;
            return i;
        }
    }
    return NULL;
}

void FileSystem::LoadFs()
{
    std::ifstream inFile(DATA_FILE, std::ifstream::binary);

    int countFiles;
    inFile >> countFiles;

//    infile.seekg (0,infile.end);
//    long size = infile.tellg();
//    char* buffer = new char[size];
//    inFile.seekg (0);

    for (int i = 0; i < VOLUME_SIZE_IN_CLUSTERS; i++)
    {
        inFile >> fileTable[i];
    }

    File* f;
    char buffer[32];
    for (int i = 0; i < countFiles; i++)
    {
        //inFile >> f;
        //fileArray.push_back(f);

        //inFile.read(buffer, 32);
        //fileArray.push_back(new File(buffer));
    }

    inFile.close();
}

void FileSystem::InitFs()
{
    std::ofstream outfile(DATA_FILE, std::ofstream::binary);

    long size=1024*1024; // 1MB
    char* buffer = new char[size];

    for (int i = 0; i < SIZE; i++)
    {
        outfile.write(buffer,size);
    }

    delete[] buffer;
    outfile.close();
}

void FileSystem::SaveFs()
{
    std::ofstream outFile(DATA_FILE, std::ofstream::binary);
    outFile << fileArray.size();

    // file table section
    char* t_str = new char;
    for(int i = 0; i < VOLUME_SIZE_IN_CLUSTERS; i++)
    {
        itoa(fileTable[i], t_str, 10);
        outFile.write(t_str, sizeof(int));
    }
    // file array section
    std::vector<File*>::iterator it;
    for(it = fileArray.begin(); it != fileArray.end(); it++)
    {
        std::string data = (*it)->GetByteArray();
        outFile.write(data.c_str(), 32);
    }

    // data storage section
    for(int i = 0;  i < VOLUME_SIZE_IN_CLUSTERS; i++)
    //for(int i = 0;  i < 1024; i++)
    {
        outFile.write(dataTable[i]->data, CLUSTER_SIZE);
    }
    outFile.close();
}

void FileSystem::NewFolder(QString name)
{
    File* newFolder = new File(name, "", GetNextFreeIndex());
    newFolder->attr = '1';
    fileArray.push_back(newFolder);
}

/*void FileSystem::loadFolder(File *file)
{

}*/

/*Cluster* FileSystem::getFreeCluster()
{
    for(int i = 0; i < VOLUME_SIZE_IN_CLUSTERS; i++)
    {
        if(!dataTable[i]->isBusy)
        {
            return dataTable[i];
        }
    }
    return NULL;
}*/

void FileSystem::editFile(File *f)
{

}

void FileSystem::editFolder(File *f)
{

}
