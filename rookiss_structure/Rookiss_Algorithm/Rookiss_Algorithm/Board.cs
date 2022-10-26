using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Rookiss_Algorithm
{

    class MyList<T> // 동적배열 구현
    {
        const int DEFAULT_SIZE = 1;
        T[] _data = new T[DEFAULT_SIZE];
        
        public int Count; // 실제로 사용중인 데이터 개수
        public int Capacity { get { return _data.Length; } } // 예약된 데이터 개수

        public void Add(T item)
        {
            // 1. 공간이 충분한지 확인
            if(Count >= Capacity)
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
                _data[i] = _data[i+1];
            _data[Count - 1] = default(T);
            Count--;
        }
    }

    class MyLinkedListNode<T>
    {
        public T Data;
        public MyLinkedListNode<T> Next;
        public MyLinkedListNode<T> Prev;   
    }

    class MyLinkedList<T>
    {
        public MyLinkedListNode<T> Head; 
        public MyLinkedListNode<T> Tail; 
        public int Count = 0;

        public MyLinkedListNode<T> AddLast(T data)
        {
            MyLinkedListNode<T> newNode = new MyLinkedListNode<T>();
            newNode.Data = data;

            // 이게 첫번째면, 즉 아예 없다면 새로추가
            if (Head == null)
                Head = newNode;

            if(Tail != null)
            {
                Tail.Next = newNode;
                newNode.Prev = Tail;
            }

                
            Tail = newNode;
            Count++;
            return newNode;
        }

        public void Remove(MyLinkedListNode<T> node)
        {
            if (Head == node)
                Head = Head.Next;

            if (Tail == node)
                Tail = Tail.Prev;

            if (node.Prev != null)
                node.Prev.Next = node.Next;

            if (node.Next != null)
                node.Next.Prev = node.Prev;


            Count--;
        }
        

    }

    class Board
    {
        public int[] _data = new int[25]; // 배열
        public MyList<int> _data2 = new MyList<int>(); // 동적 배열
        public MyLinkedList<int> _data3 = new MyLinkedList<int>(); // 연결 리스트


        public void Initialize()
        {
            _data3.AddLast(101);
            _data3.AddLast(102);
            MyLinkedListNode<int> node =  _data3.AddLast(103);
            _data3.AddLast(104);
            _data3.AddLast(105);

            _data3.Remove(node);
        }


    }
}
