#ifndef CYBERGIF_COMMANDSWIDGET_H
#define CYBERGIF_COMMANDSWIDGET_H


#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>

#include "Commands/Resize/ResizeCommandWidget.h"
#include "Commands/Speed/SpeedCommandWidget.hpp"

class CommandsWidget : public QWidget {
Q_OBJECT

public:
    CommandsWidget(QWidget *parent = nullptr);

    ResizeCommandWidget *getResizeCommandWidget() const;

    SpeedCommandWidget *getSpeedCommandWidget() const;

public slots:

    void changeToCommandsWidget();

    void changeToResizeWidget();

    void changeToSpeedWidget();

private:
    QPushButton *resize;
    QPushButton *speed;
    QPushButton *rotate;
    QPushButton *crop;
    QPushButton *optimize;

    QHBoxLayout *mainLayout;

    ResizeCommandWidget *resizeCommandWidget;
    SpeedCommandWidget *speedCommandWidget;

    void hideCommands();
};


#endif //CYBERGIF_COMMANDSWIDGET_H
