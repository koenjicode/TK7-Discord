// Created with ReClass.NET 1.2 by KN4CK3R

#pragma once
#include <Windows.h>
#include <cstdint>
#include <string>
#include <vector>

namespace T7
{
	struct Translation
	{
		float x;
		float y;
		float z;
		float unknown;
	};

	struct Euler4
	{
		float x;
		float y;
		float z;
		float unknown;
	};

	struct Vector
	{
		float x;
		float y;
		float z;
	};

	struct Vector4
	{
		float x;
		float y;
		float z;
		float w;
	};

	union TranslationOrEuler
	{
	public:
		Translation Translation;
		Euler4 Euler4;
	};

	struct Plane
	{
		float X;
		float Y;
		float Z;
		float W;
	};

	/* 706 */
	struct Matrix
	{
		Plane XPlane;
		Plane YPlane;
		Plane ZPlane;
		Plane WPlane;
	};

	// Created with ReClass.NET 1.2 by KN4CK3R

	enum class ThrowTech : int32_t
	{
		None = 0,
		TE1 = 1,
		TE2 = 2,
		TE1_2 = 3
	};

	enum class SimpleMoveState : int32_t
	{
		UNINITIALIZED = 0,
		STANDING_FORWARD = 1,
		STANDING_BACK = 2,
		STANDING = 3,
		STEVE = 4,
		CROUCH_FORWARD = 5,
		CROUCH_BACK = 6,
		CROUCH = 7,
		OFF_AXIS_GETUP = 8,
		UNKNOWN_TYPE_9 = 9,
		UNKNOWN_10 = 10,
		UNKNOWN_GETUP_11 = 11,
		GROUND_FACEUP = 12,
		GROUND_FACEDOWN = 13,
		JUGGLED = 14,
		KNOCKDOWN = 15,
		WALL_SPLAT_18 = 18,
		WALL_SPLAT_19 = 19,
		TECH_ROLL_OR_FLOOR_BREAK = 20,
		UNKNOWN_23 = 23,
		AIRBORNE_24 = 24,
		AIRBORNE = 25,
		AIRBORNE_26 = 26,
		FLY = 27
	};

	enum class HitOutcome : int32_t
	{
		NONE = 0,
		BLOCKED_STANDING = 1,
		BLOCKED_CROUCHING = 2,
		JUGGLE = 3,
		SCREW = 4,
		UNKNOWN_SCREW_5 = 5,
		UNKNOWN_6 = 6,
		UNKNOWN_SCREW_7 = 7,
		GROUNDED_FACE_DOWN = 8,
		GROUNDED_FACE_UP = 9,
		COUNTER_HIT_STANDING = 10,
		COUNTER_HIT_CROUCHING = 11,
		NORMAL_HIT_STANDING = 12,
		NORMAL_HIT_CROUCHING = 13,
		NORMAL_HIT_STANDING_LEFT = 14,
		NORMAL_HIT_CROUCHING_LEFT = 15,
		NORMAL_HIT_STANDING_BACK = 16,
		NORMAL_HIT_CROUCHING_BACK = 17,
		NORMAL_HIT_STANDING_RIGHT = 18,
		NORMAL_HIT_CROUCHING_RIGHT = 19
	};

	enum class AttackHeightType : int32_t
	{
		NotAttack = 0,
		LOW = 1,
		MID = 2,
		PROJ = 3,
		SMID = 4,
		HIGH = 5,
		UNKNOWN_6 = 6,
		MID_UNBLOCKABLE = 7,
		HIGH_UNBLOCKABLE = 8,
		LOW_UNBLOCKABLE = 9,
		THROW = 10,
		ANTIAIR_ONLY = 11
	};

	enum class InputDirection : int32_t
	{
		UNINITIALIZED = 0,
		db = 2,
		d = 4,
		df = 8,
		b = 16,
		n = 32,
		f = 64,
		ub = 128,
		u = 256,
		uf = 512
	};

	enum class InputAttack : int32_t
	{
		N = 0,
		_1 = 512,
		_2 = 1024,
		_1_2 = 1536,
		_3 = 2048,
		_1_3 = 2560,
		_2_3 = 3072,
		_1_2_3 = 3584,
		_4 = 4096,
		_1_4 = 4608,
		_2_4 = 5120,
		_1_2_4 = 5632,
		_3_4 = 6144,
		_1_3_4 = 6656,
		_2_3_4 = 7168,
		_1_2_3_4 = 7680,
		RAGE = 8192
	};

	enum class StunState : int32_t
	{
		None = 0,
		Unknown = 1,
		Block = 2,
		GettingHit = 3,
		DoingTheHitting = 4,
		BeingPunished = 5,
		BlockNoHit = 6
	};

	enum class ComplexMoveState : int32_t
	{
		F_MINUS = 0,
		S_PLUS = 1,
		S = 2,
		A = 3,
		UN04 = 4,
		C_MINUS = 5,
		A_PLUS = 6,
		C = 7,
		END1 = 10,
		BLOCK = 11,
		WALK = 12,
		SIDEROLL_GETUP = 13,
		SIDEROLL_STAYDOWN = 14,
		SS = 15,
		RECOVERING = 16,
		UN17 = 17,
		UN18 = 18,
		UN20 = 20,
		UN22 = 22,
		UN23 = 23,
		SW = 28,
		UNKN = 999999
	};

	enum class VideoModeType : int32_t
	{
		Fullscreen = 0,
		Borderless = 1,
		Windowed = 2
	};
	class SideIndex {
	public:
		enum Enum {
			Left = 0,
			Right = 1
		};
	private:
		SideIndex() = default;
	};


	class HitPoint
	{
	public:
		Vector position; //0x0000
		float sequenceId; //0x000C
	}; //Size: 0x0010
	static_assert(sizeof(HitPoint) == 0x10);

