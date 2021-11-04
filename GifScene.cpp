#include "GifScene.h"

GifScene::GifScene(QWidget *parent) {
    filename = "";
    clickToOpenBut = new QPushButton("Click to open new gifFile");
    gif = new QLabel();
    gifFile = new QMovie();
    gif->setMovie(gifFile);

    // TODO: move to stylesheet file
    clickToOpenBut->setStyleSheet("height: 100%;");
    gif->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);

    mainLayout = new QHBoxLayout();

    mainLayout->addWidget(clickToOpenBut);
    mainLayout->addWidget(gif);

    setOpenFileButToScene();

    setLayout(mainLayout);

    connect(clickToOpenBut, &QPushButton::released, this, &GifScene::openFile);
}

void GifScene::openFile() {
    filename = QFileDialog::getOpenFileName(this, "Open File",
                                            "", "Gif file (*.gif)");
    qDebug() << filename;
    if (filename != "") setGifToScene();
}

void GifScene::setOpenFileButToScene() {
    gif->hide();
    clickToOpenBut->show();
    
    emit muteCommandButs();
}

void GifScene::setGifToScene() {
    clickToOpenBut->hide();
    gif->show();

    gifFile->setFileName(filename);
    gifFile->start();

    emit unmuteCommandButs();
}
