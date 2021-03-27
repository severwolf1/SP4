#include <iostream>
#include <windows.h>
#include <conio.h> 

using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");
	STARTUPINFO sti = { 0 };
	PROCESS_INFORMATION pi = { 0 };
	DWORD excode;

	char lpszCommandLine [] = "C:\\Users\\Andrey\\source\\repos\\program_1\\Debug\\program_1.exe Hello world lo";
	
	cout << "Процесс начинается";
	if (!CreateProcess(NULL, lpszCommandLine,
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

	cout << "Процесс завершен";
	_getch();
}

