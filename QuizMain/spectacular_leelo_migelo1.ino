#include <LiquidCrystal.h>

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST      0


// change this to make the song slower or faster
int tempo = 140;

// change this to whichever pin you want to use


// notes of the moledy followed by the duration.
// a 4 means a quarter note, 8 an eighteenth , 16 sixteenth, so on
// !!negative numbers are used to represent dotted notes,
// so -4 means a dotted quarter note, that is, a quarter plus an eighteenth!!
int melody[] = {

  // Happy Birthday
  // Score available at https://musescore.com/user/8221/scores/26906

  NOTE_C4,4, NOTE_C4,8, 
  NOTE_D4,-4, NOTE_C4,-4, NOTE_F4,-4,
  NOTE_E4,-2, NOTE_C4,4, NOTE_C4,8, 
  NOTE_D4,-4, NOTE_C4,-4, NOTE_G4,-4,
  NOTE_F4,-2, NOTE_C4,4, NOTE_C4,8,

  NOTE_C5,-4, NOTE_A4,-4, NOTE_F4,-4, 
  NOTE_E4,-4, NOTE_D4,-4, NOTE_AS4,4, NOTE_AS4,8,
  NOTE_A4,-4, NOTE_F4,-4, NOTE_G4,-4,
  NOTE_F4,-2,
 
};

// sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
// there are two values per note (pitch and duration), so for each note there are four bytes
int notes = sizeof(melody) / sizeof(melody[0]) / 2;

// this calculates the duration of a whole note in ms
int wholenote = (60000 * 4) / tempo;

int divider = 0, noteDuration = 0;



int buzzer = 13;
int estadoBotao = 0;

LiquidCrystal lcd(12, 11, 6, 5, 4, 3);

char *perguntaFacil[] = {"A raiz de   ", "121 e = 11?",
                         "Pi           ", "e racional?       ",
                         "A fracao ", "11/7 e impropia?   ",
                         "1 mais 9    ", "e igual a doze?",
                         "y=2x+6 e     ", " uma funcao?       ",
                         "A soma de 13 + ", "18 e = 31.       ",
                         "12 menos 16  ", "e igual a 4?     ",
                         "12 dividido por ", "2 e igual a 6?",
                         " | -6 | - 3   ", "e igual a 9?     ",
                         "2+4x8 ", "e igual a 34?",
                         "10 + 10", "= 10 "};

char *perguntaMedio[] = {"O ar ", "so tem oxigenio?        ",
                         "Ava Lovelace fez    ", "o 1 algoritmo?   ",
                         "Golfinhos sao        ", "mamiferos?         ",
                         "Toda aurora e       ", "boral?             ",
                         "Troia ganhou", "dos gregos?             ",
                         "A Terra e     ", "plana?            ",
                         "Piramide de gize  ", "n tem tres lados?  ",
                         "O titanic afundou      ", "em 1911?          ",
                         "O macarrao e        ", "italiano?             ",
                         "Chineses criaram  ", "a bussola?  ",
                         "Constelacoes sao     ", "invencoes humanas?       "};

char *perguntaDificil[] = { "O piano tem       ", "88 teclas?            ",
                            "Salvador Dali     ", "pintou Guernica?       ",
                            "O coracao tem        ", "4 valvulas?         ",
                            "Menor osso      ", "humano e no pe?             ",
                            "Stonehenge e        ", "na Irlanda?             ",
                            "Marie curie    ", "tem um nobel?            ",
                            "Filosofia e       ", "a mae da ciencia?  ",
                            "Mercurio e =        ", "Hermes?          ",
                            "girafa e maior         ", "animal do mundo?             ",
                            "Tipo O      ", "doador universal?  ",
                            "Indonesia e     ", "arquipelago?       "};

int resFacil[] = { 1, 0, 1, 0, 1, 1, 0, 1, 0, 0,1};
int resMedio[] = {0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1};
int resDificil[] = { 1, 0, 1, 0, 0, 0, 1, 1, 0, 1};

int segundos = 0;
int tempoMaximo = 6000;
int estadoBotaoSim = 0;
int estadoBotaoNao = 0;
int estadoBotaoPular = 0; // Variável para o botão de pular pergunta
int pontuacaoFacil = 0;
int pontuacaoMedio = 0;
int pontuacaoDificil = 0;
int pulosUtilizados = 0; // Contador de pulos utilizados
int tempo_led = tempoMaximo/2;

void setup() {
  lcd.begin(16, 2);
  pinMode(2, INPUT);
  pinMode(8, INPUT); // Botão de pular pergunta
  pinMode(buzzer, OUTPUT);
  pinMode(10, INPUT);
  pinMode(9, INPUT);
  pinMode(7, OUTPUT);
  randomSeed(analogRead(0));
}

