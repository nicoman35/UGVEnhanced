/*
	Author: 		Nicoman
	Function: 		NIC_UGV_fnc_CheckRoads
	Version: 		1.0
	Edited Date: 	25.10.2021
	
	Description:
		Check, if Ugv is currently on a road or not. If AI speed limit is not to be reduced on roads,
		(NIC_UGV_ENH_AI_ROAD_MAX = true), raise max speed limit is lifted. Once off road, max speed
		limit is imposed again.
		
	Parameters:
		_UGV:		Object - UGV
		
	Returns:
		None
*/

params [["_UGV", objNull], "_engineOn"];
if (isNull _UGV || !_engineOn) exitWith {};
if (typeOf _UGV != "NIC_UGV_01_Enhanced" || !NIC_UGV_ENH_AI_SPEED_LIMIT_ALLOW) exitWith {};

if (!isNil{_UGV getVariable "NIC_UGV_ENH_Check_Roads_Mutex"}) exitWith {};
_UGV setVariable ["NIC_UGV_ENH_Check_Roads_Mutex", true, true];

if (isNil{_UGV getVariable "NIC_UGV_ENH_MaxSpeed"}) then {
	_UGV setVariable ["NIC_UGV_ENH_MaxSpeed", NIC_UGV_ENH_AI_SPEED_LIMIT];
};

while {isEngineOn _UGV && alive _UGV && NIC_UGV_ENH_AI_SPEED_LIMIT_ALLOW && NIC_UGV_ENH_AI_ROAD_MAX} do {
	if (isOnRoad _UGV) then {
		_UGV limitSpeed -1;
	} else {
		private _maxSpeed = _UGV getVariable "NIC_UGV_ENH_MaxSpeed";
		if (NIC_UGV_ENH_AI_GLOBAL_SPEED_LIMIT) then {
			_maxSpeed = NIC_UGV_ENH_AI_SPEED_LIMIT;
		};
		_UGV limitSpeed _maxSpeed;
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

_UGV setVariable ["NIC_UGV_ENH_Check_Roads_Mutex", nil, true];