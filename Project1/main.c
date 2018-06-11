#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

#include "contacts.h"
#include "main.h"
#include "menu.h"
#include "contacts.h"

void ApplicationExit()
{
	system("cls");
	printf("Do you want to exit and save the changes? [Y/n/c]: ");

	int esc = 0;
	while(esc == 0)
	{
		switch (getch())
		{
		case RETURN:
			Contacts_WriteToFile();
			exit(0);
			break;
		case ESC:
			esc = 1;
			break;
		case 'c':
			esc = 1;
			break;
		case 'y':
			Contacts_WriteToFile();
			exit(0);
			break;
		case 'Y':
			Contacts_WriteToFile();
			exit(0);
			break;
		case 'n':
			exit(0);
			break;
		case 'N':
			exit(0);
			break;
		}
	}
}

int main()
{
	Contacts_Init(&Contacts);

	Menu_Init();
	MenuInit_Main();
	Menu_Draw(&MenuState);
	Contacts_ReadFromFile();

	while (1)
	{
		Menu_Walk();
	}

	return 0;
}