class Network:

    def __init__(self, n):
        self.matrix = []   
        self.n=n
    # Add edges
    def add_edge(self, s, d, w):
        self.matrix.append([s, d, w])



    def print_solution(self, dist, src, next_hop,res):
        print("Routing Table for router ", res[src])
        print("Destination Router     Outgoing Line \t Hop Count")
        for i in range(self.n):
            print("\t{0} \t\t\t\t     {1} \t\t\t       {2}".format(res[i],res[next_hop[i]], dist[i]))

    def bellman_ford(self, src,res):

        dist = [999] * self.n
        dist[src] = 0
        next_hop = {src: src}
        for _ in range(self.n - 1):
            for s, d, w in self.matrix:
                if dist[s] != 999 and dist[s] + w < dist[d]:
                    dist[d] = dist[s] + w
                    if s == src:
                        next_hop[d] =d
                    elif s in next_hop:
                        next_hop[d] = next_hop[s]

    
        self.print_solution(dist, src, next_hop,res)


matrix=[]

n=int(input("Enter number of routers"))
nodes = input('Enter the routers: ').split()
nums=list(range(0, n))
res = {nums[i]: nodes[i] for i in range(len(nums))} 
print("Enter cost matrix:(999 for inf)")
for i in range(n):
    temp=list(map(int,input().split(" "))) 
    matrix.append(temp)
nw=Network(n)
for i in range(n):
    for j in range(n):
        v=matrix[i][j]
        nw.add_edge(i,j,v)
            
for i in range(n):
    nw.bellman_ford(i,res)
