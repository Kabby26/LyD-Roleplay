#include <YSI\y_hooks>

// - - - - - - -  - - - - - - -  <-- HELP SYSTEM

new const StandartHelp[36][] = {
	{"sup"},
    {"admin"},
    {"admin"},
    {"anrufen"},
    {"navi"},
    {"suche"},
    {"spielerinfo"},
    {"rauchzig"},
    {"zigweg"},
    {"geben"},
    {"liste"},
    {"inventar"},
    {"koffer"},
    {"kofferauf"},
    {"firmen"},
    {"mutetime"},
    {"animlist"},
    {"staatskasse"},
    {"leader"},
    {"gutscheincode"},
    {"musik"},
    {"mp3player"},
    {"ghettoblaster"},
    {"removeghettoblaster"},
    {"jailtime"},
    {"spawnchange"},
    {"clubhelp"},
    {"werbetafelkaufen"},
    {"werbetafelfinden"},
    {"werbetafel"},
    {"eventpreise"},
    {"mineninfo"},
    {"showjob"},
    {"jobkleidung"},
    {"skill"},
    {"upgradeinfo"}
};

new const MoneyHelp[6][]= {
    {"findatm"},
    {"automat"},
    {"ueberweisen"},
    {"gebecheck"},
    {"guthaben"},
    {"zahlen"}
};

new DeathmatchHelp[17][]= {
    {"nimmdrogen"},
    {"nimmspice"},
    {"isskeks"},
    {"kampfstyle"},
    {"pickwaffe"},
    {"jailtime"},
    {"tottime"},
    {"killauftrag"},
    {"driveby"},
    {"gangfightwette"},
    {"gangfightinfo"},
    {"gfinfo"},
    {"swinfo"},
    {"tankstelleausrauben"},
    {"bankhacken"},
    {"transporterausrauben"},
    {"robninedemons"}
};

new SellHelp[4][]= {
    {"sellkekse"},
    {"sellwantedcodes"},
    {"solldrogen"},
    {"sellwaffenteile"}
};

new CasinoHelp[4][]= {
    {"spielautomat"},
    {"wettspiel"},
    {"kartenspiel"},
    {"gluecksrad"}
};

new VehicleHelp[26][]= {
    {"radio"},
    {"carlock"},
    {"carkey"},
    {"movecarkey"},
    {"findcar"},
    {"flock"},
    {"tanken"},
    {"carsell"},
    {"parken"},
    {"licht"},
    {"motor"},
    {"fenster"},
    {"rauswerfen"},
    {"kanister"},
    {"kofferraum"},
    {"kofferraumansehen"},
    {"fahrzeugschein"},
    {"scheine"},
    {"scheinsperre"},
    {"fahrzeuginfo"},
    {"lock"},
    {"mieten"},
    {"entmieten"},
    {"mietlock"},
    {"findmietcar"},
    {"fahrpruefung"}
};

new HouseHelp[15][]= {
    {"hauskaufen"},
    {"zuhause"},
    {"hausupgrade"},
    {"hausmieten"},
    {"haustuer"},
    {"hausmenu"},
    {"hausverkaufen"},
    {"hausverstaatlichen"},
    {"hausmietung"},
    {"hausraus"},
    {"hausrausalle"},
    {"hausabgeben"},
    {"hoteltuer"},
    {"miethotelraum"},
    {"entmietenhotelraum"}
};

new BizHelp[10][]= {
    {"bizkaufen"},
    {"bizverkaufen"},
    {"bizverstaatlichen"},
    {"bizkassestand"},
    {"bizkasse"},
    {"biztuer"},
    {"eintritt"},
    {"warenverkaufsstelle1"},
    {"warenverkaufsstelle2"},
    {"warenverkaufsstelle3"}
};

new TankstelleHelp[9][]= {
    {"tankekaufen"},
    {"tankstelleverkaufen"},
    {"tankeverstaatlichen"},
    {"maxbenzin"},
    {"tankkassestand"},
    {"tankkasse"},
    {"spritverkaufsstelle1"},
    {"spritverkaufsstelle2"},
    {"spritverkaufsstelle3"}
};

new FirmenHelp[5][]= {
    {"firmenkasse"},
    {"firmengehalt"},
    {"firmennachricht"},
    {"entlassen"},
    {"firmen"}
};

