#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contacts.h"
#include <conio.h>

/* @brief	: Initialize the struct of contacts.
 * @param	: contacts_s *contact
 * @retval	: None 
 */
void Contacts_Init(struct contacts_s *contact)
{
	strcpy_s(contact->firstName, sizeof("Name"),"Name");
	strcpy_s(contact->lastName, sizeof("Last"), "Last");
	strcpy_s(contact->EGN, sizeof("123467"), "123467");
	strcpy_s(contact->phoneNumber, sizeof("12345"), "12345");
}

/* @brief	: Add contact in the file
 * @param:	: contacts_s *contact
 * @retval	: integer
*/
void Contacts_Add()
{
	int size;
	FILE *file;
	fopen_s(&file, "Data.dat", "a");

	fseek(file, 0, SEEK_END);
	size = ftell(file);

	if (file != NULL)
	{
		if (size != 0)
		{
			fwrite("\r", sizeof("\r"), 1, file);
		}
		fwrite(&Contact, sizeof(struct contacts_s), 1, file);
		fclose(file);
	}
}

/* @brief	: Read Contacts from file.
 * @param	: contacts_s *contact
 * @retval	: None
 */
void Contacts_Read()
{
	FILE *file;
	fopen_s(&file, "Data.dat", "r");

	system("cls");
	while (fread(&Contact, sizeof(struct contacts_s), 3, file))
	{
		printf("\n First Name\t: %s", Contact.firstName);
		printf("\n Last Name\t: %s", Contact.lastName);
		printf("\n PhoneNumber\t: %s", Contact.phoneNumber);
		printf("\n EGN\t\t: %s\n", Contact.EGN);
	}
	getchar();
}

int Contacts_Edit(struct contacts_s *contact)
{
	return 0;
}

int Contacts_Remove(struct contacts_s *contact)
{
	return 0;
}

int Contacts_Save(struct contacts_s *contact)
{
	return 0;
}

int Contacts_Search(const char *searchString, struct contacts_s *contact)
{
	//char *searchString;

	return 0;
}