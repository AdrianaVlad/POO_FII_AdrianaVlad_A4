#include "Canvas.h"
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <stdarg.h>
Canvas::Canvas(int width, int height)
{
	this->maxlin = height;
	this->maxcol = width;
	this->M = (char**)(malloc(height * sizeof(char*)));
	for (int i = 0; i < height; i++)
		this->M[i] = (char*)(malloc(width * sizeof(char)));
}
void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	int i, j;
	for(i=0;i<this->maxlin;i++)
		for (j = 0; j < this->maxcol; j++)
		{
			if((i - x) * (i - x) + (j - y) * (j - y) == ray * ray)
				this->M[i][j] = ch;
			else
----				this->M[i][j] = ' ';
		}
}
void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	int i, j;
	for (i = 0; i < this->maxlin; i++)
		for (j = 0; j < this->maxcol; j++)
		{
			if ((i - x) * (i - x) + (j - y) * (j - y) <= ray * ray)
				this->M[i][j] = ch;
			else
				this->M[i][j] = ' ';
		}
}
void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	Clear();
	int i, j;
	if (left > right || top > bottom || left > this->maxcol || top > this->maxlin) return;
	if(left>=0)
		for (i = std::max(0, top); i < std::min(this->maxlin, bottom); i++)
			this->M[i][left] = ch;
	if(right<= this->maxcol)
		for (i = std::max(0, top); i < std::min(this->maxlin, bottom); i++)
			this->M[i][right] = ch;
	if(top>=0)
		for (j = std::max(0, left); j < std::min(this->maxcol, right); j++)
			this->M[top][j] = ch;
	if (bottom <= this->maxlin)
		for (j = std::max(0, left); j < std::min(this->maxcol, right); j++)
			this->M[bottom][j] = ch;
} 
void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	Clear();
	int i, j;
	if (left > right || top > bottom || left > this->maxcol || top > this->maxlin) return;
	for (i = std::max(0, top); i < std::min(this->maxlin, bottom); i++)
		for (j = std::max(0, left); j < std::min(this->maxcol, right); j++)
			this->M[i][j] = ch;
}
void Canvas::SetPoint(int x, int y, char ch)
{
	Clear();
	this->M[x][y] = ch;
}
void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	Clear();
	int i, j;
	for (i = std::max(0,x1); i <= std::min(this->maxlin,x2); i++)
	{
		j = (y2 - y1) / (x2 - x1) * (i - x1) + y1;
		if(j>=0&&j<=this->maxcol)
			this->M[i][j] = ch;
	}
}
void Canvas::Print()
{
	int i, j;
	for (i = 0; i < this->maxlin; i++)
	{
		for (j = 0; j < this->maxcol; j++)
			printf("%c", this->M[i][j]);
		printf("\n");
	}
}
void Canvas::Clear()
{
	int i, j;
	for (i = 0; i < this->maxlin; i++)
		for (j = 0; j < this->maxcol; j++)
			this->M[i][j] = ' ';
	/* daca am inteles gresit si trebuia free:
	for (int i = 0; i < maxlin; i++)
		free (this->M[i]);
	*/
}