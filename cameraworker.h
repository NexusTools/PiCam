#ifndef CAMERAWORKER_H
#define CAMERAWORKER_H

#include <QThread>
#include "picam.h"

class CameraWorker : public QThread
{
    Q_OBJECT
public:
    explicit CameraWorker(QObject *parent = 0);
    void run();
    static QImage IplImage2QImage(const IplImage *);
signals:
    void imageFetched(QImage);
};

#endif // CAMERAWORKER_H
