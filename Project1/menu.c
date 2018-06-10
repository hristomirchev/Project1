#include "menu.h"
#include "main.h"
#include <stdio.h>
#include <conio.h>

void Menu_Init()
{
	MenuState.top = 0;
	MenuState.MAX_ROWS = 10;
	MenuState.last_top = 0;
	MenuState.currentItem = 0;
	MenuState.last_currentItem = 0;
	MenuState.currentMenu = &menu_Main;
}

void Menu_Walk()
{
	switch (getch())
	{
	case UP:
		Menu_GoUp(&MenuState);
		Menu_Draw(&MenuState);
		break;
	case DOWN:
		Menu_GoDown(&MenuState);
		Menu_Draw(&MenuState);
		break;
	case RETURN:
		Menu_Select(&MenuState);
		Menu_Draw(&MenuState);
		break;
	case ESC:
		Menu_GoBack(&MenuState);
		Menu_Draw(&MenuState);
		break;
	}
}

void Menu_Draw(struct menuState_s *ms)
{
	uint8_t i;

	system("cls");

	for (i = ms->top; i < ms->top + ms->MAX_ROWS; ++i)
	{
		if (i<ms->currentMenu->length)
		{
			if (ms->currentItem == i)
			{
				Menu_PrintSpecial(ms->currentMenu->menuArray[i]->name);
				Menu_PrintNextLine();
			}
			else
			{
				Menu_PrintNormal(ms->currentMenu->menuArray[i]->name);
				Menu_PrintNextLine();
			}
		}
		else
		{
			Menu_PrintNextLine();
		}
	}
}

void Menu_GoUp(struct menuState_s *ms)
{
	if (!((ms->top == 0) & (ms->currentItem == 0)))
	{
		ms->currentItem = ms->currentItem - 1;

		if (ms->top > ms->currentItem)
		{
			ms->top = ms->top - 1;
		}
	}
	else
	{
		ms->currentItem = ms->currentMenu->length - 1;
		if (ms->currentMenu->length > ms->MAX_ROWS)
		{
			ms->top = ms->currentItem - ms->MAX_ROWS + 1;
		}
	}
	Menu_Draw(&MenuState);
}

void Menu_GoDown(struct menuState_s *ms)
{
	if ((ms->top != ms->currentMenu->length) & (ms->currentItem < ms->currentMenu->length - 1))
	{
		ms->currentItem += 1;

		if (((ms->currentItem) - (ms->top)) == ms->MAX_ROWS)
		{
			ms->top += 1;
		}
	}
	else
	{
		ms->currentItem = 0;
		ms->top = 0;
	}
	Menu_Draw(&MenuState);
}

void Menu_Select(struct menuState_s *ms)
{
	if (ms->currentMenu->menuArray[ms->currentItem]->child != NULL)
	{
		ms->currentMenu = ms->currentMenu->menuArray[ms->currentItem]->child;
		ms->last_top = ms->top;
		ms->last_currentItem = ms->currentItem;
		ms->top = 0;
		ms->currentItem = 0;
		Menu_Draw(&MenuState);
	}
	else if (ms->currentMenu->menuArray[ms->currentItem]->handlerFunc != NULL)
	{
		CALL_FUNCTION(ms->currentMenu->menuArray[ms->currentItem]->handlerFunc);
	}
}

void Menu_GoBack(struct menuState_s *ms)
{
	if (ms->currentMenu->parent != NULL)
	{
		ms->currentMenu = ms->currentMenu->parent;
		ms->top = ms->last_top;
		ms->currentItem = ms->last_currentItem;
	}
	Menu_Draw(&MenuState);
}

void Menu_PrintNormal(const char *message)
{
	printf("  ");
	printf("%s", message);
}

void Menu_PrintSpecial(const char *message)
{
	printf("> ");
	printf("%s", message);
}

void Menu_PrintNextLine()
{
	printf("\n");
}