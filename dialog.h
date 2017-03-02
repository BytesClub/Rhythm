#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMediaPlayer>
#include <QFileDialog>
#include <QDebug>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_sliderVolume_sliderMoved(int position);

    void on_sliderProgress_sliderMoved(int position);

    void on_startButton_clicked();

    void on_stopButton_clicked();

    void on_positionChanged(qint64 position);

    void on_durationChanged(qint64 position);

    void on_browseButton_clicked();

private:
    Ui::Dialog *ui;
    QMediaPlayer* player;
    QString songName;
};

#endif // DIALOG_H
