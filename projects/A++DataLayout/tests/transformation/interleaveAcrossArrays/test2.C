#include "simpleA++.h"
#include "stdio.h"
//#define BOUNDS_CHECK 1

#define N 10

int main(int argc, char** argv) {

	doubleArray A(N);
	A = 0;
	doubleArray B(N);
	Range I(0, N - 1, 1);

	//B = 2;

	A(I) = A(I) + B(I);

	//A.display(" This is object of A");

	return 0;
}
