#include <Wire.h>
#define ADXLAddress (0x53)
int xAcc,  yAcc,  zAcc;
int buff[6];

int a_offx = 0;
int a_offy = 0;
int a_offz = 0;

int lastZ = 0; 
const int threshold = 150;
int counter = 0;

void writeRegister(int deviceAddress, byte address, byte val)
{
  Wire.beginTransmission(deviceAddress); 
  Wire.write(address);       
  Wire.write(val);        
  Wire.endTransmission();
}

void readRegister(int deviceAddress, byte address) 
{
  Wire.beginTransmission(deviceAddress);  
  Wire.write(address);        
  Wire.endTransmission(); 
  Wire.beginTransmission(deviceAddress); 
  Wire.requestFrom(deviceAddress, 6);   

  int i = 0;
  while(Wire.available())    
  {  buff[i++] = Wire.read();  }
  Wire.endTransmission(); 
}

void initAcc() 
{
  writeRegister (ADXLAddress, 0x2C, 0x09);
  writeRegister (ADXLAddress, 0x2D, 0x08);
}

void getAccData()
{
  readRegister(ADXLAddress, 0x32);  
  xAcc = ((buff[1] << 8) | buff[0] )+ a_offx;   
  yAcc = ((buff[3] << 8) | buff[2] )+ a_offy;
  zAcc = ((buff[5] << 8) | buff[4]) + a_offz;
}

void setup()
{
  Serial.begin(115200);
  Wire.begin();
  initAcc();
  delay(50);
} 
  
void loop()
{
    counter++;
    getAccData();
    //Serial.print("xAcc=");
    //Serial.print(xAcc);
    //Serial.print("  yAcc=");
    //Serial.print(yAcc);
    //Serial.print("  zAcc=");
    //Serial.println(zAcc);
     Serial.println("1");
     if(((zAcc - lastZ) > threshold))
     {
        Serial.println("0");
        counter=0;
     }
    lastZ = zAcc;
    delay(100);
}
