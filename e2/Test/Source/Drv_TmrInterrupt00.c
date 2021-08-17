/***********************************************************************/
/*                                                                     */
/*  FILE        :Drv_TmrInterrupt00.c                                  */
/*  DATE        :05/02/2014                                            */
/*  DESCRIPTION :Configure timers and define functions & interrupts    */
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
    Includes
*****************************************************************************/
#include "RAM.h"
#include "Drv_TmrInterrupt00.h"

#pragma interrupt INTER_TickTmr(vect = INTTM00)

/*****************************************************************************
 Name:          
 Parameters:    
 Returns:       
 Called by:     
 Calls:         
 Description:   
******************************************************************************/
void SR_ConfigTmrInterrupt00(void)
{
  /* Mask channel 0 interrupt */
  TMMK00 = 1U;    /* disable INTTM00 interrupt */
  TMIF00 = 0U;    /* clear INTTM00 interrupt flag */

  /* TMR00 Set INTTM00 high priority */
  TMPR100 = 0U;
  TMPR000 = 0U;
  
  /* Channel 0 used as interval timer */
  TMR00 = 0b0000000000000000;
          /*||||||||||||||||_ MDmn0. 0 Timer interrupt is not generated when counting is started
            |||||||||||||||   (timer output does not change, either).
            |||||||||||||||__ MDmn1:3. Interval timer mode. Interval timer / Square wave output / Divider function / PWM output (master)
            ||||||||||||_____ N/A (00)
            ||||||||||_______ CISmn. 00 Falling edge
            ||||||||_________ STSmn. 000 Only software trigger start is valid (other trigger sources are unselected)
            |||||____________ N/A (0)
            ||||_____________ CCSmn. 0 Operation clock (fMCK) specified by the CKSmn0 and CKSmn1 bits 
            |||______________ N/A (0)
            ||_______________ CKSmn. 00 Operation clock CKm0 set by timer clock select register m (TPSm)
          */

  TDR00 = C_TMR_INTERRUPT_REGISTER;  /* When the count value reaches 0000H, an interrupt signal (INTTMmn) is generated.
                         The countdown is started at 15999 (0x3E7F)
                   */
                   
  TOE0 = 0x0000U; // Disable TO
  
  // Set TO00 as output
  PM0 = PM0 & 0b11111101;
  TOM0 = 0x0000U; // Master channel output mode (to produce toggle output by timer interrupt request signal (INTTMmn))
  TO0 = TO0 | 0x0001; // Enable TO00
  TOE0 = TOE0 | 0x0001; // Enable TO00
}

/*****************************************************************************
 Name:          SR_EnableTmrInterrupt00
 Parameters:    None
 Returns:       none
 Called by:     InitMCU.c -> SR_EnableHardware
 Calls:         None
 Description:   enables timer 00 interrupt
******************************************************************************/
void SR_EnableTmrInterrupt00(void)
{
    TMIF00 = 0U;    /* clear INTTM00 interrupt flag */
    TMMK00 = 0U;    /* enable INTTM00 interrupt */
    TS0 = TS0 | 0x0001; // Enables TS00
}

/*****************************************************************************
 Name:          INTER_tmr_b
 Parameters:    None
 Returns:       bf_50msCompleted = True
 Called by:     None (interrupt)
 Calls:         LineVoltage -> SR_IncreaseLineVoltageTimerCnt
 Description:   Timer B Interrupt
                Set an interrupt at 500us.
                bf_MainTickCompleted is True every 100 counts
******************************************************************************/
void INTER_TickTmr(void)
{
  u16TmrCnt++;
  if(u16TmrCnt >= C_MAIN_TICK_CNT)
    {
      u16TmrCnt = 0;    // Set the bf_MainTickCompleted flag when reached the
      bf_MainTickCompleted = C_TRUE;  // main tick defines by C_MAIN_TICK_CNT
    }
      
    u16TmrCnt1++;
    if(u16TmrCnt1 >= C_GEA_TICK_CNT)
    {
      u16TmrCnt1 = 0;    // Set the bf_GEATickCompleted flag when reached the
      bf_GEATickCompleted = C_TRUE;  // GEA tick defines by C_GEA_TICK_CNT
    //  P_S2 = 1; //prueba 
    }
}