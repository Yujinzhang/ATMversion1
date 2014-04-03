/*
 * CHTPROP.cpp
 *
 *  Created on: Aug 26, 2013
 *      Author: yujin_admin
 */

#include "ChtProp.h"
#include <stdio.h>

ChtProp::ChtProp(){

};

ChtProp::~ChtProp(){

};


void ChtProp::outpLatlont3(string dirfile){

	/////////////////// For lat long variables values
		dir4latlonFile = dirfile + "data/griddata/" + "tnngiv4latlon.nc";

		NcError err(NcError::silent_nonfatal);

		LatLonFile = new NcFile(dir4latlonFile.c_str(), NcFile::ReadOnly);

		cout<<"dir4latlonFile = "<<dir4latlonFile<<endl;

		if(!LatLonFile->is_valid()){
			string msg = dir4latlonFile + " is not valid";
			char* msgc = const_cast< char* > ( msg.c_str());
			throw Exception( msgc, I_NCFILE_NOT_EXIST);
		}

		xDim = LatLonFile->get_dim("x");
		if(!xDim->is_valid()){
			string msg = "The Dimension for inicht is not Valid in TNNinicht";
			char* msgc = const_cast<char*> (msg.c_str());
			throw Exception(msgc,  I_NCDIM_NOT_EXIST);
		}

		yDim = LatLonFile->get_dim("y");
		if(!yDim->is_valid()){
			string msg = "The Dimension for inicht is not Valid in TNNinicht";
			char* msgc = const_cast<char*> (msg.c_str());
			throw Exception(msgc,  I_NCDIM_NOT_EXIST);
		}

		//get the lat long variables values

		xDV = LatLonFile->get_var("x");
	 	if (xDV==NULL) {
	 	   string msg = "Cannot get x vaules in tnngiv4latlon file";
			char* msgc = const_cast<char*> (msg.c_str());
			throw Exception(msgc,  I_NCVAR_NOT_EXIST);
	 	}

		xDV->get(lat, 10);

		yDV = LatLonFile->get_var("y");
	 	if (xDV==NULL) {
	 	   string msg = "Cannot get y vaules in tnngiv4latlon file";
			char* msgc = const_cast<char*> (msg.c_str());
			throw Exception(msgc,  I_NCVAR_NOT_EXIST);
	 	}

		yDV->get(lon, 10);

		LatLonFile->close();

		cout<<"done with outpLatlont3"<<endl;
		//getchar();


		////////////////////////////////// For proportion output file
		//string stype = string(type);

		dir4PropFile = dirfile + "TNNPropTp3.nc";
		//cout<<"dir4PropFile === "<<dir4PropFile<<endl;

		Propfilet3 = new NcFile(dir4PropFile.c_str(), NcFile::Replace);
		if(!Propfilet3->is_valid())
		{
			string msg = "The PropFile is not Valid in PropFile.";
			char* msgc = const_cast<char*> (msg.c_str());
			throw Exception(msgc,  I_NCDIM_NOT_EXIST);
		}

		cout<<"Propfilet3->is_valid() = "<<Propfilet3->is_valid()<<endl;


		//define dimension
	 	xD = Propfilet3->add_dim("X",10);
	  	if(!xD->is_valid()){
	  		string msg = "The Dimension for PropFile is not Valid in PropFile";
	 		char* msgc = const_cast<char*> (msg.c_str());
	 		throw Exception(msgc,  I_NCDIM_NOT_EXIST);
	 	}

		cout<<"dim done 33333333001"<<endl;


	 	yD = Propfilet3->add_dim("Y",10);
	  	if(!yD->is_valid()){
	  		string msg = "The Dimension for PropFile is not Valid in PropFile";
	 		char* msgc = const_cast<char*> (msg.c_str());
	 		throw Exception(msgc,  I_NCDIM_NOT_EXIST);
	 	}

		cout<<"dim done 01"<<endl;

	  	yearD = Propfilet3->add_dim("Year");
	  	if(!yearD->is_valid()){
	  		string msg = "The Dimension for PropFile is not Valid in PropFile";
	 		char* msgc = const_cast<char*> (msg.c_str());
	 		throw Exception(msgc,  I_NCDIM_NOT_EXIST);
	 	}

		cout<<"dim done 3333331"<<endl;

		// add dim variables

		xDV = Propfilet3->add_var("x", ncFloat, xD);
		yDV = Propfilet3->add_var("y", ncFloat, yD);


		//put values to Dim variables x, y
		xDV->put(lat, 10);
		yDV->put(lon, 10);

		// add .nc var attributes

		PropVt3 = Propfilet3->add_var("Prop", ncFloat, yearD, yD, xD);
		PropVt3->add_att("units", "percent");
		PropVt3->add_att("title", "Proportion of thermokarst area");

		cout<<"done with t33333333333"<<endl;
		//getchar();

};


