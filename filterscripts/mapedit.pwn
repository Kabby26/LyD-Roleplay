#include <a_samp>
#include <zcmd>
#include <sscanf2>
#define culoare 0xFFFFFFAA
new objects;
new objectmodel[500];
forward WriteLog(string[]);
public OnFilterScriptInit()
{
        printf("|------OBJECTS EDITOR--------|");
        printf("|                            |");
        printf("|                            |");
        printf("|                            |");
        printf("|                            |");
        printf("|----------------------------|");
        return 1;
}
COMMAND:addobject(playerid, params[])
{
    new oid,myobject;
        if (!sscanf(params, "i",oid ))
        {
                new string[128];
                new Float:x, Float:y, Float:z;
        GetPlayerPos(playerid, x, y, z);
            myobject = CreateObject(oid, x+2, y+2, z+2, 0.0, 0.0, 90.0);
            format(string, sizeof(string), "CREATED:%d||CreateObject(%d,%f,%f,%f,0.0,0.0,90.0)",myobject,oid,x,y,z);
            SendClientMessage(playerid,culoare,string);
            objectmodel[myobject]=oid;
                objects++;
            return 1;
        }
        else
        {
            SendClientMessage(playerid,culoare,"USE : /addobject [objectid]");
            SendClientMessage(playerid,culoare,"WARNING : Using an wrong id may crash your server");
            return 1;
        }
}
COMMAND:editobject(playerid, params[])
{
    new oid;
        if (!sscanf(params, "i",oid ))
        {
            EditObject(playerid, oid);
            return 1;
        }else{SendClientMessage(playerid,culoare,"USE : /editobject [objectid]");SendClientMessage(playerid,culoare,"INFO :Type /objects for a list of created objects"); return 1;}
       
}
COMMAND:gotoobject(playerid, params[])
{
    new oid;
        if (!sscanf(params, "i",oid ))
        {
            new Float:xo, Float:yo, Float:zo;
                GetObjectPos(oid, xo, yo, zo);
                SetPlayerPos(playerid,xo+1,yo+1,zo+1);
                return 1;
        }else{SendClientMessage(playerid,culoare,"Use :/gotoobject[objectid]"); return 1;}
}
COMMAND:ohelp(playerid,params[])
{
    SendClientMessage(playerid,culoare,"/addobject || /editobject ||/gotoobject || /objects || /savemap");
    SendClientMessage(playerid,culoare,"/oprew");
        return 1;
}
COMMAND:savemap(playerid, params[])
{
    for(new i = 0; i <=500; i++)
    {
        new stringg[128];
        new Float:RotX,Float:RotY,Float:RotZ;
                GetObjectRot(i, RotX, RotY, RotZ);
                new Float:xo, Float:yo, Float:zo;
                GetObjectPos(i, xo, yo, zo);
                if(xo!=0 && yo!=0 && zo!=0)
                {
                format(stringg, sizeof(stringg), "CreateObject(%d,%f,%f,%f,%f,%f,%f);",objectmodel[i],xo,yo,zo,RotX,RotY,RotZ,90);
                WriteLog(stringg);
        }
       
    }
    new stringg[128];
    format(stringg, sizeof(stringg), "________________//\\_______________");
    WriteLog(stringg);
    SendClientMessage(playerid,culoare,"All Objects have been saved to mapa.txt");
    return 1;
}
COMMAND:objects(playerid, params[])
{
        SendClientMessage(playerid,culoare,"___________L I S T______________");
    for(new i = 1; i <=500; i++)
    {
        new stringg[128];
        new Float:RotX,Float:RotY,Float:RotZ;
                GetObjectRot(i, RotX, RotY, RotZ);
                new Float:xo, Float:yo, Float:zo;
                GetObjectPos(i, xo, yo, zo);
                if(xo!=0 && yo!=0 && zo!=0)
                {
                format(stringg, sizeof(stringg), "ID:%dCreateObject(%d,%f,%f,%f,%f,%f,%f);",i,objectmodel[i],xo,yo,zo,RotX,RotY,RotZ);
                SendClientMessage(playerid,culoare,stringg);
                }
 
    }
    SendClientMessage(playerid,culoare,"________________________________");
    return 1;
}
public WriteLog(string[])
{
        new entry[192];
        format(entry, sizeof(entry), "%s\n",string);
        new File:hFile;
        hFile = fopen("mapa.txt", io_append);
        fwrite(hFile, entry);
        fclose(hFile);
        return 1;
}
public OnPlayerEditObject(playerid, playerobject, objectid, response, Float:fX, Float:fY, Float:fZ, Float:fRotX, Float:fRotY, Float:fRotZ)
{
    if(response == EDIT_RESPONSE_FINAL)
        {
        SetObjectPos(objectid,fX,fY,fZ);
        SetObjectRot(objectid,fRotX,fRotY,fRotZ);
        SendClientMessage(playerid,culoare,"Object Saved");
        return 1;
        }
        return 1;
}