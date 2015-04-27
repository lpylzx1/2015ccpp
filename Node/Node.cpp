/*
 * Node.cpp
 *
 *  Created on: 2015年4月27日
 *      Author: lc4t
 */

#include "Node.h"

#include "Node.h"
#include <vector>
using namespace std;
Node::Node() {}

Node::Node(int idata) {
	// TODO Auto-generated constructor stub
	data = idata;

}

void Node::Append(Node* child)
{
	children.push_back(child);
	child->parent = this;
}

int Node::Count()
{
	int cnt = 1;

	for (vector<Node*>::iterator i = children.begin();i != children.end(); i++)
	{
		cnt += (*i)->Count();
	}
	return cnt;
}

Node::~Node()
{
	// TODO Auto-generated destructor stub
}

int Node::GetValue()
{
	return data;
}

Node* Node::GetParent()
{
	return this->parent;
}


