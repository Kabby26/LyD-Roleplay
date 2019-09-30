#include <YSI\y_hooks>

// Global interior define
#define MAPS_WHEELMANBASE_INTERIOR      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 350.0;
static Float:DRAWDISTANCE   = 350.0;

// Wheelman points
#define WHEELMANBASE_SPAWN_POINT             938.7240, 1733.3646, 8.8516
#define WHEELMANBASE_SPAWN_POINT_FACING      270.0

// Map variables
new object_wheelmanBase[1];
new pickup_wheelmanBase[1];
new text3D_wheelmanBase[1];

hook OnPlayerConnect(playerid) {
	RemoveBuildingForPlayer(playerid, 1250, 997.4141, 1707.5234, 10.8516, 0.25);
    RemoveBuildingForPlayer(playerid, 1251, 997.0469, 1710.9531, 11.2656, 0.25);
    RemoveBuildingForPlayer(playerid, 1251, 998.0938, 1755.6875, 11.2656, 0.25);
    RemoveBuildingForPlayer(playerid, 1250, 997.7266, 1759.1250, 10.8516, 0.25);
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    // ---
}

hook OnGameModeInit() {
	// Pickups
	pickup_wheelmanBase[0] = CreateDynamicPickup(1240, 1, WHEELMANBASE_SPAWN_POINT, VW_MAIN, MAPS_WHEELMANBASE_INTERIOR); // Wheelman Spawn point
	
    // 3DTextLabels
    text3D_wheelmanBase[0] = _:CreateDynamic3DTextLabel("Wheelman Spawn\n" COLOR_HEX_WHITE "Tippe /Gangwaffen zum Ausrüsten\nTippe /Gheilen zum Heilen", COLOR_BLUE, WHEELMANBASE_SPAWN_POINT, 15.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_WHEELMANBASE_INTERIOR);
    
    // Vehicles

	// Objects
	object_wheelmanBase[0] = CreateDynamicObject(7096, 968.0623, 1677.0314, 12.9567, 0.0000, 0.0000, -180.0000, VW_MAIN, MAPS_WHEELMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
}
