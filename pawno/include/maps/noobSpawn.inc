#include <YSI\y_hooks>

// Global interior define
#define MAPS_NOOBSPAWN_INTERIOR      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 250.0;
static Float:DRAWDISTANCE   = 230.0;

// Noob spawn in LS points
#define NOOBSPAWN_STARTBONUS_POINT   809.3212, -1339.9855, 13.5408
#define NOOBSPAWN_SERVERINFO_POINT   817.4735, -1345.8376, 13.5269

// Map variables
new object_noobSpawn[54];
new pickup_noobSpawn[2];
new text3D_noobSpawn[2];
//new actor_noobSpawn[2];

hook OnPlayerConnect(playerid) {
    // ---
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
	// ---
}

hook OnGameModeInit() {
    // Map Icon
    CreateDynamicMapIcon(NOOBSPAWN_STARTBONUS_POINT, 38, 0, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR); // S icon for spawn

    // Pickups
    pickup_noobSpawn[0] = CreateDynamicPickup(1239, 1, NOOBSPAWN_SERVERINFO_POINT, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR); // Server info point
    pickup_noobSpawn[1] = CreateDynamicPickup(1239, 1, NOOBSPAWN_STARTBONUS_POINT, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR); // Start bonus point

    // 3DTextLabels
    text3D_noobSpawn[0] = _:CreateDynamic3DTextLabel("Server Informationen\n" COLOR_HEX_WHITE "Tippe /Info", COLOR_GREEN, NOOBSPAWN_SERVERINFO_POINT, 15.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_NOOBSPAWN_INTERIOR);
    text3D_noobSpawn[1] = _:CreateDynamic3DTextLabel("Startbonus\n" COLOR_HEX_RED "Tippe: /Startbonus", COLOR_GREEN, NOOBSPAWN_STARTBONUS_POINT, 20.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_NOOBSPAWN_INTERIOR);

    object_noobSpawn[0] = CreateDynamicObject(19447, 809.3823, -1344.1517, 17.9496, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_noobSpawn[0], 0, 18065, "ab_sfammumain", "breezewall", 0x00000000);
    object_noobSpawn[1] = CreateDynamicObject(19464, 816.5775, -1356.9693, 12.9498, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_noobSpawn[1], 0, 18065, "ab_sfammumain", "breezewall", 0x00000000);
    object_noobSpawn[2] = CreateDynamicObject(19447, 809.3823, -1353.7734, 17.9496, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_noobSpawn[2], 0, 18065, "ab_sfammumain", "breezewall", 0x00000000);
    object_noobSpawn[3] = CreateDynamicObject(19447, 814.1115, -1339.3393, 17.9496, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_noobSpawn[3], 0, 18065, "ab_sfammumain", "breezewall", 0x00000000);
    object_noobSpawn[4] = CreateDynamicObject(19447, 823.7412, -1339.3393, 17.9496, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall087
    SetDynamicObjectMaterial(object_noobSpawn[4], 0, 18065, "ab_sfammumain", "breezewall", 0x00000000);
    object_noobSpawn[5] = CreateDynamicObject(19464, 810.6477, -1356.9693, 12.9498, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_noobSpawn[5], 0, 18065, "ab_sfammumain", "breezewall", 0x00000000);
    object_noobSpawn[6] = CreateDynamicObject(19933, 827.7014, -1338.2187, 15.0797, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKWallOven1
    SetDynamicObjectMaterial(object_noobSpawn[6], 0, 18065, "ab_sfammumain", "breezewall", 0xFFFFFFFF);
    object_noobSpawn[7] = CreateDynamicObject(18981, 820.1746, -1349.8701, 20.0464, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_noobSpawn[7], 0, 18065, "ab_sfammumain", "gun_floor1", 0xFFFFFAFA);
    object_noobSpawn[8] = CreateDynamicObject(19464, 822.4882, -1356.9693, 12.9498, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_noobSpawn[8], 0, 18065, "ab_sfammumain", "breezewall", 0x00000000);
    object_noobSpawn[9] = CreateDynamicObject(19464, 828.4082, -1356.9693, 12.9498, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_noobSpawn[9], 0, 18065, "ab_sfammumain", "breezewall", 0x00000000);
    object_noobSpawn[10] = CreateDynamicObject(19464, 827.5888, -1347.5273, 12.9498, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_noobSpawn[10], 0, 18065, "ab_sfammumain", "breezewall", 0x00000000);
    object_noobSpawn[11] = CreateDynamicObject(19464, 827.5888, -1353.4659, 12.9600, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_noobSpawn[11], 0, 18065, "ab_sfammumain", "breezewall", 0x00000000);
    object_noobSpawn[12] = CreateDynamicObject(19464, 827.5888, -1359.3962, 12.9399, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_noobSpawn[12], 0, 18065, "ab_sfammumain", "breezewall", 0x00000000);
    object_noobSpawn[13] = CreateDynamicObject(19464, 827.5888, -1346.2663, 18.0499, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_noobSpawn[13], 0, 18065, "ab_sfammumain", "breezewall", 0x00000000);
    object_noobSpawn[14] = CreateDynamicObject(19464, 827.5888, -1352.1949, 18.0499, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_noobSpawn[14], 0, 18065, "ab_sfammumain", "breezewall", 0x00000000);
    object_noobSpawn[15] = CreateDynamicObject(19464, 828.4082, -1356.9693, 18.0499, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_noobSpawn[15], 0, 18065, "ab_sfammumain", "breezewall", 0x00000000);
    object_noobSpawn[16] = CreateDynamicObject(19464, 822.4882, -1356.9693, 18.0499, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_noobSpawn[16], 0, 18065, "ab_sfammumain", "breezewall", 0x00000000);
    object_noobSpawn[17] = CreateDynamicObject(19464, 816.5775, -1356.9693, 18.0499, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_noobSpawn[17], 0, 18065, "ab_sfammumain", "breezewall", 0x00000000);
    object_noobSpawn[18] = CreateDynamicObject(19464, 810.6477, -1356.9693, 18.0499, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_noobSpawn[18], 0, 18065, "ab_sfammumain", "breezewall", 0x00000000);
    object_noobSpawn[19] = CreateDynamicObject(19464, 827.5888, -1358.1247, 18.0400, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_noobSpawn[19], 0, 18065, "ab_sfammumain", "breezewall", 0x00000000);
    object_noobSpawn[20] = CreateDynamicObject(19464, 827.5786, -1340.3348, 18.0599, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_noobSpawn[20], 0, 18065, "ab_sfammumain", "breezewall", 0x00000000);
    object_noobSpawn[21] = CreateDynamicObject(19933, 827.7014, -1337.6684, 15.0797, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKWallOven1
    SetDynamicObjectMaterial(object_noobSpawn[21], 0, 18065, "ab_sfammumain", "breezewall", 0xFFFFFFFF);
    object_noobSpawn[22] = CreateDynamicObject(19933, 827.7014, -1337.6684, 14.2096, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKWallOven1
    SetDynamicObjectMaterial(object_noobSpawn[22], 0, 18065, "ab_sfammumain", "breezewall", 0xFFFFFFFF);
    object_noobSpawn[23] = CreateDynamicObject(19933, 827.7014, -1337.6684, 12.4596, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKWallOven1
    SetDynamicObjectMaterial(object_noobSpawn[23], 0, 18065, "ab_sfammumain", "breezewall", 0xFFFFFFFF);
    object_noobSpawn[24] = CreateDynamicObject(19933, 827.7014, -1337.6684, 13.3396, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKWallOven1
    SetDynamicObjectMaterial(object_noobSpawn[24], 0, 18065, "ab_sfammumain", "breezewall", 0xFFFFFFFF);
    object_noobSpawn[25] = CreateDynamicObject(19933, 827.7014, -1338.2187, 14.2096, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKWallOven1
    SetDynamicObjectMaterial(object_noobSpawn[25], 0, 18065, "ab_sfammumain", "breezewall", 0xFFFFFFFF);
    object_noobSpawn[26] = CreateDynamicObject(19933, 827.7014, -1338.2187, 13.3498, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKWallOven1
    SetDynamicObjectMaterial(object_noobSpawn[26], 0, 18065, "ab_sfammumain", "breezewall", 0xFFFFFFFF);
    object_noobSpawn[27] = CreateDynamicObject(19933, 827.7014, -1338.2187, 12.4696, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKWallOven1
    SetDynamicObjectMaterial(object_noobSpawn[27], 0, 18065, "ab_sfammumain", "breezewall", 0xFFFFFFFF);
    object_noobSpawn[28] = CreateDynamicObject(19786, 809.4688, -1351.4438, 17.6622, 5.0000, 0.0000, 90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LCDTVBig1
    object_noobSpawn[29] = CreateDynamicObject(640, 811.1193, -1356.4018, 13.0853, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush2
    object_noobSpawn[30] = CreateDynamicObject(19786, 809.4688, -1344.5146, 17.6622, 5.0000, 0.0000, 90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LCDTVBig1
    object_noobSpawn[31] = CreateObject(19172, 809.6021, -1347.8487, 17.6746, 8.6000, 0.0000, 90.0000); //SAMPPicture1
    SetObjectMaterialText(object_noobSpawn[31], "Herzlich Willkommen!", 0, OBJECT_MATERIAL_SIZE_256x128, "Arial", 24, 1, 0xFFFFFFFF, 0x00000000, 1);
    SetObjectMaterialText(object_noobSpawn[31], "", 1, OBJECT_MATERIAL_SIZE_256x128, "Arial", 24, 1, 0xFFFFFFFF, 0x00000000, 0);
    object_noobSpawn[32] = CreateDynamicObject(19786, 809.4688, -1347.8658, 17.6622, 5.0000, 0.0000, 90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LCDTVBig1
    object_noobSpawn[33] = CreateObject(19172, 809.6021, -1351.4200, 17.6746, 8.6000, 0.0000, 90.0000); //SAMPPicture1
    SetObjectMaterialText(object_noobSpawn[33], "monkey-roleplay.de", 0, OBJECT_MATERIAL_SIZE_256x128, "Arial", 24, 1, 0xFFFFFFFF, 0x00000000, 1);
    SetObjectMaterialText(object_noobSpawn[33], "", 1, OBJECT_MATERIAL_SIZE_256x128, "Arial", 24, 1, 0xFFFFFFFF, 0x00000000, 0);
    object_noobSpawn[34] = CreateObject(19172, 837.4721, -1357.5288, 21.8057, 0.0000, 0.0000, -90.0000); //SAMPPicture1
    SetObjectMaterialText(object_noobSpawn[34], "Call Wasio: Tel.: +49 421 390 4 7777", 0, OBJECT_MATERIAL_SIZE_256x128, "Arial", 24, 0, 0xFFFFFFFF, 0x00000000, 1);
    SetObjectMaterialText(object_noobSpawn[34], "", 1, OBJECT_MATERIAL_SIZE_256x128, "Arial", 10, 1, 0xFFFFFFFF, 0x00000000, 0);
    SetObjectMaterialText(object_noobSpawn[34], "Example Text", 2, OBJECT_MATERIAL_SIZE_256x128, "Arial", 24, 1, 0xFFFFFFFF, 0x00000000, 0);
    object_noobSpawn[35] = CreateDynamicObject(640, 821.7105, -1356.4018, 13.0853, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush2
    object_noobSpawn[36] = CreateDynamicObject(1280, 816.4568, -1356.5080, 12.9144, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //parkbench1
    object_noobSpawn[37] = CreateDynamicObject(640, 827.0703, -1348.8016, 13.0853, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush2
    object_noobSpawn[38] = CreateDynamicObject(640, 824.6304, -1337.8608, 13.0853, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush2
    object_noobSpawn[39] = CreateDynamicObject(640, 817.7382, -1337.8608, 13.0853, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush2
    object_noobSpawn[40] = CreateDynamicObject(640, 810.5885, -1337.8608, 13.0853, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush2
    object_noobSpawn[41] = CreateDynamicObject(19126, 821.1812, -1337.8287, 13.0666, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight6
    object_noobSpawn[42] = CreateDynamicObject(19126, 814.1812, -1337.8287, 13.0666, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight6
    object_noobSpawn[43] = CreateObject(19173, 827.2185, -1354.4537, 12.3493, 0.0000, 0.0000, 90.0000); //SAMPPicture2
    SetObjectMaterialText(object_noobSpawn[43], "#WASIO", 0, OBJECT_MATERIAL_SIZE_256x128, "Segoe Print", 24, 1, 0xFFE6E6FA, 0x00000000, 0);
    SetObjectMaterialText(object_noobSpawn[43], "Example Text", 1, OBJECT_MATERIAL_SIZE_256x128, "Arial", 24, 1, 0xFFFFFFFF, 0x00000000, 0);
    object_noobSpawn[44] = CreateDynamicObject(970, 808.0289, -1353.6430, 13.0836, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    object_noobSpawn[45] = CreateDynamicObject(1280, 816.5169, -1346.7257, 12.9144, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //parkbench1
    object_noobSpawn[46] = CreateDynamicObject(1360, 817.0540, -1348.7196, 12.8233, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BUSH_PROP3
    object_noobSpawn[47] = CreateDynamicObject(1360, 817.0540, -1344.6485, 12.8233, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BUSH_PROP3
    object_noobSpawn[48] = CreateDynamicObject(1280, 817.6867, -1346.7257, 12.9144, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //parkbench1
    object_noobSpawn[49] = CreateDynamicObject(19126, 807.9508, -1344.2091, 13.0666, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight6
    object_noobSpawn[50] = CreateDynamicObject(19126, 807.9508, -1350.5205, 13.0666, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight6
    object_noobSpawn[51] = CreateDynamicObject(970, 808.0289, -1347.3109, 13.0836, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    object_noobSpawn[52] = CreateDynamicObject(970, 808.0289, -1341.1190, 13.0836, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    object_noobSpawn[53] = CreateObject(19172, 809.6021, -1344.4960, 17.6746, 8.6000, 0.0000, 90.0000); //SAMPPicture1
    SetObjectMaterialText(object_noobSpawn[53], "ts.monkey-roleplay.de", 0, OBJECT_MATERIAL_SIZE_256x128, "Arial", 23, 1, 0xFFFFFFFF, 0x00000000, 1);
    SetObjectMaterialText(object_noobSpawn[53], "", 1, OBJECT_MATERIAL_SIZE_256x128, "Arial", 24, 1, 0xFFFFFFFF, 0x00000000, 0);
}
