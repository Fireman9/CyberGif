#include "CommandsApplier.h"

void CommandsApplier::resize(int width, int height) {
    QString command = QString("gifsicle --resize %1x%2 --batch .temp/temp.gif")
            .arg(QString::number(width), QString::number(height));
    system(command.toStdString().c_str());
    emit updateSceneSig();
}

void CommandsApplier::scale(double k) {
    QString command = QString("gifsicle --scale %1 --batch .temp/temp.gif")
            .arg(QString::number(k));
    system(command.toStdString().c_str());
    emit updateSceneSig();
}

void CommandsApplier::setSpeed(int speed) {
    QString command = QString("gifsicle --delay %1 --batch .temp/temp.gif")
            .arg(QString::number(speed));
    system(command.toStdString().c_str());
    emit updateSceneSig();
}

void CommandsApplier::rotate(int degrees) {
    // Only 90, 180, 270 degrees
    QString command = QString("gifsicle --rotate-%1 --batch .temp/temp.gif")
            .arg(QString::number(degrees));
    system(command.toStdString().c_str());
    emit updateSceneSig();
}

void CommandsApplier::crop(int x0, int y0, int width, int height) {
    QString command = QString("gifsicle --crop %1,%2+%3x%4 --batch .temp/temp.gif")
            .arg(QString::number(x0), QString::number(y0),
                 QString::number(width), QString::number(height));
    system(command.toStdString().c_str());
    emit updateSceneSig();
}

void CommandsApplier::optimize() {
    QString command = QString("gifsicle -O3 --batch .temp/temp.gif");
    system(command.toStdString().c_str());
    emit updateSceneSig();
}
