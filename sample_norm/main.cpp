#include "Norm_Sample.h"
#include <iostream>
using namespace std;

void test()
{
	vector<vector<double>> r;
	int N = 500;
	vector<vector<double>> bounds = { {0.2,0.6},{1.5,2.5},{0.03,0.05},{0.02,0.05},{1.0,1.2} };
	r = norm_sample(N, bounds);
}
int main()
{
	test();
}