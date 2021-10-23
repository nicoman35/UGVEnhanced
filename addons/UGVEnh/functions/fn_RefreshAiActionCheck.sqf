/*
	Author: 		Nicoman
	Function: 		NIC_UGV_fnc_RefreshAiActionCheck
	Version: 		1.0
	Edited Date: 	25.10.2021
	
	Description:
		Checks, if action 'Refresh AI' is available
	
	Parameters:
		_UGV:	Object - UGV Vehicle 
	
	Returns:
		bool
*/

params [["_UGV", objNull]];
if (isNull _UGV) exitWith {};

if (UAVControl _UGV select 0 == player) exitWith {true};
if (_UGV == cursorObject && _UGV distance player < 50) exitWith {true};
false
