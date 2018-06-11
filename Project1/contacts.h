#pragma once

#ifndef CONTACTS_H_
#define CONTACTS_H_

#include "main.h"

struct contacts_s
{
	char firstName[20];
	char lastName[20];
	char phoneNumber[15];
	char EGN[11];
};

struct contacts_s Contacts[MAX_CONTACTS];

/* Private function prototypes ---------------------------------------------- */
void Contacts_Init();
void Contacts_Add();
void Contacts_Remove();
void Contacts_Read();

void Contacts_WriteToFile();

#endif /* CONTACTS_H_ */