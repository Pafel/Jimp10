#include "splines_t.h"
#include "points.h"

#include <stdio.h>
#include <math.h>

#define PI 3.14

void make_spl (points_t * pts, spline_t * spl)
{
	int i, j, m;
	int n = pts->n;
	int nd = (double)n;
	if (n % 2 == 1)
		m = (n-1)/2-1;
	else 
		m = n/2-1;

	if (alloc_spl(spl, pts->n) == 0) {
		spl->x = pts->x;
		spl->y = pts->y;
	
		spl->a[0] = 0.0;
		spl->b[0] = 0.0;

		for (i = 1 ; i < n ; i++)
			spl->a[0] += spl->y[i];

		spl->a[0] /= nd;
		
		for (i=1 ; i <= m ; i++) {
			spl->a[i] = 0.0;
			spl->b[i] = 0.0;

			for(j = 1; j < n ; j++) {
				spl->a[i] += spl->y[j]*cos(2*PI*i*j/nd);
				spl->b[i] += spl->y[j]*sin(2*PI*i*j/nd);
			}

		spl->a[i] *= 2.0/nd;
		spl->b[i] *= 2.0/nd;
		}
	}
}
