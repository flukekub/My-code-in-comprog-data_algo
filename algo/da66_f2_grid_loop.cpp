#include <iostream>
#include <vector>

int ans = 0;
int row, column;
bool isLoop(std::vector<std::vector<int>> &vec, std::vector<std::vector<bool>> &vis, int& startRow, int& startColumn)
{
  // loop clockwise
  //std::cout << "new loop\n";
  //std::cout << "start " << startRow << " " << startColumn <<'\n';
  std::string nextMove = "right";
  int counter = 0;
  int r = startRow;
  int c = startColumn;
  bool completeCycle = true;
  if (vis[r][c]) return false; 
  while (!vis[r][c])
  {
    //std::cout << r << " " << c << " " << vec[r][c] << " moving ";
    //std::cout << nextMove << '\n';
    vis[r][c] = true;
    ++counter;
    if (nextMove == "right")
    {
      if (c+1 == column) 
      {
        completeCycle = false;
        break;
      }
      if (vec[r][c+1] == 1) // left-right tile
      {
        nextMove = "right";
        ++c;
      }
      else if (vec[r][c+1] == 5) // left-down tile
      {
        nextMove = "down";
        ++c;
      }
      else if (vec[r][c+1] == 6) // left-up tile
      {
        nextMove = "up";
        ++c;
      }
      else
      {
        completeCycle = false;
        break;
      }
    }
    else if (nextMove == "down")
    {
      if (r+1 == row)
      {
        completeCycle = false;
        break;
      }
      if (vec[r+1][c] == 2) // up-down tile
      {
        nextMove = "down";
        ++r;
      }
      else if (vec[r+1][c] == 3)
      {
        nextMove = "right";
        ++r;
      }
      else if (vec[r+1][c] == 6)
      {
        nextMove = "left";
        ++r;
      }
      else
      {
        completeCycle = false;
        break;
      }
    }
    else if (nextMove == "left")
    {
      if (c-1 < 0)
      {
        completeCycle = false;
        break;
      }
      if (vec[r][c-1] == 1)
      {
        nextMove = "left";
        --c;
      }
      else if (vec[r][c-1] == 3)
      {
        nextMove = "up";
        --c;
      }
      else if (vec[r][c-1] == 4)
      {
        nextMove = "down";
        --c;
      }
      else
      {
        completeCycle = false;
        break;
      }
    }
    else if (nextMove == "up")
    {
      if (r-1 < 0)
      {
        completeCycle = false;
        break;
      }
      if (vec[r-1][c] == 2)
      {
        nextMove = "up";
        --r;
      }
      else if (vec[r-1][c] == 4)
      {
        nextMove = "right";
        --r;
      }
      else if (vec[r-1][c] == 5)
      {
        nextMove = "left";
        --r;
      }
      else
      {
        completeCycle = false;
        break;
      }
    }
  }
  
  if (r != startRow || c != startColumn)
    return false;


  if (completeCycle)
    if (counter > ans)
      ans = counter;
  
  return completeCycle;
} 

int main()
{
  std::ios_base::sync_with_stdio(false); std::cin.tie(0);
  std::cin >> row >> column;
  std::vector<std::vector<int>> vec(row, std::vector<int> (column));
  std::vector<std::vector<bool>> vis(row, std::vector<bool> (column));
  std::vector<std::pair<int,int>> FoursVector;
  for (int r = 0; r < row; ++r)
  {
    for (int c = 0; c < column; ++c)
    {
      std::cin >> vec[r][c];
      if (vec[r][c] == 4)
      {
        FoursVector.push_back({r,c});
      }
    }
  }

  int numberOfLoops = 0;
  for (int i = 0; i < FoursVector.size(); ++i)
  {
    if (isLoop(vec, vis, FoursVector[i].first, FoursVector[i].second))
      ++numberOfLoops;
  }

  std::cout << numberOfLoops << " " << ans;
}
