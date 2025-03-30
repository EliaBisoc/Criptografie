#include <iostream>
#include <fstream>
using namespace std;

int modulo(int a, int n) {
	if (a >= 0 && n > 0)
		return a % n;
	if (a < 0 && n > 0)
		return a % n + n;
	if (n == 0)
		return -1;
}

char alfabet[100];
int N = 0;
int da_cod(char c)
{
	for (int i = 0; i < N; i++)
		if (alfabet[i] == c)
			return i;
}

char da_caracter(int cod)
{
	return alfabet[modulo(cod, N)];
}

void citeste_alfabet(ifstream in)
{
	char c;
	while (in >> noskipws >> c)
	{
		alfabet[N++] = c;
	}
	if (N == 0)
		cout << "Alfabet gol" << endl;
}

void criptareVigenere(ifstream& in, ofstream& out, int n, int m)
{
	char c;
	int i=0;
	int* M = new int[n];
	for (int i = 0; i < n; i++)
		*(M + i) = 0;
	int* k = new int[m];
	for (int i = 0; i < m; i++)
		*(k + i) = 0;
	int* C = new int[n];
	for (int i = 0; i < n; i++)
		*(C + i) = 0;
	while (in >> noskipws >> c)
	{
		if(i<n)
		M[i] = da_cod(c);
		else
			k[i-n] = da_cod(c);
		i++;
	}
	for (i = 0; i < n; i++)
	{
		C[i] = 0;
		if (i <= m - 1) 
			C[i] = M[i] + k[i];
		else 
			C[i] = M[i] + k[i - m];
		out << da_caracter(C[i]);
	}
}