new ChatHelp[19][]= {
    {"f"},
    {"s"},
    {"nc"},
    {"ic"},
    {"jc"},
    {"chatanim"},
    {"firmen"},
    {"gc"},
    {"chatoff"},
    {"anrufen"},
    {"sms"},
    {"auflegen"},
    {"abnehmen"},
    {"guthaben"},
    {"handystatus"},
    {"sendfs"},
    {"delfs"},
    {"fsliste"},
    {"fschat"}
};

new HaustierHelp[4][]= {
    {"haustier"},
    {"sellhaustier"},
    {"fuettern"},
    {"haustiershop"}
};

new LeaderHelp[1][]= {
    {"leaderhelp"}
};

new Job1Help[2][]= {
    {"startbauer"},
    {"stopbauer"}
};

new Job2Help[2][]= {
    {"startlinie"},
    {"stoplinie"}
};

new Job3Help[6][]= {
    {"loadbenzin"},
    {"startbenzin"},
    {"loadwaren"},
    {"startwaren"},
    {"ladung"},
    {"entladen"}
};

new Job4Help[2][]= {
    {"startflug"},
    {"stopflug"}
};

new Job5Help[2][]= {
    {"nachtanken"},
    {"reparieren"}
};

new Job6Help[2][]= {
    {"befreien"},
    {"sliste"}
};

new Job7Help[2][]= {
    {"startreinigung"},
    {"stopreinigung"}
};

new Job8Help[3][]= {
    {"startmuell"},
    {"stopmuell"},
    {"entleeren"}
};

new Job9Help[2][]= {
    {"startgarten"},
    {"stopgarten"}
};

new Job10Help[2][]= {
    {"startbauerbeiter"},
    {"stopbauerbeiter"}
};

new Job11Help[2][]= {
    {"startschiff"},
    {"stopschiff"}
};

new Job12Help[2][]= {
    {"starttransport"},
    {"stoptransport"}
};

new Job13Help[1][]= {
    {"eisverkaufen"}
};

new Job14Help[2][]= {
    {"dfinden"},
    {"dzeigen"}
};

new Job15Help[2][]= {
    {"pizzaverkaufen"},
    {"sliste"}
};

new Job16Help[1][]= {
    {"starttaxi"}
};

new Job17Help[2][]= {
    {"paketeinladen"},
    {"paketentladen"}
};

new Job18Help[2][]= {
    {"paketeinladen"},
    {"paketentladen"}
};

new Job19Help[1][]= {
    {"tascheklauen"}
};

new Job20Help[1][]= {
    {"sex"}
};

new Job21Help[3][]= {
    {"wantedhacken"},
    {"wcodes"},
    {"sellwantedcodes"}
};

new Job22Help[1][]= {
    {"autoknacken"}
};

new Job23Help[2][]= {
    {"startzug"},
    {"stopzug"}
};

new Job24Help[1][]= {
    {"hotdogverkaufen"}
};

new Frak1Help[68][]= {
    {"clear"},
    {"pdclear"},
    {"dienst"},
    {"sliste"},
    {"acceptcop"},
    {"mitglieder"},
    {"dienstmarke"},
    {"sp"},
    {"staatskasse"},
    {"haussuchen"},
    {"beamteon"},
    {"reinziehen"},
    {"freilassen"},
    {"verhaften"},
    {"entnehmen"},
    {"koffereinziehen"},
    {"offlinearrest"},
    {"rufdetektiv"},
    {"scheinentziehen"},
    {"arrest"},
    {"w"},
    {"caufbrechen"},
    {"zollamt"},
    {"ticket"},
    {"schutzgeldpolizei"},
    {"aufbrechen"},
    {"knastzeit"},
    {"finden"},
    {"pflanzeverbrennen"},
    {"gangpflanzeverbrennen"},
    {"zollsperre"},
    {"parkstrafe"},
    {"strafzettel"},
    {"entschaerfen"},
    {"fc"},
    {"bc"},
    {"vk"},
    {"pvk"},
    {"cpartner"},
    {"acceptpartner"},
    {"ve"},
    {"kofferdurchsuchen"},
    {"durchsuchen"},
    {"promille"},
    {"pakte"},
    {"gefangene"},
    {"meldestelle"},
    {"parkscheinkontrolle"},
    {"vamt"},
    {"kfzsuchen"},
    {"kzsuchen"},
    {"uclight"},
    {"copman"},
    {"copfrau"},
    {"rank"},
    {"rankfrau"},
    {"copcap"},
    {"copcapf"},
    {"copmuetze"},
    {"tcop"},
    {"pschild"},
    {"copbrille"},
    {"waffenspind"},
    {"vrk"},
    {"hsirene"},
    {"pein"},
    {"ermitteln"},
    {"findfcars"}
};

