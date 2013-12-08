#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  int T;
  cin >> T;

  for (int k=1; k<=T; ++k)
  {
    string L;
    long double N;
    cin >> L >> N;
    sort(L.begin(), L.end());

    long double LSize = (long double)L.size();

    int resultSize = 1;
    while (pow(LSize, resultSize) < N)
    {
      N -= pow(LSize, resultSize);
      ++resultSize;
    }

    string resultStr;
    resultStr.resize(resultSize);
    for (int currentPos=1; currentPos<=resultSize; ++currentPos)
    {
      int i=0;
      while (N > pow(LSize, resultSize - currentPos))
      {
        ++i;
        N -= pow(LSize, resultSize - currentPos);
      }
      resultStr[currentPos-1] = L[i];
    }

    cout << "Case #" << k << ": " << resultStr << endl;
  }
  return 0;
}
