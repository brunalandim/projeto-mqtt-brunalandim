#include <PubSubClient.h>

#include <UIPEthernet.h>

#include <SPI.h>

// variável pro servidor 
boolean mensagem;
//define o endereço MAC que será utilizado
byte mac[] = {0xBE, 0xF0, 0x4F, 0x95, 0x3B, 0xFC};
int pino2 = 2;
bool estado_sensor;
//inicia o cliente Ethernet
EthernetClient client;
// p/ protocolo MQTT
PubSubClient mqttClient(client);

void setup() {
  // controlador Ethernet
  Ethernet.begin(mac);

  //monitor serial
  Serial.begin(9600);
  pinMode(pino2,INPUT_PULLUP);

  mqttClient.setServer("3.82.94.158",1883);
  
  Serial.print("o IP do arduino e: ");
  Serial.println(Ethernet.localIP());

  Serial.print("A mascara de Rede do Arduino e: ");
  Serial.println(Ethernet.subnetMask());

  Serial.print("O Gateway do Arduino e: ");
  Serial.println(Ethernet.gatewayIP());

  delay(5000);
   
}

void loop() {
  
  //define um usuário
  mqttClient.connect("brunalandim");
  estado_sensor = digitalRead(pino2);

  /*mensagem = mqttClient.publish("brunalandim-22","resposta 42");
  mqttClient.loop();
  delay(500);*/

  if(estado_sensor == 0)
  {
    mensagem = mqttClient.publish("brunalandim-22","1");


  }
  else{
        mensagem = mqttClient.publish("brunalandim-22","0");


  }

    mqttClient.loop();
    delay(500);

}
