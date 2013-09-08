#include "picam.h"
#include "ui_picam.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
CvCapture *PiCam::captureDevice = 0;
PiCam::PiCam(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PiCam)
{
    ui->setupUi(this);
    connect(ui->actionToggle, SIGNAL(triggered()), this, SLOT(start()));
}

void PiCam::start() {
    disconnect(ui->actionToggle, SIGNAL(triggered()), this, SLOT(start()));
    bool success = false;
    captureDevice = cvCreateCameraCapture(0);

    if(success) {
        connect(ui->actionToggle, SIGNAL(triggered()), this, SLOT(stop()));
        ui->actionToggle->setText("Stop");
    } else {
        connect(ui->actionToggle, SIGNAL(triggered()), this, SLOT(start()));
    }
}

void PiCam::stop() {
    disconnect(ui->actionToggle, SIGNAL(triggered()), this, SLOT(stop()));
    cvReleaseCapture(&captureDevice);
    captureDevice = 0;
    connect(ui->actionToggle, SIGNAL(triggered()), this, SLOT(start()));
    ui->actionToggle->setText("Start");
}


PiCam::~PiCam()
{
    delete ui;
}
