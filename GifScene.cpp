#include "GifScene.h"

GifScene::GifScene(QWidget *parent) {
    toolbar = new QToolBar();
    setToolBar();

    filename = "";
    clickToOpenBut = new QPushButton("Click to open new gifFile");
    gif = new QLabel();
    gifFile = new QMovie();
    gif->setMovie(gifFile);

    // TODO: move to stylesheet file
    clickToOpenBut->setStyleSheet("height: 100%;");
    gif->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);

    mainLayout = new QVBoxLayout();

    mainLayout->addWidget(toolbar);
    mainLayout->addWidget(clickToOpenBut);
    mainLayout->addWidget(gif);

    setOpenFileButToScene();

    setLayout(mainLayout);

    connect(clickToOpenBut, &QPushButton::released, this, &GifScene::openFile);
    connect(open, &QToolButton::released, this, &GifScene::openFile);

    connect(close, &QToolButton::released, this, &GifScene::closeFile);
}

void GifScene::setToolBar() {
    open = new QToolButton();
    open->setText("Open");

    save = new QToolButton();
    save->setText("Save");

    saveAs = new QToolButton();
    saveAs->setText("Save as");

    close = new QToolButton();
    close->setText("Close");

    toolbar->addWidget(open);
    toolbar->addWidget(save);
    toolbar->addWidget(saveAs);
    toolbar->addWidget(close);
}

void GifScene::openFile() {
    filename = QFileDialog::getOpenFileName(this, "Open File",
                                            "", "Gif file (*.gif)");
    if (filename != "") {
        setGifToScene();
        emit fileUploaded(filename);
    }
}

void GifScene::saveFile() {

}

void GifScene::saveAsFile() {

}

void GifScene::closeFile() {
    setOpenFileButToScene();

    emit fileClosed();
}

void GifScene::setOpenFileButToScene() {
    gif->hide();
    gifFile->stop();

    clickToOpenBut->show();
    open->setDisabled(false);

    emit muteCommandButs();
}

void GifScene::setGifToScene() {
    clickToOpenBut->hide();
    open->setDisabled(true);

    gif->show();
    gifFile->setFileName(filename);
    gifFile->start();

    emit unmuteCommandButs();
}
