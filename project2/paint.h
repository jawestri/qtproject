#ifndef PAINT_H
#define PAINT_H

#include <QDialog>
#include <QPainter>
#include <QBoxLayout>
#include <QPushButton>
#include <QColorDialog>
#include <QMouseEvent>

class PaintPage : public QDialog {
    Q_OBJECT
private:
    QColor penColor;
    QPoint startPoint;
    QPushButton *colorBttn;
    QVBoxLayout *paintLayout;

public:
    PaintPage();
    void paintEvent(QPaintEvent *);
private slots:
    void onColorBttnClicked();

};
#endif // PAINT_H
