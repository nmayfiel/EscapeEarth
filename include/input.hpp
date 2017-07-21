#pragma once

struct Key
{
	bool endedDown;
	bool changed;
};

struct	Input
{
	Key	up;
	Key	down;
	Key	left;
	Key	right;
	Key	space;
	Key 	enter;
};
