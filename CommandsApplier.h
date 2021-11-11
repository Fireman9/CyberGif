#ifndef CYBERGIF_COMMANDSAPPLIER_H
#define CYBERGIF_COMMANDSAPPLIER_H

#include <QObject>
#include <QString>

class CommandsApplier : public QObject {
Q_OBJECT
public slots:

    void resize(int width, int height);

    void fitWidth(int width);

    void fitHeight(int height);

    void setSpeed(int speed);

    void rotate(int degrees);

    void crop(int x0, int y0, int width, int height);

    void optimize();

signals:

    void updateSceneSig();
};


#endif //CYBERGIF_COMMANDSAPPLIER_H
