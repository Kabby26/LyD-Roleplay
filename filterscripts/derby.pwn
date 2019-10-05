
/*==============================================================================
						  Derby Script v1 by OutLawZ
==============================================================================*/

#include <a_samp>
#include <sscanf2>

#define DERBY_INTERMISSION  "90"	// Time in seconds for the next derby to commence
#define DERBY_COOLDOWN      "30" 	// Time in seconds for the players to signup
#define DERBY_COUNTDOWN     "5" 	// Time in seconds for countdown
#define MONEY_REWARD 		"500"	// Money reward for the player that wins
#define SCORE_REWARD 		"10"	// Score reward for the player that wins
#define ENABLE_CLIENT_MSG           // Comment out if you don't want client messages to show

#define MIN_DERBY_PLAYERS   (2)
#define MAX_DERBY_PLAYERS   (12)
#define MAX_TD_FRAMES       (8)
#define MAX_CLIENT_STRING   (128)

#define COLOR_ERROR   		(0xF11D22FF)
#define COLOR_ORANGE      	(0xF4C70FFF)
#define COLOR_GREEN       	(0x0B9311FF)

#define DERBY_LIST      	"Derbies\\Derby.min"
#define DERBY_DATA      	"Derbies\\%s.deb"

#define isnull(%1) ((!(%1[0])) || (((%1[0]) == '\1') && (!(%1[1]))))

forward EndDerby();
forward DerbyTextdraws();
forward Commence_Derby();
forward InitiatePlayers();
forward DerbyRequirementCheck(playerid);
forward FreezeVehicle(vehicleid,toggle);
forward CountdownDerby();
forward Start_Derby();
forward KickPlayerFromDerby(playerid, reason[]);
forward RetVehicle(vehfrz,Float:VX,Float:VY,Float:VZ,Float:VA);
forward VehicleToPoint(playerid, Float:radi, Float:px, Float:py, Float:pz);

enum DERBY_SETTINGS
{
	bool:Derby_Enabled,
	bool:Derby_Access,
	bool:Derby_Start,
	Derby_Countdown,
	DerbyMaxPlayers,
	Derby_Current,
	File:DerbyFile,
	Derby_Timer
};

enum DERBY_PDATA
{
    Derby_Name[32],
	Derby_Interior,
	Derby_World,
	Derby_VehModel,
	Float:Derby_Minheight,
	bool:Derby_ActiveCheck,
	bool:Derby_HightMeassure
};

enum DERBY_INFO
{
	Derby_Vehicle,
	Float:Derby_Position[4]
};

enum DERBY_PLAYERS
{
	bool:DerbySigned,
	Float:DerbyJoinP[4],
	Float:DerbyHealth,
	DerbyIW[2],
	DerbyWeapons[13],
	DerbyAmmo[13],
	DerbyInactive
};

new
    DerbyWait 					[MAX_PLAYERS],
    DerbyString 	 	 		[MAX_CLIENT_STRING],
    Text:DerbyTextdraw 	 		[MAX_TD_FRAMES],
	fv 				 	 		[MAX_VEHICLES],
	DerbyPlayers 				[MAX_PLAYERS][DERBY_PLAYERS],
	DerbySettings 				[DERBY_SETTINGS],
	DerbyData 					[DERBY_PDATA],
	DerbyCoords 				[MAX_DERBY_PLAYERS][DERBY_INFO],
	Float:D_X, Float:D_Y, Float:D_Z
;

