#include <iostream>

class drob
{
public:

	drob(const unsigned int &chis, const unsigned int &znam, const double &epsilon) //calss drob
	{
		_chis = chis;
		_znam = znam;
		_epselon = epsilon;
	}
	friend std::ostream & operator<<(std::ostream &output, const drob &val)
	{
		output << val._chis << "/" << val._znam << " epsilon = " << val._epselon;
		return output;
	}

	
protected:

	unsigned int _chis; //chislitel
	unsigned int _znam; //znamenatel
	double _epselon;
	
	

};
