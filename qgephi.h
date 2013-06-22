#ifndef QGEPHI_H
#define QGEPHI_H

#include <QtWidgets/QMainWindow>
#include "ui_qgephi.h"

class QGephi : public QMainWindow
{
	Q_OBJECT
public:
	QGephi(QWidget *parent = 0);
	~QGephi();

private:
	Ui::QGephiClass ui;
};

#endif // QGEPHI_H
