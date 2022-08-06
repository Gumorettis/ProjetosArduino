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

void setup()
{
  pinMode(4, OUTPUT);
  Serial.begin(9600);
  dht.begin();
}

void loop()
{
    delay(2000);
    hum = dht.readHumidity();
    temp= dht.readTemperature();
    Serial.print("Humidity: ");
    Serial.print(hum);
    Serial.print(" %, Temp: ");
    Serial.print(temp);
    Serial.println(" Celsius");
    delay(500); //Delay 2 sec.
}
