/*
 * tx_user.h
 *
 *  Created on: Dec 6, 2025
 *      Author: oscar
 */

#ifndef TX_USER_H_
#define TX_USER_H_

#include "stm32f4xx.h"
#include "dma_usart.h"
#include "usart_user.h"

void dma2_stream7_setup(uint32_t src, uint32_t len);

#endif /* TX_USER_H_ */
