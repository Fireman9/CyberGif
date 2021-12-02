#include "CropCommandWidget.hpp"
#include "ui_CropCommandWidget.h"

CropCommandWidget::CropCommandWidget(QWidget *parent) :
	QWidget(parent), ui(new Ui::CropCommandWidget) {
  ui->setupUi(this);
  connect(ui->applyButton, &QPushButton::released,
		  this, &CropCommandWidget::applySlot);
}

void CropCommandWidget::applySlot() {
  emit applyCropSignal(ui->xInput->value(), ui->yInput->value(),
					   ui->widthInput->value(), ui->heightInput->value());
}

QPushButton *CropCommandWidget::getReturnBackBtn() const {
  return ui->returnBackBtn;
}

CropCommandWidget::~CropCommandWidget() {
  delete ui;
}
