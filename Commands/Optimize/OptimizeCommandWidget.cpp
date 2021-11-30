#include "OptimizeCommandWidget.hpp"
#include "ui_OptimizeCommandWidget.h"


OptimizeCommandWidget::OptimizeCommandWidget(QWidget *parent) :
        QWidget(parent), ui(new Ui::OptimizeCommandWidget) {
    ui->setupUi(this);
    connect(ui->applyButton, &QPushButton::released, this, &OptimizeCommandWidget::apply);
}

QPushButton *OptimizeCommandWidget::getReturnBackBtn() const {
    return ui->returnBackBtn;
}

void OptimizeCommandWidget::apply() {
    emit applyOptimizeSig();
}

OptimizeCommandWidget::~OptimizeCommandWidget() {
    delete ui;
}
