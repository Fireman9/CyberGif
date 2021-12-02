#include "CommandsApplier.h"

void CommandsApplier::resizeSlot(int width, int height) {
  QString command = QString("gifsicle --resize %1x%2 --batch .temp/temp.gif")
	  .arg(QString::number(width), QString::number(height));
  system(command.toStdString().c_str());
  emit updateSceneSignal();
}

void CommandsApplier::fitWidthSlot(int width) {
  QString command = QString("gifsicle --resize-width %1 --batch .temp/temp.gif")
	  .arg(QString::number(width));
  system(command.toStdString().c_str());
  emit updateSceneSignal();
}

void CommandsApplier::fitHeightSlot(int height) {
  QString command = QString("gifsicle --resize-height %1 --batch .temp/temp.gif")
	  .arg(QString::number(height));
  system(command.toStdString().c_str());
  emit updateSceneSignal();
}

void CommandsApplier::setSpeedSlot(int speed) {
  QString command = QString("gifsicle --delay %1 --batch .temp/temp.gif")
	  .arg(QString::number(speed));
  system(command.toStdString().c_str());
  emit updateSceneSignal();
}

void CommandsApplier::rotateSlot(int degrees) {
  // Only 90, 180, 270 degrees
  QString command = QString("gifsicle --rotate-%1 --batch .temp/temp.gif")
	  .arg(QString::number(degrees));
  system(command.toStdString().c_str());
  emit updateSceneSignal();
}

void CommandsApplier::cropSlot(int x0, int y0, int width, int height) {
  QString command = QString("gifsicle --crop %1,%2+%3x%4 --batch .temp/temp.gif")
	  .arg(QString::number(x0), QString::number(y0),
		   QString::number(width), QString::number(height));
  system(command.toStdString().c_str());
  emit updateSceneSignal();
}

void CommandsApplier::optimizeSlot() {
  QString command = QString("gifsicle -O3 --batch .temp/temp.gif");
  system(command.toStdString().c_str());
  emit updateSceneSignal();
}
