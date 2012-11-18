#include <string.h>
#include <stdio.h>

int main(int argc, char **argv) {
	int step=0, val;
	FILE *fl;
	
	if(argc<2) return 0;
	
	if(!(strcmp(argv[1],"dec")))
		step=-100;
	else if (!(strcmp(argv[1],"inc")))
		step=100;
	
	if(!step) return 0;
	
	fl = fopen("/sys/devices/platform/s3c24xx-pwm.0/pwm-backlight.0/backlight/pwm-backlight.0/brightness","r");
	fscanf(fl,"%d",&val);
	fclose(fl);
	
	val += step;
	if((val < 0) || (val > 2800)) return 0;
	
	fl = fopen("/sys/devices/platform/s3c24xx-pwm.0/pwm-backlight.0/backlight/pwm-backlight.0/brightness","w");
	fprintf(fl,"%d\n",val);
	fclose(fl);
	
	return 0;
}
