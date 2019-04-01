#include "audio.h"

AudioPage::AudioPage()
{

    player = new QMediaPlayer;

    /**create buttons **/
    playBttn = new QPushButton("Play");
    fileBttn = new QPushButton("Select File");
    stopBttn = new QPushButton("Stop");
    pauseBttn = new QPushButton("Pause");
    bttnLayout = new QVBoxLayout;
   // bttnLayout->addStretch(1);
    bttnLayout->addWidget(fileBttn);
    bttnLayout->addWidget(playBttn);
    bttnLayout->addWidget(pauseBttn);
    bttnLayout->addWidget(stopBttn);

    /**create sliders **/
    progressSlider = new QSlider(Qt::Horizontal);
    volumeSlider = new QSlider(Qt::Horizontal);
    volLabel = new QLabel("Volume");
    progLabel = new QLabel("Progress");
    sliderLayout = new QGridLayout;
    sliderLayout->addWidget(progLabel,0,0);
    sliderLayout->addWidget(progressSlider,0,1);
    sliderLayout->addWidget(volLabel,1,0);
    sliderLayout->addWidget(volumeSlider,1,1);

    /**Create main layout  **/
    audioLayout = new QHBoxLayout;
    audioLayout->addLayout(bttnLayout);
    audioLayout->addLayout(sliderLayout);
    volumeSlider->setValue(75);
    setLayout(audioLayout);

    /**Set connections **/
    connect ( playBttn, SIGNAL ( clicked() ),this, SLOT ( onPlayBttnClicked() ));
    connect ( stopBttn, SIGNAL ( clicked() ),this, SLOT ( onStopBttnClicked() ));
    connect ( pauseBttn, SIGNAL ( clicked() ),this, SLOT ( onPauseBttnClicked() ));
    connect ( fileBttn, SIGNAL ( clicked() ),this, SLOT ( onFileBttnClicked() ));
    connect ( volumeSlider, SIGNAL ( valueChanged(int) ),this,SLOT ( onVolumeChanged(int)));
    connect ( progressSlider, SIGNAL ( sliderMoved(int) ),this, SLOT ( onProgressChanged(int)));
    connect ( player, SIGNAL ( positionChanged(qint64) ), this, SLOT ( onPositionChanged(qint64)) );
    connect ( player, SIGNAL ( durationChanged(qint64) ), this,SLOT ( onDurationChanged(qint64) ));


}
/**selection audio file **/
void AudioPage::onFileBttnClicked()
{

    QString filename = QFileDialog::getOpenFileName(this,"Open a File","","Audio File (*.*)");
    player->setMedia(QUrl::fromLocalFile(filename));

}

/* play audio **/
void AudioPage::onPlayBttnClicked()
{
    player->play();
}

/**pause audio **/
void AudioPage::onPauseBttnClicked()
{
    player->pause();
}

/**stop audio **/
void AudioPage::onStopBttnClicked()
{
    player->stop();
}

/**set progress bar to match audio duration **/
void AudioPage::onDurationChanged(qint64 duration)
{
    progressSlider->setMaximum(duration);
}

/**update volume when user slides volume bar **/
void AudioPage::onVolumeChanged(int vol)
{
    player->setVolume(vol);
}

/**update playback position when user slides bar **/
void AudioPage::onProgressChanged(int prog)
{
    player->setPosition(prog);
}

/**update progress slider to represent playback position **/
void AudioPage::onPositionChanged(qint64 pos)
{
    progressSlider->setValue(pos);
}