void ChtProp::outpLatlont4(string dirfile){

	/////////////////// For lat long variables values
		dir4latlonFile = dirfile + "data/griddata/" + "tnngiv4latlon.nc";

		NcError err(NcError::silent_nonfatal);

		LatLonFile = new NcFile(dir4latlonFile.c_str(), NcFile::ReadOnly);

		//cout<<"dir4latlonFile = "<<dir4latlonFile<<endl;

		if(!LatLonFile->is_valid()){
			string msg = dir4latlonFile + " is not valid";
			char* msgc = const_cast< char* > ( msg.c_str());
			throw Exception( msgc, I_NCFILE_NOT_EXIST);
		}

		xDim = LatLonFile->get_dim("x");
		if(!xDim->is_valid()){
			string msg = "The Dimension for inicht is not Valid in TNNinicht";
			char* msgc = const_cast<char*> (msg.c_str());
			throw Exception(msgc,  I_NCDIM_NOT_EXIST);
		}

		yDim = LatLonFile->get_dim("y");
		if(!yDim->is_valid()){
			string msg = "The Dimension for inicht is not Valid in TNNinicht";
			char* msgc = const_cast<char*> (msg.c_str());
			throw Exception(msgc,  I_NCDIM_NOT_EXIST);
		}

		//get the lat long variables values

		xDV = LatLonFile->get_var("x");
	 	if (xDV==NULL) {
	 	   string msg = "Cannot get x vaules in tnngiv4latlon file";
			char* msgc = const_cast<char*> (msg.c_str());
			throw Exception(msgc,  I_NCVAR_NOT_EXIST);
	 	}

		xDV->get(lat, 10);

		yDV = LatLonFile->get_var("y");
	 	if (xDV==NULL) {
	 	   string msg = "Cannot get y vaules in tnngiv4latlon file";
			char* msgc = const_cast<char*> (msg.c_str());
			throw Exception(msgc,  I_NCVAR_NOT_EXIST);
	 	}

		yDV->get(lon, 10);

		LatLonFile->close();

		cout<<"done with latlon"<<endl;


		////////////////////////////////// For proportion output file
		//string stype = string(type);

		dir4PropFile = dirfile + "TNNPropTp4.nc";
		//cout<<"dir4PropFile === "<<dir4PropFile<<endl;

		Propfilet4 = new NcFile(dir4PropFile.c_str(), NcFile::Replace);
		if(!Propfilet4->is_valid())
		{
			string msg = "The PropFile is not Valid in PropFile.";
			char* msgc = const_cast<char*> (msg.c_str());
			throw Exception(msgc,  I_NCDIM_NOT_EXIST);
		}

		cout<<"Propfilet3->is_valid() = "<<Propfilet4->is_valid()<<endl;


		//define dimension
	 	xD = Propfilet4->add_dim("X",10);
	  	if(!xD->is_valid()){
	  		string msg = "The Dimension for PropFile is not Valid in PropFile";
	 		char* msgc = const_cast<char*> (msg.c_str());
	 		throw Exception(msgc,  I_NCDIM_NOT_EXIST);
	 	}

		cout<<"dim done 001"<<endl;


	 	yD = Propfilet4->add_dim("Y",10);
	  	if(!yD->is_valid()){
	  		string msg = "The Dimension for PropFile is not Valid in PropFile";
	 		char* msgc = const_cast<char*> (msg.c_str());
	 		throw Exception(msgc,  I_NCDIM_NOT_EXIST);
	 	}

		cout<<"dim done 01"<<endl;

	  	yearD = Propfilet4->add_dim("Year");
	  	if(!yearD->is_valid()){
	  		string msg = "The Dimension for PropFile is not Valid in PropFile";
	 		char* msgc = const_cast<char*> (msg.c_str());
	 		throw Exception(msgc,  I_NCDIM_NOT_EXIST);
	 	}

		cout<<"dim done 1"<<endl;

		// add dim variables

		xDV = Propfilet4->add_var("x", ncFloat, xD);
		yDV = Propfilet4->add_var("y", ncFloat, yD);


		//put values to Dim variables x, y
		xDV->put(lat, 10);
		yDV->put(lon, 10);

		// add .nc var attributes

		PropVt4 = Propfilet4->add_var("Prop", ncFloat, yearD, yD, xD);
		PropVt4->add_att("units", "percent");
		PropVt4->add_att("title", "Proportion of thermokarst area");

		cout<<"done with t4"<<endl;

};

