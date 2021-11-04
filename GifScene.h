#ifndef CYBERGIF_GIFSCENE_H
#define CYBERGIF_GIFSCENE_H


#include <QWidget>
#include <QString>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QFileDialog>
#include <QDebug>
#include <QMovie>

class GifScene : public QWidget {
Q_OBJECT
public:
    GifScene(QWidget *parent = nullptr);


public slots:

    void openFile();

signals:
    void muteCommandButs();
    void unmuteCommandButs();
    void fileUploaded(QString filename);

private:
    QString filename;
    QPushButton *clickToOpenBut;
    QLabel *gif;
    QMovie *gifFile;

    QHBoxLayout *mainLayout;

    void setOpenFileButToScene();

    void setGifToScene();
};


#endif //CYBERGIF_GIFSCENE_H
