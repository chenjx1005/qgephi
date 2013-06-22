#ifndef NODE_H
#define NODE_H

#include <QtWidgets\QGraphicsitem>
#include <QtWidgets\QApplication>
#include <QtCore\QRectF>
#include <QtCore\qvariant.h>
#include <QtCore\QSet>
#include <QtGui\QPainterPath>
class Link;

class Node : public QGraphicsItem
{
	Q_DECLARE_TR_FUNCTIONS(Node)

public:
	Node();
	~Node();

	void setOutlineColor(const QColor &color);
	QColor outlineColor() const;
	void setBackgroundColor(const QColor &color);
	QColor backgroundColor() const;

	void addLink(Link *link);
	void removeLink(Link *link);

	QRectF boundingRect() const;
	QPainterPath shape() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
protected:
	QVariant itemChange(GraphicsItemChange change, cosnt QVariant &value);
private:
	QRectF outlineRect() const;
	QSet<Link *> myLinks;
	QColor myBackgroundColor;
	QColor myOutlineColor;
};

#endif // NODE_H
