#include "dnd_character.h"
#include <stdlib.h> 
#include <time.h>  




int ability(void){
    int min_index = 0;
    int roll[4];
    int result = 0;
    
 //Roll dice 4 times
 for (int i = 0 ; i < 4 ; i++){
    roll[i] = (rand() % 6) + 1;
 }
 //Find minimum and swap to 0
 for (int i = 0 ; i < 4 ; i++) {
    if (roll[i] < roll[min_index]) {
        min_index = i;
    }
  }
    
  roll[min_index] = 0;
  //Sums the roll numbers
  for (int i = 0 ; i < 4 ; i++) {
      result += roll[i];
  }

  return result;
 
    
}
    

int modifier(int score){
    int result = (score - 10) / 2;
    if ((score - 10) < 0 && (score - 10) % 2 != 0) {
        result -= 1;
      }       
    return result;
    }
        
dnd_character_t make_dnd_character(void){
    
    dnd_character_t character;
    
    character.strength = ability();
    character.dexterity = ability();
    character.constitution = ability();
    character.intelligence = ability();
    character.wisdom = ability();
    character.charisma = ability();
    character.hitpoints = 10 + modifier(character.constitution);

    return character;

    
}
