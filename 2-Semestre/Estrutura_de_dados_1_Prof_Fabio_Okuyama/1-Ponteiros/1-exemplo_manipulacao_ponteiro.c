#include <stdio.h>

int main(){

	int x, *px, *py;

	x = 9;
	px = &x;
	py = px;

	printf ("\nx   = %d", x);
	printf ("\n&x  = %p", &x);
	printf ("\npx  = %p", px);
	printf ("\npy  = %p", py);
	printf ("\n*px = %d", *px);
	printf ("\n*py = %d", *py);
return 0;
}
