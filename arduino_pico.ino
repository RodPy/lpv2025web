
#include <Wire.h>

#define UNO_ADDR 9
#define RESP_SIZE 15

String data = "Hi from Arduino";

void setup()
{
  Serial.begin(9600);
  Wire.begin(UNO_ADDR);
  /*Event Handlers*/
  Wire.onReceive(DataReceive);
  Wire.onRequest(DataRequest);
}

void loop()
{
  delay(50);
}

void DataReceive(int numBytes)
{
  int i=0;
  char data[RESP_SIZE];
  memset(data,0, RESP_SIZE);
  while(Wire.available()) 
  { 
    data[i++] = Wire.read();
  }
  
  Serial.println("Recv Event");
  Serial.println(String(data));
}

void DataRequest()
{
  String response = data + "\n";  // Agrega salto de línea al final
  Wire.write(response.c_str());   // Envía solo el contenido útil
  Serial.println("Sent resp: " + response);
}

