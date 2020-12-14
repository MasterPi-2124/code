#include <bits/stdc++.h>

typedef struct State{
    int x,y;
    State* next;
    State* parent;

    State(int ix, int iy){
        x = ix; y = iy;
        next = NULL; parent = NULL;
        //printf("constructor state %d,%d\n",x,y);
    }
};

typedef struct Queue{
    State* head;
    State* tail;
    Queue(){
        head = NULL; tail = NULL;
        //printf("constructor queue\n");
    }
    void push(State* s){
        if(empty()){ head = s; tail = s; return;}
        tail->next = s; tail = s;
    }
    State* pop(){
        if(empty()) return NULL;
        State* tmp = head; head = head->next;
        return tmp;
    }
    bool empty(){
        return head == NULL && tail == NULL;
    }
};
Queue Q;
bool visited[1000][1000];// visited[x][y] = true co nghia (x,y) da duoc xet den
State* target;
State* start;
int a, b, c;
bool finalState(State* s){
    return s->x == c || s->y == c;
}
bool fillJug1(State* s){
    if(visited[a][s->y]) return false;
    State* p = new State(a,s->y);
    p->parent = s;
    Q.push(p);
    visited[p->x][p->y] = true;
    if(finalState(p)){
        target = p; return true;
    }
    return false;
}
bool fillJug2(State* s){
    if(visited[s->x][b]) return false;
    State* p = new State(s->x,b);
    p->parent = s;
    Q.push(p);
    visited[p->x][p->y] = true;
    if(finalState(p)){
        target = p; return true;
    }
    return false;
}
bool pour1to2(State* s){
    if(s->x + s->y > b){
        if(visited[s->x + s->y - b][b]) return false;
        State* p = new State(s->x + s->y - b,b);
        p->parent = s;
        Q.push(p);
        visited[p->x][p->y] = true;
        if(finalState(p)){
            target = p; return true;
        }
        return false;
    }else{
        if(visited[0][s->x + s->y]) return false;
        State* p = new State(0,s->x + s->y);
        p->parent = s;
        Q.push(p);
        visited[p->x][p->y] = true;
        if(finalState(p)){
            target = p; return true;
        }
        return false;

    }
}
bool pour2to1(State* s){
    if(s->x + s->y > a){
        if(visited[a][s->x + s->y - a]) return false;
        State* p = new State(a,s->x + s->y - a);
        p->parent = s;
        Q.push(p);
        visited[p->x][p->y] = true;
        if(finalState(p)){
            target = p; return true;
        }
        return false;
    }else{
        if(visited[s->x + s->y][0]) return false;
        State* p = new State(s->x + s->y,0);
        p->parent = s;
        Q.push(p);
        visited[p->x][p->y] = true;
        if(finalState(p)){
            target = p; return true;
        }
        return false;
    }
}
bool emptyJug1(State* s){
    if(visited[0][s->y]) return false;
    State* p = new State(0,s->y);
    p->parent = s;
    Q.push(p);
    visited[p->x][p->y] = true;
    if(finalState(p)){
        target = p; return true;
    }
    return false;
}
bool emptyJug2(State* s){
    if(visited[s->x][0]) return false;
    State* p = new State(s->x,0);
    p->parent = s;
    Q.push(p);
    visited[p->x][p->y] = true;
    if(finalState(p)){
        target = p; return true;
    }
    return false;

}

void process(){
    start = new State(0,0);
    Q.push(start);
    target = NULL;
    visited[0][0] = true;
    while(!Q.empty()){
        State* s = Q.pop();
        printf("POP (%d,%d)\n",s->x,s->y);
        // do nuoc tu ngoai vao day coc 1
        bool ok = fillJug1(s);// ok = true neu gap trang thai ket thuc
        if(ok) break;
        ok = fillJug2(s);
        if(ok) break;
        ok = pour1to2(s);
        if(ok) break;
        ok = pour2to1(s);
        if(ok) break;
        ok = emptyJug1(s);
        if(ok) break;
        ok = emptyJug2(s);
        if(ok) break;
    }
    printf("Print result\n");
    if(target == NULL){
        printf("No solution!\n");
    }else{
        State*  s = target;
        while(s != start){
            printf("(%d,%d)\n",s->x, s->y);
            s = s->parent;
        }
        printf("(%d,%d)\n",s->x, s->y);
    }
}
void init(){
    for(int i = 0; i < 1000; i++)
        for(int j = 0; j < 1000; j++)
            visited[i][j] = false;
}
int main(){
    a = 8; b = 6; c = 4;
    init();
    process();
}
