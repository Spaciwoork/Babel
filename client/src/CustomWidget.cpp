/*
**EPITECH PROJECT, 2018
**CPP_babel_2021
**File description:
**Created by Augustin Lopacinski
*/

#include "../include/CustomWidget.hpp"

CustomWidget::CustomWidget(QWidget *parent) : QWidget(parent)

{
}

void CustomWidget::paintEvent(QPaintEvent *event)
{
	QPainter p(this);
	p.setPen(Qt::black);
	p.setBrush(QColor(90, 90, 90, 80));
	p.drawRect(QRect(0, 100, 300, 700));
}


CustomWidget::~CustomWidget()
{
}