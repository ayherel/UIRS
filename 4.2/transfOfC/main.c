#include "stm32f10x.h"

void GPIO_Init (void){
	RCC->APB2ENR |= (RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPCEN);
	
	GPIOC->CRH &= ~(GPIO_CRH_MODE13 | GPIO_CRH_CNF13);
	GPIOC->CRH |= GPIO_CRH_CNF13_1;
	GPIOC->ODR |= GPIO_ODR_ODR13;
	
	GPIOA->CRL &= 0x00000000;
	GPIOA->CRL |= 0x33333333;
	
}

int main(void){
	GPIO_Init();
	
	while (1){
		if((GPIOC->IDR & GPIO_IDR_IDR13)){
			GPIOA->ODR |= 0xFF;
		}
		else{
			GPIOA->ODR |= 0x00;
		}
	}
}