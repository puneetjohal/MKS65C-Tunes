#include <stdio.h>
#include <string.h>
#include "ll.c"
#include "tunes.h"
#include <time.h>
#include <stdlib.h>

struct song_node * add_node(struct song_node * table[27], char * title, char * artist)
{
  char c = artist[0];
  int pos;
  struct song_node * head;
  if (c >= 'a' && c <= 'z')
    pos = artist[0] - 'a';
  else if (c >= 'A' && c <= 'Z')
    pos = artist[0] - 'A';
  else
    pos = 26;
  head = table[pos];
  table[pos] = insert_order(head, title, artist);
  return table[pos];
}

struct song_node * find_song(struct song_node * table[27], char * title, char * artist){
  struct song_node * head;
  char c = artist[0];
  if (c >= 'a' && c <= 'z')
    head = table[artist[0] - 'a'];
  else if (c >= 'A' && c <= 'Z')
    head = table[artist[0] - 'A'];
  else
    head = table[26];
  return find(head,title,artist);
}

struct song_node * find_by_artist(struct song_node * table[27], char * artist){
  struct song_node * head;
  char c = artist[0];
  if (c >= 'a' && c <= 'z')
    head = table[artist[0] - 'a'];
  else if (c >= 'A' && c <= 'Z')
    head = table[artist[0] - 'A'];
  else
    head = table[26];
  return by_artist(head,artist);
}

void print_letter(struct song_node * table[27], char c){
  if (c >= 'a' && c <= 'z')
    print_list(table[c - 'a']);
  else if (c >= 'A' && c <= 'Z')
    print_list(table[c - 'A']);
  else
    print_list(table[26]);
}

void print_artist(struct song_node * table[27], char * name){
  struct song_node * curr = find_by_artist(table, name);
  while (curr && ! strcmp(curr->artist, name))
  {
    printf("%s by %s\n", curr->name, curr->artist);
    curr = curr->next;
  }
}

void print_all(struct song_node * table[27]){
  int i;
  for (i = 0; i <= 26; i++)
  {
    if (table[i])
    {
      printf("%c\n", 'A' + i);
      print_list(table[i]);
    }
  }
}

void shuffle(struct song_node * table[27]){
  srand( time(NULL) );
  struct song_node * curr;
  int i = 0;
  while (i < 10){
    int letter = rand() % 27;
    if (table[letter])
    {
      curr = random_song(table[letter]);
      printf("%s by %s\n", curr->name, curr->artist);
      i++;
    }
  }
}

void deleter(struct song_node * table[27], char * title, char * artist)
{
  struct song_node * head = find_song(table, title, artist);
  remove_song(head, title, artist);
}

void clear(struct song_node * table[27]){
  int i;
  for (i = 0; i < 27; i++)
  {
    free_list(table[i]);
  }
}
