#include <reg51.h>
sbit ledpin1 = P1^0;
sbit ledpin2 = P0^0;

void delay(){
	int i,j;
	for(i=0;i<100;i++){
		for(j=0;j<100;j++){
		}
	}
}

void main(){
	while(1){		
		ledpin2 = 0;
		ledpin1 = 1;
		delay();
		ledpin1 = 0;
		delay();
		ledpin1 = 1;
		delay();
		ledpin1 = 0;
		delay();
		ledpin1 = 1;
		delay();
		ledpin1 = 0;
		delay();
		ledpin2 = 1;
		delay();
		ledpin2 = 0;
		delay();
		ledpin2 = 1;
		delay();
		ledpin2 = 0;
		delay();
	}
}
