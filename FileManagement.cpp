#include "FileManagement.h"

void FileManagement::loadFile(QString filename) {
    if (!QDir(".temp").exists()) {
        QDir().mkdir(".temp");
    }
    if (QFile(".temp/temp.gif").exists()) deleteFile();
    QFile::copy(filename, ".temp/temp.gif");
}

void FileManagement::deleteFile() {
    QFile::remove(".temp/temp.gif");
}
