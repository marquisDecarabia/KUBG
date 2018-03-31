#include "tools.h"
double FunU(double *y, int kk) {
	double sum;
	double u;
	cout << "Функция U:";
	cout << endl << endl;
	if (kk > 2.00) {
		for (int i = 2; i <= kk - 1; i++) {
			sum = y[i - 1] + y[i + 1];
			if (y[i] >= sum) {
				cout << "За U берём элемент вектора Х под номером " << i << "." << endl << endl;
				u = y[i];
				break;
			}
			else {
				u = y[1];
			}
		}
	}
	else {
		u = y[1];
	}
	if (u == y[1]) {
		cout << "За U берём первый элемент вектора Х." << endl << endl;
		return u;
	}
	else {
		return u;
	}
}
void viewV(double* X, int size) {
	cout << "Вектор Х: " << endl;
	for (int i = 1; i <= size; i++) {
		cout << "x[" << i << "]=" << X[i] << "\t";
	}
	cout << endl << endl;
}
void viewM(double** L, int size) {
	cout << "Матрица L:\n";
	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= size; j++) {
			cout << " l[" << i << "," << j << "]=";
			cout << fixed << setprecision(2) << L[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}
void task(double**&L, double*&X, int size) {
	double sumg = 0, sumr = 0;
	int b = 0, m = 0;
	bool check1, check2, check3 = false;
	for (int i = 1; i <= size; i++) {
		sumg += L[i][i];
	}
	for (int j = 1; j <= size; j++) {
		sumr += L[1][j];
	}
	for (int i = 1; i <= size; i++) {
		if (L[i][i] >= 0) b++;
		else m++;
	}
	check1 = (sumg > sumr);
	check2 = (b != m);
	if (check1&&check2) {
		cout << "Сумма эл-тов главной диагонали превышает сумму эл-тов первой непарной строки и количество её положительных и отрицательных эл-тов не одинаковая. \n";
		cout << "Поэтому мы смещаем эл-ты i-ой строки матрицы на i позиций влево.\n";
		int k = 1;
		for (int i = 1; i <= size; i++) {
			k = i;
			while (k != (-1)) {
				for (int j = 1; j <= size; j++) {
					if (k == 0)
						swap(L[j][size - 1], L[j][1]);
					else
						swap(L[j][k], L[j][k - 1]);					
				}
				k--;
			}
		}
	}
	else {
		cout << "Условие не выполняется, поэтому смещаем эл-ты i-ой строки матрицы на i позиций вправо.\n";
		int  k = 1;
		for (int i = 1; i<size; i++)
		{
			k = i;
			while (k != (-1)){
				for (int j = 1; j<=size; j++){			
					if (k == (size - 1))
						swap(L[j][size - 1], L[j][1]);
					else 
						swap(L[j][k],L[j][k + 1]);
				}
				k--;
			}
		}
	}
	cout << "За эл-ты вектора Х берём эл-ты главной диагонали матрицы L после смещения.\n";
	for (int i = 1; i <= size; i++) {
		X[i] = L[i][i];
	}
	cout << endl;
}

void mainCreate(double**&L, int size) {
	srand((unsigned int)time(0));
	bool povtor;
	cout << "Выберите вариант формирования матрицы:\n\
												1 для заполнения за формулой; \n\
												2 для заполнения случайными значениями; \n\
												3 для заполнения вручную.";
	cout << endl;
	do {
		povtor = false;
		switch (_getch()) {
		case '1':
			for (int i = 1; i <= size; i++) {
				for (int j = 1; j <= size; j++) {
					L[i][j] = ((j)*abs(2 - 3.1*i))*sqrt(abs((i) ^ 2 + j ^ 2)*((i - 1.5)*(j - 4.2)));
				}
			}
			break;
		case '2':
			for (int i = 1; i <= size; i++) {
				for (int j = 1; j <= size; j++) {
					L[i][j] = rand() % 50 - 20;
				}
			}
			break;
		case '3':
			for (int i = 1; i <= size; i++) {
				for (int j = 1; j <= size; j++) {
					cout << " l[" << i << "," << j << "]=";
					cin >> (L[i][j]);
				}
			}
			break;
		default: cout << "Введено не корректное значение. Выберите вариант формирования матрицы еще раз! ";
			cout << endl;
			povtor = true;
		}
	} while (povtor);
	system("cls");

}
