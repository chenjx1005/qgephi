#ifndef QGEPHI_H
#define QGEPHI_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets\QGraphicsScene>
#include <QtWidgets\QGraphicsView>
#include <QtOpenGL\QGLWidget>
#include <QtCore\QTime>
#include "ui_qgephi.h"
#include "node.h"

class QGephi : public QMainWindow
{
	Q_OBJECT
public:
	QGephi(QWidget *parent = 0);
	~QGephi();

	void addNodes();
private:
	typedef QPair<Node *, Node *> NodePair;
	Ui::QGephiClass ui;
	QGraphicsScene *scene;
	//QGraphicsView *view;
};

#endif // QGEPHI_H
