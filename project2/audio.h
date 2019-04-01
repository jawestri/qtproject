#ifndef AUDIO_H
#define AUDIO_H

#include <QDialog>
#include <QObject>
#include <QPushButton>
#include <QBoxLayout>
#include <QMediaPlayer>
#include <QSlider>
#include <QDialog>
#include <QLabel>
#include <QFileDialog>

/**Plays audio files from computer
  -Can adjust volume and playback position **/

class AudioPage : public QDialog {
     Q_OBJECT
private:
    QVBoxLayout *bttnLayout;
    QGridLayout *sliderLayout;
    QHBoxLayout *audioLayout;
    QPushButton *fileBttn, *playBttn, *pauseBttn, *stopBttn;
    QSlider *volumeSlider, *progressSlider;
    QMediaPlayer *player;
    QLabel *volLabel, *progLabel;


public:
    AudioPage();

private slots:
    void onFileBttnClicked();
    void onPlayBttnClicked();
    void onPauseBttnClicked();
    void onStopBttnClicked();
    void onDurationChanged(qint64);
    void onVolumeChanged(int);
    void onProgressChanged(int);
    void onPositionChanged(qint64);

};
#endif // AUDIO_H
