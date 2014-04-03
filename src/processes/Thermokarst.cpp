/*
 * Thermo.cpp
 *
 *  Created on: Jul 24, 2013
 *      Author: yujin_admin
 */

#include "./Thermokarst.h"

Thermokarst::Thermokarst(){

};

Thermokarst::~Thermokarst(){

};

Nodes* Thermokarst::Expansion(Nodes* hnode, Nodes* nnode, Nodes* cnode, long &cchtid){

		return hnode;
};


Nodes* Thermokarst::Initiation(Nodes* nnode, Nodes* cnode, long &tchtid){

		Nodes* plist;
		plist = cnode;

		Nodes* newchtlist = new Nodes;
		newchtlist = NULL;		//define the first list node


		if (plist->vegtype == 3 || plist->vegtype == 4 || plist->vegtype == 5
				|| plist->vegtype == 1 || plist->vegtype == 2 || plist->vegtype == 9 || plist->vegtype == 10){

				newchtlist = ChtInitiation(newchtlist, plist, tchtid);


			}

		return newchtlist;

};

Nodes* Thermokarst::ChtInitiation( Nodes* nnode, Nodes* cnode, long &tchtid){


		if(cnode->vegtype == 3){

			nnode = InitiatingFrWS(nnode, cnode, tchtid);

		}else if(cnode->vegtype == 4){

			nnode = InitiatingFrBS(nnode, cnode, tchtid);

		}else if(cnode->vegtype == 5){

			nnode = InitiatingFrDeci(nnode, cnode, tchtid);

		}else if(cnode->vegtype == 10){

			nnode = InitiatingFrTBog(nnode, cnode, tchtid);

		}else if(cnode->vegtype == 1){

			nnode = InitiatingFrBog(nnode, cnode, tchtid);

		}else if(cnode->vegtype == 2){

			nnode = InitiatingFrFen(nnode, cnode, tchtid);

		}else if(cnode->vegtype == 9){

			nnode = InitiatingFrLake(nnode, cnode, tchtid);

		}else{

			cout<<endl<<"no Initiation/Expansion"<<endl;
		}

		return nnode;

};


Nodes* Thermokarst::AddChtAge(Nodes* nnode){

	//After a year, add 1 to all old and new cohorts ages
	Nodes* plist = nnode;

	while (plist != NULL ){

			plist->age += 1;

			plist = plist->pNext;

	}

	return nnode;

};

Nodes* Thermokarst::ChtCombin(Nodes* hnode, Nodes* nnode){

	////combine the newchtlist to the current chtlist
	Nodes* nlist = new Nodes;
	Nodes* nodeEnd = new Nodes;
	nlist = hnode;

	while(nlist != NULL){
		nodeEnd = nlist;	//the pointer of last node
		nlist = nlist->pNext;	//point to next node
	}

	nodeEnd->pNext = nnode;		//nodeEnd is the pointer of the end node of the list
	return hnode;

};


Nodes* Thermokarst::InitiatingFrWS(Nodes* nnode, Nodes* curnode, long &cchtid){

	//cout<<endl<<"initi WS 33333"<<endl;

	cchtid += 1;	//add 1 to previous cchtid
	Nodes* pNode1 = new Nodes;     //using type 3: generate a cohort for new bog;
	pNode1->pNext = NULL;

	pNode1->year = curnode->year;
	pNode1->grdID = curnode->grdID;
	pNode1->parentid = curnode->cohortid;
	pNode1->cohortid = cchtid;
	pNode1->vegtype = 9;
	pNode1->age = 0;
	pNode1->generation = curnode->generation + 1;

	pNode1->proportion = curnode->proportion*1;
	pNode1->proportion = curnode->proportion/100;

	pNode1->flag = 2;


	pNode1->pNext = nnode;

	nnode = pNode1;	//nnode is the new cohort list

	return nnode;


};


Nodes* Thermokarst::InitiatingFrBS(Nodes* nnode, Nodes* curnode, long &cchtid){

	//cout<<endl<<"Initi BS 44444"<<endl;

	//new a node for a new fen
	cchtid += 1;	//add 1 to cchtid

	Nodes* pNode2 = new Nodes;     //using type 3: generate a cohort for new bog;
	pNode2->pNext = NULL;

	pNode2->year = curnode->year;
	pNode2->grdID = curnode->grdID;
	pNode2->parentid = curnode->cohortid;
	pNode2->cohortid = cchtid;
	pNode2->vegtype = 2;
	pNode2->age = 0;
	pNode2->generation = curnode->generation + 1;

	pNode2->proportion = curnode->proportion*2;
	pNode2->proportion = curnode->proportion/100;

	pNode2->flag = 2;

	//modify the current cohort

	curnode->proportion = curnode->proportion*98;
	curnode->proportion = curnode->proportion/100;

	//pNode1->pNext = pNode2;
	pNode2->pNext = nnode;
	//pNode3->pNext = nnode;
	nnode = pNode2;	//nnode is the new cohort list

	//cout<<endl<<"done BS 4444444444444444"<<endl;

	return nnode;


};


