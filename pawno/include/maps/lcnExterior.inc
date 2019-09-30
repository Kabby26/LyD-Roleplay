#include <YSI\y_hooks>

// Global interior define
#define MAPS_LCNEXTERIOR_INTERIOR      0
#define MAPS_LCNINTERIOR_INTERIOR      1

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 150.0;
static Float:DRAWDISTANCE   = 130.0;

// La Cosa Nostra base points
#define LCN_INTERIOR_ENTER_COORDS        2196.3020, 1677.2394, 12.3672
#define LCN_INTERIOR_EXIT_COORDS         -794.9042, 490.1946, 1376.1953
#define LCN_INTERIOR_ENTER_FACING        0.0
#define LCN_INTERIOR_EXIT_FACING         270.0

// Map variables
new object_lcnExterior[24];
new pickup_lcnExterior[1];
new text3D_lcnExterior[1];

hook OnPlayerConnect(playerid) {
    // Remove RenderWare objects
    RemoveBuildingForPlayer(playerid, 3509, 2093.7700, 1652.1300, 9.7031, 0.10); // VgsN_nitree_r01
    RemoveBuildingForPlayer(playerid, 3509, 2105.0000, 1652.0300, 9.7031, 0.10); // VgsN_nitree_r01
    RemoveBuildingForPlayer(playerid, 3509, 2114.2900, 1710.8699, 9.7343, 0.10); // VgsN_nitree_r01
    RemoveBuildingForPlayer(playerid, 3509, 2114.2500, 1653.3900, 9.7031, 0.10); // VgsN_nitree_r01
    RemoveBuildingForPlayer(playerid, 3509, 2126.4899, 1657.0899, 9.7031, 0.10); // VgsN_nitree_r01
    RemoveBuildingForPlayer(playerid, 3509, 2126.5600, 1706.2299, 9.7343, 0.10); // VgsN_nitree_r01
    RemoveBuildingForPlayer(playerid, 3509, 2135.6101, 1700.9799, 9.7343, 0.10); // VgsN_nitree_r01
    RemoveBuildingForPlayer(playerid, 3509, 2135.8999, 1662.5799, 9.7031, 0.10); // VgsN_nitree_r01
    RemoveBuildingForPlayer(playerid, 3509, 2143.8601, 1691.5500, 9.7343, 0.10); // VgsN_nitree_r01
    RemoveBuildingForPlayer(playerid, 3509, 2143.8601, 1671.1500, 9.7031, 0.10); // VgsN_nitree_r01
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    if (newkeys & KEY_SECONDARY_ATTACK) {
        if (IsPlayerInRangeOfPoint(playerid, 2.0, LCN_INTERIOR_ENTER_COORDS)) { // LCN Entrance
            if (Spieler[playerid][pFraktion] != 12) return SendClientMessage(playerid, COLOR_RED, "Du bist kein Mitglied des Cali Kartells.");
            SetPlayerInterior(playerid, MAPS_LCNINTERIOR_INTERIOR);
            SetPlayerVirtualWorld(playerid, VW_LCNINTERIOR);
            SetPlayerPos(playerid, LCN_INTERIOR_EXIT_COORDS);
            SetPlayerFacingAngle(playerid, LCN_INTERIOR_EXIT_FACING);
            SetCameraBehindPlayer(playerid);
            return 1;
        }
    }

    return 1;
}

