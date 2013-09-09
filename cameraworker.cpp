#include "cameraworker.h"

CameraWorker::CameraWorker(QObject *parent) :
    QThread(parent)
{
}

void CameraWorker::run() {
    while(PiCam::captureDevice) {
        IplImage* curFrame = cvQueryFrame(PiCam::captureDevice);
        qDebug() << "IMG GET" << curFrame << curFrame->width << "x" << curFrame->height << curFrame->colorModel << curFrame->depth;
        if(!curFrame)
            qDebug() << "Null frame.";
        else {
            emit imageFetched(IplImage2QImage(curFrame));
            //cvReleaseImage(&curFrame);
        }
    }
}

//Thanks to: http://josedolz.jimdo.com/computer-vision-tutorials/iplimage-to-qimage/
QImage CameraWorker::IplImage2QImage(const IplImage *iplImage) {
    return QImage((const uchar*)iplImage->imageData, iplImage->width, iplImage->height, QImage::Format_RGB888).rgbSwapped();
}
