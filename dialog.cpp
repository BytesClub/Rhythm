#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    player = new QMediaPlayer(this);

    connect(player, &QMediaPlayer::positionChanged, this, &Dialog::on_positionChanged);
    connect(player, &QMediaPlayer::durationChanged, this, &Dialog::on_durationChanged);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_sliderVolume_sliderMoved(int position)
{
    player->setVolume(position);
}

void Dialog::on_sliderProgress_sliderMoved(int position)
{
    player->setPosition(position);
}

void Dialog::on_startButton_clicked()
{
    // load the file
    if(songName != "") {
        qDebug() << "Playing: "<<songName;
        player->setMedia(QUrl::fromLocalFile(songName));
        player->play();
    }

    qDebug() << "Error: "<<player->errorString();
}

void Dialog::on_stopButton_clicked()
{
    player->stop();
}

void Dialog::on_positionChanged(qint64 position)
{
    ui->sliderProgress->setValue(position);
}

void Dialog::on_durationChanged(qint64 position)
{
    ui->sliderProgress->setMaximum(position);
}

void Dialog::on_browseButton_clicked()
{
    songName = QFileDialog::getOpenFileName(this, "Open a file...", "Audio File (mp3)");
}
