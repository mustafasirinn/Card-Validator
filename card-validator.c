#include <cs50.h>
#include <stdio.h>
#include <math.h>

int basamak(long kartNoBa);
int degerlendir(long kartNoDe);

int main(void)
{
    long kartNo;
    int basamakSa, durum;
    double a12 = pow(10,12); long pow12 = a12;
    double a13 = pow(10,13); long pow13 = a13;
    double a14 = pow(10,14); long pow14 = a14;
    double a15 = pow(10,15); long pow15 = a15;

    do{
    	kartNo = get_long("Kart No: ");
    }while(kartNo<0);

    basamakSa = basamak(kartNo);
    durum = degerlendir(kartNo);

    if(durum == 0){
	    if(basamakSa==15){
	    	if(kartNo/pow13 == 34 || kartNo/pow13 == 37){
	    		printf("AMEX\n");
	    	}
	    	else
	    		printf("INVALID\n");
	    }
	    else if(basamakSa==13){
	    	if(kartNo/pow12 == 4){
	    		printf("VISA\n");
	    	}
	    	else
	    		printf("INVALID\n");

	    }
	    else if(basamakSa==16){
	    	if(kartNo/pow15 == 4){
	    		printf("VISA\n");
	    	}
	    	else if(kartNo/pow14 == 51 || kartNo/pow14 == 52 || 
	    		kartNo/pow14 == 53 || kartNo/pow14 == 54 || 
	    		kartNo/pow14 == 55){ 
	    		printf("MASTERCARD\n");

			}
	    	else
	    		printf("INVALID\n");
	    }
	    else
	    	printf("INVALID\n");
	}
	else
		printf("INVALID\n");

	return 0;
}


int degerlendir(long kartNoDe){
	int sonuc, kalanRakamlar=0, rakam, carpi2=0;
	long kartNoTmp = kartNoDe;

	while(kartNoDe>0){
		rakam = ((kartNoDe%100)/10)*2;
		if(rakam>9){
			rakam = rakam%10 + rakam/10;
		}
		carpi2 += rakam;
		kartNoDe /= 100;
	}

	while(kartNoTmp>0){
		rakam = kartNoTmp%10;
		kalanRakamlar += rakam;
		kartNoTmp /= 100;
	}
	sonuc = (kalanRakamlar + carpi2)%10;
	return sonuc;
}

int basamak(long kartNoBa){
	int basamaks = 0;
	while(kartNoBa > 0){
		basamaks++;
		kartNoBa/=10;
	}
	return basamaks;
}
