
bool isValid(vector<vector<int>> arr, int x, int y){
    if(y == -1) return false;
    if(y == arr.size()) return false;
    
    if(x == -1) return false;
    if(x == arr[0].size()) return false;
    
 return true;    
}
int diagonalDifference(vector<vector<int>> arr) {
    if(arr.size() == 0) return 0;
    
    int s1 = 0;
    
    int x = 0, y = 0;
    
    
    while(isValid(arr, x, y)){
        s1 += arr[y][x];
        x++; y++;
    }
    
    int s2 = 0;
    y = 0, x = arr[0].size() - 1;
    while(isValid(arr, x, y)){
        s2 += arr[y][x];
        x--; y++;
    }
    
    return abs(s1 - s2);
}