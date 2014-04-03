/*
 * Thermokarst.h
 *
 *  Created on: Jul 24, 2013
 *      Author: yujin_admin
 */

#ifndef THERMOKARST_H_
#define THERMOKARST_H_

#include "./IOdata.h"
#include "./ProcCht.h"
#include "./LNode.h"

class Thermokarst{

		public:
			Thermokarst();
			~Thermokarst();

			Nodes* Expansion(Nodes* hnode, Nodes* nnode, Nodes* cnode, long &cchtid);
			Nodes* Initiation(Nodes* nnode, Nodes* cnode, long &tchtid);
			Nodes* ChtInitiation(Nodes* nnode, Nodes* cnode, long &cchtid);
			Nodes* AddChtAge(Nodes* nnode);
			Nodes* ChtCombin(Nodes* hnode, Nodes* nnode);

			Nodes* InitiatingFrWS(Nodes* nnode, Nodes* curnode, long &cchtid);
			Nodes* InitiatingFrBS(Nodes* nnode, Nodes* curnode, long &cchtid);
			Nodes* InitiatingFrDeci(Nodes* nnode, Nodes* curnode, long &cchtid);
			Nodes* InitiatingFrTBog(Nodes* nnode, Nodes* curnode, long &cchtid);
			Nodes* InitiatingFrBog(Nodes* nnode, Nodes* curnode, long &cchtid);
			Nodes* InitiatingFrFen(Nodes* nnode, Nodes* curnode, long &cchtid);
			Nodes* InitiatingFrLake(Nodes* nnode, Nodes* curnode, long &cchtid);

			void SetPointer(IOdata* ptr);
			IOdata* iopt;

		private:



};
#endif /* THERMOKARST_H_ */
