/*
 * main.cpp
 *
 *  Created on: 2015年4月17日
 *      Author: lc4t
 */

#include <iostream>
#include "Node.h"

int main(int argc, char const *argv[])
{
		Node* root = new Node(100);

		Node* child1 = new Node(200);
		Node* child2 = new Node(300);
		Node* child1_1 = new Node(400);
		Node* child1_2 = new Node(500);

		root->Append(child1);
		root->Append(child2);

		child1->Append(child1_1);
		child1->Append(child1_2);

		cout<<root->Count()<<endl;
		cout<<child1->GetValue()<<endl;
		cout<<child1->GetParent()->GetValue()<<endl;
		return 0;
}



