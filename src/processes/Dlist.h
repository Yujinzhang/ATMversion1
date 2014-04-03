/*
 * Dlist.h
 *
 *  Created on: Jul 28, 2013
 *      Author: yujin_admin
 */

#ifndef DLIST_H_
#define DLIST_H_

#include "./IOdata.h"
#include "./LNode.h"

#include <cstring>


class Dlist{

	public:
		Dlist();
		~Dlist();

		Nodes* InsertDode(Nodes* pPre, IOdata* ioptr);
		Nodes* DeleteDode(Nodes* nptr);
		Nodes* SearchNode(Nodes* nptr);
		Nodes* DeleteList(Nodes* list);

	private:

		IOdata* ioptr;
		IOdata* ptr;
		//Nodes* pPreNode;

		int nCount;

};


#endif /* DLIST_H_ */
