// C++ code
//
#include <Adafruit_LiquidCrystal.h>

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


// Variáveis da Música
int notes = 0;
// this calculates the duration of a whole note in ms
int wholenote = 0;
int divider = 0, noteDuration = 0;


int seconds = 0;
int tempo = 100;
int melody[30];
int numero_musica = random(1,2);

String nome_musica = "";

int musica1[] = { //15 Notas
  NOTE_C5,4, NOTE_G4,8, NOTE_AS4,4, NOTE_A4,8,
  NOTE_G4,16, NOTE_C4,8, NOTE_C4,16, NOTE_G4,16, NOTE_G4,8, NOTE_G4,16,
  NOTE_C5,4, NOTE_G4,8, NOTE_AS4,4, NOTE_A4,8,
  NOTE_G4,2
};  



int musica2[] = { //15 Notas
  NOTE_AS4,-2,  NOTE_F4,8,  NOTE_F4,8,  NOTE_AS4,8,//1
  NOTE_GS4,16,  NOTE_FS4,16,  NOTE_GS4,-2,
  NOTE_AS4,-2,  NOTE_FS4,8,  NOTE_FS4,8,  NOTE_AS4,8,
  NOTE_A4,16,  NOTE_G4,16,  NOTE_A4,-2,
  REST,1
};  

int buzzer = 11;

Adafruit_LiquidCrystal lcd(0);

void setup()
{
  Serial.begin(9600);
  
  // Intro
  
  /*
  lcd.begin(16, 2);
  lcd.setBacklight(1);
  lcd.clear();
  escrever("Jogo",0);
  escrever("Qual e a musica?",1);
  piscar_tela(100,3);
  lcd.clear();
  */
  
  //Inicio do Jogo
  // escolher_musica(random(2)); 
    
  
}

void loop()
{
  numero_musica = random(1,3);
  escolher_musica(numero_musica); 
  delay(2000);  	

}

// Function to copy 'len' elements from 'src' to 'dst'
void copy(int* src, int* dst, int len) {
    memcpy(dst, src, sizeof(src[0])*len);
}

void escolher_musica(int musica)
{   
  
  if (musica == 1) {
    tempo = 100;
    nome_musica = "Sonic";
    copy(musica1, melody, 30);      
  }
  else { 
    tempo = 88;
    nome_musica = "Mario";
    copy(musica2, melody, 30);     
  }

  notes = sizeof(melody) / sizeof(melody[0]) / 2;

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

    Serial.println("Nota:" + String(melody[thisNote]));
    Serial.println("Duracao:" + String(melody[thisNote + 1]));

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
}

void piscar_tela(int wait_time, int times)
{
  for (int i = 1; i<=times; i++)
  {
    lcd.setBacklight(0);
    delay(wait_time); // Wait for 500 millisecond(s)
    lcd.setBacklight(1);
    delay(wait_time); // Wait for 500 millisecond(s)
  }
}