	class HurtCylinder
	{
	public:
		Vector position; //0x0000
		float sizeModifier; //0x000C
		float height; //0x0010
		char pad_0014[4]; //0x0014
		float radius; //0x0018
		char pad_001C[4]; //0x001C
	}; //Size: 0x0020
	static_assert(sizeof(HurtCylinder) == 0x20);

	class CollisionSphere
	{
	public:
		Vector position; //0x0000
		float sizeModifier; //0x000C
		float radius; //0x0010
		char pad_0014[12]; //0x0014
	}; //Size: 0x0020
	static_assert(sizeof(CollisionSphere) == 0x20);

	struct PlayerDefaultStances {
		enum Enum {
			Standing = 1,
			Ducking = 2,
			DefaultStance = 0x8000
		};
	};

	class TekkenPlayer
	{
	public:
		char pad_0000[24]; //0x0000
		int8_t someFlag; //0x0018
		char pad_0019[187]; //0x0019
		int32_t currentPlayerNumber; //0x00D4
		int32_t characterId; //0x00D8
		int32_t characterId2; //0x00DC
		float positionX; //0x00E0
		char pad_00E4[4]; //0x00E4
		float positionY; //0x00E8
		char pad_00EC[68]; //0x00EC
		Matrix playerPositionMatrix; //0x0130
		char pad_0170[64]; //0x0170
		float floorZ; //0x01B0
		char pad_01B4[10]; //0x01B4
		int16_t rotation; //0x01BE
		char pad_01C0[20]; //0x01C0
		int32_t currentMoveFrame; //0x01D4
		char pad_01D8[12]; //0x01D8
		int32_t currentMoveFrame2; //0x01E4
		char pad_01E8[8]; //0x01E8
		int32_t currentMoveFrame3; //0x01F0
		char pad_01F4[8]; //0x01F4
		float currentMoveFrameFloat; //0x01FC
		char pad_0200[24]; //0x0200
		class Move* pCurrentMove; //0x0218
		class Move* pCurrentMove2; //0x0220
		class Move* pPreviousMove; //0x0228
		char pad_0230[240]; //0x0230
		int32_t opponentComboCounter; //0x0320
		int32_t attackDamage; //0x0324
		int32_t attackType; //0x0328
		int32_t encryptionKey; //0x032C
		char pad_0330[32]; //0x0330
		int32_t moveId; //0x0350
		char pad_0354[60]; //0x0354
		int32_t playerCanMove; //0x0390
		char pad_0394[8]; //0x0394
		int32_t totalFrames; //0x039C
		char pad_03A0[56]; //0x03A0
		HitOutcome hitOutcome; //0x03D8
		char pad_03DC[76]; //0x03DC
		SimpleMoveState simpleMoveState; //0x0428
		int32_t stunType; //0x042C
		char pad_0430[32]; //0x0430
		int32_t throwTech; //0x0450
		char pad_0454[20]; //0x0454
		int32_t throwFlag; //0x0468
		char pad_046C[4]; //0x046C
		union //0x0470
		{
			int32_t complexMoveStateInt32; //0x0000
			ComplexMoveState complexMoveState; //0x0000
		};
		char pad_0474[588]; //0x0474
		int32_t powerCrush; //0x06C0
		char pad_06C4[136]; //0x06C4
		float distance2; //0x074C
		char pad_0750[4]; //0x0750
		int32_t jumpFlags; //0x0754
		char pad_0758[48]; //0x0758
		uint32_t cancelFlags; //0x0788
		char pad_078C[20]; //0x078C
		int32_t damageTakenLastHit; //0x07A0
		char pad_07A4[408]; //0x07A4
		int32_t opponentDamageTakenTotal; //0x093C
		char pad_0940[304]; //0x0940
		int32_t gameStateNumber; //0x0A70
		char pad_0A74[396]; //0x0A74
		int32_t rageFlag; //0x0C00
		char pad_0C04[412]; //0x0C04
		class Move* pNextMove; //0x0DA0
		char pad_0DA8[8]; //0x0DA8
		int32_t moveFrameToSwitchOn; //0x0DB0
		int32_t nextMoveFlags; //0x0DB4
		int32_t nextMoveFrameToSwitchTo; //0x0DB8
		int32_t nextMoveID; //0x0DBC
		char pad_0DC0[28]; //0x0DC0
		int32_t inputAttack; //0x0DDC
		int32_t inputDirection; //0x0DE0
		char pad_0DE4[104]; //0x0DE4
		int32_t N0000021B; //0x0E4C
		char pad_0E50[4]; //0x0E50
		class HitPoint hitPoints[12]; //0x0E54
		class HurtCylinder hurtCylinders[14]; //0x0F14
		class CollisionSphere collisionSpheres[9]; //0x10D4
		char pad_11F4[604]; //0x11F4
		float distance; //0x1450
		char pad_1454[116]; //0x1454
		int32_t someAnimationFlag; //0x14C8
		int32_t isRightSide; //0x14CC
		char pad_14D0[24]; //0x14D0
		int32_t healthEncrypted; //0x14E8
		char pad_14EC[4]; //0x14EC
		int64_t healthEncryptionKey; //0x14F0
		char pad_14F8[40]; //0x14F8
		class MovesetHeader* pMotbin; //0x1520
		char pad_1528[32]; //0x1528
		class TekkenPlayer* pOpponentPlayer; //0x1548
		char pad_1550[1292]; //0x1550
		int32_t inputAttack2; //0x1A5C
		InputDirection inputDirection2; //0x1A60
		char pad_1A64[7180]; //0x1A64

