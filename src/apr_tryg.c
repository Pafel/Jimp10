#include <math.h>
#include <stdlib.h>

#include "points.h"
#include "splines_t.h"

#define PI 3.14

int factor (int m , double *a , double *b, points_t p);

double mainfactor (points_t p);

double make_spl (points_t p , spline_t spl)
{
	int m = (p.n-1)/2 - 1;

	double ao = mainfactor ( p );
	double a[m];
	double b[m];

	int i;

	for (i = 0 ; i < p.n ; i++)
		spl.x[i] = p.x[i];
}

int factor (int m , double *a ,double *b, points_t p)
{
	int i, j;

	for (i = 0 ; i < m ; i++) {
		for (j = 0 ; j < m ; j++) {
			a[i] += p.y[j] * sin((2*PI*i*j)/p.n);
			b[i] += p.y[i] * cos((2*PI*i*j)/p.n);
		}
	a[i] *= 2/p.n;
	b[i] *= 2/p.n;
	}
return 0;
}

double mainfactor (points_t p)
{
	int i;
	double ao = 0;

	for (i = 0 ; i < p.n ; i++) {
		double ao = ao + p.y[i];
	}

	ao /= p.n;

	return ao;
}
