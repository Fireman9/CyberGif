#ifndef CYBERGIF_MAINWIDGET_H
#define CYBERGIF_MAINWIDGET_H


#include <QWidget>

#include "GifScene.h"
#include "CommandsWidget.h"
#include "FileManagement.h"
#include "CommandsApplier.h"

class MainWidget : public QWidget {
Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);

public slots:

    void hideCommands();

    void showCommands();

private:
    QVBoxLayout *mainLayout;

    GifScene *gifScene;
    CommandsWidget *commandsWidget;
    FileManagement *fileManagement;
    CommandsApplier *commandsApplier;
};


#endif //CYBERGIF_MAINWIDGET_H
