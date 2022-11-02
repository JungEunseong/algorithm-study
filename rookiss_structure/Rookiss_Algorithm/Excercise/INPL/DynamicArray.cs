using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class MyList<T> // 동적배열 구현
{
    const int DEFAULT_SIZE = 1;
    T[] _data = new T[DEFAULT_SIZE];

    public int Count; // 실제로 사용중인 데이터 개수
    public int Capacity { get { return _data.Length; } } // 예약된 데이터 개수

    public void Add(T item)
    {
        // 1. 공간이 충분한지 확인
        if (Count >= Capacity)
        {
            // 공간을 다시 늘려서 확보한다
            T[] newArray = new T[Count * 2];
            for (int i = 0; i < Count; i++)
                newArray[i] = _data[i];
            _data = newArray;
        }


        // 2. 공간에 데이터를 넣는다.
        _data[Count] = item;
        Count++;
    }

    public T this[int index]
    {
        get { return _data[index]; }
        set { _data[index] = value; }
    }

    public void RemoveAt(int index)
    {
        for (int i = index; i < Count - 1; i++)
            _data[i] = _data[i + 1];
        _data[Count - 1] = default(T);
        Count--;
    }
}
