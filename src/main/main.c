#include "mcu_support_package/inc/stm32f4xx.h"
#include <stdlib.h>
#include "stm32f4xx.h"


int main(void)
{

}










#ifdef USE_FULL_ASSERT

// эта функция вызывается, если assert_param обнаружил ошибку
void assert_failed(uint8_t * file, uint32_t line)
{ 
	/* User can add his own implementation to report the file name and line number,
	 ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
	 
	(void)file;
	(void)line;

	__disable_irq();
	while(1)
	{
			// это ассемблерная инструкция "отладчик, стой тут"
			// если вы попали сюда, значит вы ошиблись в параметрах вызова функции из SPL. 
			// Смотрите в call stack, чтобы найти ее
			__BKPT(0xAB);
	}
}

#endif
