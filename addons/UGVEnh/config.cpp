#include "BIS_AddonInfo.hpp"
class CfgPatches {
	class UGV_01_Enhanced {
		version 			= 1;
		units[] 			= {"NIC_UGV_01_Enhanced"};
		weapons[] 			= {"HMG_127_UGV_SNIPER"};
		requiredVersion		= 0.1;
		requiredAddons[]	= {
			"A3_Characters_F",
			"A3_Characters_F_Beta",
			"A3_Weapons_F",
			"A3_Static_F",
			"A3_Air_F",
			"A3_Data_F",
			"A3_Soft_F",
			"A3_Modules_F",
			"A3_Modules_F_Curator"
		};
	};
};
class CfgFunctions {
	class NIC_UGV {
		class Functions {
			file="UGVEnh\functions";
			class UgvInit {
				preInit = 1;
			};
			class AddAiDeltaSpeedAction {};
			class AddAiDeltaSpeedActionCheck {};
			class DeltaMaxSpeed {};
		};
	};
};
class Extended_PreInit_EventHandlers {
	class UGV_Enhanced {
		init = "call compile preprocessFileLineNumbers '\UGVEnh\scripts\XEH_preInit.sqf'"; // CBA_a3 integration
	};
};
class DefaultVehicleSystemsDisplayManagerLeft {
	class components;
};
class DefaultVehicleSystemsDisplayManagerRight {
	class components;
};
class HMG_127_UGV;
class manual;
class cfgWeapons {
	class HMG_127_UGV_SNIPER: HMG_127_UGV {
		scope			= 2;
		maxZeroing 		= 2500;
		class manual: manual {
			reloadTime	= 0.15;
			dispersion	= 0.0002;
		};
	};
};
class Viewoptics;
class RCWSOptics;
class Turrets;
class MainTurret;
class Components;
class Eventhandlers;
class CfgVehicles {
	class B_UGV_01_rcws_F;
	class NIC_UGV_01_Enhanced: B_UGV_01_rcws_F {
		author 				= "NIC";
		_generalMacro		= "NIC_UGV_01_Enhanced";
		side				= 1;
		faction				= "BLU_F";
		scope				= 2;
		scopeCurator		= 2;
		forceInGarage		= 1;
		displayName			= "UGV Stomper Enhanced";
		canFloat			= 1;
		maxSpeed			= 75;
		redRpm				= 3800;
		class complexGearbox {
			GearboxRatios[] 	= {
				"R1",
				-4.1819999,
				"N",
				0,
				"D1",
				4.1820002,
				"D2",
				3.3180001,
				"D3",
				2.1500001,
				"D4",
				1.4100001
			};
			TransmissionRatios[] = {
				"High",
				5.539
			};
		};
		enginePower			= 100;
		fuelCapacity		= 20;
		maxOmega			= 380;
		armor				= 40;
		transportSoldier	= 1;		// Does not work proplerly. AI troops board the vehicle, but refuse to disembark when commanded. Only getting them out by force via Zeus works. Workaround: Command eject.
		class Viewoptics: ViewOptics {
			visionMode[]	= {"Normal", "NVG", "Ti"};
			thermalMode[]	= {4,5};
		};
		class Components: Components {  
			class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft {
				class components {
					class EmptyDisplay {
						componentType = "EmptyDisplayComponent";
					};
					class MinimapDisplay {
						componentType="MinimapDisplayComponent";
						resource="RscCustomInfoMiniMap";
					};
					class UAVDisplay {
						componentType="UAVFeedDisplayComponent";
					};
					class MineDetectorDisplay {			// Tried to add mine detector display component, but failed. For vehicles, missile display works, when driver has a mine detector. UGV does not, because the 'driver' is an AI. Further investigation needed
						componentType	= "MineDetectorDisplayComponent";
					};
				};
			};
			class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight {
				class components {
					class EmptyDisplay {
						componentType="EmptyDisplayComponent";
					};
					class MinimapDisplay {
						componentType="MinimapDisplayComponent";
						resource="RscCustomInfoMiniMap";
					};
					class UAVDisplay {
						componentType="UAVFeedDisplayComponent";
					};
					class MineDetectorDisplay {
						componentType	= "MineDetectorDisplayComponent";
					};
				};
			};
		};
		class Turrets: Turrets {
			class MainTurret: MainTurret {
				startEngine				= "false";
				weapons[]				= {
					"HMG_127_UGV_SNIPER",
					"GMG_40mm",
					"Laserdesignator_vehicle"
				};
				class ViewOptics: RCWSOptics {
					visionMode[] 		= {"Normal", "NVG", "TI"};
					initFov 			= 0.4667;
					maxFov 				= 0.4667;
					minFov 				= 0.01;			// raised zoom level
					directionStabilized = 1;
					thermalMode[] 		= {5,6};
				};
				magazines[]= {
					"500Rnd_127x99_mag_Tracer_Red",
					"500Rnd_127x99_mag_Tracer_Red",
					"96Rnd_40mm_G_belt",
					"Laserbatteries"
				};
				minElev					= -15;
				discreteDistance[]		= {100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000,2100,2200,2300,2400,2500};
				aggregateReflectors[] 	= {"Light_1"};
				class Reflectors {
					class Light_1 {
						color[] 			= {10000,10000,9500};
						ambient[] 			= {500,500,450};
						intensity 			= 100;
						size 				= 1;
						innerAngle			= 5;
						outerAngle 			= 35;
						coneFadeCoef 		= 12;
						position 			= "PiP1_pos";
						direction 			= "PiP1_dir";
						hitpoint 			= "HitHull";
						selection 			= "Light_1";
						useFlare 			= 1;
						flareSize 			= 10;
						flareMaxDistance 	= 1000;
						dayLight 			= 1;
						class Attenuation {
							start 			= 0;
							constant 		= 0;
							linear			= 0;
							quadratic		= 0.01;
							hardLimitStart 	= 475;
							hardLimitEnd 	= 600;
						};
					};
				};
			};
		};
		class Eventhandlers: Eventhandlers {
			engine = 	"_this select 0 execVM '\UGVEnh\functions\fn_UgvUnflipVehicle.sqf';";
		};
	};
};