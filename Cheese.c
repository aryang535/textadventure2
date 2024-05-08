/******************************************************************************
filename    CheeseFunctions.c
author      Landon Hilton
course      GAM100 

Brief Description:
This file defines the functions to create a specific item, the "cheese".

******************************************************************************/
#include "stdafx.h" /* UNREFERENCED_PARAMETER, NULL*/
#include "Cheese.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_ChangeScore */
#include "GameFlags.h" /* GameFlags_IsInList */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_GetItemList, Room_SetDescription */
#include "ItemList.h" /* ItemList_FindItem, ItemList_Remove, ItemList_Add */
#include "Item.h" /* Item_Create */


/* Helper: The action performed when the cheese is taken. */
void Cheese_Take(CommandContext context, GameState* gameState, WorldData* worldData)
{
	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(gameState);
	UNREFERENCED_PARAMETER(worldData);

	/* Give the user a hint about how the cheese might be used, whenever it is picked up. */
	printf("The Cheese feels heavy in your hand.\n");
}


/* Helper: The action performed when the brick is used. */
void Cheese_Use(CommandContext context, GameState* gameState, WorldData* worldData)
{
	Room* room; /* The current room */
	ItemList** roomItemsPtr; /* The list of items in the current room */
	Item* cheese; /* The brick in the player's inventory */

	/* safety check on the parameters */
	if ((gameState == NULL) || (worldData == NULL))
	{
		return; /* take no action if the parameters are invalid */
	}

	/* check if the user is using the brick out of their inventory */
	if (context != CommandContext_Item_Inventory)
	{
		/* the user doesn't have the brick - inform the user of the problem and take no action */
		printf("You must have the cheese before you can use it.\n");
		return;
	}

	/* check if we're in the right room to use the item */
	if (gameState->currentRoomIndex != 1)
	{
		/* we are not in the right room - inform the user of the problem and take no action */
		printf("You cannot use the cheese here.\n");
		return;
	}

	/* check if the cage has already been broken and scored */
	if (GameFlags_IsInList(gameState->gameFlags, "CheeseUsed"))
	{
		/* the player already used the brick - inform the user of the problem and take no action */
		printf("You already used the cheese here.\n");
		return;
	}
	else
	{
		/* get the current room */
		room = WorldData_GetRoom(worldData, gameState->currentRoomIndex);

		/* get the list of items in the current room */
		roomItemsPtr = Room_GetItemList(room);
		if (roomItemsPtr == NULL)
		{
			return; /* take no action, as something is wrong - we should always have an item list */
		}

		/* Find the cheese in the player's inventory - it should be there, since we are in the Inventory context */
		cheese = ItemList_FindItem(gameState->inventory, "cheese");

		/* Remove the cheese from the user's inventory - they won't need it again */
		gameState->inventory = ItemList_Remove(gameState->inventory, cheese);

		/* Tell the user what they did */
		printf("You command the rats with the Cheese. A man upon his throne. A sword of Cheese. The rats now follow you.\n");


		/* Update the room description to reflect the change in the room */
		Room_SetDescription(room, "The rats have eaten through the door.\n");

		/* Adds an exit to room 1 */
		Room_AddRoomExit(WorldData_GetRoom(worldData, 1), "east", 4);

		/* the gold piece has not been scored, so mark the flag */
		gameState->gameFlags = GameFlags_Add(gameState->gameFlags, "CheeseUsed");
	}
}


/* Build a "cheese" object */
Item* Cheese_Build()
{
	/* Create a "cheese" item, using the functions defined in this file */
	return Item_Create("cheese", "cheese", true, Cheese_Use, Cheese_Take, NULL);
}