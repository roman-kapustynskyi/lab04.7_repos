#include<iostream>
#include< cmath>
#include<iomanip>

using namespace std;

int main() {
	double xp, x, xk, dx,eps,exact, a = 0, R = 0, S = 0;
	int n = 0;

	cout << "xp = "; cin >> xp;
	cout << "xk = "; cin >> xk;
	cout << "dx = "; cin >> dx;
	cout << "eps = "; cin >> eps;

	cout << fixed;

	cout << "------------------------------------------" << endl;
	cout << "|" << setw(5) << "x"      << "    |"
		        << setw(10) << "exact" << " |"
		        << setw(7) << "S"     << "    |"
		        << setw(5) << "n"      << " |"
		        << endl;
	cout << "------------------------------------------" << endl;

	

	x = xp;
	while (x <= xk) {
		n = 0;
		a = 1.0 / x;
		S = a;
		do {
			n++;
			R = (2.0 * n - 1) / ((2.0 * n + 1) * x * x);
			a *= R;
			S += a;
		} while (fabs(a) >= eps);

		exact = 0.5 * log((x + 1) / (x - 1));

		cout << "|" << setw(7)  << setprecision(2) << x      << " |"
			        << setw(10) << setprecision(5) << exact << "  |"
			        << setw(10) << setprecision(5) << S      << " |"
			        << setw(5)  <<                    n      << " |"
			        << endl; 

		x += dx;
	}
	  cout << "------------------------------------------" << endl;

		return 0;
}