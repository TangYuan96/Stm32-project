#ifndef __KEY_H

#define __KEY_H

#include "sys.h"

#define KEY0 		PEin(4)
#define KEY1 		PEin(3)
#define KEY2 		PEin(2)
#define KEY_UP  PAin(0)

void KEY_Init(void);
u8 key_scan(void);

#endif
