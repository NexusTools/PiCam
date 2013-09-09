#include "cameraworker.h"
#include <QDateTime>
#define DESIRED_FPS 1000/30

CameraWorker::CameraWorker(QObject *parent) :
    QThread(parent)
{
}

void CameraWorker::run() {
    while(PiCam::captureDevice) {
        qint64 start = QDateTime::currentMSecsSinceEpoch();
        IplImage* curFrame = cvQueryFrame(PiCam::captureDevice);
        //qDebug() << "IMG GET" << curFrame << curFrame->width << "x" << curFrame->height << curFrame->colorModel << curFrame->depth;
        if(!curFrame)
            qDebug() << "Null frame.";
        else {
            emit imageFetched(IplImage2QImage(curFrame));
        }
        //qDebug() << "took" << (QDateTime::currentMSecsSinceEpoch() - start) << "ms";
        int sleepTime = (DESIRED_FPS - (QDateTime::currentMSecsSinceEpoch() - start));
        if(sleepTime > 0)
            msleep(sleepTime);
    }
}

//Thanks to: http://josedolz.jimdo.com/computer-vision-tutorials/iplimage-to-qimage/
QImage CameraWorker::IplImage2QImage(const IplImage *iplImage) {
    return QImage((const uchar*)iplImage->imageData, iplImage->width, iplImage->height, QImage::Format_RGB888).rgbSwapped();
}
