#include "MainWidget.h"

MainWidget::MainWidget(QWidget *parent) {
    gifScene = new GifWidget();
    commandsWidget = new CommandsWidget();
    fileManagement = new FileManagement();
    commandsApplier = new CommandsApplier();

    mainLayout = new QVBoxLayout();

    mainLayout->addWidget(gifScene);
    mainLayout->addWidget(commandsWidget);

    commandsWidget->hide();

    setLayout(mainLayout);

    connect(gifScene, &GifWidget::muteCommandButs, this, &MainWidget::hideCommands);
    connect(gifScene, &GifWidget::unmuteCommandButs, this, &MainWidget::showCommands);

    connect(gifScene, &GifWidget::fileUploaded, fileManagement, &FileManagement::loadFile);
    connect(gifScene, &GifWidget::fileSave, fileManagement, &FileManagement::saveFile);
    connect(gifScene, &GifWidget::fileSaveAs, fileManagement, &FileManagement::saveFile);
    connect(gifScene, &GifWidget::fileClosed, fileManagement, &FileManagement::deleteFile);

    connect(commandsApplier, &CommandsApplier::updateSceneSig, gifScene, &GifWidget::updateGif);

    connect(commandsWidget->getResizeCommandWidget(), &ResizeCommandWidget::applyResizeSig,
            commandsApplier, &CommandsApplier::resize);
    connect(commandsWidget->getResizeCommandWidget(), &ResizeCommandWidget::applyFitWidthSig,
            commandsApplier, &CommandsApplier::fitWidth);
    connect(commandsWidget->getResizeCommandWidget(), &ResizeCommandWidget::applyFitHeightSig,
            commandsApplier, &CommandsApplier::fitHeight);
    connect(commandsWidget->getSpeedCommandWidget(), &SpeedCommandWidget::applySpeedSig,
            commandsApplier, &CommandsApplier::setSpeed);
    connect(commandsWidget->getRotateCommandWidget(), &RotateCommandWidget::applyRotateSig,
            commandsApplier, &CommandsApplier::rotate);
    connect(commandsWidget->getCropCommandWidget(), &CropCommandWidget::applyCropSig,
            commandsApplier, &CommandsApplier::crop);
    connect(commandsWidget->getOptimizeCommandWidget(), &OptimizeCommandWidget::applyOptimizeSig,
            commandsApplier, &CommandsApplier::optimize);
}

void MainWidget::hideCommands() {
    commandsWidget->hide();
}

void MainWidget::showCommands() {
    commandsWidget->show();
}