new Frak3Help[19][]= {
    {"dienst"},
    {"aufnehmen"},
    {"deskwb"},
    {"sheilen"},
    {"samdgarage"},
    {"mv"},
    {"m"},
    {"kasse"},
    {"kassenstand"},
    {"mitglieder"},
    {"sfinden"},
    {"bc"},
    {"sliste"},
    {"acceptsani"},
    {"rtwsirene"},
    {"meinsatz"},
    {"bk"},
    {"dtasche"},
    {"findfcars"}
};

new Frak4Help[11][]= {
    {"dienst"},
    {"news"},
    {"starteventpoint"},
    {"stopeventpoint"},
    {"interview"},
    {"Kasse"},
    {"Kassenstand"},
    {"mitglieder"},
    {"sanagarage"},
    {"fskin"},
    {"findfcars"}
};

new Frak5Help[41][]= {
    {"dienst"},
    {"ov"},
    {"ogate"},
    {"beamteon"},
    {"mitglieder"},
    {"zollamt"},
    {"dienstmarke"},
    {"kasse"},
    {"kassenstand"},
    {"okamera"},
    {"sp"},
    {"fpunkte"},
    {"ticket"},
    {"strafzettel"},
    {"parkstrafe"},
    {"entnehmen"},
    {"koffereinziehen"},
    {"scheinentziehen"},
    {"blitzerabbauen"},
    {"blitzeraufstellen"},
    {"tierverbot"},
    {"deltierverbot"},
    {"oparken"},
    {"ofreistellen"},
    {"fmparkkralle"},
    {"mparkkralle"},
    {"festnehmen"},
    {"fparken"},
    {"durchsuchen"},
    {"kofferdurchsuchen"},
    {"vamt"},
    {"pakte"},
    {"kfzsuchen"},
    {"kzsuchen"},
    {"promille"},
    {"bc"},
    {"fc"},
    {"m"},
    {"ovk"},
    {"bk"},
    {"findfcars"}
};

new FrakGangHelp[34][]= {
    {"gangwaffen"},
    {"gheilen"},
    {"mitglieder"},
    {"buendnis"},
    {"kasse"},
    {"kassenstand"},
    {"fc"},
    {"bg"},
    {"flock"},
    {"gdg"},
    {"frespawn"},
    {"kidnap"},
    {"mundbinde"},
    {"augenbinde"},
    {"fesseln"},
    {"entfesseln"},
    {"gangjail"},
    {"aufbrechen"},
    {"frakblacklist"},
    {"addfrakblacklist"},
    {"delfrakblacklist"},
    {"gangfight"},
    {"gangfightstop"},
    {"fge"},
    {"gangfightinfo"},
    {"swinfo"},
    {"schutzgeld"},
    {"schutzgeldabbrechen"},
    {"gangpflanzen"},
    {"findfcars"},
    {"samenpaketeinladen"},
    {"samenpaketentladen"},
    {"samenlagerpunkt"},
    {"selldrogen"}
};

new Frak14Help[18][]= {
    {"accept hitman"},
    {"hitmanwaffen"},
    {"gheilen"},
    {"hwerbung"},
    {"fc"},
    {"flock"},
    {"hmaske"},
    {"kasse"},
    {"kassenstand"},
    {"mitglieder"},
    {"hrelease"},
    {"arz"},
    {"agbefreien"},
    {"knastbefreien"},
    {"agtor"},
    {"atorhacken"},
    {"acceptag"},
    {"findfcars"}
};

new Frak15Help[20][]= {
    {"ninowaffen"},
    {"gheilen"},
    {"fsafebox"},
    {"fc"},
    {"flock"},
    {"pflanzen"},
    {"kidnap"},
    {"augenbinde"},
    {"samen"},
    {"samenpunkte"},
    {"sellkrauter"},
    {"kasse"},
    {"kassenstand"},
    {"mitglieder"},
    {"samenlager"},
    {"paketeinladen"},
    {"storepakete"},
    {"storesamen"},
    {"samenlagerstatus"},
    {"findfcars"}
};

