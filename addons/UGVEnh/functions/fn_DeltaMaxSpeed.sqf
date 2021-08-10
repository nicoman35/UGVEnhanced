/*
	Author: 		Nicoman
	Function: 		NIC_UGV_fnc_DeltaMaxSpeed
	Version: 		1.0
	Edited Date: 	08.08.2021
	
	Description:
		Initiate UGV me addon, add hit event handler to UGV Stomper Enhanced
	
	Parameters:
		_UGV:	Object - Stomper UGV enhanced 
		_delta:	number - Speed change
		
	Returns:
		None
*/

params [["_UGV", objNull], ["_delta", 0]];
if (isNull _UGV || _delta == 0) exitWith {};

private ["_maxSpeed"];

if (NIC_UGV_ENH_AI_GLOBAL_SPEED_LIMIT) then {
	NIC_UGV_ENH_AI_SPEED_LIMIT = NIC_UGV_ENH_AI_SPEED_LIMIT + _delta;
	_maxSpeed = NIC_UGV_ENH_AI_SPEED_LIMIT;
} else {
	if (isNil{_UGV getVariable "NIC_UGV_ENH_MaxSpeed"}) then {
		_UGV setVariable ["NIC_UGV_ENH_MaxSpeed", NIC_UGV_ENH_AI_SPEED_LIMIT];
	};
	_maxSpeed = _UGV getVariable ["NIC_UGV_ENH_MaxSpeed", NIC_UGV_ENH_MaxSpeed];
	_maxSpeed = _maxSpeed + _delta;
	_UGV setVariable ["NIC_UGV_ENH_MaxSpeed", _maxSpeed];
};

_UGV limitSpeed _maxSpeed;
systemChat format[localize "STR_NIC_UGV_MAX_SPEED_SET", _maxSpeed];
