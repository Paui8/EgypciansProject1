#include"ModuleBoard.h"

ModuleBoard::ModuleBoard()//parametritzar-- 
{
	int x, y;
	int i = 0;
	int j = 0;
	for (y = 42 * SCREEN_SIZE - 16; j < NUM_SQUARES; y += 14 * SCREEN_SIZE)
	{
		if (i % 2 == 0)
		{
			for (x = 24 * SCREEN_SIZE - 16; x < 290 * SCREEN_SIZE; x += 16 * SCREEN_SIZE)//112
			{
				board.push_back(new iPoint(x, y));
				
				j++;
			}
		}

		else
		{
			for (x = 32 * SCREEN_SIZE - 16; x < 290 * SCREEN_SIZE; x += 16 * SCREEN_SIZE)//96
			{
				board.push_back(new iPoint(x, y));
				
				j++;
			}
		}
		i++;
	}
}




ModuleBoard::~ModuleBoard(){};

bool ModuleBoard::Start(){ return true; };


bool ModuleBoard::CleanUp()
{
	int i;
	for (i = 0; i < NUM_SQUARES; i++)
	{
		if (board[i]->Empty == false)
		{
			board[i]->Empty = true;
			
		}
	}
	return true;
}

void ModuleBoard::CheckPosition(Sphere* actual_sphere)
{
	int i = 0;
	int min_distance;
	int square_index = 0;
	
	min_distance = 100;

	for (i = 0;i< NUM_SQUARES; i++)
	{
		if (board[i]->Empty == true)
		{
			if (board[i]->DistanceTo(actual_sphere->position) < min_distance)
			{
				min_distance = board[i]->DistanceTo(actual_sphere->position);
				square_index = i;
			}
		}
	}
	actual_sphere->position.x = board[square_index]->x;
	actual_sphere->position.y = board[square_index]->y;
	actual_sphere->pos_board.x = board[square_index]->x;
	actual_sphere->pos_board.y = board[square_index]->y;
	board[square_index]->Empty = false;
	actual_sphere->board_index = square_index;
	
}
void ModuleBoard::CreateMap(int number[]){

	int i;
	for (i = 0 ; i < NUM_SQUARES;i++)
	{
		if (number[i] >= 0 && number[i] < 8){
			App->spheres->SetSphere(App->spheres->spheres[number[i]], board[i]->x, board[i]->y, i);
			board[i]->Empty = false;
			}				
		}
}


bool ModuleBoard::CheckWin()
{
	int i = 0;
	for (i = 0; i < NUM_SQUARES; i++)
	{
		if (board[i]->Empty != true)

			return false;
	}

	return true;
}
