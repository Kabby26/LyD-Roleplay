#include <YSI\y_hooks>

// Global interior define
#define MAPS_ADMINBASE      0

//Mapvariables
new object_aBase2[52];

// Commands
CMD:adminbase2(playerid) {
    if (Spieler[playerid][pAdmin] < 4) return SendClientMessage(playerid, COLOR_RED, "Du besitzt nicht die benötigten Rechte.");
	SetPlayerPos(playerid, 982.3470, -1553.6975, 21.5078);
	SetPlayerFacingAngle(playerid, 87.7438);
	SendClientMessage(playerid, COLOR_GREEN, "Du hast dich zur 2. Adminbase teleportiert.");
	return 1;
}

hook OnPlayerConnect(playerid) {
	RemoveBuildingForPlayer(playerid, 759, 962.8129, -1559.9100, 20.8358, 0.10); // sm_bush_large_1
	RemoveBuildingForPlayer(playerid, 759, 967.0629, -1559.9100, 20.8358, 0.10); // sm_bush_large_1
	RemoveBuildingForPlayer(playerid, 759, 971.3049, -1559.9100, 20.8358, 0.10); // sm_bush_large_1
	RemoveBuildingForPlayer(playerid, 759, 975.5469, -1559.9100, 20.8358, 0.10); // sm_bush_large_1
	RemoveBuildingForPlayer(playerid, 759, 979.7890, -1559.9100, 20.8358, 0.10); // sm_bush_large_1
	RemoveBuildingForPlayer(playerid, 759, 984.0390, -1559.9100, 20.8358, 0.10); // sm_bush_large_1
	RemoveBuildingForPlayer(playerid, 759, 962.8129, -1547.9699, 20.8358, 0.10); // sm_bush_large_1
	RemoveBuildingForPlayer(playerid, 759, 967.0629, -1547.9699, 20.8358, 0.10); // sm_bush_large_1
	RemoveBuildingForPlayer(playerid, 759, 971.3049, -1547.9699, 20.8358, 0.10); // sm_bush_large_1
	RemoveBuildingForPlayer(playerid, 759, 975.5469, -1547.9699, 20.8358, 0.10); // sm_bush_large_1
	RemoveBuildingForPlayer(playerid, 759, 979.7890, -1547.9699, 20.8358, 0.10); // sm_bush_large_1
	RemoveBuildingForPlayer(playerid, 759, 984.0390, -1547.9699, 20.8358, 0.10); // sm_bush_large_1
}

