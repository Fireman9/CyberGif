#ifndef CYBERGIF_COMMANDSWIDGET_H
#define CYBERGIF_COMMANDSWIDGET_H


#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>

#include "Commands/ResizeCommandWidget.h"

class CommandsWidget : public QWidget {
Q_OBJECT

public:
    CommandsWidget(QWidget *parent = nullptr);

    ResizeCommandWidget *getResizeCommandWidget() const;

public slots:

    void changeToCommandsWidget();

    void changeToResizeWidget();

private:
    QPushButton *resize;
    QPushButton *speed;
    QPushButton *rotate;
    QPushButton *crop;
    QPushButton *optimize;

    QHBoxLayout *mainLayout;

    ResizeCommandWidget *resizeCommandWidget;
};


#endif //CYBERGIF_COMMANDSWIDGET_H
