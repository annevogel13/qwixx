#include "Calcul.h"
#include <assert.h>

int intAdd (const int a, const int b)
{
	return a + b; 
	/*int i;
	int r;
	r = a;
	if (b>=0)					// als b groter is dan  0
		for(i=0;i<b;++i) ++r;	
	else
		for(i=0;i<-b;++i) --r;
	return r; */
}

int intMul (const int a, const int b)
{
	return a * b ; 
	/*
	int i;
	int r;
	r = 0;
	for(i=0;i<b;++i)
		r = intAdd(r,a);
	return r; */ 
}

int intDiv (const int a, const int b)
{
	assert( b!=0 );
	return ((int)(a/b));
}

int intFactoriel (const int n)
{
	/*
	if (n<=0) return 0;
	else if (n==1) return 1;
	else return intMul(n,intFactoriel(intAdd(n,-1)));*/

	// Il faut mieux faire une boucle (cela consomme moins de mémoire)
	//Si n=0, il faut retourner 1, donc la fonction ci-dessus est fausse !
	unsigned int somme=1;
	if (n<0) return 0;
	for(unsigned char i=1;i<=n;i++){
		somme *=i;
	}
	return somme;
}
