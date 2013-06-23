#include "node.h"

Node::Node()
{
	myBackgroundColor = Qt::darkGreen;
	myOutlineColor = Qt::darkBlue;
	setFlags(ItemIsMovable | ItemIsSelectable | ItemSendsGeometryChanges);
}

Node::~Node()
{
	foreach(Link *link, myLinks)
		delete link;
}

void Node::addLink(Link *link)
{
	myLinks.insert(link);	
}

void Node::removeLink(Link *link)
{
	myLinks.remove(link);
}

QRectF Node::boundingRect() const
{
	const int Margin = 1;
	return outlineRect().adjusted(-Margin,-Margin,Margin,Margin);
}

QRectF Node::outlineRect() const
{
	return QRectF(-8,-8,16,16);
}

void Node::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
{
	QPen pen(myOutlineColor);
	if(option->state & QStyle::State_Selected)
	{
		pen.setStyle(Qt::DotLine);
		pen.setWidth(2);
	}
	painter->setPen(pen);
	painter->setBrush(myBackgroundColor);
	painter->drawRect(outlineRect());
}

QVariant Node::itemChange(GraphicsItemChange change, const QVariant &value)
{
	if(change == ItemPositionHasChanged)
	{
		foreach(Link *link, myLinks)
			link->trackNodes();
	}
	return QGraphicsItem::itemChange(change,value);
}

void Node::setOutlineColor(const QColor &color)
{
	myOutlineColor = color;
}

void Node::setBackgroundColor(const QColor &color)
{
	myBackgroundColor = color;
}

QColor Node::outlineColor() const
{
	return myOutlineColor;
}

QColor Node::backgroundColor() const
{
	return myBackgroundColor;
}
