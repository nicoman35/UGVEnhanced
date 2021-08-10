/*
	Author: 		Nicoman
	Function: 		NIC_UGV_fnc_AddAiDeltaSpeedAction
	Version: 		1.0
	Edited Date: 	07.08.2021
	
	Description:
		Add / remove 'Increase / Decrease' actions to this UGV
		
	Parameters:
		_UGV:		Object - UGV
		
	Returns:
		None
*/

params [["_UGV", objNull]];
if (isNull _UGV) exitWith {};
if (typeOf _UGV != "NIC_UGV_01_Enhanced") exitWith {};

if (isNil{_UGV getVariable "NIC_UGV_ENH_MaxSpeed"}) then {
	_UGV setVariable ["NIC_UGV_ENH_MaxSpeed", NIC_UGV_ENH_AI_SPEED_LIMIT];
	_UGV limitSpeed NIC_UGV_ENH_AI_SPEED_LIMIT;
};

if (!NIC_UGV_ENH_AI_SPEED_LIMIT_ALLOW) then {
	_UGV setVariable ["NIC_UGV_ENH_MaxSpeed", nil];
	_UGV limitSpeed -1;
	NIC_UGV_ENH_AI_SPEED_DELTA_ALLOW = false;
};

if (!NIC_UGV_ENH_AI_SPEED_DELTA_ALLOW) exitWith {										// remove increase / decrease actions
	{
		_actionID = _UGV getVariable _x;
		_UGV removeAction _actionID;
		_UGV setVariable [_x, nil, false];
	} foreach ["EUGV_ActionID_Increase", "EUGV_ActionID_Decrease"];
};

if (isNil{_UGV getVariable "EUGV_ActionID_Increase"}) then {							// increase max speed
	private _actionID = _UGV addAction [
		format[localize "STR_NIC_UGV_INCREASE"],										// Title
		{[_this select 0, NIC_UGV_ENH_AI_SPEED_DELTA] call NIC_UGV_fnc_DeltaMaxSpeed},	// Script
		nil,																			// Arguments
		0,																				// Priority
		false,																			// showWindow
		true,																			// hideOnUse
		"",																				// Shortcut
		"[_target] call NIC_UGV_fnc_AddAiDeltaSpeedActionCheck"							// Condition
	];
	_UGV setVariable ["EUGV_ActionID_Increase", _actionID];
};
if (isNil{_UGV getVariable "EUGV_ActionID_Decrease"}) then {
	private _actionID = _UGV addAction [
		format[localize "STR_NIC_UGV_DECREASE"],
		{[_this select 0, -NIC_UGV_ENH_AI_SPEED_DELTA] call NIC_UGV_fnc_DeltaMaxSpeed},
		nil,
		0,
		false,
		true,
		"",
		"[_target] call NIC_UGV_fnc_AddAiDeltaSpeedActionCheck"
	];
	_UGV setVariable ["EUGV_ActionID_Decrease", _actionID];
};
