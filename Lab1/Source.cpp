#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void fill_matrix_from_console(int** matrix, int n, int m);
void fill_matrix_by_copy(int** filling_matrix, int** filled_matrix, int n, int m);
void fill_matrix_using_random(int** matrix, int n, int m);
void output_matrix_to_console(int** matrix, int n, int m);


void main()
{
	srand(time(NULL));
	int n1, m1, n2, m2, k, l = 2;
	system("chcp 1251");
	cout << "��� ������������ ���������" << endl <<
		"�������� ������������ ������ ������� ���������\n\n";

	///////////////////////////////////////////////////////////////////////////////
	////////////////////���� �������� ������� �������������////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	do
	{
		cout << "������� ������� ������ �������\n";
		cin >> n1 >> m1;
	} while (n1 <= 0 || m1 <= 0);
	do
	{
		cout << "������� ������� ������ �������\n";
		cin >> n2 >> m2;
	} while (n2 <= 0 || m2 <= 0);

	int** M1 = new int* [n1];
	int** M2 = new int* [n2];
	for (int i = 0; i < n1; i++)
		M1[i] = new int[m1];
	for (int i = 0; i < n2; i++)
		M2[i] = new int[m2];

	///////////////////////////////////////////////////////////////////////////////
	////////////////����� ������� ���������� � ���������� ������///////////////////
	///////////////////////////////////////////////////////////////////////////////

	do
	{
		cout << "�������� ������ ���������� ������\n" <<
			"1 - ������� \n2 - ��������� �������\n";
		cin >> k;
	} while (k < 1 || k > 2);
	switch (k)
	{
	case 1:
		fill_matrix_from_console(M1, n1, m1);
		fill_matrix_from_console(M2, n2, m2);		
		cout << "\n������� 1\n\n";
		output_matrix_to_console(M1, n1, m1);
		cout << "\n������� 2\n\n";
		output_matrix_to_console(M2, n2, m2);
		break;
	case 2:
		fill_matrix_using_random(M1, n1, m1);
		fill_matrix_using_random(M2, n2, m2);
		cout << "\n������� 1\n\n";
		output_matrix_to_console(M1, n1, m1);
		cout << "\n������� 2\n\n";
		output_matrix_to_console(M2, n2, m2);
		break;
	}

	///////////////////////////////////////////////////////////////////////////////
	/////////////////���������� ������ � ���������� �������////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	while (l < n1 || l < n2 || l < m1 || l < m2)
		l *= 2;
	int** M3 = new int* [l];
	int** M4 = new int* [l];

	
	for (int i = 0; i < l; i++)
	{
		M3[i] = new int[l];
		M4[i] = new int[l];
		for (int j = 0; j < l; j++)
		{
			M3[i][j] = 0;
			M4[i][j] = 0;
		}
	}
	fill_matrix_by_copy(M3, M1, n1, m1);
	fill_matrix_by_copy(M4, M2, n2, m2);	
	cout << "����������� �������\n";
	cout << "\n������� 1\n\n";
	output_matrix_to_console(M3, l, l);	
	cout << "\n������� 2\n\n";
	output_matrix_to_console(M4, l, l);
	

	///////////////////////////////////////////////////////////////////////////////
	///////////////��������� ������ �� ���������� � �� ����������//////////////////
	///////////////////////////////////////////////////////////////////////////////

	int** mat1 = new int* [l / 2];
	int** mat2 = new int* [l / 2];
	int** mat3 = new int* [l / 2];
	int** mat4 = new int* [l / 2];
	int** mat5 = new int* [l / 2];
	int** mat6 = new int* [l / 2];
	int** mat7 = new int* [l / 2];
	int** mat8 = new int* [l / 2];
	int** mat9 = new int* [l / 2];
	int** mat10 = new int* [l / 2];
	int** mat11 = new int* [l / 2];
	int** mat12 = new int* [l / 2];
	
	int** p1 = new int* [l / 2];
	int** p2 = new int* [l / 2];
	int** p3 = new int* [l / 2];
	int** p4 = new int* [l / 2];
	int** p5 = new int* [l / 2];
	int** p6 = new int* [l / 2];
	int** p7 = new int* [l / 2];
	for (auto i = 0; i < l / 2; i++)
	{
		mat1[i] = new int[l / 2];
		mat2[i] = new int[l / 2];
		mat3[i] = new int[l / 2];
		mat4[i] = new int[l / 2];
		mat5[i] = new int[l / 2];
		mat6[i] = new int[l / 2];
		mat7[i] = new int[l / 2];
		mat8[i] = new int[l / 2];
		mat9[i] = new int[l / 2];
		mat10[i] = new int[l / 2];
		mat11[i] = new int[l / 2];
		mat12[i] = new int[l / 2];

		p1[i] = new int[l / 2];
		p2[i] = new int[l / 2];
		p3[i] = new int[l / 2];
		p4[i] = new int[l / 2];
		p5[i] = new int[l / 2];
		p6[i] = new int[l / 2];
		p7[i] = new int[l / 2];
		
		for (auto j = 0; j < l / 2; j++)
		{
			mat1[i][j] = M3[i][j];
			mat2[i][j] = M3[i][j + l / 2];
			mat3[i][j] = M3[i + l / 2][j];
			mat4[i][j] = M3[i + l / 2][j + l / 2];
			mat5[i][j] = M4[i][j];
			mat6[i][j] = M4[i][j + l / 2];
			mat7[i][j] = M4[i + l / 2][j];
			mat8[i][j] = M4[i + l / 2][j + l / 2];
		}
	}
	///////////////////////////////////////////////////////////////////////////////
	////////////////////���������� �������� ������������� ������///////////////////
	///////////////////////////////////////////////////////////////////////////////

	for (int i = 0; i < l / 2; i++)
	{
		for (int j = 0; j < l / 2; j++)
		{
			p1[i][j] = 0;
			p2[i][j] = 0;
			p3[i][j] = 0;
			p4[i][j] = 0;
			p5[i][j] = 0;
			p6[i][j] = 0;
			p7[i][j] = 0;
			for (int z = 0; z < l / 2; z++)
			{
				p1[i][j] += (mat1[i][z] + mat4[i][z]) * (mat5[z][j] + mat8[z][j]);
				p2[i][j] += (mat3[i][z] + mat4[i][z]) * mat5[z][j];
				p3[i][j] += mat1[i][z] * (mat6[z][j] - mat8[z][j]);
				p4[i][j] += mat4[i][z] * (mat7[z][j] - mat5[z][j]);
				p5[i][j] += (mat1[i][z] + mat2[i][z]) * mat8[z][j];
				p6[i][j] += (mat3[i][z] - mat1[i][z]) * (mat5[z][j] + mat6[z][j]);
				p7[i][j] += (mat2[i][z] - mat4[i][z]) * (mat7[z][j] + mat8[z][j]);
			}

		}
	}

	///////////////////////////////////////////////////////////////////////////////
	////////////������� �������� ��������������� ������ �� �������������///////////
	///////////////////////////////////////////////////////////////////////////////

	for (int i = 0; i < l / 2; i++)
	{
		for (int j = 0; j < l / 2; j++)
		{
			mat9[i][j] = p1[i][j] + p4[i][j] - p5[i][j] + p7[i][j];
			mat10[i][j] = p3[i][j] + p5[i][j];
			mat11[i][j] = p2[i][j] + p4[i][j];
			mat12[i][j] = p1[i][j] - p2[i][j] + p3[i][j] + p6[i][j];
		}
	}

	///////////////////////////////////////////////////////////////////////////////
	///////////////////�������� �������������� �������/////////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	int** M5 = new int* [l];
	for (int i = 0; i < l; i++)
	{
		M5[i] = new int[l];
	}

	///////////////////////////////////////////////////////////////////////////////
	///////��������� ���������� �� ��������������� ������ � ��������������/////////
	///////////////////////////////////////////////////////////////////////////////

	for (int i = 0; i < l / 2; i++)
	{
		for (int j = 0; j < l / 2; j++)
		{
			M5[i][j] = mat9[i][j];
			M5[i][j + l / 2] = mat10[i][j];
			M5[i + l / 2][j] = mat11[i][j];
			M5[i + l / 2][j + l / 2] = mat12[i][j];
		}
	}

	///////////////////////////////////////////////////////////////////////////////
	////////////////������������ ������ �������������� �������/////////////////////
	///////////////////////////////////////////////////////////////////////////////

	int x = 0, f = 100, s = 100;
	for (int i = 0; i < l; i++)
	{
		x = 0;
		for (int j = 0; j < l; j++)
		{
			if (M5[i][j] != 0)
			{
				x++;
				f = 100;
			}
		}
		if (x == 0 && i < f)
		{
			f = i;
		}
	}
	for (int i = 0; i < l; i++)
	{
		x = 0;
		for (int j = 0; j < l; j++)
		{
			if (M5[j][i] != 0)
			{
				x++;
				s = 100;
			}
		}
		if (x == 0 && i < s)
		{
			s = i;
		}
	}

	int** M6 = new int* [f];
	for (int i = 0; i < f; i++)
	{
		M6[i] = new int[s];
		for (int j = 0; j < s; j++)
			M6[i][j] = M5[i][j];
	}

	///////////////////////////////////////////////////////////////////////////////
	///////////////////����� �������������� �������////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	cout << "\n�������������� �������\n\n";
	output_matrix_to_console(M6, f, s);	

	system("pause");

	///////////////////////////////////////////////////////////////////////////////
	/////////////////////������� ������������ ������///////////////////////////////
	///////////////////////////////////////////////////////////////////////////////
	
	for (int i = 0; i < n1; i++)
		delete[] M1[i];
	for (int i = 0; i < n2; i++)
		delete[] M2[i];
	for (int i = 0; i < l; i++)
	{
		delete[] M3[i];
		delete[] M4[i];
		delete[] M5[i];
	}
	for (int i = 0; i < f; i++)
		delete[] M6[i];
	for (int i = 0; i < l / 2; i++)
	{
		delete[] mat1[i];
		delete[] mat2[i];
		delete[] mat3[i];
		delete[] mat4[i];
		delete[] mat5[i];
		delete[] mat6[i];
		delete[] mat7[i];
		delete[] mat8[i];
		delete[] mat9[i];
		delete[] mat10[i];
		delete[] mat11[i];
		delete[] mat12[i];
		delete[] p1[i];
		delete[] p2[i];
		delete[] p3[i];
		delete[] p4[i];
		delete[] p5[i];
		delete[] p6[i];
		delete[] p7[i];
	}
	delete[] M1, M2, M3, M4, M5, M6;
	delete[] mat1, mat2, mat3, mat4, mat5, mat6, mat7, mat8, mat9, mat10, mat11, mat12;
	delete[] p1, p2, p3, p4, p5, p6, p7;
}


void fill_matrix_from_console(int** matrix, const int n, const int m)
{
	for (auto i = 0; i < n; i++)
		for (auto j = 0; j < m; j++)
			cin >> matrix[i][j];
}
void output_matrix_to_console(int** matrix, const int n, const int m)
{
	for (auto i = 0; i < n; i++)
	{
		for (auto j = 0; j < m; j++)
			cout << matrix[i][j]<<" ";
		cout << "\n";
	}
}

void fill_matrix_using_random(int** matrix, const int n, const int m)
{
	for (auto i = 0; i < n; i++)
		for (auto j = 0; j < m; j++)
			matrix[i][j] = rand() % 10;
}
void fill_matrix_by_copy(int** filling_matrix, int** filled_matrix, const int n, const int m)
{
	for (auto i = 0; i < n; i++)
	{
		for (auto j = 0; j < m; j++)
			filling_matrix[i][j] = filled_matrix[i][j];
	}
	
}