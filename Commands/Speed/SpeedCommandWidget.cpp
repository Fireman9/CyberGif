#include "SpeedCommandWidget.hpp"
#include "ui_SpeedCommandWidget.h"


SpeedCommandWidget::SpeedCommandWidget(QWidget *parent) :
        QWidget(parent), ui(new Ui::SpeedCommandWidget) {
    ui->setupUi(this);
    connect(ui->applyButton, &QPushButton::released, this, &SpeedCommandWidget::applySlot);
}

void SpeedCommandWidget::applySlot() {
    emit applySpeedSignal(ui->frameDelayInput->value() / 10);
}

QPushButton *SpeedCommandWidget::getReturnBackBtn() const {
    return ui->returnBackBtn;
}

SpeedCommandWidget::~SpeedCommandWidget() {
    delete ui;
}

