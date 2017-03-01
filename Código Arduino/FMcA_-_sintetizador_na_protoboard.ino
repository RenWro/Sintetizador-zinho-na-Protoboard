/*
 Piano na protoboard - funcao tone()
 
 Este tutorial e um oferecimento do site Musico Nerd, por Gustavo Silveira.
 
 http://www.musiconerd.com
 
 */
#include "pitches.h" //biblioteca que converte frenqueencia para nome de nota


const int noteNumber = 5; // numero de notas que serao usadas
int speakerPin = 8; // pino do auto-falante
int buttonPin[noteNumber] = {2, 3, 4, 5, 6}; //Pinos onde serao ligados os botoes
int note[noteNumber] = {NOTE_G3, NOTE_A3, NOTE_C4, NOTE_E4, NOTE_G4}; // notas que serao tocada

//
int buttonPState[noteNumber] = {0}; //estado previo do botao
int buttonCState[noteNumber] = {0}; // estado atual do botao


void setup() {
  for (int i=0; i<noteNumber; i++){
    pinMode(buttonPin[i], INPUT_PULLUP);
  }  // inicializa os pull up resistors
  Serial.begin(9600); //para debug apenas
}

void loop() {

  // le e marmazena o estado de todos os botoes
  for (int i=0; i<noteNumber; i++) {
    buttonCState[i] = digitalRead(buttonPin[i]);
  }


  for (int i=0; i < noteNumber; i++) {

    if (buttonCState[i] != buttonPState[i]) { // avalia se o estado atual do botao e diferente do anterior

      if (buttonCState[i] == LOW) { //se o estado do botao for LOW (pull up resistor) ativa afuncao tone
        tone(speakerPin, note[i]); // funcao tone tone(pino do auto falante, nota)
        buttonPState[i] = buttonCState[i]; //armazena o estado atual no estado previo
      }
      else {
        noTone(speakerPin); // corta a nota
        buttonPState[i] = buttonCState[i];
      }
    }
  }

}



