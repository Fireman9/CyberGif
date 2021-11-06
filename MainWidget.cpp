#include "MainWidget.h"

MainWidget::MainWidget(QWidget *parent) {
    gifScene = new GifScene();
    commandsWidget = new CommandsWidget();
    fileManagement = new FileManagement();

    mainLayout = new QVBoxLayout();

    mainLayout->addWidget(gifScene);
    mainLayout->addWidget(commandsWidget);

    commandsWidget->hide();

    setLayout(mainLayout);

    connect(gifScene, &GifScene::muteCommandButs, this, &MainWidget::hideCommands);
    connect(gifScene, &GifScene::unmuteCommandButs, this, &MainWidget::showCommands);

    connect(gifScene, &GifScene::fileUploaded, fileManagement, &FileManagement::loadFile);
    connect(gifScene, &GifScene::fileClosed, fileManagement, &FileManagement::deleteFile);
    connect(gifScene, &GifScene::fileSave, fileManagement, &FileManagement::saveFile);
}

void MainWidget::hideCommands() {
    commandsWidget->hide();
}

void MainWidget::showCommands() {
    commandsWidget->show();
}
