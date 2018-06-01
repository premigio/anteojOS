#ifndef SHELL_H
#define SHELL_H

void shell();
void turnOn();
void setPresentatonImageCoordinates(int *x, int*y,int width, int height);
void setNewShell();
void doBeforeExit();
int  parseAndInterpet(char *buffer);


#endif
