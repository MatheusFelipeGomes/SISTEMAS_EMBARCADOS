# Documentação do Projeto: Sistema de Fluxo de Pessoas com Raspberry Pi Pico

## Visão Geral

Este projeto tem como objetivo criar um sistema para monitorar e controlar o fluxo de pessoas em um ambiente utilizando sensores ultrassônicos para detectar a entrada e a saída de pessoas. O número de pessoas no ambiente é exibido em um display LCD, permitindo o acompanhamento em tempo real.

## Objetivos

- Contar o número de pessoas que entraram e saíram de um ambiente.
- Exibir a quantidade de pessoas no ambiente em um display LCD.
- Utilizar sensores ultrassônicos para detectar a presença de pessoas na entrada e saída.
- Oferecer a possibilidade de simular a entrada e saída de pessoas através de botões.

## Componentes Utilizados

- **Raspberry Pi Pico**: Microcontrolador utilizado para controlar o sistema.
<img src="https://www.raspberrypi.com/documentation/microcontrollers/images/picow-pinout.svg" width="400"/>

- **Sensor Ultrassônico HC-SR04** (2 unidades): Utilizados para medir a distância e detectar a presença de pessoas na entrada e na saída.
<img src="https://freesvg.org/img/1570649329hc-sr04.png" height="200"/>

- **Display LCD 16x2 com I2C**: Usado para exibir o número de pessoas no ambiente.
<img src="https://freesvg.org/img/16x2_lcd_with_iicmodule.png" width="200"/>

- **Botões de Entrada e Saída**: Utilizados para simular a adição ou remoção de pessoas no sistema manualmente.
<img src="https://archive.smashing.media/assets/344dbf88-fdf9-42bb-adb4-46f01eedd629/c28d1061-95a7-44bf-b469-f6172ac28dfe/svg-arduino-pushbutton-image3.svg" width="200"/>
- **Fios de Conexão**: Para realizar as ligações entre os componentes.

## Esquema de Conexão

| Componente                 | Pino Raspberry Pi Pico |
|----------------------------|------------------------|
| **LCD (I2C)**               | GP16 (SDA)             |
|                            | GP17 (SCL)             |
|                            | VCC (5V)               |
|                            | GND (GND)              |
| **Botão Entrada**           | GP6                    |
| **Botão Saída**             | GP7                    |
| **Sensor Ultrassônico (Entrada)** | GP2               |
| **Sensor Ultrassônico (Saída)**   | GP3               |

## Funcionamento

### Entrada e Saída de Pessoas

- O sistema utiliza dois sensores ultrassônicos (um para entrada e outro para saída). Quando um objeto (como uma pessoa) atravessa o feixe do sensor, a distância é medida e comparada com um valor limite. Se a distância for abaixo do limite, a pessoa é contada como entrada ou saída, dependendo da direção.
- Botões de entrada e saída permitem simular a entrada ou saída de pessoas manualmente. A contagem é aumentada ou diminuída com base na ação do botão.

### Exibição no LCD

- O número de pessoas no ambiente é exibido em tempo real no display LCD. O contador é atualizado cada vez que uma pessoa entra ou sai do ambiente.

## Considerações Finais

- **Precauções**: O limite de distância do sensor ultrassônico (10 cm) pode ser ajustado para otimizar a detecção dependendo do ambiente.
- **Possíveis Melhorias**:
  - A implementação de um controle de limite máximo de pessoas no ambiente pode ser uma melhoria útil.
  - Pode-se adicionar mais sensores para aumentar a precisão e a cobertura da detecção.
  - O sistema pode ser expandido para incluir notificações ou alertas em caso de superlotação.

## Conclusão

Este sistema simples de controle de fluxo de pessoas foi desenvolvido para monitorar a quantidade de pessoas em tempo real, utilizando sensores e um display LCD para exibição. Ele oferece uma base sólida para futuras melhorias e personalizações, permitindo a integração com outros sistemas e sensores para criar soluções mais completas.