hook OnGameModeInit() {

	// Objects
	object_aBase2[0] = CreateObject(8661, 979.0476, -1561.0123, 15.4097, 90.0000, 0.0000, 0.0000); //gnhtelgrnd_lvs
	object_aBase2[1] = CreateObject(19381, 963.8618, -1557.5179, 25.4678, 0.0000, 90.0000, 0.0000); //wall029
	SetObjectMaterial(object_aBase2[1], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0x00000000);
	object_aBase2[2] = CreateObject(8661, 979.7982, -1546.3271, 15.4195, 90.0000, 180.0000, 0.0000); //gnhtelgrnd_lvs
	object_aBase2[3] = CreateObject(19381, 963.8610, -1549.7834, 25.4778, 0.0000, 90.0000, 0.0000); //wall029
	SetObjectMaterial(object_aBase2[3], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0x00000000);
	object_aBase2[4] = CreateObject(19381, 974.3577, -1557.5179, 25.4678, 0.0000, 90.0000, 0.0000); //wall029
	SetObjectMaterial(object_aBase2[4], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0x00000000);
	object_aBase2[5] = CreateObject(19381, 984.8375, -1557.4880, 25.4678, 0.0000, 90.0000, 0.2998); //wall029
	SetObjectMaterial(object_aBase2[5], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0x00000000);
	object_aBase2[6] = CreateObject(19381, 974.3516, -1549.7834, 25.4778, 0.0000, 90.0000, 0.0000); //wall029
	SetObjectMaterial(object_aBase2[6], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0x00000000);
	object_aBase2[7] = CreateObject(19381, 984.8134, -1549.8032, 25.4778, 0.0000, 90.0000, -0.5000); //wall029
	SetObjectMaterial(object_aBase2[7], 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0x00000000);
	object_aBase2[8] = CreateObject(1985, 982.1881, -1551.2495, 24.3635, 0.0000, 0.0000, 0.0000); //punchbagnu
	object_aBase2[9] = CreateObject(11691, 971.5359, -1557.8917, 20.5118, 0.0000, 0.0000, 90.0000); //CTable2
	object_aBase2[10] = CreateObject(1431, 971.2960, -1554.8028, 21.0126, 0.0000, 0.0000, 88.4000); //DYN_BOX_PILE
	object_aBase2[11] = CreateObject(1703, 986.5980, -1556.9947, 20.4712, 0.0000, 0.0000, -90.0000); //kb_couch02
	object_aBase2[12] = CreateObject(1703, 985.3767, -1559.7237, 20.4712, 0.0000, 0.0000, 180.0000); //kb_couch02
	object_aBase2[13] = CreateObject(19381, 965.0512, -1550.0638, 20.4276, 0.0000, 90.0000, 0.0000); //wall029
	SetObjectMaterial(object_aBase2[13], 0, 10426, "backroad_sfs", "Bow_church_dirt", 0x00000000);
	object_aBase2[14] = CreateObject(19381, 965.0512, -1557.4759, 20.4176, 0.0000, 90.0000, 0.0000); //wall029
	SetObjectMaterial(object_aBase2[14], 0, 10426, "backroad_sfs", "Bow_church_dirt", 0x00000000);
	object_aBase2[15] = CreateObject(19465, 970.4458, -1549.4376, 23.0028, 0.0000, 0.0000, 0.0000); //wall105
	SetObjectMaterial(object_aBase2[15], 0, 1649, "wglass", "carshowwin2", 0x00000000);
	object_aBase2[16] = CreateObject(3409, 966.6234, -1558.6417, 20.2268, 0.0000, 0.0000, 0.0000); //grassplant
	object_aBase2[17] = CreateObject(3409, 966.7335, -1553.7796, 20.2268, 0.0000, 0.0000, 0.0000); //grassplant
	object_aBase2[18] = CreateObject(3409, 966.7733, -1549.0290, 20.2268, 0.0000, 0.0000, 0.0000); //grassplant
	object_aBase2[19] = CreateObject(3409, 962.4207, -1558.6417, 20.2268, 0.0000, 0.0000, 0.0000); //grassplant
	object_aBase2[20] = CreateObject(3409, 962.3201, -1553.7796, 20.2268, 0.0000, 0.0000, 0.0000); //grassplant
	object_aBase2[21] = CreateObject(3409, 962.4425, -1549.0290, 20.2268, 0.0000, 0.0000, 0.0000); //grassplant
	object_aBase2[22] = CreateObject(19363, 959.7717, -1557.8576, 23.4747, -3.1998, 0.0000, 0.0000); //wall011
	SetObjectMaterial(object_aBase2[22], 0, 14801, "lee_bdupsmain", "Bdup_graf1", 0x00000000);
	object_aBase2[23] = CreateObject(19464, 970.4417, -1557.8833, 22.9950, 0.0000, 0.0000, 0.0000); //wall104
	SetObjectMaterial(object_aBase2[23], 0, 1649, "wglass", "carshowwin2", 0x00000000);
	object_aBase2[24] = CreateObject(19464, 970.4519, -1555.2607, 22.9950, 0.0000, 0.0000, 0.0000); //wall104
	SetObjectMaterial(object_aBase2[24], 0, 1649, "wglass", "carshowwin2", 0x00000000);
	object_aBase2[25] = CreateObject(1491, 970.4276, -1550.1949, 20.4508, 0.0000, 0.0000, 90.0000); //Gen_doorINT01
	SetObjectMaterial(object_aBase2[25], 0, 3261, "grasshouse", "veg_marijuana", 0x00000000);
	object_aBase2[26] = CreateObject(19172, 970.4842, -1549.4737, 23.8210, 0.0000, 0.0000, 90.0000); //SAMPPicture1
	SetObjectMaterialText(object_aBase2[26], "42O Plantage", 0, OBJECT_MATERIAL_SIZE_256x128, "Arial", 45, 1, 0xFF000000, 0x00000000, 1);
	SetObjectMaterial(object_aBase2[26], 1, 1419, "break_fence3", "CJ_FRAME_Glass", 0x00000000);
	object_aBase2[27] = CreateObject(2228, 970.2877, -1548.3120, 21.0687, 0.0000, 0.0000, 90.0000); //CJ_SHOVEL
	object_aBase2[28] = CreateObject(1576, 971.3965, -1559.1010, 21.2585, 0.0000, 0.0000, 0.0000); //drug_orange
	object_aBase2[29] = CreateObject(18075, 983.5927, -1552.8789, 25.2964, 0.0000, 0.0000, 0.0000); //lightD
	object_aBase2[30] = CreateObject(19363, 959.7717, -1553.1860, 23.4747, 6.2999, 0.0000, 0.0000); //wall011
	SetObjectMaterial(object_aBase2[30], 0, 1381, "cranes_dyn2", "ws_dudelogo", 0x00000000);
	object_aBase2[31] = CreateObject(19363, 959.7717, -1548.6728, 23.4747, -5.8000, 0.0000, 0.0000); //wall011
	SetObjectMaterial(object_aBase2[31], 0, 17700, "gangblok1_lae2", "pigpen1_LAe", 0x00000000);
	object_aBase2[32] = CreateObject(2228, 970.2880, -1548.0117, 21.0687, 0.0000, 0.0000, 87.3000); //CJ_SHOVEL
	object_aBase2[33] = CreateObject(2228, 969.7963, -1547.9256, 20.5221, 87.8999, 49.4999, 90.0000); //CJ_SHOVEL
	object_aBase2[34] = CreateObject(2321, 983.5999, -1558.3603, 20.4740, 0.0000, 0.0000, 0.0000); //CJ_TV_TABLE6
	object_aBase2[35] = CreateObject(1576, 971.3965, -1558.6906, 21.2585, 0.0000, 0.0000, -10.1000); //drug_orange
	object_aBase2[36] = CreateObject(18075, 966.3178, -1552.5487, 24.2464, 0.0000, 0.0000, 0.0000); //lightD
	object_aBase2[37] = CreateObject(18075, 966.3178, -1555.5716, 24.2464, 0.0000, 0.0000, 0.0000); //lightD
	object_aBase2[38] = CreateObject(19381, 965.0512, -1556.4902, 24.4076, 0.0000, 90.0000, 0.0000); //wall029
	SetObjectMaterial(object_aBase2[38], 0, 17588, "lae2coast_alpha", "plainglass", 0x00000000);
	object_aBase2[39] = CreateObject(19381, 965.0512, -1550.0687, 24.4076, 0.0000, 90.0000, 0.0000); //wall029
	SetObjectMaterial(object_aBase2[39], 0, 17588, "lae2coast_alpha", "plainglass", 0x00000000);
	object_aBase2[40] = CreateObject(2321, 983.5999, -1557.4394, 20.4740, 0.0000, 0.0000, 0.0000); //CJ_TV_TABLE6
	object_aBase2[41] = CreateObject(1670, 985.1887, -1557.7873, 20.9829, 0.0000, 0.0000, 84.7998); //propcollecttable
	object_aBase2[42] = CreateObject(1670, 983.9290, -1558.5360, 20.9829, 0.0000, 0.0000, -1.7000); //propcollecttable
	object_aBase2[43] = CreateObject(1577, 983.4863, -1558.0097, 20.9101, 0.0000, 0.0000, 0.0000); //drug_yellow
	object_aBase2[44] = CreateObject(1577, 983.4863, -1557.6395, 20.9101, 0.0000, 0.0000, 0.0000); //drug_yellow
	object_aBase2[45] = CreateObject(1580, 983.4943, -1557.8160, 21.0461, 0.0000, 0.0000, 58.1999); //drug_red
	object_aBase2[46] = CreateObject(356, 983.4677, -1557.1643, 21.0226, 89.3999, 9.5999, 0.0000); //m4
	object_aBase2[47] = CreateObject(1578, 971.3905, -1558.2694, 21.2525, 0.0000, 0.0000, 7.0999); //drug_green
	object_aBase2[48] = CreateObject(1579, 971.3639, -1558.9294, 21.3951, 0.0000, 0.0000, 24.9999); //drug_blue
	object_aBase2[49] = CreateObject(1580, 971.4519, -1558.4243, 21.3918, 0.0000, 0.0000, -29.9000); //drug_red
	object_aBase2[50] = CreateObject(19172, 970.4537, -1549.4541, 23.3909, 0.0000, 0.0000, 90.0000); //SAMPPicture1
	SetObjectMaterialText(object_aBase2[50], "Benny & Jose's Reich!", 0, OBJECT_MATERIAL_SIZE_256x128, "Arial", 25, 1, 0xFF000000, 0x00000000, 1);
	SetObjectMaterial(object_aBase2[50], 1, 1419, "break_fence3", "CJ_FRAME_Glass", 0x00000000);
	object_aBase2[51] = CreateObject(14791, 982.0707, -1550.6583, 22.0451, 0.0000, 0.0000, 0.0000); //a_vgsGymBoxa
}