void ChtProp::outpLatlont5(string dirfile){


	/////////////////// For lat long variables values
		dir4latlonFile = dirfile + "data/griddata/" + "tnngiv4latlon.nc";

		NcError err(NcError::silent_nonfatal);

		LatLonFile = new NcFile(dir4latlonFile.c_str(), NcFile::ReadOnly);

		//cout<<"dir4latlonFile = "<<dir4latlonFile<<endl;

		if(!LatLonFile->is_valid()){
			string msg = dir4latlonFile + " is not valid";
			char* msgc = const_cast< char* > ( msg.c_str());
			throw Exception( msgc, I_NCFILE_NOT_EXIST);
		}

		xDim = LatLonFile->get_dim("x");
		if(!xDim->is_valid()){
			string msg = "The Dimension for inicht is not Valid in TNNinicht";
			char* msgc = const_cast<char*> (msg.c_str());
			throw Exception(msgc,  I_NCDIM_NOT_EXIST);
		}

		yDim = LatLonFile->get_dim("y");
		if(!yDim->is_valid()){
			string msg = "The Dimension for inicht is not Valid in TNNinicht";
			char* msgc = const_cast<char*> (msg.c_str());
			throw Exception(msgc,  I_NCDIM_NOT_EXIST);
		}

		//get the lat long variables values

		xDV = LatLonFile->get_var("x");
	 	if (xDV==NULL) {
	 	   string msg = "Cannot get x vaules in tnngiv4latlon file";
			char* msgc = const_cast<char*> (msg.c_str());
			throw Exception(msgc,  I_NCVAR_NOT_EXIST);
	 	}

		xDV->get(lat, 10);

		yDV = LatLonFile->get_var("y");
	 	if (xDV==NULL) {
	 	   string msg = "Cannot get y vaules in tnngiv4latlon file";
			char* msgc = const_cast<char*> (msg.c_str());
			throw Exception(msgc,  I_NCVAR_NOT_EXIST);
	 	}

		yDV->get(lon, 10);

		LatLonFile->close();

		cout<<"done with latlon"<<endl;


		////////////////////////////////// For proportion output file
		//string stype = string(type);

		dir4PropFile = dirfile + "TNNPropTp5.nc";
		//cout<<"dir4PropFile === "<<dir4PropFile<<endl;

		Propfilet5 = new NcFile(dir4PropFile.c_str(), NcFile::Replace);
		if(!Propfilet5->is_valid())
		{
			string msg = "The PropFile is not Valid in PropFile.";
			char* msgc = const_cast<char*> (msg.c_str());
			throw Exception(msgc,  I_NCDIM_NOT_EXIST);
		}

		cout<<"Propfilet3->is_valid() = "<<Propfilet5->is_valid()<<endl;


		//define dimension
	 	xD = Propfilet5->add_dim("X",10);
	  	if(!xD->is_valid()){
	  		string msg = "The Dimension for PropFile is not Valid in PropFile";
	 		char* msgc = const_cast<char*> (msg.c_str());
	 		throw Exception(msgc,  I_NCDIM_NOT_EXIST);
	 	}

		cout<<"dim done 001"<<endl;


	 	yD = Propfilet5->add_dim("Y",10);
	  	if(!yD->is_valid()){
	  		string msg = "The Dimension for PropFile is not Valid in PropFile";
	 		char* msgc = const_cast<char*> (msg.c_str());
	 		throw Exception(msgc,  I_NCDIM_NOT_EXIST);
	 	}

		cout<<"dim done 01"<<endl;

	  	yearD = Propfilet5->add_dim("Year");
	  	if(!yearD->is_valid()){
	  		string msg = "The Dimension for PropFile is not Valid in PropFile";
	 		char* msgc = const_cast<char*> (msg.c_str());
	 		throw Exception(msgc,  I_NCDIM_NOT_EXIST);
	 	}

		cout<<"dim done 1"<<endl;

		// add dim variables

		xDV = Propfilet5->add_var("x", ncFloat, xD);
		yDV = Propfilet5->add_var("y", ncFloat, yD);


		//put values to Dim variables x, y
		xDV->put(lat, 10);
		yDV->put(lon, 10);

		// add .nc var attributes

		PropVt5 = Propfilet5->add_var("Prop", ncFloat, yearD, yD, xD);
		PropVt5->add_att("units", "percent");
		PropVt5->add_att("title", "Proportion of thermokarst area");

		cout<<"done with t5"<<endl;
};

