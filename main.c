#include "stm32f10x.h"

void delay (int r)
{
  int i, j;
  for (i=0; i<r; i++){
    for (j=0; j<4000; j++);
  }
}

int main(void)
{
  int i;
  RCC->APB2ENR |= (1<<2);
  
  GPIOA->CRL |= (0x33333333<<0);
  
  int a, b, sum, diff, mul, div;
	a = 6;
	b = 3;
	sum = a + b;
	diff = a - b;
	mul = a * b;
	div = a / b;
	
	
  if (sum == 9 && diff == 3 & mul == 18 && div == 2)
	{
		while (1){
			for (i=0; i<8;i++)
			{
				GPIOA->ODR=(1<<i);
				delay (200);
			}
		}
	}
  
}