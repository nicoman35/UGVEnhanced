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
		class close: manual	{
			aiBurstTerminable		= 1;
			showToPlayer			= 0;
			burst					= 5;
			burstRangeMax			= 12;
			aiRateOfFire			= 0.5;
			aiRateOfFireDispersion	= 1.5;
			aiRateOfFireDistance	= 50;
			minRange				= 0;
			minRangeProbab			= 0.79999999;
			midRange				= 200;
			midRangeProbab			= 0.79999999;
			maxRange				= 300;
			maxRangeProbab			= 0.4;
		};
		class short: close {
			aiBurstTerminable		= 1;
			showToPlayer			= 0;
			burst					= 4;
			burstRangeMax			= 12;
			aiRateOfFire			= 1;
			aiRateOfFireDispersion	= 2;
			aiRateOfFireDistance	= 150;
			minRange				= 100;
			minRangeProbab			= 0.79999999;
			midRange				= 500;
			midRangeProbab			= 0.85;
			maxRange				= 1000;
			maxRangeProbab			= 0.4;
		};
		class medium: close	{
			aiBurstTerminable		= 1;
			showToPlayer			= 0;
			burst					= 3;
			burstRangeMax			= 8;
			aiRateOfFire			= 2;
			aiRateOfFireDispersion	= 2;
			aiRateOfFireDistance	= 400;
			minRange				= 400;
			minRangeProbab			= 0.85;
			midRange				= 1000;
			midRangeProbab			= 0.79999999;
			maxRange				= 2000;
			maxRangeProbab			= 0.2;
		};
		class far: close {
			aiBurstTerminable		= 1;
			showToPlayer			= 0;
			burst					= 3;
			burstRangeMax			= 8;
			aiRateOfFire			= 4;
			aiRateOfFireDispersion	= 4;
			aiRateOfFireDistance	= 800;
			minRange				= 1000;
			minRangeProbab			= 0.60000002;
			midRange				= 1800;
			midRangeProbab			= 0.45;
			maxRange				= 2500;
			maxRangeProbab			= 0.2;
		};
	};
};
class Viewoptics;
class RCWSOptics;
class Turrets;
class MainTurret;
class Components;
class Eventhandlers;
class HitPoints	{
	class HitLFWheel;
	class HitLBWheel;
	class HitLMWheel;
	class HitLF2Wheel;
	class HitRFWheel;
	class HitRBWheel;
	class HitRMWheel;
	class HitRF2Wheel;
};
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
		transportSoldier	= 1;		// Does not work proplerly. AI troops board the vehicle, but refuse to disembark when commanded to. Workaround: Command eject.
		class Viewoptics: ViewOptics {
			visionMode[]	= {"Normal", "NVG", "Ti"};
			thermalMode[]	= {4, 5};
		};
		class HitPoints: HitPoints {
			class HitHull {
				armor 				= 1;
				material			= 50;
				armorComponent		= "hit_hull";
				name				= "hit_hull_point";
				visual				= "zbytek";
				passThrough			= 1;
				minimalHit			= 0.2;
				explosionShielding	= 0.2;
				radius				= 0.30000001;
			};
			class HitEngine {
				armor			 	= 2;
				material			= -1;
				armorComponent		= "hit_engine";
				name				= "hit_engine_point";
				visual				= "-";
				passThrough			= 0.5;
				minimalHit			= 0.2;
				explosionShielding	= 0.2;
				radius				= 0.30000001;
			};
			class HitFuel {
				armor				= 1;
				material			= -1;
				armorComponent		= "hit_fuel";
				name				= "hit_fuel_point";
				visual				= "-";
				passThrough			= 0.30000001;
				minimalHit			= 0.1;
				explosionShielding	= 0.60000002;
				radius				= 0.30000001;
			};
			class HitLFWheel: HitLFWheel {
				armor 	= 1;
				name	= "wheel_1_1";
			};
			class HitLF2Wheel: HitLF2Wheel {
				armor 	= 1;
				name	= "wheel_1_2";
			};
			class HitLMWheel: HitLMWheel {
				armor 	= 1;
				name	= "wheel_1_3";
			};
			class HitRFWheel: HitRFWheel {
				armor 	= 1;
				name	= "wheel_2_1";
			};
			class HitRF2Wheel: HitRF2Wheel {
				armor 	= 1;
				name	= "wheel_2_2";
			};
			class HitRMWheel: HitRMWheel {
				armor 	= 1;
				name	= "wheel_2_3";
			};
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