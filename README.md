# L9110Control

Biblioteca Arduino para controle de motor DC usando ponte H L9110.

## Descrição

Esta biblioteca disponibiliza uma classe de controle de motor DC para circuitos que usem a ponte H L9110 para controle de direção. No momento somente controle de direção está disponibilizado, sendo que o controle de velocidade será adicionado em versões futuras.

##Instalação
Copie o diretório L9110Control para o diretório *libraries* dentro do diretório de *sketches* do seu Arduíno IDE.
**Atenção** o diretório de *sketches* **não** é o diretório onde o Arduino IDE está instalado, para saber qual o seu diretório de *sketches*, verifique a opção *Arquivo* / *Preferências* / *Local do Sketchbook* dentro do Arduino IDE.

**É preciso reiniciar a IDE do Arduino após a cópia para ele reconhecer a biblioteca**


## Uso

Para usar basta incluir o arquivo L9110Control.h colocando a linha *#include* ou usando a opção *Sketch* / *Inserir biblioteca*.

O controle possui um construtor para criação e 3 métodos:

- L9110Control(int Ia, int Ib) : cria um objeto de controle. O parâmetro Ia é o número da GPIO ligada no conector Ia da ponte H e o parâmetro Ib é o número da GPIO ligada no conector Ib da ponte H.

- forward(): coloca o motor em movimento com velocidade máxima e direção para a frente;

- backward(): coloca o motor em movimento com velocidade máxiam e direção para trás;

- stop(): para o motor

**Obs1**: Para a frente e para trás dependem de como os polos do motor estão conectados na saída da ponte H. Se a direção real do motor estiver "ao contrário", inverta os polos;

**Obs2**: A "velocidade máxima" depende da corrente alimentada na ponte e da corrente de operação do motor. Esta biblioteca simplesmente manda 100% da corrente de entrada para o motor, porém se a sua ponte está alimentada com 3.3V e o seu motor é de 3-6V ele rodará em 10% da velocidade.

O código de exemplo abaixo ilustra um loop que faz o motor girar para frente, parar, girar para trás e parar, continuamente. A Ia está ligada no GPIO0 e a Ib no GPIO2 (pinos D3 e D4 na Wemos R1 D2).

```
#include <L9110Control.h>

L9110Control control(0,2);


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  control.forward();
  delay(2000);
  control.stop();
  delay(1000);
  control.backward();
  delay(2000);
  control.stop();
  delay(1000);

}
```
