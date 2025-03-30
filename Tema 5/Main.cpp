#include "Cripto.h"
using namespace std;

int main()
{
	citeste_alfabet(ifstream("alfabet.txt"));
	ifstream in("sursa.txt");
	ofstream out("destinatie.txt");
	criptareVigenere(in, out, 10, 5);
}