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
    fitWidth = new QCheckBox("Fit to width");
    fitHeight = new QCheckBox("Fit to height");
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
    aspectRatioLayout->addWidget(fitWidth);
    aspectRatioLayout->addWidget(fitHeight);

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

    connect(applyBtn, &QPushButton::released, this, &ResizeCommandWidget::apply);

    connect(fitWidth, &QCheckBox::stateChanged, this, &ResizeCommandWidget::muteHeight);
    connect(fitHeight, &QCheckBox::stateChanged, this, &ResizeCommandWidget::muteWidth);
}

void ResizeCommandWidget::muteWidth() {
    if (fitHeight->isChecked()) {
        widthInput->setDisabled(true);
        fitWidth->setDisabled(true);

        heightInput->setDisabled(false);
        fitHeight->setDisabled(false);
    } else {
        widthInput->setDisabled(false);
        fitWidth->setDisabled(false);
    }
}

void ResizeCommandWidget::muteHeight() {
    if (fitWidth->isChecked()) {
        heightInput->setDisabled(true);
        fitHeight->setDisabled(true);

        widthInput->setDisabled(false);
        fitWidth->setDisabled(false);
    } else {
        heightInput->setDisabled(false);
        fitHeight->setDisabled(false);
    }
}

void ResizeCommandWidget::apply() {
    if (fitWidth->isChecked()) {
        emit applyFitWidthSig(widthInput->value());
    } else if (fitHeight->isChecked()) {
        emit applyFitHeightSig(heightInput->value());
    } else {
        emit applyResizeSig(widthInput->value(), heightInput->value());
    }
}

QPushButton *ResizeCommandWidget::getReturnBackBtn() const {
    return returnBackBtn;
}
