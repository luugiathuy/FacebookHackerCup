#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

typedef vector< vector<int> > Image;

bool isPerfectSquare(int n)
{
	if (n < 0)
		return false;

	int root = (int)(sqrt(n) + 0.5);
	return root*root == n;
}

bool isSquareShape(const Image &image, int firstRow, int firstCol, int blackCount)
{
	int imageSize = image.size();
	int squareSize = (int)(sqrt(blackCount) + 0.5);

	for (int i=firstRow; i<firstRow+squareSize; ++i)
		for (int j=firstCol; j<firstCol+squareSize; ++j)
		{
			if (i >= imageSize || j >= imageSize)
				return false;

			if (image[i][j] == 0)
				return false;
		}
	return true;
}


int main()
{
	int testCount;
	string line;

	cin >> testCount;

	for (int k=1; k<=testCount; ++k)
	{
		int size;
		cin >> size;
		getline(cin, line); // finish reading line of image size
		
		Image image;
		image.resize(size);

		int firstBlackRow = -1; // row of first black
		int firstBlackCol = -1; // col of first black
		int blackCount = 0;

		for (int i=0; i<size; ++i)
		{
			image[i].resize(size);
			
			getline(cin, line);
			for (int j=0; j<size; ++j)
			{
				if (line[j] == '.')
				{
					image[i][j] = 0;
				}
				else
				{
					image[i][j] = 1;
					++blackCount;
					if (firstBlackRow == -1)
					{
						firstBlackRow = i;
						firstBlackCol = j;
					}
				}
			}
		}

		cout << "Case #" << k << ": ";
		if (isPerfectSquare(blackCount) && isSquareShape(image, firstBlackRow, firstBlackCol, blackCount))
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}

	}
	return 0;
}