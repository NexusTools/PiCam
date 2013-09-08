#include "picam.h"
#include "ui_picam.h"
#include <QMessageBox>
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
    bool success = true;
    captureDevice = cvCreateCameraCapture(-1);
    if(captureDevice == 0) {
        success = false;
        QMessageBox errMsg;
        errMsg.setInformativeText("Error");
        errMsg.setText("There's been an error while initaiting the camera device."); //TODO: Non-vague message?
        errMsg.setStandardButtons(QMessageBox::Ok);
        errMsg.exec();
    }
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
