#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QStackedLayout>
#include <QPushButton>

#include "audio.h"
#include "home.h"
#include "notes.h"
#include "paint.h"

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();
private:
    QStackedLayout *myStackedLayout;
    QVBoxLayout *mainLayout;
    QHBoxLayout *buttonLayout;
    QPushButton *homeBttn,*audioBttn,*notesBttn,*paintBttn;
    HomePage *homePage;
    AudioPage *audioPage;
    NotesPage *notesPage;
    PaintPage *paintPage;


private slots:
    void onHomeBttnClicked();
    void onAudioBttnClicked();
    void onNotesBttnClicked();
    void onPaintBttnClicked();


};

#endif // DIALOG_H
