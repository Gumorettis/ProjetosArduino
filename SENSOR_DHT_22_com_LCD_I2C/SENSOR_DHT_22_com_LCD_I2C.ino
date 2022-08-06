#include <Adafruit_Sensor.h>

#include <DHT_U.h>

//Libraries
#include <DHT.h>;

//Constants
#define DHTPIN 4     
#define DHTTYPE DHT22   
DHT dht(DHTPIN, DHTTYPE); 

//Variables
int chk;
float hum;  //Stores humidity value
float temp; //Stores temperature value

// parte do lcd 

#include <LiquidCrystal_I2C.h>

byte custom[8] = {
  0b00111,          // Caractere customizado
  0b00101,
  0b00111,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};

LiquidCrystal_I2C lcd(0x27,16,2); 

void setup()
{
  pinMode(4, OUTPUT);
  Serial.begin(9600);
  dht.begin();

  // inicialização do lcd 
  analogReference(INTERNAL);  // Muda a referência de 5V para 1,1V
  lcd.init();           
  lcd.backlight(); 
  lcd.createChar(5, custom);
}

void loop()
{
    delay(1000);
    hum = dht.readHumidity();
    temp= dht.readTemperature();

    lcd.setCursor(1,0);
    lcd.print("Temp: ");
    lcd.print(temp); 
    lcd.print("C "); 
    lcd.home();
    lcd.setCursor(1,1);
     
    lcd.print("Humid: ");
    lcd.print(hum);
    
    
   // Serial.print("Humidity: ");
   // Serial.print(hum);
   // Serial.print(" %, Temp: ");
   // Serial.print(temp);
   // Serial.println(" Celsius");
}
