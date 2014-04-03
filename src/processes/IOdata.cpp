#include "IOdata.h"

IOdata::IOdata(){
	
};

IOdata::~IOdata(){
	
};


void IOdata::initlz(){

	//input data for predisposition
	predgrdid = -9999;
	predfrost = -9999;
	predlowland = -9999;
	predgiv = -9999;
	predwetland = -9999;

	predisposed = -9999;
	predFlag = -9999;

	//data for Node for linked list

	year = -9999;
	ingrdid = -9999;
	inparentid = -9999;
	incohortid = -9999;
	invegtype = -9999;
	inage = -9999;
	inproportion = -9999;
	inflag = -9999;


	//intermediate

	//output data

	outgridid = -9999;
	outcohortid = -9999;
	outvegetype = -9999;
	outage = -9999;
	outproportion = -9999;
	outflag = -9999;


	area3 = 0;
	area4 = 0;
	area5 = 0;
	area1 = 0;
	area2 = 0;
	area9 = 0;
	area10 = 0;


};





