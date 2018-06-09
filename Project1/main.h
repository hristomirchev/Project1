#pragma once

#ifndef MAIN_H_
#define MAIN_H_

typedef struct
{
	const char* firstName;
	const char* lastName;
	const char* phoneNumber;
	const char* EGN;
} contacts_s;

contacts_s Contacts[100];

/* Private function prototypes ---------------------------------------------- */
int DisplayContacts(contacts_s* contacts);

#endif /* MAIN_H_ */