/******************************************************************************
filename    WorldDataFactory.c
author      Justin Chambers
DP email    justin.chambers@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file defines the WorldData factory, which creates the WorldData objects used
in this game.

This could be used to create default states as well as loaded state.

******************************************************************************/
#include "WorldDataFactory.h" /* Function declarations */
#include "WorldData.h" /* WorldData_Create, WorldData_SetRoom */
#include "Room.h" /* Room_Create, Room_AddRoomExit, Room_GetItemList */
#include "ItemList.h" /* ItemList_Add */
#include "BrickFunctions.h" /* Brick_Build */
#include "GoldPieceFunctions.h" /* GoldPiece_Build */
#include "ExitDoorFunctions.h" /* ExitDoor_Build */



/******************************************************************************
	Build room TEMPLATE
    Use this example function to build additional rooms
******************************************************************************/
Room* RoomN_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room;

	/* Create the room
	   include an initial room description */
	room = Room_Create("DEBUG: This is a template - Include a description for the room here\n");

	/* Exits
	   add one or more exits to allow navigation between rooms */
	Room_AddRoomExit(room, "north", 1);  /* 1 = the room index this exit connects to */

	/* Items
	   add items to the room */
	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	/* Return the new room */
	return room;

	//https://1drv.ms/p/s!Ah3nZBWhZQF1cRQUItK3veuk7F8?e=gjecZV
}

Room* Room0_Build()
{

	Room* room = Room_Create("This is the rubber room. The rubber room with rats. The rats make you crazy. Crazy? You were crazy once. You were locked in a room. A rubber room. The rubber room makes you crazy. \n");

	/* TODO REQUIRED: Add an Exit "south" back to Room 0 */
	Room_AddRoomExit(room, "south", 1);
	/* TODO BASIC: Add room exit shortcut for "s" */

	/* TODO REQUIRED: Add a brick to the list of items in the room */
	ItemList_AddItem(Room_GetItemList(room), NULL);
	/* return the new room */
	return room;
}

Room* Room1_Build()
{
	Room* room = Room_Create("This is the rat room. This room has rats. It is like the rubber room. The rubber room with the rats. Also. All the rats are deadly. Killer rats.\n");

	Room_AddRoomExit(room, "north", 2);

	/* TODO REQUIRED: Add a brick to the list of items in the room */
	ItemList_AddItem(Room_GetItemList(room), Key1_Build());
	/* return the new room */
	return room;
}

/* TODO REQUIRED: Build room 1 |||            Landon Hilton */
Room* Room2_Build()
{
	
	Room* room = Room_Create("You enter the cheese room. Cheese. Cheese. Cheese. Cheese. Cheese. Cheese. Hmmmmmmm Cheese. I love Cheese. There is cheese in the room. Do you want cheese?\n");


	Room_AddRoomExit(room, "south", 0);


	//change this to cheese once the cheese is made
	ItemList_AddItem(Room_GetItemList(room), Cheese_Build());


	/* return the new room */
	return room;
}

// Landon Hilton
Room* Room3_Build()
{


	Room* room = Room_Create("The room is empty. What did you think there would be? There is definitely nothing here.\n");


	Room_AddRoomExit(room, "north", 4);


	/* Items add items to the room */
	ItemList_AddItem(Room_GetItemList(room), RatTrap_Build());


	/* Return the new room */
	return room;
}





/* TODO ADVANCED: Build room 3 */
/* TODO ADVANCED: Build room 4 */

#include "SkibidiToilet.h"


/*
* The player discovers the SkibidiToilet. If the player is to flush this skibidi toilet, it drowns the player.
*/
Room* Room4_Build()
{
	/* TODO: Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	room = Room_Create("This is room 4. In this room, you see a throne, of which the Rat King is currently seated.\n");

	//Room_AddRoomExit(room, "south", 3);
	//Room_AddRoomExit(room, "east", 5);
	//Room_AddRoomExit(room, "west", 1);

	/* TODO REQUIRED: Add a gold piece to the list of items in the room */
	ItemList_AddItem(Room_GetItemList(room), RatTrap_Build());
	/* return the new room */
	return room;
}

Room* Room5_Build()
{
	return NULL;
}


/* ------------------------------------------------------- */
/* Create the world data for a new game */
/* ------------------------------------------------------- */
WorldData* CreateInitialWorldData()
{
	/* The new world data */
	WorldData* worldData;

	/* TODO REQUIRED: update room count to match the number of rooms you have created and added to the world
	   if this number doesn't match then your game will either crash or you will end up stuck in a broken room with no exits */
	int roomCount = 6;

	/* create the new WorldData object with 3 rooms */
	worldData = WorldData_Create("Welcome to Rubber Room™\n\n", roomCount);

	/* build each room and assign them to the world data */
	WorldData_SetRoom(worldData, 0, Room0_Build());
	/* TODO REQUIRED: add rooms 1 and 2 to the world data */
	WorldData_SetRoom(worldData, 1, Room1_Build());
	WorldData_SetRoom(worldData, 2, Room2_Build());
	WorldData_SetRoom(worldData, 3, Room3_Build());
	WorldData_SetRoom(worldData, 4, Room4_Build());
	WorldData_SetRoom(worldData, 5, Room5_Build());

	/* TODO ADVANCED: add additional advanced rooms */

	/* return the new object */
	return worldData;
}