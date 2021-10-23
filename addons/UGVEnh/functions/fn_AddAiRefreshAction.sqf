/*
	Author: 		Nicoman
	Function: 		NIC_UGV_fnc_AddAiRefreshAction
	Version: 		1.0
	Edited Date: 	25.10.2021
	
	Description:
		Add 'Refresh UAV AI' action to this UAV
		
	Parameters:
		_UGV:		Object - UGV Vehicle 
		
	Returns:
		None
*/

params [["_UGV", objNull]];
if (isNull _UGV) exitWith {};
if (typeOf _UGV != "NIC_UGV_01_Enhanced") exitWith {};
if (isNil "NIC_UGV_ENH_AI_REFRESH_ALLOW") exitWith {};

private ["_actionID"];
if (!NIC_UGV_ENH_AI_REFRESH_ALLOW) exitWith {								// remove 'Refresh AI' action dialog
	_actionID = _UGV getVariable "UGV_ActionID_RefreshAi";
	_UGV removeAction _actionID;
	_UGV setVariable ["UGV_ActionID_RefreshAi", nil, true];
};

if (isNil{_UGV getVariable "UGV_ActionID_RefreshAi"}) then {				// add 'Refresh AI' action dialog to uav
	_actionID = _UGV addAction [
		"Refresh AI",														// Title
		{_this select 0 call NIC_UGV_fnc_RefreshAi},						// Script
		nil,																// Arguments
		0,																	// Priority
		false,																// showWindow
		true,																// hideOnUse
		"",																	// Shortcut
		"[_target] call NIC_UGV_fnc_RefreshAiActionCheck"					// Condition
	];
	_UGV setVariable ["UGV_ActionID_RefreshAi", _actionID];
};
