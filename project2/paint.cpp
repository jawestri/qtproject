#include "paint.h"

PaintPage::PaintPage()
{



    colorBttn = new QPushButton("Color");
    paintLayout = new QVBoxLayout;
    paintLayout->addWidget(colorBttn);
    paintLayout->addStretch(1);
    setLayout(paintLayout);

    connect( colorBttn, SIGNAL(clicked()), this, SLOT(onColorBttnClicked()));
}

void PaintPage::paintEvent(QPaintEvent *)
{

    QPainter painter(this);
    painter.setPen(Qt::black);
    QPoint p1(10,10);
    QPoint p2(200,200);
    painter.drawLine(p1,p2);



}

void PaintPage::onColorBttnClicked()
{
    QColor newColor = QColorDialog::getColor();
    if (newColor.isValid()){

    }




}
