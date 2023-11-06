# Greendzine_Assignment
Calculation of the delays;

Timer1 register is 16 bit :65536.

system clock: 16MHz.

pre-scaler is set to 256 : 16MHz/256=62500Hz.

compare register value for 500ms delay:0.5*62500=31250.

compare register value for 250ms delay:0.25*62500=15625.

Calculation of temparature;

Analog read value range :0-1023.

conversion to volts =value*(5/1024)  (for 5v).

temparature valur according to lm35 datasheet = volt*100.
