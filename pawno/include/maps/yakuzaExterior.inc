#include <YSI\y_hooks>

// Global interior define
#define MAPS_YAKUZAEXTERIOR_INTERIOR      0
#define MAPS_YAKUZAINTERIOR_INTERIOR      1

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 350.0;
static Float:DRAWDISTANCE   = 350.0;

// Yakuza points
#define YAKUZA_INTERIOR_ENTER_COORDS        1046.3217, 1008.5336, 11.0000
#define YAKUZA_INTERIOR_EXIT_COORDS         2234.0027, 1713.4369, 1012.1367
#define YAKUZA_INTERIOR_ENTER_FACING        180.0
#define YAKUZA_INTERIOR_EXIT_FACING         320.5

// Map variables
new object_yakuzaExterior[24];
new pickup_yakuzaExterior[1];
new text3D_yakuzaExterior[1];

hook OnPlayerConnect(playerid) {
    // Remove RenderWare objects
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    if (newkeys & KEY_SECONDARY_ATTACK) {
        if (IsPlayerInRangeOfPoint(playerid, 2.0, YAKUZA_INTERIOR_ENTER_COORDS)) { // Yakuza Entrance
            if (Spieler[playerid][pFraktion] != 10) return SendClientMessage(playerid, COLOR_RED, "Du bist kein Mitglied der Yakuza.");
            SetPlayerInterior(playerid, MAPS_YAKUZAINTERIOR_INTERIOR);
            SetPlayerVirtualWorld(playerid, VW_YAKUZAINTERIOR);
            SetPlayerPos(playerid, YAKUZA_INTERIOR_EXIT_COORDS);
            SetPlayerFacingAngle(playerid, YAKUZA_INTERIOR_ENTER_FACING);
            SetCameraBehindPlayer(playerid);
            return 1;
        }
    }

    return 1;
}

hook OnGameModeInit() {
    // Vehicles

    // Pickups
    pickup_yakuzaExterior[0] = CreateDynamicPickup(19197, 1, YAKUZA_INTERIOR_ENTER_COORDS, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR); // Yakuza Entrance
    
    // 3DTextLabels
    text3D_yakuzaExterior[0] = _:CreateDynamic3DTextLabel("Territorium der\n" COLOR_HEX_GRAU "YAKUZA", COLOR_YELLOW, YAKUZA_INTERIOR_ENTER_COORDS, 25.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_YAKUZAEXTERIOR_INTERIOR);
    
    // Actors

    // Objects
    object_yakuzaExterior[0] = CreateDynamicObject(1215, 1053.7462, 1002.2079, 10.4697, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_yakuzaExterior[1] = CreateDynamicObject(1215, 1078.4964, 994.9673, 10.4697, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_yakuzaExterior[2] = CreateDynamicObject(1215, 1031.4466, 1018.6584, 10.4697, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_yakuzaExterior[3] = CreateDynamicObject(1215, 1016.8665, 1040.5992, 10.4697, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_yakuzaExterior[4] = CreateDynamicObject(3934, 1088.2928, 1064.6407, 9.8289, 0.0000, 0.0000, 45.0000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //helipad01
    object_yakuzaExterior[5] = CreateDynamicObject(3934, 1098.1514, 1074.4993, 9.8289, 0.0000, 0.0000, 45.0000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //helipad01
    object_yakuzaExterior[6] = CreateDynamicObject(3934, 1088.3702, 1084.2806, 9.8289, 0.0000, 0.0000, 45.0000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //helipad01
    object_yakuzaExterior[7] = CreateDynamicObject(3934, 1078.5410, 1074.4514, 9.8289, 0.0000, 0.0000, 45.0000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //helipad01
    object_yakuzaExterior[8] = CreateDynamicObject(1215, 1083.1650, 1064.2180, 9.7697, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_yakuzaExterior[9] = CreateDynamicObject(1215, 1087.9653, 1059.3758, 9.7697, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_yakuzaExterior[10] = CreateDynamicObject(1215, 1093.3950, 1064.8057, 9.7697, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_yakuzaExterior[11] = CreateDynamicObject(1215, 1088.5743, 1069.6268, 9.7697, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_yakuzaExterior[12] = CreateDynamicObject(1215, 1088.0438, 1079.0378, 9.7697, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_yakuzaExterior[13] = CreateDynamicObject(1215, 1088.6444, 1089.2486, 9.7697, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_yakuzaExterior[14] = CreateDynamicObject(1215, 1093.4750, 1084.4390, 9.7697, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_yakuzaExterior[15] = CreateDynamicObject(1215, 1083.2446, 1083.8385, 9.7697, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_yakuzaExterior[16] = CreateDynamicObject(1215, 1078.8037, 1079.4382, 9.7697, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_yakuzaExterior[17] = CreateDynamicObject(1215, 1078.2337, 1069.1976, 9.7697, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_yakuzaExterior[18] = CreateDynamicObject(1215, 1073.4218, 1074.0191, 9.7697, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_yakuzaExterior[19] = CreateDynamicObject(1215, 1083.6442, 1074.6093, 9.7697, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_yakuzaExterior[20] = CreateDynamicObject(1215, 1093.0242, 1074.0588, 9.7697, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_yakuzaExterior[21] = CreateDynamicObject(1215, 1097.8243, 1069.2290, 9.7697, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_yakuzaExterior[22] = CreateDynamicObject(1215, 1098.4149, 1079.5201, 9.7697, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_yakuzaExterior[23] = CreateDynamicObject(1215, 1103.2749, 1074.6400, 9.7697, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
}
