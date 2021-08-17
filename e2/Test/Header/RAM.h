/***********************************************************************/
/*                                                                     */
/*  FILE        :Ram.h                                                 */
/*  DATE        :31/01/2014                                            */
/*  DESCRIPTION :Ram Definitions & Initialization                      */
/*  CPU TYPE    :RL78G13                                               */
/*  AUTHOR      :Carlos Humberto Reyes Andres                          */
/*                                                                     */
/*  PROJECT     : Hidra washer machine Control                         */
/*                                                                     */
/*  Copyright 2014 Mabe TyP                                            */
/*  All rights reserved                                                */
/*                                                                     */
/***********************************************************************/

/*****************************************************************************
    Pragma directive
******************************************************************************/
#define DI    __DI
#define EI    __EI
#define NOP   __NOP
#define HALT  __HALT
#define STOP  __STOP

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/

#include "iodefine.h"
#include "GlobalDefine.h"

extern EMainProcessState EMainProcessSt;

extern U8 u8FCTSt;
extern U8 u8FCTTestComplete;
extern U8 u8DeviceRqstID;
extern U8 u8PlayBuzzerTest;
extern U8 u8CycleTemp;
extern U8 u8LastCycleTemp;
extern U8 u8KnobFilterCnt;
extern U8 u8AltTestSt;
extern U8 u8TestSt;
extern U8 u8Cycle;
extern U8 au8BufferTx[C_COMM_FRAME_SIZE];
extern U8 au8BufferRx[C_COMM_FRAME_SIZE];
extern U8 u8TxByteCnt;
extern U8 u8RxByteCnt;
extern U8 u8CommandTx;
extern U8 u8CommandRx;
extern U8 u8CommLevel;
extern U8 u8TestEquipmentDisconnectedCnt;
extern U8 u8TxRxID;
extern U8 u8PersonalizeTimeElapsed;
extern U8 u8FrameReceivedStatus;
extern U8 u8EnableSlaveTx;
extern U8 u8RxFrameReceived;
extern U8 u8TECmdRx;
extern U8 u8FCTData1;
extern U8 u8ConfirmRamSaved;
extern U8 u8UserInterfaceType;
extern U8 u8CycleSelectorADC;
extern U8 u8BuzzerTone;
extern U8 u8Model;
extern U8 u8MuxCnt;
extern U8  u8Tune;
extern U8  u8MusicPtr;
extern U8 u8ReleaseBtn;
extern U8 u8BuzzerTickCnt;
extern U8 u8CommTimeout;

extern U16 u16TestTickCnt;
extern U16 u16AltTestTimeCnt;
extern U16 u16TmrCnt;
extern U16 u16TmrCnt1;  //variable tick gea
extern U16 u16SecondsElapsed;
extern volatile U16  u16BuzzerCnt;
extern U16  u16VolumeIncrease;
extern U16  u16SoundVolume;
extern U16  u16SustainVolume;
extern U16  u16PeakVolume;
extern U16 u16Tone;
extern EBuzzerSt eBuzzerST;
extern const struct SBuzzerParam* pS_BuzzerParam;

extern struct stFilterBtnParameters stFilterBtnData1;
extern struct stFilterBtnParameters stFilterBtnData2;

extern volatile union Ubyte_def u8MainTickVar;
#define    bf_MainTickCompleted u8MainTickVar.Ubit.b0


extern volatile union Ubyte_def u8GEATickVar;  //variable tick gea
#define    bf_GEATickCompleted u8GEATickVar.Ubit.b0


extern volatile union Ubyte_def u_BtnPressedData1;
#define u8BtnPressedData1  u_BtnPressedData1.Ubyte
#define bf_Btn_0          u_BtnPressedData1.Ubit.b0
#define bf_Btn_1          u_BtnPressedData1.Ubit.b1
#define bf_Btn_2          u_BtnPressedData1.Ubit.b2
#define bf_Btn_3          u_BtnPressedData1.Ubit.b3
#define bf_Btn_4          u_BtnPressedData1.Ubit.b4
#define bf_Btn_5          u_BtnPressedData1.Ubit.b5
#define bf_Btn_6          u_BtnPressedData1.Ubit.b6
#define bf_Btn_7          u_BtnPressedData1.Ubit.b7

extern volatile union Ubyte_def u_BtnFilteredData1;
#define u8BtnFilteredData1  u_BtnFilteredData1.Ubyte
#define bf_Btn_0_Filtered      u_BtnFilteredData1.Ubit.b0
#define bf_Btn_1_Filtered      u_BtnFilteredData1.Ubit.b1
#define bf_Btn_2_Filtered      u_BtnFilteredData1.Ubit.b2
#define bf_Btn_3_Filtered      u_BtnFilteredData1.Ubit.b3
#define bf_Btn_4_Filtered      u_BtnFilteredData1.Ubit.b4
#define bf_Btn_5_Filtered      u_BtnFilteredData1.Ubit.b5
#define bf_Btn_6_Filtered      u_BtnFilteredData1.Ubit.b6
#define bf_Btn_7_Filtered      u_BtnFilteredData1.Ubit.b7

