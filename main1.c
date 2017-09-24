#include <msp430g2553.h>

#define t1 BIT0
#define e1 BIT1
#define c BIT2
#define h BIT3
#define n BIT4
#define i BIT5
#define t2 BIT0
#define e2 BIT1
#define s BIT2

void turnalloff();
void turnallon();
void spanout();
void closein();
void TtoS();
void pat1();
void pat2();
void pat3();

/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	P1DIR |= t1+e1+c+h+n+i;
	P2DIR |= t2+e2+s;
	BCSCTL1 = CALBC1_1MHZ; // Set DCO
	DCOCTL = CALDCO_1MHZ;
	P1OUT= t1+e1+c+h+n+i;
	P2OUT=t2+e2+s;

    while(1)

    {
    	//pat2();

    	//TtoS();
///*
    	 pat1();

		pat2();
    	pat3();
    	pat2();
    	pat3();
    	pat2();
    	pat3();
    	pat1();
    	pat2();
    	pat3();

    }

//*/

}

void turnallon()
{
	P1OUT|= t1+e1+c+h+n+i;
	P2OUT|= t2+e2+s;


}

void turnalloff()
{
	P1OUT&= ~(t1+e1+c+h+n+i);
	P2OUT&= ~(t2+e2+s);

}

void closein()
{
	P1OUT|= t1;
	P2OUT|= s;
	P1OUT&= ~(e1+c+h+n+i);
	P2OUT&= ~(t2+e2);
	__delay_cycles(200000);

	P1OUT|= e1;
	P2OUT|= e2;
	P1OUT&= ~(t1+c+h+n+i);
	P2OUT&= ~(t2+s);
	__delay_cycles(200000);

	P1OUT|= c;
	P2OUT|= t2;
	P1OUT&= ~(t1+e1+h+n+i);
	P2OUT&= ~(e2+s);
	__delay_cycles(200000);

	P1OUT|= h+n;
	//P2OUT|= ;
	P1OUT&= ~(t1+e1+c+i);
	P2OUT&= ~(t2+e2+s);
	__delay_cycles(200000);

	P1OUT|= i;
	//P2OUT|= e2;
	P1OUT&= ~(t1+e1+c+h+n);
	P2OUT&= ~(t2+e2+s);
	__delay_cycles(200000);

}

void spanout()
{
	P1OUT|= i;
	//P2OUT|= e2;
	P1OUT&= ~(t1+e1+c+h+n);
	P2OUT&= ~(t2+e2+s);
	__delay_cycles(150000);

	P1OUT|= h+n;
	//P2OUT|= ;
	P1OUT&= ~(t1+e1+c+i);
	P2OUT&= ~(t2+e2+s);
	__delay_cycles(150000);

	P1OUT|= c;
	P2OUT|= t2;
	P1OUT&= ~(t1+e1+h+n+i);
	P2OUT&= ~(e2+s);
	__delay_cycles(150000);

	P1OUT|= e1;
	P2OUT|= e2;
	P1OUT&= ~(t1+c+h+n+i);
	P2OUT&= ~(t2+s);
	__delay_cycles(150000);

	P1OUT|= t1;
	P2OUT|= s;
	P1OUT&= ~(e1+c+h+n+i);
	P2OUT&= ~(t2+e2);
	__delay_cycles(150000);

}

void TtoS()
{
	P1OUT|= t1;
	//P2OUT|= ;
	P1OUT&= ~(e1+c+h+n+i);
	P2OUT&= ~(t2+e2+s);
	__delay_cycles(250001);

	P1OUT|= e1;
	//P2OUT|= ;
	P1OUT&= ~(t1+c+h+n+i);
	P2OUT&= ~(t2+e2+s);
	__delay_cycles(250001);

	P1OUT|= c;
	//P2OUT|= ;
	P1OUT&= ~(t1+e1+h+n+i);
	P2OUT&= ~(t2+e2+s);
	__delay_cycles(250001);

	P1OUT|= h;
	//P2OUT|= ;
	P1OUT&= ~(t1+e1+c+n+i);
	P2OUT&= ~(t2+e2+s);
	__delay_cycles(250001);

	P1OUT|= n;
	//P2OUT|= ;
	P1OUT&= ~(t1+e1+c+h+i);
	P2OUT&= ~(t2+e2+s);
	__delay_cycles(250001);

	P1OUT|= i;
	//P2OUT|= ;
	P1OUT&= ~(t1+e1+c+h+n);
	P2OUT&= ~(t2+e2+s);
	__delay_cycles(250001);

	//P1OUT|= t1;
	P2OUT|= t2;
	P1OUT&= ~(t1+e1+c+h+n+i);
	P2OUT&= ~(e2+s);
	__delay_cycles(250001);

	//P1OUT|= t1;
	P2OUT|= e2;
	P1OUT&= ~(t1+e1+c+h+n+i);
	P2OUT&= ~(t2+s);
	__delay_cycles(250001);

	//P1OUT|= t1;
	P2OUT|= s;
	P1OUT&= ~(t1+e1+c+h+n+i);
	P2OUT&= ~(t2+e2);
	__delay_cycles(250001);
}

void pat1()
{
	turnallon();
	 	__delay_cycles(200000);
	 	turnalloff();
		__delay_cycles(200000);

	 turnallon();
	__delay_cycles(200000);
	turnalloff();
	__delay_cycles(200000);

	turnallon();
	__delay_cycles(200000);
	turnalloff();
	__delay_cycles(200000);

	turnallon();
	__delay_cycles(200000);
	turnalloff();
	__delay_cycles(200000);
}

void pat2()
{
	TtoS();
	TtoS();
	TtoS();
	TtoS();
	TtoS();
	TtoS();
	TtoS();
	TtoS();
	TtoS();
	TtoS();
	TtoS();
	TtoS();
	TtoS();
	TtoS();
}

void pat3()
{
	closein();
	spanout();
	closein();
	spanout();
	closein();
	spanout();
	closein();
	spanout();
	closein();
	spanout();
}
