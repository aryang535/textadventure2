#include "SkibidiToilet.h"
#include "stdafx.h" /* NULL, UNREFERENCED_PARAMETER */
#include "GameState.h" /* struct GameState, GameState_ChangeScore, GameState_EndGame */
#include "GameFlags.h" /* GameFlags_IsInList, GameFlags_Add */
#include "Item.h" /* Item_Create */
#include "Source/Room.h"

typedef struct WorldData WorldData;

void RatTrap_Use(CommandContext context, GameState* gameState, WorldData* worldData)
{
	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(worldData);

	/* safety check on the parameters */
	if (gameState == NULL)
	{
		return; /* take no action if the parameters are invalid */
	}

	GameState_EndGame(gameState, "The Rat Trap clamps on your hand and you get a booboo and start crying.");
}

#include "Source/WorldData.h"

void RatTrap_Drop(CommandContext context, GameState* gameState, WorldData* worldData)
{
	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(worldData);

	/* safety check on the parameters */
	if (gameState == NULL)
	{
		return; /* take no action if the parameters are invalid */
	}
	
	printf("Ding Ding Ding! A new room exit has been made! East.\n");
	Room_AddRoomExit(WorldData_GetRoom(worldData, 4), "east", 5);
}

Item* RatTrap_Build()
{
	return Item_Create("rat_trap", "The Rat Trap is a rat trap. User's Discretion is advised.", true, RatTrap_Use, NULL, RatTrap_Drop);
}
