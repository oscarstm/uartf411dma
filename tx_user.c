/*
 * tx_user.c
 *
 *  Created on: Dec 6, 2025
 *      Author: oscar
 */

#include "tx_user.h"

int tx_done = 1;

void dma2_stream7_setup(uint32_t src, uint32_t len) {
	USART1->SR &= ~USART_SR_TC; // clear TC flag
	DMA2_Stream7->CR &= ~DMA_SxCR_EN;

	while (DMA2_Stream7->CR & DMA_SxCR_EN) {
		//
	}

	DMA2_Stream7->PAR = (uint32_t) &(USART1->DR);
	DMA2_Stream7->M0AR = src;
	DMA2_Stream7->NDTR = len;

	// channel 4
	DMA2_Stream7->CR &= ~DMA_SxCR_CHSEL_0;
	DMA2_Stream7->CR &= ~DMA_SxCR_CHSEL_1;
	DMA2_Stream7->CR |= DMA_SxCR_CHSEL_2;

	DMA2_Stream7->CR |= DMA_SxCR_MINC;

	DMA2_Stream7->CR |= DMA_SxCR_TCIE;

	// memory to peripheral
	DMA2_Stream7->CR |= DMA_SxCR_DIR_0;
	DMA2_Stream7->CR &= ~DMA_SxCR_DIR_1;

	DMA2_Stream7->CR |= DMA_SxCR_EN;
}

void dma2_stream7_IRQHandler(void) {
	if ((DMA2->HISR) & DMA_HISR_TCIF7) {
		tx_done = 1;
		// clear the flag
		DMA2->HIFCR |= DMA_HIFCR_CTCIF7;

	}
}

