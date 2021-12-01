#include "FileManagement.h"

void FileManagement::loadFileSlot(const QString &filename) {
    if (!QDir(".temp").exists()) {
        QDir().mkdir(".temp");
    }
    if (QFile(".temp/temp.gif").exists()) deleteFileSlot();
    QFile::copy(filename, ".temp/temp.gif");
}

void FileManagement::saveFileSlot(const QString &filename) {
    if (QFile(filename).exists()) {
        QFile::remove(filename);
    }
    QFile::copy(".temp/temp.gif", filename);
}

void FileManagement::deleteFileSlot() {
    QFile::remove(".temp/temp.gif");
}