new Frak19Help[12][]= {
    {"fc"},
    {"kasse"},
    {"kassenstand"},
    {"kassenstand"},
    {"mitglieder"},
    {"flock"},
    {"bombelegen"},
    {"terrorwaffen"},
    {"entfesseln"},
    {"kidnap"},
    {"terrorgate"},
    {"findfcars"}
};

new const StandartHelpText[36][] = {
	{"Supportticket erstellen"},
    {"Nachricht an Admins versenden"},
    {"Nachricht an Admins versenden"},
    {"Spieler anrufen"},
    {"Navigtionspunkte anzeigen"},
    {"Spieler suchen"},
    {"Spielerinformationen anzeigen"},
    {"Zigarette Rauchen"},
    {"Zigarette Wegwerfen"},
    {"Inventare geben"},
    {"Online Liste"},
    {"Inventar anzeigen"},
    {"Koffer holen/weglegen"},
    {"Koffer öffnen"},
    {"Firmen anzeigen"},
    {"Mutezeit anzeigen"},
    {"Animationsliste"},
    {"Staatskasse"},
    {"Leaderliste"},
    {"Gutscheincode einlösen"},
    {"Musik abspielen"},
    {"Mp3Player starten"},
    {"Ghettoblaster aufstellen"},
    {"Ghettoblaster entfernen"},
    {"Jailtime anzeigen"},
    {"Spawnpunkt ändern"},
    {"Clubbefehle anzeigen"},
    {"Werbetafel kaufen"},
    {"Werbetafel finden"},
    {"Werbetafel bearbeiten"},
    {"Eventpreise anzeigen"},
    {"Minen Informationen"},
    {"Jobpunkt anzeigen"},
    {"Jobkleidung anziehen"},
    {"Skillliste öffnen"},
    {"Skillupgrade bzw. Skillup einsehen"}
};

new const MoneyHelpText[6][]= {
    {"Nächsten Geldautomaten anzeigen"},
    {"Interaktiv mit Geldautomaten"},
    {"Überweisung tätigen"},
    {"Geldcheck vergeben"},
    {"Handyguthaben einsehen"},
    {"Zahlungen tätigen"}
};

new DeathmatchHelpText[17][]= {
    {"Drogen einnehmen"},
    {"Spice einnehmen"},
    {"Kekse essen"},
    {"Kampfstyle ändern"},
    {"Waffen aufheben"},
    {"Knastzeit"},
    {"Totzeit"},
    {"Kopfgeld stellen"},
    {"Drive-By tätigen"},
    {"Gangfightwette"},
    {"Gangfight Informationen"},
    {"Gangfight Informationen"},
    {"Streetwar Informationen"},
    {"Tankstelle ausrauben"},
    {"Bank ausrauben"},
    {"Geldtransporter ausrauben"},
    {"NineDemons Safebox ausrauben"}
};

new SellHelpText[4][]= {
    {"Kekse verkaufen"},
    {"Wantedhackercodes verkaufen"},
    {"Drogen verkaufen"},
    {"Waffenteile verkaufen"}
};

new CasinoHelpText[4][]= {
    {"Spielautomat im Casino"},
    {"Wettspiel im Casino"},
    {"kartenspiel im Casino"},
    {"gluecksrad im Casino"}
};

new VehicleHelpText[26][]= {
    {"Radio abspielen"},
    {"Fahrzeug aufschließen und abschließen"},
    {"Fahrzeugschlüssel wechseln"},
    {"Fahrzeugschlüssel Slot ändern"},
    {"Fahrzeug orten"},
    {"Fraktionsfahrzeug abschließen"},
    {"Fahrzeug Tanken"},
    {"Fahrzeug verkaufen"},
    {"Parken"},
    {"Licht"},
    {"Motor"},
    {"Fenster öffnen"},
    {"Spieler aus Fahrzeug rauswerfen"},
    {"Kanister benutzen"},
    {"Kofferraum öffnen"},
    {"Kofferraum ansehen"},
    {"Fahrzeugschein ansehen"},
    {"Führerscheine ansehen"},
    {"Scheinsperre Informationen"},
    {"Fahrzeug Informationen"},
    {"Mietfahrzeug abschließen"},
    {"Fahrzeug mieten"},
    {"Mietfahrzeug abgeben"},
    {"Mietfahrzeug abschließen"},
    {"Mietfahrzeug orten"},
    {"Führerscheinprüfung starten"}
};

