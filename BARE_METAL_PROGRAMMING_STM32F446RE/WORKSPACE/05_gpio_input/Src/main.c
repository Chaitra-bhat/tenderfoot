#include<stm32f4xx.h>

#define GPIOAENA			(1U<<0)
#define GPIOCENA			(1U<<2)

#define LED_PIN5		(1U<<5)
#define USER_BTN		(1U<<13)

#define GPIOA_BSRR_SET		(1U<<5)
#define GPIOA_BSRR_RESET	(1U<<21)

int main()
{
	RCC->AHB1ENR |= GPIOAENA;
	RCC->AHB1ENR |= GPIOCENA;

	GPIOA->MODER |= (1U<<10);
	GPIOA->MODER &= ~(1U<<11);

	GPIOC->MODER &= ~(1U<<26);
	GPIOC->MODER &= ~(1U<<27);

	while(1)
	{
		if((GPIOC->IDR && USER_BTN))
		{
			GPIOA->ODR |= (1<<5);
			for(int i=0;i<1000000;i++);
		}
	}

	return 0;
}
