int SEQUENCIA[100] = {};
int RODADA_ATUAL = 0;
int VALOR_BOTAO = 0;
int PASSO_ATUAL_SEQUENCIA = 0;
int BOTAO_PRESSIONADO = 0;
int GAME_OVER = false;
int LEDS[4] = {3, 2, 1, 4};

 
void setup()
{ 
  randomSeed(analogRead(0));

    for (int i = 0; i <= 3; i++){
        pinMode(LEDS[i], OUTPUT);
        }
}
 
void loop()
{

  if(GAME_OVER){
      gameOver();
  }
  if(RODADA_ATUAL == 0){
  inicio();
  delay(500);
  }

  proximaRodada();
  reproduzirSequencia();
  aguardarJogador();

}

void inicio() {
  for (int i = 0; i < 4; i++) {
  digitalWrite(LEDS[i], HIGH);
  }
  delay(500);

  for (int i = 0; i < 4; i++) {
  digitalWrite(LEDS[i], LOW);
  }
  delay(500);
}

int valorBotao(int valor){
    if (valor >1010 && valor <1024)
    return 3;
    if (valor >999 && valor <1011)
    return 2;
    if (valor >975 && valor <1000)
    return 1;
    if (valor >900 && valor <976)
    return 4;
}

void gameOver(){
      SEQUENCIA[100] = {};
      RODADA_ATUAL = 0;
      VALOR_BOTAO = 0;
      PASSO_ATUAL_SEQUENCIA = 0;
      GAME_OVER = false;
}

void proximaRodada() {
  int RNG = random(0, 4);
  SEQUENCIA[RODADA_ATUAL++] = RNG;
}

void reproduzirSequencia() {
  for (int i = 0; i < RODADA_ATUAL; i++) {
    digitalWrite(LEDS[SEQUENCIA[i]], HIGH);
    delay(500);

    digitalWrite(LEDS[SEQUENCIA[i]], LOW);
    delay(100);
  }
}

void aguardarJogador() {

  for (int i = 0; i < RODADA_ATUAL; i++) {
    aguardarJogada();
    verificarJogada();
 
    if (GAME_OVER) {
      break;
    }

    PASSO_ATUAL_SEQUENCIA++;
  }

  PASSO_ATUAL_SEQUENCIA = 0;
}

void aguardarJogada() {
  boolean JOGADA_EFETUADA = false;

while(!JOGADA_EFETUADA){
      if (valorBotao(analogRead(A0)) == 3) {
        BOTAO_PRESSIONADO = 0;

        digitalWrite(LEDS[0], HIGH);
        delay(300);
        digitalWrite(LEDS[0], LOW);

        JOGADA_EFETUADA = true;
        delay(500);
      }
      if (valorBotao(analogRead(A0)) == 2) {
        BOTAO_PRESSIONADO = 1;
        
        digitalWrite(LEDS[1], HIGH);
        delay(300);
        digitalWrite(LEDS[1], LOW);

        JOGADA_EFETUADA = true;
        delay(500);
      }
      if (valorBotao(analogRead(A0)) == 1) {
        BOTAO_PRESSIONADO = 2;

        digitalWrite(LEDS[2], HIGH);
        delay(300);
        digitalWrite(LEDS[2], LOW);

        JOGADA_EFETUADA = true;
        delay(500);
      }
      if (valorBotao(analogRead(A0)) == 4) {
        BOTAO_PRESSIONADO = 3;

        digitalWrite(LEDS[3], HIGH);
        delay(300);
        digitalWrite(LEDS[3], LOW);

        JOGADA_EFETUADA = true;
        delay(500);
      }
      }
}

void verificarJogada() {
  if (SEQUENCIA[PASSO_ATUAL_SEQUENCIA] !=BOTAO_PRESSIONADO) {

    for (int i = 0; i < 4; i++) {
      digitalWrite(LEDS[i], HIGH);
      delay(200);
      digitalWrite(LEDS[i], LOW);
      delay(200);
    }

    for (int i = 0; i <= 3; i++) {
      digitalWrite(LEDS[i], HIGH);
      delay(100);
      digitalWrite(LEDS[i], LOW);
      delay(100);
    }

    GAME_OVER = true;
    delay(500);
  } else {
      delay(1000);
  }
}