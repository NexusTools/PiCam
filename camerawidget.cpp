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
    curImage = QPixmap::fromImage(newImg);
    repaint();
}

void CameraWidget::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    if(!curImage.isNull()) {
        QPixmap s = curImage.scaled(size(), Qt::KeepAspectRatio);
        painter.drawPixmap(QPoint(width() / 2 - s.width() / 2, 0), s);
    }
}
