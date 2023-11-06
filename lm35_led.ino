// C++ code
//
#define temp_pin A0  // the lm35 is connected to pin A0
#define led PB5 //PB5 is the bit in portB which correspond to built in led
 uint16_t comp;
 uint16_t comp_250 =15625; //for 250ms delay
 uint16_t comp_500 =31250; //for 500ms delay
void setup()
{
  //Serial.begin(9600);
  DDRB|=(1<<led); //set led as output
  TCCR1A=0;  //resetting the timer configurations
  TCNT1=0;   //resetting the timer
    
  //set the prescaler to 256
  TCCR1B|=(1<<CS12); 
  TCCR1B&=~(1<<CS11);
  TCCR1B&=~(1<<CS10);
  
  TIMSK1|=(1<<OCIE1A);// enable interrupt of compare register A
  
}

void loop()
{
int rawValue = analogRead(temp_pin); // Read the raw analog value
float voltage = rawValue * (5.0 / 1023.0); // Convert the raw value to voltage 
float temp = voltage*100;

if(temp<30)        //if its less than 30
  comp= comp_250;  //blink 250ms
else if(temp>30)    //if its more than 30
  comp=comp_500;    //blink 500ms
//Serial.println(temp);
}

//--------------ISR------------

ISR(TIMER1_COMPA_vect){
  TCNT1=0;   //resetting the timer
  PORTB^=(1<<led); // toggle the led when delay reached
  OCR1A= comp;    // set the compare register value
}