		bool IsPlayerStanding() {
			bool IsDefaultStance = moveId & PlayerDefaultStances::DefaultStance;
			if(!IsDefaultStance)
				return false;
			auto MoveIndex = moveId ^ PlayerDefaultStances::DefaultStance;
			return MoveIndex == PlayerDefaultStances::Standing;
		}

		bool CanMove() {
			return playerCanMove;
		}
	}; //Size: 0x3670
	static_assert(sizeof(TekkenPlayer) == 0x3670);

	class VideoMode
	{
	public:
		int32_t Width; //0x0000
		int32_t Height; //0x0004
		int32_t Bit; //0x0008
		int32_t RefreshRate; //0x000C
	}; //Size: 0x0010
	static_assert(sizeof(VideoMode) == 0x10);

	class UnknownClassWithVideoMode
	{
	public:
		char pad_0000[1780]; //0x0000
		VideoMode Width; //0x06F4
		char pad_0704[2452]; //0x0704
	}; //Size: 0x1098
	static_assert(sizeof(UnknownClassWithVideoMode) == 0x1098);

	class PingSample
	{
	public:
		int32_t SampleNumber; //0x0000
		char pad_0004[4]; //0x0004
		int32_t LatencyMs; //0x0008
	}; //Size: 0x000C
	static_assert(sizeof(PingSample) == 0xC);

	class PingContainer
	{
	public:
		char pad_0000[340]; //0x0000
		int32_t averagePing; //0x0154
		char pad_0158[56]; //0x0158
		class PingSample pingSamples[16][1]; //0x0190
		char pad_0250[1644]; //0x0250
	}; //Size: 0x08BC
	static_assert(sizeof(PingContainer) == 0x8BC);

	class Move
	{
	public:
		char* pName; //0x0000
		char* pAnimationName; //0x0008
		int64_t pAnimation; //0x0010
		uint32_t vulnerabilityBitMask; //0x0018
		uint32_t hitLevel; //0x001C
		class Cancel* pCancelList; //0x0020
		char pad_0028[8]; //0x0028
		uint64_t u2; //0x0030
		uint64_t u3; //0x0038
		uint64_t u4; //0x0040
		char pad_0048[8]; //0x0048
		uint32_t u6; //0x0050
		uint16_t transitionMoveID; //0x0054
		uint16_t u7; //0x0056
		uint16_t u8; //0x0058
		uint16_t u8_2; //0x005A
		uint16_t u9; //0x005C
		char pad_005E[2]; //0x005E
		class HitCondition* pHitConditionList; //0x0060
		int32_t animationMaxLength; //0x0068
		uint32_t floatableStart; //0x006C
		uint32_t floatableEnd; //0x0070
		uint32_t u12; //0x0074
		class Voiceclip* pVoiceclip; //0x0078
		class ExtraMoveProperty* pExtraPropertiesList; //0x0080
		char pad_0088[16]; //0x0088
		uint32_t u15; //0x0098
		int32_t hitboxIndex; //0x009C
		int32_t hitboxStartFrame; //0x00A0
		int32_t hitboxEndFrame; //0x00A4
		uint16_t u16; //0x00A8
		uint16_t u17; //0x00AA
		uint32_t u18; //0x00AC
	}; //Size: 0x00B0
	static_assert(sizeof(Move) == 0xB0);

	class AnimationHeader0xC8
	{
	public:
		uint8_t AnimationSignatureByte1; //0x0000
		uint8_t unusedAlignment; //0x0001
		uint16_t AnimationVectorsPerFrame; //0x0002
		uint32_t AnimationLength; //0x0004
		uint32_t DeviationDescriptorMask; //0x0008
		uint32_t JumpStrengthDescriptorMask; //0x000C
		uint32_t UnknownDescriptorMask; //0x0010
		uint32_t MeshDescriptorMask; //0x0014
		uint32_t UpperBodyDescriptorMask; //0x0018
		uint32_t LowerBodyDescriptorMask; //0x001C
		uint32_t SpineFlexureDescriptorMask; //0x0020
		uint32_t NeckDescriptorMask; //0x0024
		uint32_t HeadDescriptorMask; //0x0028
		uint32_t RightInnerShoulderDescriptorMask; //0x002C
		uint32_t RightOuterShoulderDescriptorMask; //0x0030
		uint32_t RightElbowDescriptorMask; //0x0034
		uint32_t RightHandDescriptorMask; //0x0038
		uint32_t LeftInnerShoulderDescriptorMask; //0x003C
		uint32_t LeftOuterShoulderDescriptorMask; //0x0040
		uint32_t LeftElbowDescriptorMask; //0x0044
		uint32_t LeftHandDescriptorMask; //0x0048
		uint32_t RightHipDescriptorMask; //0x004C
		uint32_t RightKneeDescriptorMask; //0x0050
		uint32_t RightFootDescriptorMask; //0x0054
		uint32_t LeftHipDescriptorMask; //0x0058
		uint32_t LeftKneeDescriptorMask; //0x005C
		uint32_t LeftFootDescriptorMask; //0x0060
	}; //Size: 0x0064
	static_assert(sizeof(AnimationHeader0xC8) == 0x64);

	class FrameHistoryContainer
	{
	public:
		char pad_0000[8]; //0x0000
		class PointerToFrameHistory* ppFrameHistory; //0x0008
		int32_t LastWrittenArrayIndex; //0x0010
		char pad_0014[172]; //0x0014
	}; //Size: 0x00C0
	static_assert(sizeof(FrameHistoryContainer) == 0xC0);


