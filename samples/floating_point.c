#include "custom_math.h"
#include <criterion/criterion.h>
#include <criterion/new/assert.h>

Test(sqrt,trqs0) {
	cr_assert(eq(dbl,my_sqrt(0),0));
}

Test(sqrt,trqs1) {
	cr_assert(eq(dbl,my_sqrt(4),2));
}

Test(sqrt,trqs2) {
	cr_expect(eq(dbl,my_sqrt(-9),-1),"Square root cannot be negative!");
}

Test(sqrt,trqs3) {
	cr_expect(epsilon_eq(dbl,my_sqrt(2.0),1.4141,0.01));
}

Test(factorial,factorial0) {
	cr_assert(eq(llong,factorial(0),1));
}

Test(factorial,factorial1) {
	cr_assert(eq(llong,factorial(5),120));
}

Test(factorial,factorial2) {
	cr_assert(eq(llong,factorial(-1),1));
}

Test(factorial,factorial3) {
	cr_expect(eq(llong,factorial(15),1307674368000),"It won't overflow!");
}

Test(pow,pow0) {
	cr_expect(eq(int,my_pow(0,0),-1),"There is no such thing!");
}

Test(pow,pow1) {
	cr_assert(eq(int,my_pow(2,2),4));
}

Test(pow,pow2) {
	cr_expect(eq(dbl,my_pow(2,-2),0.25), "That one is easy, is it not?");
}

Test(pow,pow3) {
	cr_assert(epsilon_eq(dbl,my_pow(2.5,2),6.25,0.00001));
}

Test(sin,sin0) {
	cr_assert(epsilon_eq(dbl,my_sin(0),0,0.00001));
}

Test(sin,sin1) {
	cr_assert(epsilon_eq(dbl,my_sin(90*M_PI/180.0),1.0,0.00001));
}

Test(sin,sin2) {
	cr_assert(epsilon_eq(dbl,my_sin(30*M_PI/180.0),0.5,0.00001));
}

Test(sin,sin3) {
	cr_expect(epsilon_eq(dbl,my_sin(360.0*M_PI/180.0),my_sin(0),0.00001),"We have done a full circle.");
}

Test(cos,cos0) {
	cr_assert(epsilon_eq(dbl,my_cos(0),1,0.00001));
}

Test(cos,cos1) {
	cr_assert(epsilon_eq(dbl,my_cos(60 * M_PI/180.0),0.5,0.00001));
}

Test(cos,cos2) {
	cr_expect(epsilon_eq(dbl,my_cos(360 * M_PI / 180.0),my_cos(0),0.00001),"We have done a full circle.");
}

Test(Trigonometric_identity,T0) {
	cr_assert(epsilon_eq(dbl,my_pow(my_cos(0),2) + my_pow(my_sin(0),2), 1.0, 0.00001));
}

Test(Trigonometric_identity,T1) {
	cr_assert( epsilon_eq( dbl, my_pow( my_cos( 60 * M_PI / 180.0 ), 2)
				+ my_pow( my_sin( 60 * M_PI / 180.0), 2 ), 1.0, 0.00001 ));
}
