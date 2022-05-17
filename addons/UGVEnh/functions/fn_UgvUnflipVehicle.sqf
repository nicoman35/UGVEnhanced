/*
	Author: 		Nicoman
	Function: 		NIC_UGV_fnc_UgvUnflipVehicle
	Version: 		1.1
	Edited Date: 	23.10.2021
	
	Description:
		a) Upon engine start/stop, start loop of detecting, wether vehicle is flipped. If so, unflip it.
		b) Turn off engine, if vehicle does not move and driver does not have any commands
		
	Parameters:
		_UGV:		Object - UGV Vehicle
		
	Returns:
		None
*/

waitUntil {time > 0};

params [["_UGV", objNull]];
if (isNil "_UGV") exitWith {};

if (!isNil {_UGV getVariable "NIC_UgvUnflipLoop"}) exitWith {};
_UGV setVariable ["NIC_UgvUnflipLoop", true, true];											// mutex for not having multiple instances of unflip loops running simultaneously

if (isNil{_UGV getVariable "NIC_UGV_ENH_MaxSpeed"}) then {
	_UGV setVariable ["NIC_UGV_ENH_MaxSpeed", NIC_UGV_ENH_AI_SPEED_LIMIT];
	_UGV limitSpeed NIC_UGV_ENH_AI_SPEED_LIMIT;
	systemChat format[localize "STR_NIC_UGV_MAX_SPEED_SET", NIC_UGV_ENH_AI_SPEED_LIMIT];
};
sleep 1;

private ["_upsideDown", "_bank", "_flipLeft", "_bbr", "_UGVWidth", "_force", "_forcePointX", "_forcePointZ"];

private _engineOFFcounter = 0;
private _forceFactor = 1;
while {alive _UGV && _engineOFFcounter < 5} do {
	_engineOFFcounter = _engineOFFcounter + 1;
	if (isEngineOn _UGV) then {
		_engineOFFcounter = 0;
		if (currentCommand _UGV == "" && abs(speed _UGV) < 0.1) then {_UGV engineOn false};	// turn off engine no later than 10 s after uav is not reviving any move commands
	};
	(_UGV call BIS_fnc_getPitchBank) params ["_vx", "_vy"];
	if (([_vx, _vy] findIf {_x > 80 || _x < -80}) != -1 && {!canMove _UGV}) then {
		_upsideDown = (vectorUp _UGV vectorDotProduct surfaceNormal getPos _UGV) < -0.80;
		_bank = _UGV call BIS_fnc_getPitchBank select 1;
		_flipLeft = _bank >= 0;
		if (_upsideDown) then {_flipLeft = !_flipLeft};										// When upside down then left is right and right is left
		if (!_upsideDown && 55 > abs _bank) exitWith {false};
		_bbr = boundingBoxReal _UGV;
		_UGVWidth = abs ((_bbr #0 #0) * 2);
		_force = getMass _UGV * ([1 + (_UGVWidth/10), _UGVWidth] select _upsideDown) * _forceFactor;
		_forcePointX = _bbr select ([0, 1] select _flipLeft) select 0;
		_forcePointZ = _bbr select ([1, 0] select _upsideDown) select 2;
		_UGV addForce [_UGV vectorModelToWorld [[_force, -_force] select _flipLeft, 0, 0], [_forcePointX, 0, _forcePointZ]];
		_forceFactor = _forceFactor + (_engineOFFcounter / 20);
	};
	sleep 10;
};
_UGV setVariable ["NIC_UgvUnflipLoop", nil, true];										// anill mutex