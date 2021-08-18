/*
	Author: 		Nicoman
	Function: 		NIC_UGV_fnc_UgvUnflipVehicle
	Version: 		1.0
	Edited Date: 	08.08.2021
	
	Description:
		Starts loop of detecting, wether vehicle is flipped. If so, unflip it.
	
	Parameters:
		_UGV:		Object - UGV Vehicle
		
	Returns:
		None
*/

params [["_UGV", objNull]];
if (isNil "_UGV") exitWith {};

if (!isNil {_UGV getVariable "NIC_UgvUnflipLoop"}) exitWith {};
_UGV setVariable ["NIC_UgvUnflipLoop", true];			// mutex for not having multiple instances of unflip loops running simultaneously

if (isNil{_UGV getVariable "NIC_UGV_ENH_MaxSpeed"}) then {
	_UGV setVariable ["NIC_UGV_ENH_MaxSpeed", NIC_UGV_ENH_AI_SPEED_LIMIT];
	_UGV limitSpeed NIC_UGV_ENH_AI_SPEED_LIMIT;
	systemChat format[localize "STR_NIC_UGV_MAX_SPEED_SET", NIC_UGV_ENH_AI_SPEED_LIMIT];
};

private _engineOFFcounter = 0;
while {alive _UGV && _engineOFFcounter < 5} do {
	_engineOFFcounter = _engineOFFcounter + 1;
	if (isEngineOn _UGV) then {_engineOFFcounter = 0};
	(_UGV call BIS_fnc_getPitchBank) params ["_vx", "_vy"];
	if (([_vx,_vy] findIf {_x > 80 || _x < -80}) != -1 && {!canMove _UGV}) then {
		private _upsideDown = (vectorUp _UGV vectorDotProduct surfaceNormal getPos _UGV) < -0.80;
		private _bank = _UGV call BIS_fnc_getPitchBank select 1;
		
		private _flipLeft = _bank >= 0;
		if (_upsideDown) then {_flipLeft = !_flipLeft};		// When upside down then left is right and right is left
		if (!_upsideDown && 55 > abs _bank) exitWith {false};

		private _bbr = boundingBoxReal _UGV;
		private _UGVWidth = abs (_bbr #0 #0 * 2);
		private _forceFactor = 1;
		
		// force factor is set in vet_unflipping_unflip_start event
		private _lastUnflipAttempt = _UGV getVariable ["vet_lastUnflipAttempt", time];
		if (isNil{UNFLIP_FORCEFACTOR_EXPIRATIONTIME}) then {UNFLIP_FORCEFACTOR_EXPIRATIONTIME = 300};
		private _forceFactor = if ((time - _lastUnflipAttempt) < UNFLIP_FORCEFACTOR_EXPIRATIONTIME) then {
			_UGV getVariable ["vet_forceFactor", 1]
		} else {
			_UGV setVariable ["vet_forceFactor", nil];
			1
		};
		_UGV setVariable ["vet_lastUnflipAttempt", time];

		private _force = getMass _UGV * ([1 + (_UGVWidth/10), _UGVWidth] select _upsideDown) * _forceFactor;
		private _forcePointX = _bbr select ([0, 1] select _flipLeft) select 0;
		private _forcePointZ = _bbr select ([1, 0] select _upsideDown) select 2;
		_UGV addForce [
			_UGV vectorModelToWorld [[_force, -_force] select _flipLeft, 0, 0],
			[_forcePointX, 0, _forcePointZ]
		];
	};
	sleep 10;
};
_UGV setVariable ["NIC_UgvUnflipLoop", nil];