#ifndef CYBERGIF_GIFSCENE_H
#define CYBERGIF_GIFSCENE_H


#include <QWidget>
#include <QString>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFileDialog>
#include <QMovie>
#include <QToolBar>
#include <QToolButton>
#include <QFileInfo>

class GifScene : public QWidget {
Q_OBJECT
public:
    GifScene(QWidget *parent = nullptr);

public slots:

    void openFile();

    void saveFile();

    void saveAsFile();

    void closeFile();

    void stopGif();

    void updateGif();

signals:

    void muteCommandButs();

    void unmuteCommandButs();

    void fileUploaded(const QString &filename);

    void fileSave(const QString &filename);

    void fileSaveAs(const QString &filename);

    void fileClosed();

private:
    QString filename;
    QPushButton *clickToOpenBut;
    QLabel *gif;
    QMovie *gifFile;
    QLabel *filenameLbl;
    QLabel *widthLbl;
    QLabel *heightLbl;
    QLabel *speedLbl;
    QLabel *sizeLbl;

    QToolBar *toolbar;
    QToolButton *open;
    QToolButton *save;
    QToolButton *saveAs;
    QToolButton *close;

    QVBoxLayout *mainLayout;
    QHBoxLayout *bodyLayout;
    QVBoxLayout *infoLayout;

    void setOpenFileButToScene();

    void setGifToScene();

    void setToolBar();

    void setInfo();

    void showInfo();

    void hideInfo();
};


#endif //CYBERGIF_GIFSCENE_H
