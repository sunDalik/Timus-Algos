#include <iostream>

using namespace std;

int main() {
    int tests;
    cin >> tests;
    for (int i = 0; i < tests; ++i) {
        int n, k;
        cin >> n >> k;
        int players_per_team = n / k;
        int leftover_players = n % k; // aka "abnormal" teams
        int normal_teams = k - leftover_players;

        // everyone is fighting against every non-ally player
        int total_battles = normal_teams * players_per_team * (n - players_per_team)
                            + leftover_players * (players_per_team + 1) * (n - (players_per_team + 1));

        cout << total_battles / 2 << "\n"; // we counted every battle twice so now we just divide it by 2
    }
}