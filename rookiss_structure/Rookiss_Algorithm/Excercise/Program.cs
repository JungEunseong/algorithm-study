using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Excercise
{
  
    class Knight : IComparable<Knight>
    {
        public int Id { get; set; }
    

        public int CompareTo(Knight? other)
        {
            if (Id == other.Id)
                return 0;
            return Id > other.Id ? 1 : -1;
        }
    }
    class Program
    {
        public static void Main(string[] args)
        {
            // 우선순위 큐
            // 우선순위가 가장 높은 사람이 먼저 빠져나옴
            // 가장 큰 값이 먼저 나옴

            PriorityQueue<Knight> q = new PriorityQueue<Knight>();
            q.Push(new Knight() { Id = 20});
            q.Push(new Knight() { Id = 10});
            q.Push(new Knight() { Id = 30});
            q.Push(new Knight() { Id = 80});
            q.Push(new Knight() { Id = 40});
            q.Push(new Knight() { Id = 30});

            // 작은 값을 먼저하고싶어 꼼수
            // 1. 값을 넣을 때 -를 곱해주고 뺄 때 한번 더 곱해주기
            while (q.Count() > 0)
            {
                Console.WriteLine("Knight   " + q.Pop().Id);
            }
        }
    }
}
