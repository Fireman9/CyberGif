#ifndef CYBERGIF_FILEMANAGEMENT_H
#define CYBERGIF_FILEMANAGEMENT_H


#include <QObject>
#include <QFile>
#include <QDir>

class FileManagement : public QObject {
Q_OBJECT
public:

public slots:

    void loadFile(const QString &filename);

    void saveFile(const QString &filename);

    void deleteFile();

};


#endif //CYBERGIF_FILEMANAGEMENT_H
