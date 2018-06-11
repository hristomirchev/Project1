#include "menu.h"
#include "main.h"
#include "contacts.h"

void Menu_InitMain()
{
	node_Main1.name = "Add contact";
	node_Main1.handlerFunc = Contacts_Add;
	node_Main1.child = NULL;

	node_Main2.name = "Edit contact";
	node_Main2.handlerFunc = NULL;
	node_Main2.child = &menu_EditContact;

	node_Main6.name = "Delete Contacts";
	node_Main6.handlerFunc = Contacts_ConfirmDelete;
	node_Main6.child = NULL;

	node_Main3.name = "Search contact";
	node_Main3.handlerFunc = Contacts_Search;
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

	node_Main8.name = "Discard Changes";
	node_Main8.handlerFunc = Contacts_DiscardChanges;
	node_Main8.child = NULL;

	elements_Main[0] = &node_Main1;
	elements_Main[1] = &node_Main2;
	elements_Main[2] = &node_Main6;
	elements_Main[3] = &node_Main3;
	elements_Main[4] = &node_Main4;
	elements_Main[5] = &node_Main7;
	elements_Main[6] = &node_Main8;
	elements_Main[7] = &node_Main5;

	menu_Main.length = 8;
	menu_Main.parent = NULL;
	menu_Main.menuArray = elements_Main;
}

void Menu_InitEditContact()
{
	node_EditContact1.name = "Edit by ID";
	node_EditContact1.handlerFunc = Contacts_EditByID;
	node_EditContact1.child = NULL;

	node_Editcontact2.name = "Search in contacts";
	node_Editcontact2.handlerFunc = Contacts_EditBySearch;
	node_Editcontact2.child = NULL;

	elements_EditContact[0] = &node_EditContact1;
	elements_EditContact[1] = &node_Editcontact2;

	menu_EditContact.length = 2;
	menu_EditContact.parent = &menu_Main;
	menu_EditContact.menuArray = elements_EditContact;
}