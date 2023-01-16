int TRIG = 6;      
int ECO = 7;    
int bomba = 4;  
int humedadSuelo = A0;    
int DURACION;
int DISTANCIA;
int temperatura;

void setup()
{
  pinMode(TRIG, OUTPUT);  
  pinMode(ECO, INPUT);    
  pinMode(bomba, OUTPUT); 
  Serial.begin(9600);

}

void loop()
{
  int humedad = analogRead(humedadSuelo);
  digitalWrite(TRIG, HIGH);
  delay(1);
  digitalWrite(TRIG, LOW);
  DURACION = pulseIn(ECO, HIGH);
  DISTANCIA = DURACION / 58.2;
  int porcentajeHumedad = map(humedad, 1023, 200, 0, 100);
  Serial.print(porcentajeHumedad);
  Serial.println("% de humedad");
  Serial.print(DISTANCIA);
  Serial.println("cm");
  if (porcentajeHumedad < 60) {
    digitalWrite(bomba, LOW);
    Serial.println("SI");
  }
  else {
    digitalWrite(bomba, HIGH);
    Serial.println("NO");
  }
  delay(200);
}
