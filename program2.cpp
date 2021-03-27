#include <iostream>
#include <windows.h>
#include <conio.h> 
#include <vector>
#include <stdio.h>
#include<TCHAR.H>

using namespace std;


int main()
{
	string s = "Hello world!";
	int size = 3;

	if (s.length() % size != 0)
		s += string(s.length() % size, ' ');

	vector<string> blocks;

	int l = 0;
	int r = size;

	while (s.length() >= r) {
		blocks.push_back(s.substr(l, r - l));

		l = r;
		r += size;
	}

	setlocale(LC_ALL, "Russian");
	STARTUPINFO sti = { 0 };
	PROCESS_INFORMATION pi = { 0 };
	DWORD excode;

	for (int i = 0; i < s.length() / size; i++)
	{
		string d = blocks[i];
		string adress = "C:\\Users\\Andrey\\source\\repos\\program_1\\Debug\\program_1.exe";
		string str = "lo";
		string q = adress+ " " + d + " " + str;
		wstring lpszCommandLine (q.begin(), q.end());
		LPWSTR lpwLine = &lpszCommandLine[0];

		cout << "\nСтрока: " << d;
		cout << "\nПроцесс № "<< i + 1 << "начинается";
		if (!CreateProcess(NULL, lpwLine,
			NULL, NULL, FALSE, 0, NULL, NULL, &sti, &pi)) {
			cout << "\nОшибка в создании процесса" << endl;
			return -1;
		}
		_getch();

		GetExitCodeProcess(pi.hProcess, &excode);

		if (excode != STILL_ACTIVE)
		{
			cout << "\nВыполнено\n";

		}
		else { cout << "\nПроцесс все еще работает"; }

		cout << "Процесс завершен\n";
		_getch();
	}
	
	
	
}

