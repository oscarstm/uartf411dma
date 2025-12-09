/*
 * rx_user.c
 *
 *  Created on: Dec 8, 2025
 *      Author: oscar
 */

#include "rx_user.h"

char uart_data_buffer[UART_DATA_BUFFER_SIZE];
int rx_done = 1;

void dma2_stream2_rx_setup(void) {
	DMA2_Stream2->CR &= ~DMA_SxCR_EN;

	while (DMA2_Stream2->CR & DMA_SxCR_EN) {
		//
	}
	DMA2->LIFCR |= DMA_LIFCR_CFEIF2;
	DMA2->LIFCR |= DMA_LIFCR_CDMEIF2;
	DMA2->LIFCR |= DMA_LIFCR_CTEIF2;
	DMA2->LIFCR |= DMA_LIFCR_CHTIF2;
	DMA2->LIFCR |= DMA_LIFCR_CTCIF2;

	DMA2_Stream2->PAR = (uint32_t) (&(USART1->DR));
	DMA2_Stream2->M0AR = (uint32_t) &uart_data_buffer;
	DMA2_Stream2->NDTR = (uint16_t) UART_DATA_BUFFER_SIZE;

	// channel 4
	DMA2_Stream2->CR &= ~DMA_SxCR_CHSEL_0;
	DMA2_Stream2->CR &= ~DMA_SxCR_CHSEL_1;
	DMA2_Stream2->CR |= DMA_SxCR_CHSEL_2;

	DMA2_Stream2->CR |= DMA_SxCR_MINC;

	DMA2_Stream2->CR |= DMA_SxCR_TCIE;

	DMA2_Stream2->CR |= DMA_SxCR_CIRC;

	// peripheral to memory
	DMA2_Stream2->CR &= ~DMA_SxCR_DIR_0;
	DMA2_Stream2->CR &= ~DMA_SxCR_DIR_1;

	DMA2_Stream2->CR |= DMA_SxCR_EN;

	NVIC_EnableIRQ(DMA2_Stream2_IRQn);
}

void dma2_stream2_IRQHandler(void) {
	if ((DMA2->LISR) & DMA_LISR_TCIF2) {
		rx_done = 1;
		// clear the flag
		DMA2->LIFCR |= DMA_LIFCR_CTCIF2;

	}
}
