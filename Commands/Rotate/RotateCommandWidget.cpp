#include "RotateCommandWidget.hpp"
#include "ui_RotateCommandWidget.h"

RotateCommandWidget::RotateCommandWidget(QWidget *parent) :
	QWidget(parent), ui(new Ui::RotateCommandWidget) {
  ui->setupUi(this);
  connect(ui->rotateLeftButton, &QPushButton::released,
		  this, &RotateCommandWidget::rotateLeftSlot);
  connect(ui->rotateRightButton, &QPushButton::released,
		  this, &RotateCommandWidget::rotateRightSlot);
}

void RotateCommandWidget::rotateLeftSlot() {
  emit applyRotateSignal(270);
}

void RotateCommandWidget::rotateRightSlot() {
  emit applyRotateSignal(90);
}

QPushButton *RotateCommandWidget::getReturnBackBtn() const {
  return ui->returnBackBtn;
}

RotateCommandWidget::~RotateCommandWidget() {
  delete ui;
}