extern volatile union Ubyte_def u_BtnPressedData2;
#define u8BtnPressedData2  u_BtnPressedData2.Ubyte
#define bf_Btn_8          u_BtnPressedData2.Ubit.b0
#define bf_Btn_9          u_BtnPressedData2.Ubit.b1
#define bf_Btn_10         u_BtnPressedData2.Ubit.b2
#define bf_Btn_11         u_BtnPressedData2.Ubit.b3
#define bf_Btn_12         u_BtnPressedData2.Ubit.b4
#define bf_Btn_13         u_BtnPressedData2.Ubit.b5
#define bf_Btn_14         u_BtnPressedData2.Ubit.b6
#define bf_Btn_15         u_BtnPressedData2.Ubit.b7

extern volatile union Ubyte_def u_BtnFilteredData2;
#define u8BtnFilteredData2  u_BtnFilteredData2.Ubyte
#define bf_Btn_8_Filtered      u_BtnFilteredData2.Ubit.b0
#define bf_Btn_9_Filtered      u_BtnFilteredData2.Ubit.b1
#define bf_Btn_10_Filtered     u_BtnFilteredData2.Ubit.b2
#define bf_Btn_11_Filtered     u_BtnFilteredData2.Ubit.b3
#define bf_Btn_12_Filtered     u_BtnFilteredData2.Ubit.b4
#define bf_Btn_13_Filtered     u_BtnFilteredData2.Ubit.b5
#define bf_Btn_14_Filtered     u_BtnFilteredData2.Ubit.b6
#define bf_Btn_15_Filtered     u_BtnFilteredData2.Ubit.b7

extern volatile union Ubyte_def u_BtnPressedData3;
#define u8BtnPressedData3  u_BtnPressedData3.Ubyte
#define bf_Btn_16         u_BtnPressedData3.Ubit.b0
#define bf_Btn_17         u_BtnPressedData3.Ubit.b1
#define bf_Btn_18         u_BtnPressedData3.Ubit.b2
#define bf_Btn_19         u_BtnPressedData3.Ubit.b3
#define bf_Btn_20         u_BtnPressedData3.Ubit.b4
#define bf_Btn_21         u_BtnPressedData3.Ubit.b5
#define bf_Btn_22         u_BtnPressedData3.Ubit.b6
#define bf_Btn_23         u_BtnPressedData3.Ubit.b7

extern volatile union Ubyte_def u_BtnPressedData4;
#define u8BtnPressedData4  u_BtnPressedData4.Ubyte
#define bf_Btn_24         u_BtnPressedData4.Ubit.b0
#define bf_Btn_25         u_BtnPressedData4.Ubit.b1
#define bf_Btn_26         u_BtnPressedData4.Ubit.b2
#define bf_Btn_27         u_BtnPressedData4.Ubit.b3
#define bf_Btn_28         u_BtnPressedData4.Ubit.b4
#define bf_Btn_29         u_BtnPressedData4.Ubit.b5
#define bf_Btn_30         u_BtnPressedData4.Ubit.b6
#define bf_Btn_31         u_BtnPressedData4.Ubit.b7

extern volatile union Ubyte_def u_BtnPressedData5;
#define u8BtnPressedData5  u_BtnPressedData5.Ubyte
#define bf_Btn_32         u_BtnPressedData5.Ubit.b0
#define bf_Btn_33         u_BtnPressedData5.Ubit.b1
#define bf_Btn_34         u_BtnPressedData5.Ubit.b2
#define bf_Btn_35         u_BtnPressedData5.Ubit.b3
#define bf_Btn_36         u_BtnPressedData5.Ubit.b4
#define bf_Btn_37         u_BtnPressedData5.Ubit.b5
#define bf_Btn_38         u_BtnPressedData5.Ubit.b6
#define bf_Btn_39         u_BtnPressedData5.Ubit.b7

extern volatile union Ubyte_def u8TxDisplayRqstData6;
#define u8BtnCoded        u8TxDisplayRqstData6.Ubyte

extern volatile union Ubyte_def u8TxDisplayRqstData11;
#define u8TxDispRqstData11  u8TxDisplayRqstData11.Ubyte
#define bf_EncoderLeft    u8TxDisplayRqstData11.Ubit.b6
#define bf_EncoderRight   u8TxDisplayRqstData11.Ubit.b5

