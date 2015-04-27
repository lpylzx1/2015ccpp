/*
 * Node.h
 *
 *  Created on: 2015年4月27日
 *      Author: lc4t
 */

#ifndef NODE_H_
#define NODE_H_

#include "Node.h"
#include <vector>
using namespace std;
class Node
{
	public:
		Node();
		Node(int idata);
		void Append(Node* child);
		int Count();
		~Node();
		int GetValue();
		Node* GetParent();
	private:
		int data;
		vector<Node*> children;
		Node * parent;

};

#endif /* NODE_H_ */
