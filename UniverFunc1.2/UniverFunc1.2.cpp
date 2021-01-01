
#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>

using namespace std;

int k, p;
int Z = 0;
double rez;
// чтобы выбрать нужную функцию, надо просто переименовать ее название в f без номера
double f0(double bazov[])// пример функции с 1 переменной для обоснования ввода N вручную
{
	double x = bazov[0];
	rez = pow(x, 3);
	return rez;
	//данная функция не из учебника. 
	//Эта функция используется для обоснования ввода N, а так же для наглядности работы точки останова если функция не имеет экстремума
}

double f1(double bazov[])//0,0 
{
	double x = bazov[0];
	double y = bazov[1];
	rez = 4 * (pow((x - 5), 2)) + (pow((y - 6), 2));
	return rez;
}
double f2(double bazov[])//0,0  
{
	double x = bazov[0];
	double y = bazov[1];
	rez = 2 * (pow((x - 4), 2)) + (pow((y - 6), 2));
	return rez;
}
double f3(double bazov[])//0,0
{
	double x = bazov[0];
	double y = bazov[1];
	rez = 2 * (pow((x - 5), 2)) + (pow((y - 6), 2));
	return rez;
}
double f4(double bazov[])//0,0 
{
	double x = bazov[0];
	double y = bazov[1];
	rez = 2 * (pow((x - 7), 2)) + (pow((y - 6), 2));
	return rez;
}
double f5(double bazov[])//0,0 
{
	double x = bazov[0];
	double y = bazov[1];
	rez = 3 * (pow((x - 5), 2)) + (pow((y - 4), 2));
	return rez;
}
double f6(double bazov[])//5,5 
{
	double x = bazov[0];
	double y = bazov[1];
	rez = 2 * (pow(x, 2)) + x * y + pow(y, 2);
	return rez;
}
double f7(double bazov[])//7,7  
{
	double x = bazov[0];
	double y = bazov[1];
	rez = pow((pow(x, 2) + y - 11), 2) + (pow((x + pow(y, 2) - 7), 2));
	return rez;
}
double f8(double bazov[])//5,5  
{
	double x = bazov[0];
	double y = bazov[1];
	rez = 1 - 2 * y - 2 * x - 4 * y*x + pow((10 * x), 2) + 2 * (pow(y, 2));
	return rez;
}
double f9(double bazov[])//5,5 
{
	double x = bazov[0];
	double y = bazov[1];
	rez = pow(x, 4) + pow(y, 4) + 2 * (pow(x, 2))*(pow(y, 2)) - 4 * x + 3;
	return rez;
}
double f10(double bazov[])//3,2  
{
	double x = bazov[0];
	double y = bazov[1];
	rez = pow(x, 2) + x * y + pow(y, 2) - 3 * x - 6 * y;
	return rez;
}
double f11(double bazov[])//5.23, 4.41  
{
	double x = bazov[0];
	double y = bazov[1];
	rez = pow(x, 3) + pow(y, 3) - 15 * x * y;
	return rez;
}
double f12(double bazov[])//2.31, 4.27  работает
{
	double x = bazov[0];
	double y = bazov[1];
	rez = (pow((pow(x, 2) + pow(y, 2)), 2 / 3)) - 4;
	return rez;
}
double f13(double bazov[])//1.5,2  работает
{
	double x = bazov[0];
	double y = bazov[1];
	rez = (pow(x, 2) + pow(y, 2))*(1 - exp((-pow(x, 2) - pow(y, 2))));
	return rez;
}
double f14(double bazov[])//1.5, 0.7 
{
	double x = bazov[0];
	double y = bazov[1];
	rez = pow(x, 3) + pow(y, 3) - 3 * x * y;
	return rez;
}
double f15(double bazov[])//0.78, 1 
{
	double x = bazov[0];
	double y = bazov[1];
	rez = 3 * x - pow(x, 3) + 3 * (pow(y, 2)) + 4 * y;
	return rez;
}
double f16(double bazov[])//2,2  работает
{
	double x = bazov[0];
	double y = bazov[1];
	rez = x * y + (50 / x) + (20 / y);
	return rez;
}
double f17(double bazov[])//2.31, 4.27 
{
	double x = bazov[0];
	double y = bazov[1];
	rez = pow(x, 2) + pow(y, 3) - 2 * log(x) - 18 * log(y);
	return rez;
}
double f18(double bazov[])//0.3,0.5 
{
	double x = bazov[0];
	double y = bazov[1];
	rez = 2 * pow(x, 3) - x * (pow(y, 2)) + 5 * pow(x, 2) + pow(y, 2);
	return rez;
}
double f19(double bazov[])//3,5 
{
	double x = bazov[0];
	double y = bazov[1];
	rez = pow((pow(x, 2) + pow(y, 2)), 0.3333333333) - 2;
	return rez;
	// в данном случае если вместо 0.3333333333 поставить 1/3 то результат считается некорректно.
	// смотрел в библиотеке cmath определение функции pow, там нет определения возведения числа в степень периодической дроби.
	//посему, решил заменить дробь конечным числом с точностью 10 знаков. думаю этого будет достаточно, да и сама функция pow сможет сконвертировать его 
	//в более приемлемое число (как минимум в long dowble)
}
double f20(double bazov[])//2.31, 4.27  
{
	double x = bazov[0];
	double y = bazov[1];
	rez = 2 * (pow(x, 3)) + 4 * x * pow(y, 2) - 10 * x * y + pow(y, 2);
	return rez;
}

