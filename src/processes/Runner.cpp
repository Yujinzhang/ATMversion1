/*
 * Runner.cpp
 *
 *  Created on: Jul 25, 2013
 *      Author: yujin_admin
 */

#include "./Runner.h"

Runner::Runner(){

};

Runner::~Runner(){

};


void Runner::InitInputFile(string & dirfile){   //check all model intput files to make sure they are correct

		///////////////////////////////////////////open and check for inputting giv data

		string dir4givfile = dirfile + "data/griddata/" + "TNNgiv.nc";

		NcFile givfile(dir4givfile.c_str(), NcFile::ReadOnly);


	 	if(!givfile.is_valid()){
	 		string msg = dir4givfile + " is not valid";
	 		char* msgc = const_cast< char* > ( msg.c_str());
	 		throw Exception( msgc, I_NCFILE_NOT_EXIST);
	 	}

		NcDim* givD = givfile.get_dim("GRDID");
		if(!givD->is_valid()){
			string msg = "The Dimension for giv is not Valid in TNNgiv";
			char* msgc = const_cast<char*> (msg.c_str());
			throw Exception(msgc,  I_NCDIM_NOT_EXIST);
		}

		givfile.close();

		///////////////////////////////////////////open and check for inputting permafrost data

		string dir4frostfile;
		dir4frostfile = dirfile +  "data/griddata/" + "TNNfrost.nc";

		NcFile frostfile(dir4frostfile.c_str(), NcFile::ReadOnly);

		if(!frostfile.is_valid()){
			string msg = dir4frostfile + " is not valid";
			char* msgc = const_cast< char* > ( msg.c_str());
			throw Exception( msgc, I_NCFILE_NOT_EXIST);
		}


		NcDim* frostD = frostfile.get_dim("GRDID");
		if(!frostD->is_valid()){
			string msg = "The Dimension for frost is not Valid in TNNfrost";
			char* msgc = const_cast<char*> (msg.c_str());
			throw Exception(msgc,  I_NCDIM_NOT_EXIST);
		}

		frostfile.close();

		///////////////////////////////////////////open and check for inputting cohortid data

		string dir4cohortidfile;
		dir4cohortidfile = dirfile +  "data/griddata/" + "TNNcohortid.nc";

		NcFile cohortidfile(dir4cohortidfile.c_str(), NcFile::ReadOnly);
		//cout<<"cohortidfile.is_valid() = "<<cohortidfile.is_valid()<<endl;

		if(!cohortidfile.is_valid()){
			string msg = dir4cohortidfile + " is not valid";
			char* msgc = const_cast< char* > ( msg.c_str());
			throw Exception( msgc, I_NCFILE_NOT_EXIST);
		}

		NcDim* cohortidD = cohortidfile.get_dim("GRDID");
		if(!cohortidD->is_valid()){
			string msg = "The Dimension for cohortid is not Valid in TNNcohortid";
			char* msgc = const_cast<char*> (msg.c_str());
			throw Exception(msgc,  I_NCDIM_NOT_EXIST);
		}
		cohortidfile.close();

		///////////////////////////////////////////open and check for inputting inicht data

		string dir4inichtfile;
		dir4inichtfile = dirfile +  "data/griddata/" + "TNNinicht.nc";

		NcFile inichtfile(dir4inichtfile.c_str(), NcFile::ReadOnly);

		if(!inichtfile.is_valid()){
			string msg = dir4inichtfile + " is not valid";
			char* msgc = const_cast< char* > ( msg.c_str());
			throw Exception( msgc, I_NCFILE_NOT_EXIST);
		}

		NcDim* inichtD = inichtfile.get_dim("TOTALCHTS");
		if(!inichtD->is_valid()){
			string msg = "The Dimension for inicht is not Valid in TNNinicht";
			char* msgc = const_cast<char*> (msg.c_str());
			throw Exception(msgc,  I_NCDIM_NOT_EXIST);
		}

		inichtfile.close();

		///////////////////////////////////////////open and check for inputting lowland data

		string dir4lowlandfile;
		dir4lowlandfile = dirfile +  "data/griddata/" + "TNNlowlandnew.nc";


		NcFile lowlandfile(dir4lowlandfile.c_str(), NcFile::ReadOnly);
		if(!lowlandfile.is_valid()){
			string msg = dir4lowlandfile + " is not valid";
			char* msgc = const_cast< char* > ( msg.c_str());
			throw Exception( msgc, I_NCFILE_NOT_EXIST);
		}

		NcDim* lowlandD = lowlandfile.get_dim("GRDID");
		if(!lowlandD->is_valid()){
			string msg = "The Dimension for lowland is not Valid in TNNlowland";
			char* msgc = const_cast<char*> (msg.c_str());
			throw Exception(msgc,  I_NCDIM_NOT_EXIST);
		}

		lowlandfile.close();

		//cout<<"done 5"<<endl;


		///////////////////////////////////////////open and check for inputting wetland data
		string dir4wetlandfile;
		dir4wetlandfile = dirfile +  "data/griddata/" + "TNNwetland.nc";

		NcFile wetlandfile(dir4wetlandfile.c_str(), NcFile::ReadOnly);

		if(!wetlandfile.is_valid()){
			string msg = dir4wetlandfile + " is not valid";
			char* msgc = const_cast< char* > ( msg.c_str());
			throw Exception( msgc, I_NCFILE_NOT_EXIST);
		}

		NcDim* wetlandD = wetlandfile.get_dim("GRDID");
		if(!wetlandD->is_valid()){
			string msg = "The Dimension for wetland is not Valid in TNNwetland";
			char* msgc = const_cast<char*> (msg.c_str());
			throw Exception(msgc,  I_NCDIM_NOT_EXIST);
		}

		wetlandfile.close();


};

