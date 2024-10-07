#include <iostream>
using namespace std;

class Sparse{
    public:
    int rows,col;
    int sRows=0,sCol=3;
    int **matrix,**sparse;
    
    bool getMatrix(){
        cout<<"Enter the number of Rows: ";
        cin>>rows;
        cout<<"Enter the number of Colums: ";
        cin>>col;
        
        matrix=new int*[rows];
        for(int i=0;i<rows;i++){
            matrix[i]=new int[col];
        }
        
        cout<<"Enter the Matrix Elements:"<<endl;
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<col;j++){
                cout<<"("<<i+1<<","<<j+1<<"): ";
                cin>>matrix[i][j];
                if(matrix[i][j]!=0)sRows++;
            }
        }
        if(sRows<(rows*col)){
            cout<<"Matrix is :"<<endl;
            displaySparse();
            toSparse(); 
            return true;
        }else{
            cout<<"Enter Valid Sparse Matrix!!!"<<endl;
            return false;
        }
    }
    
    void toSparse(){
        sparse=new int*[sRows+1];
        for(int i=0;i<sRows+1;i++){
            sparse[i]=new int[sCol];
        }
        int sr=1;
        for(int i=0;i<rows;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]!=0){
                    sparse[sr][0]=i;
                    sparse[sr][1]=j;
                    sparse[sr][2]=matrix[i][j];
                    sr++;
                }
            }
        }
                    sparse[0][0]=rows;
                    sparse[0][1]=col;
                    sparse[0][2]=sRows;
        cout<<"Sparse Matrix is :"<<endl;
        displaySparse();
    }
    
    void displaySparse(){
        for(int i=0;i<rows;i++){
            cout<<"| ";
            for(int j=0;j<col;j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<" |"<<endl;
        }
    }
    
    void displaySparse(){
        cout<<" R C V"<<endl;
        for(int i=0;i<sRows;i++){
            cout<<"| ";
            for(int j=0;j<sCol;j++){
                cout<<sparse[i][j]<<" ";
            }
            cout<<" |"<<endl;
        }
    }
    friend Sparse operator+(Sparse,Sparse);
};

Sparse operator+(Sparse mat1,Sparse mat2){
    Sparse add;    
    add.sRows=mat1.sRows+mat2.sRows;
    add.sCol=3;
    add.sparse=new int*[add.sRows+1];
    for(int i=0;i<add.sRows+1;i++){
        add.sparse[i]=new int[add.sCol];
    }
    int addCtr=1, ctr1=1,ctr2=1;
    
    while(ctr1<mat1.sRows+1 && ctr2<mat2.sRows+1){
        if(mat1.sparse[ctr1][0]<mat2.sparse[ctr2][0] 
        || (mat1.sparse[ctr1][0]==mat2.sparse[ctr2][0] 
        && mat1.sparse[ctr1][1]<mat2.sparse[ctr2][1])){
            add.sparse[addCtr][0]=mat1.sparse[ctr1][0];
            add.sparse[addCtr][1]=mat1.sparse[ctr1][1];
            add.sparse[addCtr][2]=mat1.sparse[ctr1][2];
            addCtr++;
            ctr1++;
        }
        else if(mat1.sparse[ctr1][0]>mat2.sparse[ctr2][0]){
            add.sparse[addCtr][0]=mat2.sparse[ctr2][0];
            add.sparse[addCtr][1]=mat2.sparse[ctr2][1];
            add.sparse[addCtr][2]=mat2.sparse[ctr2][2];
            addCtr++;
            ctr2++;
        }
        else {
            add.sparse[addCtr][0]=mat1.sparse[ctr1][0];
            add.sparse[addCtr][1]=mat1.sparse[ctr1][1];
            add.sparse[addCtr][2]=mat1.sparse[ctr1][2]+mat2.sparse[ctr2][2];
            addCtr++;
            ctr1++;
            ctr2++;
        }
    }
    while(ctr1<mat1.sRows+1){
        add.sparse[addCtr][0]=mat1.sparse[ctr1][0];
        add.sparse[addCtr][1]=mat1.sparse[ctr1][1];
        add.sparse[addCtr][2]=mat1.sparse[ctr1][2];
        addCtr++;
        ctr1++;
    }
    while(ctr2<mat2.sRows+1){
        add.sparse[addCtr][0]=mat2.sparse[ctr2][0];
        add.sparse[addCtr][1]=mat2.sparse[ctr2][1];
        add.sparse[addCtr][2]=mat2.sparse[ctr2][2];
        addCtr++;
        ctr2++;
    }
    add.sRows=addCtr;
    return add;
}

int main()
{   
    int n=2;
    Sparse obj[n],add;
    for(int i=0;i<n;i++){
        obj[i].getMatrix();
    }
    add=obj[0]+obj[1];
    add.displaySparse();
    return 0;
}