hook OnGameModeInit() {
    // Pickups
    pickup_lcnExterior[0] = CreateDynamicPickup(19197, 1, LCN_INTERIOR_ENTER_COORDS, VW_MAIN, MAPS_LCNEXTERIOR_INTERIOR); // LCN Entrance
    
    // 3DTextLabels
    text3D_lcnExterior[0] = _:CreateDynamic3DTextLabel("Territorium der\n" COLOR_HEX_BLACK "CK", COLOR_YELLOW, LCN_INTERIOR_ENTER_COORDS, 25.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_LCNEXTERIOR_INTERIOR);
    
    // Vehicles

    // Objects
    object_lcnExterior[0] = CreateDynamicObject(19172, 2086.5449, 1654.8537, 12.0551, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_LCNEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_lcnExterior[0], 0, "CK", OBJECT_MATERIAL_SIZE_256x128, "Arial", 145, 1, 0xFFFFFFFF, 0x00000000, 0);
    SetDynamicObjectMaterial(object_lcnExterior[0], 1, 19297, "matlights", "invisible", 0x00000000);
    object_lcnExterior[1] = CreateDynamicObject(3509, 2103.5742, 1726.9681, 9.8148, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LCNEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //VgsN_nitree_r01
    object_lcnExterior[2] = CreateDynamicObject(3934, 2124.7893, 1665.4836, 9.8203, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LCNEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //helipad01
    object_lcnExterior[3] = CreateDynamicObject(18981, 2099.0476, 1543.4321, 1.9378, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LCNEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_lcnExterior[3], 0, 12855, "cunte_cop", "ws_bigstones", 0xFFFFFFFF);
    object_lcnExterior[4] = CreateDynamicObject(3934, 2104.5256, 1665.4836, 9.8203, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LCNEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //helipad01
    object_lcnExterior[5] = CreateDynamicObject(18981, 2087.0466, 1555.4521, 1.9385, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LCNEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_lcnExterior[5], 0, 12855, "cunte_cop", "ws_bigstones", 0xFFFFFFFF);
    object_lcnExterior[6] = CreateDynamicObject(3934, 2104.5256, 1701.4033, 9.8203, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LCNEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //helipad01
    object_lcnExterior[7] = CreateDynamicObject(3934, 2124.7893, 1701.4033, 9.8203, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LCNEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //helipad01
    object_lcnExterior[8] = CreateDynamicObject(18981, 2087.0466, 1580.4520, 1.9385, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LCNEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_lcnExterior[8], 0, 12855, "cunte_cop", "ws_bigstones", 0xFFFFFFFF);
    object_lcnExterior[9] = CreateDynamicObject(18981, 2087.0466, 1605.4499, 1.9385, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LCNEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_lcnExterior[9], 0, 12855, "cunte_cop", "ws_bigstones", 0xFFFFFFFF);
    object_lcnExterior[10] = CreateDynamicObject(18981, 2087.0476, 1626.7292, 1.9377, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LCNEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_lcnExterior[10], 0, 12855, "cunte_cop", "ws_bigstones", 0xFFFFFFFF);
    object_lcnExterior[11] = CreateDynamicObject(18981, 2087.0476, 1664.2674, 1.9377, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LCNEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_lcnExterior[11], 0, 12855, "cunte_cop", "ws_bigstones", 0xFFFFFFFF);
    object_lcnExterior[12] = CreateDynamicObject(18981, 2087.0476, 1689.2668, 1.9377, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LCNEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_lcnExterior[12], 0, 12855, "cunte_cop", "ws_bigstones", 0xFFFFFFFF);
    object_lcnExterior[13] = CreateDynamicObject(18766, 2090.8742, 1710.5843, 11.9335, 0.0000, 0.0000, 62.9000, VW_MAIN, MAPS_LCNEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_lcnExterior[13], 0, 12855, "cunte_cop", "ws_bigstones", 0xFFFFFFFF);
    object_lcnExterior[14] = CreateDynamicObject(18766, 2087.0561, 1698.2441, 11.9335, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LCNEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_lcnExterior[14], 0, 12855, "cunte_cop", "ws_bigstones", 0xFFFFFFFF);
    object_lcnExterior[15] = CreateDynamicObject(18766, 2089.2775, 1707.4654, 11.9343, 0.0000, 0.0000, 62.9000, VW_MAIN, MAPS_LCNEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_lcnExterior[15], 0, 12855, "cunte_cop", "ws_bigstones", 0xFFFFFFFF);
    object_lcnExterior[16] = CreateDynamicObject(18981, 2104.9020, 1737.9670, 1.9377, 0.0000, 0.0000, -26.6000, VW_MAIN, MAPS_LCNEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_lcnExterior[16], 0, 12855, "cunte_cop", "ws_bigstones", 0xFFFFFFFF);
    object_lcnExterior[17] = CreateDynamicObject(18981, 2112.0214, 1752.1883, 1.9364, 0.0000, 0.0000, -26.6000, VW_MAIN, MAPS_LCNEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_lcnExterior[17], 0, 12855, "cunte_cop", "ws_bigstones", 0xFFFFFFFF);
    object_lcnExterior[18] = CreateDynamicObject(19172, 2086.5449, 1636.3835, 12.0551, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_LCNEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_lcnExterior[18], 0, "CK", OBJECT_MATERIAL_SIZE_256x128, "Arial", 145, 1, 0xFFFFFFFF, 0x00000000, 0);
    SetDynamicObjectMaterial(object_lcnExterior[18], 1, 19297, "matlights", "invisible", 0x00000000);
    object_lcnExterior[19] = CreateDynamicObject(19172, 2091.3649, 1712.6739, 12.0551, 0.0000, 0.0000, 242.8999, VW_MAIN, MAPS_LCNEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_lcnExterior[19], 0, "CK", OBJECT_MATERIAL_SIZE_256x128, "Arial", 145, 1, 0xFFFFFFFF, 0x00000000, 0);
    SetDynamicObjectMaterial(object_lcnExterior[19], 1, 19297, "matlights", "invisible", 0x00000000);
    object_lcnExterior[20] = CreateDynamicObject(19172, 2100.0244, 1729.3298, 12.0551, 0.0000, 0.0000, -116.5998, VW_MAIN, MAPS_LCNEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_lcnExterior[20], 0, "CK", OBJECT_MATERIAL_SIZE_256x128, "Arial", 145, 1, 0xFFFFFFFF, 0x00000000, 0);
    SetDynamicObjectMaterial(object_lcnExterior[20], 1, 19297, "matlights", "invisible", 0x00000000);
    object_lcnExterior[21] = CreateDynamicObject(3509, 2110.3769, 1739.5672, 9.8148, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LCNEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //VgsN_nitree_r01
    object_lcnExterior[22] = CreateDynamicObject(3509, 2115.3886, 1750.1975, 9.8148, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LCNEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //VgsN_nitree_r01
    object_lcnExterior[23] = CreateDynamicObject(3509, 2119.7985, 1759.7591, 9.8148, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LCNEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //VgsN_nitree_r01
}
