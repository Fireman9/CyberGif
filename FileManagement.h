#ifndef CYBERGIF_FILEMANAGEMENT_H
#define CYBERGIF_FILEMANAGEMENT_H

#include <QObject>
#include <QFile>
#include <QDir>

class FileManagement : public QObject {
 Q_OBJECT
 public slots:
  void loadFileSlot(const QString &filename);

  void saveFileSlot(const QString &filename);

  void deleteFileSlot();

};

#endif //CYBERGIF_FILEMANAGEMENT_H
