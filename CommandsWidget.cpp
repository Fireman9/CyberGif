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

    mainLayout->addWidget(resizeCommandWidget);
    resizeCommandWidget->hide();

    setLayout(mainLayout);

    connect(resize, &QPushButton::released, this, &CommandsWidget::changeToResizeWidget);
    connect(resizeCommandWidget->getReturnBackBtn(), &QPushButton::released,
            this, &CommandsWidget::changeToCommandsWidget);
}

void CommandsWidget::changeToCommandsWidget() {
    resizeCommandWidget->hide();

    resize->show();
    speed->show();
    rotate->show();
    crop->show();
    optimize->show();
}

void CommandsWidget::changeToResizeWidget() {
    resize->hide();
    speed->hide();
    rotate->hide();
    crop->hide();
    optimize->hide();

    resizeCommandWidget->show();
}

ResizeCommandWidget *CommandsWidget::getResizeCommandWidget() const {
    return resizeCommandWidget;
}
