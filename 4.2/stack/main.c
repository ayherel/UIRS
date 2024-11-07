#include "stm32f10x.h"

#define STACK_SIZE 256
uint32_t stack[STACK_SIZE];
uint32_t* stack_pointer;

void delay (int r){
	int i, j;
	for (i=0; i<r; i++) {
		for (j=0; j<40000; j++);
	}
}

void stack_init() {
	stack_pointer = &stack[STACK_SIZE - 1];
}

void push(uint32_t value) {
	*stack_pointer = value;
	stack_pointer--;
}

uint32_t pop() {
	stack_pointer++;
	return *stack_pointer;
}

int main() {
	int i;
	RCC->APB2ENR |= (1<<2);
	GPIOA->CRL |= (0x33333333<<0);
	stack_init();
	push(10);
	push(20);
	uint32_t value1 = pop();
	uint32_t value2 = pop();
	
	if (value1 == 20 && value2 == 10) {
		while (1) {
			for(i=0; i<8; i++) {
				GPIOA->ODR = (1<<i);
				delay(200);
			}
		}
	}
}
