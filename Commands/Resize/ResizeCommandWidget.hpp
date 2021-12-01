#ifndef CYBERGIF_RESIZECOMMANDWIDGET_HPP
#define CYBERGIF_RESIZECOMMANDWIDGET_HPP

#include <QWidget>
#include <QVBoxLayout>
#include <QSpinBox>
#include <QCheckBox>
#include <QPushButton>
#include <QLabel>


QT_BEGIN_NAMESPACE
namespace Ui { class ResizeCommandWidget; }
QT_END_NAMESPACE

class ResizeCommandWidget : public QWidget {
Q_OBJECT

public:
    explicit ResizeCommandWidget(QWidget *parent = nullptr);

    QPushButton *getReturnBackBtn() const;

    ~ResizeCommandWidget() override;

public slots:

    void applySlot();

    void muteWidthSlot();

    void muteHeightSlot();

signals:

    void applyResizeSignal(int width, int height);

    void applyFitWidthSignal(int width);

    void applyFitHeightSignal(int height);

private:
    Ui::ResizeCommandWidget *ui;
};


#endif //CYBERGIF_RESIZECOMMANDWIDGET_HPP