	class RotatorsToBonesMatricesConverter
	{
	public:
		int32_t* VTable; //0x0000
		char pad_0008[8]; //0x0008
		Vector4 N0000D6AA; //0x0010
		Vector4 N0000D6DB; //0x0020
		Vector4 N0000D6AB; //0x0030
		Vector4 N0000D6DD; //0x0040
		Vector4 N0000D6AC; //0x0050
		Vector4 N0000D6DF; //0x0060
		Vector4 N0000D6AD; //0x0070
		Vector4 N0000D6E1; //0x0080
		Vector4 N0000D6AE; //0x0090
		Vector4 N0000D6E3; //0x00A0
		Vector4 N0000D6AF; //0x00B0
		Vector4 N0000D6E5; //0x00C0
		Vector4 N0000D6B0; //0x00D0
		Vector4 N0000D6E7; //0x00E0
		Vector4 N0000D6B1; //0x00F0
		Vector4 N0000D6E9; //0x0100
		Vector4 N0000D6B2; //0x0110
		Vector4 N0000D6EB; //0x0120
		Vector4 N0000D6B3; //0x0130
		Vector4 N0000D6ED; //0x0140
		Vector4 N0000D6B4; //0x0150
		Vector4 N0000D6EF; //0x0160
		Vector4 N0000D6B5; //0x0170
		Vector4 N0000D6F1; //0x0180
		Vector4 N0000D849; //0x0190
		Vector4 N0000D84A; //0x01A0
		Vector4 N0000D84B; //0x01B0
		Vector4 N0000D84C; //0x01C0
		Vector4 N0000D84D; //0x01D0
		Vector4 N0000D84E; //0x01E0
		Vector4 N0000D84F; //0x01F0
		Vector4 N0000D850; //0x0200
		Vector4 N0000D851; //0x0210
		Vector4 N0000D852; //0x0220
		Vector4 N0000D853; //0x0230
		Vector4 N0000D854; //0x0240
		Vector4 N0000D855; //0x0250
		Vector4 N0000D856; //0x0260
		Vector4 N0000D857; //0x0270
		Vector4 N0000D858; //0x0280
		Vector4 N0000D859; //0x0290
		Vector4 N0000D85A; //0x02A0
		Vector4 N0000D85B; //0x02B0
		Vector4 N0000D85C; //0x02C0
		Vector4 N0000D85D; //0x02D0
		Vector4 N0000D85E; //0x02E0
		Vector4 N0000D85F; //0x02F0
		Vector4 N0000D860; //0x0300
		Vector4 N0000D861; //0x0310
		Vector4 N0000D862; //0x0320
		Vector4 N0000D863; //0x0330
		Vector4 N0000D864; //0x0340
		Vector4 N0000D865; //0x0350
		Vector4 N0000D866; //0x0360
		Vector4 N0000D867; //0x0370
		Vector4 N0000D868; //0x0380
		Vector4 N0000D869; //0x0390
		Vector4 N0000D86A; //0x03A0
		Vector4 N0000D86B; //0x03B0
		Vector4 N0000D86C; //0x03C0
		Vector4 N0000D86D; //0x03D0
		Vector4 N0000D86E; //0x03E0
		Vector4 N0000D86F; //0x03F0
		Vector4 N0000D870; //0x0400
		Vector4 N0000D871; //0x0410
		Vector4 N0000D872; //0x0420
		Vector4 N0000D873; //0x0430
		Vector4 N0000D874; //0x0440
		Vector4 N0000D875; //0x0450
		Vector4 N0000D876; //0x0460
		Vector4 N0000D877; //0x0470
		Vector4 N0000D878; //0x0480
		Vector4 N0000D879; //0x0490
		Vector4 N0000D87A; //0x04A0
		Vector4 N0000D87B; //0x04B0
		Vector4 N0000D87C; //0x04C0
		Vector4 N0000D87D; //0x04D0
		Vector4 N0000D87E; //0x04E0
		Vector4 N0000D87F; //0x04F0
		Vector4 N0000D880; //0x0500
		Vector4 N0000D881; //0x0510
		Vector4 N0000D882; //0x0520
		Vector4 N0000D883; //0x0530
		Vector4 N0000D884; //0x0540
		Vector4 N0000D885; //0x0550
		Vector4 N0000D886; //0x0560
		Vector4 N0000D887; //0x0570
		Vector4 N0000D888; //0x0580
		Vector4 N0000D889; //0x0590
		Vector4 N0000D88A; //0x05A0
		Vector4 N0000D88B; //0x05B0
		Vector4 N0000D88C; //0x05C0
		Vector4 N0000D88D; //0x05D0
		Vector4 N0000D88E; //0x05E0
		Vector4 N0000D88F; //0x05F0
		Vector4 N0000D890; //0x0600
		Vector4 N0000D891; //0x0610
		Vector4 N0000D892; //0x0620
		Vector4 N0000D893; //0x0630
		Vector4 N0000D894; //0x0640
		char pad_0650[464]; //0x0650
		int64_t N0000D7AE; //0x0820
		char pad_0828[15608]; //0x0828
		int32_t playerNumber; //0x4520
		char pad_4524[5004]; //0x4524
	}; //Size: 0x58B0
	static_assert(sizeof(RotatorsToBonesMatricesConverter) == 0x58B0);

	/* 707 */
	struct BoneWithMatrices
	{
		Matrix matrix1;
		Matrix matrix2;
		char gap80[8];
		__int16 boneIndex;
		__int16 parentBoneIndex;
		BoneWithMatrices* pAnotherBoneWithMatrices;
		int field_98_someFlag;
		char gap9C[3];
		char field_9F;
	};

	struct CurrentAnimationFrameWithBoneMatrices
	{
		BYTE gap0[24];
		__int64 field_18;
		BYTE gap20[8];
		BoneWithMatrices* pBonesWithMatrices;
		BYTE gap30[932];
		char flag_field_isValid;
		char flag_field_3D5;
		char field_3D6;
		char field_3D7;
		void* field_3D8_somePointer;
	};

