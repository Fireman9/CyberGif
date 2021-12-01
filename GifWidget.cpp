#include "GifWidget.h"

GifWidget::GifWidget(QWidget *parent) {
    toolbar = new QToolBar();
    setToolBar();

    filename = "";
    clickToOpenBut = new QPushButton("Click to open new gifFile");
    gif = new QLabel();
    gifFile = new QMovie();
    gif->setMovie(gifFile);

    filenameLbl = new QLabel();
    widthLbl = new QLabel();
    heightLbl = new QLabel();
    speedLbl = new QLabel();
    sizeLbl = new QLabel();

    // TODO: move to stylesheet file
    clickToOpenBut->setStyleSheet("height: 100%;");
    gif->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);

    mainLayout = new QVBoxLayout();
    bodyLayout = new QHBoxLayout();
    infoLayout = new QVBoxLayout();

    mainLayout->addWidget(toolbar);

    bodyLayout->addWidget(clickToOpenBut);
    bodyLayout->addWidget(gif);

    infoLayout->addWidget(filenameLbl);
    infoLayout->addWidget(widthLbl);
    infoLayout->addWidget(heightLbl);
    infoLayout->addWidget(speedLbl);
    infoLayout->addWidget(sizeLbl);

    bodyLayout->addLayout(infoLayout);
    hideInfo();

    mainLayout->addLayout(bodyLayout);

    setOpenFileButToScene();

    setLayout(mainLayout);

    connect(clickToOpenBut, &QPushButton::released, this, &GifWidget::openFileSlot);

    connect(open, &QToolButton::released, this, &GifWidget::openFileSlot);
    connect(save, &QToolButton::released, this, &GifWidget::saveFileSlot);
    connect(saveAs, &QToolButton::released, this, &GifWidget::saveAsFileSlot);
    connect(close, &QToolButton::released, this, &GifWidget::closeFileSlot);
}

void GifWidget::setToolBar() {
    open = new QToolButton();
    open->setText("Open");

    save = new QToolButton();
    save->setText("Save");

    saveAs = new QToolButton();
    saveAs->setText("Save as");

    close = new QToolButton();
    close->setText("Close");

    save->setDisabled(true);
    saveAs->setDisabled(true);
    close->setDisabled(true);

    toolbar->addWidget(open);
    toolbar->addWidget(save);
    toolbar->addWidget(saveAs);
    toolbar->addWidget(close);
}

void GifWidget::openFileSlot() {
    filename = QFileDialog::getOpenFileName(this, "Open File",
                                            "/", "Gif file (*.gif)");
    if (filename != "") {
        emit fileUploadedSignal(filename);
        setGifToScene();
    }
}

void GifWidget::saveFileSlot() {
    emit fileSaveSignal(filename);
}

void GifWidget::saveAsFileSlot() {
    QString newSaveAsFileName = QFileDialog::getSaveFileName(this, "Save File",
                                                             "/", "Gif file (*.gif)");
    if (newSaveAsFileName != "") {
        emit fileSaveAsSignal(newSaveAsFileName);
    }
}

void GifWidget::closeFileSlot() {
    setOpenFileButToScene();
    emit fileClosedSignal();
}

void GifWidget::stopGifSlot() {
    gifFile->stop();
}

void GifWidget::updateGifSlot() {
    stopGifSlot();
    gifFile->setFileName(".temp/temp.gif");
    gifFile->start();
    setInfo();
}

void GifWidget::setOpenFileButToScene() {
    gif->hide();
    gifFile->stop();

    hideInfo();

    save->setDisabled(true);
    saveAs->setDisabled(true);
    close->setDisabled(true);

    clickToOpenBut->show();
    open->setDisabled(false);

    emit muteCommandButsSignal();
}

void GifWidget::setGifToScene() {
    clickToOpenBut->hide();
    open->setDisabled(true);

    save->setDisabled(false);
    saveAs->setDisabled(false);
    close->setDisabled(false);

    gif->show();
    gifFile->setFileName(".temp/temp.gif");
    gifFile->start();

    setInfo();
    showInfo();

    emit unmuteCommandButsSignal();
}

void GifWidget::setInfo() {
    filenameLbl->setText(QString("Filename: %1")
                                 .arg(QFileInfo(filename).fileName()));
    widthLbl->setText(QString("Width: %1 px")
                              .arg(QString::number(gifFile->currentImage().width())));
    heightLbl->setText(QString("Height: %1 px")
                               .arg(QString::number(gifFile->currentImage().height())));
    speedLbl->setText(QString("Frame delay: %1 ms")
                              .arg(QString::number(gifFile->nextFrameDelay())));
    sizeLbl->setText(QString("Filesize: %1 kb")
                             .arg(QString::number(QFileInfo("./.temp/temp.gif").size() / 1000)));
}

void GifWidget::showInfo() {
    filenameLbl->show();
    widthLbl->show();
    heightLbl->show();
    speedLbl->show();
    sizeLbl->show();
}

void GifWidget::hideInfo() {
    filenameLbl->hide();
    widthLbl->hide();
    heightLbl->hide();
    speedLbl->hide();
    sizeLbl->hide();
}
