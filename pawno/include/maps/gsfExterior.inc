#include <YSI\y_hooks>

// Global interior define
#define MAPS_GSFEXTERIOR_INTERIOR      0
#define MAPS_GSFINTERIOR_INTERIOR      3

// Local drawdistance & streamdistance setting
// static Float:STREAMDISTANCE = 350.0;
// static Float:DRAWDISTANCE   = 350.0;

// GSF points
#define GSF_INTERIOR_ENTER_COORDS        2495.3547, -1690.6273, 14.7656
#define GSF_INTERIOR_EXIT_COORDS         2495.9873, -1692.3297, 1014.7422
#define GSF_INTERIOR_ENTER_FACING        180.0
#define GSF_INTERIOR_EXIT_FACING         0.0

// Map variables
new pickup_gsfExterior[1];
new text3D_gsfExterior[1];

hook OnPlayerConnect(playerid) {
    // ---
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    if (newkeys & KEY_SECONDARY_ATTACK) {
        if (IsPlayerInRangeOfPoint(playerid, 2.0, GSF_INTERIOR_ENTER_COORDS)) { // GSF Entrance
            if (Spieler[playerid][pFraktion] != 6) return SendClientMessage(playerid, COLOR_RED, "Du bist kein Mitglied der Grove Street.");
            SetPlayerInterior(playerid, MAPS_GSFINTERIOR_INTERIOR);
            SetPlayerVirtualWorld(playerid, VW_GSFINTERIOR);
            SetPlayerPos(playerid, GSF_INTERIOR_EXIT_COORDS);
            SetPlayerFacingAngle(playerid, GSF_INTERIOR_ENTER_FACING);
            SetCameraBehindPlayer(playerid);
            return 1;
        }
    }

    return 1;
}

hook OnGameModeInit() {
    // Vehicles

    // Pickups
    pickup_gsfExterior[0] = CreateDynamicPickup(19197, 1, GSF_INTERIOR_ENTER_COORDS, VW_MAIN, MAPS_GSFEXTERIOR_INTERIOR); // Grove Street Entrance

    // 3DTextLabels
    text3D_gsfExterior[0] = _:CreateDynamic3DTextLabel("Territorium der\n" COLOR_HEX_GREEN "GROVE STREET", COLOR_YELLOW, GSF_INTERIOR_ENTER_COORDS, 25.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_GSFEXTERIOR_INTERIOR);
}
