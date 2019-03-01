#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "ex1.h"

Answer *get_indices_of_item_weights(int *weights, int length, int limit)
{
  HashTable *ht = create_hash_table(16);
  ht->capacity = length;
  ht->storage = malloc(sizeof(int));
  // ht->storage[weights];
  // ht->storage[weights]->key = 
  // ONE LOOP
    for (int i = 1; i < length; i++) {
    int w = weights[i-1];
    int comp_w = limit - w;
    if (comp_w == weights[i]) {
      if (weights[i] > comp_w) {
        int index_1 = weights[i];
        int index_2 = comp_w;
        ht->storage[0]->value = index_1;
        ht->storage[1]->value = index_2;
      } else {
        int index_1 = comp_w;
        int index_2 = weights[i];
        ht->storage[0]->value = index_1;
        ht->storage[1]->value = index_2;
      }

      // return [index_1, index_2];
      
    }
    return ht->storage[2];
  } 
  // NESTED FOR LOOPS
  // if (length < 2) {return NULL;};
  // for (int i = 0; i < length - 1; i++) {
  //   for (int j = i + 1; j< length; j++) {
  //     if (weights[i] + weights[j] == limit) {
  //       if (weights[i] > weights[j]) {
  //         int index_1 = weights[i];
  //         int index_2 = weights[j];
  //         return *Answer(index_1, index_2);
  //       } else {
  //         int index_1 = weights[j];
  //         int index_2 = weights[i];
  //         return *(index_1, index_2);
  //       }
  //     }
  //   }
  // }
  
  return NULL;
}
// input: int *weights = { 4, 6, 10, 15, 16 }, int length = 5, int limit = 21
// output: Answer{ index_1: 3, index_2: 1 }  # since these are the indices of weights 15 and 6 whose sum equals 21
// typedef struct LinkedPair {
//   int key;
//   int value;
//   struct LinkedPair *next;
// } LinkedPair;

// typedef struct HashTable {
//   int capacity;
//   LinkedPair **storage;
// } HashTable;

// typdef struct Answer {
//   int index_1;
//   int index_2;
// } Answer;

void print_answer(Answer *answer)
{
  if (answer != NULL) {
    printf("%d %d\n", answer->index_1, answer->index_2);
  } else {
    printf("NULL\n");
  }
}

#ifndef TESTING
int main(void)
{

  // TEST 1
  int weights_1 = {9};
  Answer *answer_1 = get_indices_of_item_weights(&weights_1, 1, 9);
  print_answer(answer_1);  // NULL

  // TEST 2
  int weights_2[] = {4, 4};
  Answer* answer_2 = get_indices_of_item_weights(weights_2, 2, 8);
  print_answer(answer_2);  // {1, 0}

  // TEST 3
  int weights_3[] = {4, 6, 10, 15, 16};
  Answer* answer_3 = get_indices_of_item_weights(weights_3, 5, 21);
  print_answer(answer_3);  // {3, 1}

  // TEST 4
  int weights_4[] = {12, 6, 7, 14, 19, 3, 0, 25, 40};
  Answer* answer_4 = get_indices_of_item_weights(weights_4, 9, 7);
  print_answer(answer_4);  // {6, 2}

  return 0;
}
#endif
