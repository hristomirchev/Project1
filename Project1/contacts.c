#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contacts.h"
#include <conio.h>

/* @brief	: Initialize the struct of contacts.
 * @param	: contacts_s *contact
 * @retval	: None 
 */
void Contacts_Init()
{
	lastRecord = 0;
	for (int i = 0; i < 100; i++)
	{
		strcpy(Contacts[i].firstName, "");
		strcpy(Contacts[i].lastName, "");
		strcpy(Contacts[i].EGN, "");
		strcpy(Contacts[i].phoneNumber, "");
	}
}

/* @brief	: Add contact to the structure.
 * @param	: struct contacts_s **contact
 * @retval	: None
 */
void Contacts_Add()
{
	system("cls");

	char buffer[21] = "";
	printf(" Enter first name: ");
	scanf("%20s", Contacts[lastRecord].firstName);
	printf(" Enter last name: ");
	scanf("%20s", Contacts[lastRecord].lastName);
	printf(" Enter phone number: ");
	scanf("%15s", Contacts[lastRecord].phoneNumber);
	printf(" Enter EGN: ");
	scanf("%11s", Contacts[lastRecord].EGN);

	lastRecord++;
}

/* @brief	: Write contacts array to file.
 * @retval	: None
*/
void Contacts_WriteToFile()
{
	int size;
	FILE *file;
	fopen_s(&file, "Data.dat", "w");

	fseek(file, 0, SEEK_END);
	size = ftell(file);

	if (file != NULL)
	{
		if (size != 0)
		{
			fwrite("\r", sizeof("\r"), 1, file);
		}
		fwrite(&Contacts, sizeof(struct contacts_s), 4, file);
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

	const char *firstName = "First Name";
	printf("%20s%20s%15s%15s\n", "First Name", "Last Name", "Phone Number", "EGN");

	int i = 1;

	//fscanf("%*s, %*s, %*s, %*s", 20, Contacts[i].firstName, 20, Contacts[i].lastName, 15, Contacts[i].phoneNumber, 11, Contacts[i].EGN);

	fread(&Contacts, sizeof(Contacts), 1, file);
	{
		printf("\n%*s", 20, Contacts[i].firstName);
		printf("%*s", 20, Contacts[i].lastName);
		printf("%*s", 15, Contacts[i].phoneNumber);
		printf("%*s", 11, Contacts[i].EGN);
	}
	fclose(file);
	while (_getch() != ESC);
}

int Contacts_Edit(struct contacts_s *contact)
{
	return 0;
}

void Contacts_Remove()
{
	FILE *file;
	fopen_s(&file, "Data.dat", "w");
	fclose(file);
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