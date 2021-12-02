#ifndef CYBERGIF_GIFWIDGET_H
#define CYBERGIF_GIFWIDGET_H


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

class GifWidget : public QWidget {
Q_OBJECT
public:
    GifWidget(QWidget *parent = nullptr);

public slots:

    void openFileSlot();

    void saveFileSlot();

    void saveAsFileSlot();

    void closeFileSlot();

    void stopGifSlot();

    void updateGifSlot();

signals:

    void muteCommandButsSignal();

    void unmuteCommandButsSignal();

    void fileUploadedSignal(const QString &filename);

    void fileSaveSignal(const QString &filename);

    void fileSaveAsSignal(const QString &filename);

    void fileClosedSignal();

    void sizeChanged();

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


#endif //CYBERGIF_GIFWIDGET_H
