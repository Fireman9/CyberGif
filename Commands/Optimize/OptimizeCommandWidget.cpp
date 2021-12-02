#include "OptimizeCommandWidget.hpp"
#include "ui_OptimizeCommandWidget.h"

OptimizeCommandWidget::OptimizeCommandWidget(QWidget *parent) :
	QWidget(parent), ui(new Ui::OptimizeCommandWidget) {
  ui->setupUi(this);
  connect(ui->applyButton, &QPushButton::released,
		  this, &OptimizeCommandWidget::applySlot);
}

QPushButton *OptimizeCommandWidget::getReturnBackBtn() const {
  return ui->returnBackBtn;
}

void OptimizeCommandWidget::applySlot() {
  emit applyOptimizeSignal();
}

OptimizeCommandWidget::~OptimizeCommandWidget() {
  delete ui;
}