void ChtProp::outpLatlont1(string dirfile){


	/////////////////// For lat long variables values
		dir4latlonFile = dirfile + "data/griddata/" + "tnngiv4latlon.nc";

		NcError err(NcError::silent_nonfatal);

		LatLonFile = new NcFile(dir4latlonFile.c_str(), NcFile::ReadOnly);

		//cout<<"dir4latlonFile = "<<dir4latlonFile<<endl;

		if(!LatLonFile->is_valid()){
			string msg = dir4latlonFile + " is not valid";
			char* msgc = const_cast< char* > ( msg.c_str());
			throw Exception( msgc, I_NCFILE_NOT_EXIST);
		}

		xDim = LatLonFile->get_dim("x");
		if(!xDim->is_valid()){
			string msg = "The Dimension for inicht is not Valid in TNNinicht";
			char* msgc = const_cast<char*> (msg.c_str());
			throw Exception(msgc,  I_NCDIM_NOT_EXIST);
		}

		yDim = LatLonFile->get_dim("y");
		if(!yDim->is_valid()){
			string msg = "The Dimension for inicht is not Valid in TNNinicht";
			char* msgc = const_cast<char*> (msg.c_str());
			throw Exception(msgc,  I_NCDIM_NOT_EXIST);
		}

		//get the lat long variables values

		xDV = LatLonFile->get_var("x");
	 	if (xDV==NULL) {
	 	   string msg = "Cannot get x vaules in tnngiv4latlon file";
			char* msgc = const_cast<char*> (msg.c_str());
			throw Exception(msgc,  I_NCVAR_NOT_EXIST);
	 	}

		xDV->get(lat, 10);

		yDV = LatLonFile->get_var("y");
	 	if (xDV==NULL) {
	 	   string msg = "Cannot get y vaules in tnngiv4latlon file";
			char* msgc = const_cast<char*> (msg.c_str());
			throw Exception(msgc,  I_NCVAR_NOT_EXIST);
	 	}

		yDV->get(lon, 10);

		LatLonFile->close();

		cout<<"done with latlon"<<endl;


		////////////////////////////////// For proportion output file
		//string stype = string(type);

		dir4PropFile = dirfile + "TNNPropTp1.nc";
		//cout<<"dir4PropFile === "<<dir4PropFile<<endl;

		Propfilet1 = new NcFile(dir4PropFile.c_str(), NcFile::Replace);
		if(!Propfilet1->is_valid())
		{
			string msg = "The PropFile is not Valid in PropFile.";
			char* msgc = const_cast<char*> (msg.c_str());
			throw Exception(msgc,  I_NCDIM_NOT_EXIST);
		}

		cout<<"Propfilet1->is_valid() = "<<Propfilet1->is_valid()<<endl;


		//define dimension
	 	xD = Propfilet1->add_dim("X",10);
	  	if(!xD->is_valid()){
	  		string msg = "The Dimension for PropFile is not Valid in PropFile";
	 		char* msgc = const_cast<char*> (msg.c_str());
	 		throw Exception(msgc,  I_NCDIM_NOT_EXIST);
	 	}

		cout<<"dim done 001"<<endl;


	 	yD = Propfilet1->add_dim("Y",10);
	  	if(!yD->is_valid()){
	  		string msg = "The Dimension for PropFile is not Valid in PropFile";
	 		char* msgc = const_cast<char*> (msg.c_str());
	 		throw Exception(msgc,  I_NCDIM_NOT_EXIST);
	 	}

		cout<<"dim done 01"<<endl;

	  	yearD = Propfilet1->add_dim("Year");
	  	if(!yearD->is_valid()){
	  		string msg = "The Dimension for PropFile is not Valid in PropFile";
	 		char* msgc = const_cast<char*> (msg.c_str());
	 		throw Exception(msgc,  I_NCDIM_NOT_EXIST);
	 	}

		cout<<"dim done 1"<<endl;

		// add dim variables

		xDV = Propfilet1->add_var("x", ncFloat, xD);
		yDV = Propfilet1->add_var("y", ncFloat, yD);


		//put values to Dim variables x, y
		xDV->put(lat, 10);
		yDV->put(lon, 10);

		// add .nc var attributes

		PropVt1 = Propfilet1->add_var("Prop", ncFloat, yearD, yD, xD);
		PropVt1->add_att("units", "percent");
		PropVt1->add_att("title", "Proportion of thermokarst area");

		cout<<"done with t1"<<endl;

};