	struct __declspec(align(4)) AnimationManager
	{
		BYTE gap0[16];
		TranslationOrEuler BonesTranslationsOrEulersArray[23];
		BYTE gap180[1696];
		CurrentAnimationFrameWithBoneMatrices currentAnimationFrameWithBoneMatrices;
		BYTE gapC00[14624];
		int myPlayerNumber;
		BYTE gap4524[5003];
		char field_58AF;
	};

	class UnknownClassThatPlayerClassWritesTo
	{
	public:
		char pad_0000[112]; //0x0000
		float N0000E42A; //0x0070
		char pad_0074[156]; //0x0074
		int32_t N0000E43E; //0x0110
		char pad_0114[156]; //0x0114
		int32_t N0000E452; //0x01B0
		char pad_01B4[156]; //0x01B4
		int32_t N0000E466; //0x0250
		char pad_0254[156]; //0x0254
		int32_t N0000E47A; //0x02F0
		char pad_02F4[156]; //0x02F4
		int32_t N0000E48E; //0x0390
		char pad_0394[156]; //0x0394
		int32_t N0000E4A2; //0x0430
		char pad_0434[156]; //0x0434
		int32_t N0000E4B6; //0x04D0
		char pad_04D4[44]; //0x04D4
	}; //Size: 0x0500
	static_assert(sizeof(UnknownClassThatPlayerClassWritesTo) == 0x500);

	class RepeatActionManagerGlobal
	{
	public:
		struct RepeatFlags {
			enum Enum : unsigned __int32 {
				SecondRepeatAction = 1 << 17,
				RepeatActionActivated = 1 << 25 // 25th bit
			};
		private:
			RepeatFlags() = default;
		};

		struct RecordPlayingFlags
		{
			enum Enum {
				NotPlaying = 0x0,
				Playing = 0x3,
			};
		};

		RepeatFlags::Enum RepeatFlags; //0x0000
		char pad_0004[4]; //0x0004
		int64_t N000116A3; //0x0008
		char pad_0010[100]; //0x0010
		int32_t RepeatCountdownTimer; //0x0074
		char pad_0078[12]; //0x0078
		RecordPlayingFlags::Enum RecordPlayingFlags; //0x0084
		char pad_0088[14]; //0x0088
		int8_t SomeByteIndicator; //0x0096
		char pad_0097[384]; //0x0097

		bool IsRepeatActionActivated() {
			return RepeatFlags & RepeatFlags::RepeatActionActivated;
		}

		void ActivateRepeatAction() {
			RepeatFlags = static_cast<RepeatFlags::Enum>(RepeatFlags | RepeatFlags::RepeatActionActivated);
		}

		void DeactivateRepeatAction() {
			RepeatFlags = static_cast<RepeatFlags::Enum>(RepeatFlags & (~RepeatFlags::RepeatActionActivated));
		}

		bool IsRecordActionPlaying() {
			return RecordPlayingFlags == RecordPlayingFlags::Playing;
		}

		bool IsDuringSecondCPUAction() {
			return RepeatFlags & RepeatFlags::SecondRepeatAction;
		}

		void SetRecordActionPlaying() {
			RecordPlayingFlags = RecordPlayingFlags::Playing;
		}
	}; //Size: 0x0217
	static_assert(sizeof(RepeatActionManagerGlobal) == 0x218);

	struct PlayerInput
	{
		enum PlayerInputEnum
		{
			None = 0,
			Up = 1 << 0,
			Down = 1 << 1,
			Back = 1 << 2,
			Forward = 1 << 3,
			_1 = 1 << 14,
			_2 = 1 << 15,
			_3 = 1 << 12,
			_4 = 1 << 13,
		};
	};

	// Created with ReClass.NET 1.2 by KN4CK3R

	class OpponentInformation
	{
	public:
		int16_t N0000E45C; //0x0000
		char pad_0002[2]; //0x0002
		int32_t Bars; //0x0004
		int32_t N0000E45D; //0x0008
		char pad_000C[4]; //0x000C
		char Nickname[32]; //0x0010
		int32_t N0000E471; //0x0030
		int32_t N0000E45F; //0x0034
		int32_t CharacterID; //0x0038
		int32_t Rank; //0x003C
		int32_t N0000E475; //0x0040
		int32_t N0000E461; //0x0044
		int32_t N0000E477; //0x0048
		int32_t N0000E462; //0x004C
		int32_t N0000E479; //0x0050
		int32_t Ping; //0x0054
		int32_t Wifi; //0x0058
		char pad_005C[4]; //0x005C
	}; //Size: 0x0060
	static_assert(sizeof(OpponentInformation) == 0x60);


	class OpponentInformationContainer
	{
	public:
		OpponentInformation* pStartCopyOpponentInformationTo; //0x0000
		OpponentInformation* pEndCopyOpponentInformationTo; //0x0008
	}; //Size: 0x0010
	static_assert(sizeof(OpponentInformationContainer) == 0x10);

	enum DirectionInput : __int8
	{
		Up = 1 << 4,
		Forward = 1 << 5,
		Down = 1 << 6,
		Back = 1 << 7,
	};

	enum AttackInput : __int8
	{
		_1 = 1 << 7,
		_2 = 1 << 4,
		_3 = 1 << 6,
		_4 = 1 << 5,
	};

	struct RepeatMoveInput
	{
		DirectionInput DirectionInput;
		AttackInput AttackInput;
		unsigned char PlayForNumberOfFrames;
		char field_3;

		bool IsNeutralInput() {
			return DirectionInput == 0 && AttackInput == 0;
		}
	};

	struct RepeatMovelistPlayableMove
	{
		__int8 gap0[2];
		__int16 Distance;
		__int16 OpponentRotation;
		__int8 gap6[8];
		__int16 InputSequenceSize;
		unsigned int InputSequenceOffset;
		bool NeedsRage;
		__int8 gap15[10];
		char field_1F;

