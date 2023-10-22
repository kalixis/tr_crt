/*

	About: Convert Russian text to Special Symbols v1.3
	Author: kalixis

*/

#if !defined _samp_included
	#error "Please include a_samp or a_npc before tr_crt"
#endif

#if defined _tr_crt_included_
	#endinput
#endif
#define _tr_crt_included_

/*

	Define const

*/

#if !defined MAX_CRT_SIZE
	#define MAX_CRT_SIZE 256
#endif

/*

	Vars

*/

static const
	crt_text_aya[] = {"aó¢ôöeõüúùkûØÆo£pc¶yÅxâ§•°ß®©™´¨"}, // Ù, ˆ
	crt_text_AYA[] = {"AÄãÇÉEÑàÖÜKáMHOåPCèYÅXâçéäêëíìîï"};

/*

	Private functions

*/

static stock ConvertRussianToSpecialSymbols(const string[], buffer[])
{
	for (new c, i; (c = string[i]) != '\0'; i++) {
		switch (c) {
			case '‡'..'ˇ':
				buffer[i] = crt_text_aya[c - '‡'];
			case '¿'..'ﬂ':
				buffer[i] = crt_text_AYA[c - '¿'];
			case '∏':
				buffer[i] = 'e';
			case '®':
				buffer[i] = 'E';
			default:
				buffer[i] = c;
		}
	}
}

/*

	GameTextForAll

*/

stock tr_crt_GameTextForAll(const string[], time, style)
{
	new
		info[MAX_CRT_SIZE + 1];

	ConvertRussianToSpecialSymbols(string, info);
	return GameTextForAll(info, time, style);
}
#if defined _ALS_GameTextForAll
	#undef GameTextForAll
#else
	#define _ALS_GameTextForAll
#endif

#define GameTextForAll( tr_crt_GameTextForAll(

/*

	GameTextForPlayer

*/

stock tr_crt_GameTextForPlayer(playerid, const string[], time, style)
{
	new
		info[MAX_CRT_SIZE + 1];

	ConvertRussianToSpecialSymbols(string, info);
	return GameTextForPlayer(playerid, info, time, style);
}
#if defined _ALS_GameTextForPlayer
	#undef GameTextForPlayer
#else
	#define _ALS_GameTextForPlayer
#endif

#define GameTextForPlayer( tr_crt_GameTextForPlayer(

/*

	TextDrawCreate

*/

stock Text:tr_crt_TextDrawCreate(Float:x, Float:y, const text[])
{
	new
		info[MAX_CRT_SIZE + 1];

	ConvertRussianToSpecialSymbols(text, info);
	return TextDrawCreate(x, y, info);
}
#if defined _ALS_TextDrawCreate
	#undef TextDrawCreate
#else
	#define _ALS_TextDrawCreate
#endif

#define TextDrawCreate( tr_crt_TextDrawCreate(

/*

	TextDrawSetString

*/

stock tr_crt_TextDrawSetString(Text:text, const string[])
{
	new
		info[MAX_CRT_SIZE + 1];

	ConvertRussianToSpecialSymbols(string, info);
	return TextDrawSetString(text, info);
}
#if defined _ALS_TextDrawSetString
	#undef TextDrawSetString
#else
	#define _ALS_TextDrawSetString
#endif

#define TextDrawSetString( tr_crt_TextDrawSetString(

/*

	CreatePlayerTextDraw

*/

stock PlayerText:tr_crt_CreatePlayerTextDraw(playerid, Float:x, Float:y, const text[])
{
	new
		info[MAX_CRT_SIZE + 1];

	ConvertRussianToSpecialSymbols(text, info);
	return CreatePlayerTextDraw(playerid, x, y, info);
}
#if defined _ALS_CreatePlayerTextDraw
	#undef CreatePlayerTextDraw
#else
	#define _ALS_CreatePlayerTextDraw
#endif

#define CreatePlayerTextDraw( tr_crt_CreatePlayerTextDraw(

/*

	PlayerTextDrawSetString

*/

stock tr_crt_PlayerTextDrawSetString(playerid, PlayerText:text, const string[])
{
	new
		info[MAX_CRT_SIZE + 1];

	ConvertRussianToSpecialSymbols(string, info);
	return PlayerTextDrawSetString(playerid, text, info);
}
#if defined _ALS_PlayerTextDrawSetString
	#undef PlayerTextDrawSetString
#else
	#define _ALS_PlayerTextDrawSetString
#endif

#define PlayerTextDrawSetString( tr_crt_PlayerTextDrawSetString(