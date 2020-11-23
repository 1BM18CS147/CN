class Network:

    def __init__(self, n):
        self.matrix = []   
        self.n=n
    # Add edges
    def add_edge(self, s, d, w):
        self.matrix.append([s, d, w])

    def print_solution(self, dist,src):
        print("Routing Table of {}".format(chr(ord('A')+src)))
        print("{0}\t{1}".format("Dest", "Distance"))  
        for i in range(self.n):
            print("{0}\t\t{1}".format(chr(ord('A')+i),dist[i]))

    def bellman_ford(self, src):

        # Step 1: fill the distance array and predecessor array
        dist = [999]* self.n
        # Mark the source vertex
        dist[src] = 0

        # Step 2: relax edges |V| - 1 times
        for _ in range(self.n - 1):
            for s, d, w in self.matrix:
                if dist[s] != 999 and dist[s] + w < dist[d]:
                    dist[d] = dist[s] + w

    
        # Print the distance and predecessor array
        self.print_solution(dist,src)


matrix=[]
n=int(input("Enter number of nodes"))
print("Enter cost matrix:")
for i in range(n):
    temp=list(map(int,input().split(" "))) 
    matrix.append(temp)
nw=Network(n)
for i in range(n):
    for j in range(n):
        v=matrix[i][j]
        nw.add_edge(i,j,v)
            
for i in range(n):
    nw.bellman_ford(i)
