#include "menu.h"
#include "main.h"
#include "contacts.h"

void MenuInit_Main()
{
	node_Main1.name = "Add contact";
	node_Main1.handlerFunc = Contacts_Add;
	node_Main1.child = NULL;

	node_Main2.name = "Edit contact";
	node_Main2.handlerFunc = NULL;
	node_Main2.child = NULL;

	node_Main6.name = "Delete Contacts";
	node_Main6.handlerFunc = Contacts_ConfirmDelete;
	node_Main6.child = NULL;

	node_Main3.name = "Search contact";
	node_Main3.handlerFunc = NULL;
	node_Main3.child = NULL;

	node_Main4.name = "View all contacts";
	node_Main4.handlerFunc = Contacts_Read;
	node_Main4.child = NULL;

	node_Main7.name = "Save changes";
	node_Main7.handlerFunc = Contacts_WriteToFile;
	node_Main7.child = NULL;

	node_Main5.name = "Exit";
	node_Main5.handlerFunc = ApplicationExit;
	node_Main5.child = NULL;

	elements_Main[0] = &node_Main1;
	elements_Main[1] = &node_Main2;
	elements_Main[2] = &node_Main6;
	elements_Main[3] = &node_Main3;
	elements_Main[4] = &node_Main4;
	elements_Main[5] = &node_Main7;
	elements_Main[6] = &node_Main5;

	menu_Main.length = 7;
	menu_Main.parent = NULL;
	menu_Main.menuArray = elements_Main;
}

void Menu_InitContacts()
{
	for (int i = 0; i < lastRecord; i++)
	{
		unsigned char buffer[200] = "";
		strcpy(Contacts[i].firstName)
		node_Contacts[i].name = Contacts[i].firstName;
		node_Contacts[i].handlerFunc = NULL;
		node_Contacts[i].child = NULL;
	}

}