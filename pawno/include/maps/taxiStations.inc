#include <YSI\y_hooks>

// Global interior define
#define MAPS_TAXISTATIONS_INTERIOR      0

// Local drawdistance & streamdistance setting
//static Float:STREAMDISTANCE = 350.0;
//static Float:DRAWDISTANCE   = 350.0;

// Taxi stations in LS points
#define TAXISTATIONS_JOBSKIN_POINT_CITYHALL     1442.4465,-1639.1947,13.6280
//#define TAXISTATIONS_JOBSKIN_POINT_BUSSTATION   1272.3879, -1353.3357, 13.5069

// Map variables
new pickup_taxiStations[1];
new text3D_taxiStations[1];
//new actor_taxiStations[2];
new vehicle_taxiStations[6];

hook OnPlayerConnect(playerid) {
    // ---
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
	// ---
}

hook OnGameModeInit() {
    // Pickups
    pickup_taxiStations[0] = CreateDynamicPickup(1275, 1, TAXISTATIONS_JOBSKIN_POINT_CITYHALL, VW_MAIN, MAPS_TAXISTATIONS_INTERIOR); // Job clothes point
    //pickup_taxiStations[1] = CreateDynamicPickup(1275, 1, TAXISTATIONS_JOBSKIN_POINT_BUSSTATION, VW_MAIN, MAPS_TAXISTATIONS_INTERIOR); // Job clothes point

    // 3DTextLabels
    text3D_taxiStations[0] = _:CreateDynamic3DTextLabel("Arbeitskleidung f�r Taxifahrer\n" COLOR_HEX_WHITE "Tippe /Jobkleidung", COLOR_YELLOW, TAXISTATIONS_JOBSKIN_POINT_CITYHALL, 25.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_TAXISTATIONS_INTERIOR); // Job clothes
    //text3D_taxiStations[1] = _:CreateDynamic3DTextLabel("Arbeitskleidung f�r Taxifahrer\n" COLOR_HEX_WHITE "Tippe /Jobkleidung", COLOR_YELLOW, TAXISTATIONS_JOBSKIN_POINT_BUSSTATION, 25.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_TAXISTATIONS_INTERIOR); // Job clothes
    
    // Actors
	/*
    actor_taxiStations[0] = CreateDynamicActor(189, 1438.5156, -1696.6446, 13.5469, 359.6128, .worldid = VW_MAIN, .interiorid = MAPS_TAXISTATIONS_INTERIOR); // Greeting woman
    ApplyDynamicActorAnimation(actor_taxiStations[0], "SHOP", "Smoke_RYD", 4.0, 1, 0, 0, 0, 0);

    actor_taxiStations[1] = CreateDynamicActor(189, 1271.5378, -1350.7891, 13.5032, 271.0947, .worldid = VW_MAIN, .interiorid = MAPS_TAXISTATIONS_INTERIOR); // Greeting woman
    ApplyDynamicActorAnimation(actor_taxiStations[1], "GANGS", "leanIDLE", 4.0, 1, 0, 0, 0, 0);
    */
    // Vehicles
    /*vehicle_taxiStations[0] = AddStaticVehicleEx(420, 1484.7172, -1662.0835, 13.5004, 178.9520, 6, 6, 60*10); // Taxicar1
    vehicle_taxiStations[1] = AddStaticVehicleEx(438, 1488.8422, -1662.3359, 13.2709, 179.3681, 6, 6, 60*10); // Taxicar1
    vehicle_taxiStations[2] = AddStaticVehicleEx(420, 1493.6617, -1662.5077, 13.2709, 179.3681, 6, 6, 60*10); // Taxicar1
    vehicle_taxiStations[3] = AddStaticVehicleEx(420, 1498.2452, -1661.9644, 13.5002, 178.9830, 6, 6, 60*10); // Taxicar1*/

    vehicle_taxiStations[0] = AddStaticVehicleEx(420, 1457.3201,-1642.9407,13.2789,90.1557, 6, 6, 60*10);
    vehicle_taxiStations[1] = AddStaticVehicleEx(420, 1470.3037,-1642.9843,13.1810,90.2907, 6, 6, 60*10);
    vehicle_taxiStations[2] = AddStaticVehicleEx(420, 1489.1276,-1643.2502,13.4129,269.7363, 6, 6, 60*10);
    vehicle_taxiStations[3] = AddStaticVehicleEx(420, 1502.7079,-1643.0225,13.1812,270.1382, 6, 6, 60*10);
    vehicle_taxiStations[4] = AddStaticVehicleEx(420, 1517.0214,-1643.0815,13.4214,269.0073, 6, 6, 60*10);
    vehicle_taxiStations[5] = AddStaticVehicleEx(420, 1443.0872,-1643.0731,13.1547,90.5903, 6, 6, 60*10);
 

	// Objects
    /*object_taxiStations[0] = CreateDynamicObject(997, 1434.7246, -1717.3287, 12.6930, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TAXISTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier3
    object_taxiStations[1] = CreateDynamicObject(997, 1437.8950, -1714.1589, 12.6930, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_TAXISTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier3
    object_taxiStations[2] = CreateDynamicObject(997, 1437.8950, -1709.7183, 12.6930, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_TAXISTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier3
    object_taxiStations[3] = CreateDynamicObject(997, 1437.8950, -1705.2983, 12.6930, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_TAXISTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier3
    object_taxiStations[4] = CreateDynamicObject(997, 1437.8950, -1700.9489, 12.6930, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_TAXISTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier3
    object_taxiStations[5] = CreateDynamicObject(997, 1437.8950, -1696.8385, 12.6930, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_TAXISTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier3
    object_taxiStations[6] = CreateDynamicObject(997, 1437.5148, -1696.0311, 12.6930, 0.0000, 0.0000, 135.4999, VW_MAIN, MAPS_TAXISTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier3
    object_taxiStations[7] = CreateDynamicObject(19174, 1436.1149, -1697.5141, 12.6319, -89.5999, 0.0000, 0.0000, VW_MAIN, MAPS_TAXISTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
    SetDynamicObjectMaterialText(object_taxiStations[7], 0, "T", 90, "Arial", 150, 1, 0xFFD78E10, 0x0, 1);
    SetDynamicObjectMaterial(object_taxiStations[7], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_taxiStations[8] = CreateDynamicObject(19174, 1436.1149, -1704.0549, 12.5864, -89.5999, 0.0000, 0.0000, VW_MAIN, MAPS_TAXISTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
    SetDynamicObjectMaterialText(object_taxiStations[8], 0, "T", 90, "Arial", 150, 1, 0xFFD78E10, 0x0, 1);
    SetDynamicObjectMaterial(object_taxiStations[8], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_taxiStations[9] = CreateDynamicObject(19174, 1436.1149, -1698.8045, 12.6229, -89.5999, 0.0000, 0.0000, VW_MAIN, MAPS_TAXISTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
    SetDynamicObjectMaterialText(object_taxiStations[9], 0, "A", 90, "Arial", 150, 1, 0xFFD78E10, 0x0, 1);
    SetDynamicObjectMaterial(object_taxiStations[9], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_taxiStations[10] = CreateDynamicObject(19174, 1436.1149, -1700.1248, 12.6137, -89.5999, 0.0000, 0.0000, VW_MAIN, MAPS_TAXISTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
    SetDynamicObjectMaterialText(object_taxiStations[10], 0, "X", 90, "Arial", 150, 1, 0xFFD78E10, 0x0, 1);
    SetDynamicObjectMaterial(object_taxiStations[10], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_taxiStations[11] = CreateDynamicObject(19174, 1436.1149, -1701.4348, 12.6047, -89.5999, 0.0000, 0.0000, VW_MAIN, MAPS_TAXISTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
    SetDynamicObjectMaterialText(object_taxiStations[11], 0, "I", 90, "Arial", 150, 1, 0xFFD78E10, 0x0, 1);
    SetDynamicObjectMaterial(object_taxiStations[11], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_taxiStations[12] = CreateDynamicObject(19174, 1436.1149, -1705.4854, 12.5764, -89.5999, 0.0000, 0.0000, VW_MAIN, MAPS_TAXISTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
    SetDynamicObjectMaterialText(object_taxiStations[12], 0, "A", 90, "Arial", 150, 1, 0xFFD78E10, 0x0, 1);
    SetDynamicObjectMaterial(object_taxiStations[12], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_taxiStations[13] = CreateDynamicObject(19174, 1436.1149, -1713.4157, 12.5420, -89.5999, 0.0000, 0.0000, VW_MAIN, MAPS_TAXISTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
    SetDynamicObjectMaterialText(object_taxiStations[13], 0, "X", 90, "Arial", 150, 1, 0xFFD78E10, 0x0, 1);
    SetDynamicObjectMaterial(object_taxiStations[13], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_taxiStations[14] = CreateDynamicObject(19174, 1436.1149, -1708.2158, 12.5577, -89.5999, 0.0000, 0.0000, VW_MAIN, MAPS_TAXISTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
    SetDynamicObjectMaterialText(object_taxiStations[14], 0, "I", 90, "Arial", 150, 1, 0xFFD78E10, 0x0, 1);
    SetDynamicObjectMaterial(object_taxiStations[14], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_taxiStations[15] = CreateDynamicObject(19174, 1436.1149, -1710.8138, 12.5390, -89.5999, 0.0000, 0.0000, VW_MAIN, MAPS_TAXISTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
    SetDynamicObjectMaterialText(object_taxiStations[15], 0, "T", 90, "Arial", 150, 1, 0xFFD78E10, 0x0, 1);
    SetDynamicObjectMaterial(object_taxiStations[15], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_taxiStations[16] = CreateDynamicObject(19174, 1436.1149, -1712.1351, 12.5409, -89.5999, 0.0000, 0.0000, VW_MAIN, MAPS_TAXISTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
    SetDynamicObjectMaterialText(object_taxiStations[16], 0, "A", 90, "Arial", 150, 1, 0xFFD78E10, 0x0, 1);
    SetDynamicObjectMaterial(object_taxiStations[16], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_taxiStations[17] = CreateDynamicObject(19174, 1436.1149, -1714.8057, 12.5615, -89.5999, 0.0000, 0.0000, VW_MAIN, MAPS_TAXISTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
    SetDynamicObjectMaterialText(object_taxiStations[17], 0, "I", 90, "Arial", 150, 1, 0xFFD78E10, 0x0, 1);
    SetDynamicObjectMaterial(object_taxiStations[17], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_taxiStations[18] = CreateDynamicObject(19174, 1436.1149, -1706.8759, 12.5667, -89.5999, 0.0000, 0.0000, VW_MAIN, MAPS_TAXISTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
    SetDynamicObjectMaterialText(object_taxiStations[18], 0, "X", 90, "Arial", 150, 1, 0xFFD78E10, 0x0, 1);
    SetDynamicObjectMaterial(object_taxiStations[18], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_taxiStations[19] = CreateDynamicObject(19978, 1437.9177, -1706.9104, 11.4004, 0.0000, 0.0000, -90.1000, VW_MAIN, MAPS_TAXISTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign31
    object_taxiStations[20] = CreateDynamicObject(19978, 1437.9023, -1715.7908, 11.4004, 0.0000, 0.0000, -90.1000, VW_MAIN, MAPS_TAXISTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign31
    object_taxiStations[21] = CreateDynamicObject(19978, 1437.9321, -1698.4501, 11.4004, 0.0000, 0.0000, -90.1000, VW_MAIN, MAPS_TAXISTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign31
    object_taxiStations[22] = CreateDynamicObject(1256, 1438.4429, -1711.3146, 13.2020, 0.0000, 0.0000, -179.8999, VW_MAIN, MAPS_TAXISTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Stonebench1
    object_taxiStations[23] = CreateDynamicObject(1256, 1438.4279, -1702.5445, 13.2020, 0.0000, 0.0000, -179.8999, VW_MAIN, MAPS_TAXISTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Stonebench1
    object_taxiStations[24] = CreateDynamicObject(1360, 1438.6650, -1715.7471, 13.3027, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TAXISTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BUSH_PROP3
    object_taxiStations[25] = CreateDynamicObject(1360, 1438.6650, -1706.9174, 13.3027, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TAXISTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BUSH_PROP3
    object_taxiStations[26] = CreateDynamicObject(1360, 1438.6650, -1698.4475, 13.3027, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_TAXISTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BUSH_PROP3
    object_taxiStations[27] = CreateDynamicObject(19425, 1434.5103, -1715.6916, 12.3527, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_TAXISTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //speed_bump01
    object_taxiStations[28] = CreateDynamicObject(19425, 1434.5103, -1712.4017, 12.3527, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_TAXISTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //speed_bump01
    object_taxiStations[29] = CreateDynamicObject(19425, 1434.5103, -1709.1115, 12.3527, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_TAXISTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //speed_bump01
    object_taxiStations[30] = CreateDynamicObject(19425, 1434.5103, -1705.8208, 12.3527, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_TAXISTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //speed_bump01
    object_taxiStations[31] = CreateDynamicObject(19425, 1434.5103, -1702.5306, 12.3527, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_TAXISTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //speed_bump01
    object_taxiStations[32] = CreateDynamicObject(19425, 1434.5103, -1699.2298, 12.3527, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_TAXISTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //speed_bump01
    object_taxiStations[33] = CreateDynamicObject(19425, 1434.5103, -1695.9299, 12.3527, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_TAXISTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //speed_bump01
    object_taxiStations[34] = CreateDynamicObject(19425, 1434.9079, -1718.8837, 12.3527, 0.0000, 0.0000, -75.8999, VW_MAIN, MAPS_TAXISTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //speed_bump01
    object_taxiStations[35] = CreateDynamicObject(19425, 1434.9049, -1692.7419, 12.3527, 0.0000, 0.0000, 75.8999, VW_MAIN, MAPS_TAXISTATIONS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //speed_bump01*/
}