double func(double bazov[], int Numb)
{
	if (Numb == 1)
	{
		f1(bazov);
	}
	if (Numb == 2)
	{
		f2(bazov);
	}
	if (Numb == 3)
	{
		f3(bazov);
	}
	if (Numb == 4)
	{
		f4(bazov);
	}
	if (Numb == 5)
	{
		f5(bazov);
	}
	if (Numb == 6)
	{
		f6(bazov);
	}
	if (Numb == 7)
	{
		f7(bazov);
	}
	if (Numb == 8)
	{
		f8(bazov);
	}
	if (Numb == 9)
	{
		f9(bazov);
	}
	if (Numb == 10)
	{
		f10(bazov);
	}
	if (Numb == 11)
	{
		f11(bazov);
	}
	if (Numb == 12)
	{
		f12(bazov);
	}
	if (Numb == 13)
	{
		f13(bazov);
	}
	if (Numb == 14)
	{
		f14(bazov);
	}
	if (Numb == 15)
	{
		f15(bazov);
	}
	if (Numb == 16)
	{
		f16(bazov);
	}
	if (Numb == 17)
	{
		f17(bazov);
	}
	if (Numb == 18)
	{
		f18(bazov);
	}
	if (Numb == 19)
	{
		f19(bazov);
	}
	if (Numb == 20)
	{
		f20(bazov);
	}
	return 0;
}


