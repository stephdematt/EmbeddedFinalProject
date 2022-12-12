#include <msp430.h> 
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

/**
 * main.c
 */
void setup()
{
    byte error;
    Wire.begin();
    Wire.beginTransmission(0x27);
    error = Wire.endTransmission();
    if(error == 0){                      // If your device is 0x27
      LiquidCrystal_I2C lcd(0x27,20,4);
      lcd.init();
      lcd.backlight();
      lcd.setCursor(0,0);
      lcd.print("Device Addr = 0x27");
    }else{                               // If your device is 0x3F
      LiquidCrystal_I2C lcd(0x3F,20,4);
      lcd.init();
      lcd.backlight();
      lcd.setCursor(0,0);
      lcd.print("Device Addr = 0x3F");
    }
}

void loop(){}

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	return 0;
}



