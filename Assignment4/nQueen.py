import json

n=4
matrix=[[0 for x in range(n)]for y in range(n)]
b={}  

def IsColumnSafe(row,col,matrix):
    while(row>=0):
        if(matrix[row][col]==1):
            return 0
        row=row-1
    return 1

def IsRightDiagonalSafe(row,col,matrix):
    while(row>=0 and col<n):
        if(matrix[row][col]==1):
            return 0
        row=row-1
        col=col+1
    return 1
    
def IsLeftDiagonalSafe(row,col,matrix):
    while(row>=0 and col>=0):
        if(matrix[row][col]==1):
            return 0
        row=row-1
        col=col-1
    return 1


def IsSafe (row,col):
    if(IsColumnSafe(row,col,matrix)==0):
        return 0
    if(IsLeftDiagonalSafe(row,col,matrix)==0):
        return 0
    if(IsRightDiagonalSafe(row,col,matrix)==0):
        return 0
    return 1
    

  
def board(row,col):
    if (row>=n):
        return
    p=0
    while(col<n):
        p=IsSafe(row,col)
        if(p==1):
            matrix[row][col]=1
            b.update({row:col})
            break
        col=col+1
    if(p==1):
        board(row+1,0)
    else:
        matrix[row-1][b.get(row-1)]=0
        board(row-1,int(b.get(row-1))+1)
 


if __name__=='__main__':
    board(0,0)
    print(matrix)
    
    with open('data.json','w') as f:
        json.dump(b,f)