#include<iostream>
#include<vector>
#include<queue>
using namespace std;



class Row{

public:
    int count;
    int inx;

    Row(int count,int inx){
        this->count = count;
        this->inx   = inx;
    }


    bool operator < (const Row &obj) const{
        if(this->count == obj.count){
            return this->inx > obj.inx;
        }

        return this->count > obj.count;
    }


};
void weakestSoldier(vector<vector<int>> mat, int k){

    vector<Row> rows;

    for(int i = 0; i<mat.size(); i++){
        int count = 0;
        for(int j = 0; j<mat[i].size() && mat[i][j] == 1; j++){
            count++;
        }
        rows.push_back(Row(count,i));
    }


    priority_queue<Row> pq(rows.begin(), rows.end());

    for(int i =0; i<k; i++){
        cout<<"Row"<<pq.top().inx<<endl;
        pq.pop();
    }


}

int main(){
    vector<vector<int>> matrix = {{1,0,0,0},
                                  {1,1,1,1},
                                  {1,0,0,0},
                                  {1,0,0,0}};

weakestSoldier(matrix,2);
}