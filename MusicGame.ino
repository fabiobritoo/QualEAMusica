// C++ code
//
#include <LiquidCrystal_I2C.h>

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


// DEFINIÇÕES
#define endereco  0x27 // Endereços comuns: 0x27, 0x3F
#define colunas   16
#define linhas    2


const int quantidade_notas = 100;


// Variáveis da Música
int notes = 0;
// this calculates the duration of a whole note in ms
int wholenote = 0;
int divider = 0, noteDuration = 0;



int seconds = 0;
int tempo = 100;
int melody[quantidade_notas];


String nome_musica = "";

String nomes_musicas[] = {"Sonic", "Mario","Tetris"};
int quantidade_musicas = 3;
int numero_musica = random(0,quantidade_musicas);

int musica_sonic[] = { //15 Notas
  REST,2, NOTE_D5,8, NOTE_B4,4, NOTE_D5,8, //1
  NOTE_CS5,4, NOTE_D5,8, NOTE_CS5,4, NOTE_A4,2, 
  REST,8, NOTE_A4,8, NOTE_FS5,8, NOTE_E5,4, NOTE_D5,8,
  NOTE_CS5,4, NOTE_D5,8, NOTE_CS5,4, NOTE_A4,2, 
  REST,4, NOTE_D5,8, NOTE_B4,4, NOTE_D5,8,
  NOTE_CS5,4, NOTE_D5,8, NOTE_CS5,4, NOTE_A4,2, 

  REST,8, NOTE_B4,8, NOTE_B4,8, NOTE_G4,4, NOTE_B4,8, //7
  NOTE_A4,4, NOTE_B4,8, NOTE_A4,4, NOTE_D4,2,
  REST,4, NOTE_D5,8, NOTE_B4,4, NOTE_D5,8,
  NOTE_CS5,4, NOTE_D5,8, NOTE_CS5,4, NOTE_A4,2, 
  REST,8, NOTE_A4,8, NOTE_FS5,8, NOTE_E5,4, NOTE_D5,8,
  NOTE_CS5,4, NOTE_D5,8, NOTE_CS5,4, NOTE_A4,2
};  


int musica_mario[] = { //15 Notas
  NOTE_E5,8, NOTE_E5,8, REST,8, NOTE_E5,8, REST,8, NOTE_C5,8, NOTE_E5,8, //1
  NOTE_G5,4, REST,4, NOTE_G4,8, REST,4, 
  NOTE_C5,-4, NOTE_G4,8, REST,4, NOTE_E4,-4, // 3
  NOTE_A4,4, NOTE_B4,4, NOTE_AS4,8, NOTE_A4,4,
  NOTE_G4,-8, NOTE_E5,-8, NOTE_G5,-8, NOTE_A5,4, NOTE_F5,8, NOTE_G5,8,
  REST,8, NOTE_E5,4,NOTE_C5,8, NOTE_D5,8, NOTE_B4,-4,
  NOTE_C5,-4, NOTE_G4,8, REST,4, NOTE_E4,-4, // repeats from 3
  NOTE_A4,4, NOTE_B4,4, NOTE_AS4,8, NOTE_A4,4,
  NOTE_G4,-8, NOTE_E5,-8, NOTE_G5,-8, NOTE_A5,4, NOTE_F5,8, NOTE_G5,8,
  REST,8, NOTE_E5,4,NOTE_C5,8, NOTE_D5,8, NOTE_B4,-4
};  

int musica_tetris[] = { //15 Notas
  NOTE_E5, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_C5,8,  NOTE_B4,8,
  NOTE_A4, 4,  NOTE_A4,8,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
  NOTE_B4, -4,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
  NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,8,  NOTE_A4,4,  NOTE_B4,8,  NOTE_C5,8,

  NOTE_D5, -4,  NOTE_F5,8,  NOTE_A5,4,  NOTE_G5,8,  NOTE_F5,8,
  NOTE_E5, -4,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
  NOTE_B4, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
  NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,4, REST, 4,

  NOTE_E5, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_C5,8,  NOTE_B4,8,
  NOTE_A4, 4,  NOTE_A4,8,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
  NOTE_B4, -4,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
  NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,8,  NOTE_A4,4,  NOTE_B4,8,  NOTE_C5,8,

  NOTE_D5, -4,  NOTE_F5,8,  NOTE_A5,4,  NOTE_G5,8,  NOTE_F5,8,
  NOTE_E5, -4,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
  NOTE_B4, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
  NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,4, REST, 4
};  

