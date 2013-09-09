#include "camerawidget.h"
#include <QPainter>
#include <QDebug>

CameraWidget::CameraWidget(QWidget *parent) :
    QWidget(parent)
{
}

void CameraWidget::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    while(PiCam::captureDevice) {
        IplImage* curFrame = cvQueryFrame(PiCam::captureDevice);
        qDebug() << curFrame << curFrame->width << "x" << curFrame->height << curFrame->colorModel << curFrame->depth;
        if(!curFrame)
            qDebug() << "Null frame.";
        else {
            painter.drawImage(QPoint(0, 0), IplImage2QImage(curFrame));
            cvReleaseImage(&curFrame);
            break; //temporary until threaded.
        }
    }
}

//Thanks to: http://josedolz.jimdo.com/computer-vision-tutorials/iplimage-to-qimage/
QImage CameraWidget::IplImage2QImage(const IplImage *iplImage) {
    return QImage((const uchar*)iplImage->imageData, iplImage->width, iplImage->height, QImage::Format_RGB888).rgbSwapped();
}