public OnFilterScriptInit()
{
	print("\n--------------------------------------");
	print(" Derby Filterscript by OutLawZ Loaded   ");
	print("--------------------------------------\n");

    if(!fexist(DERBY_LIST))
	{
	    printf("Error: You don't have derby file %s", DERBY_LIST);
	    DerbySettings[DerbyFile] = fopen(DERBY_LIST, io_write);
	    fclose(DerbySettings[DerbyFile]);
	}
	else
	{
	    new bool:Empty = true;
	    DerbySettings[DerbyFile] = fopen(DERBY_LIST, io_read);

		while(fread(DerbySettings[DerbyFile], DerbyString))
		    if(!isnull(DerbyString)) Empty = false;

		if(Empty) printf("Error: Derby file %s is empty!", DERBY_LIST);
	}

	DerbySettings[Derby_Current] = -1;
	DerbySettings[Derby_Enabled] = true;

	DerbyTextdraw[0] = TextDrawCreate(619.000000, 125.000000, "_");
	TextDrawBackgroundColor(DerbyTextdraw[0], 255);
	TextDrawFont(DerbyTextdraw[0], 1);
	TextDrawLetterSize(DerbyTextdraw[0], 0.519999, 10.200002);
	TextDrawColor(DerbyTextdraw[0], -1);
	TextDrawSetOutline(DerbyTextdraw[0], 0);
	TextDrawSetProportional(DerbyTextdraw[0], 1);
	TextDrawSetShadow(DerbyTextdraw[0], 1);
	TextDrawUseBox(DerbyTextdraw[0], 1);
	TextDrawBoxColor(DerbyTextdraw[0], 140);
	TextDrawTextSize(DerbyTextdraw[0], 488.000000, -1.000000);
	TextDrawSetSelectable(DerbyTextdraw[0], 0);

	DerbyTextdraw[1] = TextDrawCreate(614.000000, 131.000000, "_");
	TextDrawBackgroundColor(DerbyTextdraw[1], 255);
	TextDrawFont(DerbyTextdraw[1], 1);
	TextDrawLetterSize(DerbyTextdraw[1], 0.519999, 1.799999);
	TextDrawColor(DerbyTextdraw[1], -1);
	TextDrawSetOutline(DerbyTextdraw[1], 0);
	TextDrawSetProportional(DerbyTextdraw[1], 1);
	TextDrawSetShadow(DerbyTextdraw[1], 1);
	TextDrawUseBox(DerbyTextdraw[1], 1);
	TextDrawBoxColor(DerbyTextdraw[1], 150);
	TextDrawTextSize(DerbyTextdraw[1], 493.000000, -1.000000);
	TextDrawSetSelectable(DerbyTextdraw[1], 0);

	DerbyTextdraw[2] = TextDrawCreate(614.000000, 158.000000, "_");
	TextDrawBackgroundColor(DerbyTextdraw[2], 255);
	TextDrawFont(DerbyTextdraw[2], 1);
	TextDrawLetterSize(DerbyTextdraw[2], 0.519999, 5.599998);
	TextDrawColor(DerbyTextdraw[2], -1);
	TextDrawSetOutline(DerbyTextdraw[2], 0);
	TextDrawSetProportional(DerbyTextdraw[2], 1);
	TextDrawSetShadow(DerbyTextdraw[2], 1);
	TextDrawUseBox(DerbyTextdraw[2], 1);
	TextDrawBoxColor(DerbyTextdraw[2], 150);
	TextDrawTextSize(DerbyTextdraw[2], 493.000000, -1.000000);
	TextDrawSetSelectable(DerbyTextdraw[2], 0);

	DerbyTextdraw[3] = TextDrawCreate(552.000000, 133.000000, "Diesel Induction");
	TextDrawAlignment(DerbyTextdraw[3], 2);
	TextDrawBackgroundColor(DerbyTextdraw[3], 255);
	TextDrawFont(DerbyTextdraw[3], 2);
	TextDrawLetterSize(DerbyTextdraw[3], 0.169999, 1.000000);
	TextDrawColor(DerbyTextdraw[3], -1179010561);
	TextDrawSetOutline(DerbyTextdraw[3], 0);
	TextDrawSetProportional(DerbyTextdraw[3], 1);
	TextDrawSetShadow(DerbyTextdraw[3], 1);
	TextDrawSetSelectable(DerbyTextdraw[3], 0);

	DerbyTextdraw[4] = TextDrawCreate(554.000000, 158.000000, "Derby is going to start~n~in 0 seconds!");
	TextDrawAlignment(DerbyTextdraw[4], 2);
	TextDrawBackgroundColor(DerbyTextdraw[4], 255);
	TextDrawFont(DerbyTextdraw[4], 2);
	TextDrawLetterSize(DerbyTextdraw[4], 0.199999, 0.899999);
	TextDrawColor(DerbyTextdraw[4], -1);
	TextDrawSetOutline(DerbyTextdraw[4], 0);
	TextDrawSetProportional(DerbyTextdraw[4], 1);
	TextDrawSetShadow(DerbyTextdraw[4], 1);
	TextDrawSetSelectable(DerbyTextdraw[4], 0);

	DerbyTextdraw[5] = TextDrawCreate(614.000000, 187.000000, "_");
	TextDrawBackgroundColor(DerbyTextdraw[5], 255);
	TextDrawFont(DerbyTextdraw[5], 1);
	TextDrawLetterSize(DerbyTextdraw[5], 0.519999, 1.200000);
	TextDrawColor(DerbyTextdraw[5], -1);
	TextDrawSetOutline(DerbyTextdraw[5], 0);
	TextDrawSetProportional(DerbyTextdraw[5], 1);
	TextDrawSetShadow(DerbyTextdraw[5], 1);
	TextDrawUseBox(DerbyTextdraw[5], 1);
	TextDrawBoxColor(DerbyTextdraw[5], 255);
	TextDrawTextSize(DerbyTextdraw[5], 493.000000, -1.000000);
	TextDrawSetSelectable(DerbyTextdraw[5], 0);

	DerbyTextdraw[6] = TextDrawCreate(554.000000, 197.000000, "Currently 0 Joined!");
	TextDrawAlignment(DerbyTextdraw[6], 2);
	TextDrawBackgroundColor(DerbyTextdraw[6], 255);
	TextDrawFont(DerbyTextdraw[6], 2);
	TextDrawLetterSize(DerbyTextdraw[6], 0.199999, 0.899999);
	TextDrawColor(DerbyTextdraw[6], 463129599);
	TextDrawSetOutline(DerbyTextdraw[6], 0);
	TextDrawSetProportional(DerbyTextdraw[6], 1);
	TextDrawSetShadow(DerbyTextdraw[6], 1);
	TextDrawSetSelectable(DerbyTextdraw[6], 0);

    DerbyTextdraw[7] = TextDrawCreate(488.500, 121.000, "hud:radar_race");
    TextDrawFont(DerbyTextdraw[7], 4);
    TextDrawTextSize(DerbyTextdraw[7], 14.500, 13.000);
    TextDrawColor(DerbyTextdraw[7], -1);

	Start_Derby();
	return 1;
}

