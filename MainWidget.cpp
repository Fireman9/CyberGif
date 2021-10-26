#include "MainWidget.h"

MainWidget::MainWidget(QWidget *parent) {
    gifScene = new GifScene();
    commandsWidget = new CommandsWidget();

    mainLayout = new QVBoxLayout();

    mainLayout->addWidget(gifScene);
    mainLayout->addWidget(commandsWidget);

    setLayout(mainLayout);
}
