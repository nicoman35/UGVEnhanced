/*
	Author: 		Nicoman
	Function: 		NIC_UGV_fnc_AddMineDetector
	Version: 		1.0
	Edited Date: 	14.05.2022
	
	Description:
		Add backpacks and mine detectors both to driver and gunner of the UGV
		
	Parameters:
		_UGV:		Object - UGV Vehicle 
		
	Returns:
		None
*/

params [["_UGV", objNull]];
if (isNull _UGV) exitWith {};

driver _UGV addBackpack "B_AssaultPack_blk";											// add a backpack to vehicle's AI driver
driver _UGV addItem "MineDetector";														// for the driver mine detector display to work, add a mine detector to driver's inventory
gunner _UGV addBackpack "B_AssaultPack_blk";											// add a backpack to vehicle's AI gunner
gunner _UGV addItem "MineDetector";														// for the gunner mine detector display to work, add a mine detector to gunner's inventory
