#ifndef PICAM_H
#define PICAM_H

#include <QMainWindow>

namespace Ui {
class PiCam;
}

class PiCam : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit PiCam(QWidget *parent = 0);
    ~PiCam();
    
private:
    Ui::PiCam *ui;

private slots:
    void start();
    void stop();
};

#endif // PICAM_H
