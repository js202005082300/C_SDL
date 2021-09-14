#ifndef __UTIL__H__
#define __UTIL__H__

#define SIDE_PLAYER 0
#define SIDE_ALIEN  1

int collision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2);
int min(int a, int b);
int max(int a, int b);

#endif