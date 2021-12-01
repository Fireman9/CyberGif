#ifndef CYBERGIF_SPEEDCOMMANDWIDGET_HPP
#define CYBERGIF_SPEEDCOMMANDWIDGET_HPP

#include <QWidget>
#include <QPushButton>


QT_BEGIN_NAMESPACE
namespace Ui { class SpeedCommandWidget; }
QT_END_NAMESPACE

class SpeedCommandWidget : public QWidget {
Q_OBJECT

public:
    explicit SpeedCommandWidget(QWidget *parent = nullptr);

    QPushButton *getReturnBackBtn() const;

    ~SpeedCommandWidget() override;

public slots:

    void applySlot();

signals:

    void applySpeedSignal(int frameDelay);

private:
    Ui::SpeedCommandWidget *ui;
};


#endif //CYBERGIF_SPEEDCOMMANDWIDGET_HPP
