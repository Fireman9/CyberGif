#ifndef CYBERGIF_COMMANDSAPPLIER_H
#define CYBERGIF_COMMANDSAPPLIER_H

#include <QObject>
#include <QString>

class CommandsApplier : public QObject {
Q_OBJECT
public slots:

    void resizeSlot(int width, int height);

    void fitWidthSlot(int width);

    void fitHeightSlot(int height);

    void setSpeedSlot(int speed);

    void rotateSlot(int degrees);

    void cropSlot(int x0, int y0, int width, int height);

    void optimizeSlot();

signals:

    void updateSceneSignal();
};


#endif //CYBERGIF_COMMANDSAPPLIER_H
