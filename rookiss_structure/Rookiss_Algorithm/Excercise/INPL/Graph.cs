using System;



// 스택 : LIFO (후입선출)
// 큐 : FIFO (선입선출)

// 그래프 :[현실 세계의 사물이나 추상적인 개념 간]의 [연결 관계]를 표현한다.
// 정점(Vertex): 데이터를  표현함(사물,개념 등)
// 간선(Edge): 정점들을 연결하는데 사용
//    예시: 소셜 네트워크관계도,
// 가중치 그래프 - 간선에 수치를 추가
//    예시: 지하철 노선도
// 방향 그래프 - 간선에 방향 추가
//    예시: 일방통행이 포함된 도로망
//
//
// 

class Graph
{
    int[,] adj = new int[6, 6]
    {
        {-1,15,-1,35,-1,-1 },
        {15,-1,05,10,-1,-1 },
        {-1,05,-1,-1,-1,-1 },
        {35,10,-1,-1,05,-1 },
        {-1,-1,-1,05,-1,05 },
        {-1,-1,-1,-1,05,-1 },
    };

    public void Dijikstra(int start)
    {
        bool[] visited = new bool[6];
        int[] distance = new int[6]; // 점을 찾았을 때 최단거리
        int[] parent = new int[6];
        Array.Fill(distance, Int32.MaxValue);

        distance[start] = 0;
        parent[start] = start;
        while (true)
        {
            //제일 가까이 있는 후보를 찾는다.


            // 가장 유려ㅛㄱ한 후보의 거리와 번호를 저장
            int closest = Int32.MaxValue;
            int now = -1;
            for (int i = 0; i < 6; i++)
            {
                //이미 방문 스킵
                if (visited[i])
                    continue;
                // 아직 발견된 적없거나, 기존 후보보다 멀리있으면 스킵
                if (distance[i] == Int32.MaxValue || distance[i] >= closest)
                    continue;
                // 여태껏 발견한 가장 가깝다는 ㅢ미, 정보 갱신

                closest = distance[i];
                now = i;
            }

            // 다음 후보가 하나도없다. -> 종료
            if (now == -1)
                break;

            // 제일 가까운 후보 찾음 방문.

            visited[now] = true;

            // 방문한 정점과 인접한 정점 조사,
            // 상황에 따라 발견한 최단거리 갱신

            for (int next = 0; next < 6; next++)
            {
                // 연결되지 않은 정점 스킵
                if (adj[now, next] == -1)
                    continue;

                // 이미 방문 시 스킵 (이전 노드)
                if (visited[next])
                    continue;

                // 새로 조사된 정점의 최단거리를 계산한다.
                int nextDist = distance[now] + adj[now,next]; 
                // 만약 기존 발견한 최단거리가 새로 조사된 최단거리보다 크면 정보 갱신
                if(nextDist < distance[next])
                {
                    distance[next] = nextDist;
                    parent[next] = now;
                }       

            }
        }


    }

    /*List<int>[] adj2 = new List<int>[]
    {
        new List<int>(){1,3},
        new List<int>(){0,2,3},
        new List<int>(){1},
        new List<int>(){0,1,4},
        new List<int>(){3,5},
        new List<int>(){4},
    };*/


    #region DFS
    bool[] visited = new bool[6];
    // 1) 우선 now를 방문
    // 2) noew와 연결된 정점들을 하나 씩 확인해서 방문해서 , 아직 미방문 상태라면 방문
    public void DFS(int now)
    {
        Console.WriteLine(now);
        visited[now] = true; // now 방문
        
        for (int next = 0; next < 6; next++)
        {
            if (adj[now, next] == 0) // 연결 X => 넘기기
                continue;
            if (visited[next]) //이미 방문 시 넘기기
                continue;
            DFS(next);
        }

    }

    /*public void DFS2(int now)
    {
        Console.WriteLine(now);
        visited[now] = true;

        foreach (int next in adj2[now])
        {
            if (visited[next])
                continue;

            DFS2(next);
        }
    }*/

    public void SearcAll()
    {
        visited = new bool[6];
        for (int now = 0; now < 6; now++)
            if (visited[now] == false)
                DFS(now);
    }

    #endregion DFS

    #region BFS
    public void BFS(int start)
    {
        bool[] found = new bool[6];
        int[] parent = new int[6];
        int[] distance= new int[6];

        Queue<int> q = new Queue<int>();
        q.Enqueue(start);
        found[start] = true;
        parent[start] = start;
        distance[start] = 0;
        while(q.Count > 0)
        {
            int now = q.Dequeue();
            Console.WriteLine(now);

            for (int next = 0; next < 6; next++)
            {
                if (adj[now, next] == 0) // 인접하지 않으면 넘기기
                    continue;
                if (found[next]) // 이미 발견했으면 넘기기
                    continue;

                q.Enqueue(next);
                found[next] = true;
                parent[next] = now;
                distance[next] = distance[now] + 1;
            }
        }
    }
    #endregion
}
class GraphProgram
{
    //public static void Main(string[] args)
        //DFS (Depth First  Search 깊이 우선 탐색)
        //깊게 먼저 갈 수 있는곳 까지 간다.
        //더 이상 갈 수 있는 곳이 없으면 되돌아가면서 새로운길로간다. 거기서 또 최대한 깊게
        //BFS (Breadth First Search 너비 우선 탐색)
        // 
        //
    //    Graph graph = new Graph();
    //    graph.SearcAll();
        
}