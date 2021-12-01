#ifndef CYBERGIF_ROTATECOMMANDWIDGET_HPP
#define CYBERGIF_ROTATECOMMANDWIDGET_HPP

#include <QWidget>
#include <QPushButton>


QT_BEGIN_NAMESPACE
namespace Ui { class RotateCommandWidget; }
QT_END_NAMESPACE

class RotateCommandWidget : public QWidget {
Q_OBJECT

public:
    explicit RotateCommandWidget(QWidget *parent = nullptr);

    QPushButton *getReturnBackBtn() const;

    ~RotateCommandWidget() override;

public slots:

    void rotateRightSlot();

    void rotateLeftSlot();

signals:

    void applyRotateSignal(int degrees);

private:
    Ui::RotateCommandWidget *ui;
};


#endif //CYBERGIF_ROTATECOMMANDWIDGET_HPP