public OnFilterScriptExit()
{
	for(new i; i < MAX_DERBY_PLAYERS; i++)
	{
		DestroyVehicle(DerbyCoords[i][Derby_Vehicle]);
		DerbyCoords[i][Derby_Vehicle] = INVALID_VEHICLE_ID;
	}

	for(new i; i < MAX_TD_FRAMES; i++)
	{
		TextDrawHideForAll(DerbyTextdraw[i]);
		TextDrawDestroy(DerbyTextdraw[i]);
	}
	DerbySettings[Derby_Enabled] = false;
	return 1;
}

stock LoadNextDerby()
{
    DerbySettings[Derby_Current] ++;
    new Next = -1, D_Load[32];
    DerbySettings[DerbyFile] = fopen(DERBY_LIST, io_read);

    while(fread(DerbySettings[DerbyFile], DerbyString))
    {
    	Next++;
        StripNewLine(DerbyString);

        if(!Next) format(D_Load, sizeof D_Load, "%s", DerbyString);
        if(Next == DerbySettings[Derby_Current])
            return LoadDerby(DerbyString);
    }
    DerbySettings[Derby_Current] = 0;
    return LoadDerby(D_Load);
}

stock LoadDerby(derbyname[])
{
	if(DerbySettings[DerbyFile]) fclose(DerbySettings[DerbyFile]);
	format(DerbyString, sizeof DerbyString, DERBY_DATA, derbyname);
	if(!fexist(DerbyString)) return printf("ERROR: Derby Data File (%s) doesn't exist!", DerbyString);

    DerbySettings[DerbyFile] = fopen(DerbyString, io_read);
    new Next, iIndex, Float:DCoords[4];
    while(fread(DerbySettings[DerbyFile], DerbyString))
    {
        StripNewLine(DerbyString);
        Next++;

        if(!sscanf(DerbyString, "p<,>ffff", DCoords[0], DCoords[1], DCoords[2], DCoords[3]))
        {
            if(0 <= iIndex < MAX_DERBY_PLAYERS)
            {
                DerbyCoords[iIndex][Derby_Position][0] = DCoords[0];
                DerbyCoords[iIndex][Derby_Position][1] = DCoords[1];
                DerbyCoords[iIndex][Derby_Position][2] = DCoords[2];
                DerbyCoords[iIndex][Derby_Position][3] = DCoords[3];
             }
            iIndex++;
        }
		else if(!sscanf(DerbyString, "p<|>s[32]iiifll", DerbyData[Derby_Name], DerbyData[Derby_Interior], DerbyData[Derby_World], DerbyData[Derby_VehModel], DerbyData[Derby_Minheight], DerbyData[Derby_ActiveCheck], DerbyData[Derby_HightMeassure]))
        {
			printf("Loaded \"%s\" Header", DerbyData[Derby_Name]);
        }
		else printf("Error: Derby (%s) has invalid data format @Line %i", DerbyString, Next);
	}
	fclose(DerbySettings[DerbyFile]);

	if(iIndex != MAX_DERBY_PLAYERS) printf("Warning: Loaded Coords for %i derby players (Required: %i)", iIndex, MAX_DERBY_PLAYERS);

	else printf("Loaded Coordinates for all players");
    return 1;
}

