#include "picam.h"
#include "ui_picam.h"

PiCam::PiCam(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PiCam)
{
    ui->setupUi(this);
    connect(ui->actionStart, SIGNAL(triggered()), this, SLOT(start()));
}

void PiCam::start() {
    disconnect(ui->actionStart, SIGNAL(triggered()), this, SLOT(start()));
    connect(ui->actionStart, SIGNAL(triggered()), this, SLOT(stop()));
    ui->actionStart->setText("Stop");
}

void PiCam::stop() {
    disconnect(ui->actionStart, SIGNAL(triggered()), this, SLOT(stop()));
    connect(ui->actionStart, SIGNAL(triggered()), this, SLOT(start()));
    ui->actionStart->setText("Start");
}


PiCam::~PiCam()
{
    delete ui;
}
