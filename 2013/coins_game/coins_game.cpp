#include <iostream>

using namespace std;

int main()
{
  int T;
  cin >> T;
  for (int k=1; k<=T; ++k)
  {
    unsigned int N,K,C;
    cin >> N >> K >> C;
    unsigned long bestResult = 0;

    unsigned int minNK = N > K ? K : N;
    for (unsigned int i=minNK; i>=1; --i)
    {
      unsigned long result = C + (N-i);
      if ((K / i) * i < C)
      {
        result += C % i;
      }

      if (result < bestResult || bestResult == 0)
      {
        bestResult = result;
      }
    }

    cout << "Case #" << k << ": " << bestResult << endl;
  }
  return 0;
}
