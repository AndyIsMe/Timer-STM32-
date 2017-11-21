/*
 * DbgMcu.h
 *
 *  Created on: Nov 21, 2017
 *      Author: TARUC
 */

#ifndef DBGMCU_H_
#define DBGMCU_H_

#define DBGMCU_APB2_FZ		(*(uint32_t *)(0xE004200C))
#define DBG_TIM8_STOP		(1<<1)
#define haltTimerWhenDebugging()		(DBGMCU_APB2_FZ |= DBG_TIM8_STOP)
#endif /* DBGMCU_H_ */
