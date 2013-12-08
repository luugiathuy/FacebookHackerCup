#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>

using namespace std;

struct Cell
{
  int r,c;
  Cell (int r_, int c_) : r(r_), c(c_) {}
};

struct Path
{
  vector<Cell> cells;
  int dir; // 0: right, 1: down, 2: up, 3: left
  bool noMoreUpLeft;
};

const int ROW_OFFSET[4] = {0, 1, -1, 0};
const int COL_OFFSET[4] = {1, 0, 0, -1};

int main()
{
  int T;
  cin >> T;

  for (int k=1; k<=T; ++k)
  {
    int N,M;
    cin >> N >> M;

    std::vector< string > A;
    A.resize(N);
    for(int i=0; i<N; ++i)
    {
      cin >> A[i];
    }

    queue<Path> pathQueue;

    Cell startCell(0,0);

    if (M > 1 && A[0][1] == '.') {
      Path path;
      Cell cell(0,1);
      path.cells.push_back(startCell);
      path.cells.push_back(cell);
      path.dir = 0;
      path.noMoreUpLeft = false;
      pathQueue.push(path);
    }

    if (N > 1 && A[1][0] == '.') {
      Path path;
      Cell cell(1,0);
      path.cells.push_back(startCell);
      path.cells.push_back(cell);
      path.dir = 1;
      path.noMoreUpLeft = false;
      pathQueue.push(path);
    }

    int bestPath = 1;
    while (!pathQueue.empty())
    {
      Path currentPath = pathQueue.front();
      pathQueue.pop();

      if (currentPath.cells.size() > bestPath)
      {
        bestPath = currentPath.cells.size();
      }

      Cell lastCell = currentPath.cells[currentPath.cells.size()-1];

      for (int i=0; i<4; ++i)
      {
        bool isReverseDir = (i == 3 - currentPath.dir);
        if (isReverseDir) {
          continue;
        }

        int nextCellR = lastCell.r + ROW_OFFSET[i];
        int nextCellC = lastCell.c + COL_OFFSET[i];

        bool invalidCell = (nextCellR < 0 || N <= nextCellR || nextCellC < 0 || M <= nextCellC || A[nextCellR][nextCellC] != '.');
        if (invalidCell) {
          continue;
        }

        bool invalidUp = (i==2 && currentPath.dir != 2 && currentPath.noMoreUpLeft);
        if (invalidUp) {
          continue;
        }

        bool invalidLeft = (i==3 && currentPath.dir != 3 && currentPath.noMoreUpLeft);
        if (invalidLeft) {
          continue;
        }

        Path newPath;
        if (i == 2 || i == 3) {
          newPath.noMoreUpLeft = true;
        } else {
          newPath.noMoreUpLeft = currentPath.noMoreUpLeft;
        }

        newPath.dir = i;
        newPath.cells = currentPath.cells;
        newPath.cells.push_back(Cell(nextCellR, nextCellC));
        pathQueue.push(newPath);
      }
    }

    cout << "Case #" << k << ": " << bestPath << endl;
  }
  return 0;
}