void ChtProp::outpLatlont2(string dirfile){


	/////////////////// For lat long variables values
		dir4latlonFile = dirfile + "data/griddata/" + "tnngiv4latlon.nc";

		NcError err(NcError::silent_nonfatal);

		LatLonFile = new NcFile(dir4latlonFile.c_str(), NcFile::ReadOnly);

		//cout<<"dir4latlonFile = "<<dir4latlonFile<<endl;

		if(!LatLonFile->is_valid()){
			string msg = dir4latlonFile + " is not valid";
			char* msgc = const_cast< char* > ( msg.c_str());
			throw Exception( msgc, I_NCFILE_NOT_EXIST);
		}

		xDim = LatLonFile->get_dim("x");
		if(!xDim->is_valid()){
			string msg = "The Dimension for inicht is not Valid in TNNinicht";
			char* msgc = const_cast<char*> (msg.c_str());
			throw Exception(msgc,  I_NCDIM_NOT_EXIST);
		}

		yDim = LatLonFile->get_dim("y");
		if(!yDim->is_valid()){
			string msg = "The Dimension for inicht is not Valid in TNNinicht";
			char* msgc = const_cast<char*> (msg.c_str());
			throw Exception(msgc,  I_NCDIM_NOT_EXIST);
		}

		//get the lat long variables values

		xDV = LatLonFile->get_var("x");
	 	if (xDV==NULL) {
	 	   string msg = "Cannot get x vaules in tnngiv4latlon file";
			char* msgc = const_cast<char*> (msg.c_str());
			throw Exception(msgc,  I_NCVAR_NOT_EXIST);
	 	}

		xDV->get(lat, 10);

		yDV = LatLonFile->get_var("y");
	 	if (xDV==NULL) {
	 	   string msg = "Cannot get y vaules in tnngiv4latlon file";
			char* msgc = const_cast<char*> (msg.c_str());
			throw Exception(msgc,  I_NCVAR_NOT_EXIST);
	 	}

		yDV->get(lon, 10);

		LatLonFile->close();

		cout<<"done with latlon"<<endl;


		////////////////////////////////// For proportion output file
		//string stype = string(type);

		dir4PropFile = dirfile + "TNNPropTp2.nc";
		//cout<<"dir4PropFile === "<<dir4PropFile<<endl;

		Propfilet2 = new NcFile(dir4PropFile.c_str(), NcFile::Replace);
		if(!Propfilet2->is_valid())
		{
			string msg = "The PropFile is not Valid in PropFile.";
			char* msgc = const_cast<char*> (msg.c_str());
			throw Exception(msgc,  I_NCDIM_NOT_EXIST);
		}

		cout<<"Propfilet3->is_valid() = "<<Propfilet2->is_valid()<<endl;


		//define dimension
	 	xD = Propfilet2->add_dim("X",10);
	  	if(!xD->is_valid()){
	  		string msg = "The Dimension for PropFile is not Valid in PropFile";
	 		char* msgc = const_cast<char*> (msg.c_str());
	 		throw Exception(msgc,  I_NCDIM_NOT_EXIST);
	 	}

		cout<<"dim done 001"<<endl;


	 	yD = Propfilet2->add_dim("Y",10);
	  	if(!yD->is_valid()){
	  		string msg = "The Dimension for PropFile is not Valid in PropFile";
	 		char* msgc = const_cast<char*> (msg.c_str());
	 		throw Exception(msgc,  I_NCDIM_NOT_EXIST);
	 	}

		cout<<"dim done 01"<<endl;

	  	yearD = Propfilet2->add_dim("Year");
	  	if(!yearD->is_valid()){
	  		string msg = "The Dimension for PropFile is not Valid in PropFile";
	 		char* msgc = const_cast<char*> (msg.c_str());
	 		throw Exception(msgc,  I_NCDIM_NOT_EXIST);
	 	}

		cout<<"dim done 1"<<endl;

		// add dim variables

		xDV = Propfilet2->add_var("x", ncFloat, xD);
		yDV = Propfilet2->add_var("y", ncFloat, yD);


		//put values to Dim variables x, y
		xDV->put(lat, 10);
		yDV->put(lon, 10);

		// add .nc var attributes

		PropVt2 = Propfilet2->add_var("Prop", ncFloat, yearD, yD, xD);
		PropVt2->add_att("units", "percent");
		PropVt2->add_att("title", "Proportion of thermokarst area");

		cout<<"done with t5"<<endl;
};

