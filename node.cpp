#include "node.h"

Node::Node()
{
	myBackgroundColor = Qt::darkGreen;
	myOutlineColor = Qt::darkBlue;
	setFlags(ItemIsMovable | ItemIsSelectable);
}

Node::~Node()
{
	foreach(Link *link, myLinks)
		delete link;
}

void Node::addLink(Link *link)
{

}

void Node::removeLink(Link *link)
{
}
