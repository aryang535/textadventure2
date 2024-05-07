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


/* TODO REQUIRED: Build room 0 */
Room* Room0_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* TODO REQUIRED: Call Room_Create with the Room 1 description:
	"This is room 0. It is a display room with a cage in the middle. You can see a jeweled egg inside the cage.  There is a crack in the west wall, but you can't fit through it from this side.\n" */
	room = Room_Create("This is room 0. It is a display room with a cage in the middle. You can see a jeweled egg inside the cage.  There is a crack in the west wall, but you can't fit through it from this side.\n");

	/* TODO REQUIRED: Add an Exit "north" to Room 1 */
	Room_AddRoomExit(room, "north", 1);
	/* TODO BASIC: Add room exit shortcut for "n" */
	Room_AddRoomExit(room, "n", 1);

	/* TODO REQUIRED: add an exit door to the list of items in the room, ExitDoor_Build() */
	ExitDoor_Build();

	/* TODO ADVANCED: (not required) update the description and add a room exit to the "east" */

	/* return the new room */
	return room;
}


/* TODO REQUIRED: Build room 1 |||            Landon Hilton */
Room* Room2_Build()
{
	
	// THE CHEESE CALLS TO ME AHHAHAHAHHAHAHAHAHAHAHHAHA


	Room* room = Room_Create("You enter the cheese room. Cheese. Cheese. Cheese. Cheese. Cheese. Cheese. Hmmmmmmm Cheese. I love Cheese. There is cheese in the room. Do you want cheese?\n");


	Room_AddRoomExit(room, "south", 0);



	//change this to cheese once the cheese is made
	ItemList_AddItem(Room_GetItemList(room), Brick_Build());


	/* return the new room */
	return room;
}

// Landon Hilton
Room* Room3_Build()
{


	Room* room = Room_Create("\n");


	Room_AddRoomExit(room, "north", 4); 

	/* Items
	   add items to the room */
	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());


	/* Return the new room */
	return room;
}


/* TODO REQUIRED: Build room 2 */
Room* Room2_Build()
{
	/* TODO: Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* TODO REQUIRED: Call Room_Create with the Room 2 description:
	"This is room 2.  The room is isolated from the others, but you can see a crack in the east wall, just large enough to get through.\n" */
	room = Room_Create("This is room 2.  The room is isolated from the others, but you can see a crack in the east wall, just large enough to get through.\n");

	/* TODO REQUIRED: Add an Exit "east" to Room 0 */
	Room_AddRoomExit(room, "east", 0);
	/* TODO BASIC: Add exit shortcuts for "e" and "crack" */
	Room_AddRoomExit(room, "e", 0);
	Room_AddRoomExit(room, "crack", 0);

	/* TODO REQUIRED: Add a gold piece to the list of items in the room */
	ItemList_AddItem(Room_GetItemList(room), GoldPiece_Build());
	/* return the new room */
	return room;
}





/* TODO ADVANCED: Build room 3 */
/* TODO ADVANCED: Build room 4 */

Room* Room6_Build()
{
	/* TODO: Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	room = Room_Create("This is room 6. This room is \n");

	/* TODO REQUIRED: Add an Exit "east" to Room 0 */
	Room_AddRoomExit(room, "east", 0);
	/* TODO BASIC: Add exit shortcuts for "e" and "crack" */
	Room_AddRoomExit(room, "e", 0);
	Room_AddRoomExit(room, "crack", 0);

	/* TODO REQUIRED: Add a gold piece to the list of items in the room */
	ItemList_AddItem(Room_GetItemList(room), GoldPiece_Build());
	/* return the new room */
	return room;
}

Room* Room7_Build()
{

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
	int roomCount = 3;

	/* create the new WorldData object with 3 rooms */
	worldData = WorldData_Create("Welcome to my GAM100 Game!\n\n", roomCount);

	/* build each room and assign them to the world data */
	WorldData_SetRoom(worldData, 0, RoomN_Build());
	/* TODO REQUIRED: add rooms 1 and 2 to the world data */
	WorldData_SetRoom(worldData, 1, RoomN_Build());
	WorldData_SetRoom(worldData, 2, RoomN_Build());

	/* TODO ADVANCED: add additional advanced rooms */

	/* return the new object */
	return worldData;
}