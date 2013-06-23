#include "qgephi.h"

QGephi::QGephi(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	scene = new QGraphicsScene;
	ui.graphicsView->setViewport(new QGLWidget(QGLFormat(QGL::SampleBuffers)));
	//ui.graphicsView->setViewport(new QGLWidget);
	ui.graphicsView->setScene(scene);
	//......
	addNodes();
}

QGephi::~QGephi()
{
	delete scene;
}

void QGephi::addNodes()
{
	QTime t;
	Node *start = new Node;
	start->setPos(10,10);
	scene->addItem(start);
	for(int i = 0 ; i < 500 ; i++)
	{
		t = QTime::currentTime();
		qsrand(t.msec() + t.second()*1000);
		int n1 = qrand()%460 + 20;
		t = QTime::currentTime();
		qsrand(t.msec() + t.second()*1000);
		int n2 = qrand()%460 + 20;
		Node *node = new Node;
		node->setPos(n1,n2);
		scene->addItem(node);
		scene->addItem(new Link(start,node));
	}
}

