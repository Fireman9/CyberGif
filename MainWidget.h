#ifndef CYBERGIF_MAINWIDGET_H
#define CYBERGIF_MAINWIDGET_H


#include <QWidget>

#include "GifScene.h"
#include "CommandsWidget.h"

class MainWidget : public QWidget {
Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);

private:
    QVBoxLayout *mainLayout;

    GifScene *gifScene;
    CommandsWidget *commandsWidget;
};


#endif //CYBERGIF_MAINWIDGET_H