		RepeatMoveInput* GetInputSequenceStart() {
			return reinterpret_cast<RepeatMoveInput*>(reinterpret_cast<char*>(this) + InputSequenceOffset);
		}
	};

	struct RepeatMovelistDisplayableMove
	{
		struct MoveCategoryOrPastEndOfMovelist {
			enum Enum : __int16
			{
				MoveCategory = 0x8,
				PastEndOfMovelist = 0xA,
			};
		};

		char gap0[4];
		int MoveNameOffset;
		char gap8[12];
		int DisplayableInputsEncodedOffset;
		char gap18[44];
		__int16 PlayableMovelistMoveID;
		__int16 field_46;
		MoveCategoryOrPastEndOfMovelist::Enum IsMoveCategoryOrPastEndShowableMoveList;
		__int16 IsSelectableInMovelist;
		char gap4C[295];
		char field_173;


		const char* GetDisplayableEncodedInputs() {
			const char* DisplayableEncodedInputs = reinterpret_cast<const char*>(this) + DisplayableInputsEncodedOffset;

			return DisplayableEncodedInputs;
		}

		const char* GetName() {
			const char* InGameName = reinterpret_cast<const char*>(this) + MoveNameOffset;

			return InGameName;
		}

		bool IsSelectable() {
			return IsSelectableInMovelist;
		}

		bool IsNormalMove() {
			return !IsMoveCategory() && !IsPastEndOfMovelist();
		}

		bool IsMoveCategory() {
			return IsMoveCategoryOrPastEndShowableMoveList == MoveCategoryOrPastEndOfMovelist::MoveCategory;
		}

		bool IsPastEndOfMovelist() {
			return IsMoveCategoryOrPastEndShowableMoveList == MoveCategoryOrPastEndOfMovelist::PastEndOfMovelist;
		}
	};

	class RepeatMovelistHead
	{
	public:
		char pad_0000[12]; //0x0000
		int32_t PlayableMoveListSize; //0x000C
		char pad_0010[8]; //0x0010
		int32_t PlayableMovesOffset; //0x0018
		char pad_001C[36]; //0x001C
	}; //Size: 0x0040
	static_assert(sizeof(RepeatMovelistHead) == 0x40);

	struct RepeatActionManagerPlayer
	{
		struct CurrentlyPlayingFlags {
			enum Enum {
				NotPlaying = 1,
				Playing = 0xD
			};
		private:
			CurrentlyPlayingFlags() = default;
		};

		CurrentlyPlayingFlags::Enum CurrentlyPlayingFlags;
		T7::TekkenPlayer* MyTekkenPlayer;
		int DisplayableMovesListSize;
		RepeatMovelistDisplayableMove* RepeatMovelistDisplayableMovesPtr;
		RepeatMovelistHead* RepeatMovelistPtr;
		char gap28[16];
		int CurrentlyRepeatingMoveID;
		char gap3C[4];
		int RepeatMoveIDs[5];

		__declspec(align(16)) RepeatMoveInput* InputSequencePointerEnd;
		RepeatMoveInput* InputSequencePointerCurrent;
		int CurrentInputFrameNumber;
		int CurrentInputPlayedForNumberOfFrames;
		char StartingPlaying;
		char gap79[6];
		char field_7F;

		void SetCurrentlyPlaying() {
			CurrentlyPlayingFlags = CurrentlyPlayingFlags::Enum::Playing;
		}

		bool IsCurrentlyPlaying() {
			return CurrentlyPlayingFlags == CurrentlyPlayingFlags::Enum::Playing;
		}

		//RepeatMovelistPlayableMove* GetPlayableMoveFromDisplayableMove(const RepeatMovelistDisplayableMove& RepeatMoveListDisplayableMove) {
		//	return GetPlayableMoveByID(RepeatMoveListDisplayableMove.PlayableMovelistMoveID);
		//}
	};

	static_assert(offsetof(RepeatActionManagerPlayer, field_7F) == 0x7F);

	// Created with ReClass.NET 1.2 by KN4CK3R

	class RepeatAction
	{
	public:
		int32_t RepeatActionType; //0x0000
		int32_t Probability; //0x0004
	}; //Size: 0x0008
	static_assert(sizeof(RepeatAction) == 0x8);

	class PracticeModeManager
	{
	public:
		struct OpponentActionsMode {
			enum Enum : int
			{
				CPUAction12 = 0,
				CPU = 1,
				RepeatAction = 2
			};
		};

		OpponentActionsMode::Enum OpponentActionsMode; //0x0000
		char pad_0004[20]; //0x0004
		int32_t SelectedRepeatCountdownTimerIndex; //0x0018
		char pad_001C[80]; //0x001C
		SideIndex::Enum SelectedSide; //0x006C
		char pad_0070[3]; //0x0070
		int8_t N0000E648; //0x0073
		RepeatAction RepeatActions[5]; //0x0074
		RepeatAction RepeatActions2[5]; //0x009C
		char pad_00C4[96]; //0x00C4

		void SetOpponentMode_CPUAction12() {
			OpponentActionsMode = OpponentActionsMode::CPUAction12;
		}

		void SetOpponentMode_CPU() {
			OpponentActionsMode = OpponentActionsMode::CPU;
		}

		void SetOpponentMode_RepeatAction() {
			OpponentActionsMode = OpponentActionsMode::RepeatAction;
		}

		bool IsAnyOfRepeatActionsCanBePlayed() {
			for(auto& [RepeatActionType, Probability] : RepeatActions) {
				if(RepeatActionType != 0 && Probability != 0)
					return true;
			}

			return false;
		}