extern volatile union Ubyte_def uRxDisplayRqst1Data1;
#define u8RxDisplayRqst1Data1 uRxDisplayRqst1Data1.Ubyte
#define bf_Led_0              uRxDisplayRqst1Data1.Ubit.b0
#define bf_Led_1              uRxDisplayRqst1Data1.Ubit.b1
#define bf_Led_2              uRxDisplayRqst1Data1.Ubit.b2
#define bf_Led_3              uRxDisplayRqst1Data1.Ubit.b3
#define bf_Led_4              uRxDisplayRqst1Data1.Ubit.b4
#define bf_Led_5              uRxDisplayRqst1Data1.Ubit.b5
#define bf_Led_6              uRxDisplayRqst1Data1.Ubit.b6
#define bf_Led_7              uRxDisplayRqst1Data1.Ubit.b7

extern volatile union Ubyte_def uRxDisplayRqst1Data2;
#define u8RxDisplayRqst1Data2 uRxDisplayRqst1Data2.Ubyte
#define bf_Led_8              uRxDisplayRqst1Data2.Ubit.b0
#define bf_Led_9              uRxDisplayRqst1Data2.Ubit.b1
#define bf_Led_10             uRxDisplayRqst1Data2.Ubit.b2
#define bf_Led_11             uRxDisplayRqst1Data2.Ubit.b3
#define bf_Led_12             uRxDisplayRqst1Data2.Ubit.b4
#define bf_Led_13             uRxDisplayRqst1Data2.Ubit.b5
#define bf_Led_14             uRxDisplayRqst1Data2.Ubit.b6
#define bf_Led_15             uRxDisplayRqst1Data2.Ubit.b7

extern volatile union Ubyte_def uRxDisplayRqst1Data3;
#define u8RxDisplayRqst1Data3 uRxDisplayRqst1Data3.Ubyte
#define bf_Led_16             uRxDisplayRqst1Data3.Ubit.b0
#define bf_Led_17             uRxDisplayRqst1Data3.Ubit.b1
#define bf_Led_18             uRxDisplayRqst1Data3.Ubit.b2
#define bf_Led_19             uRxDisplayRqst1Data3.Ubit.b3
#define bf_Led_20             uRxDisplayRqst1Data3.Ubit.b4
#define bf_Led_21             uRxDisplayRqst1Data3.Ubit.b5
#define bf_Led_22             uRxDisplayRqst1Data3.Ubit.b6
#define bf_Led_23             uRxDisplayRqst1Data3.Ubit.b7

extern volatile union Ubyte_def uRxDisplayRqst1Data4;
#define u8RxDisplayRqst1Data4 uRxDisplayRqst1Data4.Ubyte
#define bf_Led_24             uRxDisplayRqst1Data4.Ubit.b0
#define bf_Led_25             uRxDisplayRqst1Data4.Ubit.b1
#define bf_Led_26             uRxDisplayRqst1Data4.Ubit.b2
#define bf_Led_27             uRxDisplayRqst1Data4.Ubit.b3
#define bf_Led_28             uRxDisplayRqst1Data4.Ubit.b4
#define bf_Led_29             uRxDisplayRqst1Data4.Ubit.b5
#define bf_Led_30             uRxDisplayRqst1Data4.Ubit.b6
#define bf_Led_31             uRxDisplayRqst1Data4.Ubit.b7

extern volatile union Ubyte_def uRxDisplayRqst1Data5;
#define u8RxDisplayRqst1Data5 uRxDisplayRqst1Data5.Ubyte
#define bf_Led_32             uRxDisplayRqst1Data5.Ubit.b0
#define bf_Led_33             uRxDisplayRqst1Data5.Ubit.b1
#define bf_Led_34             uRxDisplayRqst1Data5.Ubit.b2
#define bf_Led_35             uRxDisplayRqst1Data5.Ubit.b3
#define bf_Led_36             uRxDisplayRqst1Data5.Ubit.b4
#define bf_Led_37             uRxDisplayRqst1Data5.Ubit.b5
#define bf_Led_38             uRxDisplayRqst1Data5.Ubit.b6
#define bf_Led_39             uRxDisplayRqst1Data5.Ubit.b7

extern volatile union Ubyte_def uRxDisplayRqst1Data6;
#define u8RxDisplayRqst1Data6 uRxDisplayRqst1Data6.Ubyte
#define u8WaterLevel          uRxDisplayRqst1Data6.nu4byte.MSNibble
#define u8SoilLevel           uRxDisplayRqst1Data6.nu4byte.LSNibble

extern volatile union Ubyte_def uRxDisplayRqst1Data7;
#define u8RxDisplayRqst1Data7 uRxDisplayRqst1Data7.Ubyte
#define u8TemperatureLevel    uRxDisplayRqst1Data7.nu4byte.MSNibble
#define u8SpinLevel           uRxDisplayRqst1Data7.nu4byte.LSNibble

