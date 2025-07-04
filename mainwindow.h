#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private slots:
    void on_startButton_clicked();

    void on_stopButton_clicked();

    void updatePlot();

    void on_resetButton_clicked();



private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QVector<double> x, sineData,cosData;
    double t;


};
#endif // MAINWINDOW_H
