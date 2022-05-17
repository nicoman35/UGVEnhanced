/*
	Author: 		Nicoman
	Function: 		NIC_UGV_fnc_RefreshAi
	Version: 		1.0
	Edited Date: 	23.10.2021
	
	Description:
		Deletes old AI crew of an UGV, then creates a new one. Reconnects player and reassigns old role.
		Intention: 	Sometimes, UGVs get unresponsive to commands. 
					By replacing the UAV crew with a new one, hopefully
					things get corrected and the UAV gets responsive again.
	
	Parameters:
		_UGV:		Object - UGV Vehicle 
		
	Returns:
		None
*/

params [["_UGV", objNull]];
if (isNull _UGV) exitWith {};

private _connectedPlayer = UAVControl _UGV select 0;
private _role = UAVControl _UGV select 1;
_connectedPlayer connectTerminalToUAV objNull;
private _group = group _UGV;	
for "_i" from count waypoints _group - 1 to 0 step -1 do {deleteWaypoint [_group, _i]};			// delete all group waypoints from last to first
sleep 0.1;																							// needed short waiting period for group to 'achieve' current waypoint
{_UGV deleteVehicleCrew _x} forEach crew _UGV;														// delete every AI unit in UAV group
sleep 0.1;																							// wait a bit (eventually not needed?)
createVehicleCrew _UGV;																				// create new UAV AI group
(group ((crew _UGV) select 0)) setBehaviour "SAFE";
if !(isNull _connectedPlayer) then {																
	_connectedPlayer connectTerminalToUAV _UGV;														// if player was connected, reconnect player
	if (_role == "Driver") exitWith {_connectedPlayer action ["SwitchToUAVDriver", _UGV]};			// if player was driver, give player driver role
	if (_role == "Gunner") then {_connectedPlayer action ["SwitchToUAVGunner", _UGV]};				// if player was gunner, give player gunner role
};

_UGV call NIC_UGV_fnc_AddMineDetector;																// add mine detectors to ugv crew