void ChtProp::outpLatlont9(string dirfile){


	/////////////////// For lat long variables values
		dir4latlonFile = dirfile + "data/griddata/" + "tnngiv4latlon.nc";

		NcError err(NcError::silent_nonfatal);

		LatLonFile = new NcFile(dir4latlonFile.c_str(), NcFile::ReadOnly);

		//cout<<"dir4latlonFile = "<<dir4latlonFile<<endl;

		if(!LatLonFile->is_valid()){
			string msg = dir4latlonFile + " is not valid";
			char* msgc = const_cast< char* > ( msg.c_str());
			throw Exception( msgc, I_NCFILE_NOT_EXIST);
		}

		xDim = LatLonFile->get_dim("x");
		if(!xDim->is_valid()){
			string msg = "The Dimension for inicht is not Valid in TNNinicht";
			char* msgc = const_cast<char*> (msg.c_str());
			throw Exception(msgc,  I_NCDIM_NOT_EXIST);
		}

		yDim = LatLonFile->get_dim("y");
		if(!yDim->is_valid()){
			string msg = "The Dimension for inicht is not Valid in TNNinicht";
			char* msgc = const_cast<char*> (msg.c_str());
			throw Exception(msgc,  I_NCDIM_NOT_EXIST);
		}

		//get the lat long variables values

		xDV = LatLonFile->get_var("x");
	 	if (xDV==NULL) {
	 	   string msg = "Cannot get x vaules in tnngiv4latlon file";
			char* msgc = const_cast<char*> (msg.c_str());
			throw Exception(msgc,  I_NCVAR_NOT_EXIST);
	 	}

		xDV->get(lat, 10);

		yDV = LatLonFile->get_var("y");
	 	if (xDV==NULL) {
	 	   string msg = "Cannot get y vaules in tnngiv4latlon file";
			char* msgc = const_cast<char*> (msg.c_str());
			throw Exception(msgc,  I_NCVAR_NOT_EXIST);
	 	}

		yDV->get(lon, 10);

		LatLonFile->close();

		cout<<"done with latlon"<<endl;


		////////////////////////////////// For proportion output file
		//string stype = string(type);

		dir4PropFile = dirfile + "TNNPropTp9.nc";
		//cout<<"dir4PropFile === "<<dir4PropFile<<endl;

		Propfilet9 = new NcFile(dir4PropFile.c_str(), NcFile::Replace);
		if(!Propfilet9->is_valid())
		{
			string msg = "The PropFile is not Valid in PropFile.";
			char* msgc = const_cast<char*> (msg.c_str());
			throw Exception(msgc,  I_NCDIM_NOT_EXIST);
		}

		cout<<"Propfilet9->is_valid() = "<<Propfilet9->is_valid()<<endl;


		//define dimension
	 	xD = Propfilet9->add_dim("X",10);
	  	if(!xD->is_valid()){
	  		string msg = "The Dimension for PropFile is not Valid in PropFile";
	 		char* msgc = const_cast<char*> (msg.c_str());
	 		throw Exception(msgc,  I_NCDIM_NOT_EXIST);
	 	}

		cout<<"dim done 001"<<endl;


	 	yD = Propfilet9->add_dim("Y",10);
	  	if(!yD->is_valid()){
	  		string msg = "The Dimension for PropFile is not Valid in PropFile";
	 		char* msgc = const_cast<char*> (msg.c_str());
	 		throw Exception(msgc,  I_NCDIM_NOT_EXIST);
	 	}

		cout<<"dim done 01"<<endl;

	  	yearD = Propfilet9->add_dim("Year");
	  	if(!yearD->is_valid()){
	  		string msg = "The Dimension for PropFile is not Valid in PropFile";
	 		char* msgc = const_cast<char*> (msg.c_str());
	 		throw Exception(msgc,  I_NCDIM_NOT_EXIST);
	 	}

		cout<<"dim done 1"<<endl;

		// add dim variables

		xDV = Propfilet9->add_var("x", ncFloat, xD);
		yDV = Propfilet9->add_var("y", ncFloat, yD);


		//put values to Dim variables x, y
		xDV->put(lat, 10);
		yDV->put(lon, 10);

		// add .nc var attributes

		PropVt9 = Propfilet9->add_var("Prop", ncFloat, yearD, yD, xD);
		PropVt9->add_att("units", "percent");
		PropVt9->add_att("title", "Proportion of thermokarst area");

		cout<<"done with t9"<<endl;
};

