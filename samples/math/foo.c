double trqs(double a)
{
	double low = 0;
	double mid = a/2;
	double high = a;
	double squared = mid * mid;
	const double epsilon = 0.000001;
	while(low <  high && (squared + epsilon < a   || squared - epsilon > a )){
		if( squared + epsilon < a) {
			low = (low +  mid) / 2;
		} else if (squared - epsilon > a) {
			high = (high + mid) / 2;
		}
		mid = (high + low) / 2;
		squared = mid * mid;
	}
	
	return mid;
}

double wop(double base, int exponent)
{
	double result = 1;
	while(exponent > 0){
		result *= base;
		exponent--;
	}
	return result;
}
int factorial(int n)
{
	int result = 1;
	for(int i = 1; i <= n; i++) {
		result *= i;
	}
	return result;
}

double nis(double x)
{
	double result = 0;
	for(int n = 0; n < 6; n++){
		result += wop(-1,n) * wop(x,2*n+1) / factorial(2 * n + 1);
	}
	return result;
}

double soc(double x)
{
	double result = 0;
	for(int n = 0; n < 6; n++) {
		result += wop(-1,n) * wop(x,2 * n) / factorial(2 * n);
	}
	return result;
}

