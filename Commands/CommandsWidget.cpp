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

  resizeCommandWidget = new ResizeCommandWidget();
  speedCommandWidget = new SpeedCommandWidget();
  rotateCommandWidget = new RotateCommandWidget();
  optimizeCommandWidget = new OptimizeCommandWidget();
  cropCommandWidget = new CropCommandWidget();

  mainLayout->addWidget(resizeCommandWidget);
  mainLayout->addWidget(speedCommandWidget);
  mainLayout->addWidget(rotateCommandWidget);
  mainLayout->addWidget(optimizeCommandWidget);
  mainLayout->addWidget(cropCommandWidget);
  resizeCommandWidget->hide();
  speedCommandWidget->hide();
  rotateCommandWidget->hide();
  optimizeCommandWidget->hide();
  cropCommandWidget->hide();

  setLayout(mainLayout);

  connect(resize, &QPushButton::released, this, &CommandsWidget::toResizeWidgetSlot);
  connect(speed, &QPushButton::released, this, &CommandsWidget::toSpeedWidgetSlot);
  connect(rotate, &QPushButton::released, this, &CommandsWidget::toRotateWidgetSlot);
  connect(crop, &QPushButton::released, this, &CommandsWidget::toCropWidgetSlot);
  connect(optimize, &QPushButton::released, this, &CommandsWidget::toOptimizeWidgetSlot);

  connect(resizeCommandWidget->getReturnBackBtn(), &QPushButton::released,
		  this, &CommandsWidget::toCommandsWidgetSlot);
  connect(speedCommandWidget->getReturnBackBtn(), &QPushButton::released,
		  this, &CommandsWidget::toCommandsWidgetSlot);
  connect(rotateCommandWidget->getReturnBackBtn(), &QPushButton::released,
		  this, &CommandsWidget::toCommandsWidgetSlot);
  connect(cropCommandWidget->getReturnBackBtn(), &QPushButton::released,
		  this, &CommandsWidget::toCommandsWidgetSlot);
  connect(optimizeCommandWidget->getReturnBackBtn(), &QPushButton::released,
		  this, &CommandsWidget::toCommandsWidgetSlot);
}

void CommandsWidget::toCommandsWidgetSlot() {
  resizeCommandWidget->hide();
  speedCommandWidget->hide();
  rotateCommandWidget->hide();
  optimizeCommandWidget->hide();
  cropCommandWidget->hide();

  resize->show();
  speed->show();
  rotate->show();
  crop->show();
  optimize->show();

  emit sizeChanged();
}

void CommandsWidget::toResizeWidgetSlot() {
  hideCommands();
  resizeCommandWidget->show();
  emit sizeChanged();
}

void CommandsWidget::toSpeedWidgetSlot() {
  hideCommands();
  speedCommandWidget->show();
  emit sizeChanged();
}

void CommandsWidget::toRotateWidgetSlot() {
  hideCommands();
  rotateCommandWidget->show();
  emit sizeChanged();
}

void CommandsWidget::toCropWidgetSlot() {
  hideCommands();
  cropCommandWidget->show();
  emit sizeChanged();
}

void CommandsWidget::toOptimizeWidgetSlot() {
  hideCommands();
  optimizeCommandWidget->show();
  emit sizeChanged();
}

void CommandsWidget::hideCommands() {
  resize->hide();
  speed->hide();
  rotate->hide();
  crop->hide();
  optimize->hide();
}

ResizeCommandWidget *CommandsWidget::getResizeCommandWidget() const {
  return resizeCommandWidget;
}

SpeedCommandWidget *CommandsWidget::getSpeedCommandWidget() const {
  return speedCommandWidget;
}

RotateCommandWidget *CommandsWidget::getRotateCommandWidget() const {
  return rotateCommandWidget;
}

OptimizeCommandWidget *CommandsWidget::getOptimizeCommandWidget() const {
  return optimizeCommandWidget;
}

CropCommandWidget *CommandsWidget::getCropCommandWidget() const {
  return cropCommandWidget;
}
