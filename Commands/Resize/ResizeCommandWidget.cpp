#include "ResizeCommandWidget.hpp"
#include "ui_ResizeCommandWidget.h"


ResizeCommandWidget::ResizeCommandWidget(QWidget *parent) :
        QWidget(parent), ui(new Ui::ResizeCommandWidget) {
    ui->setupUi(this);
    connect(ui->applyBtn, &QPushButton::released, this, &ResizeCommandWidget::apply);

    connect(ui->fitWidth, &QCheckBox::stateChanged, this, &ResizeCommandWidget::muteHeight);
    connect(ui->fitHeight, &QCheckBox::stateChanged, this, &ResizeCommandWidget::muteWidth);
}

void ResizeCommandWidget::muteWidth() {
    if (ui->fitHeight->isChecked()) {
        ui->widthInput->setDisabled(true);
        ui->fitWidth->setDisabled(true);

        ui->heightInput->setDisabled(false);
        ui->fitHeight->setDisabled(false);
    } else {
        ui->widthInput->setDisabled(false);
        ui->fitWidth->setDisabled(false);
    }
}

void ResizeCommandWidget::muteHeight() {
    if (ui->fitWidth->isChecked()) {
        ui->heightInput->setDisabled(true);
        ui->fitHeight->setDisabled(true);

        ui->widthInput->setDisabled(false);
        ui->fitWidth->setDisabled(false);
    } else {
        ui->heightInput->setDisabled(false);
        ui->fitHeight->setDisabled(false);
    }
}

void ResizeCommandWidget::apply() {
    if (ui->fitWidth->isChecked()) {
        emit applyFitWidthSig(ui->widthInput->value());
    } else if (ui->fitHeight->isChecked()) {
        emit applyFitHeightSig(ui->heightInput->value());
    } else {
        emit applyResizeSig(ui->widthInput->value(), ui->heightInput->value());
    }
}

QPushButton *ResizeCommandWidget::getReturnBackBtn() const {
    return ui->returnBackBtn;
}

ResizeCommandWidget::~ResizeCommandWidget() {
    delete ui;
}
