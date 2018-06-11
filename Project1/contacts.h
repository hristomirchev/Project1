#pragma once

#ifndef CONTACTS_H_
#define CONTACTS_H_

#include "main.h"

typedef struct contacts_s
{
	char firstName[20];
	char lastName[20];
	char phoneNumber[15];
	char EGN[11];
} contacts;

struct contacts_s Contacts[MAX_CONTACTS];

/* Private function prototypes ---------------------------------------------- */
void Contacts_Init();
void Contacts_Add();
void Contacts_Delete(); 
void Contacts_ConfirmDelete();
void Contacts_Read();
void Contacts_Search();
void Contacts_EditByID();
void Contacts_EditBySearch();
void Contacts_DiscardChanges();

void Contacts_WriteToFile();
void Contacts_ReadFromFile();

#endif /* CONTACTS_H_ */