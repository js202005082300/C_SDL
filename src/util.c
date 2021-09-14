#include "util.h"

int collision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2)
{
	return (max(x1, x2) < min(x1 + w1, x2 + w2)) && (max(y1, y2) < min(y1 + h1, y2 + h2));
}

int min(int a, int b)
{
    if(a > b)
        return b;
    
    return a;
}

int max(int a, int b)
{
    if(a > b)
        return a;
    
    return b;
}
