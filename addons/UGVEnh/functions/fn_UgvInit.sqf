/*
	Author: 		Nicoman
	Function: 		NIC_UGV_fnc_UgvInit
	Version: 		1.0
	Edited Date: 	08.08.2021
	
	Description:
		Initiate addon, define CBA variables, add init event handler to UGV Stomper Enhanced units
	
	Parameters:
		None
	
	Returns:
		None
*/

if (isNil "NIC_UGV_ENH_AI_SPEED_LIMIT_ALLOW") then {NIC_UGV_ENH_AI_SPEED_LIMIT_ALLOW 		= true};						// reduce max speed limit for AI?
if (isNil "NIC_UGV_ENH_AI_SPEED_LIMIT") then {NIC_UGV_ENH_AI_SPEED_LIMIT 					= 45};							// max speed limit in km/h when AI is driving the vehicle
if (isNil "NIC_UGV_ENH_AI_SPEED_DELTA") then {NIC_UGV_ENH_AI_SPEED_DELTA 					= 5};							// change of max speed limit in km/h
if (isNil "NIC_UGV_ENH_AI_ROAD_MAX") then {NIC_UGV_ENH_AI_ROAD_MAX 							= true};						// no speed limit on roads
if (isNil "NIC_UGV_ENH_AI_SPEED_DELTA_ALLOW") then {NIC_UGV_ENH_AI_SPEED_DELTA_ALLOW 		= true};						// change of max speed limit action dialogs allowed
if (isNil "NIC_UGV_ENH_AI_GLOBAL_SPEED_LIMIT") then {NIC_UGV_ENH_AI_GLOBAL_SPEED_LIMIT 		= true};						// change of max speed limit is global; all UGVs will be limited to same speed

["NIC_UGV_01_Enhanced", "init", {_this call NIC_UGV_fnc_AddAiDeltaSpeedAction}, true] call CBA_fnc_addClassEventHandler;	// adds init event to all UGV Enhanced vehicles; has to be run preinit!
["NIC_UGV_01_Enhanced", "Engine", {_this spawn NIC_UGV_fnc_CheckRoads}, true] call CBA_fnc_addClassEventHandler;			// adds engine event to all UGV Enhanced vehicles; has to be run preinit!