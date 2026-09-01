class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        // litterId[i][j] = bit assigned to this litter
        vector<vector<int>> litterId(m, vector<int>(n, -1));

        int startRow = 0, startCol = 0;
        int litterCount = 0;

        // Find start position and assign an ID to every litter cell
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    startRow = i;
                    startCol = j;
                } 
                else if (classroom[i][j] == 'L') {
                    litterId[i][j] = litterCount++;
                }
            }
        }

        // No litter to collect
        if (litterCount == 0) return 0;

        int fullMask = (1 << litterCount) - 1;

        /*
            visited[row][col][remainingEnergy][mask]

            mask stores collected litter:
            bit = 1 -> collected
            bit = 0 -> not collected
        */
        vector visited(
            m,
            vector(
                n,
                vector(
                    energy + 1,
                    vector<bool>(1 << litterCount, false)
                )
            )
        );

        // {row, col, remainingEnergy, collectedMask}
        queue<tuple<int, int, int, int>> q;

        q.push({startRow, startCol, energy, 0});
        visited[startRow][startCol][energy][0] = true;

        int moves = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            int size = q.size();

            // Process all states reachable in exactly `moves` steps
            while (size--) {
                auto [row, col, currentEnergy, mask] = q.front();
                q.pop();

                if (mask == fullMask) {
                    return moves;
                }

                // Cannot make another move
                if (currentEnergy == 0) continue;

                for (int k = 0; k < 4; k++) {
                    int nr = row + dr[k];
                    int nc = col + dc[k];

                    // Invalid position or obstacle
                    if (nr < 0 || nr >= m ||
                        nc < 0 || nc >= n ||
                        classroom[nr][nc] == 'X') {
                        continue;
                    }

                    // Moving costs 1 energy
                    int nextEnergy = currentEnergy - 1;

                    // Reset area restores energy after reaching it
                    if (classroom[nr][nc] == 'R') {
                        nextEnergy = energy;
                    }

                    int nextMask = mask;

                    // Collect litter
                    if (classroom[nr][nc] == 'L') {
                        int id = litterId[nr][nc];
                        nextMask |= (1 << id);
                    }

                    if (!visited[nr][nc][nextEnergy][nextMask]) {
                        visited[nr][nc][nextEnergy][nextMask] = true;
                        q.push({nr, nc, nextEnergy, nextMask});
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};