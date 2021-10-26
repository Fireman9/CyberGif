#ifndef CYBERGIF_COMMANDSWIDGET_H
#define CYBERGIF_COMMANDSWIDGET_H


#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>

class CommandsWidget : public QWidget {
Q_OBJECT

public:
    CommandsWidget(QWidget *parent = nullptr);

private:
    QPushButton *resize;
    QPushButton *speed;
    QPushButton *rotate;
    QPushButton *crop;
    QPushButton *optimize;

    QHBoxLayout *mainLayout;
};


#endif //CYBERGIF_COMMANDSWIDGET_H
