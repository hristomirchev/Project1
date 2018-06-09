#include <stdio.h>
#include "contacts.h"
#include <conio.h>

/*	@brief:		Add contact in the file
@param:		contacts_s* contact
@retval:	integer
*/
int Contacts_Add(contacts_s* contact)
{
	FILE* file;
	fopen_s(&file, "Data.txt", "a");

	char buffer[200] = "";
	strcat_s(buffer, sizeof(buffer), contact->firstName);
	strcat_s(buffer, sizeof(buffer), "; ");
	strcat_s(buffer, sizeof(buffer), contact->lastName);
	strcat_s(buffer, sizeof(buffer), "; ");
	strcat_s(buffer, sizeof(buffer), contact->phoneNumber);
	strcat_s(buffer, sizeof(buffer), "; ");
	strcat_s(buffer, sizeof(buffer), contact->EGN);
	strcat_s(buffer, sizeof(buffer), "; \n");

	if (file != NULL)
	{
		fwrite(buffer, sizeof(char), strlen(buffer), file);
		fclose(file);
	}

	return 0;
}

void Contacts_Read(contacts_s* contact)
{
	FILE *file;
	fopen_s(&file, "Data.txt", "r");

	char buffer[200] = "";
	fscanf_s(file, "%s", buffer, sizeof(buffer));
	printf(" 1. %s", buffer);

	_getch();
}

int Contacts_Edit(contacts_s* contact)
{
	return 0;
}

int Contacts_Remove(contacts_s* contact)
{
	return 0;
}

int Contacts_Save(contacts_s* contact)
{
	return 0;
}

int Contacts_Search(contacts_s* contact)
{
	//char* searchString;

	return 0;
}