Nodes* Thermokarst::InitiatingFrDeci(Nodes* nnode, Nodes* curnode, long &cchtid){

	//cout<<endl<<"initi DECI 55555555555555"<<endl;

	//new a node for a new lake
	cchtid += 1;	//add 1 to cchtid

	Nodes* pNode3 = new Nodes;     //using type 3: generate a cohort for new bog;
	pNode3->pNext = NULL;

	pNode3->year = curnode->year;
	pNode3->grdID = curnode->grdID;
	pNode3->parentid = curnode->cohortid;
	pNode3->cohortid = cchtid;
	pNode3->vegtype = 1;
	pNode3->age = 0;

	pNode3->generation = curnode->generation + 1;
	pNode3->proportion = curnode->proportion*3;
	pNode3->proportion = curnode->proportion/100;
	pNode3->flag = 2;

	//modify the current cohort
	curnode->proportion = curnode->proportion*97;
	curnode->proportion = curnode->proportion/100;

	pNode3->pNext = nnode;
	nnode = pNode3;	//nnode is the new cohort list

	//cout<<endl<<"done WITH DECI 55555555555555555"<<endl;
	return nnode;

};


Nodes* Thermokarst::InitiatingFrTBog(Nodes* nnode, Nodes* curnode, long &cchtid){


		//cout<<endl<<"initi treed bog 10"<<endl;

		//new a node for a new fen
		cchtid += 1;	//add 1 to cchtid

		Nodes* pNode2 = new Nodes;     //using type 3: generate a cohort for new bog;
		pNode2->pNext = NULL;

		pNode2->year = curnode->year;
		pNode2->grdID = curnode->grdID;
		pNode2->parentid = curnode->cohortid;
		pNode2->cohortid = cchtid;
		pNode2->vegtype = 4;
		pNode2->age = 0;
		//cout<<"curnode->generation = "<<curnode->generation<<endl;
		//getchar();
		pNode2->generation = curnode->generation + 1;
		pNode2->proportion = curnode->proportion*1;
		pNode2->proportion = curnode->proportion/1000;
		pNode2->flag = 2;

		//modify the current cohort
		curnode->proportion = curnode->proportion*999;
		curnode->proportion = curnode->proportion/1000;

		//add the new node before current nnode
		pNode2->pNext = nnode;
		nnode = pNode2;	//nnode is the new cohort list

		return nnode;

};



Nodes* Thermokarst::InitiatingFrBog(Nodes* nnode, Nodes* curnode, long &cchtid){


		//add a cohort for new treed bog
		//cout<<endl<<"initiate from bog 1111111"<<endl;

		cchtid += 1;	//add 1 to cchtid

		//new a node for new bog
		Nodes* pNode1 = new Nodes;     //using type 3: generate a cohort for new bog;
		pNode1->pNext = NULL;

		pNode1->year = curnode->year;
		pNode1->grdID = curnode->grdID;
		pNode1->parentid = curnode->cohortid;
		pNode1->cohortid = cchtid;
		pNode1->vegtype = 10;
		pNode1->age = 0;
		pNode1->generation = curnode->generation + 1;


		pNode1->proportion = curnode->proportion*1;
		pNode1->proportion = curnode->proportion/100;


		pNode1->flag = 2;

		//curnode->proportion = 1000;
		curnode->proportion = curnode->proportion*99;
		curnode->proportion = curnode->proportion/100;

		pNode1->pNext = nnode;
		nnode = pNode1;	//nnode is the new cohort list

		return nnode;

};


Nodes* Thermokarst::InitiatingFrFen(Nodes* nnode, Nodes* curnode, long &cchtid){


	//add a cohort for new treed bog
	//cout<<endl<<"initiate from Fen 22222222"<<endl;

	cchtid += 1;	//add 1 to cchtid

	//new a node for new bog
	Nodes* pNode1 = new Nodes;     //using type 3: generate a cohort for new bog;
	pNode1->pNext = NULL;

	pNode1->year = curnode->year;
	pNode1->grdID = curnode->grdID;
	pNode1->parentid = curnode->cohortid;
	pNode1->cohortid = cchtid;
	pNode1->vegtype = 1;
	pNode1->age = 0;
	pNode1->generation = curnode->generation + 1;

	pNode1->proportion = curnode->proportion*1;
	pNode1->proportion = curnode->proportion/100;

	pNode1->flag = 2;

	curnode->proportion = curnode->proportion*99;
	curnode->proportion = curnode->proportion/100;

	pNode1->pNext = nnode;
	nnode = pNode1;	//nnode is the new cohort list

	return nnode;
};


Nodes* Thermokarst::InitiatingFrLake(Nodes* nnode, Nodes* curnode, long &cchtid){


	//add a cohort for new treed bog
	//cout<<endl<<"initiate from Lake 9999999999999"<<endl;

	cchtid += 1;	//add 1 to cchtid

	//new a node for new bog
	Nodes* pNode1 = new Nodes;
	pNode1->pNext = NULL;

	pNode1->year = curnode->year;
	pNode1->grdID = curnode->grdID;
	pNode1->parentid = curnode->cohortid;
	pNode1->cohortid = cchtid;
	pNode1->vegtype = 2;
	pNode1->age = 0;
	pNode1->generation = curnode->generation + 1;

	pNode1->proportion = curnode->proportion*1;
	pNode1->proportion = curnode->proportion/100;

	pNode1->flag = 2;

	curnode->proportion = curnode->proportion*99;
	curnode->proportion = curnode->proportion/100;

	pNode1->pNext = nnode;
	nnode = pNode1;	//nnode is the new cohort list

	//cout<<endl<<"done with From Lake 999999999999"<<endl;

//	getchar();

	return nnode;

};


void Thermokarst::SetPointer(IOdata* ptr){

	iopt = ptr;
}
