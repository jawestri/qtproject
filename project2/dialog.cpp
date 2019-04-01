#include "dialog.h"


Dialog::Dialog(QWidget *parent) :
    QDialog(parent)
{
    //resize(500,500);

    homeBttn = new QPushButton("Home");
    audioBttn = new QPushButton("Audio");
    notesBttn = new QPushButton("Notes");
    paintBttn = new QPushButton("Paint");


    homePage = new HomePage;
    audioPage = new AudioPage;
    notesPage = new NotesPage;
    paintPage = new PaintPage;

    myStackedLayout = new QStackedLayout;
    buttonLayout = new QHBoxLayout;
    mainLayout = new QVBoxLayout;

    buttonLayout->addWidget(homeBttn);
    buttonLayout->addWidget(audioBttn);
    buttonLayout->addWidget(notesBttn);
    buttonLayout->addWidget(paintBttn);


    myStackedLayout->addWidget(homePage);
    myStackedLayout->addWidget(audioPage);
    myStackedLayout->addWidget(notesPage);
    myStackedLayout->addWidget(paintPage);

    mainLayout->addLayout(myStackedLayout);
    mainLayout->addLayout(buttonLayout);

    setLayout(mainLayout);

    connect( homeBttn,SIGNAL( clicked() ),this, SLOT( onHomeBttnClicked()) );
    connect( audioBttn,SIGNAL( clicked() ),this, SLOT( onAudioBttnClicked()) );
    connect( notesBttn,SIGNAL( clicked() ),this, SLOT( onNotesBttnClicked()) );
    connect( paintBttn,SIGNAL( clicked() ),this, SLOT( onPaintBttnClicked()) );
}

Dialog::~Dialog()
{

}

void Dialog::onHomeBttnClicked()
{
    myStackedLayout->setCurrentIndex(0);
}

void Dialog::onAudioBttnClicked()
{
    myStackedLayout->setCurrentIndex(1);
}

void Dialog::onNotesBttnClicked()
{
    myStackedLayout->setCurrentIndex(2);
}

void Dialog::onPaintBttnClicked()
{
    myStackedLayout->setCurrentIndex(3);
}
