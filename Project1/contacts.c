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

	for (int i = 0; i < MAX_CONTACTS; i++)
	{
		strcpy(Contacts[i].firstName, "");
		strcpy(Contacts[i].lastName, "");
		strcpy(Contacts[i].phoneNumber, "");
		strcpy(Contacts[i].EGN, "");
	}
}

/* @brief	: Add contact to the structure.
 * @param	: struct contacts_s **contact
 * @retval	: None
 */
void Contacts_Add()
{
	system("cls");

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
	fopen_s(&file, "Data.dat", "wb");



	if (file != NULL)
	{
		fseek(file, 0, SEEK_END);
		size = ftell(file);

		//if (size != 0) fwrite("\r", sizeof("\r"), 1, file);
		fwrite(&Contacts, sizeof(struct contacts_s), lastRecord, file);
		fclose(file);
		
	}
}

/* @brief	: Read Contacts from file.
 * @param	: contacts_s *contact
 * @retval	: None
 */
void Contacts_Read()
{
	system("cls");

	printf("Total contacts: %d\n\n", lastRecord);

	const char *firstName = "First Name";
	printf("%-20s | %-21s | %-16s | %-12s\n", "First Name", "Last Name", "Phone Number", "EGN");
	printf("---------------------+-----------------------+------------------+-------------");
	//fscanf("%*s, %*s, %*s, %*s", 20, Contacts[i].firstName, 20, Contacts[i].lastName, 15, Contacts[i].phoneNumber, 11, Contacts[i].EGN);
/*
	fread(&Contacts, sizeof(Contacts), 1, file);
	{*/
	for (int i = 0; i < lastRecord; i++)
	{
		printf("\n%*s | ", 20, Contacts[i].firstName);
		printf("%*s | ", 21, Contacts[i].lastName);
		printf("%*s | ", 16, Contacts[i].phoneNumber);
		printf("%*s", 11, Contacts[i].EGN);
	}
	printf("\n---------------------+-----------------------+------------------+-------------");

	printf("\n\nPress ESC key to go back.");
	while (_getch() != ESC);
}

void Contacts_ReadFromFile()
{
	size_t count = 0;

	FILE *file;
	fopen_s(&file, "Data.dat", "rb");

	for (int i = 0; i < MAX_CONTACTS; i++)
	{
		fread(&Contacts, sizeof(contacts), MAX_CONTACTS, file);
		if (Contacts[i].firstName[0] != '\0') lastRecord++;
		//Contacts[i] = *p;
	}

	fclose(file);
}

int Contacts_Edit(struct contacts_s *contact)
{
	return 0;
}

void Contacts_ConfirmDelete()
{
	system("cls");
	printf("Are you sure you want to delete all the contacts? [Y/n]\nWaiting for reaction: ");

	switch (getchar())
	{
	case 'y':
		Contacts_Delete();
		system("cls");
		printf("Contacts are successfully deleted!\n\n");
		system("pause");
		break;
	case 'Y':
		Contacts_Delete();
		system("cls");
		printf("Contacts are successfully deleted!\n\n");
		system("pause");
		break;
	case 'n':
		system("cls");
		printf("Contacts are not deleted!\n\n");
		system("pause");
		break;
	case 'N':
		system("cls");
		printf("Contacts are not deleted!\n\n");
		system("pause");
		break;
	}
}

void Contacts_Delete()
{
	FILE * file;
	fopen_s(&file, "Data.dat", "wb");
	fclose(file);
	
	Contacts_Init();
}

void Contacts_Search()
{
	system("cls");

	unsigned char searchString[20];
	printf("Search contact: ");
	scanf("%19s", searchString);

	system("cls");

	printf("Total contacts: %d\n\n", lastRecord);

	const char *firstName = "First Name";
	printf("%-20s | %-21s | %-16s | %-12s\n", "First Name", "Last Name", "Phone Number", "EGN");
	printf("---------------------+-----------------------+------------------+-------------");

	int foundContacts = 0;
	for (int i = 0; i < lastRecord; i++)
	{
		if (strcmp(Contacts[i].firstName, searchString) == 0 ||
			strcmp(Contacts[i].lastName, searchString) == 0)
		{
			printf("\n%*s | ", 20, Contacts[i].firstName);
			printf("%*s | ", 21, Contacts[i].lastName);
			printf("%*s | ", 16, Contacts[i].phoneNumber);
			printf("%*s", 11, Contacts[i].EGN);
			foundContacts++;
		}
	}
	printf("\n---------------------+-----------------------+------------------+-------------");
	printf("\n\nFound: %d", foundContacts);

	printf("\n\nPress ESC key to go back.");
	while (_getch() != ESC);
}

