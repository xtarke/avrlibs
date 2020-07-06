# Placa de potência para Buggy AWD

Baseado em [Projeto PI3](https://github.com/luscasos/PI3-carro) de __Lucas Odair Silva.__

![carro final](./images/photo_01.jpg)

## Informações gerais

Projeto da placa eletrônica de potência para o acionamento de um Buggy 4x4. Um conector de 26-vias faz a conexão das seguintes placas:

- [Arduino Uno](https://github.com/xtarke/avrlibs/tree/master/shields/carrinho_shield)
- [MSP-EXP430G2](https://github.com/xtarke/msplibs/tree/master/hardware/shield_exp430g2)
- [MSP-EXP430FR2355](https://github.com/xtarke/msplibs/tree/master/hardware/shield_exp430fr2355)
- [Raspberry Pi](https://github.com/xtarke/automated_buggy)

## Características

- Controle independente dos motores (lado esquerdo e lado direito)
- Sensores de velocidade [Encoder](https://www.filipeflop.com/produto/sensor-de-velocidade-encoder/)
- Monitoramento de bateria de LiPo
- Sensor de linha dual
- Sensor ultrassom
- Comunicação Bluetooth (UART)


# Hardware

## Acionamento dos motores

![Ponte H](https://i.ibb.co/JCv0MNN/ponte-h.png)

Circuito final de alimentação dos motores, com queda de 0,4V de tensão na carga em relação a VCC e corrente de polarização externa de 640pA, não exigindo muita corrente do microcontrolador.
![Ponte H](https://i.ibb.co/ZXjB03W/ponte.png)

## Comunicação

![HC-05](https://i.ebayimg.com/images/g/U7MAAOSw6jJb868K/s-l300.jpg)

## Aferição de velocidade

![encoder](https://cdn.awsli.com.br/600x450/154/154718/produto/24268110/4b2e443ab4.jpg)

## Baterias
Para alimentar o carro foram escolhidas duas baterias de LIPO, de 3,7V e 1200mAh, conectadas em série, o que resulta em 7,4V de tensão.

![Bateria](https://encrypted-tbn2.gstatic.com/shopping?q=tbn:ANd9GcSpjiAIQ2f9JGUJtZus21vVg8vtvALbAbm2rqdRHKAY2R2VNm6NoqiVKkhJ6pQQutPrGLsdANjfVmnbD21Rb0aYAq7dlIuCOGFzmBbqDxXh0q080XQtv5Aq&usqp=CAc)

## Regulador de tensão
Como o conjunto de baterias tem como tensão 7,4V na saída, é necessário baixar a tensão para níveis aceitáveis para o microcontrolador e modulo bluetooth, no caso foi usado um regulador ajustável Step-up-down, por questão de disponibilidade, mesmo esse sendo superdimensionado para a aplicação em questão, já que suporta correntes de até 5A e nesse caso não passa de 200mA.

![Regulador](./images/buck.png)

## Medição da tensão das baterias
Como regra geral, não se pode descarregar uma bateria abaixo de uma certa tensão, com as usadas nesse projeto não é diferente, não sendo recomendado baixar a tensão da marca dos 3V, como o sistema possui duas baterias é necessário medir a tensão delas individualmente. O conversor analógico digital do microcontrolador tem como tensão base 3V, então é preciso baixar as tensões para menos de 3V, o circuito usado para isso é o diferencial com ampop, que pode dar um ganho menor que 1, sem usar tensão negativa. O Ampop escolhido foi o LM324, com ganho de 1/3 para a tensão superior (bateria 1 em serie com a bateria 2), e de 2/3 para a tensão media (bateria 1).
![diferencial](http://www.c2o.pro.br/hackaguas/figuras/amplificador_operacional_diferencial.png)


## Placa de circuito

![carro visto de cima](./images/board.png)
