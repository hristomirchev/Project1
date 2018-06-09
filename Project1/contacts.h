#pragma once

#ifndef CONTACTS_H_
#define CONTACTS_H_

#include "main.h"

/* Private function prototypes ---------------------------------------------- */
int Contacts_Add(contacts_s* contacts);
int Contacts_Edit(contacts_s* contacts);
int Contacts_Remove(contacts_s* contacts);
int Contacts_Search(contacts_s* contacts);
void Contacts_Read(contacts_s* contacts);

#endif /* CONTACTS_H_ */