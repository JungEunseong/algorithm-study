using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

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

        if (Tail != null)
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