new HouseHelpText[15][]= {
    {"Haus kaufen"},
    {"Wohnort anzeigen"},
    {"Haussafebox und Waffenlager"},
    {"Wohnung mieten"},
    {"Haustür abschließen und aufschließen"},
    {"Hausmenü"},
    {"Haus an einen Spieler verkaufen"},
    {"Haus an den Staat verkaufen"},
    {"Mieterliste"},
    {"Mieter kündigen"},
    {"Allen Mietern kündigen"},
    {"Haus an den Staat verkaufen"},
    {"Hoteltür abschließen und aufschließen"},
    {"Hotelraum mieten"},
    {"Hotelraum kündigen"}
};

new BizHelpText[10][]= {
    {"Business kaufen"},
    {"Business verkaufen"},
    {"Business an den Staat verkaufen"},
    {"Business Kasse"},
    {"Business Kasse"},
    {"Business aufschließen und abschließen"},
    {"Business Eintritt festlegen"},
    {"Business Waren kaufen"},
    {"Business Waren kaufen"},
    {"Business Waren kaufen"}
};

new TankstelleHelpText[9][]= {
    {"Tankstelle kaufen"},
    {"Tankstelle verkaufen"},
    {"Tankstelle an den Staat verkaufen"},
    {"Tankstelle Benzinlager"},
    {"Tankstelle Kasse"},
    {"Tankstelle Kasse"},
    {"Tankstelle Sprit kaufen"},
    {"Tankstelle Sprit kaufen"},
    {"Tankstelle Sprit kaufen"}
};

new FirmenHelpText[5][]= {
    {"Firmen Kasse"},
    {"Firmen Gehalt anpassen"},
    {"Firmennachricht"},
    {"Spieler entlassen"},
    {"Alle Firmen anzeigen"}
};

new ChatHelpText[19][]= {
    {"flüstern"},
    {"schreien"},
    {"Neulingschat"},
    {"Roleplay Chat"},
    {"Job Chat"},
    {"Reden Animation"},
    {"Alle Firmen anzeigen"},
    {"Gobaler Serverchat"},
    {"Chats ausschalten"},
    {"Spieler anrufen"},
    {"SMS schreiben"},
    {"Anruf auflegen"},
    {"Anruf abnehmen"},
    {"Guthaben einsehen"},
    {"Handy anschalten und ausschalten"},
    {"Freundschaftsanfrage senden"},
    {"Freund löschen"},
    {"Freundschaftsliste"},
    {"Freundschaftschat"}
};

new HaustierHelpText[4][]= {
    {"Haustier"},
    {"Haustier verkaufen"},
    {"Haustier füttern"},
    {"Haustiershop"}
};

new LeaderHelpText[1][]= {
    {"leaderhelp"}
};

new SupporterHelp[41][]= {
    {"Goto"},
    {"Gethere"},
    {"Spawn"},
    {"Kick"},
    {"Ban (Level 1-3)"},
    {"Spec"},
    {"Specoff"},
    {"Adienst"},
    {"Gebannt"},
    {"Spawncar"},
    {"Setafk"},
    {"Mute"},
    {"Sichercode"},
    {"Sc"},
    {"Freeze"},
    {"Unfreeze"},
    {"Guncheck"},
    {"Check"},
    {"Checkscheine"},
    {"Supauto"},
    {"Respawncar"},
    {"Delveh"},
    {"Rghettoblaster"},
    {"Gotocp"},
    {"Asettings"},
    {"Gotohaus"},
    {"Regelwarnung"},
    {"Openticket"},
    {"Delticket"},
    {"Dticket"},
    {"Aticket"},
    {"Closeticket"},
    {"Tickets"},
    {"Rjobcars"},
    {"Rfrakcars"},
    {"Jobs"},
    {"Fraktionen"},
    {"Ngeld"},
    {"Gotocar"},
    {"Getcar"},
    {"Gotopos"}
};

