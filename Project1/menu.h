#pragma once

#ifndef MENU_H_
#define MENU_H_

#define CALL_FUNCTION(fp) ((*fp)())

#include <stdint.h>
#include <stdio.h>
#include "main.h"

typedef struct menuState_s
{
	uint8_t top;
	uint8_t MAX_ROWS;
	uint8_t last_top;
	uint8_t currentItem;
	uint8_t last_currentItem;
	struct menu_s *currentMenu;
};

typedef struct menuItem_s
{
	const char *name;
	void(*handlerFunc)();
	struct menu_s *child;
};

typedef struct menu_s
{
	uint8_t length;
	struct menu_s *parent;
	struct menuItem_s **menuArray;
};

/* Private function prototypes ---------------------------------------------- */
void Menu_Walk();
void Menu_Draw(struct menuState_s *ms);

void Menu_GoUp(struct menuState_s *ms);
void Menu_GoDown(struct menuState_s *ms);
void Menu_Select(struct menuState_s *ms);
void Menu_GoBack(struct menuState_s *ms);

void Menu_PrintNormal(const char *message);
void Menu_PrintSpecial(const char *message);
void Menu_PrintNextLine();

void MenuInit_Main();

/* Menu Structure ----------------------------------------------------------- */
struct menuItem_s node_Main1;
struct menuItem_s node_Main2;
struct menuItem_s node_Main3;
struct menuItem_s node_Main4;
struct menuItem_s node_Main5;
struct menuItem_s node_Main6;
struct menuItem_s node_Main7;
struct menuItem_s *elements_Main[7];
struct menu_s menu_Main;

struct menuItem_s node_Contacts[MAX_CONTACTS];
struct menuItem_s elements_Contacts[MAX_CONTACTS];

struct menuState_s MenuState;

#endif /* MENU_H_ */