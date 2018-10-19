#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tunes.c"

//test
int main(){
  printf("LINKED LIST TESTS\n");
  printf("====================================\n");
  struct song_node *head = (struct song_node*)malloc(sizeof(struct song_node)); //allocates memory
  struct song_node song = {"Bohemian Rhapsody", "Queen", NULL};
  head = &song;
  printf("\nTesting insert_front and print_list...\n");
  head = insert_front(head, "Space Oddidity", "David Bowie");
  print_list(head);

  head = insert_order(head, "The Photograph", "Ghost Quartet");
  head = insert_order(head, "Another One Bites the Dust", "Queen");
  head = insert_order(head, "Heart-Shaped Box", "Nirvana");
  printf("\nTesting insert_order...\n");
  print_list(head);

  printf("\nFinding Space Oddidity by David Bowie...\n");
  struct song_node * temp = find(head, "Space Oddidity", "David Bowie");
  printf("%s by %s\n", temp->name, temp->artist);

  printf("\nFinding first song by Queen...\n");
  temp = by_artist(head, "Queen");
  printf("%s by %s\n", temp->name, temp->artist);

  printf("\nFinding a random song...\n");
  temp = random_song(head);
  printf("%s by %s\n", temp->name, temp->artist);

  printf("\nRemoving The Photograph by Ghost Quartet...\n");
  head = remove_song(head, "The Photograph", "Ghost Quartet");
  print_list(head);

  printf("\n\nMUSIC LIBRARY TESTS\n");
  printf("====================================\n");
  int i;
  struct song_node * table[27];
  for (i = 0; i < 27; i++)
  {
    table[i] = NULL;
  }
  add_node(table, "Froot", "Marina and the Diamonds");
  add_node(table, "Hot Knife", "Fiona Apple");
  add_node(table, "Havana", "Camila Cabello");
  add_node(table, "Immortal", "Marina and the Diamonds");
  add_node(table, "Blue", "Marina and the Diamonds");
  add_node(table, "Dear No One", "Tori Kelly");
  add_node(table, "Neon", "John Mayer");
  add_node(table, "Bloom - Bonus Track", "The Paper Kites");
  add_node(table, "Rendez Vous", "Defunk");
  add_node(table, "California Dreamin\'", "The Mamas & The Papas");
  print_all(table);
  printf("\nAll songs by M&theD:\n");
  print_artist(table, "Marina and the Diamonds");
  printf("shuffling...\n");
  shuffle(table);
  printf("deleting California Dreamin\n");
  deleter(table, "California Dreamin\'", "The Mamas & The Papas");
  //printf("deleting Immortal\n");
  //deleter(table, "Immortal", "Marina and the Diamonds");
  print_all(table);
  printf("clearing table");
  clear(table);
  return 0;
}
