#pragma once
#include<vector>
#include <iostream>
using namespace std;

vector<double> random_sort(vector<double> array);//�������һά����
vector<vector<double>> random_sort_N_D(vector<vector<double>> d); //������򣬶�ά���飬�����������ڵ����ݽ�������

vector<vector<double>> u_lhs(int N, vector<vector<double>> bounds); //�ڲ���ʼ��������������������
vector<vector<double>> lhs(int N, vector<vector<double>> bounds); //����������������������

