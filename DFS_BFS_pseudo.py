# DFS pseudo
DFS(u , adj):
    u.visited = True 
    for each v is included to adj[u]:
        if v.visited is False:
            DFS(v,adj) 

# 아니면 일단 호출하고 그다음 거르는것도 방법임
DFS(u, adj):
    if not u.visited: return
    u.visited = True
    for each v is included to adj[u]:
        DFS(v,adj)
        
# BFS pseudo -> for 최단거리
BFS(G, u)
    u.visited = 1
    q.push(u);
    while(q.size()) 
        u = q.front() 
        q.pop()
        for each v ∈ G.Adj[u]
            if v.visited == false
                v.visited = u.visited + 1
                # 그냥 visited만 확인하려면 v.visited = 1 하면 되겠죠
                q.push(v)

# 그냥 visited만 확인하려면 그냥 

