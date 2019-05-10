#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

double f(double x) {
	return x * x;
}

void carlo(double p, double k, int N) {
	double dx, wynik=0,blad;

	dx = k - p;   
	for (int i = 1; i <= N; i++)
	wynik += f(p + ((double)rand() / (double)(RAND_MAX + 1)*dx));
	wynik = dx * wynik / N;
	blad = abs(330.666 - wynik);
	cout << "wynik dla carlo, N=" << N << " :" << wynik <<" blad="<<blad<< endl;

}

void trapez(double p, double k, int N) {
	double wynik=0, dx,blad;
	dx = (k - p) / N;  
	for (int i = 1; i < N; i++) wynik += f(p + i * dx);
	wynik = (wynik + (f(p) + f(k)) / 2) * dx;
	blad = abs(330.666 - wynik);
	cout << "wynik dla trapez, N=" << N << " :" << wynik <<" blad="<<blad<< endl;

}

void simpson(double p, double k, int N) {
	double wynik = 0, dx, x, s = 0;
	dx = (k - p) / N;



	for (int i = 1; i < N; i++) {
		x = p + i * dx;
		s += f(x - dx / 2);
		wynik += f(x);
	}
	s += f(k - dx / 2);
	wynik = (dx / 6) * (f(p) + f(k) + 2 * wynik + 4 * s);
	cout << "wynik dla simpson, N=" << N << " :" << wynik << " blad=" << abs(330.666 - wynik) << endl;
}

int main() {

	srand(time(NULL));
	cout << setprecision(3) << fixed;

	carlo(2, 10, 2);
	carlo(2, 10, 16);
	carlo(2, 10, 128);
	carlo(2, 10, 1024);
	carlo(2, 10, 2048);
	carlo(2, 10, 100000);

	trapez(2, 10, 1);
	trapez(2, 10, 16);
	trapez(2, 10, 128);
	trapez(2, 10, 1024);
	trapez(2, 10, 2048);


	simpson(2, 10, 1);
	simpson(2, 10, 16);
	simpson(2, 10, 128);
	simpson(2, 10, 1024);
	simpson(2, 10, 2048);
	

	system("pause");
	return 0;
}