[
	"NIC_UGV_ENH_AI_SPEED_LIMIT_ALLOW",																				// internal setting name, should always contain a tag! This will be the global variable which takes the value of the setting.
	"CHECKBOX",																										// setting type
	[format[localize "STR_NIC_UGV_AI_SPEED_LIMIT_ALLOW"], format[localize "STR_NIC_UGV_AI_SPEED_LIMIT_ALLOW_TIP"]],	// [setting name, tooltip]
	format[localize "STR_NIC_UGV_TITLE"],																			// pretty name of the category where the setting can be found. Can be stringtable entry.
	true,																											// default value of setting
    true,																											// "_isGlobal" flag. Set this to true to always have this setting synchronized between all clients in multiplayer
	{
		{
			[_x] call NIC_UGV_fnc_AddAiDeltaSpeedAction;
		} foreach vehicles;
	}																												// code executed on setting change
] call CBA_fnc_addSetting;
[
	"NIC_UGV_ENH_AI_SPEED_LIMIT",
	"SLIDER",
	[format[localize "STR_NIC_UGV_MAX_SPEED"], format[localize "STR_NIC_UGV_MAX_SPEED_TIP"]],
	format[localize "STR_NIC_UGV_TITLE"],
	[20, 75, 45, 0],																								// [_min, _max, _default, _trailingDecimals]
    true,
	{NIC_UGV_ENH_AI_SPEED_LIMIT = round NIC_UGV_ENH_AI_SPEED_LIMIT}
] call CBA_fnc_addSetting;
[
	"NIC_UGV_ENH_AI_ROAD_MAX",
	"CHECKBOX",
	[format[localize "STR_NIC_UGV_MAX_SPEED_RD"], format[localize "STR_NIC_UGV_MAX_SPEED_RD_TIP"]],
	format[localize "STR_NIC_UGV_TITLE"],
	true,
    true
] call CBA_fnc_addSetting;
[
	"NIC_UGV_ENH_AI_SPEED_DELTA",
	"SLIDER",
	[format[localize "STR_NIC_UGV_MAX_SPEED_D"], format[localize "STR_NIC_UGV_MAX_SPEED_D_TIP"]],
	format[localize "STR_NIC_UGV_TITLE"],
	[2, 20, 5, 0],
	true,
	{NIC_UGV_ENH_AI_SPEED_DELTA = round NIC_UGV_ENH_AI_SPEED_DELTA}
] call CBA_fnc_addSetting;
[
	"NIC_UGV_ENH_AI_SPEED_DELTA_ALLOW",
	"CHECKBOX",
	[format[localize "STR_NIC_UGV_MAX_SPEED_D_A"], format[localize "STR_NIC_UGV_MAX_SPEED_D_A_TIP"]],
	format[localize "STR_NIC_UGV_TITLE"],
	true,
    true,
	{
		{
			[_x] call NIC_UGV_fnc_AddAiDeltaSpeedAction;
		} foreach vehicles;
	}	
] call CBA_fnc_addSetting;
[
	"NIC_UGV_ENH_AI_GLOBAL_SPEED_LIMIT",
	"CHECKBOX",
	[format[localize "STR_NIC_UGV_MAX_SPEED_GLB"], format[localize "STR_NIC_UGV_MAX_SPEED_GLB_TIP"]],
	format[localize "STR_NIC_UGV_TITLE"],
	true,
    true
] call CBA_fnc_addSetting;
[
	"NIC_UGV_ENH_AI_REFRESH_ALLOW",
	"CHECKBOX",
	[format[localize "STR_NIC_UGV_REFRESH"], format[localize "STR_NIC_UGV_REFRESH_TIP"]],
	format[localize "STR_NIC_UGV_TITLE"],
	true,
    true,
	{
		{
			[_x] call NIC_UGV_fnc_AddAiRefreshAction;
		} foreach vehicles;
	}		
] call CBA_fnc_addSetting;