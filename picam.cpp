#include "picam.h"
#include "ui_picam.h"

PiCam::PiCam(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PiCam)
{
    ui->setupUi(this);
    connect(ui->actionStart, SIGNAL(triggered()), this, SLOT(toggleCam()));
}

void PiCam::toggleCam() {

}

PiCam::~PiCam()
{
    delete ui;
}