extern volatile union Ubyte_def uRxDisplayRqst1Data8;
#define u8RxDisplayRqst1Data8 uRxDisplayRqst1Data8.Ubyte
#define u8EcoLevel            uRxDisplayRqst1Data8.nu4byte.MSNibble
#define bf_Led_Manuals_Spin   uRxDisplayRqst1Data8.Ubit.b0
#define bf_Led_Manuals_Rinse  uRxDisplayRqst1Data8.Ubit.b1
#define bf_Led_Manuals_Wash   uRxDisplayRqst1Data8.Ubit.b2
#define bf_Led_Manuals_Soak   uRxDisplayRqst1Data8.Ubit.b3

extern volatile union Ubyte_def uRxDisplayRqst1Data9;
#define u8RxDisplayRqst1Data9 uRxDisplayRqst1Data9.Ubyte
#define bf_Led_LidLock        uRxDisplayRqst1Data9.Ubit.b7

extern volatile union Ubyte_def uRxDisplayRqst1Data10;
#define u8RxDisplayRqst1Data10 uRxDisplayRqst1Data10.Ubyte

extern volatile union Ubyte_def uRxDisplayRqst1Data11;
#define u8RxDisplayRqst1Data11 uRxDisplayRqst1Data11.Ubyte

extern volatile union Ubyte_def uRxDisplayRqst2Data1;
#define u8RxDisplayRqst2Data1 uRxDisplayRqst2Data1.Ubyte
#define u8MillarCoded         uRxDisplayRqst2Data1.Ubyte

extern volatile union Ubyte_def uRxDisplayRqst2Data2;
#define u8RxDisplayRqst2Data2 uRxDisplayRqst1Data2.Ubyte
#define u8HundredsCoded       uRxDisplayRqst1Data2.Ubyte

extern volatile union Ubyte_def uRxDisplayRqst2Data3;
#define u8RxDisplayRqst2Data3 uRxDisplayRqst2Data3.Ubyte
#define u8TeensCoded          uRxDisplayRqst2Data3.Ubyte

extern volatile union Ubyte_def uRxDisplayRqst2Data4;
#define u8RxDisplayRqst2Data4 uRxDisplayRqst1Data4.Ubyte
#define u8UnitsCoded          uRxDisplayRqst1Data4.Ubyte

extern volatile union Ubyte_def uRxDisplayRqst2Data5;
#define u8RxDisplayRqst2Data5 uRxDisplayRqst2Data5.Ubyte
#define u8TimeMillarCoded     uRxDisplayRqst2Data5.Ubyte

extern volatile union Ubyte_def uRxDisplayRqst2Data6;
#define u8RxDisplayRqst2Data6 uRxDisplayRqst1Data6.Ubyte
#define u8TimeHundredsCoded   uRxDisplayRqst1Data6.Ubyte

extern volatile union Ubyte_def uRxDisplayRqst2Data7;
#define u8RxDisplayRqst2Data7 uRxDisplayRqst2Data7.Ubyte
#define u8TimeTeensCoded      uRxDisplayRqst2Data7.Ubyte

extern volatile union Ubyte_def uRxDisplayRqst2Data8;
#define u8RxDisplayRqst2Data8 uRxDisplayRqst1Data8.Ubyte
#define u8TimeUnitsCoded      uRxDisplayRqst1Data8.Ubyte

extern volatile union Ubyte_def uTeens;
#define u8Teens           uTeens.Ubyte
#define bf_Teens_Seg_A    uTeens.Ubit.b0
#define bf_Teens_Seg_B    uTeens.Ubit.b1
#define bf_Teens_Seg_C    uTeens.Ubit.b2
#define bf_Teens_Seg_D    uTeens.Ubit.b3
#define bf_Teens_Seg_E    uTeens.Ubit.b4
#define bf_Teens_Seg_F    uTeens.Ubit.b5
#define bf_Teens_Seg_G    uTeens.Ubit.b6
#define bf_Teens_Seg_Dot  uTeens.Ubit.b7

extern volatile union Ubyte_def uUnits;
#define u8Units           uUnits.Ubyte
#define bf_Units_Seg_A    uUnits.Ubit.b0
#define bf_Units_Seg_B    uUnits.Ubit.b1
#define bf_Units_Seg_C    uUnits.Ubit.b2
#define bf_Units_Seg_D    uUnits.Ubit.b3
#define bf_Units_Seg_E    uUnits.Ubit.b4
#define bf_Units_Seg_F    uUnits.Ubit.b5
#define bf_Units_Seg_G    uUnits.Ubit.b6
#define bf_Units_Seg_Dot  uUnits.Ubit.b7

extern void SR_InitRam(void);