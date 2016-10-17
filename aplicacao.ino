#include <UIPEthernet.h>
#define AGUARDE 5

EthernetUDP udp; //Criando o objeto udp da nossa librarie

void setup() {

Serial.begin(9600);

// Meu MAC Address do Ethernet Shield
uint8_t mac[6] = {0x00,0x11,0xAE,0xFF,0xA4,0x05};
// Meu IP do Ethernet Shield
Ethernet.begin(mac,IPAddress(192,168,0,25));

}

void loop() {
  
int success;

//Inicia a montagem do pacote para enviar ao host especificado
// No caso 10,7,12,246 é o IP do meu servidor(destino) e 5000 é a porta UDP
success = udp.beginPacket(IPAddress(10,7,12,246),5000);
Serial.print("Pacote Iniciado: ");
Serial.println(success);

// Envia string "copa2014" via UDP
success = udp.write("Dados Infravermelho"); //success recebe o numero de bytes enviados
Serial.print("bytes enviado: ");
Serial.println(success);

// Finaliza o pacote enviado, retorna 1 para sucesso e 0 para erro
success = udp.endPacket();
Serial.print("Fim do Pacote: ");
Serial.println(success);

// Informa o IP Remoto
Serial.print("IP Remoto: ");
Serial.println(udp.remoteIP());

// Informa a Porta Remota
Serial.print("Porta Remota: ");
Serial.println(udp.remotePort());

// Encerra este socket
udp.stop();

delay(AGUARDE*1000); //Aguarda 5s, altere AGUARDE pelo tempo em segundos
}