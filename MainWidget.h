#ifndef CYBERGIF_MAINWIDGET_H
#define CYBERGIF_MAINWIDGET_H

#include <QWidget>

#include "GifWidget.h"
#include "Commands/CommandsWidget.h"
#include "FileManagement.h"
#include "CommandsApplier.h"

class MainWidget : public QWidget {
 Q_OBJECT
 public:
  MainWidget(QWidget *parent = nullptr);

 public slots:
  void hideCommandsSlot();

  void showCommandsSlot();

  void resizeToMinimumSlot();

 private:
  QVBoxLayout *mainLayout;

  GifWidget *gifWidget;
  CommandsWidget *commandsWidget;
  FileManagement *fileManagement;
  CommandsApplier *commandsApplier;
};

#endif //CYBERGIF_MAINWIDGET_H
