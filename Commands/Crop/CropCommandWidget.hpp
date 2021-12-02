#ifndef CYBERGIF_CROPCOMMANDWIDGET_HPP
#define CYBERGIF_CROPCOMMANDWIDGET_HPP

#include <QWidget>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class CropCommandWidget; }
QT_END_NAMESPACE

class CropCommandWidget : public QWidget {
 Q_OBJECT
 public:
  explicit CropCommandWidget(QWidget *parent = nullptr);

  QPushButton *getReturnBackBtn() const;

  ~CropCommandWidget() override;

 public slots:
  void applySlot();

 signals:
  void applyCropSignal(int x0, int y0, int width, int height);

 private:
  Ui::CropCommandWidget *ui;

};

#endif //CYBERGIF_CROPCOMMANDWIDGET_HPP
