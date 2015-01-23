#ifndef SPLINES_H
#define SPLINES_H

#include "points.h"

#include <stdio.h>
#include <math.h>

typedef struct {
		int n;
		double *x;
		double *y;
		double *a;
		double *b;
} spline_t;

int alloc_spl_tan( spline_t *spl, int n );

int  read_spl_tan ( FILE *inf,  spline_t *spl );

void  write_spl_tan ( spline_t *spl, FILE * ouf );

double value_spl_tan( spline_t *spl, double x );

#endif
