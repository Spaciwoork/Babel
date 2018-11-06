/*
**EPITECH PROJECT, 2018
**CPP_babel_2021
**File description:
**Created by Augustin Lopacinski
*/

#include <QtWidgets/QWidget>
#include <QPainter>

#ifndef CPP_BABEL_2021_CUSTOMWIDGET_HPP
#define CPP_BABEL_2021_CUSTOMWIDGET_HPP

class CustomWidget : public QWidget
{
	Q_OBJECT

	public:
	explicit CustomWidget(QWidget *parent = nullptr);
	~CustomWidget();

	protected:
	void paintEvent(QPaintEvent* event);

};

#endif //CPP_BABEL_2021_CUSTOMWIDGET_HPP
