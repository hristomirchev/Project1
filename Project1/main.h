#pragma once

#ifndef MAIN_H_
#define MAIN_H_

#define MAX_CONTACTS 100

#define UP		72
#define DOWN	80
#define RETURN		13
#define ESC		27

struct contacts_s
{
	char firstName[20];
	char lastName[20];
	char phoneNumber[12];
	char EGN[10];
};

struct contacts_s Contact;

/* Private function prototypes ---------------------------------------------- */
void ApplicationExit();

#endif /* MAIN_H_ */