#ifndef IODATA_H_
	#define IODATA_H_

	class IOdata{

		public:
			IOdata();
			~IOdata();

			//input data
			int predgrdid;
			int predfrost;
			int predlowland;
			int predgiv;
			int predwetland;

			float predisposed;
			int predFlag;

			int year;
			int ingrdid;
			int inparentid;
			int incohortid;
			int invegtype;
			int inage;
			float inproportion;
			int inflag;


			//intermediate

			//output data

			int outgridid;
			int outcohortid;
			int outvegetype;
			int outage;
			float outproportion;
			int outflag;

			//for the areas of types3,4,5,1,2,9
			double area3;
			double area4;
			double area5;
			double area1;
			double area2;
			double area9;
			double area10;


			void initlz();

	};

#endif /*IODATA_H_*/
