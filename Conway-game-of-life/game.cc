#include<iostream>
#include<vector>
#include<unistd.h>
using namespace std;
#define CTRL(x) (#x[0]-'a'+1)

int dx[8] = {0,0,-1,-1,-1,1,1,1};
int dy[8] = {-1,1,0,-1,1,0,-1,1};

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int count_neighbors(int r, int c, const vector<vector<int>> &mat){
    int ans = 0;
    for(int k = 0; k < 8; k++){
        int x = r + dx[k];
        int y = c + dy[k];
        if(x < 0 || x >= mat.size() || y < 0 || y >= mat[0].size())
            continue;
        ans += mat[x][y] == 1;
    }
    return ans;
}

void next_iteration(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> next_mat(n, vector<int> (m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int c = count_neighbors(i,j, mat);
            if(mat[i][j] && (c == 2 || c == 3)) next_mat[i][j] = 1;
            else if(not mat[i][j] && c == 3) next_mat[i][j] = 1;
            else next_mat[i][j] = 0;
        }
    }
    mat = next_mat;
}

void display(const vector<vector<int>> &mat){
  for (int i = 0; i < mat.size(); i++) {
    for (int j = 0; j < mat[0].size(); j++) {
      cout<<(mat[i][j] ? '*' : ' ')<<' ';
    }
    cout<<endl;
  }
  cout<<endl;
}

void random_fill(vector<vector<int>> &mat){
  for (int i = 0; i < mat.size(); i++) {
    for (int j = 0; j < mat[0].size(); j++) {
      mat[i][j] = rand(0,1);
    }
    cout<<endl;
  }
}
int32_t main(int argc, char const *argv[]){
  if(argc == 2)  // random seed that you can pass like ./a.out 42
    srand(atoi(argv[1]));
  else
    srand(42);
  vector<vector<int>> mat(30, vector<int>(40));
  random_fill(mat);
  while(true){
    display(mat);
    next_iteration(mat);
    usleep(49999);
    cout<<CTRL('Z');
  }
  return 0;
}
