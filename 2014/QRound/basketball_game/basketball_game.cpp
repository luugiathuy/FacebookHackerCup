#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Player
{
	string name;
	int shotPercentage;
	int height;

	bool operator<(const Player& other) const
	{
		if ((shotPercentage < other.shotPercentage) || 
			(shotPercentage == other.shotPercentage && height < other.height))
		{
			return true;
		}
		return false;
	}
};
typedef vector<Player> PlayerList;

std::istream& operator>>(std::istream& is, Player& player)
{
  is >> player.name >> player.shotPercentage >> player.height;
  return is;
}

std::ostream& operator<<(std::ostream& os, const Player& player)
{
  os << player.name << " " << player.shotPercentage << " " << player.height << endl;
  return os;
}

int main()
{
	int testCount;
	cin >> testCount;
	string line;

	for (int k=1; k<=testCount; ++k)
	{
		int N,M,P;
		cin >> N >> M >> P;
		
		PlayerList playerList;

		// read players' infos
		playerList.resize(N);
		for (int i=0; i<N; ++i)
		{
			cin >> playerList[i];
		}

		sort(playerList.rbegin(), playerList.rend());

		// divide to two teams
		PlayerList teamOne;
		PlayerList teamTwo;
		for (int i=1; i<=N; ++i)
		{
			if (i%2==1)
			{
				teamOne.push_back(playerList[i-1]);
			}
			else
			{
				teamTwo.push_back(playerList[i-1]);
			}
		}

		// reverse top P players so that we can have queue order
		reverse(teamOne.begin(), teamOne.begin() + P);
		reverse(teamTwo.begin(), teamTwo.begin() + P);

		// Observe that after each team's size minutes, the team queue restart
		PlayerList::iterator teamOneIter = teamOne.begin() + (M % teamOne.size());
		PlayerList::iterator teamTwoIter = teamTwo.begin() + (M % teamTwo.size());

		vector<string> playingPlayerName;

		int count = P;

		while (count > 0)
		{
			if (teamOneIter == teamOne.end())
				teamOneIter = teamOne.begin();

			if (teamTwoIter == teamTwo.end())
				teamTwoIter = teamTwo.begin();

			playingPlayerName.push_back((*teamOneIter).name);
			playingPlayerName.push_back((*teamTwoIter).name);

			++teamOneIter;
			++teamTwoIter;

			--count;
		}

		sort(playingPlayerName.begin(), playingPlayerName.end());

		cout << "Case #" << k << ":";
		for (int i=0; i<playingPlayerName.size(); ++i)
		{
			cout << " " << playingPlayerName[i];
		}
		cout << endl;
	}

	return 0;
}