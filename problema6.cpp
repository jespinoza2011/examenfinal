#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int process_dataset(int N, int S, int Q, vector<vector<int>>& queues) {
    int total_time = 0;
    vector<deque<int>> platform_queues(N); 
    deque<int> transport; 
    int current_station = 0; 

    // Process each station
    for (int station = 0; station < N; ++station) {
        int target_station = (station + current_station) % N;
        int move_steps = (target_station >= current_station) ? (target_station - current_station) : (N - current_station + target_station);
        total_time += move_steps * 2; // 2 minutes per step

        while (!queues[station].empty() && transport.size() < S) {
            transport.push_back(queues[station].front());
            queues[station].erase(queues[station].begin());
            total_time++; // Loading time
        }

        int unload_time = 0;
        while (!transport.empty()) {
            int cargo = transport.back();
            transport.pop_back();
            if (cargo == station + 1) {
                unload_time++;
            } else {
                if (platform_queues[station].size() < Q) {
                    platform_queues[station].push_back(cargo);
                    unload_time++;
                }
            }
        }
        total_time += unload_time; 

        current_station = (station + 1) % N;
    }

    return total_time;
}

int main() {
    int T;
    cout << "Input: " << endl;
    cin >> T;

    vector<int> results;

    while (T--) {
        int N, S, Q;
        cin >> N >> S >> Q;

        vector<vector<int>> queues(N);

        for (int i = 0; i < N; ++i) {
            int Qi;
            cin >> Qi;
            queues[i].resize(Qi);
            for (int j = 0; j < Qi; ++j) {
                cin >> queues[i][j];
            }
        }

        int result = process_dataset(N, S, Q, queues);
        results.push_back(result);
    }

    cout << "" << endl;
    cout << "Output: " << endl;
    for (int result : results) {
        cout << result << endl;
    }

    return 0;
}