#include "camerawidget.h"
#include <QPainter>
#include <QDebug>

CameraWidget::CameraWidget(QWidget *parent) :
    QWidget(parent) {
}

void CameraWidget::startWorker() {
    connect(&worker, SIGNAL(imageFetched(QImage)), this, SLOT(displayImage(QImage)));
    worker.start();
}

void CameraWidget::displayImage(QImage newImg) {
    curImage = newImg;
    repaint();
}

void CameraWidget::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    if(!curImage.isNull()) {
        painter.drawImage(QPoint(0, 0), curImage);
    }
}
