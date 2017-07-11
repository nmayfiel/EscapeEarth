#ifndef INPUT_HPP
# define INPUT_HPP

typedef struct		s_key
{
	uint32_t ended_down;
	uint32_t changed;
}			t_key;

typedef struct		s_input
{
	// t_key	close;
	t_key	k_up;
	t_key	k_down;
  t_key	k_left;
  t_key	k_right;
  t_key k_space;
  t_key k_enter;
	// t_key	up_arrow;
	// t_key	down_arrow;
	// t_key	left_alt;
	// t_key	right_alt;
	// t_key	enter;
	// t_key	pause;
  // t_key fire;
}			t_input;


#endif
