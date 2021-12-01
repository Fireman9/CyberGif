#include "MainWidget.h"

MainWidget::MainWidget(QWidget *parent) {
    gifWidget = new GifWidget();
    commandsWidget = new CommandsWidget();
    fileManagement = new FileManagement();
    commandsApplier = new CommandsApplier();

    mainLayout = new QVBoxLayout();

    mainLayout->addWidget(gifWidget);
    mainLayout->addWidget(commandsWidget);

    commandsWidget->hide();

    setLayout(mainLayout);

    connect(gifWidget, &GifWidget::muteCommandButsSignal, this, &MainWidget::hideCommandsSlot);
    connect(gifWidget, &GifWidget::unmuteCommandButsSignal, this, &MainWidget::showCommandsSlot);

    connect(gifWidget, &GifWidget::fileUploadedSignal, fileManagement, &FileManagement::loadFileSlot);
    connect(gifWidget, &GifWidget::fileSaveSignal, fileManagement, &FileManagement::saveFileSlot);
    connect(gifWidget, &GifWidget::fileSaveAsSignal, fileManagement, &FileManagement::saveFileSlot);
    connect(gifWidget, &GifWidget::fileClosedSignal, fileManagement, &FileManagement::deleteFileSlot);

    connect(commandsApplier, &CommandsApplier::updateSceneSignal, gifWidget, &GifWidget::updateGifSlot);

    connect(commandsWidget->getResizeCommandWidget(), &ResizeCommandWidget::applyResizeSignal,
            commandsApplier, &CommandsApplier::resizeSlot);
    connect(commandsWidget->getResizeCommandWidget(), &ResizeCommandWidget::applyFitWidthSignal,
            commandsApplier, &CommandsApplier::fitWidthSlot);
    connect(commandsWidget->getResizeCommandWidget(), &ResizeCommandWidget::applyFitHeightSignal,
            commandsApplier, &CommandsApplier::fitHeightSlot);
    connect(commandsWidget->getSpeedCommandWidget(), &SpeedCommandWidget::applySpeedSignal,
            commandsApplier, &CommandsApplier::setSpeedSlot);
    connect(commandsWidget->getRotateCommandWidget(), &RotateCommandWidget::applyRotateSignal,
            commandsApplier, &CommandsApplier::rotateSlot);
    connect(commandsWidget->getCropCommandWidget(), &CropCommandWidget::applyCropSignal,
            commandsApplier, &CommandsApplier::cropSlot);
    connect(commandsWidget->getOptimizeCommandWidget(), &OptimizeCommandWidget::applyOptimizeSignal,
            commandsApplier, &CommandsApplier::optimizeSlot);
}

void MainWidget::hideCommandsSlot() {
    commandsWidget->hide();
}

void MainWidget::showCommandsSlot() {
    commandsWidget->show();
}
