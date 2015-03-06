#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LENGTH 99

#define MODEL_START 0
#define MODEL_LENGTH 19
#define PRICE_START 20
#define PRICE_LENGTH 9
#define WEIGHT_START 30
#define WEIGHT_LENGTH 9

#define SIZE_START 40
#define SIZE_LENGTH 19
#define FREQUENCY_CPU_START 60
#define FREQUENCY_CPU_LENGTH 4
#define RAM_START 65
#define RAM_LENGTH 4

#define MOMORY_VIDIO_START 70
#define MOMORY_VIDIO_LENGTH 4
#define DISPLAY_START 75
#define DISPLAY_LENGTH 9
#define FREQUENCY_DISPLAY_START 85
#define FREQUENCY_DISPLAY_LENGTH 4

#define VOLUME_HDD_START 90
#define VOLUME_HDD_LENGTH 9

char* getLinePattern() {
	return "%-19s %-9d %-9.2f %-19s %-4d %-4d %-4d %-9s %-4d %-9.2f\n";
}
 
// Обявляем свой тип
typedef struct {
  char model [20];  
  int price;  
  float weight;   
  char size [20];   
  int frequency_cpu;   
  int RAM;      
  int memory_video;    
  char display_size [10];  
  int frequency_display;   
  float volume_hdd;  
} Laptop;


void output_list(char *filename, int n, Laptop *laptops){
  FILE *newfile;
  newfile = fopen(filename,"w");

  int i;
  for(i = 0; i < n; i++) {
	fprintf(newfile,getLinePattern(),
	  laptops[i].model,laptops[i].price,laptops[i].weight,laptops[i].size,laptops[i].frequency_cpu,laptops[i].RAM,laptops[i].memory_video,laptops[i].display_size,laptops[i].frequency_display,laptops[i].volume_hdd);
  }

  fclose (newfile);
}

void print_list(int n, Laptop *laptops){
   
  int i;
  for(i = 0; i < n; i++) {
    printf(getLinePattern(),
      laptops[i].model,laptops[i].price,laptops[i].weight,laptops[i].size,laptops[i].frequency_cpu,laptops[i].RAM,laptops[i].memory_video,laptops[i].display_size,laptops[i].frequency_display,laptops[i].volume_hdd);
  }
}

Laptop laptop_new(char *model,int price, float weight, char *size, int frequency_cpu, int RAM, int memory_video, char *display_size, int frequency_display, float volume_hdd) {
  Laptop a;
  strcpy(a.model,model);
  a.price = price;
  a.weight = weight;
  strcpy(a.size,size);
  a.frequency_cpu = frequency_cpu;
  a.RAM = RAM;
  a.memory_video = memory_video;
  strcpy(a.display_size,display_size);
  a.frequency_display = frequency_display;
  a.volume_hdd = volume_hdd;
  return a;
}

void input_data (char *filename, int n, Laptop laptops[n], int *size){
  
  FILE *in;
  in = fopen(filename,"r");
  char str[LINE_LENGTH+2];

  char tmp_model[MODEL_LENGTH+1];  
  char tmp_price[PRICE_LENGTH+1];
  char tmp_weight[WEIGHT_LENGTH+1];
  char tmp_size[SIZE_LENGTH+1];
  char tmp_frequency_cpu[FREQUENCY_CPU_LENGTH+1];
  char tmp_ram[RAM_LENGTH+1];
  char tmp_memory_vidio[MOMORY_VIDIO_LENGTH+1];
  char tmp_display[DISPLAY_LENGTH+1];
  char tmp_frequency_display[FREQUENCY_DISPLAY_LENGTH+1];
  char tmp_volume_hdd[VOLUME_HDD_LENGTH+1];
  
  int i = 0;
  
  while (!feof(in)&&i<n) {  
    // Read one line
    str[0] = '\0';
    fgets(str,LINE_LENGTH+2, in);
    if(strlen(str)<LINE_LENGTH) {
		break;
	} 
	
    str[LINE_LENGTH] = '\0';

    strncpy(tmp_model, &str[MODEL_START], MODEL_LENGTH);
    tmp_model[MODEL_LENGTH] = '\0';
    strncpy(tmp_price, &str[PRICE_START], PRICE_LENGTH);
    tmp_price[PRICE_LENGTH] = '\0';
    strncpy(tmp_weight, &str[WEIGHT_START], WEIGHT_LENGTH);
    tmp_weight[WEIGHT_LENGTH] = '\0';
    strncpy(tmp_size, &str[SIZE_START], SIZE_LENGTH);
    tmp_size[SIZE_LENGTH] = '\0';
    strncpy(tmp_frequency_cpu, &str[FREQUENCY_CPU_START], FREQUENCY_CPU_LENGTH);
    tmp_frequency_cpu[FREQUENCY_CPU_LENGTH] = '\0';
    strncpy(tmp_ram, &str[RAM_START], RAM_LENGTH);
    tmp_ram[RAM_LENGTH] = '\0';
    strncpy(tmp_memory_vidio, &str[MOMORY_VIDIO_START], MOMORY_VIDIO_LENGTH);
    tmp_memory_vidio[MOMORY_VIDIO_LENGTH] = '\0';
    strncpy(tmp_display, &str[DISPLAY_START], DISPLAY_LENGTH);
    tmp_display[DISPLAY_LENGTH] = '\0';
    strncpy(tmp_frequency_display, &str[FREQUENCY_DISPLAY_START], FREQUENCY_DISPLAY_LENGTH);
    tmp_frequency_display[FREQUENCY_DISPLAY_LENGTH] = '\0';
    strncpy(tmp_volume_hdd, &str[VOLUME_HDD_START], VOLUME_HDD_LENGTH);
    tmp_volume_hdd[VOLUME_HDD_LENGTH] = '\0';
  
  
    laptops[i++] = laptop_new(
      tmp_model, atoi(tmp_price), 
      atof(tmp_weight), 
      tmp_size, 
      atoi(tmp_frequency_cpu), 
      atoi(tmp_ram), 
      atoi(tmp_memory_vidio), 
      tmp_display, 
      atoi(tmp_frequency_display), 
      atof(tmp_volume_hdd));
  }  
  *size = i;
  fclose (in);
}

int main() {
	
  Laptop laptops[10];
  int size = 0;
  
  // read data
  input_data("note.txt", 10, laptops, &size);
  
  print_list(size,laptops);
  
  // save to file
  output_list("result.txt", size,laptops);
 
  return 0;
}
