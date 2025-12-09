/*
 * rx_user.h
 *
 *  Created on: Dec 8, 2025
 *      Author: oscar
 */

#ifndef RX_USER_H_
#define RX_USER_H_

#include "stm32f4xx.h"
#include "usart_user.h"

#define UART_DATA_BUFFER_SIZE 150

void dma2_stream2_rx_setup(void);

#endif /* RX_USER_H_ */
