#include <stdio.h>
#include <string.h>
#include <windows.h>

int main() {
  byte teste[26];
  for (int i = 0; i < 54; i++) {
    memcpy(teste + i, "H", 1);
    i++;
    memcpy(teste + i, "E", 1);
    i++;
    memcpy(teste + i, "L", 1);
    i++;
    memcpy(teste + i, "O", 1);
  }
}
