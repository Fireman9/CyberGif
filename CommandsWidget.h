#ifndef CYBERGIF_COMMANDSWIDGET_H
#define CYBERGIF_COMMANDSWIDGET_H


#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>

#include "Commands/Resize/ResizeCommandWidget.h"
#include "Commands/Speed/SpeedCommandWidget.hpp"
#include "Commands/Rotate/RotateCommandWidget.hpp"

class CommandsWidget : public QWidget {
Q_OBJECT

public:
    CommandsWidget(QWidget *parent = nullptr);

    ResizeCommandWidget *getResizeCommandWidget() const;

    SpeedCommandWidget *getSpeedCommandWidget() const;

    RotateCommandWidget *getRotateCommandWidget() const;

public slots:

    void changeToCommandsWidget();

    void changeToResizeWidget();

    void changeToSpeedWidget();

    void changeToRotateWidget();

private:
    QPushButton *resize;
    QPushButton *speed;
    QPushButton *rotate;
    QPushButton *crop;
    QPushButton *optimize;

    QHBoxLayout *mainLayout;

    ResizeCommandWidget *resizeCommandWidget;
    SpeedCommandWidget *speedCommandWidget;
    RotateCommandWidget *rotateCommandWidget;

    void hideCommands();
};


#endif //CYBERGIF_COMMANDSWIDGET_H
