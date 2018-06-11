#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

#include "contacts.h"
#include "main.h"
#include "menu.h"

void ApplicationExit()
{
	exit(0);
}

int main()
{
	Contacts_Init(&Contacts);

	Menu_Init();
	MenuInit_Main();
	Menu_Draw(&MenuState);

	while (1)
	{
		Menu_Walk();
	}

	return 0;
}