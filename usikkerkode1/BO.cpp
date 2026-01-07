
#include <stdio.h>
#include <string.h>
#include <windows.h>
HINSTANCE hDll = LoadLibrary("dll.dll");
int main(int argc, char **argv) {
  char string[16] = "";
  strcpy(string, argv[1]);
}
