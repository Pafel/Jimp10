#include "splines_t.h"
#include "points.h"

#include <stdio.h>
#include <math.h>

void make_tryg (points_t * pts, spline_t * spl)
{
	int i, j, m;
	int n = pts->n;
	double p = 2*M_PI/n;

	if (n % 2 == 1)
		m = (n-1)/2;
	else
		m = n/2;

	if (alloc_spl(spl, pts->n) == 0) {
		spl->x = pts->x;
		spl->y = pts->y;

		for (i=0 ; i <= m ; i++) {
			spl->a[i] = 0.0;
			spl->b[i] = 0.0;
				for(j = 0; j < n ; j++) {
					spl->a[i] += spl->y[j]*cos(p*i*j);
					spl->b[i] += spl->y[j]*sin(p*i*j);
				}
			spl->a[i] *= 2.0/n;
			spl->b[i] *= 2.0/n;
		}
	}
}
