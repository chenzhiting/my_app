
#include "io430.h"

void Delay(int iDelayCnt)
{
  int iCnt,iCount;
  for(iCount = 0; iCount < iDelayCnt; iCount++)
  {
    for(iCnt = 0; iCnt < 4000; iCnt++);
  }
}

int main( void )
{
  
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  
  P1DIR |= BIT1;// P1.1 output        // 设置p1.1为输出模式
    P1OUT |= BIT1;//P1.1 = 1 / LED ON   // 高电平有效，打开led灯
    
  while(1)
  {
    P1OUT |= BIT1;//P1.1 = 1 / LED ON
    Delay(10);
    P1OUT &= (~BIT1);//P1.1 = 0 / LED off
    Delay(10);
  }

    
  return 0;
}
