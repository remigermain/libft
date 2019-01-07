#include <stdio.h>
#include "ft_printf.h"
#include <math.h>

int main()
{
	int a = 0;

long double f1 = 48656568.256479123456789123456789;


double f2 = 456.45366;

double f3 = 456.45362;
	

	a = printf("float11   :%8f|", 12.34 );
	printf("pf = %d\n", a);
	a = ft_printf("float11   :%8g|", 12.34 );
	printf("ft = %d\n", a);
	a = printf("float12   :%8g|", 1234.5678 );
	printf("pf = %d\n", a);
	a = ft_printf("float12   :%8g|", 1234.5678 );
	printf("ft = %d\n", a);
	a = printf("float13   :%8g|", 0.0478 );
	printf("pf = %d\n", a);
	a = printf("float13   :%8g|", 0.0478 );
	printf("ft = %d\n", a);
	a = printf("float14   :%8g|", 422121.0 );
	printf("pf = %d\n", a);
	a = printf("float14   :%8g|", 422121.0 );
	printf("ft = %d\n", a);
	a = printf("float15   :%8g|", 422121234.345345 );
	printf("pf = %d\n", a);
	a = printf("float15   :%8g|", 422121234.345345 );
	printf("ft = %d\n\n", a);



	printf("float16   :%.0f|",  1000.123456789123456789 );
	printf("pf = %d\n", a);
	ft_printf("float16   :%.0f|",  1000.123456789123456789 );
	printf("ft = %d\n", a);
	printf("float17   :%.1f|",  2000.123456789123456789 );
	printf("pf = %d\n", a);
	ft_printf("float17   :%.1f|",  2000.123456789123456789 );
	printf("ft = %d\n", a);
	printf("float18   :%.2f|",  3000.123456789123456789 );
	printf("pf = %d\n", a);
	ft_printf("float18   :%.2f|",  3000.123456789123456789 );
	printf("ft = %d\n", a);
	printf("float19   :%.10f|", 4000.123456789123456789 );
	printf("pf = %d\n", a);
	ft_printf("float19   :%.10f|", 4000.123456789123456789 );
	printf("ft = %d\n", a);
	printf("float20   :%.30f|", 5000.123456789123456789 );
	printf("pf = %d\n", a);
	ft_printf("float20   :%.30f|", 5000.123456789123456789 );
	printf("ft = %d\n", a);
	printf("float21   :%f|",    6000.123456789123456789 );
	printf("pf = %d\n", a);
	ft_printf("float21   :%f|",    6000.123456789123456789 );
	printf("ft = %d\n\n", a);



	printf("float3    :%7.3f", 1.2345);
	printf("pf = %d\n", a);
	ft_printf("float3    :%7.3f", 1.2345);
	printf("ft = %d\n\n", a);
	printf("float3bis :%7.3lf",4865.256479 );
	printf("pf = %d\n", a);
	ft_printf("float3bis :%7.3lf",4865.256479 );
	printf("ft = %d\n\n", a);
	printf("float4    :%10.3f", 1.2345e3);
	printf("pf = %d\n", a);
	ft_printf("float4    :%10.3f", 1.2345e3);
	printf("ft = %d\n\n", a);
	printf("float5    :%10.3f", 1.2345e7);
	printf("pf = %d\n", a);
	ft_printf("float5    :%10.3f", 1.2345e7);
	printf("ft = %d\n\n", a);
	printf("float6    :%12.4e", 1.2345);
	printf("pf = %d\n", a);
	ft_printf("float6    :%12.4e", 1.2345);
	printf("ft = %d\n\n", a);
	printf("float7    :%12.4e", 123.456789e8);
	printf("pf = %d\n", a);
	ft_printf("float7    :%12.4e", 123.456789e8);
	printf("ft = %d\n\n", a);
	printf("float8    :%15.5lf",48656568.256479 );
	printf("pf = %d\n", a);
	ft_printf("float8    :%15.5lf",48656568.256479 );
	printf("ft = %d\n\n", a);
	printf("float9    :%15.6lf",48656568.256479 - 48656568.256478 );
	printf("pf = %d\n", a);
	ft_printf("float9    :%15.6lf",48656568.256479 - 48656568.256478 );
	printf("ft = %d\n\n", a);
	printf("float9bis :%15.2lf",f2*f3 );
	printf("pf = %d\n", a);
	ft_printf("float9bis :%15.2lf",f2*f3 );
	printf("ft = %d\n\n", a);

	printf("LONG DOUBLE  :%Lf - %20.10Lf - %20.15Lf - %20.20Lf - %30.30Lf", f1,  f1, f1, f1, f1);
	printf("pf = %d\n\n", a);
	printf("LONG DOUBLE  :%Lf - %20.10Lf - %20.15Lf - %20.20Lf - %30.30Lf", f1,  f1, f1, f1, f1);
	printf("ft = %d\n\n", a);
	printf("float2    :%4.2f %+.0e %E ", 3.1416, 3.1416, 3.1416);
	printf("pf = %d\n\n", a);
	printf("float2    :%4.2f %+.0e %E ", 3.1416, 3.1416, 3.1416);
	printf("ft = %d\n\n", a);










	return (0);
}