int buzzer = 8;

LiquidCrystal_I2C lcd(endereco, colunas, linhas);

void setup()
{
  Serial.begin(9600);
  
  // Intro
  
  
  lcd.init();
  lcd.backlight();
  lcd.clear();
  escrever("Jogo",0);
  escrever("Qual e a musica?",1);
  delay(3000);
  piscar_tela(100,3);
  lcd.clear();
  
  Serial.println("Inicio");
  //Inicio do Jogo
  // escolher_musica(random(2)); 
    
  
}

void loop()
{ 
  Serial.println("Entrou no loop");
  numero_musica = random(0,quantidade_musicas);
  Serial.println("Musica: " + String(numero_musica));
  escolher_musica(numero_musica); 

  delay(2000); 
  lcd.clear();

}

// Function to copy 'len' elements from 'src' to 'dst'
void copy(int* src, int* dst, int len) {
    memcpy(dst, src, sizeof(src[0])*len);
}

void escolher_musica(int musica)
{   
  Serial.println("Entrou no escolher musica");
  nome_musica = nomes_musicas[musica];
  Serial.println("Nome: " + nome_musica);

  if (musica == 0) {
    tempo = 100;    
    copy(musica_sonic, melody, quantidade_notas);      
  }
  else if (musica == 1) {
    tempo = 150;    
    copy(musica_mario, melody, quantidade_notas);      
  }
  else if (musica == 2) {
    tempo = 144;    
    copy(musica_tetris, melody, quantidade_notas);      
  }
  else { 
    tempo = 150;    
    copy(musica_mario, melody, quantidade_notas);     
  }

  notes = sizeof(melody) / sizeof(melody[0]) / 2;

  // Decidir a outra resposta
  int nome_errado = random(0,quantidade_musicas);
  Serial.println("Nome Errado Inicial: " + String(nome_errado));

  while (nome_errado == musica){
    nome_errado = random(0,quantidade_musicas);
  }
  // Decidir se a resposta fica na posição a ou b

  Serial.println("Pos Nome Errado: " + String(nome_errado));
  Serial.println("Nome Errado: " + nomes_musicas[nome_errado]);

  int pos = random(0,2);

  if (pos == 1){
    escrever("a) " + nome_musica,0);
    escrever("b) " + nomes_musicas[nome_errado],1);
    // escrever("b) Sonic",1);
  } else{
    escrever("a) " + nomes_musicas[nome_errado],0);
    escrever("b) " + nome_musica,1);
  }  

  tocar_musica(notes, melody, tempo, nome_musica);
  
}

void tocar_musica(int notes, int melody[], int tempo, String nome_musica)
{
 
  Serial.println("Nome:" + nome_musica);
  /*Serial.println("Melodia Inicial:" + String(melody[0])); 
  Serial.println("Tempo:" + String(tempo));
  Serial.println("Nome:" + nome_musica);
  Serial.println("Notes:" + String(notes));  */

  wholenote = (60000 * 4) / tempo;
  divider = 0;
  noteDuration = 0;

  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {

    // calculates the duration of each note

    divider = melody[thisNote + 1];
    if (divider > 0) {
      // regular note, just proceed
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      // dotted notes are represented with negative durations!!
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // increases the duration in half for dotted notes
    }

    // we only play the note for 90% of the duration, leaving 10% as a pause
    tone(buzzer, melody[thisNote], noteDuration * 0.9);

    // Wait for the specief duration before playing the next note.
    delay(noteDuration);

    // stop the waveform generation before the next note.
    noTone(buzzer);
  }


}

void escrever (String text, int pos)
{
  lcd.setCursor(0, pos);
  lcd.print(text);
  delay(1000);
}

void piscar_tela(int wait_time, int times)
{
  for (int i = 1; i<=times; i++)
  {
    lcd.noBacklight();
    delay(wait_time); // Wait for 500 millisecond(s)
    lcd.backlight();
    delay(wait_time); // Wait for 500 millisecond(s)
  }
}

