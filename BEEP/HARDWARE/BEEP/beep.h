#ifndef  __BEEP_H
#define __BEEP_H

#include "sys.h"


#define BEEP  PFout(8)
#define LED 	PFout(9)

void BEEP_Init(void);



#endif 
