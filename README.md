# Sistema de comunicação LoRa (Half-Duplex)

## Descrição
Esse projeto implementa um sistema de comunicação sem fio, utilizando dois microcontroladores ESP-32.
O projeto opera em Half-Duplex, onde ambos os modos recebem e enviam dados de maneira alternada.

## Configuração
- Frequência: 433.6 MHz
- Interface: SPI
- Biblioteca: LoRa.h

## Funcionamento
Cada dispositivo: 
- Envia os sinais de #0 até #5
- Alterna para modo de recepção após o envio
- Recebe mensagens do outro dispositivo
- Exibe os dados no Serial Monitor

## Estrutura do projeto
- [Código do Dispositivo A](dispositivo_A/codigo.ino)
- [Código do Dispositivo B](dispositivo_b/codigo.ino)

## Problemas encontrados
- O microcontrolador, ESP-32, do laboratório do CEFAST, estava dando problema de brownout, resetando diversas vezes seguidamente, isso devido a picos de consumo do módulo LoRa, causando queda momentânea na tensão de alimentação.
- O sistema com o ESP-32 do CEFAST, também estava instável, indicando fornecimento de corrente insuficiente.

## Soluções implementadas
- Para resolver o problema do brownout, foram utilizados alguns capacitores na alimentação para estabilizar a tensão, suprindo os picos de corrente durante a transmissão e evitando resets.
- Para solucionar a instabilidade de alimentação, foi utilizada a fonte de alimentação do Arduino Uno para garantir maior estabilidade e fornecimento adequado de corrente ao sistema. O Arduino foi utilizado exclusivamente como suporte de alimentação, e não participou da lógica do sistema.

## Integrantes
- Daniel Bosco;
- Davi Lacerda.
