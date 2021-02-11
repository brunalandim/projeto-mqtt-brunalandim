/*
    Descrição:
    Aula presencial configurando o sensor magnético
    autor:Bruna Landim
    data:27/01/2021

*/


int pino2 = 2;
bool estado_sensor;

void setup() {
  pinMode(pino2,INPUT_PULLUP);
  Serial.begin(9600);

}

void loop() {
  //definindo o pino 2 para fazer leitura do estado sensor
  estado_sensor = digitalRead(pino2);

  if(estado_sensor == 0)
  {
    Serial.println("o rack esta fechado");
    delay(1000);
      
  
  }
  else{
    Serial.println("o rack esta aberto");
    delay(1000);
  }
  
  //Serial.println("o estado do sensor e: ");
  //Serial.println(estado_sensor);
  
}
