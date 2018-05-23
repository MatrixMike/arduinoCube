/*
 * File:    CubeAPItest
 * Version: 1.0
 * Author:  Mike Hewitt
 *
 * as example see entry below on Jon's forum
 * http://forum.freetronics.com/viewtopic.php?f=32&t=5579
 *
 *
 * the cube can still take serial commands during the execution of this program.
 * try feeding it from serial port
 *
 */

#include "SPI.h"
#include "Cube.h"

word timer = 800;
byte rr;
byte gg;
byte bb;


Cube cube;

void setup(void) {
  cube.begin(0, 115200); // Start on serial port 0 (USB) at 115200 baud
}

void loop(void) {

  rr = random(0, 2) * 255;
  gg = random(0, 2) * 255;
  bb = random(0, 2) * 255;


  cubeAll(RGB(00, 00, 00));

  cube.setplane(X, 0, RGB(rr, gg, bb));
  delay(1000);
  cube.setplane(X, 0, RGB(100, 100, 100));
  delay(1000);

  cube.line(0, 0, 0, 2, 2, 2, RGB(255, 00, 00));
  //   delay(1000);

  cube.set(1, 0, 1, RGB(200, 200, 00));
  cube.set(2, 0, 2, RGB(200, 200, 00));
  cube.set(3, 0, 3, RGB(200, 200, 00));

  delay(1000);
  cube.setplane(Z, 0, GREEN);

  delay(1000);
  cube.all(RGB(255, 00, 00));   // changed from cubeAll  to cube.all
  delay(1000);

  for (int c = 0; c < 4; c++) {
    cube.set(c, 0, 1, RGB(00, 200, 00));
    delay(300);
  }
  for (int c = 0; c < 4; c++) {
    cube.set(2, c, 1, RGB(00, 000, 200));
    delay(300);
  }
  cube.all(BLACK);
  // draw a chasing dot around the top
  for (int c = 0; c < 4; c++) {
    cube.set(3, c, 3, RGB(00, 000, 200));
    delay(300);
  }
  for (int c = 0; c < 4; c++) {
    cube.set(0, c, 3, RGB(00, 000, 200));
    delay(300);
  }
  for (int c = 0; c < 4; c++) {
    cube.set(c, 0, 3, RGB(00, 000, 200));
    delay(300);
  }
  for (int c = 0; c < 4; c++) {
    cube.set(4 - c, 3, 3, RGB(00, 000, 200));
    delay(300);
  }
  /*  for (int c = 4; c > 0; c--) {
   *   //  this causes some sort of a crash with a non-changing display and a line of colour that does not appear to have been programmed
      cube.set(c, 0, 2, RGB(200, 100, 00));
      delay(100);
    }
  */
  for (int c = 0; c < 256; c = c + 8) {
    cube.all( RGB(c, 000, 200));
    delay(300);
  }
  for (int c = 0; c < 256; c = c + 8) {
    cube.all( RGB(256 - c, 000, 00));
    delay(300);
  }
  delay(1000);
}



