#ifndef CAMERAWIDGET_H
#define CAMERAWIDGET_H

#include <QWidget>
#include "picam.h"
#include "cameraworker.h"

class CameraWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CameraWidget(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    QImage curImage;
    void startWorker();
private:
    CameraWorker worker;
public slots:
    void displayImage(QImage);
};

#endif // CAMERAWIDGET_H