		std::vector<std::pair<int, RepeatAction>> GetEnabledRepeatingActions() {
			std::vector<std::pair<int, RepeatAction>> EnabledRepeatingActions{};
			for(int Index = 0; Index < std::size(RepeatActions); ++Index) {
				auto& CurrentRepeatAction = RepeatActions[Index];
				if(CurrentRepeatAction.RepeatActionType != 0 && CurrentRepeatAction.Probability != 0)
					EnabledRepeatingActions.emplace_back(Index, CurrentRepeatAction);
			}

			return EnabledRepeatingActions;
		}
	}; //Size: 0x0100
	static_assert(sizeof(PracticeModeManager) == 0x124);

	struct RecordActionDirectionInput {
		enum Enum : unsigned char {
			Neutral = 0x0,
			Up = 1,
			Down = 1 << 1,
			Left = 1 << 2,
			Right = 1 << 3,
			Select = 1 << 4,
			IsDirectionalInputInverted = 1 << 5
		};
	};

	struct RecordActionAttackInput {
		enum Enum : unsigned char {
			No = 0,
			_1 = 1 << 6,
			_2 = 1 << 7,
			_3 = 1 << 4,
			_4 = 1 << 5
		};
	};

	class RepeatActionRecordInput
	{
	public:
		RecordActionDirectionInput::Enum Direction; //0x0000
		RecordActionAttackInput::Enum Attack; //0x0001
		uint8_t Unknown; //0x0002
		uint8_t PlayForNumberOfFrames; //0x0003
	}; //Size: 0x0004
	static_assert(sizeof(RepeatActionRecordInput) == 0x4);

	class RepeatActionRecord
	{
	public:
		uint16_t NumberOfFramesInRecording; //0x0000
		RepeatActionRecordInput Inputs[1800]; //0x0002
	}; //Size: 0x1C22
	static_assert(sizeof(RepeatActionRecord) == 0x1C22);

	class RepeatActionRecord2Records
	{
	public:
		RepeatActionRecord RepeatActionPlayerRecords[2]; //0x0000
	}; //Size: 0x3844
	static_assert(sizeof(RepeatActionRecord2Records) == 0x3844);

	class RepeatActionRecordContainer
	{
	public:
		RepeatActionRecord2Records* RepeatActionRecords; //0x0000
	}; //Size: 0x11954
	static_assert(sizeof(RepeatActionRecordContainer) == 8);

