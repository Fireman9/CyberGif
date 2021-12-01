#ifndef CYBERGIF_COMMANDSWIDGET_H
#define CYBERGIF_COMMANDSWIDGET_H


#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>

#include "Resize/ResizeCommandWidget.hpp"
#include "Speed/SpeedCommandWidget.hpp"
#include "Rotate/RotateCommandWidget.hpp"
#include "Crop/CropCommandWidget.hpp"
#include "Optimize/OptimizeCommandWidget.hpp"

class CommandsWidget : public QWidget {
Q_OBJECT

public:
    CommandsWidget(QWidget *parent = nullptr);

    ResizeCommandWidget *getResizeCommandWidget() const;

    SpeedCommandWidget *getSpeedCommandWidget() const;

    RotateCommandWidget *getRotateCommandWidget() const;

    OptimizeCommandWidget *getOptimizeCommandWidget() const;

    CropCommandWidget *getCropCommandWidget() const;

public slots:

    void toCommandsWidgetSlot();

    void toResizeWidgetSlot();

    void toSpeedWidgetSlot();

    void toRotateWidgetSlot();

    void toOptimizeWidgetSlot();

    void toCropWidgetSlot();

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
    OptimizeCommandWidget *optimizeCommandWidget;
    CropCommandWidget *cropCommandWidget;

    void hideCommands();
};


#endif //CYBERGIF_COMMANDSWIDGET_H
