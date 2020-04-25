#include "snake.h"
#include <cmath>
#include <iostream>

Snake::Snake(){};
void Snake::Update()
{
  SDL_Point prev_cell{
      static_cast<int>(head_x),
      static_cast<int>(
          head_y)}; // We first capture the head's cell before updating.

  UpdateHead();
  SDL_Point current_cell{
      static_cast<int>(head_x),
      static_cast<int>(head_y)}; // Capture the head's cell after updating.

  // Update all of the body vector items if the snake head has moved to a new
  // cell.
  if (current_cell.x != prev_cell.x || current_cell.y != prev_cell.y)
  {
    UpdateBody(current_cell, prev_cell);
  }

  //std::cout<<" diff x :: "<< abs(current_cell_float.x - prev_cell_float.x) << " diff y :: "<< abs(current_cell_float.y - prev_cell_float.y) <<std::endl;
}

float Snake::head_total_distance = 0;

void Snake::UpdateHead()
{
  switch (direction)
  {
  case Direction::kUp:
    head_y -= speed;
    break;

  case Direction::kDown:
    head_y += speed;
    break;

  case Direction::kLeft:
    head_x -= speed;
    break;

  case Direction::kRight:
    head_x += speed;
    break;
  }

  // Wrap the Snake around to the beginning if going off of the screen.
  head_x = fmod(head_x + grid_width, grid_width);
  head_y = fmod(head_y + grid_height, grid_height);

  //std::cout<<"TRAVEL :: x : "<< head_x  << "  :: y :: "<< head_y<< std::endl;

  HeadDistanceTravel(head_total_distance, head_x, head_y, x_prev, y_prev);

  //std::cout << "head distance  :::" << head_total_distance << std::endl;
}
//-------------------------------------------------------------------------------
void Snake::HeadDistanceTravel(float &h_tot_dist, float h_x, float head_y, float &x_prev, float &y_prev)
{

  h_tot_dist = h_tot_dist + abs(head_x - x_prev) + abs(head_y - y_prev);
  x_prev = head_x;
  y_prev = head_y;
}

void Snake::UpdateBody(SDL_Point &current_head_cell, SDL_Point &prev_head_cell)
{
  // Add previous head location to vector
  body.push_back(prev_head_cell);

  if (!growing)
  {
    // Remove the tail from the vector.
    body.erase(body.begin());
  }
  else
  {
    growing = false;
    size++;
  }

  // Check if the snake has died.
  for (auto const &item : body)
  {
    if (current_head_cell.x == item.x && current_head_cell.y == item.y)
    {
      alive = false;
    }
  }
}

void Snake::GrowBody() { growing = true; }

// Inefficient method to check if cell is occupied by snake.
bool Snake::SnakeCell(int x, int y)
{
  if (x == static_cast<int>(head_x) && y == static_cast<int>(head_y))
  {
    return true;
  }
  for (auto const &item : body)
  {
    if (x == item.x && y == item.y)
    {
      return true;
    }
  }
  return false;
}