	class CharacterStatsStruct
	{
	public:
		int32_t CharacterID; //0x0000
		uint32_t OfflineRank; //0x0004
		uint32_t OfflineRank2; //0x0008
		uint32_t OfflinePoints; //0x000C
		int32_t N0000448F; //0x0010
		int32_t N000044E4; //0x0014
		int32_t N00004490; //0x0018
		int32_t N000044E6; //0x001C
		uint32_t OnlineRank; //0x0020
		uint32_t OnlineRank2; //0x0024
		uint32_t OnlinePoints; //0x0028
		int32_t N00004493; //0x002C
		int32_t N00004494; //0x0030
		int32_t N000044EC; //0x0034
		int32_t N00004495; //0x0038
		int32_t ArcadeBattlesWins; //0x003C
		int32_t ArcadeBattlesLosses; //0x0040
		int32_t ArcadeBattlesLosingStreak; //0x0044
		int32_t N00004496; //0x0048
		int32_t N00004497; //0x004C
		int32_t N00004498; //0x0050
		int32_t TreasureWins; //0x0054
		int32_t TreasureLoses; //0x0058
		int32_t TreasureBattlesLosingStreak; //0x005C
		int32_t N00004499; //0x0060
		int32_t N000044F8; //0x0064
		int32_t N0000449A; //0x0068
		int32_t RankedWins; //0x006C
		int32_t RankedLosses; //0x0070
		int32_t RankedMatchLosingStreak; //0x0074
		int32_t N0000449C; //0x0078
		int32_t RankedMatchWinningStreak; //0x007C
		int32_t N0000449D; //0x0080
		int32_t QuickMatchWins; //0x0084
		int32_t QuickMatchLoses; //0x0088
		int32_t QuickMatchLosingStreak; //0x008C
		int32_t N0000449F; //0x0090
		int32_t QuickMatchWinningStreak; //0x0094
		int32_t N000044A0; //0x0098
		int32_t PlayerMatchWins; //0x009C
		int32_t PlayerMatchLoses; //0x00A0
		int32_t PlayerMatchLosingStreak; //0x00A4
		int32_t N00004409; //0x00A8
		int32_t PlayerMatchWinningStreak; //0x00AC
		int32_t N000044A3; //0x00B0
		int32_t N0000450C; //0x00B4
		int32_t N000044A4; //0x00B8
		int32_t N0000450E; //0x00BC
		int32_t N000044A5; //0x00C0
		int32_t N00004510; //0x00C4
		int32_t N000044A6; //0x00C8
		int32_t N00004512; //0x00CC
		int32_t TournamentsWon; //0x00D0
		int32_t N00004514; //0x00D4
		int32_t SelectedCostume; //0x00D8
		int32_t N00004516; //0x00DC
		int32_t N000044A9; //0x00E0
		int32_t N00004518; //0x00E4
		int32_t N000044AA; //0x00E8
		int32_t N0000451A; //0x00EC
		int32_t N000044AB; //0x00F0
		int32_t N0000451C; //0x00F4
		int32_t N000044AC; //0x00F8
		int32_t N0000451E; //0x00FC
		int32_t N000044AD; //0x0100
		int32_t N00004520; //0x0104
		int32_t N000044AE; //0x0108
		int32_t N00004522; //0x010C
		int32_t N000044AF; //0x0110
		int32_t N00004524; //0x0114
		int32_t N000044B0; //0x0118
		int32_t N00004526; //0x011C
		int32_t N000044B1; //0x0120
		int32_t N00004528; //0x0124
		int32_t N000044B2; //0x0128
		int32_t N0000452A; //0x012C
		int32_t N000044B3; //0x0130
		int32_t N0000452C; //0x0134
		int32_t N000044B4; //0x0138
		int32_t N0000452E; //0x013C
		int32_t N000044B5; //0x0140
		int32_t N00004530; //0x0144
		int32_t N000044B6; //0x0148
		int32_t N00004532; //0x014C
		int32_t N000044B7; //0x0150
		int32_t N00004534; //0x0154
		int32_t N000044B8; //0x0158
		int32_t N00004536; //0x015C
		int32_t N000044B9; //0x0160
		int32_t N00004538; //0x0164
		int32_t N000044BA; //0x0168
		int32_t N0000453A; //0x016C
		int32_t N000044BB; //0x0170
		int32_t N0000453C; //0x0174
		int32_t N000044BC; //0x0178
		int32_t N0000453E; //0x017C
		int32_t N000044BD; //0x0180
		int32_t N00004540; //0x0184
		int32_t N000044BE; //0x0188
		int32_t N00004542; //0x018C
		int32_t N000044BF; //0x0190
		int32_t N00004544; //0x0194
		int32_t N000044C0; //0x0198
		int32_t N00004546; //0x019C
		int32_t N000044C1; //0x01A0
		int32_t N00004548; //0x01A4
		int32_t N000044C2; //0x01A8
		int32_t N0000454A; //0x01AC
		int32_t N000044C3; //0x01B0
		int32_t N0000454C; //0x01B4
		int32_t N000044C4; //0x01B8
		int32_t N0000454E; //0x01BC
		int32_t N000044C5; //0x01C0
		int32_t N00004550; //0x01C4
		int32_t N000044C6; //0x01C8
		int32_t N00004552; //0x01CC
		int32_t N000044C7; //0x01D0
		int32_t N00004554; //0x01D4
		int32_t N000044C8; //0x01D8
		int32_t N00004556; //0x01DC
		int32_t N000044C9; //0x01E0
		int32_t N00004558; //0x01E4
		int32_t N000044CA; //0x01E8
		int32_t N0000455A; //0x01EC
		int32_t N000044CB; //0x01F0
		int32_t N0000455C; //0x01F4
		int32_t N000044CC; //0x01F8
		int32_t N0000455E; //0x01FC
		int32_t N000044CD; //0x0200
		int32_t N00004560; //0x0204
		int32_t N000044CE; //0x0208
		int32_t N00004562; //0x020C
		int32_t N000044CF; //0x0210
		int32_t N00004564; //0x0214
		int32_t N000044D0; //0x0218
		int32_t N00004566; //0x021C
		int32_t N000044D1; //0x0220
		int32_t N00004568; //0x0224
		int32_t N000044D2; //0x0228
		int32_t N0000456A; //0x022C
		int32_t N000044D3; //0x0230
		int32_t N0000456C; //0x0234
		int32_t N000044D4; //0x0238
		int32_t N0000456E; //0x023C
		int32_t N000044D5; //0x0240
		int32_t N00004570; //0x0244
		int32_t N000044D6; //0x0248
		int32_t N00004572; //0x024C
		int32_t N000044D7; //0x0250
		int32_t N00004574; //0x0254
		int32_t N000044D8; //0x0258
		int32_t N00004576; //0x025C
		int32_t N000044D9; //0x0260
		int32_t N00004578; //0x0264
		int32_t N000044DA; //0x0268
		int32_t N0000457A; //0x026C
		int32_t N000044DB; //0x0270
		int32_t N0000457C; //0x0274
		int32_t N000044DC; //0x0278
		int32_t N0000457E; //0x027C
		int32_t N000044DD; //0x0280
		int32_t N00004580; //0x0284
		int32_t N000044DE; //0x0288
	}; //Size: 0x028C
	static_assert(sizeof(CharacterStatsStruct) == 0x28C);

	class CharacterSelect1
	{
	public:
		char pad_0000[1224]; //0x0000
		int32_t CostumeVisibleIndexSelection; //0x04C8
		int32_t CostumeIndex; //0x04CC
		char pad_04D0[4]; //0x04D0
		int32_t CustomCostumesSize; //0x04D4
		int32_t TotalCostumesSize; //0x04D8
		int32_t PresetCostumesSize; //0x04DC
		int32_t DefaultCostumesSize; //0x04E0
		char pad_04E4[36]; //0x04E4
		int32_t CharacterSelectSelectionCharacterID; //0x0508
		int32_t N000071A5; //0x050C
		int32_t N0000719C; //0x0510
		int32_t N000071A7; //0x0514
		int32_t N0000719D; //0x0518
		char pad_051C[1396]; //0x051C
	}; //Size: 0x0A90
	static_assert(sizeof(CharacterSelect1) == 0xA90);

	class CharacterSelect2
	{
	public:
		char pad_0000[16]; //0x0000
		int32_t SelectedCharacterID1; //0x0010
		char pad_0014[84]; //0x0014
		int32_t SelectedSide; //0x0068
		char pad_006C[36]; //0x006C
		int32_t EncryptedMoney; //0x0090
		char pad_0094[136]; //0x0094
		char PlayerNickname[32]; //0x011C
		char pad_013C[100]; //0x013C
		class CharacterStatsStruct CharacterStats[75]; //0x01A0
		int32_t SelectedCharacterID2; //0xC0A4
		int32_t SelectedCostumeID; //0xC0A8
		char pad_C0AC[16184]; //0xC0AC
	}; //Size: 0xFFE4
	static_assert(sizeof(CharacterSelect2) == 0xFFE4);
}
