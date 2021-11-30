#include "CommandsWidget.h"

CommandsWidget::CommandsWidget(QWidget *parent) {
    resize = new QPushButton("Resize");
    speed = new QPushButton("Set speed");
    rotate = new QPushButton("Rotate");
    crop = new QPushButton("Crop");
    optimize = new QPushButton("Optimize");

    mainLayout = new QHBoxLayout();

    mainLayout->addWidget(resize);
    mainLayout->addWidget(speed);
    mainLayout->addWidget(rotate);
    mainLayout->addWidget(crop);
    mainLayout->addWidget(optimize);

    resizeCommandWidget = new ResizeCommandWidget();
    speedCommandWidget = new SpeedCommandWidget();
    rotateCommandWidget = new RotateCommandWidget();
    optimizeCommandWidget = new OptimizeCommandWidget();

    mainLayout->addWidget(resizeCommandWidget);
    mainLayout->addWidget(speedCommandWidget);
    mainLayout->addWidget(rotateCommandWidget);
    mainLayout->addWidget(optimizeCommandWidget);
    resizeCommandWidget->hide();
    speedCommandWidget->hide();
    rotateCommandWidget->hide();
    optimizeCommandWidget->hide();

    setLayout(mainLayout);

    connect(resize, &QPushButton::released, this, &CommandsWidget::changeToResizeWidget);
    connect(speed, &QPushButton::released, this, &CommandsWidget::changeToSpeedWidget);
    connect(rotate, &QPushButton::released, this, &CommandsWidget::changeToRotateWidget);
    connect(optimize, &QPushButton::released, this, &CommandsWidget::changeToOptimizeWidget);

    connect(resizeCommandWidget->getReturnBackBtn(), &QPushButton::released,
            this, &CommandsWidget::changeToCommandsWidget);
    connect(speedCommandWidget->getReturnBackBtn(), &QPushButton::released,
            this, &CommandsWidget::changeToCommandsWidget);
    connect(rotateCommandWidget->getReturnBackBtn(), &QPushButton::released,
            this, &CommandsWidget::changeToCommandsWidget);
    connect(optimizeCommandWidget->getReturnBackBtn(), &QPushButton::released,
            this, &CommandsWidget::changeToCommandsWidget);
}

void CommandsWidget::changeToCommandsWidget() {
    resizeCommandWidget->hide();
    speedCommandWidget->hide();
    rotateCommandWidget->hide();
    optimizeCommandWidget->hide();

    resize->show();
    speed->show();
    rotate->show();
    crop->show();
    optimize->show();
}

void CommandsWidget::changeToResizeWidget() {
    hideCommands();
    resizeCommandWidget->show();
}

void CommandsWidget::changeToSpeedWidget() {
    hideCommands();
    speedCommandWidget->show();
}

void CommandsWidget::changeToRotateWidget() {
    hideCommands();
    rotateCommandWidget->show();
}

void CommandsWidget::changeToOptimizeWidget() {
    hideCommands();
    optimizeCommandWidget->show();
}

void CommandsWidget::hideCommands() {
    resize->hide();
    speed->hide();
    rotate->hide();
    crop->hide();
    optimize->hide();
}

ResizeCommandWidget *CommandsWidget::getResizeCommandWidget() const {
    return resizeCommandWidget;
}

SpeedCommandWidget *CommandsWidget::getSpeedCommandWidget() const {
    return speedCommandWidget;
}

RotateCommandWidget *CommandsWidget::getRotateCommandWidget() const {
    return rotateCommandWidget;
}

OptimizeCommandWidget *CommandsWidget::getOptimizeCommandWidget() const {
    return optimizeCommandWidget;
}
