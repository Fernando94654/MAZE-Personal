void ahead(){}
void back(){}
void left(){}
void right(){}
bool paredAdelante(){}
int rows = 0;
int cols = 0;

void girar(int directions[4][2]){
    int tempx = directions[0][0];
    int tempy = directions[0][1];
    for (int i = 0; i< 3; i++){
        directions[i][0] = directions[i+1][0];
        directions[i][1] = directions[i+1][1];
    }
    directions[3][0] = tempx;
    directions[3][1] = tempy;
    left();
}
// arriba, izquierda, abajo, derecha
void search(bool visited[rows][cols], int x, int y, int directions[4][2], int backstep[rows][cols], int& count, bool& pathFound){
    visited[x][y] = true;
    if(!pathFound){
        count++;
        backstep[x][y] = count;
    }
    if(x== rows-1 && y == cols-1){
        pathFound = true; 
    }
    for (int i = 0; i<4; i++){
        int newX = x + directions[0][0];
        int newY = y + directions[0][1];
        if((newX >= 0 && newY >=0 && newX<=rows && newY <= cols) && (paredAdelante() == false)){
            for(int j = 0; j< i-; j++){
                left();
            }
            bool negro = cuadroNegro();
            if(negro == false){
                if(visited[newX][newY] == false){
                    ahead();
                    search(visited, newX, newY, directions, colors, backstep, count, pathFound);
                    back();
                }
            }else{
                visited[newX][newY] = true; 
            } 
        }             
        girar(directions);
    }
    if(!pathFound){
        backstep[x][y] = INT_MAX;
        count--;
    }
}
void fuga(int count, int x, int y, int Mcolor, int directions[4][2], int backstep[5][3]){
    for(int i = 0; i < count; i++){
        for (int j = 0; j < 4; j++){
            int newX = x + directions[0][0];
            int newY = y + directions[0][1];
            if (newX >= 0 && newY >= 0 && newX < 5 && newY < 3 && backstep[newX][newY] == i+1){
                ahead();
                j=4;
            }else{
                girar(directions);
            }
        }
    }
    ahead();
}
void maze() {
    //adelante, izquierda, atras, derecha
    int directions[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

    bool visited[rows][cols] = {{false}}; 
    vector<vector<int> > backstep[rows][cols] = {{}}; 
    int count = 0;
    // punto inicial
    int start_x = 0, start_y = 0;
    bool pathFound = false;
    search(visited, start_x, start_y, directions, backstep, count, pathFound);
    fuga(count, start_x, start_y, Mcolor, directions, backstep);
}

void printMaze(const vector<vector<char> >& mazeToPrint) {
    for (int i = 0; i < mazeToPrint.size(); ++i) {
        for (int j = 0; j < mazeToPrint[i].size(); j++) {
            cout << mazeToPrint[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    vector<vector<char> > maze = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'}, // 1.
        {'#', ' ', '#', ' ', '#', ' ', '#', '#', '#', '#', '#'},
        {'#', ' ', '#', ' ', '#', ' ', ' ', ' ', '#', ' ', '#'}, // 3.
        {'#', ' ', '#', '#', '#', ' ', '#', ' ', '#', '#', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#'}, // 5.
        {'#', ' ', '#', '#', '#', ' ', '#', '#', ' ', ' ', '#'},
        {'#', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'}, // 7.
        {'#', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'}, // 9.
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
        //{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        //{'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'}, // 1.
        //{'#', ' ', '#', '#', '#', ' ', '#', '#', '#', ' ', '#'},
        //{'#', ' ', ' ', 'r', '#', ' ', '#', 'l', ' ', ' ', '#'}, // 3.
        //{'#', ' ', '#', '#', '#', ' ', '#', '#', '#', ' ', '#'},
        //{'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'}, // 5.
        //{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
    };
    rows = maze.size();
    cols = maze[0].size();
    maze();
    return 0;
}