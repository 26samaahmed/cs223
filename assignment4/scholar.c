// Author: Sama Ahmed
// Contact: 26samahmed@csu.fullerton.edu
// Course ID: CPSC223C
// Due Date: 2024-Apr-16 at 11:59 PM
// Program name: Binary

// This program takes the user to input separators. I then print the tokens which is the text in between those
// user-specified separators.

// Program was developed and tested on: Ubuntu

// Programming language: C language
// Date development begun: 2024-Apr-12
// Date of last update:    2024-Apr-16
// Status: Put text in binary file and read it then print to terminal
// Compile:  gcc -c -Wall -m64 -no-pie -o scholar.o scholar.c -lm -std=c2x
// Link:  gcc -m64 -no-pie -o result.out scholar.o -lm -std=c2x

//======== Begin source code ==========

#include <stdio.h> //Provides access to printf and scanf
#include <string.h>
#include <stdlib.h>
#include "student.h"

int main(int argc, char *argv[])
{

  FILE *file; // Pointer to input file
  FILE *binaryFile;
  const unsigned int max_length_file_name = 64;
  char file_name[max_length_file_name];

  printf("%s", "Welcome to Manage Academic Data\n");
  printf("Please enter the name of the text file: ");
  scanf("%s", file_name);

  file = fopen(file_name, "r"); // open the file for reading

  // Prompt the user to enter a valid file name that's in the directory
  while (file == NULL)
  {
    printf("%s", "Sorry. File was not found. Try again.\n");
    printf("Please enter the name of your file: ");
    scanf("%s", file_name);
    file = fopen(file_name, "r"); // open the file for reading
  }


  char *dot;
  dot = strrchr(file_name, '.');
  strcpy(dot, ".bin");
  printf("The file name is %s\n", file_name);
  binaryFile = fopen(file_name, "wb");

  printf("The output file name is %s\n", file_name);

  char name[100];
  unsigned int cwid;
  char major[100];
  unsigned int zip;
  struct Student person;
  char class_level_string[20];

  while (!feof(file))
  {
    fscanf(file, "%s\n%u\n%s\n%s\n%u", name, &cwid, major, class_level_string, &zip);

    if (strcmp(class_level_string, "freshman") == 0)
    {
      person.level = freshman;
    }
    else if (strcmp(class_level_string, "sophomore") == 0)
    {
      person.level = sophomore;
    }
    else if (strcmp(class_level_string, "junior") == 0)
    {
      person.level = junior;
    }
    else if (strcmp(class_level_string, "senior") == 0)
    {
      person.level = senior;
    }
    else
    {
      printf("Invalid class: %s\n", class_level_string);
      continue;
    }
    strcpy(person.name , name), person.cwId = cwid, strcpy(person.major , major), person.zipCode = zip;
    fwrite(&person, sizeof(struct Student), 1, binaryFile);
  }

  fclose(binaryFile);

}
