tab = [[1,1,1,1,1],
       [1,0,0,1,1],
       [1,1,0,0,1],
       [1,0,0,1,0],
       [1,1,0,1,0]]
#get number of zeros around a point
def getZeros(tab, x, y, visited = []):
    if (x, y) in visited:
        return 0
    count = 0
    visited.append((x, y))
    if x > 0 and tab[x-1][y] == 0:
        count += 1 + getZeros(tab, x-1, y)
    if x < len(tab)-1 and tab[x+1][y] == 0:
        count += 1 + getZeros(tab, x+1, y)
    if y > 0 and tab[x][y-1] == 0:
        count += 1 + getZeros(tab, x, y-1)
    if y < len(tab[0])-1 and tab[x][y+1] == 0:
        count += 1 + getZeros(tab, x, y+1)
    return count

for i in range(len(tab)):
    for j in range(len(tab[0])):
        if 
        print(tab[i][j], end=" ")
    print()

print(getZeros(tab, 2, 2))