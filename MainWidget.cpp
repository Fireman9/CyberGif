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

    commandsApplier = new CommandsApplier();

    connect(gifScene, &GifScene::muteCommandButs, this, &MainWidget::hideCommands);
    connect(gifScene, &GifScene::unmuteCommandButs, this, &MainWidget::showCommands);

    connect(gifScene, &GifScene::fileUploaded, fileManagement, &FileManagement::loadFile);
    connect(gifScene, &GifScene::fileSave, fileManagement, &FileManagement::saveFile);
    connect(gifScene, &GifScene::fileSaveAs, fileManagement, &FileManagement::saveFile);
    connect(gifScene, &GifScene::fileClosed, fileManagement, &FileManagement::deleteFile);

    connect(commandsApplier, &CommandsApplier::updateSceneSig, gifScene, &GifScene::updateGif);

    connect(commandsWidget->getResizeCommandWidget(), &ResizeCommandWidget::applyResizeSig,
            commandsApplier, &CommandsApplier::resize);
}

void MainWidget::hideCommands() {
    commandsWidget->hide();
}

void MainWidget::showCommands() {
    commandsWidget->show();
}
