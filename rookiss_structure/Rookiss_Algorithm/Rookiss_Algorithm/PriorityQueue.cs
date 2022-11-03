using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

// 우선 순위 큐는 어떻게든 대소 관계를 비교할 수 있어야한다.
class PriorityQueue<T> where T : IComparable<T>
{

    List<T> _heap = new List<T>();
    public void Push(T data)
    {
        // 힙의 맨 끝에 새로운 데이터를 삽입한다.
        _heap.Add(data);

        int now = _heap.Count - 1;
        // 도장깨기 시작
        while (now > 0)
        {
            // 도장깨기 시도
            int next = (now - 1) / 2; // 나의 부모 인덱스
            if (_heap[now].CompareTo(_heap[next]) < 0)
                break; // 내가 더 작음

            // 값 교체한다.
            T temp = _heap[now];
            _heap[now] = _heap[next];
            _heap[next] = temp;

            // 검사 위치 이동
            now = next;
        }
    }

    public T Pop()
    {
        // 반환할 데이터를 따로 저장
        T ret = _heap[0];

        // 마지막 데이터를 루트로 이동시킨다.
        int lastIndex = _heap.Count - 1;
        _heap[0] = _heap[lastIndex];
        _heap.RemoveAt(lastIndex);
        lastIndex--;

        // 역으로 내려가는 도장깨기 시작
        int now = 0;
        while (true)
        {
            int left = 2 * now + 1;
            int right = 2 * now + 2;

            int next = now;
            // 왼쪽ㄱ밧이 현재값보다 크면, 왼쪽으로 이동
            if (left <= lastIndex && _heap[next].CompareTo(_heap[left]) < 0)
                next = left;

            // 오른쪽이 현재값(왼쪽이동 포함)보다 크면, 올른쪽으로 이동
            if (right <= lastIndex && _heap[next].CompareTo(_heap[right]) < 0)
                next = right;

            // 왼쪽,올느쪽 모두 현재값보다 작으면 종료
            if (next == now)
                break;

            // 두 값을 교체
            T temp = _heap[now];
            _heap[now] = _heap[next];
            _heap[next] = temp;
            // 검사위치 이동
            now = next;

        }

        return ret;
    }
    public int Count
    {
        get
        {
            return _heap.Count;
        }
    }
}

//A*
//시작지점 도착지점을 알고있음
//ㄱ상태에서 각 지점마다 도착지까지 가기위한 비용, 가까워지는지 계산해 가산점?같은걸 줌
//가까워지는지 어떤식으로?
//1. 이동해야하는 칸
//2. 피타고라스를 이용해 직접 계산