new EventSupporterHelp[30][]= {
    {"Sethp"},
    {"Setarmor"},
    {"Veh"},
    {"Givegun"},
    {"Aeventitem"},
    {"Awiederbeleben"},
    {"Startevent"},
    {"Stopevent"},
    {"Eventpunkte"},
    {"Eventuhr"},
    {"Eventmarker"},
    {"Clearweapons"},
    {"Setmark"},
    {"Delmark"},
    {"Gotomark"},
    {"Waffeumgebung"},
    {"Healumgebung"},
    {"Armorumgebung"},
    {"Freezeumgebung"},
    {"Unfreezeumgebung"},
    {"Addobject"},
    {"Editobject"},
    {"Gotoobject"},
    {"Removeobject"},
    {"Removeallobjects"},
    {"Objectlist"},
    {"Addlabel"},
    {"Removelabel"},
    {"Removealllabels"},
    {"Dust2"}
};

new ModeratorHelp[47][]= {
    {"Ban"},
    {"Ipban"},
    {"Tban"},
    {"zollsperre"},
    {"Verwarnen"},
    {"Prison"},
    {"Cprison"},
    {"Offprison"},
    {"Offcprison"},
    {"Clearchat"},
    {"Gotoliste"},
    {"Delallvehs"},
    {"Spec"},
    {"Specoff"},
    {"Changeweather"},
    {"Bizkassestand"},
    {"Setinterior"},
    {"Spielerip"},
    {"Akteneintrag"},
    {"Waffensperre"},
    {"Atafelentmieten"},
    {"Checkskill"},
    {"Afkick"},
    {"Configplayer"},
    {"Entbannen"},
    {"Offbannen"},
    {"Offtban"},
    {"Fraksperre"},
    {"Delfraksperre"},
    {"Respawnallcars"},
    {"Oafkick"},
    {"Offverwarnen"},
    {"Gebeskill"},
    {"Gcoff"},
    {"Inballon"},
    {"Givecar"},
    {"Adminwarnung"},
    {"Bwstrafe"},
    {"Bwstrafen"},
    {"Setbwstrafe"},
    {"Ageld"},
    {"Alevel"},
    {"Arp"},
    {"Offageld"},
    {"Lastdmg"},
    {"Carowner"},
    {"Setkasse"}
};

new FraktionsverwalterHelp[8][]= {
    {"Makeleader"},
    {"Setzoneowner"},
    {"Gebietupgrade"},
    {"Awaffenlager"},
    {"Fsbreset"},
    {"Createfcar"},
    {"FCarcolor"},
    {"Delfcar"}
};

new AdministratorHelp[23][]= {
    {"Sban"},
    {"Confighouse"},
    {"Configbiz"},
    {"Rauswerfenhotel"},
    {"Configtanke"},
    {"Gebefirma"},
    {"Delfirma"},
    {"Gebeclub"},
    {"Delclub"},
    {"Bfreischalten (2. Biz-Schlüssel)"},
    {"SFreischalten (6. Schlüssel)"},
    {"Namechange"},
    {"Createhouse"},
    {"delhouse"},
    {"Fixveh"},
    {"Gotoad"},
    {"Purge"},
    {"Delallgvehs"},
    {"Adminbase"},
    {"Adminbase2"},
    {"PGiveGun"},
    {"PGiveHealth"},
    {"PGiveArmor"}
};

new VertretungBennyHelp[6][]= {
    {"Creategutschein"},
    {"Amotor"},
    {"Pwchange"},
    {"Aunlock"},
    {"Givecoins"},
    {"Configbiz"}
};

new ManagerHelp[7][]= {
    {"Createaplatz"},
    {"Createtanke"},
    {"Createhotelroom"},
    {"Startlotto"},
    {"MakeBMOD"},
    {"MakeFV"},
    {"Adminmaske"}
};

new ProjektleiterHelp[11][]= {
    {"Makeadmin"},
    {"Offmakeadmin"},
    {"Gmx"},
    {"Event"},
    {"Pwchange"},
    {"Givecoins"},
    {"Vehcolor"},
    {"Jailtimeout"},
    {"Debugpos"},
    {"Tankstand"},
    {"Auftanken"}
};

/*new RconHelp[11][]= {
    {"Makeadmin"},
    {"Gmx"}
};*/


// - - - - - - - - - - - - - - -