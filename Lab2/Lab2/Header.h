#pragma once

inline double getX_case2(const double a, const double b, const double c, const double d, const double e, const double f){return (d * e - b * f) / (d * a - b * c);}
inline double getY_case2(const double a, const double b, const double c, const double d, const double e, const double f) {return (a * f - c * e) / (a * d - c * b);}
inline double getY_case4_1(const double a, const double b, const double c, const double d, const double e, const double f){
	if (b == 0)
		return  f / d;
	else if (d == 0)
		return e / b;
	else if (e == 0 || f == 0)
		return 0;	
}
inline double getY_case4_2(const double a, const double b, const double c, const double d, const double e, const double f) {
	if (e == 0)
		return f / d;
	else if (f == 0)
		return e / b;
	else
		return e / b;
}
inline double getX_case3_1(const double a, const double b, const double c, const double d, const double e, const double f) {
	if (a == 0)
		return  f / c;
	else if (c == 0)
		return e / a;
	else if (e == 0 || f == 0)
		return 0;
}
inline double getX_case3_2(const double a, const double b, const double c, const double d, const double e, const double f) {
	if (e == 0)
		return f / c;
	else if (f == 0)
		return e / a;
	else
		return e / a;
}
bool case1(const double a, const double b, const double c, const double d, const double e, const double f, double& k, double& n)
{
	if (b == 0 && e == 0)
	{	
	k = -c / d;
	n = f / d;
	return true;
	}

	else if (d == 0 && f == 0)
	{
	k = -a / b;
	n = e / b;
	return true;
	}

	else if (a == 0 && e == 0)
	{	
	k = -d / c;
	n = f / c;
	return true;
	}

	else if (c == 0 && f == 0)
	{	
	k = -b / a;
	n = e / a;
	return true;
	}
	else if ((a / b == c / d))
	{	
	k = -c / d;
	n = f / d;
	return true;
	}
	return  false;
}

