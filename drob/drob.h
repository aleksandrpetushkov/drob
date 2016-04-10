#include <iostream>
//#include "algo_drob.h"

class drob
{
public:
	//drob();

	drob(const unsigned int &chis, const unsigned int &znam, const double &epsilon)
	{
		_chis = chis;
		_znam = znam;
		_epselon = epsilon;
	}
	friend std::ostream & operator<<(std::ostream &output, const drob &val)
	{
		output << val._chis << "/" << val._znam << " epsilon = " << val._epselon << std::endl;
		return output;
	}

	
protected:

	unsigned int _chis; //chislitel
	unsigned int _znam; //znamenatel
	double _epselon;
	
	

};
