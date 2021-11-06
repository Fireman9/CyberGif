#include "FileManagement.h"

void FileManagement::loadFile(const QString &filename) {
    if (!QDir(".temp").exists()) {
        QDir().mkdir(".temp");
    }
    if (QFile(".temp/temp.gif").exists()) deleteFile();
    QFile::copy(filename, ".temp/temp.gif");
}

void FileManagement::saveFile(const QString &filename) {
    if (QFile(filename).exists()) {
        QFile::remove(filename);
    }
    QFile::copy(".temp/temp.gif", filename);
}

void FileManagement::deleteFile() {
    QFile::remove(".temp/temp.gif");
}
