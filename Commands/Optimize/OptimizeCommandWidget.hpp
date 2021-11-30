#ifndef CYBERGIF_OPTIMIZECOMMANDWIDGET_HPP
#define CYBERGIF_OPTIMIZECOMMANDWIDGET_HPP

#include <QWidget>
#include <QPushButton>


QT_BEGIN_NAMESPACE
namespace Ui { class OptimizeCommandWidget; }
QT_END_NAMESPACE

class OptimizeCommandWidget : public QWidget {
Q_OBJECT

public:
    explicit OptimizeCommandWidget(QWidget *parent = nullptr);

    QPushButton *getReturnBackBtn() const;

    ~OptimizeCommandWidget() override;

public slots:

    void apply();

signals:

    void applyOptimizeSig();

private:
    Ui::OptimizeCommandWidget *ui;
};


#endif //CYBERGIF_OPTIMIZECOMMANDWIDGET_HPP
