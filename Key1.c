#include "stdafx.h" /* UNREFERENCED_PARAMETER, NULL*/
#include "Key1.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_ChangeScore */
#include "GameFlags.h" /* GameFlags_IsInList */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_GetItemList, Room_SetDescription */
#include "ItemList.h" /* ItemList_FindItem, ItemList_Remove, ItemList_Add */
#include "Item.h" /* Item_Create */


/* Helper: The action performed when the hotdog is taken. */
void Key1_Take(CommandContext context, GameState* gameState, WorldData* worldData)
{
	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(gameState);
	UNREFERENCED_PARAMETER(worldData);

	/* Give the user a hint about how the cheese might be used, whenever it is picked up. */
	printf("You are now holding the hotdog. If only there was a suspiciously hotdog shaped hole nearby that you could put this hotdog into.\n");
}

void Key1_Use(CommandContext context, GameState* gameState, WorldData* worldData)
{
	Room* room; /* The current room */
	ItemList** roomItemsPtr; /* The list of items in the current room */
	Item* brick; /* The brick in the player's inventory */

	/* safety check on the parameters */
	if ((gameState == NULL) || (worldData == NULL))
	{
		return; /* take no action if the parameters are invalid */
	}

	/* check if the user is using the brick out of their inventory */
	if (context != CommandContext_Item_Inventory)
	{
		/* the user doesn't have the brick - inform the user of the problem and take no action */
		printf("Are you delusional? Are you crazy? Did the rats finally got to you? YOU DON'T HAVE ONE!!! WHAT AN IDIOT!! NEVER HAVE I MET SOMEONE SO STUPID!!!!\n");
		return;
	}

	/* check if we're in the right room to use the item */
	if (gameState->currentRoomIndex != 0)
	{
		/* we are not in the right room - inform the user of the problem and take no action */
		printf("HOW STUPID CAN YOU POSSIBLY BE TO EVEN THINK THAT YOU COULD POSSIBLY USE THAT HERE?!? THERE IS NO INDICATOR WHATSOEVER!!! WHAT AN IDIOT!! EVERYONE LAUGH AT THIS IMBECILE!!! HAHAHAHAHAHAHAA!!\n");
		return;
	}

	/* check if the cage has already been broken and scored */
	if (GameFlags_IsInList(gameState->gameFlags, "hotdogUsed"))
	{
		/* the player already used the brick - inform the user of the problem and take no action */
		printf("Pray, elucidate unto me what DELUSIONS could have possibly infiltrated your SINGULAR BRAIN CELL that you could POSSIBLY think to use an item AFTER YOU NO LONGER HAVE IT!! \n");
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

		/* Find the brick in the player's inventory - it should be there, since we are in the Inventory context */
		brick = ItemList_FindItem(gameState->inventory, "hotdog");

		/* Remove the brick from the user's inventory - they won't need it again */
		gameState->inventory = ItemList_Remove(gameState->inventory, brick);

		/* Tell the user what they did */
		printf("You insert the hotdog into the suspiciously hotdog shaped hole with a noticable squelch. It is an extremely uncomfortable experience.\n");

		printf("Exit added bruh: North\n");
		Room_AddRoomExit(WorldData_GetRoom(worldData, 0), "north", 2);

		/* the gold piece has not been scored, so mark the flag */
		gameState->gameFlags = GameFlags_Add(gameState->gameFlags, "hotdogUsed");
	}
}

Item* Key1_Build()
{


	/* Create a "brick" item, using the functions defined in this file */
	return Item_Create("hotdog", "A hotdog. Reeks of dead rats. Absolutely disguting. Not safe for consumption.", true, Key1_Use, Key1_Take, NULL);
}