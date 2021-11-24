#include "RotateCommandWidget.hpp"
#include "ui_RotateCommandWidget.h"


RotateCommandWidget::RotateCommandWidget(QWidget *parent) :
        QWidget(parent), ui(new Ui::RotateCommandWidget) {
    ui->setupUi(this);
    connect(ui->rotateLeftButton, &QPushButton::released, this, &RotateCommandWidget::rotateLeft);
    connect(ui->rotateRightButton, &QPushButton::released, this, &RotateCommandWidget::rotateRight);
}

void RotateCommandWidget::rotateLeft() {
    emit applyRotateSig(270);
}

void RotateCommandWidget::rotateRight() {
    emit applyRotateSig(90);
}

QPushButton *RotateCommandWidget::getReturnBackBtn() const {
    return ui->returnBackBtn;
}

RotateCommandWidget::~RotateCommandWidget() {
    delete ui;
}
