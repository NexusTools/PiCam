#ifndef CAMERAWIDGET_H
#define CAMERAWIDGET_H

#include <QWidget>
#include <QThread>
#include "picam.h"

class CameraWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CameraWidget(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    static QImage IplImage2QImage(const IplImage *);
};

#endif // CAMERAWIDGET_H
