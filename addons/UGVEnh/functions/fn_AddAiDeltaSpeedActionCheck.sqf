/*
	Author: 		Nicoman
	Function: 		NIC_UGV_fnc_AddAiDeltaSpeedActionCheck
	Version: 		1.0
	Edited Date: 	08.08.2021
	
	Description:
		Checks, if delta max speed action is available
	
	Parameters:
		_UGV:	Object - Stomper UGV enhanced 
	
	Returns:
		bool
*/

// diag_log formatText ["%1%2%3%4%5", time, "s (NIC_UGV_fnc_AddAiDeltaSpeedActionCheck) 	 This: ", _this];

params [["_UGV", objNull]];
if (isNull _UGV) exitWith {false};
if (UAVControl _UGV #0 == player) exitWith {true};
if (_UGV == cursorObject && _UGV distance player < 20) exitWith {true};
false