int Proverka(double *Rezultat[], double Ex, double Ey, double iskom[], int N, double Raznica[])
{
	for (k = 0; k < N; k++)//данный цикл позволяет проверить ВСЕ координаты, а не только 2 как в задании
	{
		double maxRaznica = abs(Rezultat[1][N] - abs(Rezultat[0][N]));//сравниваем каждую координату текущей точки и предыдущей, ищем наиболшую разницу среди всех
		if (maxRaznica > Raznica[0])
			Raznica[0] = maxRaznica / Ex;// в качестве нормы выбрана Ex, т.к. это верхний допустимый предел измерений
	}

	if (abs(Rezultat[1][N] - Rezultat[0][N]) > Ey)//сначала проверка по значению( вдруг мы будем квадратичную тестить, а там быстро корни ищутся)
	{
		if (abs(Raznica[0]) >= Ex)//затем проверяем аргумент
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	else
	{
		return 1;
	}
}

double Issledov(double obraz[], double bazov[], double iskom[], double shag, double A, int N, double Ex, double Ey, int i, double zapas, double *Rezultat[], double Raznica[], int Numb)// исслед соседн точки от базов x0
{
	if (i < N)//проходим все координаты
	{
		if (shag > Ex)//если шаг меньше, следоват. точн. всех аргументов будет выше погрешности
		{
			iskom[i] = bazov[i] + shag;
			if (func(iskom, Numb) < func(bazov, Numb))
			{
				//cout << " min koord* = " << iskom[i] << endl;//нашли коорд i звездочка используется для лучшего отслеживания информации о текущем выполнении кода и различия выполняемых строк кода при выводе
			}
			else
			{
				iskom[i] = bazov[i] - shag;
				if (func(iskom, Numb) < func(bazov, Numb))
				{
					//cout << " min koord** = " << iskom[i] << endl;//нашли коорд i
				}
				else
				{
					if (shag > Ex)//есди шаг меньше, то ловить уже нечего, оставляем так
					{
						shag = shag / A;//уменьшаем шаг в А раз
						cout << " уменьшили шаг. шаг равен =" << shag << endl;
						Issledov(obraz, bazov, iskom, shag, A, N, Ex, Ey, i, zapas, Rezultat, Raznica, Numb);//если хоть одна коорд не меняется, уменьш шаг и занового проходим все
					}
				}
			}

			i = i + 1;
			Issledov(obraz, bazov, iskom, shag, A, N, Ex, Ey, i, zapas, Rezultat, Raznica, Numb);

		}
		else
		{
			iskom[i] = bazov[i];//проверили максим точно выбран коорд
			i = i + 1;
			shag = zapas;//восстанавливаем шаг после уменьшения( для исследов текущ коорд)  для след координтаы
			Issledov(obraz, bazov, iskom, shag, A, N, Ex, Ey, i, zapas, Rezultat, Raznica, Numb);
		}
	}

	for (i = 0; i < (N); i++)//запомин координаты для послед сравн. с погрешн
		Rezultat[0][i] = iskom[i];
	Rezultat[0][N] = func(iskom, Numb);//запомин результат функ для послед сравн. с погрешн

	if (Proverka(Rezultat, Ex, Ey, iskom, N, Raznica) == 0)
	{
		return 0;// если нашли различия в точках- продолжаем поиск и т.д.
	}
	else
	{
		return 1;//различий нет выход из проги
	}
}

double PoiskObr(double bazov[], double iskom[], double obraz[], double Ex, double Ey, int N, int i, double shag, double A, double zapas, double *Rezultat[], double Uskor, double Raznica[], int Numb)//пишу теже имена чтоб было понятно что будет принимать
{
	//получаем исслед точку , массив iskom
	for (k = 0; k < N; k++)
	{
		obraz[k] = iskom[k] + Uskor * (iskom[k] - bazov[k]);//используем параметр ускорения для снижения кол-ва циклов программы

	}
	cout << endl << endl;

	if (func(obraz, Numb) < func(iskom, Numb))
	{
		Issledov(obraz, bazov, iskom, shag, A, N, Ex, Ey, 0, zapas, Rezultat, Raznica, Numb);
		for (k = 0; k < N; k++)
			bazov[k] = iskom[k];
	}
	else
	{
		for (k = 0; k < N; k++)
		{
			bazov[k] = iskom[k];
		}
		Issledov(obraz, bazov, iskom, shag, A, N, Ex, Ey, 0, zapas, Rezultat, Raznica, Numb);//исследуем точку останов, последн точка поиска, котор давала наименьш знач функ
	}
	return 0;
}


double Huk_Djivs(int cikl, double bazov[], double iskom[], double obraz[], double shag, double A, double Ex, double Ey, int N, int i, double zapas, double *Rezultat[], vector <vector <double>> &Tochki, double Uskor, double Raznica[], int MaxCikl, int Numb)
{
	cout << "++++++ Cikl programmi = " << cikl << " +++++++" << endl;

	if (Issledov(obraz, bazov, iskom, shag, A, N, Ex, Ey, i, zapas, Rezultat, Raznica, Numb) == 1)//здесь точка конечного выхода из проги  и результата !
	{
		cout << endl << "количество координат точки= " << N << endl;
		cout << "исходное Ex = " << Ex << endl;
		cout << "исходное Ey = " << Ey << endl;
		cout << "Шаг = " << shag << endl;
		cout << "параметр  сжатия = " << A << endl;
		cout << "параметр  ускорения = " << Uskor << endl;
		cout << "достигнутая точность по аргументу = " << abs(Raznica[0]) << endl;
		cout << "достигнутая точность по значению  = " << abs(Rezultat[1][N] - Rezultat[0][N]) << endl;
		cout << "все исследованные точки : " << endl;
		for (p = 0; p < Tochki.size(); p++)//печать всех исследованных точек
		{
			for (k = 0; k < Tochki[p].size(); k++)
			{
				cout << " | " << Tochki[p][k];
			}
			cout << endl;
		}
		cout << endl;
		cout << endl << "координаты возможного экстремума = " << endl;
		for (k = 0; k < N; k++)
		{
			cout << " | " << iskom[k];
		}
		cout << endl;
		cout << "func(x,y) = " << func(iskom, Numb) << endl;
		cout << endl << "циклов программы(без учета начальной точки) = " << cikl << endl;


		ofstream rezult("rezultat.txt", ios::binary | ios::app); //пишем результат в конец файл
		rezult << "\r\n";
		rezult << "       Финальный отчет : " << "\r\n";
		rezult << "количество координат точки= " << N << "\r\n";
		rezult << "исходное Ex = " << Ex << "\r\n";
		rezult << "исходное Ey = " << Ey << "\r\n";
		rezult << "Шаг = " << shag << "\r\n";
		rezult << "параметр  сжатия = " << A << "\r\n";
		rezult << "параметр  ускорения = " << Uskor << "\r\n";
		rezult << "достигнутая точность по аргументу = " << abs(Raznica[0]) << "\r\n";
		rezult << "достигнутая точность по значению  = " << abs(Rezultat[1][N] - Rezultat[0][N]) << "\r\n";
		rezult << "все исследованные точки : " << "\r\n";
		for (p = 0; p < Tochki.size(); p++)//печать всех исследованных точек
		{
			for (k = 0; k < Tochki[p].size(); k++)
			{
				rezult << " | " << Tochki[p][k];
			}
			rezult << "\r\n";
		}
		rezult << "\r\n";
		rezult << endl << "координаты возможного экстремума = " << "\r\n";
		for (k = 0; k < N; k++)
		{
			rezult << " | " << iskom[k];
		}
		rezult << "\r\n";
		rezult << "func(x,y) = " << func(iskom, Numb) << "\r\n";
		rezult << endl << "циклов программы(без учета начальной точки) = " << cikl << "\r\n";
		rezult << "\r\n";
		rezult << " Если  точка возможного экстремума не входит в число исследованных, значит последний найденный минимум(исследованная точка) не является экстремумом" << "\r\n";
		rezult << "и дальше есть еще как минимум одна точка  в которой func(x)  принимает еще  меньшее значение(котороая и была найдена как возможный экстремум)" << "\r\n";
		rezult << " Данное утверждение относится в основном к кубическим функциям" << "\r\n";
		rezult << "\r\n";
		rezult.close();

		delete[] bazov;
		delete[] iskom;
		delete[] obraz;
		delete[] Rezultat;
		return 0;
	}
	else
	{
		if (cikl > abs(MaxCikl))// условие останова для выхода из рекурсии
		{
			cout << endl << " пройдено " << cikl << "  циклов программы - возможно, экстремума нет." << endl;
			cout << " Попробуйте увеличить шаг в 100 раз. В качестве начальной точки выберите последнюю исследованную ";

			ofstream rezult("rezultat.txt", ios::binary | ios::app);

			rezult << " координаты последней исследованной точки = ";
			for (k = 0; k < N; k++)
			{
				rezult << " | " << iskom[k];
			}
			rezult << " достигнутая точность по аргументу = " << abs(Raznica[0]) << "\r\n";
			rezult << " достигнутая точность по значению   = " << abs(Rezultat[1][N] - Rezultat[0][N]) << "\r\n";
			rezult << "\r\n" << " пройдено " << cikl << "  циклов программы - возможно, экстремума нет." << "\r\n";
			rezult << " Попробуйте увеличить шаг в 100 раз. В качестве начальной точки выберите последнюю исследованную";
		}
		else
		{
			//пишем промежуточный результат по исследованной точке
			cout << endl << "координаты исследованной точки = ";
			for (k = 0; k < N; k++)
			{
				cout << " | " << iskom[k];
			}
			cout << endl;
			cout << endl << "                           func(x) = " << func(iskom, Numb) << endl;
			cout << " точность по аргументу на этапе = " << abs(Raznica[0]) << endl;
			cout << " точность по значению  на этапе = " << abs(Rezultat[1][N] - Rezultat[0][N]) << endl;

			ofstream rezult("rezultat.txt", ios::binary | ios::app); //пишем результат в конец файл
			rezult << "координаты исследованной точки = ";
			for (k = 0; k < N; k++)
			{
				rezult << " | " << iskom[k];
			}
			rezult << "\r\n";
			rezult << "                          func(x) = " << func(iskom, Numb) << "\r\n";
			rezult << " точность по аргументу на этапе = " << abs(Raznica[0]) << "\r\n";
			rezult << " точность по значению  на этапе = " << abs(Rezultat[1][N] - Rezultat[0][N]) << "\r\n";
			rezult << "\r\n";
			rezult.close();

			//каждая исследованная точка записывается в многомерный вектор Tochki
			Tochki.push_back(vector<double>()); // добавляем новый вектор в конец общего вектора
			for (int k = 0; k < N; k++) //копируем из iskom в новый вектор, для вставки в конец общего вектора
			{
				Tochki[cikl + 1].push_back(iskom[k]); // в данный вектор добавляем элементы.
			}

			for (i = 0; i < (N + 1); i++)//исследованная точка становится старой, 
				Rezultat[1][i] = Rezultat[0][i];
			cikl = cikl + 1;

			//cout <<endl<<endl<< "Poisk po obrazcu..." << endl;
			PoiskObr(bazov, iskom, obraz, Ex, Ey, N, i, shag, A, zapas, Rezultat, Uskor, Raznica, Numb);//поиск координаты окончен
			if (PoiskObr(bazov, iskom, obraz, Ex, Ey, N, i, shag, A, zapas, Rezultat, Uskor, Raznica, Numb) == 1)
			{
				return 1;
			}

			Huk_Djivs(cikl, bazov, iskom, obraz, shag, A, Ex, Ey, N, 0, zapas, Rezultat, Tochki, Uskor, Raznica, MaxCikl, Numb);
			return 0;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int  N, cikl, MaxCikl;
	double  shag, A, Ex, Ey, zapas, Uskor;//коэфиц увеличения шага при поиске по образцу
	cikl = 0;//cчетчик выполнения всей программы 


	cout << endl << " Выберите номер уравнения... " << endl;
	int Numb;
	cin >> Numb;

	cout << endl << " введите количеств неизвестных " << endl;
	cin >> N;//количество переменных, это сделано для того, что в код можно будет добавить функцию с любым количеством переменных(как задел на будущее использование)
	cout << " введите шаг " << endl;//шаг для исследов должен быть больше погрешности, иначе мы сразу получаем ответ
	cin >> shag;
	zapas = shag;// переменная будет использ в исследовании для восстановления шага после уменьшения

	cout << " введите коэфициент ускорения " << endl;
	cin >> Uskor;
	cout << " введите параметр сжатия шага" << endl;//коэфициент уменьшения шага при исследовании
	cin >> A;
	cout << " введите точность Ex" << endl;
	cin >> Ex;
	cout << " введите точность Ey" << endl;
	cin >> Ey;
	cout << " введите максимально допустимое количество циклов для программы" << endl;
	cin >> MaxCikl;//данный параметр используется как критерий останова для функций, которые могут и не иметь экстремума вообще.
	//Чтобы не ждать переполнение буфера можно просто самому выбрать этот параметр в зависимости от интереса и возможностей компьютера, на котором запустится данная прога

	// решил не выпендриваться и все-таки воспользоваться вектором
	vector < vector <double> >Tochki(1, vector <double>(N));// 1 строка на N элементов, как начальный не заполненый многомерный массив

	double *bazov = new double[N];//создаем отправную точку для метода
	for (k = 0; k < N; k++)
	{
		cout << "введите координату" << endl;
		cin >> bazov[k];
		Tochki[0][k] = bazov[k];
	}

	double* iskom = new double[N];//создаем доп точку для исследов
	for (k = 0; k < N; k++)
	{
		iskom[k] = bazov[k];
	}

	double* obraz = new double[N];//создаем доп точку для поиска по образцу
	for (k = 0; k < N; k++)
	{
		obraz[k] = iskom[k];
	}

	//сюда будем запоминать предыдущ удачную точку и текущую удачную точку - чтоб потом сравнить с погрешностью
	double** Rezultat = new double*[2];
	for (k = 0; k < 2; k++)
	{
		Rezultat[k] = new double[N + 1];//  первые N слота -это координаты найден. точки, N+1 слот это f(x)
	}
	for (p = 0; p < (N + 1); p++)//первая строка пустая(нули)- еще нет новой исследов точки
		Rezultat[0][p] = 0;

	for (k = 0; k < N; k++)//вторая строка - пишем туда иначальную точку( она как бы уже проидена), будем использовать в первой проверке погрешности
	{
		Rezultat[1][k] = bazov[k];
	}
	Rezultat[1][2] = func(bazov, Numb);

	double *Raznica = new double[1];

	ofstream rezult("rezultat.txt");// т.к. запись будет производится всегда в конец фаила, чистим его от предыдущих результатов 
	Huk_Djivs(cikl, bazov, iskom, obraz, shag, A, Ex, Ey, N, 0, zapas, Rezultat, Tochki, Uskor, Raznica, MaxCikl, Numb);
	system("pause");
}/*особенность данной проги в том, что она находит конечную точку минимума(с учетом условия останова). а затем от нее еще раз пытается вычислить точку минимума.
если результат не меняется, значит это раельная точка минимума. Такая двойная проверка связана с рекурсивностью шагов программы.
Конечно, рекурсию можно заменить на итерацию и наоборот, но суть не поменяется - программа подразумевает выполнение всего своего тела к каждой найденной точке.
Да, рекурсия затратнее, но нагляднее. В задании не было указано каким методом надо писать, эффективность программы тоже не упоминалась. На момент первого написания кода Мне так было понятнее .
*/