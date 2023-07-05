#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void bfs(vector<vector<int> >& graph, int start) {
    int n = graph.size();
    vector<bool> visited(n, false); // Menandai simpul yang sudah dikunjungi
    queue<int> q; // Membuat antrian untuk traversal BFS

    visited[start] = true; // Menandai simpul awal sebagai sudah dikunjungi
    q.push(start); // Menambahkan simpul awal ke dalam antrian

    while (!q.empty()) {
        int current = q.front(); // Mengambil simpul saat ini dari depan antrian
        q.pop(); // Menghapus simpul saat ini dari antrian

        cout << current << " "; // Menampilkan simpul yang sedang dikunjungi

        // Melakukan traversal ke semua simpul tetangga yang belum dikunjungi
        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = true; // Menandai simpul tetangga sebagai sudah dikunjungi
                q.push(i); // Menambahkan simpul tetangga ke dalam antrian
            }
        }
    }
}

int main() {
    int n, start;
    cout << "Masukkan jumlah simpul dalam graph: ";
    cin >> n;

    vector<vector<int> > graph(n, vector<int>(n, 0));

    cout << "Masukkan matriks ketetanggaan (0 atau 1):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    cout << "Masukkan simpul awal: ";
    cin >> start;

    cout << "Hasil traversal BFS: ";
    bfs(graph, start);

    return 0;
}
