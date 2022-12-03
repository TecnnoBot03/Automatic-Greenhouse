

int TRIG = 6;			
int ECO = 7;		
int bomba = 3;	
int humedadSuelo = A0;		
int DURACION;
int DISTANCIA;

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
  Serial.println(porcentajeHumedad + "% de humedad");
  Serial.println(DISTANCIA + "cm");
  delay(200);


   
}
