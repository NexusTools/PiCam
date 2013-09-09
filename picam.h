#ifndef PICAM_H
#define PICAM_H

#include <QMainWindow>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

namespace Ui {
class PiCam;
}

class PiCam : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit PiCam(QWidget *parent = 0);
    ~PiCam();
    static CvCapture *captureDevice;
    
private:
    Ui::PiCam *ui;

private slots:
    void start();
    void stop();
};

#endif // PICAM_H
