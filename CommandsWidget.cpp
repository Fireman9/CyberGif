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

    setLayout(mainLayout);
}
