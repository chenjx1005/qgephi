#ifndef LINK_H
#define LINK_H

#include <QtWidgets\QGraphicsLineItem>
#include <QPen>
#include "node.h"

class Node;

class Link : public QGraphicsLineItem
{
public:
	Link(Node *fromNode, Node *toNode);
	~Link();

	Node *fromNode() const;
	Node *toNode() const;

	void setColor(const QColor &color);
	QColor color() const;

	void trackNodes();

private:
	Node *myFromNode;
	Node *myToNode;
};

#endif // LINK_H