void ChtProp::outpLatlont10(string dirfile){


	/////////////////// For lat long variables values
		dir4latlonFile = dirfile + "data/griddata/" + "tnngiv4latlon.nc";

		NcError err(NcError::silent_nonfatal);

		LatLonFile = new NcFile(dir4latlonFile.c_str(), NcFile::ReadOnly);

		//cout<<"dir4latlonFile = "<<dir4latlonFile<<endl;

		if(!LatLonFile->is_valid()){
			string msg = dir4latlonFile + " is not valid";
			char* msgc = const_cast< char* > ( msg.c_str());
			throw Exception( msgc, I_NCFILE_NOT_EXIST);
		}

		xDim = LatLonFile->get_dim("x");
		if(!xDim->is_valid()){
			string msg = "The Dimension for inicht is not Valid in TNNinicht";
			char* msgc = const_cast<char*> (msg.c_str());
			throw Exception(msgc,  I_NCDIM_NOT_EXIST);
		}

		yDim = LatLonFile->get_dim("y");
		if(!yDim->is_valid()){
			string msg = "The Dimension for inicht is not Valid in TNNinicht";
			char* msgc = const_cast<char*> (msg.c_str());
			throw Exception(msgc,  I_NCDIM_NOT_EXIST);
		}

		//get the lat long variables values

		xDV = LatLonFile->get_var("x");
	 	if (xDV==NULL) {
	 	   string msg = "Cannot get x vaules in tnngiv4latlon file";
			char* msgc = const_cast<char*> (msg.c_str());
			throw Exception(msgc,  I_NCVAR_NOT_EXIST);
	 	}

		xDV->get(lat, 10);

		yDV = LatLonFile->get_var("y");
	 	if (xDV==NULL) {
	 	   string msg = "Cannot get y vaules in tnngiv4latlon file";
			char* msgc = const_cast<char*> (msg.c_str());
			throw Exception(msgc,  I_NCVAR_NOT_EXIST);
	 	}

		yDV->get(lon, 10);

		LatLonFile->close();

		cout<<"done with latlon"<<endl;


		////////////////////////////////// For proportion output file
		//string stype = string(type);

		dir4PropFile = dirfile + "TNNPropTp10.nc";
		//cout<<"dir4PropFile === "<<dir4PropFile<<endl;

		Propfilet10 = new NcFile(dir4PropFile.c_str(), NcFile::Replace);
		if(!Propfilet10->is_valid())
		{
			string msg = "The PropFile is not Valid in PropFile.";
			char* msgc = const_cast<char*> (msg.c_str());
			throw Exception(msgc,  I_NCDIM_NOT_EXIST);
		}

		cout<<"Propfilet10->is_valid() = "<<Propfilet10->is_valid()<<endl;


		//define dimension
	 	xD = Propfilet10->add_dim("X",10);
	  	if(!xD->is_valid()){
	  		string msg = "The Dimension for PropFile is not Valid in PropFile";
	 		char* msgc = const_cast<char*> (msg.c_str());
	 		throw Exception(msgc,  I_NCDIM_NOT_EXIST);
	 	}

		cout<<"dim done 001"<<endl;


	 	yD = Propfilet10->add_dim("Y",10);
	  	if(!yD->is_valid()){
	  		string msg = "The Dimension for PropFile is not Valid in PropFile";
	 		char* msgc = const_cast<char*> (msg.c_str());
	 		throw Exception(msgc,  I_NCDIM_NOT_EXIST);
	 	}

		cout<<"dim done 01"<<endl;

	  	yearD = Propfilet10->add_dim("Year");
	  	if(!yearD->is_valid()){
	  		string msg = "The Dimension for PropFile is not Valid in PropFile";
	 		char* msgc = const_cast<char*> (msg.c_str());
	 		throw Exception(msgc,  I_NCDIM_NOT_EXIST);
	 	}

		cout<<"dim done 1"<<endl;

		// add dim variables

		xDV = Propfilet10->add_var("x", ncFloat, xD);
		yDV = Propfilet10->add_var("y", ncFloat, yD);


		//put values to Dim variables x, y
		xDV->put(lat, 10);
		yDV->put(lon, 10);

		// add .nc var attributes

		PropVt10 = Propfilet10->add_var("Prop", ncFloat, yearD, yD, xD);
		PropVt10->add_att("units", "percent");
		PropVt10->add_att("title", "Proportion of thermokarst area");

		cout<<"done with t10"<<endl;

};


