#include "MainWidget.h"

MainWidget::MainWidget(QWidget *parent) {
    gifScene = new GifScene();
    commandsWidget = new CommandsWidget();

    mainLayout = new QVBoxLayout();

    mainLayout->addWidget(gifScene);
    mainLayout->addWidget(commandsWidget);

    commandsWidget->hide();

    setLayout(mainLayout);

    connect(gifScene, &GifScene::muteCommandButs, this, &MainWidget::hideCommands);
    connect(gifScene, &GifScene::unmuteCommandButs, this, &MainWidget::showCommands);
}

void MainWidget::hideCommands() {
    commandsWidget->hide();
}

void MainWidget::showCommands() {
    commandsWidget->show();
}