void Contacts_EditByID()
{
	system("cls");

	int contactID;
	printf("Enter contact ID number: ");
	scanf("%d", &contactID);

	if (contactID >= 0 && contactID <= 100)
	{
		printf("\nFirst Name\t: %s", Contacts[contactID].firstName);
		printf("\nLast name\t: %s", Contacts[contactID].lastName);
		printf("\nPhone Number\t: %s", Contacts[contactID].phoneNumber);
		printf("\nEGN:\t\t: %s\n", Contacts[contactID].EGN);

		printf("\n\nEnter new *:\n\n");
		printf("First Name\t: ");
		scanf("%19s", Contacts[contactID].firstName);
		printf("Last Name\t: ");
		scanf("%19s", Contacts[contactID].lastName);
		printf("Phone Number\t: ");
		scanf("%14s", Contacts[contactID].phoneNumber);
		printf("EGN\t\t: ");
		scanf("%10s", Contacts[contactID].EGN);
	}
	else
	{
		printf("\nContact ID should be between 0 and 100");
		printf("\nPress ESC to return.");
	}
	while (_getch() != ESC);
}

void Contacts_EditBySearch()
{
	system("cls");

	unsigned char searchString[20];
	printf("Search contact: ");
	scanf("%19s", searchString);

	system("cls");

	printf("Total contacts: %d\n\n", lastRecord);

	const char *firstName = "First Name";
	printf("%-3s| %-19s| %-20s | %-15s| %-11s\n", "ID", "First Name", "Last Name", "Phone Number", "EGN");
	printf("---+--------------------+----------------------+----------------+-------------");

	int contactID = 0;
	int foundContacts = 0;
	for (int i = 0; i < lastRecord; i++)
	{
		if (strcmp(Contacts[i].firstName, searchString) == 0 ||
			strcmp(Contacts[i].lastName, searchString) == 0)
		{
			contactID = i;
			printf("\n%*d|", 3, i);
			printf("%*s | ", 19, Contacts[i].firstName);
			printf("%*s | ", 20, Contacts[i].lastName);
			printf("%*s | ", 14, Contacts[i].phoneNumber);
			printf("%*s", 10, Contacts[i].EGN);
			foundContacts++;
		}
	}
	printf("\n---+--------------------+----------------------+----------------+-------------");
	printf("\n\nFound: %d\n", foundContacts);

	char ch;
	if (foundContacts == 1)
	{
		printf("Do you want to edit %s %s? [Y/n]: ", Contacts[contactID].firstName, Contacts[contactID].lastName);
		scanf("%1c", &ch);
		if (ch == 'Y' && ch == 'y')
		{
			printf("First Name\t: ");
			scanf("%19s", Contacts[contactID].firstName);
			printf("Last Name\t: ");
			scanf("%19s", Contacts[contactID].lastName);
			printf("Phone Number\t: ");
			scanf("%14s", Contacts[contactID].phoneNumber);
			printf("EGN\t\t: ");
			scanf("%10s", Contacts[contactID].EGN);
		}
	}
	else
	{
		printf("Enter contact ID number to change: ");
		scanf("%d", &contactID);
		if (contactID >= 0 && contactID <= 100)
		{
			printf("First Name\t: ");
			scanf("%19s", Contacts[contactID].firstName);
			printf("Last Name\t: ");
			scanf("%19s", Contacts[contactID].lastName);
			printf("Phone Number\t: ");
			scanf("%14s", Contacts[contactID].phoneNumber);
			printf("EGN\t\t: ");
			scanf("%10s", Contacts[contactID].EGN);
		}
	}
	
	printf("\n\nPress ESC key to go back.");
	while (_getch() != ESC);
}

void Contacts_DiscardChanges()
{
	system("cls");
	printf("Are you sure you want to discard changes? [Y/n]: ");
	if (getchar() == 'y')
	{
		Contacts_Init();
		Contacts_ReadFromFile();
	}
}