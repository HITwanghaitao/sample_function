#pragma once
#pragma warning(disable:4996)
#include<vector>
#include<cmath>
#include<iostream>
#include <algorithm>
#include<vector>
#include<random>
#include<fstream>
# include <cstdlib>
# include <iomanip>
# include <ctime>
# include <cstring>
#include <iomanip>       //C++输出精度控制需要
#include <string>

using namespace std;

double gaussrand();//标准正态分布
double gaussrand_u_sigma(double u, double sigma);//生成特定u,sigma正态分布
vector<vector<double>> norm_sample(int N, vector<vector<double>> bounds);//正态分布抽样，每列参数符合一定分布