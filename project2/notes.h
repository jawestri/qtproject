#ifndef NOTES_H
#define NOTES_H

#include <QObject>
#include <QDialog>
#include <QTextEdit>
#include <QBoxLayout>
#include <QFileDialog>
#include <QTextStream>
#include <QPushButton>

/**Notepad with option to save as **/

class NotesPage : public QDialog {
     Q_OBJECT
private:
   QVBoxLayout *notesLayout;
   QHBoxLayout *bttnLayout;
   QTextEdit *text;
   QPushButton *saveBttn, *clearBttn;
   QString fileName;

public:
    NotesPage();
private slots:
    void onSaveButtonClicked();
    void onClearButtonClicked();

};
#endif // NOTES_H