void Runner::Run(IOdata* ptr, string dir){

	//setup the year loop

	string dir4files;
	dir4files = dir;

	//cout<<endl<<"	dir4files = "<<	dir4files<<endl;

	int year = 0;
	int ystart = 2000;
	int yend = 2003;

	int ChtRec;	//record of cohort read

	IOdata* pt;
	pt = ptr; // the pointer with function Run()

	Predisposition pred;
	//initializing the output file
	pred.InitiPred(dir4files);
	//setup the data pointer
	pred.SetPointer(pt);		//using the pointer to predisposing factors

	Thermokarst thmkst;
	thmkst.SetPointer(pt);

	Dlist dlist;

	ChtInputer chtin;
	Outputer outputr;

	DelFile delfile;

	//check input datasets in NetCDF files.
	InitInputFile(dir4files);

	ProcCht proccht;	//output cht
	proccht.SetPointer(pt);		//using the pointer to initial cohorts data in iodata

	ChtProp chtprop;
	//chtprop.outputlatlont3(dir4files);
	//chtprop.outputlatlont4(dir4files);
	//chtprop.outputlatlont5(dir4files);

	/*
	//new outputs
	chtprop.outpLatlont3(dir4files);
	chtprop.outpLatlont4(dir4files);
	chtprop.outpLatlont5(dir4files);
	chtprop.outpLatlont1(dir4files);
	chtprop.outpLatlont2(dir4files);
	chtprop.outpLatlont9(dir4files);
	chtprop.outpLatlont10(dir4files);
	*/

	////////////////////////////////////////////////////

	CreateFlder crtfld;
	for(int grdid=1;grdid<101;grdid++){

		crtfld.Createflder(dir,grdid);
	}

	////////////////////////////////////////////////////
	//loop through years within the current grid cell

	year = ystart;
	bool bthmkst = 0;

	string s_Dir;

	stringstream ss_Dir;

	long maxchtid = chtin.InitMaxChtId();

	int ttlGrdCnt =100;
	chtin.InitChtFile(dir4files);

	while ( year < yend){   //loop through years

		////////////////////////////////////////////////////
		//loop through grid cells
		int grdid = 1;

		while (grdid <= ttlGrdCnt){   //loop through grids

				cout<<endl<<"//////////////////////////////// loop grdid NO. = "<<grdid<<endl;

				//initializing the folder for current grid cell
				ss_Dir.str("");
				ss_Dir << grdid;
				s_Dir = dir4files + "data/output/G" + ss_Dir.str() + "/";

				//cout<<"current grid ss_Dir.str() = "<<ss_Dir.str()<<endl;
				//cout<<"current grid s_Dir = "<<s_Dir<<endl;
				outputr.InitOutputCht(s_Dir,grdid,year);

				//if year = ystart, open the cohorts in "TNNinichtnew.nc"
				//else, open the chts in previous year and initialize new output for the current grid cell in current year
				if ( year == ystart){

					int ttlnumGridRec = chtin.getNumVals(dir4files);
					////////////////////////////////////////////////////
					long tRecid = 0;	//control of record of output file
					//loop through all cohorts within a particular gridgrid cell
					int irec = 0;	//start from the first record id
					while(irec < ttlnumGridRec){
						ChtRec = chtin.getInitGrdRecID(dir4files, grdid, irec);

						if (ChtRec >= 0){

							proccht.GetCht(dir4files, ChtRec);
							Nodes* chtlist = new Nodes;
							chtlist = NULL;		//define the first list node

							chtlist = dlist.InsertDode(chtlist, pt);

							if(year % 1 == 0){

								bthmkst = 1;
							}
							else{

								bthmkst = 0;
							}

							//loop through the current chtlist to examine if a new cohort is initiated, add it to newlist in each year.

							if(bthmkst == 1){

								Nodes* newchtlist = new Nodes;
								newchtlist = NULL;

								newchtlist = thmkst.Initiation(newchtlist,chtlist,maxchtid);

								thmkst.ChtCombin(chtlist,newchtlist);

							}else{

								cout<<"The year is not an initiation year."<<endl;

							}

							//After a year, add 1 to all old and new cohorts ages previous
							chtlist = thmkst.AddChtAge(chtlist);

							/*
							bool blist;
							blist = 0;
							if (blist){
								//list the list data
								Nodes* llist = new Nodes;
								llist = chtlist;
								int No=0;
								cout<<endl<<"3333333333 In current year "<<year<<" after adding nodes in chtlist, grdID = "<<llist->grdID<<endl;
								while (llist != NULL ){


										cout<<endl<<"grdID = "<<llist->grdID<<"			cht No.= "<<No<<endl
											<<"plist->grdID = "<<llist->grdID<<endl
											<<"cohortid = "<<llist->cohortid<<endl
											<<"vegtype = "<<llist->vegtype<<endl
											<<"age = "<<llist->age<<endl
											<<"proportion = "<<llist->proportion<<endl
											<<"flag = "<<llist->flag<<endl;

										llist = llist->pNext;
										No +=1;
								}

								//getchar();
							}
							*/

							Nodes* plist = new Nodes;
							plist = NULL;
							plist = chtlist;
							while(plist != NULL){

								outputr.OutputCht(s_Dir, grdid, year, plist, tRecid);
								tRecid +=1;

								plist = plist->pNext;

								//getchar();
							}


						}else{

							//cout<<"The Rec id not the one needed"<<endl;
						}

						irec += 1;
					}


					//////////////////////////////////
					//close output files and move to the next grid
					pred.PredFile->close();
					outputr.ChtFile->close();
					cout<<endl<<"grid = "<<grdid<<" year done = "<<year<<endl;


				}else if( year > ystart){

					cout<<"		year = "<<year<<endl;
					//getchar();

					//get the num_vales of variable gridid in "TNNinichtnew.nc"
					int ttlnumGridRec = chtin.getNumValsRec(s_Dir, grdid, year);

					long tRec = 0;	//control of record of output file

					chtin.InitChtFile(s_Dir,grdid,year);

					////////////////////////////////////////////////////
					//loop through all cohorts within a particular gridgrid cell

					int irec = 0;	//start from the first record id

					while(irec < ttlnumGridRec){

						//get the cht rec id and data from previous .nc and return the rec when gididv=grdid and move on to next one which meet the if condition

						ChtRec = chtin.getGrdRecID(s_Dir, grdid, year, irec);

						if (ChtRec >= 0){

							proccht.GetCht(s_Dir, grdid, year, irec);  //proccht class, read data into IODATA

							Nodes* chtlist = new Nodes;
							chtlist = NULL;
							chtlist = dlist.InsertDode(chtlist, pt);
							if(year % 1 == 0){

								bthmkst = 1;
							}
							else{

								bthmkst = 0;
							}

							//loop through the current chtlist to examine if a new cohort is initiated, add it to newlist in each year.

							if(bthmkst == 1){

								Nodes* newchtlist = new Nodes;
								newchtlist = NULL;
								newchtlist = thmkst.Initiation(newchtlist,chtlist,maxchtid);

								thmkst.ChtCombin(chtlist,newchtlist);

							}else{

								cout<<"The year is not an initiation year."<<endl;

							}

							//After a year, add 1 to all old and new cohorts ages
							chtlist = thmkst.AddChtAge(chtlist);

							//output the result of current cht and move on to the next
							Nodes* plist = new Nodes;
							plist = chtlist;
							while(plist != NULL){

								outputr.OutputCht(s_Dir, grdid, year, plist, tRec);
								plist = plist->pNext;

								tRec +=1;
							}


						}else{

							cout<<"The Rec id is not the one needed"<<endl;
						}

						irec += 1;		//move to next cohort rec


					}


					////

					pred.PredFile->close();

					outputr.ChtFile->close();

				}else{

					cout<<"Year setting is not correct for current grid cell"<<endl;	//move to next grid cell
				}


				/*	//chtin
				chtprop.LatLonFile->close();
				chtprop.PropFile->close();
				chtprop.PropFilet4->close();
				chtprop.PropFilet5->close();
				chtprop.Propfilet1->close();
				chtprop.Propfilet10->close();
				chtprop.Propfilet2->close();
				chtprop.Propfilet3->close();
				chtprop.Propfilet4->close();
				chtprop.Propfilet5->close();
				chtprop.Propfilet9->close();
			 	 */

				///////////delete old file
				if (year > ystart)
					delfile.delFile(s_Dir, grdid, year);

				grdid += 1;

		}

		year += 1;

	}

};

void Runner::SetPointer(IOdata* pointer){

	ioptr = pointer;
};

