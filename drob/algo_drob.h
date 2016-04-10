#include "drob.h"
#include <vector>

class algo_drob
{
public:
	std::vector<drob>* calc(const double &val, const double &_error, std::vector<drob> * mass)
	{
		if (val < 3.0e-10 || val > 4.0e+10 || _error < 0.0)
		{
			throw "Uncorrected value(s)";
		}
		result = mass;
		d = D = 1;
		n = (int)val;
		N = n + 1;
		error = _error;
		v = val;
		three();
		return result;
	}
	
	void one() 
	{
		if (r > 1.0)
		{
			two();
		}
		else
		{
			r = 1.0 / r;
			two();
		}
	}
	void two()
	{
		N += n*(int)r;
		D += d*(int)r;
		n += N;
		d += D;
		three();
	}
	void three()
	{
		r = 0.0;
		if (v*d == (double)n)
		{
			four();
		}
		r = (N - v*D) / (v*d - n);
		if (r > 1.0)
		{
			four();
		}
		else
		{
			t = N;
			N = n;
			n = t;
			t = D;
			D = d;
			d = t;
			four();
		}
		
	}
	void four()
	{
		//std::cout << n << "/" << d<<"  ";
		//printf("%d/%d", *n, *d);
		epsilon = 1.0 - n / (v*d);
		if (epsilon <= error)
		{
			six();
		}
		else
		{
			m = 1.0;
			do
			{
				m *= 10.0;
			} while (m*epsilon < 1.0);
			epsilon = 1.0 / m * ((int)(0.5 + m*epsilon));
			six();
		}
		
	}
	void six()
	{
		drob dr(n, d, epsilon);
		//printf("	 %e\n", epsilon);
		//std::cout << "epsilon =" << epsilon << std::endl;
		(*result).push_back(dr);
		//std::cout << (*result).size() << std::endl;

		if (r != 0.0 && epsilon > error)
		{

			one();
		}
		/*
		if (epsilon <= error)
		{
			return;

		}
		//*/
		
	}
private:
	//int D, N, t;
	//double  r;// m,
	std::vector<drob> *result;
	int D, N, t,n, d;
	double _chis, _znam, error, v, epsilon, r, m;
};
