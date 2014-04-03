/*
 * CHTPROP.h
 *
 *  Created on: Aug 26, 2013
 *      Author: yujin_admin
 */

#ifndef CHTPROP_H_
#define CHTPROP_H_

	#include <iostream>
	#include <fstream>
	#include <string>


	using namespace std;

	#include "../netcdf/includes/netcdfcpp.h"
	#include "../inc/ErrorCode.h"
	#include "../inc/Exception.h"

	#include "./IOdata.h"
	#include "./LNode.h"

	class ChtProp{
		public:
			ChtProp();
			~ChtProp();

			void outpLatlont3(string dirfile);
			void outpLatlont4(string dirfile);
			void outpLatlont5(string dirfile);
			void outpLatlont1(string dirfile);
			void outpLatlont2(string dirfile);
			void outpLatlont9(string dirfile);
			void outpLatlont10(string dirfile);

			void outpPropt3(IOdata* IOpointer, int yDid, int xDid, int yearid);
			void outpPropt4(IOdata* IOpointer, int yDid, int xDid, int yearid);
			void outpPropt5(IOdata* IOpointer, int yDid, int xDid, int yearid);
			void outpPropt1(IOdata* IOpointer, int yDid, int xDid, int yearid);
			void outpPropt2(IOdata* IOpointer, int yDid, int xDid, int yearid);
			void outpPropt9(IOdata* IOpointer, int yDid, int xDid, int yearid);
			void outpPropt10(IOdata* IOpointer, int yDid, int xDid, int yearid);

			void setPointer(IOdata* IOpointer);

			NcFile* PropFile;
			NcFile* PropFilet4;
			NcFile* PropFilet5;

			NcFile* Propfilet3;
			NcFile* Propfilet4;
			NcFile* Propfilet5;
			NcFile* Propfilet1;
			NcFile* Propfilet2;
			NcFile* Propfilet9;
			NcFile* Propfilet10;

			NcFile* LatLonFile;

			NcDim* xDim;
			NcDim* yDim;

			NcDim* xD;
			NcDim* yD;
			NcDim* yearD;

			double lat[10];
			double lon[10];

			NcVar* xDV;
			NcVar* yDV;
			NcVar* propV;
			NcVar* propVt4;
			NcVar* propVt5;

			NcVar* PropVt3;
			NcVar* PropVt4;
			NcVar* PropVt5;
			NcVar* PropVt1;
			NcVar* PropVt2;
			NcVar* PropVt9;
			NcVar* PropVt10;


		private:
			string dir4latlonFile;
			string dir4PropFile;

			string dir4latlonFilet4;
			string dir4PropFilet4;

			string dir4latlonFilet5;
			string dir4PropFilet5;

			IOdata* ioptr;


	};

#endif /*CHTPROP_H_*/
