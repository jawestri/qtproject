#include "notes.h"

NotesPage::NotesPage()
{
    text = new QTextEdit;
    saveBttn = new QPushButton("Save");
    clearBttn = new QPushButton("Clear");
    bttnLayout = new QHBoxLayout;
    bttnLayout->addWidget(saveBttn);
    bttnLayout->addWidget(clearBttn);

    notesLayout = new QVBoxLayout;
    notesLayout->addLayout(bttnLayout);
    notesLayout->addWidget(text);
    setLayout(notesLayout);

    connect(saveBttn, SIGNAL(clicked()), this, SLOT(onSaveButtonClicked()));
    connect(clearBttn, SIGNAL(clicked()), this, SLOT(onClearButtonClicked()));
}

void NotesPage::onSaveButtonClicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),"",tr("Text (*.txt)"));

    QFile sFile(fileName);
        if(sFile.open(QFile::WriteOnly |  QFile::Text))
        {
            QTextStream out(&sFile);
            out << text->toPlainText();
            sFile.flush();
            sFile.close();
        }
}

void NotesPage::onClearButtonClicked()
{
    text->clear();
}
