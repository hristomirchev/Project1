#include <stdio.h>
#include <conio.h>
#include <string.h>

#include "contacts.h"
#include "main.h"


int DisplayContacts(contacts_s* contact)
{
	return 0;
}


int main()
{
	Contacts[0].firstName = "Name";
	Contacts[0].lastName = "Last";
	Contacts[0].EGN = "12345";
	Contacts[0].phoneNumber = "1234";

	Contacts_Add(&Contacts[0]);


	printf(" -- Main Menu -- \r\n");
	printf(" 1. Add contact \r\n");
	printf(" 2. Edit contact \r\n");
	printf(" 3. Delete contact \r\n");
	printf(" 4. Search Contact \r\n");
	printf(" 5. View all contacts \r\n\r\n");

	printf(" 0. Close application \r\n\r\n");

	printf(" Select an option: ");
	char ch;
	ch = getchar();

	switch (ch)
	{
	case '1':
		Contacts_Read(&Contacts);
		break;

	}

	return 0;
}