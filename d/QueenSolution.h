#pragma once

#include "LinkList.h"




//八皇后问题回溯算法说明：
//回溯算法的核心就是函数回溯后原栈上元素不变
//本质上相当与在一个只有单一入口多个出口的迷宫对于走上死胡同的《即存在不满足要求的》自动过滤而正确的不断积累
//在单条线上按顺序存储在链表上在到达最终出口开始回溯（释放链表、清空棋盘）至最初的入口，然后i+1执行下一次迭代
//


namespace mylib
{
	template<int SIZE>
	class QueenSolution :public Object
	{
	protected:
		enum { N = SIZE + 2 };
		struct Pos :public Object
		{
			Pos(int px=0,int py=0):x(px),y(py){}
			int x;
			int y;
		};
		int m_chassboard[N][N];
		Pos m_derection[3];
		LinkList<Pos> m_solution;
		int m_count;
		
		void init()
		{
			m_count = 0;
			for (int i = 0; i < N; i += (N - 1))
			{
				for (int j = 0; j < N; j++)
				{
					m_chassboard[i][j] = 2;
					m_chassboard[j][i] = 2;
				}
			}

			for (int i = 1; i < N - 1; i++)
			{
				for (int j = 1; j < N - 1; j++)
				{
					m_chassboard[i][j] = 0;
				}
			}

			m_derection[0].x = -1;
			m_derection[0].y = -1;
			m_derection[1].x = 0;
			m_derection[1].y = -1;
			m_derection[2].x = 1;
			m_derection[2].y = -1;
		}

		void print()
		{
			for (m_solution.move(0, 1); !m_solution.end(); m_solution.next())
			{
				cout << "(" << m_solution.current().x << "," << m_solution.current().y << ")";
			}
			cout << endl;
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					switch (m_chassboard[i][j])
					{
					case 0:cout << " "; break;
					case 1:cout << "*"; break;
					case 2:cout << "#"; break;
					}
				}
				cout << endl;
			}
			cout << endl;
		}

		bool check(int x, int y, int d)
		{
			bool flag = true;
			do
			{
				x += m_derection[d].x;
				y += m_derection[d].y;
				flag = flag && (m_chassboard[x][y] == 0);
			} while (flag);

			return (m_chassboard[x][y] == 2);
		}
		
		void run(int j)
		{
			if (j <= SIZE)
			{
				for (int i = 1; i <= SIZE; i++)
				{
					if (check(i, j, 0) && check(i, j, 1) && check(i, j, 2))
					{
						m_chassboard[i][j] = 1;
						m_solution.insert(Pos(i, j));
						run(j + 1);
						//当i=1时
						//检测符合三种条件的j
						// 之后每个符合条件的继续执行run（j+1）
						//直到j+1>size
						//执行else
						//run（j+1）结束开始返回/回溯
						//run（j）-run(1)开始执行下列语句即回溯到头
						m_chassboard[i][j] = 0;
						m_solution.remove(m_solution.length() - 1);
					}
				}
			}
			else//如果到最后几步不存在满足要求的位置那么也不会执行print和count因为j一直小于size
			{
				m_count++;
				print();
			}
		}
	public:
		QueenSolution()
		{
			init();
		}
		void run()
		{
			run(1);
			cout << "Total:" << m_count << endl;
		}
	};
}