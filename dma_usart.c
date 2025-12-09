/*
 * dma_usart.c
 *
 *  Created on: Dec 4, 2025
 *      Author: oscar
 */

#include "dma_usart.h"



void dma2_init(void) {
	RCC->AHB1ENR |= RCC_AHB1ENR_DMA2EN;

	DMA2->HIFCR |= DMA_HIFCR_CFEIF7;
	DMA2->HIFCR |= DMA_HIFCR_CDMEIF7;
	DMA2->HIFCR |= DMA_HIFCR_CTEIF7;
	DMA2->HIFCR |= DMA_HIFCR_CHTIF7;
	DMA2->HIFCR |= DMA_HIFCR_CTCIF7;

	NVIC_EnableIRQ(DMA2_Stream7_IRQn);
}

