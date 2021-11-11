#include "ResizeCommandWidget.h"

ResizeCommandWidget::ResizeCommandWidget(QWidget *parent) {
    widthLbl = new QLabel("Width: ");
    heightLbl = new QLabel("Height: ");
    widthInput = new QSpinBox();
    widthInput->setMaximum(1920);
    widthInput->setMinimum(10);
    heightInput = new QSpinBox();
    heightInput->setMaximum(1080);
    heightInput->setMinimum(10);
    keepAspectRatio = new QCheckBox("Keep aspect ratio");
    returnBackBtn = new QPushButton("Back");
    applyBtn = new QPushButton("Apply");

    widthLayout = new QHBoxLayout();
    widthLayout->addWidget(widthLbl);
    widthLayout->addWidget(widthInput);

    heightLayout = new QHBoxLayout();
    heightLayout->addWidget(heightLbl);
    heightLayout->addWidget(heightInput);

    whLayout = new QVBoxLayout();
    whLayout->addLayout(widthLayout);
    whLayout->addLayout(heightLayout);

    aspectRatioLayout = new QVBoxLayout();
    aspectRatioLayout->addWidget(keepAspectRatio);

    bottomLayout = new QHBoxLayout();
    bottomLayout->addLayout(whLayout);
    bottomLayout->addLayout(aspectRatioLayout);
    bottomLayout->addWidget(applyBtn);

    topLayout = new QHBoxLayout();
    topLayout->addWidget(returnBackBtn);

    mainLayout = new QVBoxLayout();
    mainLayout->addLayout(topLayout);
    mainLayout->addLayout(bottomLayout);

    setLayout(mainLayout);

    connect(applyBtn, &QPushButton::released, this, &ResizeCommandWidget::applyResize);
}

void ResizeCommandWidget::applyResize() {
    emit applyResizeSig(widthInput->value(), heightInput->value());
}

QPushButton *ResizeCommandWidget::getReturnBackBtn() const {
    return returnBackBtn;
}
