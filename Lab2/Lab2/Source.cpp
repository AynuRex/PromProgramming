#include <iostream>
#include "Header.h"
using namespace std;

int main()
{
	double a, b, c, d, e, f;
	std::cout << "Enter coefficients of linear equations\n";
	
	cin >> a>> b >> c >> d >> e >> f;

	if ((a == 0) && (b == 0) && (c == 0) && (d == 0) && (e == 0) && (f == 0))
	{
		cout << '5';
	}

	else if ((a * d - c * b != 0) && ((e * d - b * f != 0) || (a * f - c * e != 0)))
	{
		double y = getY_case2(a, b, c, d, e, f);
		double x = getX_case2(a, b, c, d, e, f);
		cout << "2 " << x << ' ' << y;
	}

	else if (((a * d - c * b == 0) && ((e * d - b * f != 0) || (a * f - c * e != 0))) ||
		(a == 0 && c == 0 && e / b != f / d) ||
		(b == 0 && d == 0 && e / a != f / c) ||
		(a == 0 && b == 0 && c == 0 && d == 0 && (e / f > 0))){
		if (((a == 0 && b == 0 && e == 0 && d != 0 && c == 0) ||
			(c == 0 && d == 0 && f == 0 && b != 0 && a == 0)))
		{

			double y = getY_case4_1(a, b, c, d, e, f);
			cout << '4' << ' ' << y;
		}
		else if (((a == 0 && b == 0 && e == 0 && c != 0 && d == 0) ||
			(c == 0 && d == 0 && f == 0 && a != 0 && b == 0)))
		{
			double x = getX_case3_1(a,b,c,d,e,f);		
			cout << '3' << ' ' << x;
		}
		else
			cout << '0';
	}

	else if (a == 0 && c == 0)
	{
		double y = getY_case4_2(a,b,c,d,e,f);		
		cout << '4' << ' ' << y;
	}

	else if (b == 0 && d == 0)
	{
		double x = getX_case3_2(a,b,c,d,e,f);		
		cout << '3' << ' ' << x;
	}
	
	else
	{
		double k = 0, n = 0;;
		bool is_correct = case1(a, b, c, d, e, f, f, n);
		if(is_correct)	
		{
			cout << '1' << ' ' << k << ' ' << n;
		}
		else
		{
			cout << "Are you kidding me?";
		}
	}
	return 0;
}


