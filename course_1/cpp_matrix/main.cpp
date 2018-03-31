#include "tools.h"

int main() {
	setlocale(0, "");
	int n;
	double **l;
	double *x;
	cout << "Введите количество столбцов и строк N= ";
	cin >> n;

	l = new double *[n + 1];

	for (int i = 1; i <= n; i++)
		l[i] = new double[n + 1];

	mainCreate(l, n);

	x = new double[n + 1];

	viewM(l, n);

	task(l, x, n);

	viewV(x, n);

	cout << "U = " << FunU(x, n) << "." << endl;

	for (int i = 1; i <= n; i++) {
		delete l[i];
	}
	delete[] l; delete[] x;
	system("pause");
	return 0;
}
