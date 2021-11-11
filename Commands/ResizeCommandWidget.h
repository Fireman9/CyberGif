#ifndef CYBERGIF_RESIZECOMMANDWIDGET_H
#define CYBERGIF_RESIZECOMMANDWIDGET_H


#include <QWidget>
#include <QVBoxLayout>
#include <QSpinBox>
#include <QCheckBox>
#include <QPushButton>
#include <QLabel>

class ResizeCommandWidget : public QWidget {
Q_OBJECT

public:
    ResizeCommandWidget(QWidget *parent = nullptr);

    QPushButton *getReturnBackBtn() const;

public slots:

    void applyResize();

signals:

    void applyResizeSig(int width, int height);

private:
    QLabel *widthLbl;
    QLabel *heightLbl;
    QSpinBox *widthInput;
    QSpinBox *heightInput;
    QCheckBox *keepAspectRatio;
    QPushButton *returnBackBtn;
    QPushButton *applyBtn;

    QVBoxLayout *mainLayout;
    QHBoxLayout *topLayout;
    QHBoxLayout *bottomLayout;
    QVBoxLayout *whLayout;
    QHBoxLayout *widthLayout;
    QHBoxLayout *heightLayout;
    QVBoxLayout *aspectRatioLayout;
};


#endif //CYBERGIF_RESIZECOMMANDWIDGET_H
