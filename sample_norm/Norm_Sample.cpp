#include "Norm_Sample.h"

using namespace std;
double gaussrand()//标准正态分布
{
	static double V1, V2, S;
	static int phase = 0;
	double X;

	if (phase == 0) {
		do {
			double U1 = (double)rand() / RAND_MAX;
			double U2 = (double)rand() / RAND_MAX;

			V1 = 2 * U1 - 1;
			V2 = 2 * U2 - 1;
			S = V1 * V1 + V2 * V2;
		} while (S >= 1 || S == 0);

		X = V1 * sqrt(-2 * log(S) / S);
	}
	else
		X = V2 * sqrt(-2 * log(S) / S);

	phase = 1 - phase;

	return X;
}

double gaussrand_u_sigma(double u, double sigma)
{
	return sigma * gaussrand() + u;
}

vector<vector<double>> norm_sample(int N, vector<vector<double>> bounds) //正态分布抽样，每列参数符合一定分布
{
	int D = bounds.size();
	vector<vector<double>> r(N, vector<double>(D));
	for (int j = 0; j < D; j++)
	{
		double mu = (bounds[j][0] + bounds[j][1]) / 2;
		double sigma = (bounds[j][1] - bounds[j][0]) / 4;
		vector<double> temp(N);
		for (int k = 0; k < N; k++)
		{
			r[k][j] = gaussrand_u_sigma(mu, sigma);
		}
	}
	/*
	for (int j = 0; j < N; j++)
	{
		for (int k = 0; k < D; k++)
		{
			cout << r[j][k] << '\t';
		}
		cout << endl;
	}
	*/
	return r;
}