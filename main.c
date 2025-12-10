#include <stdio.h>
#include <string.h>
#include "stm32f4xx.h"
#include "clk_user.h"
#include "usart_user.h"
#include "dma_usart.h"
#include "tx_user.h"
#include "rx_user.h"

extern int uart_done;
extern int tx_done;
extern int rx_done;

char c[] = "from STM32F411\r\n";
char message[sizeof(c)];
extern char uart_data_buffer[UART_DATA_BUFFER_SIZE];

int main(void) {
	clk_user_init();
	usart1_init();
	dma2_init();
	dma2_stream2_rx_setup();

	while (1) {

		int i;
		int size = strlen(c);

		for (i = 0; i < size; i++) {
			message[i] = c[i];
		}

		while (tx_done == 0) {
			//
		}
		tx_done = 0;

		dma2_stream7_setup((uint32_t) message, size);

	}

}

