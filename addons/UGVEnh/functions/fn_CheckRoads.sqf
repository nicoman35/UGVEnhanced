/*
	Author: 		Nicoman
	Function: 		NIC_UGV_fnc_CheckRoads
	Version: 		1.0
	Edited Date: 	23.08.2021
	
	Description:
		Check, if Ugv is currently on a road or not. 
		
	Parameters:
		_UGV:		Object - UGV
		
	Returns:
		None
*/

// diag_log formatText ["%1%2%3%4%5", time, "s (NIC_UGV_fnc_CheckRoads) 	 This: ", _this];

params [["_UGV", objNull], "_engineOn"];
if (isNull _UGV) exitWith {};
if (typeOf _UGV != "NIC_UGV_01_Enhanced" || !NIC_UGV_ENH_AI_SPEED_LIMIT_ALLOW || !_engineOn) exitWith {};

if (!isNil{_UGV getVariable "NIC_UGV_ENH_Check_Roads_Mutex"}) exitWith {};
_UGV setVariable ["NIC_UGV_ENH_Check_Roads_Mutex", true];

if (isNil{_UGV getVariable "NIC_UGV_ENH_MaxSpeed"}) then {
	_UGV setVariable ["NIC_UGV_ENH_MaxSpeed", NIC_UGV_ENH_AI_SPEED_LIMIT];
	// diag_log formatText ["%1%2%3%4%5", time, "s (NIC_UGV_fnc_CheckRoads) 	 NIC_UGV_ENH_MaxSpeed set: ", NIC_UGV_ENH_MaxSpeed];
};

while {isEngineOn _UGV && alive _UGV && NIC_UGV_ENH_AI_SPEED_LIMIT_ALLOW && NIC_UGV_ENH_AI_ROAD_MAX} do {
	if (isOnRoad _UGV) then {
		_UGV limitSpeed -1;
		// hintSilent "On road, max speed: /";
	} else {
		// private _maxSpeed = _UGV getVariable ["NIC_UGV_ENH_MaxSpeed", NIC_UGV_ENH_MaxSpeed];
		private _maxSpeed = _UGV getVariable "NIC_UGV_ENH_MaxSpeed";
		if (NIC_UGV_ENH_AI_GLOBAL_SPEED_LIMIT) then {
			_maxSpeed = NIC_UGV_ENH_AI_SPEED_LIMIT;
		};
		_UGV limitSpeed _maxSpeed;
		// hintSilent format["Off road, max speed: %1", _maxSpeed];
	};
	sleep 2;
};

if (NIC_UGV_ENH_AI_SPEED_LIMIT_ALLOW && alive _UGV) then {
	private _maxSpeed = _UGV getVariable "NIC_UGV_ENH_MaxSpeed";
	if (NIC_UGV_ENH_AI_GLOBAL_SPEED_LIMIT) then {
		_maxSpeed = NIC_UGV_ENH_AI_SPEED_LIMIT;
	};
	_UGV limitSpeed _maxSpeed;
};

_UGV setVariable ["NIC_UGV_ENH_Check_Roads_Mutex", nil];