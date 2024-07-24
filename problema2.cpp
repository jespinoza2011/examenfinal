#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxPasto(vector<int>& pasto) {
    int n = pasto.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<vector<int>> sum(n, vector<int>(n, 0));

    // Inicializar la matriz de sumas parciales
    for (int i = 0; i < n; ++i) {
        sum[i][i] = pasto[i];
        for (int j = i + 1; j < n; ++j) {
            sum[i][j] = sum[i][j - 1] + pasto[j];
        }
    }

    // Inicializar la matriz dp para intervalos de longitud 1
    for (int i = 0; i < n; ++i) {
        dp[i][i] = pasto[i];
    }

    // Llenar la matriz dp para intervalos de longitud mayor a 1
    for (int length = 2; length <= n; ++length) {
        for (int i = 0; i <= n - length; ++i) {
            int j = i + length - 1;
            int left = sum[i][j] - dp[i + 1][j];
            int right = sum[i][j] - dp[i][j - 1];
            dp[i][j] = max(left, right);
        }
    }

    return dp[0][n - 1];
}

int main() {
    int numTests;
    cout << "Input: " << endl;
    std::cin >> numTests;
    
    std::vector<int> results;
    
    for (int t = 0; t < numTests; ++t) {
        int numBlocks;
        std::cin >> numBlocks;
        
        std::vector<int> grassBlocks(numBlocks);
        for (int i = 0; i < numBlocks; ++i) {
            std::cin >> grassBlocks[i];
        }
        
        results.push_back(maxPasto(grassBlocks));
    }
    
    cout << "" << endl;
    cout << "Output: " << endl;

    for (int result : results) {
        std::cout << result << std::endl;
    }
    
    return 0;
}