#include "libakh.h"
#define TRUE	1
#define FALSE	0

int dateplusdays(int date, int plusdays)
{
	const int days[2][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
	int leap = FALSE;
	int plusflag = TRUE;	
	int y, m, d;

	if (99991231 < date || date < 10000) {
		return -1;
	} else {
		y = date / 10000;
		m = date / 100 - 100 * y;
		d = date - 10000 * y - m * 100;				
	}

begin:
	if (plusflag)
		d += plusdays;

	if (y % 4 == 0 && !(y % 100 == 0 && y % 400 != 0))
		leap = TRUE;

	while(d > days[leap][m - 1]) {
		d -= days[leap][m - 1];
		m++;
		if (m > 12) {
			m = 1;
			y++;
			plusflag = FALSE;
			goto begin;
		}
	}

	return 10000 * y + 100 * m + d;
}
