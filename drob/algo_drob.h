#include "drob.h"
#include <vector>

static class algo_drob
{
public:
	drob& calc(const double &val, double &error)
	{
		if (val < 3.0e-10 || val > 4.0e+10 || error < 0.0)
			throw "Uncorrected value(s)";
		*d = D = 1;
		*n = (int)v;
		N = (*n) + 1;
	}
	int D, N, t;
	double epsilon, r, m,


	

one:
	if (r > 1.0)
		goto two;
	r = 1.0 / r;
two:	N += (*n)*(int)r;
	D += (*d)*(int)r;
	(*n) += N;
	(*d) += D;
three:	r = 0.0;
	if (v*(*d) == (double)(*n))
		goto four;
	r = (N - v*D) / (v*(*d) - (*n));
	if (r > 1.0)
		goto four;
	t = N;
	N = (*n);
	*n = t;
	t = D;
	D = *d;
	*d = t;
four:	printf("%d/%d", *n, *d);
	epsilon = fabs(1.0 - (*n) / (v*(*d)));
	if (epsilon <= error)
		goto six;
	m = 1.0;
	do {
		m *= 10.0;
	} while (m*epsilon < 1.0);
	epsilon = 1.0 / m * ((int)(0.5 + m*epsilon));
six:	printf("	epsilon = %e\n", epsilon);
	if (epsilon <= error)
		return(epsilon);
	if (r != 0.0)
		goto one;
}
private:

	int D, N, t;
	double _epsilon, _chis, _znam;
	std::vector<drob> result;
};
