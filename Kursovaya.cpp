//Даны N точек на плоскости. Найти среди них точки являющиеся вершинами фигуры, содержащей максимальное число заданных точек. 
//Фигура - параллелограмм.
#include "stdafx.h"
#include "iostream"
#include "math.h"
#include "fstream"
using namespace std;
const int N = 250;

ifstream inx; // Файл с координатами X
ifstream iny; // Файл с координатами Y
ofstream par; // Файл с полученными параллелограммами
ofstream maxpar; // Файл с максимальным параллелограммом
ofstream to4k; // Файл с точками, которые принадлежат параллелограмму, т.е. те которые входят в пар-мм (включая вершины)
ofstream polu4; // Файл со всеми точками

double in(double X[N], double Y[N], double  n) // Начало функции ввода
{
	//fstream g; g.open("in.txt", ios::in);
	inx.open("inx.txt", ios::in); // Открытие файла с координатами x
	iny.open("iny.txt", ios::in); // Открытие файла с координатами y
	polu4.open("polu4.txt", ios::out);

	int i;
	double z;
	polu4 << "Все введенные точки" << endl;
	for (i = 0; i> z;   // Ввод Х
			X[i] = z;

			iny >> z;  // Вод У
			Y[i] = z;
		}
		polu4 << "(" << X[i] << "; " << Y[i] << ");" << endl;
	}

	return 0;
} // Конец функции ввода




  //длина стороны АВ
double side(double xa, double ya, double xb, double yb)
{
	return sqrt((xb - xa)*(xb - xa) + (yb - ya)*(yb - ya));
}

//отклонение С от АВ
double deviation(double x1, double y1, double x2, double y2, double x3, double y3)
{
	double r = side(x1, y1, x2, y2);
	double A = (y2 - y1) / r;
	double B = (x2 - x1) / r;
	double C = (x1*(y2 - y1) - y1*(x2 - x1)) / r;
	return (x3*A - y3*B - C);
}



double process(double X[N], double Y[N], double K[N], double n, double juk = 0) 
{
	par.open("par.txt", ios::out);
	to4k.open("to4k.txt", ios::out);
	maxpar.open("maxpar.txt", ios::out);
	//maxpar << "Максимального параллелограмма не обнаружено" << endl;
	to4k << "Точки которые принадлежат параллелограмму" << endl;
	
//	maxpar.close();
	int i, j, u, h, c = 0;
	int i1, j1, u1, h1;
	double max;
	int nomer = 0;
	max = 0;
	for (i = 0; i<(n - 3); i++) // Цикл
	{
		for (j = (i + 1); j<(n - 2); j++) // Который
		{
			for (u = (j + 1); u<(n - 1); u++) // Меня
			{
				for (h = (u + 1); h= sobch)
							{		
								// 	kol = kol + 1;
								// if kol>max	max=kol;
									
								
									par << "Точка (" << X[i1] << "; " << Y[i1] << ") принадлежит данному параллелограмму; " << endl;
										
									juk++; 
							

									par << "Жук равен: " << juk << endl;
									
			/*						maxpar << "Максимальный параллелограмм" << endl;
									maxpar << "(" << X[i] << "; " << Y[i] << ");" << endl;
									maxpar << "(" << X[j] << "; " << Y[j] << ");" << endl;
									maxpar << "(" << X[u] << "; " << Y[u] << ");" << endl;
									maxpar << "(" << X[h] << "; " << Y[h] << ");" << endl;
									*/
								

							}

						}
					}
				}
			}
		}
	} 

	maxpar.close();
	par.close();
	return 0;
}



void main()
{
	setlocale(LC_ALL, "");

	double x[N], y[N], k[N], kol;
	double n, l = 1, max;
	int juk = 0;
	cout << "Введите количество точек" << endl;
	do
	{
		cin >> n;

		if (n<4)
		{
			cout << " Мало точек " << endl;
		}

		if (l == 3)
		{
			cout << " n=4" << endl;
			//cout << "Поехали? " << endl;
			system("pause");
		}
		l++;
	} while (n<4);

	in(&x[0], &y[0], n);
	process(&x[0], &y[0], &k[0], n, juk);

}
