#include "BIS_AddonInfo.hpp"
class CfgPatches {
	class UGV_01_Enhanced {
		version 			= 1;
		units[] 			= {"NIC_UGV_01_Enhanced"};
		weapons[] 			= {
				"HMG_127_UGV_SNIPER",
				"GMG_40mm_SNIPER"
		};
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
			file = "UGVEnh\functions";
			class UgvInit {
				preInit = 1;
			};
			class AddAiDeltaSpeedAction {};
			class AddAiDeltaSpeedActionCheck {};
			class AddAiRefreshAction {};
			class AddMineDetector {};
			class CheckRoads {};
			class DeltaMaxSpeed {};
			class RefreshAi {};	
			class RefreshAiActionCheck {};
			class UgvUnflipVehicle {};
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
class Mode_Burst;
class GMG_40mm;
class GMG_F;
class cfgWeapons {
	class HMG_127_UGV_SNIPER: HMG_127_UGV {
		scope			= 2;
		displayName		= "$STR_NIC_UGV_HMG";
		modes[]			= {
			"manual",
			"precisionBurst",
			"close",
			"short",
			"medium",
			"far"
		};
		maxZeroing 		= 2500;
		class precisionBurst: Mode_Burst {
			reloadTime	= 0.15;
			dispersion	= 0.0002;
			burst		= 3;
			sounds[]	= {
				"StandardSound"
			};
			class StandardSound	{
				begin1[]		= {
					"A3\Sounds_F\arsenal\weapons_vehicles\HMG_127mm\HMG_127mm_01",
					1.5848932,
					1,
					2100
				};
				begin2[]		= {
					"A3\Sounds_F\arsenal\weapons_vehicles\HMG_127mm\HMG_127mm_02",
					1.5848932,
					1,
					2100
				};
				begin3[]		= {
					"A3\Sounds_F\arsenal\weapons_vehicles\HMG_127mm\HMG_127mm_03",
					1.5848932,
					1,
					2100
				};
				soundBegin[]	= {
					"begin1",
					0.33000001,
					"begin2",
					0.33000001,
					"begin3",
					0.34
				};
				closure1[]		= {
					"A3\Sounds_F\weapons\Closure\sfx10",
					0.63095737,
					1,
					20
				};
				closure2[]		= {
					"A3\sounds_f\weapons\closure\sfx11",
					0.63095737,
					1.2,
					20
				};
				soundClosure[]	= {
					"closure1",
					0.5,
					"closure2",
					0.5
				};
			};
		};
		class manual: manual {
			dispersion	= 0.0008;		// original value: 0.0016
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
	class GMG_40mm_SNIPER: GMG_40mm {
		scope		=2;
		displayName	="$STR_NIC_UGV_GMG_40mm";
		magazines[]	= {
			"200Rnd_40mm_G_belt",
			"96Rnd_40mm_G_belt",
			"64Rnd_40mm_G_belt",
			"32Rnd_40mm_G_belt"
		};
		magazineReloadTime=20;
		showAimCursorInternal=0;
		modes[]		= {
			"manual",
			"close",
			"short",
			"medium",
			"far"
		};
		class manual: GMG_F {
			displayName				="$STR_A3_GMG_40mm0";
			sounds[]				= {
				"StandardSound"
			};
			class StandardSound
			{
				begin1[]		= {
					"A3\Sounds_F\arsenal\weapons_static\Static_GMG\GMG_01",
					1.1220185,
					1,
					1200
				};
				begin2[]		= {
					"A3\Sounds_F\arsenal\weapons_static\Static_GMG\GMG_02",
					1.1220185,
					1,
					1200
				};
				begin3[]		= {
					"A3\Sounds_F\arsenal\weapons_static\Static_GMG\GMG_03",
					1.1220185,
					1,
					1200
				};
				soundBegin[]	= {
					"begin1",
					0.33000001,
					"begin2",
					0.33000001,
					"begin3",
					0.34
				};
			};
			soundContinuous			= 0;
			soundBurst				= 0;
			dispersion				= 0.00099999999;		// original value: 0.0049999999	
			aiRateOfFire			= 1;
			aiRateOfFireDistance	= 10;
			minRange				= 0;
			minRangeProbab			= 0.0099999998;
			midRange				= 1;
			midRangeProbab			= 0.0099999998;
			maxRange				= 2;
			maxRangeProbab			= 0.0099999998;
		};
		class close: manual {
			aiBurstTerminable		= 1;
			showToPlayer			= 0;
			burst					= 1;
			burstRangeMax			= 6;
			aiRateOfFire			= 1;
			aiRateOfFireDispersion	= 2;
			aiRateOfFireDistance	= 50;
			minRange				= 16;
			minRangeProbab			= 0.1;
			midRange				= 100;
			midRangeProbab			= 0.5;
			maxRange				= 200;
			maxRangeProbab			= 0.2;
		};
		class short: close {
			aiBurstTerminable		= 1;
			showToPlayer			= 0;
			burst					= 1;
			burstRangeMax			= 5;
			aiRateOfFire			= 1;
			aiRateOfFireDispersion	= 2;
			aiRateOfFireDistance	= 150;
			minRange				= 100;
			minRangeProbab			= 0.5;
			midRange				= 250;
			midRangeProbab			= 0.69999999;
			maxRange				= 500;
			maxRangeProbab			= 0.75;
		};
		class medium: close {
			aiBurstTerminable		= 1;
			showToPlayer			= 0;
			burst					= 1;
			burstRangeMax			= 5;
			aiRateOfFire			= 2;
			aiRateOfFireDispersion	= 2;
			aiRateOfFireDistance	= 400;
			minRange				= 400;
			minRangeProbab			= 0.75;
			midRange				= 800;
			midRangeProbab			= 0.80000001;
			maxRange				= 1200;
			maxRangeProbab			= 0.75;
		};
		class far: close {
			aiBurstTerminable		= 1;
			showToPlayer			= 0;
			burst					= 1;
			burstRangeMax			= 3;
			aiRateOfFire			= 4;
			aiRateOfFireDispersion	= 4;
			aiRateOfFireDistance	= 1000;
			minRange				= 1000;
			minRangeProbab			= 0.76999998;
			midRange				= 1200;
			midRangeProbab			= 0.75;
			maxRange				= 1500;
			maxRangeProbab			= 0.1;
		};
		class GunParticles {
			class effect1 {
				positionName	= "usti hlavne";
				directionName	= "konec hlavne";
				effectName		= "GrenadeLauncherCloud";
			};
		};
	};
};
class Viewoptics;
class RCWSOptics;
class Turrets;
class MainTurret;
class Components;
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
		transportSoldier	= 1;						// Does not work proplerly. AI troops board the vehicle, but refuse to disembark when commanded to. Workaround: Command eject.
		class Viewoptics: ViewOptics {
			visionMode[]	= {"Normal", "NVG", "Ti"};
			thermalMode[]	= {4, 5};
		};
		class Reflectors {
			class Left {
				color[]			= {1900, 1800, 1700};
				ambient[]		= {5, 5, 5};
				position		= "Light_L";
				direction		= "Light_L_end";
				hitpoint		= "Light_L";
				selection		= "Light_L";
				size			= 1;
				innerAngle		= 100;
				outerAngle		= 179;
				coneFadeCoef	= 3;					// original value: 10
				intensity		= 2;
				useFlare		= 0;
				dayLight		= 0;
				flareSize		= 1;
				class Attenuation {
					start			= 1;
					constant		= 0;
					linear			= 0;
					quadratic		= 0.1;				// original value: 0.25
					hardLimitStart	= 60;				// original value: 30
					hardLimitEnd	= 120;				// original value: 60
				};
			};
			class Right: Left {
				position	= "Light_R";
				direction	= "Light_R_end";
				hitpoint	= "Light_R";
				selection	= "Light_R";
			};
			class Right2: Right {
				position	= "light_R_flare";
				useFlare	= 1;
			};
			class Left2: Left {
				position	= "light_L_flare";
				useFlare	= 1;
			};
			class Left3: Left2 {
				position	= "light_L_flare2";
				flareSize	= 0.30000001;
			};
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
				armor 	= 2;				// original value: 0.5
				name	= "wheel_1_1";
			};
			class HitLF2Wheel: HitLF2Wheel {
				armor 	= 2;				// original value: 0.5
				name	= "wheel_1_2";
			};
			class HitLMWheel: HitLMWheel {
				armor 	= 2;				// original value: 0.5
				name	= "wheel_1_3";
			};
			class HitRFWheel: HitRFWheel {
				armor 	= 2;				// original value: 0.5
				name	= "wheel_2_1";
			};
			class HitRF2Wheel: HitRF2Wheel {
				armor 	= 2;				// original value: 0.5
				name	= "wheel_2_2";
			};
			class HitRMWheel: HitRMWheel {
				armor 	= 2;				// original value: 0.5
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
					class MineDetectorDisplay {
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
					class MineDetectorDisplay {
						componentType	= "MineDetectorDisplayComponent";
					};
				};
			};
		};
		class Turrets: Turrets {
			class MainTurret: MainTurret {
				startEngine					= "false";
				weapons[]					= {
					"HMG_127_UGV_SNIPER",
					"GMG_40mm_SNIPER",
					"Laserdesignator_vehicle"
				};
				class ViewOptics: RCWSOptics {
					visionMode[] 		= {"Normal", "NVG", "TI"};
					initFov 			= 0.4667;
					maxFov 				= 0.4667;
					minFov 				= 0.005;			// raised zoom level
					directionStabilized = 1;
					thermalMode[] 		= {5, 6};
				};
				magazines[]					= {
					"500Rnd_127x99_mag_Tracer_Red",
					"500Rnd_127x99_mag_Tracer_Red",
					"200Rnd_40mm_G_belt",
					"Laserbatteries"
				};
				minElev						= -20;
				maxElev						= 70;
				discreteDistance[]			= {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000, 2100, 2200, 2300, 2400, 2500};
				discreteDistanceInitIndex 	= 3;
				aggregateReflectors[] 		= {"Light_1"};
				stabilizedInAxes			= 3;
				maxHorizontalRotSpeed		= 3.0; 		// Float - the maximum horizontal speed of the turret: maxHorizontalRotSpeed/8 = X; X = time in seconds to turn 360°
				maxVerticalRotSpeed			= 3.0; 		// Float - the maximum vertical speed of the turret, unit unknown. Bigger value - bigger rotation speed
				class Reflectors {
					class Light_1 {
						color[] 			= {10000, 10000, 9500};
						ambient[] 			= {500, 500, 450};
						intensity 			= 2;
						size 				= 1;
						innerAngle			= 5;
						outerAngle 			= 35;
						coneFadeCoef 		= 12;
						position 			= "PiP1_pos";
						direction 			= "PiP1_dir";
						hitpoint 			= "HitHull";
						selection 			= "Light_1";
						useFlare 			= 1;
						flareSize 			= 20;
						flareMaxDistance 	= 1000;
						dayLight 			= 1;
						class Attenuation {
							start 			= 0;
							constant 		= 0;
							linear			= 0;
							quadratic		= 0.005;
							hardLimitStart 	= 500;
							hardLimitEnd 	= 600;
						};
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
							class MineDetectorDisplay {
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
							class MineDetectorDisplay {
								componentType	= "MineDetectorDisplayComponent";
							};
						};
					};
				};
			};
		};
	};
};