stock StripNewLine(string[]) // DracoBlue
{
	new len = strlen(string);
	if (string[0]==0) return;
	if ((string[len - 1] == '\n') || (string[len - 1] == '\r')) {
		string[len - 1] = 0;
		if (string[0]==0) return;
		if ((string[len - 2] == '\n') || (string[len - 2] == '\r')) string[len - 2] = 0;
	}
}

public Commence_Derby()
{
    DerbySettings[Derby_Access] = false;
    
    if(DerbySettings[DerbyMaxPlayers] < 2)
    {
        for(new i; i < MAX_PLAYERS; i++)
		{
			TextDrawHideForPlayer(i, DerbyTextdraw[0]);
			TextDrawHideForPlayer(i, DerbyTextdraw[1]);
			TextDrawHideForPlayer(i, DerbyTextdraw[2]);
			TextDrawHideForPlayer(i, DerbyTextdraw[3]);
			TextDrawHideForPlayer(i, DerbyTextdraw[4]);
			TextDrawHideForPlayer(i, DerbyTextdraw[5]);
			TextDrawHideForPlayer(i, DerbyTextdraw[6]);
			TextDrawHideForPlayer(i, DerbyTextdraw[7]);
			DerbyPlayers[i][DerbySigned] = false;
		}
		SendClientMessageToAll(COLOR_GREEN, "Derby Event couldn't start because there were not enough players (Next derby in "#DERBY_INTERMISSION" seconds)");
		if(DerbySettings[Derby_Enabled]) SetTimer("Start_Derby", strval(DERBY_INTERMISSION) * 1000, false);
		DerbySettings[Derby_Start] = false;
		return 1;
	}
	
	for(new i; i < DerbySettings[DerbyMaxPlayers]; i++)
	{
		for(new a; a < MAX_PLAYERS; a++) TextDrawHideForPlayer(i, DerbyTextdraw[a]);
	    DerbyCoords[i][Derby_Vehicle] = CreateVehicle(DerbyData[Derby_VehModel], DerbyCoords[i][Derby_Position][0], DerbyCoords[i][Derby_Position][1], DerbyCoords[i][Derby_Position][2], DerbyCoords[i][Derby_Position][3], -1, -1, 999999);
		LinkVehicleToInterior(DerbyCoords[i][Derby_Vehicle], DerbyData[Derby_Interior]);
		SetVehicleVirtualWorld(DerbyCoords[i][Derby_Vehicle], DerbyData[Derby_World]);
		FreezeVehicle((DerbyCoords[i][Derby_Vehicle]), true);
		DerbyPlayers[i][DerbyInactive] = 0;
	}
	SetTimer("InitiatePlayers", 3000, 0);
	SendClientMessageToAll(COLOR_GREEN, "Derby Initializing...");
	return 1;
}

public InitiatePlayers()
{
	new iIndex;
	for(new i; i<MAX_PLAYERS; i++)
	{
	    if(!DerbyPlayers[i][DerbySigned]) continue;
	    
	    GetPlayerPos(i, DerbyPlayers[i][DerbyJoinP][0], DerbyPlayers[i][DerbyJoinP][1], DerbyPlayers[i][DerbyJoinP][2]);
	    GetPlayerFacingAngle(i, DerbyPlayers[i][DerbyJoinP][3]);
	    DerbyPlayers[i][DerbyIW][0] = GetPlayerInterior(i);
	    DerbyPlayers[i][DerbyIW][1] = GetPlayerVirtualWorld(i);
	    for(new w; w < 13; w++) GetPlayerWeaponData(i, w, DerbyPlayers[i][DerbyWeapons][w], DerbyPlayers[i][DerbyAmmo][w]);
	    
        RemovePlayerFromVehicle(i);
        ResetPlayerWeapons(i);
        
        SetPlayerInterior(i, DerbyData[Derby_Interior]);
        SetPlayerVirtualWorld(i, DerbyData[Derby_World]);
        PutPlayerInVehicle(i, DerbyCoords[iIndex][Derby_Vehicle], 0);
        TogglePlayerControllable(i, false);
        iIndex++;
	}
	DerbySettings[Derby_Countdown] = strval(DERBY_COUNTDOWN) + 1;
	DerbySettings[Derby_Start] = true;
	CountdownDerby();
	return 1;
}

public CountdownDerby()
{
    new D_Small[5];
    DerbySettings[Derby_Countdown] --;
	if(DerbySettings[Derby_Countdown] >= 1)
	{
	    format(D_Small, sizeof D_Small, "%i", DerbySettings[Derby_Countdown]);
	    for(new i = 0; i < MAX_PLAYERS ;i++)
		{
			if(!DerbyPlayers[i][DerbySigned]) continue;
			GameTextForPlayer(i, D_Small, 1600, 5);
		}
		SetTimer("CountdownDerby", 2000, false);
	}
	else
	{
	    for(new i; i < MAX_PLAYERS ;i++)
		{
			if(!DerbyPlayers[i][DerbySigned]) continue;
			GameTextForPlayer(i, "~g~GO", 999, 5);
			PlayerPlaySound(i, 1057, 0.0, 0.0, 10.0);
			TogglePlayerControllable(i, true);
			if(!IsPlayerInAnyVehicle(i)) KickPlayerFromDerby(i, "You lost the derby for exiting your vehicle.");
			FreezeVehicle(GetPlayerVehicleID(i), false);
		}
		DerbySettings[Derby_Timer] = SetTimer("DerbyRequirementCheck", 1000, false);
		format(DerbyString, sizeof DerbyString, "Derby \"%s\" has been started!", DerbyData[Derby_Name]);
		SendClientMessageToAll(COLOR_GREEN, DerbyString);
	}
	return 1;
}


public KickPlayerFromDerby(playerid, reason[])
{
    DerbyPlayers[playerid][DerbySigned] = false;
    SendClientMessage(playerid, COLOR_ERROR, reason);
    if(DerbySettings[DerbyMaxPlayers] < 2) return EndDerby();
    SetPlayerPos(playerid, DerbyPlayers[playerid][DerbyJoinP][0], DerbyPlayers[playerid][DerbyJoinP][1], DerbyPlayers[playerid][DerbyJoinP][2]);
    SetPlayerFacingAngle(playerid, DerbyPlayers[playerid][DerbyJoinP][3]);
	SetPlayerInterior(playerid, DerbyPlayers[playerid][DerbyIW][0]);
	SetPlayerVirtualWorld(playerid, DerbyPlayers[playerid][DerbyIW][1]);
	ResetPlayerWeapons(playerid);
	for(new w; w < 13; w++) GivePlayerWeapon(playerid, DerbyPlayers[playerid][DerbyWeapons][w], DerbyPlayers[playerid][DerbyAmmo][w]);
	DerbySettings[DerbyMaxPlayers] --;
	return 1;
}

public DerbyRequirementCheck(playerid)
{
    if(DerbySettings[DerbyMaxPlayers] < MIN_DERBY_PLAYERS) return EndDerby();
    
	static CheckLocalData;
	CheckLocalData++;

    for(new i; i<MAX_PLAYERS; i++)
	{
	    if(!DerbyPlayers[i][DerbySigned]) continue;
	    if(DerbyData[Derby_HightMeassure])
	    {
			GetPlayerPos(i, D_X, D_Y, D_Z);
			if (D_Z < DerbyData[Derby_Minheight]) KickPlayerFromDerby(i, "You lost the derby for falling out of range.");
		}
		if(!IsPlayerInAnyVehicle(i))
		{
			KickPlayerFromDerby(i, "You lost the derby for exiting your vehicle.");
			continue;
		}
		if(CheckLocalData >= 20)
		{
			if(DerbyData[Derby_ActiveCheck])
			{
				GetVehicleHealth(GetPlayerVehicleID(i), D_X);
				if(D_X == DerbyPlayers[i][DerbyHealth])
				{
					if(++DerbyPlayers[i][DerbyInactive] >= 20)
					{
					    GetVehicleHealth(GetPlayerVehicleID(i), D_Y);
						SetVehicleHealth(GetPlayerVehicleID(i), D_Y - 150.00);
						SendClientMessage(i, 0xFF0000FF, "Your vehicle health is decreased by 150 for avoiding being hit.");
					}
				}
				else
				{
					DerbyPlayers[i][DerbyHealth] = D_X;
					DerbyPlayers[i][DerbyInactive] = 0;
				}
			}
			CheckLocalData = 0;
  		}
	}
	if(DerbySettings[Derby_Start]) SetTimer("DerbyRequirementCheck", 1000, false);
	return 1;
}

public EndDerby()
{
    if(DerbySettings[DerbyMaxPlayers] >= 2) return 1;
	if(!DerbySettings[Derby_Start]) return 1;
	
	DerbySettings[Derby_Start] = false;
	KillTimer(DerbySettings[Derby_Timer]);
	
	#if defined ENABLE_CLIENT_MSG
    format(DerbyString, sizeof DerbyString, "Derby \"%s\" has ended, (Next derby in "#DERBY_INTERMISSION" seconds)", DerbyData[Derby_Name]);
	SendClientMessageToAll(COLOR_GREEN, DerbyString);
    #endif

	for(new i; i < MAX_PLAYERS; i++)
	{
		if(!DerbyPlayers[i][DerbySigned]) continue;
		DerbyPlayers[i][DerbySigned] = false;
		
		GetPlayerName(i, DerbyString, MAX_PLAYER_NAME);
		format(DerbyString, sizeof DerbyString, "%s won the derby with a reward of $"#MONEY_REWARD" and "#SCORE_REWARD" points", DerbyString);
		SendClientMessageToAll(COLOR_GREEN, DerbyString);
		
		GivePlayerMoney(i, strval(MONEY_REWARD));
		SetPlayerScore(i, GetPlayerScore(i) + strval(SCORE_REWARD));

		SetPlayerPos(i, DerbyPlayers[i][DerbyJoinP][0], DerbyPlayers[i][DerbyJoinP][1], DerbyPlayers[i][DerbyJoinP][2]);
	    SetPlayerFacingAngle(i, DerbyPlayers[i][DerbyJoinP][3]);
		SetPlayerInterior(i, DerbyPlayers[i][DerbyIW][0]);
		SetPlayerVirtualWorld(i, DerbyPlayers[i][DerbyIW][1]);
		ResetPlayerWeapons(i);
		for(new w; w < 13; w++) GivePlayerWeapon(i, DerbyPlayers[i][DerbyWeapons][w], DerbyPlayers[i][DerbyAmmo][w]);
	}
	
	for(new i; i < MAX_DERBY_PLAYERS; i++)
	{
		DestroyVehicle(DerbyCoords[i][Derby_Vehicle]);
		DerbyCoords[i][Derby_Vehicle] = INVALID_VEHICLE_ID;
	}

	DerbySettings[DerbyMaxPlayers] = 0;
	DerbySettings[Derby_Countdown] = 0;
	DerbySettings[Derby_Access] = false;
	
	if(DerbySettings[Derby_Enabled]) SetTimer("Start_Derby", strval(DERBY_INTERMISSION) * 1000, false);
	return 1;
}

public Start_Derby()
{
	LoadNextDerby();
	
	#if defined ENABLE_CLIENT_MSG
	format(DerbyString, sizeof DerbyString,"%s is going to start in "#DERBY_COOLDOWN" seconds, /derby to sign up.", DerbyData[Derby_Name]);
	SendClientMessageToAll(COLOR_GREEN, DerbyString);
    #endif

	DerbySettings[DerbyMaxPlayers] = 0;
    DerbySettings[Derby_Access] = true;
	DerbySettings[Derby_Countdown] = strval(DERBY_COOLDOWN);

    for(new i; i < MAX_PLAYERS; i++)
    {
    	for(new w; w < MAX_TD_FRAMES; w++) TextDrawShowForPlayer(i, DerbyTextdraw[w]);
	    DerbyWait[i] = 0;
	}
	DerbyTextdraws();
	return 1;
}

public DerbyTextdraws()
{
	DerbySettings[Derby_Countdown] --;
	TextDrawSetString(DerbyTextdraw[3], DerbyData[Derby_Name]);

    format(DerbyString, sizeof DerbyString, "Derby is going to start~n~in %i seconds!", DerbySettings[Derby_Countdown]);
	TextDrawSetString(DerbyTextdraw[4], DerbyString);

    format(DerbyString, sizeof DerbyString, "Currently %i Joined!", DerbySettings[DerbyMaxPlayers]);
	TextDrawSetString(DerbyTextdraw[6], DerbyString);

	if(DerbySettings[Derby_Countdown] <= 0)
	{
		for(new i = 0; i < MAX_PLAYERS;i++)
		{
			if(IsPlayerConnected(i) && DerbyPlayers[i][DerbySigned])
			{
				TextDrawHideForPlayer(i, DerbyTextdraw[4]);
				TextDrawHideForPlayer(i, DerbyTextdraw[6]);
			}
		}
		Commence_Derby();
	}
	else SetTimer("DerbyTextdraws", 1000, 0);
}

public OnPlayerConnect(playerid)
{
	DerbyWait[playerid] = gettime() + 45; // I added this to prevent textdraw bugs!
	return 1;
}

public OnPlayerDisconnect(playerid, reason)
{
	if(DerbyPlayers[playerid][DerbySigned])
	{
	    DerbySettings[DerbyMaxPlayers] --;
		DerbyPlayers[playerid][DerbySigned] = false;
	}
	return 1;
}

public OnPlayerDeath(playerid, killerid, reason)
{
	if(DerbyPlayers[playerid][DerbySigned] && DerbySettings[Derby_Start])
	{
		DerbySettings[DerbyMaxPlayers] --;
		DerbyPlayers[playerid][DerbySigned] = false;
		if(DerbySettings[DerbyMaxPlayers] < 2) return EndDerby();
		GameTextForPlayer(playerid, "~r~You have been kicked out!", 4000, 0);
	}
	return 1;
}

public OnPlayerExitVehicle(playerid, vehicleid)
{
	if(DerbyPlayers[playerid][DerbySigned] && DerbySettings[Derby_Start])
	{
		KickPlayerFromDerby(playerid, "You lost the derby for exiting your vehicle.");
	}
	return 1;
}

public FreezeVehicle(vehicleid, toggle) // Seif
{
	new Float:fvX,Float:fvY,Float:fvZ,Float:fvA;
	new mp = GetMaxPlayers();
	for(new all = 0; all < mp; all++)
	{
	    if (GetPlayerState(all) == 2)
	    {
	        if (GetPlayerVehicleID(all) == vehicleid)
	        {
	            TogglePlayerControllable(all,0);
				TogglePlayerControllable(all,1);
	        }
	    }
	}
	GetVehiclePos(vehicleid,fvX,fvY,fvZ);
 	GetVehicleZAngle(vehicleid,fvA);

 	if (toggle == 1) fv[vehicleid] = SetTimerEx("RetVehicle", 200,1,"iffff",vehicleid,fvX,fvY,fvZ,fvA);
	else KillTimer(fv[vehicleid]);
}

public RetVehicle(vehfrz,Float:VX,Float:VY,Float:VZ,Float:VA)
{
	if (!VehicleToPoint(vehfrz,1.0,VX,VY,VZ))
	{
		SetVehiclePos(vehfrz,VX,VY,VZ);
		SetVehicleZAngle(vehfrz,VA);
	}
}

public VehicleToPoint(playerid, Float:radi, Float:px, Float:py, Float:pz)
{
    if(IsPlayerConnected(playerid))
	{
		new Float:x, Float:y, Float:z;
		new Float:ox, Float:oy, Float:oz;
		GetVehiclePos(playerid, ox, oy, oz);
		x = (ox -px);
		y = (oy -py);
		z = (oz -pz);
		if (((x < radi) && (x > -radi)) && ((y < radi) && (y > -radi)) && ((z < radi) && (z > -radi))) return 1;
	}
	return 0;
}

public OnPlayerCommandText(playerid, cmdtext[])
{
	if (strcmp("/derby", cmdtext, true, 10) == 0)
	{
	    if(!DerbySettings[Derby_Enabled]) return SendClientMessage(playerid, COLOR_ERROR, "Derbies are currently closed.");
  		if(!DerbySettings[Derby_Access]) return SendClientMessage(playerid, COLOR_ERROR, "Derby signups are currently closed, wait for the next one to start.");
  		if(DerbyPlayers[playerid][DerbySigned]) return SendClientMessage(playerid, COLOR_ERROR, "You already signed up for the derby, wait for it to start!");
 		if(DerbyWait[playerid] - gettime() > 1) return SendClientMessage(playerid, COLOR_ERROR, "Please wait before you can join the derby!");
     	if(DerbySettings[DerbyMaxPlayers] >= MAX_DERBY_PLAYERS) return SendClientMessage(playerid, COLOR_ERROR, "The arena is full!");

	    DerbySettings[DerbyMaxPlayers] ++;
	    DerbyPlayers[playerid][DerbySigned] = true;
	    GetPlayerName(playerid, DerbyString, MAX_PLAYER_NAME);

	    SendClientMessage(playerid, COLOR_ORANGE, "You have successfully signed up for the derby!");
        TextDrawShowForPlayer(playerid, DerbyTextdraw[6]);

	    #if defined ENABLE_CLIENT_MSG
		format(DerbyString, sizeof DerbyString, "%s has signed up for derby using /derby", DerbyString);
		SendClientMessageToAll(COLOR_ORANGE, DerbyString);
		#endif

		return 1;
	}
	return 0;
}