void loop() {
  telaInicio();
  
  for (int i = 0; i < 5; i++) {
    int indiceFacil = random(8);
    perguntas(perguntaFacil[indiceFacil * 2], perguntaFacil[indiceFacil * 2 + 1], resFacil[indiceFacil], pontuacaoFacil);
  }
  mostrarPontuacaoAcumulada(pontuacaoFacil);
  
  for (int i = 0; i < 5; i++) {
    int indiceMedio = random(10);
    perguntas(perguntaMedio[indiceMedio * 2], perguntaMedio[indiceMedio * 2 + 1], resMedio[indiceMedio], pontuacaoMedio);
  }
  mostrarPontuacaoAcumulada(pontuacaoFacil + pontuacaoMedio);
  
  for (int i = 0; i < 5; i++) {
    int indiceDificil = random(10);
    perguntas(perguntaDificil[indiceDificil * 2], perguntaDificil[indiceDificil * 2 + 1], resDificil[indiceDificil], pontuacaoDificil);
  }
  mostrarPontuacaoAcumulada(pontuacaoFacil + pontuacaoMedio + pontuacaoDificil);
  
  int pontuacaoTotal = pontuacaoFacil + pontuacaoMedio + pontuacaoDificil;
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Pergunta Final?");
  lcd.setCursor(0, 1);
  lcd.print("O 10 VEM?");
  
  estadoBotaoSim = digitalRead(10);
  estadoBotaoNao = digitalRead(9);
  estadoBotaoPular = digitalRead(8); // Lê o estado do botão de pular pergunta
  segundos = 0;
  
  while (segundos < tempoMaximo && estadoBotaoSim == LOW && estadoBotaoNao == LOW && estadoBotaoPular == LOW) {
    delay(1000);
    segundos += 1000;
    estadoBotaoSim = digitalRead(10);
    estadoBotaoNao = digitalRead(9);
    estadoBotaoPular = digitalRead(8); // Atualiza o estado do botão de pular pergunta
  }
  
  if (estadoBotaoSim == HIGH) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Voce ganhou!");
    for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
    divider = melody[thisNote + 1];
    if (divider > 0) {
      // regular note, just proceed
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      // dotted notes are represented with negative durations!!
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // increases the duration in half for dotted notes
    }
    tone(buzzer, melody[thisNote], noteDuration * 0.9);
    delay(noteDuration);
    noTone(buzzer);
  }
    lcd.setCursor(0, 1);
    lcd.print("Pontuacao: ");
    lcd.print(pontuacaoTotal);
    delay(2000);
  } else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Voce perdeu!");
    delay(2000);
    // Reinicia o jogo
    reiniciarJogo();
  }
}

void telaInicio() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Bem-vindo ao");
  lcd.setCursor(0, 1);
  lcd.print("Jogo de Quiz!");
  
  while (true) {
    if (digitalRead(2) == HIGH) {
      delay(1000); // debounce delay
      while (digitalRead(2) == HIGH); // wait for button release
      break; // exit the loop when button is pressed
    }
  }
}

void perguntas(char *pergunta, char *pergunta_desc, int resposta, int &pontuacao) {
  int estadoBotaoSim = 0;
  int estadoBotaoNao = 0;
  int estadoBotaoPular = 0; // Novo botão para pular a pergunta
  int segundos = 0;
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(pergunta);
  lcd.setCursor(0, 1);
  lcd.print(pergunta_desc);
  
  estadoBotaoSim = digitalRead(10);
  estadoBotaoNao = digitalRead(9);
  estadoBotaoPular = digitalRead(8); // Lê o estado do botão de pular pergunta
  segundos = 0;
  
  // Loop para aguardar uma resposta ou o botão de pular ser pressionado
  while (segundos < tempoMaximo && estadoBotaoSim == LOW && estadoBotaoNao == LOW && estadoBotaoPular == LOW) {
    delay(1000);
    segundos += 1000;
    estadoBotaoSim = digitalRead(10);
    estadoBotaoNao = digitalRead(9);
    estadoBotaoPular = digitalRead(8); // Atualiza o estado do botão de pular pergunta
  }
  
  // Verifica se o botão de pular foi pressionado e se ainda há pulos disponíveis
  if (estadoBotaoPular == HIGH && pulosUtilizados < 3) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Pergunta pulada!");
    delay(2000);
    pulosUtilizados++; // Incrementa o contador de pulos utilizados
    return; // Retorna para a função loop() para avançar para a próxima pergunta
  }
  if((segundos > tempo_led)){
  		digitalWrite(7,HIGH);
    	tone(buzzer,900);
    	delay(250);
    	digitalWrite(7, LOW);
    	delay(250);
    	digitalWrite(7,HIGH);
    	delay(250);
    	digitalWrite(7, LOW);
      	delay(250);
        digitalWrite(7,HIGH);
    	delay(250);
    	digitalWrite(7, LOW);
    	delay(250);
    	digitalWrite(7,HIGH);
    	delay(250);
    	digitalWrite(7, LOW);
      	delay(250);
    	noTone(buzzer);
    	
  
  }
  if((segundos > tempo_led)){
  		
  		
  }
  
  // Verifica se o tempo acabou ou se a resposta está correta
  if ((estadoBotaoSim == HIGH && resposta == 1) || (estadoBotaoNao == HIGH && resposta == 0)) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Correto!       ");
    tone(buzzer,262);
  	delay(1000);
    pontuacao++;
    lcd.setCursor(0, 1);
    lcd.print("Pontuacao: ");
    lcd.print(pontuacao);
    noTone(buzzer);
  } else if (segundos == tempoMaximo) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Tempo Esgotado!     ");
    tone(buzzer,430);
  	delay(1000);
    noTone(buzzer);
    // Reinicia o jogo
    reiniciarJogo();
  } else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Perdeu !");
   	tone(buzzer,100);
  	delay(1000);
    noTone(buzzer);
    // Reinicia o jogo
    reiniciarJogo();
  }
}

// Função para reiniciar o jogo
void reiniciarJogo() {
  pontuacaoFacil = 0;
  pontuacaoMedio = 0;
  pontuacaoDificil = 0;
  pulosUtilizados = 0; // Reinicia o contador de pulos utilizados
  telaInicio();
}

// Função para mostrar a pontuação acumulada
void mostrarPontuacaoAcumulada(int pontuacao) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("TOTAL:");
  lcd.setCursor(0, 1);
  lcd.print(pontuacao);
  delay(3000);
}