void ChtProp::outpPropt3(IOdata* IOpointer, int yDid, int xDid, int yearid){

	PropVt3->set_cur(yearid, yDid, xDid);
	NcBool nb1 = PropVt3->put(&IOpointer->area3, 1, 1, 1);  	//number for reading
	if (!nb1) {
	 string msg = "problem in put prop in TNNprop.nc";
		char* msgc = const_cast<char*> (msg.c_str());
		throw Exception(msgc,  I_NCVAR_GET_ERROR);
	}

};


void ChtProp::outpPropt4(IOdata* IOpointer, int yDid, int xDid, int yearid){

	PropVt4->set_cur(yearid, yDid, xDid);
	NcBool nb1 = PropVt4->put(&IOpointer->area4, 1, 1, 1);  	//number for reading
	if (!nb1) {
	 string msg = "problem in put prop in TNNprop.nc";
		char* msgc = const_cast<char*> (msg.c_str());
		throw Exception(msgc,  I_NCVAR_GET_ERROR);
	}
};

void ChtProp::outpPropt5(IOdata* IOpointer, int yDid, int xDid, int yearid){

	PropVt5->set_cur(yearid, yDid, xDid);
	NcBool nb1 = PropVt5->put(&IOpointer->area5, 1, 1, 1);  	//number for reading
	if (!nb1) {
	 string msg = "problem in put prop in TNNprop.nc";
		char* msgc = const_cast<char*> (msg.c_str());
		throw Exception(msgc,  I_NCVAR_GET_ERROR);
	}
};

void ChtProp::outpPropt1(IOdata* IOpointer, int yDid, int xDid, int yearid){

	PropVt1->set_cur(yearid, yDid, xDid);
	NcBool nb1 = PropVt1->put(&IOpointer->area1, 1, 1, 1);  	//number for reading
	if (!nb1) {
	 string msg = "problem in put prop in TNNprop.nc";
		char* msgc = const_cast<char*> (msg.c_str());
		throw Exception(msgc,  I_NCVAR_GET_ERROR);
	}
};

void ChtProp::outpPropt2(IOdata* IOpointer, int yDid, int xDid, int yearid){

	PropVt2->set_cur(yearid, yDid, xDid);
	NcBool nb1 = PropVt2->put(&IOpointer->area2, 1, 1, 1);  	//number for reading
	if (!nb1) {
	 string msg = "problem in put prop in TNNprop.nc";
		char* msgc = const_cast<char*> (msg.c_str());
		throw Exception(msgc,  I_NCVAR_GET_ERROR);
	}
};

void ChtProp::outpPropt9(IOdata* IOpointer, int yDid, int xDid, int yearid){

	PropVt9->set_cur(yearid, yDid, xDid);
	NcBool nb1 = PropVt9->put(&IOpointer->area9, 1, 1, 1);  	//number for reading
	if (!nb1) {
	 string msg = "problem in put prop in TNNprop.nc";
		char* msgc = const_cast<char*> (msg.c_str());
		throw Exception(msgc,  I_NCVAR_GET_ERROR);
	}
};

void ChtProp::outpPropt10(IOdata* IOpointer, int yDid, int xDid, int yearid){

	PropVt10->set_cur(yearid, yDid, xDid);
	NcBool nb1 = PropVt10->put(&IOpointer->area10, 1, 1, 1);  	//number for reading
	if (!nb1) {
	 string msg = "problem in put prop in TNNprop.nc";
		char* msgc = const_cast<char*> (msg.c_str());
		throw Exception(msgc,  I_NCVAR_GET_ERROR);
	}
};

void ChtProp::setPointer(IOdata* IOpointer){

		ioptr = IOpointer;
};
